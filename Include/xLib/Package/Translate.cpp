/**
 * \file  Translate.cpp
 * \brief Translate text
 */


#include "Translate.h"


//-------------------------------------------------------------------------------------------------

xNAMESPACE_BEGIN2(xl, package)

/**************************************************************************************************
*   public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
Translate::Translate() :
	IRestClient()
{
}
//-------------------------------------------------------------------------------------------------
void_t
Translate::languagesDetect(
    std::ctstring_t     &a_text,
    Translate::Language *out_langFrom,
    Translate::Language *out_langTo
) const
{
    xTEST(!a_text.empty());
    xTEST(out_langFrom != nullptr);
    xTEST(out_langTo != nullptr);

    std::ctstring_t lettersEn = xT("abcdefghijklmnopqrstuvwxyz");
    std::ctstring_t lettersRu = xT("абвгдеёжзийклмнопрстуфхцчшщъыьэюя");

    std::size_t countEn {};
    std::size_t countRu {};
	{
	    for (int i = 0; i < a_text.size(); ++ i) {
			core::CharT letter( a_text.at(i)/*.toLower()*/ );
			xCHECK_DO(!letter.isAlpha(), continue);

			xCHECK_DO(lettersEn.find(letter.character()) != std::tstring_t::npos, ++ countEn);
			xCHECK_DO(lettersRu.find(letter.character()) != std::tstring_t::npos, ++ countRu);
		}
	}

    cbool_t isEn      = (countEn != 0 && countRu == 0);
    cbool_t isRu      = (countEn == 0 && countRu != 0);
    cbool_t isMixed   = (countEn != 0 && countRu != 0);
    cbool_t isUnknown = (countEn == 0 && countRu == 0);

    if      (isEn) {
        *out_langFrom = Translate::Language::En;
        *out_langTo   = Translate::Language::Ru;

        Trace() << "Langs: en-ru\n";
    }
    else if (isRu) {
        *out_langFrom = Translate::Language::Ru;
        *out_langTo   = Translate::Language::En;

        Trace() << "Langs: ru-en\n";
    }
    else if (isMixed) {
        Trace() << "Langs: mixed-mixed\n";

        cbool_t isPreferEn = (countEn >= countRu);
        cbool_t isPreferRu = (countRu >  countEn);

        if      (isPreferEn) {
            *out_langFrom = Translate::Language::En;
            *out_langTo   = Translate::Language::Ru;

            Trace() << "Langs (prefer): en-ru\n";
        }
        else if (isPreferRu) {
            *out_langFrom = Translate::Language::Ru;
            *out_langTo   = Translate::Language::En;

            Trace() << "Langs (prefer): ru-en\n";
        }
        else {
            xTEST(false);
        }
    }
    else if (isUnknown) {
        *out_langFrom = Translate::Language::Unknown;
        *out_langTo   = Translate::Language::Unknown;

        Trace() << "Langs: unknown-unknown\n";
    }
    else {
        *out_langFrom = Translate::Language::Unknown;
        *out_langTo   = Translate::Language::Unknown;

        Trace() << xTRACE_VAR(countEn);
        Trace() << xTRACE_VAR(countRu);

        xTEST(false);
    }
}
//-------------------------------------------------------------------------------------------------
void_t
Translate::execute(
    std::ctstring_t &a_textFrom,		///< source text
    cLanguage        a_langFrom,		///< source text language
    cLanguage        a_langTo,			///< target text language
    std::tstring_t  *out_textToBrief,	///< [out] target brief translate
    std::tstring_t  *out_textToDetail,	///< [out] target detail translate
    std::tstring_t  *out_textToRaw		///< [out] target raw translate (HTML) (maybe nullptr)
) const
{
    xTEST(!a_textFrom.empty());
    xTEST(a_langFrom != Language::Unknown);
    xTEST(a_langTo != Language::Unknown);
    xTEST(out_textToBrief != nullptr);
    xTEST(out_textToDetail != nullptr);
    xTEST_NA(out_textToRaw);

    std::ctstring_t host  = std::tstring_t("https://translate.google.com");
    std::tstring_t  request;
    std::tstring_t  response;

    // request
    {
	   /**
		* HTTP POST request:
		*
		* <form action="/m" class="">
		*     ...
		*     <input type="hidden" name="hl" value="ru"/>
		*     <input type="hidden" name="sl" value="auto"/>
		*     <input type="hidden" name="tl" value="ru"/>
		*     <input type="hidden" name="ie" value="UTF-8"/>
		*     <input type="hidden" name="prev" value="_m"/>
		*     <input type="text" name="q" style="width:65%" maxlength="2048" value=""/><br>
		*     <input type="submit" value="Перевести"/>
		* </form>
		*/

	#if 0
		cQUrl url = std::tstring_t("%1/m").arg(host);
		url.toEncoded();

		QUrlQuery query;
		query.addQueryItem("h1", a_langFrom);
		query.addQueryItem("tl", a_langTo);
		query.addQueryItem("ie", "UTF-8");
		query.addQueryItem("q",  a_textFrom);

		request.setUrl(url);
		request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

		response = manager.post(request, query.toString(QUrl::FullyEncoded).toUtf8());
		xTEST(!response.empty());
	#endif
     }

     _responseParse(response, out_textToBrief, out_textToDetail, out_textToRaw);
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*   private
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
void_t
Translate::_responseParse(
    std::ctstring_t &a_response,		///<
    std::tstring_t  *out_textToBrief,	///< [out]
    std::tstring_t  *out_textToDetail,	///< [out]
    std::tstring_t  *out_textToRaw		///< [out]
) const
{
    std::tstring_t textToBrief;
    std::tstring_t textToDetail;
    std::tstring_t textToRaw;

    std::tstring_t response;

    bool isDictionaryText {};
    {
    #if 0
        cQVariant httpStatusCode = a_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        if ( !httpStatusCode.isValid() ) {
            Trace() << xTRACE_VAR(httpStatusCode);
            return;
        }

        int status = httpStatusCode.toInt();
        if (status != 200) {
            std::ctstring_t reason = a_reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
            Trace() << xTRACE_VAR(reason);
        }
    #endif

	#if 0
		if (a_reply->error() != QNetworkReply::NoError) {
			*a_textToBrief  = a_reply->errorString();
			*a_textToDetail = a_reply->errorString();

			if (a_textToRaw != nullptr) {
				*a_textToRaw = a_reply->errorString();
			}

			return;
		}

		for ( ; ; ) {
			QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents);

			xCHECK_DO(a_reply->isFinished(), break);
		}

		response = std::tstring_t::fromUtf8(a_reply->readAll());
		xTEST(!response.empty());

		textToRaw        = response;
		isDictionaryText = response.contains("Dictionary:");

		// Trace() << xTRACE_VAR(response);
		}

		// proccess response

		{
		response.replace("Dictionary:", "\n");
		response.replace("<br>", "\n");
		}

		// parse response
		{
		QDomDocument document;
		document.setContent(response);

		QDomNodeList docList = document.elementsByTagName("div");
		xTEST(docList.count() >= 3);

		// out - textToBrief
		textToBrief = docList.at(2).toElement().text();
		xTEST(!textToBrief.empty());

		// out - textToDetail
		if (isDictionaryText) {
			textToDetail = docList.at(5).toElement().text();
			xTEST(!textToDetail.empty());
		} else {
			textToDetail = xT("n/a");
		}
	#endif
	}

    // out
    {
        a_textToBrief->swap(textToBrief);
        a_textToDetail->swap(textToDetail);

        if (a_textToRaw != nullptr) {
            a_textToRaw->swap(textToRaw);
        }

        // Trace() << xTRACE_VAR(*a_textToBrief);
        // Trace() << xTRACE_VAR(*a_textToDetail);
        // Trace() << xTRACE_VAR(*a_textToRaw);
    }
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, package)