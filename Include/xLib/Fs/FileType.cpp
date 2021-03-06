/**
 * \file  FileType.inl
 * \brief file type
 */


#include "FileType.h"

#include <xLib/Core/Utils.h>
#include <xLib/Test/Test.h>
#include <xLib/Debug/Debug.h>
#include <xLib/Debug/NativeError.h>
#include <xLib/Debug/StdError.h>
#include <xLib/Debug/StackTrace.h>
#include <xLib/Debug/ErrorReport.h>
#include <xLib/Debug/Debugger.h>
#include <xLib/Log/Trace.h>

#if   xENV_WIN
    #include "Platform/Win/FileType_win.inl"
#elif xENV_UNIX
    #include "Platform/Unix/FileType_unix.inl"
#endif


xNAMESPACE_BEGIN2(xl, fs)

/**************************************************************************************************
*    public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
FileType::FileType(
    std::ctstring_t &a_filePath
) :
    _filePath(a_filePath)
{
    xTEST_EQ(a_filePath.empty(), false);
}
//-------------------------------------------------------------------------------------------------
std::ctstring_t &
FileType::filePath() const
{
    xTEST_EQ(_filePath.empty(), false);

    return _filePath;
}
//-------------------------------------------------------------------------------------------------
bool_t
FileType::isExists(
    cType a_value
) const
{
    xTEST_EQ(filePath().empty(), false);
    xTEST_NA(a_value);

    xCHECK_RET(a_value == static_cast<Type>(get() & static_cast<FileType::types_t>(a_value)), true);

    return false;
}
//-------------------------------------------------------------------------------------------------
FileType::types_t
FileType::get() const
{
    xTEST_EQ(filePath().empty(), false);

    return _get_impl();
}
//-------------------------------------------------------------------------------------------------
void_t
FileType::set(
    ctypes_t a_values
) const
{
    xTEST_EQ(filePath().empty(), false);
    xTEST_NA(a_values);

    _set_impl(a_values);
}
//-------------------------------------------------------------------------------------------------
void_t
FileType::add(
    cType a_value
) const
{
    xTEST_EQ(filePath().empty(), false);
    xTEST_NA(a_value);

    modify(static_cast<Type>( 0 ), a_value);
}
//-------------------------------------------------------------------------------------------------
void_t
FileType::remove(
    cType a_value
) const
{
    xTEST_EQ(filePath().empty(), false);
    xTEST_NA(a_value);

    modify(a_value, static_cast<Type>( 0 ));
}
//-------------------------------------------------------------------------------------------------
void_t
FileType::modify(
    cType a_valueRemove,
    cType a_valueAdd
) const
{
    xTEST_EQ(filePath().empty(), false);
    xTEST_NA(a_valueRemove);
    xTEST_NA(a_valueAdd);

    // get current attributes
    const types_t valueRemove = static_cast<types_t>( a_valueRemove );
    const types_t valueAdd    = static_cast<types_t>( a_valueAdd );
    types_t       values      = get();

    // change bits
    values &= ~valueRemove;
    values |= valueAdd;

    // change the attributes
    set(values);
}
//-------------------------------------------------------------------------------------------------
void_t
FileType::clear() const
{
    xTEST_EQ(filePath().empty(), false);

    _clear_impl();
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, fs)
