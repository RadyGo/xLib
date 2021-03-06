/**
 * \file  Mutex.h
 * \brief mutex
 */


#pragma once

#include <xLib/Core/Core.h>
//-------------------------------------------------------------------------------------------------
xNAMESPACE_BEGIN2(xl, sync)

class Mutex
    /// critical section
{
public:
#if   xENV_WIN
    using handle_t = CRITICAL_SECTION;
#elif xENV_UNIX
    using handle_t = pthread_mutex_t;
#endif

                     Mutex() = default;
        ///< constructor
    virtual         ~Mutex();
        ///< destructor

    const handle_t & handle() const xWARN_UNUSED_RV;
        ///< get handle
    void_t           create();
        ///< create
    void_t           lock();
        ///< lock
    bool_t           tryLock() xWARN_UNUSED_RV;
        ///< try lock
    void_t           unlock();
        ///< unlock

private:
    handle_t         _handle {};   ///< mutex native handle

    xNO_COPY_ASSIGN(Mutex)

xPLATFORM_IMPL:
    void_t           _destruc_impl();
    void_t           _create_impl();
    void_t           _lock_impl();
    bool_t           _tryLock_impl() xWARN_UNUSED_RV;
    void_t           _unlock_impl();

};
//-------------------------------------------------------------------------------------------------
xNAMESPACE_END2(xl, sync)
//-------------------------------------------------------------------------------------------------
