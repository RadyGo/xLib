/**
 * \file   Client.h
 * \brief  CURL client
 *
 * https://curl.haxx.se/libcurl/c/allfuncs.html
 * https://curl.haxx.se/libcurl/c/example.html
 */


#pragma once

#include <xLib/Core/Core.h>
#include <xLib/Core/Handle.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include "Types.h"
//-------------------------------------------------------------------------------------------------
xNAMESPACE_BEGIN3(xl, package, curl)

class Client
    /// Client (interface)
{
public:
    explicit       Client();
        ///< constructor
    virtual       ~Client();
        ///< destructor

    // handle
    HandleCurl &   get();
    void_t         reset();

	template<typename T>
	void_t         setOption(cCURLoption option, const T &value);
    void_t         perform();
    void_t         pause(cint_t bitMask);
    template<typename T>
    void_t         info(cCURLINFO info, const T &value);

    void_t         receive(void_t *buff, std::csize_t buffSize, std::size_t *n);
    void_t         send(cvoid_t *buff, std::csize_t buffSize, std::size_t *n);

    std::tstring_t escape(std::ctstring_t &str);
    std::tstring_t unescape(std::ctstring_t &str);

    static
    std::tstring_t escapeUrl(std::ctstring_t &str);
    static
    std::tstring_t unescapeUrl(std::ctstring_t &str);

    /// struct curl_slist *curl_slist_append(struct curl_slist *,  const char *);
    /// void_t               curl_slist_free_all(struct curl_slist *);

	static
    std::tstring_t strError(cCURLcode code);

    // callbacks
	static
	std::size_t    onWriteHeader(void_t *buff, std::size_t size, std::size_t items, std::tstring_t *userData);
	static
	std::size_t    onWriteData(void_t *buff, std::size_t size, std::size_t items, std::tstring_t *userData);
	static
	std::size_t    onReadData(void_t *buff, std::size_t size, std::size_t items, std::tstring_t *userData);
	static
	int            onDebug(CURL *curl, curl_infotype type, char *buf, std::size_t len, void_t *useData);

    HandleCurl _handle;

private:
    xNO_COPY_ASSIGN(Client)
};

xNAMESPACE_END3(xl, package, curl)
//-------------------------------------------------------------------------------------------------

#include "Client.inl"

/**
 * TODO: curl_easy
 *
 * url_easy_cleanup
 * curl_easy_duphandle
 * curl_easy_escape
 * curl_easy_getinfo
 * curl_easy_init
 * curl_easy_pause
 * curl_easy_perform
 * curl_easy_recv
 * curl_easy_reset
 * curl_easy_send
 * curl_easy_setopt
 * curl_easy_strerror
 * curl_easy_unescape
 */
