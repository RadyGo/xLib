/**
 * \file   Test_Flags.cpp
 * \brief  test Flags
 */


#include <xLib/xLib.h>

//-------------------------------------------------------------------------------------------------
using namespace xl;

xTEST_CLASS(Test_Flags)
xTEST_UNIT(Test_Flags)
//-------------------------------------------------------------------------------------------------
/* virtual */
bool_t
Test_Flags::unit()
{
	// TEST: Flags

    xTEST_CASE("Flags")
    {
        Flags iFlags(10.0);
        std::tcout << xTRACE_VAR(iFlags) << std::endl;
    }

    return true;
}
//-------------------------------------------------------------------------------------------------