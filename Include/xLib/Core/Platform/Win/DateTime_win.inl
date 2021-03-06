/**
 * \file  DateTime.inl
 * \brief date, time
 */


xNAMESPACE_BEGIN2(xl, core)

/**************************************************************************************************
*    public: static
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
/* static */
DateTime
DateTime::_current_impl()
{
    SYSTEMTIME dateTime = {0};

    (void_t)::GetLocalTime(&dateTime);
    xTEST_EQ(Validator::datetime(dateTime.wYear, dateTime.wMonth, dateTime.wDay,
        dateTime.wHour, dateTime.wMinute, dateTime.wSecond, dateTime.wMilliseconds), true);

    return DateTime(dateTime.wYear, dateTime.wMonth, dateTime.wDay,
        dateTime.wHour, dateTime.wMinute, dateTime.wSecond, dateTime.wMilliseconds);
}
//-------------------------------------------------------------------------------------------------
/* static */
longlong_t
DateTime::fileToInt64(
    const FILETIME &a_fileTime
)
{
    return Int64ShllMod32(a_fileTime.dwHighDateTime, 32) | a_fileTime.dwLowDateTime;
}
//-------------------------------------------------------------------------------------------------
/* static */
void_t
DateTime::unixToFile(
    const time_t &a_unixTime,
    FILETIME     *a_fileTime
)
{
    xTEST_NA(a_unixTime);
    xTEST_PTR(a_fileTime);

    longlong_t llRv = 0LL;

    llRv = Int32x32To64(a_unixTime, 10000000) + 116444736000000000;
    a_fileTime->dwLowDateTime  = static_cast<ulong_t>( llRv );
    a_fileTime->dwHighDateTime = llRv >> 32;
}
//-------------------------------------------------------------------------------------------------
/* static */
time_t
DateTime::fileToUnix(
    const FILETIME &a_fileTime
)
{
    // TEST: DateTime::fileToUnix()

    const __int64 nanosecsBetweenEpochs = 116444736000000000LL;

    __int64 llRv = 0LL;

    llRv = (static_cast<__int64>( a_fileTime.dwHighDateTime ) << 32) + a_fileTime.dwLowDateTime;
    llRv -= nanosecsBetweenEpochs;
    llRv /= 10000000;

    return static_cast<time_t>( llRv );
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, core)
