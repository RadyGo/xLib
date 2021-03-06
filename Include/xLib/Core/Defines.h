/**
 * \file  Defines.h
 * \brief predefined macros
 */


#pragma once

//-------------------------------------------------------------------------------------------------
///@name xTEXT, xT (Ansi, Unicode string)
///@{
#if xUNICODE
    #define xTEXT(x) \
        L##x
    #define xT(x) \
        xTEXT(x)
#else
    #define xTEXT(x) \
        x
    #define xT(x) \
        xTEXT(x)
#endif
///@}
//-------------------------------------------------------------------------------------------------
// cmOPTION_TEST_PRIVATE
#if cmOPTION_TEST_PRIVATE
    #define private \
        public
    #define protected \
        public
#endif
    ///< for testing private class data
//-------------------------------------------------------------------------------------------------
///@name xDECL, xDECL_TEMPL
///@{
#if xENV_WIN && cmOPTION_PROJECT_LIB_SHARE
    #if xAPI_EXPORTS
        #define xDECL \
            __declspec(dllexport)
            ///< export DLL information
        #define xDECL_TEMPL
            ///< export DLL information
    #else
        #define xDECL \
            __declspec(dllimport)
            ///< import DLL information
        #define xDECL_TEMPL \
            extern
            ///< import DLL information
    #endif
#elif xENV_UNIX
    #define xDECL
        ///< export, import DLL information
    #define xDECL_TEMPL
        ///< export, import DLL information
#endif
///@}
//-------------------------------------------------------------------------------------------------
// xNO_VTABLE
#if   xENV_WIN
    #define xNO_VTABLE \
        __declspec(novtable)
#elif xENV_UNIX
    #define xNO_VTABLE \
        xNOT_AVAILABLE
#endif
    ///< disable class virtual table (only: Windows)
//-------------------------------------------------------------------------------------------------
// xFORCE_INLINE
#if   xCOMPILER_MINGW
    #define xFORCE_INLINE \
        __attribute__((__always_inline__)) inline
#elif xCOMPILER_MS
    #define xFORCE_INLINE \
        __forceinline
#elif xCOMPILER_CODEGEAR
    #define xFORCE_INLINE \
        inline
#elif xCOMPILER_GNUC
    #define xFORCE_INLINE \
        __attribute__((__always_inline__)) inline
#else
    #define xFORCE_INLINE \
        inline
#endif
    ///< keyword "inline"
//-------------------------------------------------------------------------------------------------
// xNO_INLINE
#if   xCOMPILER_MINGW
    #define xNO_INLINE \
        __attribute__ ((noinline))
#elif xCOMPILER_MS
    #define xNO_INLINE \
        __declspec(noinline)
#elif xCOMPILER_CODEGEAR
    #define xNO_INLINE \
        xNOT_AVAILABLE
#elif xCOMPILER_GNUC
    #define xNO_INLINE \
        __attribute__ ((noinline))
#else
    #define xNO_INLINE \
        xNOT_AVAILABLE
#endif
    ///< keyword "no inline"
//-------------------------------------------------------------------------------------------------
// xSTDCALL
#if   xENV_WIN
    #define xSTDCALL \
        __stdcall
#elif xENV_UNIX
    #define xSTDCALL \
        xNOT_AVAILABLE
#endif
    ///< calling convention
//-------------------------------------------------------------------------------------------------
// xWARN_UNUSED_RV
#if   xCOMPILER_MINGW
    #define xWARN_UNUSED_RV \
        __attribute__((warn_unused_result))
#elif xCOMPILER_MS
    #define xWARN_UNUSED_RV \
        xNOT_AVAILABLE
#elif xCOMPILER_CODEGEAR
    #define xWARN_UNUSED_RV \
        xNOT_AVAILABLE
#elif xCOMPILER_GNUC
    #define xWARN_UNUSED_RV \
        __attribute__((warn_unused_result))
#else

#endif
    ///< give a warning if the return value of function was not used
//-------------------------------------------------------------------------------------------------
///@name namespace
///@{
#define xNAMESPACE_ANONYM_BEGIN \
    namespace {
    ///< begin anonymous namespace
#define xNAMESPACE_ANONYM_END \
    }
    ///< end anonymous namespace

#define xNAMESPACE_BEGIN(n1) \
    namespace n1 {
    ///< begin namespace
#define xNAMESPACE_END(n1) \
    }
    ///< end namespace

#define xNAMESPACE_BEGIN2(n1, n2) \
    namespace n1 { \
    namespace n2 {
    ///< begin namespaces
#define xNAMESPACE_END2(n1, n2) \
    }}
    ///< end namespaces

#define xNAMESPACE_BEGIN3(n1, n2, n3) \
    namespace n1 { \
    namespace n2 { \
    namespace n3 {
    ///< begin namespaces
#define xNAMESPACE_END3(n1, n2, n3) \
    }}}
    ///< end namespaces
///@}
//-----------------------------------------------------------------------------------------------
///@name usings
///@{
#define xUSING_CONST(t) \
    using c##t = const t
    ///< using const types
#define xUSING_PTR_CONST(t) \
    using cptr_##c##t = const t * const
    ///< using const types
///@}
//-----------------------------------------------------------------------------------------------
///@name Converters
///@{
#if xUNICODE
    #define xA2T(a) \
        ( String::castW(a) )
        ///< convert std::string to std::wstring
    #define xT2A(t) \
        ( String::castA(t) )
        ///< convert std::wstring to std::string
#else
    #define xA2T(a) \
        ( a )
        ///< convert std::string to std::wstring
    #define xT2A(t) \
        ( t )
        ///< convert std::wstring to std::string
#endif

#define xT2U(t) \
    std::ustring_t( (t).begin(),  (t).begin()  + (t).size()  )
    ///< convert std::tstring_t to std::ustring_t
#define xU2T(u) \
    std::tstring_t( (u).begin(), (u).begin() + (u).size() )
    ///< convert std::ustring_t to std::tstring_t
///@}
//-------------------------------------------------------------------------------------------------
///@name Utils
///@{
#define xARRAY_SIZE(a) \
    ( sizeof(a) / sizeof((a)[0]) )
    ///< get array size
#define xSWITCH_CASE_RETURN_STRINGISED(x) \
    case x: return #x
    ///< help for switch
#define xLAMBDA(return_type, name, function) \
    struct \
    { \
        return_type operator () function \
    } name
    ///< lambda (local function)
///@}
//-------------------------------------------------------------------------------------------------
// xUNUSED
#if   (xCOMPILER_MINGW || xCOMPILER_MS)
    #define xUNUSED(arg) \
    ( static_cast<void>( arg ) )
#elif xCOMPILER_CODEGEAR
    #define xUNUSED(arg) \
    ( static_cast<void>( arg ) )
#elif xCOMPILER_GNUC
    #define xUNUSED(arg) \
    { static_cast<void>( true ? (arg) : (arg) ); }
#else
    #define xUNUSED(arg) \
    ( static_cast<void>( arg ) )
#endif
    ///< hide "unused variable" warnings
//-------------------------------------------------------------------------------------------------
// xUNKNOWN_CSTRING
#define xUNKNOWN_CSTRING \
    xT("[unknown]")
    ///< C string as unknown value
//-------------------------------------------------------------------------------------------------
///@name Temporary enable/disable code
///@{
#define xTEMP_ENABLED  1
    ///< temporary code enabled
#define xTEMP_DISABLED 0
    ///< temporary code disable
#define xDEPRECIATE    0
    ///< temporary code depreciate
#define xTODO          0
    ///< to do code
#define xCAN_REMOVE    0
    ///< can remove code
#define xTEST_IGNORE   0
    ///< ignore test code
#define xNOT_COMPILE   0
    ///< code not compile
#define xREVIEW        1
    ///< code for review
#define xCOMMENT       0
    ///< comment for code
#define xNA            // n/a
    ///< at this point the code is not applicable
#define xNOT_IMPL      // n/a
    ///< code not implemented
#define xNOT_AVAILABLE // n/a
    ///< code not available
///@}
//-------------------------------------------------------------------------------------------------
///@name Build in macros
///@{
// xFILE
#if defined(__FILE__)
    #define xFILE \
        xT(__FILE__)
#else
    #define xFILE \
        xUNKNOWN_CSTRING
#endif
    ///< source file path

// xBASE_FILE
#define xBASE_FILE \
    ((std::strrchr(xFILE, '/') == nullptr) ? xFILE : std::strrchr(xFILE, '/') + 1)
    ///< file basename

// xLINE
#if defined(__LINE__)
    #define xLINE \
        __LINE__
#else
    #define xLINE \
        0
#endif
    ///< source code line number

// xFUNCTION
#if   xCOMPILER_MS
    #define xFUNCTION \
        xT(__FUNCTION__)
#elif xCOMPILER_CODEGEAR
    #define xFUNCTION \
        xT(__FUNC__)
#elif xCOMPILER_GNUC || xCOMPILER_MINGW
    #define xFUNCTION \
        xA2T(__PRETTY_FUNCTION__)
#else
    #define xFUNCTION \
        xUNKNOWN_CSTRING
#endif
    ///< source function name

#define xSOURCE_AT \
    xFILE xT(":") xSTRINGIZE(xLINE)
    ///< source information

#define xSOURCE_AT_EXPR(expr) \
    xFILE xT(":") xSTRINGIZE(xLINE) #expr
    ///< source information

// xDATE
#if defined(__DATE__)
    #define xDATE \
        xT(__DATE__)
#else
    #define xDATE \
        xUNKNOWN_CSTRING
#endif
    ///< build source date stamp

// xTIME
#if defined(__TIME__)
    #define xTIME \
        xT(__TIME__)
#else
    #define xTIME \
        xUNKNOWN_CSTRING
#endif
    ///< build source time stamp

// xDATETIME
#if defined(xDATE) && defined(xTIME)
    #define xDATETIME \
        xDATE xT(" ") xTIME
#else
    #define xDATETIME \
        xUNKNOWN_CSTRING
#endif
    ///< build source date time stamp

// xCOUNTER
#if defined(__COUNTER__)
    #define xCOUNTER \
        __COUNTER__
#else
    #define xCOUNTER \
        0
#endif
    ///< Expands to an integer starting with 0 and
    ///< incrementing by 1 every time it is used in a compiland
///@}
//-------------------------------------------------------------------------------------------------
///@name Function params
///@{
#define xIN
    ///< incoming param
#define xOUT
    ///< out coming param
#define xIN_OUT
    ///< incoming and out coming param
///@}
//-------------------------------------------------------------------------------------------------
///@name Variable arguments
///@{
#if defined(va_start)
    #define xVA_START(val, fmt) \
        ( va_start(val, fmt) )
#endif
    ///< initializes ap for subsequent use by xVA_ARG() and xVA_END(), and must be called first

#if defined(va_copy)
    #define xVA_COPY(dest, src) \
        ( va_copy(dest, src) )
#elif defined(__va_copy)
    #define xVA_COPY(dest, src) \
        ( __va_copy(dest, src) )
#else
    #define xVA_COPY(dest, src) \
        ( (void_t *)std::memcpy(&dest, &src, sizeof(va_list)) )
#endif
    ///< copy xVA_LIST

#if defined(va_end)
    #define xVA_END(val) \
        ( va_end(val) )
#endif
    ///< Each invocation of xVA_START() must be matched by a corresponding invocation of xVA_END()
    ///< in the same function
///@}
//-------------------------------------------------------------------------------------------------
///@name Variable arguments utils
///@{
#define xVA_TYPES_1                 class T1
#define xVA_TYPES_2   xVA_TYPES_1,  class T2
#define xVA_TYPES_3   xVA_TYPES_2,  class T3
#define xVA_TYPES_4   xVA_TYPES_3,  class T4
#define xVA_TYPES_5   xVA_TYPES_4,  class T5
#define xVA_TYPES_6   xVA_TYPES_5,  class T6
#define xVA_TYPES_7   xVA_TYPES_6,  class T7
#define xVA_TYPES_8   xVA_TYPES_7,  class T8
#define xVA_TYPES_9   xVA_TYPES_8,  class T9
#define xVA_TYPES_10  xVA_TYPES_9,  class T10
#define xVA_TYPES_11  xVA_TYPES_10, class T11
#define xVA_TYPES_12  xVA_TYPES_11, class T12
#define xVA_TYPES_13  xVA_TYPES_12, class T13
#define xVA_TYPES_14  xVA_TYPES_13, class T14
#define xVA_TYPES_15  xVA_TYPES_14, class T15
#define xVA_TYPES_16  xVA_TYPES_15, class T16
#define xVA_TYPES_17  xVA_TYPES_16, class T17
#define xVA_TYPES_18  xVA_TYPES_17, class T18
#define xVA_TYPES_19  xVA_TYPES_18, class T19
#define xVA_TYPES_20  xVA_TYPES_19, class T20

#define xVA_VARS_1                 const T1  &a_v1
#define xVA_VARS_2    xVA_VARS_1,  const T2  &a_v2
#define xVA_VARS_3    xVA_VARS_2,  const T3  &a_v3
#define xVA_VARS_4    xVA_VARS_3,  const T4  &a_v4
#define xVA_VARS_5    xVA_VARS_4,  const T5  &a_v5
#define xVA_VARS_6    xVA_VARS_5,  const T6  &a_v6
#define xVA_VARS_7    xVA_VARS_6,  const T7  &a_v7
#define xVA_VARS_8    xVA_VARS_7,  const T8  &a_v8
#define xVA_VARS_9    xVA_VARS_8,  const T9  &a_v9
#define xVA_VARS_10   xVA_VARS_9,  const T10 &a_v10
#define xVA_VARS_11   xVA_VARS_10, const T11 &a_v11
#define xVA_VARS_12   xVA_VARS_11, const T12 &a_v12
#define xVA_VARS_13   xVA_VARS_12, const T13 &a_v13
#define xVA_VARS_14   xVA_VARS_13, const T14 &a_v14
#define xVA_VARS_15   xVA_VARS_14, const T15 &a_v15
#define xVA_VARS_16   xVA_VARS_15, const T16 &a_v16
#define xVA_VARS_17   xVA_VARS_16, const T17 &a_v17
#define xVA_VARS_18   xVA_VARS_17, const T18 &a_v18
#define xVA_VARS_19   xVA_VARS_18, const T19 &a_v19
#define xVA_VARS_20   xVA_VARS_19, const T20 &a_v20

#define xVA_VALUES_1                 v1
#define xVA_VALUES_2  xVA_VALUES_1,  v2
#define xVA_VALUES_3  xVA_VALUES_2,  v3
#define xVA_VALUES_4  xVA_VALUES_3,  v4
#define xVA_VALUES_5  xVA_VALUES_4,  v5
#define xVA_VALUES_6  xVA_VALUES_5,  v6
#define xVA_VALUES_7  xVA_VALUES_6,  v7
#define xVA_VALUES_8  xVA_VALUES_7,  v8
#define xVA_VALUES_9  xVA_VALUES_8,  v9
#define xVA_VALUES_10 xVA_VALUES_9,  v10
#define xVA_VALUES_11 xVA_VALUES_10, v11
#define xVA_VALUES_12 xVA_VALUES_11, v12
#define xVA_VALUES_13 xVA_VALUES_12, v13
#define xVA_VALUES_14 xVA_VALUES_13, v14
#define xVA_VALUES_15 xVA_VALUES_14, v15
#define xVA_VALUES_16 xVA_VALUES_15, v16
#define xVA_VALUES_17 xVA_VALUES_16, v17
#define xVA_VALUES_18 xVA_VALUES_17, v18
#define xVA_VALUES_19 xVA_VALUES_18, v19
#define xVA_VALUES_20 xVA_VALUES_19, v20
///@}
//-------------------------------------------------------------------------------------------------
///@name Formattong qualifiers
///@{
#if   xENV_WIN
    #ifdef xARCH_BITS_32
        #define xPR_SIZET xT("u")
            ///< qualifier for std::size_t
        #define xPR_I64d  xT("lld")
            ///< qualifier for  long_t long_t int_t
        #define xPR_I64u  xT("llu")
            ///< qualifier for unsigned long_t long_t in
        #define xPR_I64x  xT("llx")
            ///< qualifier for long_t long_t int_t (hex)
        #define xPR_I64X  xT("llX")
            ///< qualifier for long_t long_t int_t (hex)
    #else
        #define xPR_SIZET xT("I")
            ///< qualifier for std::size_t
        #define xPR_I64d  xT("I64d")
            ///< qualifier for  long_t long_t int_t
        #define xPR_I64u  xT("I64u")
            ///< qualifier for unsigned long_t long_t int_t
        #define xPR_I64x  xT("I64x")
            ///< qualifier for long_t long_t int_t (hex)
        #define xPR_I64X  xT("I64X")
            ///< qualifier for long_t long_t int_t (hex)
    #endif
#elif xENV_UNIX
    #ifdef xARCH_BITS_32
        #define xPR_SIZET xT("zu")
            ///< qualifier for std::size_t
        #define xPR_I64d  xT("lld")
            ///< qualifier for  long_t long_t int_t
        #define xPR_I64u  xT("llu")
            ///< qualifier for unsigned long_t long_t int_t
        #define xPR_I64x  xT("llx")
            ///< qualifier for long_t long_t int_t (hex)
        #define xPR_I64X  xT("llX")
            ///< qualifier for long_t long_t int_t (hex)
    #else
        #define xPR_SIZET xT("zu")
            ///< qualifier for std::size_t
        #define xPR_I64d  xT("lld")
            ///< qualifier for  long_t long_t int_t
        #define xPR_I64u  xT("llu")
            ///< qualifier for unsigned long_t long_t int_t
        #define xPR_I64x  xT("llx")
            ///< qualifier for long_t long_t int_t (hex)
        #define xPR_I64X  xT("llX")
            ///< qualifier for long_t long_t int_t (hex)
    #endif
#endif
    ///< qualifiers
///@}
//-------------------------------------------------------------------------------------------------
// xDIR_TEMP temporary directory
#if   xENV_WIN
    #if defined(P_tmpdir)
        #define xDIR_TEMP \
            xT(P_tmpdir)
    #else
        #define xDIR_TEMP \
            xT("C:\\Temp")  // custom define
    #endif
#elif xENV_UNIX
    #if defined(P_tmpdir)
        #define xDIR_TEMP \
            xT(P_tmpdir)
    #else
        #define xDIR_TEMP \
            xT("/tmp")      // custom define
    #endif
#endif
    ///< temporary directory
//-------------------------------------------------------------------------------------------------
///@name xNATIVE_HANDLE_NULL, xNATIVE_HANDLE_INVALID
///@{
#if   xENV_WIN
    #define xNATIVE_HANDLE_NULL \
        ( static_cast<native_handle_t>( nullptr ) )
        ///< native handle value "null"
    #define xNATIVE_HANDLE_INVALID \
        ( static_cast<native_handle_t>( INVALID_HANDLE_VALUE ) )
        ///< native handle value "invalid"
#elif xENV_UNIX
    #define xNATIVE_HANDLE_NULL \
        ( static_cast<native_handle_t>( 0 ) )
        ///< native handle value "null"
    #define xNATIVE_HANDLE_INVALID \
        ( static_cast<native_handle_t>( - 1 ) )
        ///< native handle value "invalid"
#endif
///@}
//-------------------------------------------------------------------------------------------------
///@name xFIND_DIR_HANDLE_NULL
///@{
#if   xENV_WIN
    #define xFIND_DIR_HANDLE_NULL \
        ( static_cast<find_dir_handle_t>( INVALID_HANDLE_VALUE ) )
        ///< find directory handle
#elif xENV_UNIX
    #define xFIND_DIR_HANDLE_NULL \
        ( static_cast<find_dir_handle_t>( nullptr ) )
        ///< find directory handle
#endif
///@}
//-------------------------------------------------------------------------------------------------
///@name xSOCKET_ERROR, xSOCKET_HANDLE_INVALID
///@{
#if xENV_WIN
    #define xSOCKET_ERROR \
        ( SOCKET_ERROR )
        ///< socket native handle value "error"
    #define xSOCKET_HANDLE_INVALID \
        ( static_cast<socket_t>( INVALID_SOCKET ) )
        ///< socket native handle value "null"
#elif xENV_UNIX
    #define xSOCKET_ERROR \
        ( - 1 )
        ///< socket native handle value "error"
    #define xSOCKET_HANDLE_INVALID \
        ( static_cast<socket_t>( - 1 ) )
        ///< socket native handle value "null"
#endif
///@}
//-------------------------------------------------------------------------------------------------
// xWND_NATIVE_HANDLE_NULL
#if xENV_WIN
    #define xWND_NATIVE_HANDLE_NULL \
        ( static_cast<HWND>( nullptr ) )
        ///< window native handle value "null"
#endif

//-------------------------------------------------------------------------------------------------
///@name Generic test for success on any status value (for Windows XP)
///@{
#if xENV_WIN
    #ifndef NT_SUCCESS
        #define NT_SUCCESS(Status) \
            (((NTSTATUS)(Status)) >= 0)
            ///< generic test for success on any status value
    #endif

    #ifndef NT_INFORMATION
        #define NT_INFORMATION(Status) \
            ((((ULONG)(Status)) >> 30) == 1)
            ///< generic test for success on any status value
    #endif

    #ifndef NT_WARNING
        #define NT_WARNING(Status) \
            ((((ULONG)(Status)) >> 30) == 2)
            ///< generic test for success on any status value
    #endif

    #ifndef NT_ERROR
        #define NT_ERROR(Status) \
            ((((ULONG)(Status)) >> 30) == 3)
            ///< generic test for success on any status value
    #endif
#endif
///@}
//-------------------------------------------------------------------------------------------------
#if xENV_WIN
    #define xHOTKEY(modifier, key) \
        ((((modifier) & 0xFF) << 8) | ((key) & 0xFF))
        ///< hot key
#endif
//-------------------------------------------------------------------------------------------------
///@name xFOR_EACH
///@{
#define xFOR_EACH(it_t, it, cont) \
    for (it_t::iterator               it((cont).begin());  it != (cont).end();  ++ it)
    ///< iterate STL container (using it_t::iterator)

#define xFOR_EACH_CONST(it_t, it, cont) \
    for (it_t::const_iterator         it((cont).begin());  it != (cont).end();  ++ it)
    ///< iterate STL container (using it_t::const_iterator)

#define xFOR_EACH_R(it_t, it, cont) \
    for (it_t::reverse_iterator       it((cont).rbegin()); it != (cont).rend(); ++ it)
    ///< iterate STL container (using it_t::reverse_iterator)

#define xFOR_EACH_R_CONST(it_t, it, cont) \
    for (it_t::const_reverse_iterator it((cont).rbegin()); it != (cont).rend(); ++ it)
    ///< iterate STL container (using it_t::const_reverse_iterator)
///@}

///@name xFOR_ARRAY
///@{
#define xFOR_ARRAY(i, cont) \
    for (size_t i = 0; i < Utils::arraySizeT(cont); ++ i)
///@}
//-------------------------------------------------------------------------------------------------
///@name xTHROW_REPORT, xTRY, xCATCH_ALL
///@{
#define xTHROW_REPORT(msg) \
    { \
        culong_t         nativeError    = NativeError::get(); \
        SourceInfoData   sourceInfoData = {xFILE, xLINE, xFUNCTION, xCOUNTER}; \
        SourceInfo       sourceInfo(sourceInfoData); \
        std::ctstring_t &stackTrace     = StackTrace().toString(); \
        \
        ErrorReport report(nativeError, sourceInfo, stackTrace, msg); \
        \
        throw Exception() << report.toString(); \
    }
    ///< like throw
#define xTRY \
    try
    ///< like try
#define xCATCH_ALL \
    catch (const Exception &a_ex) {          \
        xTEST_FAIL_MSG(a_ex.what());         \
    }                                        \
    catch (const std::exception &a_ex) {     \
        std::string msg = a_ex.what();       \
        xTEST_FAIL_MSG(xA2T(msg));          \
    }                                        \
    catch (...) {                            \
        xTEST_FAIL_MSG(xT("unknown error")); \
    }
    ///< catch Exception, std::exception and all other exceptions
///@}
//-------------------------------------------------------------------------------------------------
///@name Class disallows
///@{
#define xNO_DEFAULT_CONSTRUCT(className) \
    className() = delete;
	///< disallow default constructor
#define xNO_COPY(className) \
    className(const className &) = delete;
    ///< disallow copy
#define xNO_MOVE(className) \
    className(className &&) = delete;
    ///< disallow move
#define xNO_ASSIGN(className) \
    className & operator = (const className &) = delete;
    ///< disallow assign
#define xNO_MOVE_ASSIGN(className) \
    className & operator = (className &&) = delete;
    ///< disallow move assign
#define xNO_COPY_ASSIGN(className) \
    xNO_COPY(className) \
    xNO_MOVE(className) \
    xNO_ASSIGN(className) \
    xNO_MOVE_ASSIGN(className)
    ///< disallow copy, move, assign, move assign
#define xNO_INSTANCE(className) \
    className() = delete;
    ///< disallow make instance
#define xNO_HEAP \
    private: \
        void_t* operator new    (size_t) throw() { return nullptr; } \
        void_t  operator delete (void_t*)        { ; }
    ///< disallow object on heap
#define xNO_ARRAY_HEAP \
    private: \
        void_t* operator new []    (size_t) throw() { return nullptr; } \
        void_t  operator delete [] (void_t*)        { ; }
    ///< disallow array on heap
///@}
//-------------------------------------------------------------------------------------------------
///@name Class properties
///@{
// TEST: Defines - xPROPERTY, add tests
#define xPROPERTY(type, name, Name) \
    public:\
        type & name()                         { return _##name; } \
        void   set##Name(const type& a_value) { _##name = a_value; } \
    private: \
        type _##name {}
    ///< property with read, write

#define xPROPERTY_CONST(type, name) \
    public:\
        const type & name() const { return _##name; } \
    private: \
        const type _##name {}
    ///< property with read

#define xPROPERTY_STATIC(type, name, Name) \
    public:\
        static type & name()                         { return _##name; } \
        static void   set##Name(const type& a_value) { _##name = a_value; } \
    private: \
        static type _##name
    ///< property with read, write (static)

#define xPROPERTY_CONST_STATIC(type, name, Name) \
    public:\
        static const type & name()                         { return _##name; } \
        static void         set##Name(const type& a_value) { _##name = a_value; } \
    private: \
        static type _##name
    ///< property with read, write (static)
///@}
//-------------------------------------------------------------------------------------------------
