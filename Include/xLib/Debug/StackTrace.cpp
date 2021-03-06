/**
 * \file   StackTrace.h
 * \brief  stackrace of the caller function
 */


#include "StackTrace.h"

#include <xLib/Core/Const.h>
#include <xLib/Core/String.h>
#include <xLib/Core/Format.h>
#include <xLib/Core/Utils.h>
#include <xLib/Fs/Path.h>
#include <xLib/Log/Trace.h>

xNAMESPACE_ANONYM_BEGIN

std::csize_t elementsNum = 5;
    ///< number of elements

xNAMESPACE_ANONYM_END

#if   xENV_WIN
    #include "Platform/Win/StackTrace_win.inl"
#elif xENV_UNIX
    #include "Platform/Unix/StackTrace_unix.inl"

    #if   xENV_LINUX
        // #include "Platform/Linux/StackTrace_linux.inl"
    #elif xENV_BSD
        // #include "Platform/Bsd/StackTrace_bsd.inl"
    #elif xENV_APPLE
        // #include "Platform/Unix/StackTrace_apple.inl"
    #endif
#endif


xNAMESPACE_BEGIN2(xl, debug)

/**************************************************************************************************
*   public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
StackTrace::StackTrace(
    cStackTraceData &a_data
) :
    _data(a_data)
{
}
//-------------------------------------------------------------------------------------------------
std::tstring_t
StackTrace::toString()
{
    std::tstring_t                  sRv;
    std::vector<std::vec_tstring_t> stack;

    _get_impl(&stack);
    std::reverse(stack.begin(), stack.end());
    _format(stack, &sRv);

    xCHECK_RET(sRv.empty(), Const::strUnknown());

    return sRv;
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*   private
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
void_t
StackTrace::_format(
    std::vector<std::vec_tstring_t> &a_stack,     ///< stack as std::vector
    std::tstring_t                  *a_stackStr   ///< [out] stack as formatted string
) const
{
    xCHECK_DO(a_stack.empty(),         return);
    xCHECK_DO(a_stackStr == nullptr, return);

    std::tstring_t     sRv;
    std::vector<int_t> maxs(::elementsNum, 0);

    // add header
    {
        std::vec_tstring_t stackHeader;
        stackHeader.push_back(xT("Module"));
        stackHeader.push_back(xT("File"));
        stackHeader.push_back(xT("Line"));
        stackHeader.push_back(xT("Offset"));
        stackHeader.push_back(xT("Function"));

        a_stack.insert(a_stack.begin(), stackHeader);
    }

    // get elements max sizes
    for (size_t i = 0; i < ::elementsNum; ++ i) {
        for (auto &it : a_stack) {
            std::csize_t current = it.at(i).size();
            xCHECK_DO(static_cast<int_t>(current) > maxs[i], maxs[i] = static_cast<int_t>(current));
        }
    }

    // formatting
    std::size_t lineNumber = 0;

    xFOR_EACH_CONST(std::vector<std::vec_tstring_t>, it, a_stack) {
        if (it != a_stack.begin()) {
            ++ lineNumber;
        }

		std::tstring_t lineNumberStr;
		{
			if (lineNumber == 0) {
				lineNumberStr = xT("#  ");
			} else {
				lineNumberStr = Format::str(xT("[{}]"), lineNumber);
			}

			if (a_stack.size() >= 10 && lineNumber < 10) {
				lineNumberStr.insert(1, xT(" "));
			}
		}

        std::tstringstream_t stackLine;
        stackLine
            << std::setw(0)       << std::right << lineNumberStr << xT(" ")
            << std::setw(maxs[0]) << std::left  << it->at(0)     << xT("  ")
            << std::setw(maxs[1]) << std::left  << it->at(1)     << xT("  ")
            << std::setw(maxs[2]) << std::right << it->at(2)     << xT("  ")
            << std::setw(maxs[3]) << std::left  << it->at(3)     << xT("  ")
            << std::setw(maxs[4]) << std::left  << it->at(4);

        if (it + 1 != a_stack.end()) {
             stackLine << Const::nl();
        }

        sRv += stackLine.str();
    }

    // out
    a_stackStr->swap(sRv);
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, debug)
