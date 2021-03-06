/**
 * \file  IpcSemaphore.inl
 * \brief semaphore
 */


#include "IpcSemaphore.h"

#include <xLib/Core/Const.h>
#include <xLib/Fs/Path.h>

#if   xENV_WIN
    #include "Platform/Win/IpcSemaphore_win.inl"
#elif xENV_UNIX
    #include "Platform/Unix/IpcSemaphore_unix.inl"

    #if   xENV_LINUX
        // #include "Platform/Linux/IpcSemaphore_linux.inl"
    #elif xENV_BSD
        // #include "Platform/Bsd/IpcSemaphore_bsd.inl"
    #elif xENV_APPLE
        // #include "Platform/Unix/IpcSemaphore_apple.inl"
    #endif
#endif


xNAMESPACE_BEGIN2(xl, sync)

/**************************************************************************************************
*    public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
IpcSemaphore::IpcSemaphore()
{
    xTEST_EQ(_isValid(), false);

    _construct_impl();
}
//-------------------------------------------------------------------------------------------------
IpcSemaphore::~IpcSemaphore()
{
    xTEST_EQ(_isValid(), true);

    _destruct_impl();
}
//-------------------------------------------------------------------------------------------------
long_t
IpcSemaphore::valueMax() const
{
    return _valueMax_impl();
}
//-------------------------------------------------------------------------------------------------
const IpcSemaphore::handle_t &
IpcSemaphore::handle() const
{
    xTEST_EQ(_isValid(), true);

    return _handle;
}
//-------------------------------------------------------------------------------------------------
void_t
IpcSemaphore::create(
    clong_t         &a_initialValue,
    std::ctstring_t &a_name
)
{
    xTEST_EQ(_isValid(), false);
    xTEST_GR(Path::maxSize(), a_name.size());
    xTEST_EQ(0L <= a_initialValue && a_initialValue <= valueMax(), true);

    _create_impl(a_initialValue, a_name);
}
//-------------------------------------------------------------------------------------------------
void_t
IpcSemaphore::open(
    std::ctstring_t &a_name
)
{
    xTEST_EQ(_isValid(), true);
    //name    - n/a

    _open_impl(a_name);
}
//-------------------------------------------------------------------------------------------------
void_t
IpcSemaphore::post() const
{
    xTEST_EQ(_isValid(), true);

    _post_impl();
}
//-------------------------------------------------------------------------------------------------
void_t
IpcSemaphore::wait(
    culong_t &a_timeoutMsec
) const
{
    xTEST_EQ(_isValid(), true);
    xTEST_NA(a_timeoutMsec);

    _wait_impl(a_timeoutMsec);
}
//-------------------------------------------------------------------------------------------------
long_t
IpcSemaphore::value() const
{
    xTEST_EQ(_isValid(), true);

    return _value_impl();
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*    private
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
bool_t
IpcSemaphore::_isValid() const
{
    return _isValid_impl();
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, sync)
