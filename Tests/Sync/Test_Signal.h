/**
 * \file   Test_Signal.h
 * \brief  test Signal
 */


#pragma once

#include <xLib/xLib.h>
//-------------------------------------------------------------------------------------------------
using namespace xlib;

class Test_Signal :
    public Unit
    ///< tests for Signal
{
public:
                   Test_Signal() {}

    virtual bool_t unit() xOVERRIDE;
        ///< unit test
};
//-------------------------------------------------------------------------------------------------