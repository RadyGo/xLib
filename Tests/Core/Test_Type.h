/**
 * \file   Test_Type.h
 * \brief
 */


#pragma once

#include <xLib/xLib.h>
//-------------------------------------------------------------------------------------------------
using namespace xlib;

class Test_Type :
    public Unit
{
public:
                   Test_Type() {}

    virtual bool_t unit() xOVERRIDE;
};
//-------------------------------------------------------------------------------------------------