/**
 * \file  PrivaBankApi.h
 * \brief PrivaBank API
 */


#pragma once

#include <xLib/Core/Core.h>
#include <xLib/Package/IRestClient.h>
//-------------------------------------------------------------------------------------------------
xNAMESPACE_BEGIN2(xl, package)

class PrivaBankApi
    /// PrivaBank API
{
public:
             PrivaBankApi();
        ///< constructor
    virtual ~PrivaBankApi();
        ///< destructor

	using exchange_rate_t = std::map<std::tstring_t, std::map<std::tstring_t, std::map_tstring_t>>;

    void getExchangeRates(std::ctstring_t &date, exchange_rate_t *data)
    		const;
		///< API позволяет получить информацию о наличных курсах валют ПриватБанка и НБУ
		///< на выбранную дату. Архив хранит данные за последние 4 года

private:
    void_t _parseExchangeRates(std::ctstring_t &date, std::ctstring_t &response, exchange_rate_t *data) const;
        ///< parse response

    xNO_COPY_ASSIGN(PrivaBankApi)
};

xNAMESPACE_END2(xl, package)
//-------------------------------------------------------------------------------------------------