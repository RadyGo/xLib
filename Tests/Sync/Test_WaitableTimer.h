/**
 * \file   Test_WaitableTimer.h
 * \brief
 */


#pragma once

#include <xLib/xLib.h>
//-------------------------------------------------------------------------------------------------
using namespace xlib;

class Test_WaitableTimer :
    public Unit
{
public:
                   Test_WaitableTimer() {}

    virtual bool_t unit() xOVERRIDE;
};
//-------------------------------------------------------------------------------------------------