/**
 * \file   Test_ErrorReport.cpp
 * \brief
 */


#include <xLib/xLib.h>

//-------------------------------------------------------------------------------------------------
using namespace xl;

xTEST_CLASS(Test_ErrorReport)
xTEST_UNIT(Test_ErrorReport)
//-------------------------------------------------------------------------------------------------
/* virtual */
bool_t
Test_ErrorReport::unit()
{
    xTEST_CASE("ErrorReport")
    {
        ulong_t        nativeError    = NativeError::get();
        SourceInfoData sourceInfoData = {xFILE, xLINE, xFUNCTION, xCOUNTER};
        SourceInfo     sourceInfo(sourceInfoData);

        ulong_t val1 = 10UL;
        ulong_t val2 = 20UL;

        ErrorReport rpReport(ErrorReport::Type::rtMsgbox, xT("val1"), xT("val2"), val1, val2,
            xT("=="), nativeError, sourceInfo, StackTrace().toString(), xT(""));
    }

    return true;
}
//-------------------------------------------------------------------------------------------------
