/**
 * \file   Test_Enum.cpp
 * \brief  test Enum
 */


#include <xLib/xLib.h>


//-------------------------------------------------------------------------------------------------
using namespace xl;

xTEST_CLASS(Test_Enum)
xTEST_UNIT(Test_Enum)
//-------------------------------------------------------------------------------------------------
enum class TestType
{
	Unknown = 0,
	First   = 1,
	Second  = 2,
	Third   = 3,
	Last    = Third + 1
};
//-------------------------------------------------------------------------------------------------
/* virtual */
bool_t
Test_Enum::unit()
{
    xTEST_CASE("str")
    {
        m_sRv = Enum::str(TestType::First);
        xTEST_EQ(m_sRv, std::tstring_t(xT("1")));
    }

    xTEST_CASE("value")
    {
        m_ullRv = Enum::value(TestType::Last);
        xTEST_EQ(m_ullRv, 4ULL);
    }

    xTEST_CASE("cast")
    {
        auto arv = Enum::cast<TestType>(xT("2"));
        xTEST_EQ((int)arv, (int)TestType::Second);
    }

    xTEST_CASE("name")
    {
        m_sRv = Enum::name(TestType::Third);
        xTEST_EQ(m_sRv, std::tstring_t(xT("Third")));
    }

    xTEST_CASE("inc/dec")
    {
        TestType eRv {};

        eRv = Enum::inc(eRv);
        xTEST_EQ((int)eRv, (int)TestType::First);

        eRv = Enum::dec(eRv);
        xTEST_EQ((int)eRv, (int)TestType::Unknown);
    }

    xTEST_CASE("operator <<")
    {
    #if 0
        const size_t enumSize = 5;
        const EnumArray<TestType, enumSize> enums;

        std::stringstream ss;
        for (auto &it_enum : enums) {
            ss << it_enum;
        }
        xTEST_EQ(ss.str(), std::tstring_t(xT("01234")));
    #else
        // std::tcout << TestType::First << std::endl;
        // OStream() << TestType::First << std::endl;

        Enum::print(std::cout, TestType::First); std::cout << std::endl;

        Cout xCout;
        Enum::print(xCout, TestType::Second); Cout() << std::endl;
    #endif
    }

    /**************************************************************************************************
    *   Operators
    *
    **************************************************************************************************/

    enum class Type
    {
        Zero  = 0,
        One   = 1,
        Two   = 2,
        Three = 3
    };

    xTEST_CASE("Operators::operator ++")
    {
        Type t {Type::Zero};
        ++ t;
        xTEST_EQ((int_t)t, (int_t)Type::One);
    }

    xTEST_CASE("Operators::operator --")
    {
        Type t {Type::Three};
        -- t;
        xTEST_EQ((int_t)t, (int_t)Type::Two);
    }

    return true;
}
//-------------------------------------------------------------------------------------------------
