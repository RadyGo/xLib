/**
 * \file   Test_Flags.h
 * \brief  test Flags
 */


#pragma once

#include <xLib/xLib.h>
//-------------------------------------------------------------------------------------------------
using namespace xlib;

class Test_Flags :
    public Unit
    ///< tests for Flags
{
public:
                   Test_Flags() {}

    virtual bool_t unit() xOVERRIDE;
        ///< unit test
};
//-------------------------------------------------------------------------------------------------