/**
 * \file   Test_Char.h
 * \brief
 */


#pragma once

#include <xLib/xLib.h>
//-------------------------------------------------------------------------------------------------
using namespace xlib;

class Test_Char :
    public Unit
{
public:
                   Test_Char() {}

    virtual bool_t unit() xOVERRIDE;
};
//-------------------------------------------------------------------------------------------------