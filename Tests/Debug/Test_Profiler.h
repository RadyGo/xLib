/**
 * \file   Test_Profiler.h
 * \brief
 */


#pragma once

#include <xLib/xLib.h>
//-------------------------------------------------------------------------------------------------
using namespace xlib;

class Test_Profiler :
    public Unit
{
public:
                   Test_Profiler() {}

    virtual bool_t unit() xOVERRIDE;
};
//-------------------------------------------------------------------------------------------------
