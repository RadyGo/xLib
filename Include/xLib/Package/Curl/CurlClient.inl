/**
 * \file   CurlClient.inl
 * \brief  CURL client
 */


xNAMESPACE_BEGIN2(xl, package)

/**************************************************************************************************
*   public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<typename ValueT>
inline void
CurlClient::setOption(
	const CURLoption a_option,
	const ValueT     a_value
)
{
	CURLcode iRv = ::curl_easy_setopt(_handle.get(), a_option, a_value);

	xTEST_EQ_MSG(iRv, CURLE_OK, "Option: " + std::to_string(a_option) + " - " + strError(iRv));
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, package)