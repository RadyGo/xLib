/**
 * \file   Test_StdStream.h
 * \brief  test StdStream
 */


#pragma once

#include <xLib/xLib.h>
//-------------------------------------------------------------------------------------------------
using namespace xlib;

class Test_StdStream :
    public Unit
    ///< tests for StdStream
{
public:
                   Test_StdStream() {}

    virtual bool_t unit() xOVERRIDE;
        ///< unit test
};
//-------------------------------------------------------------------------------------------------