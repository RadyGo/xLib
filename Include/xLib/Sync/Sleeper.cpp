/**
 * \file  Sleeper.inl
 * \brief sleeper
 */


#include "Sleeper.h"


xNAMESPACE_BEGIN2(xl, sync)

/**************************************************************************************************
*    public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
Sleeper::Sleeper() :
    _event(false, false)
{
    _event.create();
}
//-------------------------------------------------------------------------------------------------
void_t
Sleeper::sleep(
    culong_t &a_timeoutMsec  ///< in milliseconds
)
{
    // n/a

    Event::ObjectState osRv = _event.wait(a_timeoutMsec);
    xTEST_EQ(osRv == Event::ObjectState::osSignaled || osRv == Event::ObjectState::osTimeout, true);
}
//-------------------------------------------------------------------------------------------------
void_t
Sleeper::wakeUp()
{
    // n/a

    _event.set();
}
//-------------------------------------------------------------------------------------------------
bool_t
Sleeper::isSleeping() const
{
    // n/a

    return _event.isSignaled();
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, sync)
