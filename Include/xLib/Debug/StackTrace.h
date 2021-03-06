/**
 * \file   StackTrace.h
 * \brief  stackrace of the caller function
 */


#pragma once

#include <xLib/Core/Core.h>
//-------------------------------------------------------------------------------------------------
xNAMESPACE_BEGIN2(xl, debug)

struct StackTraceData
    /// StackTrace data
{
    cint_t  skipFramesNum {0};
    cbool_t isWrapFilePaths {true};
    cbool_t isFuncParamsDisable {true};
};
xUSING_CONST(StackTraceData);

class StackTrace
    /// stack trace
{
public:
    explicit       StackTrace(cStackTraceData &data = cStackTraceData());
        ///< constructor
    virtual       ~StackTrace() = default;
        ///< destructor

    std::tstring_t toString() xWARN_UNUSED_RV;
        ///< get stack trace with format output

private:
    StackTraceData _data; ///< data

    void_t _format(std::vector<std::vec_tstring_t> &stack, std::tstring_t *stackStr) const;
        ///< format stack trace

    xNO_COPY_ASSIGN(StackTrace)

xPLATFORM_IMPL:
    void_t _get_impl(std::vector<std::vec_tstring_t> *stack) const;

#if xENV_UNIX
    static
    void_t _addr2Line(cptr_cvoid_t symbolAddress, std::tstring_t *filePath,
    			std::tstring_t *functionName, ulong_t *sourceLine);
#endif
};

xNAMESPACE_END2(xl, debug)
//-------------------------------------------------------------------------------------------------
