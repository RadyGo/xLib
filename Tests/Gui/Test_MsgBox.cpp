/**
 * \file   Test_MsgBox.cpp
 * \brief  test MsgBox
 */


#include "Test_MsgBox.h"

//-------------------------------------------------------------------------------------------------
xTEST_UNIT(Test_MsgBox)
//-------------------------------------------------------------------------------------------------
/* virtual */
bool_t
Test_MsgBox::unit()
{
#if xTEST_IGNORE || 1
    xTEST_CASE("show")
    {
        std::ctstring_t  text  = xT("\n::: Message box :::\n\n\n\nSimple test 1\n\nSimple test 2\n");
        std::ctstring_t  title = xT("Simple title");
        MsgBox::ExType type  = MsgBox::tpOk;

        MsgBox::ExModalResult mrRes = MsgBox().show(text, title, type);
        xUNUSED(mrRes);
    }
#endif

    return true;
}
//-------------------------------------------------------------------------------------------------