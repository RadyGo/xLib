/**
 * \file  Crc32.h
 * \brief Crc32
 */


#pragma once

#include <xLib/Core/Core.h>
//-------------------------------------------------------------------------------------------------
xNAMESPACE_BEGIN2(xl, crypt)

class Crc32
    /// Crc32
{
public:
                   Crc32() = default;
        ///< constructor
    virtual       ~Crc32() = default;
        ///< destructor

    ulong_t        calc(uchar_t *buff, culong_t &buffSize) xWARN_UNUSED_RV;
        ///< calculate
    ulong_t        calcFile(std::ctstring_t &filePath) xWARN_UNUSED_RV;
        ///< calculate

    std::tstring_t formatHex() const xWARN_UNUSED_RV;
        ///< format Crc32 like "0AADDEA0"

private:
    ulong_t _crc32 {};

    xNO_COPY_ASSIGN(Crc32)
};

xNAMESPACE_END2(xl, crypt)
//-------------------------------------------------------------------------------------------------
