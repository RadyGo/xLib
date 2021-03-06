/**
 * \file   Semaphore.h
 * \brief  semaphore
 */


#pragma once

#include <xLib/Core/Core.h>
//-------------------------------------------------------------------------------------------------
xNAMESPACE_BEGIN2(xl, sync)

class Semaphore
    /// semaphore
{
public:
             Semaphore() = default;
        ///< constructor
    virtual ~Semaphore() = default;
        ///< destructor

private:
    xNO_COPY_ASSIGN(Semaphore)
};

xNAMESPACE_END2(xl, sync)
//-------------------------------------------------------------------------------------------------
