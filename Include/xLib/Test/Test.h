/**
 * \file  Test.h
 * \brief code testing
 */


#pragma once

//-------------------------------------------------------------------------------------------------
#define xTEST_EQ_MSG_IMPL(reportType, val1, val2, msg) \
    if ( !((val1) == (val2)) ) { \
        culong_t        nativeError    = NativeError::get(); \
        cSourceInfoData sourceInfoData = {xFILE, xLINE, xFUNCTION, xCOUNTER}; \
        SourceInfo      sourceInfo(sourceInfoData); \
        \
        ErrorReport report(reportType, xT(#val1), xT(#val2), (val1), (val2), xLEX_TO_STR(==), \
            nativeError, sourceInfo, StackTrace().toString(), (msg)); \
        Debugger().reportMake(report); \
    }
#define xTEST_DIFF_MSG_IMPL(reportType, val1, val2, msg) \
    if ( !((val1) != (val2)) ) { \
        culong_t        nativeError    = NativeError::get(); \
        cSourceInfoData sourceInfoData = {xFILE, xLINE, xFUNCTION, xCOUNTER}; \
        SourceInfo      sourceInfo(sourceInfoData); \
        \
        ErrorReport report(reportType, xT(#val1), xT(#val2), (val1), (val2), xLEX_TO_STR(!=), \
            nativeError, sourceInfo, StackTrace().toString(), (msg)); \
        Debugger().reportMake(report); \
    }
#define xTEST_LESS_MSG_IMPL(reportType, val1, val2, msg) \
    if ( !((val1) < (val2)) ) { \
        culong_t        nativeError    = NativeError::get(); \
        cSourceInfoData sourceInfoData = {xFILE, xLINE, xFUNCTION, xCOUNTER}; \
        SourceInfo      sourceInfo(sourceInfoData); \
        \
        ErrorReport report(reportType, xT(#val1), xT(#val2), (val1), (val2), xLEX_TO_STR(<), \
            nativeError, sourceInfo, StackTrace().toString(), (msg)); \
        Debugger().reportMake(report); \
    }
#define xTEST_GR_MSG_IMPL(reportType, val1, val2, msg) \
    if ( !((val1) > (val2)) ) { \
        culong_t        nativeError    = NativeError::get(); \
        cSourceInfoData sourceInfoData = {xFILE, xLINE, xFUNCTION, xCOUNTER}; \
        SourceInfo      sourceInfo(sourceInfoData); \
        \
        ErrorReport report(reportType, xT(#val1), xT(#val2), (val1), (val2), xLEX_TO_STR(>), \
            nativeError, sourceInfo, StackTrace().toString(), (msg)); \
        Debugger().reportMake(report); \
    }
#define xTEST_LESS_EQ_MSG_IMPL(reportType, val1, val2, msg) \
    if ( !((val1) <= (val2)) ) { \
        culong_t        nativeError    = NativeError::get(); \
        cSourceInfoData sourceInfoData = {xFILE, xLINE, xFUNCTION, xCOUNTER}; \
        SourceInfo      sourceInfo(sourceInfoData); \
        \
        ErrorReport report(reportType, xT(#val1), xT(#val2), (val1), (val2), xLEX_TO_STR(<=), \
            nativeError, sourceInfo, StackTrace().toString(), (msg)); \
        Debugger().reportMake(report); \
    }
#define xTEST_GR_EQ_MSG_IMPL(reportType, val1, val2, msg) \
    if ( !((val1) >= (val2)) ) { \
        culong_t        nativeError    = NativeError::get(); \
        cSourceInfoData sourceInfoData = {xFILE, xLINE, xFUNCTION, xCOUNTER}; \
        SourceInfo      sourceInfo(sourceInfoData); \
        \
        ErrorReport report(reportType, xT(#val1), xT(#val2), (val1), (val2), xLEX_TO_STR(>=), \
            nativeError, sourceInfo, StackTrace().toString(), (msg)); \
        Debugger().reportMake(report); \
    }
#define xTEST_PTR_MSG_IMPL(reportType, ptr, msg) \
    if ( intptr_t(ptr) == intptr_t(nullptr) ) { \
        culong_t        nativeError    = NativeError::get(); \
        cSourceInfoData sourceInfoData = {xFILE, xLINE, xFUNCTION, xCOUNTER}; \
        SourceInfo      sourceInfo(sourceInfoData); \
        \
        ErrorReport report(reportType, xLEX_TO_STR(nullptr), xT(#ptr), intptr_t(ptr), \
            intptr_t(nullptr), xLEX_TO_STR(!=), nativeError, sourceInfo, \
            StackTrace().toString(), (msg)); \
        Debugger().reportMake(report); \
    }
#define xTEST_PTR_FAIL_MSG_IMPL(reportType, ptr, msg) \
    if ( intptr_t(ptr) != intptr_t(nullptr) ) { \
        culong_t        nativeError    = NativeError::get(); \
        cSourceInfoData sourceInfoData = {xFILE, xLINE, xFUNCTION, xCOUNTER}; \
        SourceInfo      sourceInfo(sourceInfoData); \
        \
        ErrorReport report(reportType, xLEX_TO_STR(nullptr), xT(#ptr), intptr_t(ptr), \
            intptr_t(nullptr), xLEX_TO_STR(==), nativeError, sourceInfo, \
            StackTrace().toString(), (msg)); \
        Debugger().reportMake(report); \
    }
#define xTEST_FAIL_MSG_IMPL(reportType, msg) \
    if ( true ) { \
        culong_t        nativeError    = NativeError::get(); \
        cSourceInfoData sourceInfoData = {xFILE, xLINE, xFUNCTION, xCOUNTER}; \
        SourceInfo      sourceInfo(sourceInfoData); \
        \
        ErrorReport report(reportType, xLEX_TO_STR(false), xT(""), xT(""), xT(""), xT(""), \
            nativeError, sourceInfo, StackTrace().toString(), (msg)); \
        Debugger().reportMake(report); \
    }

// _xREPORT_TYPE
#if   cmOPTION_DEBUG_MODE_STDOUT
    #define _xREPORT_TYPE ErrorReport::Type::rtStdout
#elif cmOPTION_DEBUG_MODE_MSGBOX
    #define _xREPORT_TYPE ErrorReport::Type::rtMsgbox
#elif cmOPTION_DEBUG_MODE_LOG
    #define _xREPORT_TYPE ErrorReport::Type::rtLog
#elif cmOPTION_DEBUG_MODE_STDOUT_LOG
    #define _xREPORT_TYPE ErrorReport::Type::rtStdoutLog
#elif cmOPTION_DEBUG_MODE_EXCEPTION
    #define _xREPORT_TYPE ErrorReport::Type::rtException
#endif

#if defined(_xREPORT_TYPE)
    #define xTEST_EQ(val1, val2) \
        xTEST_EQ_MSG_IMPL      (_xREPORT_TYPE, val1, val2, xT(""))
    #define xTEST_EQ_MSG(val1, val2, msg) \
        xTEST_EQ_MSG_IMPL      (_xREPORT_TYPE, val1, val2, msg)

    #define xTEST_DIFF(val1, val2) \
        xTEST_DIFF_MSG_IMPL    (_xREPORT_TYPE, val1, val2, xT(""))
    #define xTEST_DIFF_MSG(val1, val2, msg) \
        xTEST_DIFF_MSG_IMPL    (_xREPORT_TYPE, val1, val2, msg)

    #define xTEST_LESS(val1, val2) \
        xTEST_LESS_MSG_IMPL    (_xREPORT_TYPE, val1, val2, xT(""))
    #define xTEST_LESS_MSG(val1, val2, msg) \
        xTEST_LESS_MSG_IMPL    (_xREPORT_TYPE, val1, val2, msg)

    #define xTEST_GR(val1, val2) \
        xTEST_GR_MSG_IMPL      (_xREPORT_TYPE, val1, val2, xT(""))
    #define xTEST_GR_MSG(val1, val2, msg) \
        xTEST_GR_MSG_IMPL      (_xREPORT_TYPE, val1, val2, msg)

    #define xTEST_LESS_EQ(val1, val2) \
        xTEST_LESS_EQ_MSG_IMPL (_xREPORT_TYPE, val1, val2, xT(""))
    #define xTEST_LESS_EQ_MSG(val1, val2, msg) \
        xTEST_LESS_EQ_MSG_IMPL (_xREPORT_TYPE, val1, val2, msg)

    #define xTEST_GR_EQ(val1, val2) \
        xTEST_GR_EQ_MSG_IMPL   (_xREPORT_TYPE, val1, val2, xT(""))
    #define xTEST_GR_EQ_MSG(val1, val2, msg) \
        xTEST_GR_EQ_MSG_IMPL   (_xREPORT_TYPE, val1, val2, msg)

    #define xTEST_PTR(ptr) \
        xTEST_PTR_MSG_IMPL     (_xREPORT_TYPE, ptr, xT(""))
    #define xTEST_PTR_MSG(ptr, msg) \
        xTEST_PTR_MSG_IMPL     (_xREPORT_TYPE, ptr, msg)

    #define xTEST_PTR_FAIL(ptr) \
        xTEST_PTR_FAIL_MSG_IMPL(_xREPORT_TYPE, ptr, xT(""))
    #define xTEST_PTR_FAIL_MSG(ptr, msg) \
        xTEST_PTR_FAIL_MSG_IMPL(_xREPORT_TYPE, ptr, msg)

    #define xTEST_FAIL \
        xTEST_FAIL_MSG_IMPL    (_xREPORT_TYPE, xT(""))
    #define xTEST_FAIL_MSG(msg) \
        xTEST_FAIL_MSG_IMPL    (_xREPORT_TYPE, msg)

    #define xTEST(expr) \
        xTEST_EQ_MSG_IMPL      (_xREPORT_TYPE, true, expr, xT(""))
    #define xTEST_MSG(expr, msg) \
        xTEST_EQ_MSG_IMPL      (_xREPORT_TYPE, true, expr, msg)

    #define xTEST_THROW(expr, exception_t)          \
        {                                           \
            bool_t isExpected = false;              \
            try {                                   \
                expr;                               \
            }                                       \
            catch (const exception_t &) {           \
                isExpected = true;                  \
            }                                       \
            catch (...) {                           \
            }                                       \
            xTEST_EQ(isExpected, true);             \
        }
    #define xTEST_THROW_MSG(expr, exception_t, msg) \
        {                                           \
            bool_t isExpected = false;              \
            try {                                   \
                expr;                               \
            }                                       \
            catch (const exception_t &) {           \
                isExpected = true;                  \
            }                                       \
            catch (...) {                           \
            }                                       \
            xTEST_EQ_MSG(isExpected, true, msg);    \
        }

    #define xTEST_THROW_ALL(expr)                   \
        {                                           \
            bool_t isExpected = false;              \
            try {                                   \
                expr;                               \
            }                                       \
            catch (...) {                           \
                isExpected = true;                  \
            }                                       \
            xTEST_EQ(isExpected, true);             \
        }
    #define xTEST_THROW_ALL_MSG(expr, msg)          \
        {                                           \
            bool_t isExpected = false;              \
            try {                                   \
                expr;                               \
            }                                       \
            catch (...) {                           \
                isExpected = true;                  \
            }                                       \
            xTEST_EQ_MSG(isExpected, true, msg);    \
        }

    #define xTEST_THROW_NO(expr)                    \
        {                                           \
            bool_t isExpected = true;               \
            try {                                   \
                expr;                               \
            }                                       \
            catch (...) {                           \
                isExpected = false;                 \
            }                                       \
            xTEST_EQ(isExpected, true);             \
        }
    #define xTEST_THROW_NO_MSG(expr, msg)           \
        {                                           \
            bool_t isExpected = true;               \
            try {                                   \
                expr;                               \
            }                                       \
            catch (...) {                           \
                isExpected = false;                 \
            }                                       \
            xTEST_EQ_MSG(isExpected, true, msg);    \
        }
#else
    // just empty macros
    #define xTEST_EQ(val1, val2)
    #define xTEST_EQ_MSG(val1, val2, msg)

    #define xTEST_DIFF(val1, val2)
    #define xTEST_DIFF_MSG(val1, val2, msg)

    #define xTEST_LESS(val1, val2)
    #define xTEST_LESS_MSG(val1, val2, msg)

    #define xTEST_GR(val1, val2)
    #define xTEST_GR_MSG(val1, val2, msg)

    #define xTEST_LESS_EQ(val1, val2)
    #define xTEST_LESS_EQ_MSG(val1, val2, msg)

    #define xTEST_GR_EQ(val1, val2)
    #define xTEST_GR_EQ_MSG(val1, val2, msg)

    #define xTEST_PTR(ptr)
    #define xTEST_PTR_MSG(ptr, msg)

    #define xTEST_PTR_FAIL(ptr)
    #define xTEST_PTR_FAIL_MSG(ptr, msg)

    #define xTEST_FAIL
    #define xTEST_FAIL_MSG(msg)

    #define xTEST(expr)
    #define xTEST_MSG(expr, msg)

    #define xTEST_THROW(expr, exception_t)
    #define xTEST_THROW_MSG(expr, exception_t, msg)

    #define xTEST_THROW_ALL(expr)
    #define xTEST_THROW_ALL_MSG(expr, msg)

    #define xTEST_THROW_NO(expr)
    #define xTEST_THROW_NO_MSG(expr, msg)
#endif

#define xTEST_NA(var) \
    xUNUSED(var)
    ///< at this point debug code for variable is not applicable
#define xTESTS_NA \
    ;
    ///< at this point debug code for variables is not applicable

#if cmOPTION_TEST_TRACING
    #define xTEST_CASE(caseName) \
        Trace() << xT("\tCase: ") << xT(caseName); \
        for (size_t caseLoops = 0; caseLoops < data.caseLoops; ++ caseLoops)
#else
    #define xTEST_CASE(caseName) \
        for (size_t caseLoops = 0; caseLoops < data.caseLoops; ++ caseLoops)
#endif
    ///< test case

#define xTEST_CLASS(className) \
	class className : \
		public Unit \
	{ \
	public: \
					   className() {} \
		virtual bool_t unit() override; \
	};

#define xTEST_UNIT(unitClassName) \
    int_t xTMAIN(int_t a_argsNum, tchar_t *a_args[]) \
    { \
        bool_t bRv = false; \
        \
        UnitData data; \
        data.unitLoops   = 1; \
        data.caseLoops   = 1; \
        data.tempDirPath = xT(""); \
        data.name        = xLEX_TO_STR(unitClassName); \
        \
        unitClassName unit; \
        unit.setData(data); \
        \
        try {  \
            bRv = unit.run(); \
        } \
        catch (const xl::debug::Exception &a_xlibException) { \
            Trace() << a_xlibException.what(); \
            bRv = false; \
        } \
        catch (const std::exception &a_stdException) { \
            Trace() << a_stdException.what(); \
            bRv = false; \
        } \
        catch (...) { \
            Trace() << xT("Unknown error"); \
            bRv = false; \
        } \
        \
        return bRv ? EXIT_SUCCESS : EXIT_FAILURE; \
    }
//-------------------------------------------------------------------------------------------------
// TODO: STD_VERIFY - fix
#define STD_VERIFY(x) \
    assert(x)
