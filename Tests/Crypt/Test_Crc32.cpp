/**
 * \file   Test_Crc32.cpp
 * \brief
 */


#include <xLib/xLib.h>

//-------------------------------------------------------------------------------------------------
using namespace xl;

xTEST_CLASS(Test_Crc32)
xTEST_UNIT(Test_Crc32)
//-------------------------------------------------------------------------------------------------
/* virtual */
bool_t
Test_Crc32::unit()
{
    std::ctstring_t filePath = data.tempDirPath  + Const::slash() + xT("Crc32.txt");

    // Prepare
    {
        File file;

        file.create(filePath, File::OpenMode::omCreateReadWrite);
        file.resize(1337LL);
    }

    xTEST_CASE("calcFile, calc, formatHex")
    {
        Crc32 crc32;

        m_ulRv = crc32.calcFile(filePath);
        xTEST_EQ(432847819UL, m_ulRv);

        m_sRv = crc32.formatHex();
        xTEST_EQ(m_sRv, std::tstring_t(xT("19CCBBCB")));
    }

    return true;
}
//-------------------------------------------------------------------------------------------------
