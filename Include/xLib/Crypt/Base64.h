/**
 * \file  Base64.h
 * \brief base64
 */


#pragma once

#include <xLib/Core/Core.h>
//-------------------------------------------------------------------------------------------------
xNAMESPACE_BEGIN2(xl, crypt)

class Base64
    /// Base64
{
public:
                Base64() = default;
        ///< constructor
    virtual    ~Base64() = default;
        ///< destructor

    std::string encode(cuchar_t *bytes, std::csize_t &size) xWARN_UNUSED_RV;
        ///< encoding
    std::string encode(std::cstring_t &str) xWARN_UNUSED_RV;
        ///< encoding
    std::string decode(std::cstring_t &str) xWARN_UNUSED_RV;
        ///< decoding
private:
    bool_t      _isValid(cuchar_t &ch) xWARN_UNUSED_RV;
        ///< check char for validness

    xNO_COPY_ASSIGN(Base64)
};

xNAMESPACE_END2(xl, crypt)
//-------------------------------------------------------------------------------------------------
