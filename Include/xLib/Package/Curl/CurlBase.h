/**
 * \file  CurlBase.h
 * \brief CURL client
 */


#pragma once


#include <xLib/Package/Curl/CurlClient.h>
//-------------------------------------------------------------------------------------------------
xNAMESPACE_BEGIN2(xl, package)

struct CurlBaseData
    /// base data
{
	bool        isUseHeader {true};

	bool        isSslVerifyPeer {true};
	bool        isSslVerifyHost {true};
	long int    ssl_version {CURL_SSLVERSION_DEFAULT};
	std::string ssl_cert;
	std::string ssl_cert_pass;

	HttpVersion http_version {HttpVersion::Default};

	bool        isVerbose {true};

	std::string cookie_file;
	std::string add_cookie;

	std::string encoding_param;
	std::string ciphers;

	char        error_str[255] {};

	int         timeout_sec {};
	int         timeout_ms {};
	int         continue_timeout_ms {};

	ProxyType   proxy_type {ProxyType::Http};
	std::string proxy;
	std::string proxy_userpass;
	std::string userpass;

	curl_slist *slist {};
	std::map_tstring_t add_header;

	std::string referer;
	std::string accept_encoding;
	std::string agent;

	bool        isFollowLocation {true};
	int         max_redirects {100};

	bool        isDebugHeader {true};


	std::string debug_text;
	std::string debug_header_in;
	std::string debug_header_out;
	std::string debug_data_in;
	std::string debug_data_out;
	std::string debug_ssl_data_in;
	std::string debug_ssl_data_out;
	DebugData   debug_data;

	// out
	std::string content_type;
	std::string effective_url;
	int         response_code {};
	double      total_time_sec {};
};
xTYPEDEF_CONST(CurlBaseData);

class CurlBase :
	public CurlClient
    ///< CURL base
{
protected:
	CurlBaseData &data;

    explicit CurlBase(CurlBaseData &data);
        ///< constructor
    virtual ~CurlBase();
        ///< destructor

    void     setProtocols(clong_t bitMask);
		///< set allowed protocols
    void     setOptionsDefault();
        ///< set options in
    void     getInfos();
        ///< get options out
};

xNAMESPACE_END2(xl, package)
//-------------------------------------------------------------------------------------------------