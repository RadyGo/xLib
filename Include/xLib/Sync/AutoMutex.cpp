/**
 * \file  AutoMutex.h
 * \brief auto critical section (using between threads)
 */


#include "AutoMutex.h"

#include <xLib/Sync/Mutex.h>


xNAMESPACE_BEGIN2(xl, sync)

/**************************************************************************************************
*    public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
AutoMutex::AutoMutex(
    Mutex *a_mutex
) :
    _mutex(a_mutex)
{
    _mutex->create();
    _mutex->lock();
}
//-------------------------------------------------------------------------------------------------
AutoMutex::~AutoMutex()
{
    _mutex->unlock();
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, sync)
