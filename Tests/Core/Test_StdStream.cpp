/**
 * \file   Test_StdStream.cpp
 * \brief  test StdStream
 */


#include "Test_StdStream.h"

#include <xLib/Crypt/Random.h>


//-------------------------------------------------------------------------------------------------
xTEST_UNIT(Test_StdStream)
//-------------------------------------------------------------------------------------------------
/* virtual */
bool_t
Test_StdStream::unit()
{
    xTEST_CASE("operator << for std::ustring_t")
    {
        for (size_t i = 0; i < 10; ++ i) {
            std::ustring_t usStr;
            StdRandom    random;

            usStr.resize( random.nextInt(size_t(1), size_t(64)) );
            std::fill_n(usStr.begin(), usStr.size(), static_cast<std::ustring_t::value_type>( random.nextInt(1, 255) ));

            std::tstring_t sVal1 = std::tstring_t(usStr.begin(), usStr.end());

            std::tostringstream_t osOut;   osOut << usStr;
            std::tstring_t sVal2 = osOut.str();

            xTEST_EQ(sVal1, sVal2);
        }
    }

    xTEST_CASE("operator << for std::vector")
    {
        m_vsRv.clear();

        m_vsRv.push_back(xT("Value0"));
        m_vsRv.push_back(xT("Value1"));
        m_vsRv.push_back(xT("Value2"));
        m_vsRv.push_back(xT("Value3"));
        m_vsRv.push_back(xT("Value4"));

        std::tostringstream_t osOut;   osOut << m_vsRv;
        xTEST_EQ(false, osOut.str().empty());

        m_vsRv.clear();
    }

    xTEST_CASE("operator << for std::map")
    {
        m_msRv.clear();

        m_msRv.insert( std::pair<std::tstring_t, std::tstring_t>(xT("Key0"), xT("Value0")) );
        m_msRv.insert( std::pair<std::tstring_t, std::tstring_t>(xT("Key1"), xT("Value1")) );
        m_msRv.insert( std::pair<std::tstring_t, std::tstring_t>(xT("Key2"), xT("Value2")) );
        m_msRv.insert( std::pair<std::tstring_t, std::tstring_t>(xT("Key3"), xT("Value3")) );
        m_msRv.insert( std::pair<std::tstring_t, std::tstring_t>(xT("Key4"), xT("Value4")) );

        std::tostringstream_t osOut;   osOut << m_msRv;
        xTEST_EQ(false, osOut.str().empty());

        m_msRv.clear();
    }

    xTEST_CASE("operator << for std::multimap")
    {
        m_mmsRv.clear();

        m_mmsRv.insert( std::pair<std::tstring_t, std::tstring_t>(xT("Key0"), xT("Value0")) );
        m_mmsRv.insert( std::pair<std::tstring_t, std::tstring_t>(xT("Key1"), xT("Value1")) );
        m_mmsRv.insert( std::pair<std::tstring_t, std::tstring_t>(xT("Key2"), xT("Value2")) );
        m_mmsRv.insert( std::pair<std::tstring_t, std::tstring_t>(xT("Key0"), xT("Value0")) );
        m_mmsRv.insert( std::pair<std::tstring_t, std::tstring_t>(xT("Key1"), xT("Value1")) );

        std::tostringstream_t osOut;   osOut << m_mmsRv;
        xTEST_EQ(false, osOut.str().empty());

        m_mmsRv.clear();
    }

    return true;
}
//-------------------------------------------------------------------------------------------------