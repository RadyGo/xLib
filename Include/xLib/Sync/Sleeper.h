/**
 * \file  Sleeper.h
 * \brief sleeper
 */


#pragma once

#include <xLib/Core/Core.h>
#include <xLib/Sync/Event.h>
//-------------------------------------------------------------------------------------------------
xNAMESPACE_BEGIN2(xl, sync)

class Sleeper
    /// sleeper
{
public:
             Sleeper();
        ///< constructor
    virtual ~Sleeper() = default;
        ///< destructor

    void_t   sleep(culong_t &timeoutMsec);
        ///< sleep
    void_t   wakeUp();
        ///< wake up
    bool_t   isSleeping() const xWARN_UNUSED_RV;
        ///< check for sleeping

private:
    Event  _event;    ///< event object

    xNO_COPY_ASSIGN(Sleeper)
};

xNAMESPACE_END2(xl, sync)
//-------------------------------------------------------------------------------------------------
