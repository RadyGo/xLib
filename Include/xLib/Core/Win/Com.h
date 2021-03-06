/**
 * \file  Com.h
 * \brief Component Object Model (COM)
 */


#pragma once

#include <xLib/Core/Core.h>
//-------------------------------------------------------------------------------------------------
#if xENV_WIN

xNAMESPACE_BEGIN2(xl, core)

class Com
    /// Component Object Model (COM)
{
public:
    explicit  Com(const COINIT &concurrencyModel);
        ///< constructor
    virtual  ~Com();
        ///< destructor

private:
    xNO_COPY_ASSIGN(Com)
};

xNAMESPACE_END2(xl, core)

#endif
//-------------------------------------------------------------------------------------------------
