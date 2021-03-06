/**
 * \file  Handle.inl
 * \brief handle
 */


#include <xLib/Test/Test.h>
#include <xLib/Debug/Debug.h>
#include <xLib/Debug/NativeError.h>
#include <xLib/Debug/StdError.h>
#include <xLib/Debug/ErrorReport.h>
#include <xLib/Debug/Debugger.h>
#include <xLib/Debug/StackTrace.h>


xNAMESPACE_BEGIN2(xl, core)

/**************************************************************************************************
*    public - HandlePolicy Std
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<typename T>
std::size_t
HandlePolicy<T, HandlePolicyType::hvStdFile>::_openMax_impl()
{
    return HandlePolicy<native_handle_t, HandlePolicyType::hvNative>::openMax();
}
//-------------------------------------------------------------------------------------------------
template<typename T>
T
HandlePolicy<T, HandlePolicyType::hvStdFile>::_clone_impl(const T &a_handle)
{
    int_t handle = /*::*/fileno(a_handle);
    xTEST_DIFF(handle, - 1);

    native_handle_t nativeHandle = HandlePolicy<native_handle_t, HandlePolicyType::hvNative>::clone(handle);

    return static_cast<T>( xTFDOPEN(nativeHandle, xT("r+")) );  // TODO: [skynowa] clone - open mode
}
//-------------------------------------------------------------------------------------------------
template<typename T>
bool_t
HandlePolicy<T, HandlePolicyType::hvStdFile>::_isValid_impl(const T &a_handle)
{
    return (a_handle != null());
}
//-------------------------------------------------------------------------------------------------
template<typename T>
void_t
HandlePolicy<T, HandlePolicyType::hvStdFile>::_close_impl(T &a_handle)
{
    int_t iRv = std::fclose(a_handle);
    xTEST_DIFF(iRv, xTEOF);

    a_handle = null();
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*    public - HandlePolicy hvMySqlConn
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<typename T>
std::size_t
HandlePolicy<T, HandlePolicyType::hvMySqlConn>::_openMax_impl()
{
	// TODO: [skynowa] _openMax_impl

   /**
	* show variables like "max_connections"
	*
    * +-----------------+-------+
    * | Variable_name   | Value |
    * +-----------------+-------+
    * | max_connections | 100   |
    * +-----------------+-------+
    *
    * set global max_connections = 200;
    */

    return 0;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
T
HandlePolicy<T, HandlePolicyType::hvMySqlConn>::_clone_impl(const T &a_handle)
{
    return a_handle;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
bool_t
HandlePolicy<T, HandlePolicyType::hvMySqlConn>::_isValid_impl(const T &a_handle)
{
    return (a_handle != null());
}
//-------------------------------------------------------------------------------------------------
template<typename T>
void_t
HandlePolicy<T, HandlePolicyType::hvMySqlConn>::_close_impl(T &a_handle)
{
    (void_t)::mysql_close(a_handle);

    a_handle = null();
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*    public - HandlePolicy hvMySqlResult
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<typename T>
std::size_t
HandlePolicy<T, HandlePolicyType::hvMySqlResult>::_openMax_impl()
{
	// TODO: [skynowa] _openMax_impl

    return 0;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
T
HandlePolicy<T, HandlePolicyType::hvMySqlResult>::_clone_impl(const T &a_handle)
{
    return a_handle;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
bool_t
HandlePolicy<T, HandlePolicyType::hvMySqlResult>::_isValid_impl(const T &a_handle)
{
    return (a_handle != null());
}
//-------------------------------------------------------------------------------------------------
template<typename T>
void_t
HandlePolicy<T, HandlePolicyType::hvMySqlResult>::_close_impl(T &a_handle)
{
    (void_t)::mysql_free_result(a_handle);

    a_handle = null();
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*    public - HandlePolicy hvCurl
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<typename T>
std::size_t
HandlePolicy<T, HandlePolicyType::hvCurl>::_openMax_impl()
{
    return static_cast<std::size_t>(CURLOPT_MAXCONNECTS);
}
//-------------------------------------------------------------------------------------------------
template<typename T>
T
HandlePolicy<T, HandlePolicyType::hvCurl>::_clone_impl(const T &a_handle)
{
    return ::curl_easy_duphandle(a_handle);
}
//-------------------------------------------------------------------------------------------------
template<typename T>
bool_t
HandlePolicy<T, HandlePolicyType::hvCurl>::_isValid_impl(const T &a_handle)
{
    return (a_handle != null());
}
//-------------------------------------------------------------------------------------------------
template<typename T>
void_t
HandlePolicy<T, HandlePolicyType::hvCurl>::_close_impl(T &a_handle)
{
    (void_t)::curl_easy_cleanup(a_handle);

    a_handle = null();
}
//-------------------------------------------------------------------------------------------------


#if 0

/**************************************************************************************************
*    public - HandlePolicy hvXXXXXXXXXX
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<typename T>
std::size_t
HandlePolicy<T, HandlePolicyType::hvXXXXXXXXXX>::_openMax_impl()
{
	// TODO: [skynowa] _openMax_impl

    return 0;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
T
HandlePolicy<T, HandlePolicyType::hvXXXXXXXXXX>::_clone_impl(const T &a_handle)
{
    return a_handle;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
bool_t
HandlePolicy<T, HandlePolicyType::hvXXXXXXXXXX>::_isValid_impl(const T &a_handle)
{
    return (a_handle != null());
}
//-------------------------------------------------------------------------------------------------
template<typename T>
void_t
HandlePolicy<T, HandlePolicyType::hvXXXXXXXXXX>::_close_impl(T &a_handle)
{
    // (void_t)::mysql_free_result(a_handle);

    a_handle = null();
}
//-------------------------------------------------------------------------------------------------

#endif

xNAMESPACE_END2(xl, core)
