/**
 * \file  StdError_win.inl
 * \brief standard C library last error
 */


xNAMESPACE_BEGIN2(xl, debug)

/**************************************************************************************************
*    public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
/* static */
std::tstring_t
StdError::_format_impl(
    cint_t &a_code
)
{
    std::tstring_t sRv;

#if   xCOMPILER_MINGW
    cptr_ctchar_t error = xSTRERROR(a_code);
    xCHECK_RET(error == nullptr, sRv.append(xT("[Cann't format error message]")));

    sRv.append(error);
#elif xCOMPILER_MS || xCOMPILER_CODEGEAR
    tchar_t buff[64 + 1] = {0};

    errno_t error = xSTRERROR(buff, xARRAY_SIZE(buff), a_code);
    xCHECK_RET(error != 0, sRv.append(xT("[Cann't format error message]")));

    sRv.append(buff);
#endif

    return sRv;
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, debug)
