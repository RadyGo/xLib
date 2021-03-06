/**
 * \file   Service.h
 * \brief  service
 */


#pragma once

#include <xLib/Core/Core.h>
//-------------------------------------------------------------------------------------------------
xNAMESPACE_BEGIN2(xl, sync)

class Service
    ///< service
{
public:
             Service() = default;
        ///< constructor
    virtual ~Service() = default;
        ///< destructor

    void_t   create();
        ///< create
    void_t   start();
        ///< start
    void_t   stop();
        ///< stop
    void_t   restart();
        ///< restart
    void_t   close();
        ///< restart

private:
    xNO_COPY_ASSIGN(Service)

xPLATFORM_IMPL:
    void_t   _create_impl();
    void_t   _start_impl();
    void_t   _stop_impl();
    void_t   _close_impl();
};

xNAMESPACE_END2(xl, sync)
//-------------------------------------------------------------------------------------------------
