/**
 * \file  File.inl
 * \brief file
 */


xNAMESPACE_BEGIN2(xl, fs)

//-------------------------------------------------------------------------------------------------
void_t
File::setMode(
    cTranslationMode a_mode
) const
{
    xTEST_NA(a_mode);

    int_t iRv = ::setmode(_nativeHandle(get()), a_mode);
    xTEST_DIFF(iRv, - 1);
}
//-------------------------------------------------------------------------------------------------

/**************************************************************************************************
*    public, static
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
/* static */
bool_t
File::_isFile_impl(
    const FileType &a_type
)
{
    bool_t bRv = false;

    bRv = a_type.isExists(FileType::Type::faDirectory);
    xCHECK_RET(bRv, false);

    bRv = a_type.isExists(FileType::Type::faDevice);
    xCHECK_RET(bRv, false);

    bRv = a_type.isExists(FileType::Type::faReparsePoint);
    xCHECK_RET(bRv, false);

    bRv = a_type.isExists(FileType::Type::faOffline);
    xCHECK_RET(bRv, false);

    return true;
}
//-------------------------------------------------------------------------------------------------
/* static */
bool_t
File::_isExecutable_impl(
	std::ctstring_t &a_filePath
)
{
	DWORD binaryType {-1};
	BOOL blRv = ::GetBinaryType(a_filePath.c_str(), &binaryType);
	xUNUSED(binaryType);
	if (blRv == FALSE) {
		return false;
	}

    return true;
}
//-------------------------------------------------------------------------------------------------
/* static */
void_t
File::_time_impl(
    std::ctstring_t &a_filePath,
    time_t          *a_create,
    time_t          *a_access,
    time_t          *a_modified
)
{
    FILETIME timeCreate   = {0};
    FILETIME timeAccess   = {0};
    FILETIME timeModified = {0};

    HandleNativeInvalid file;

    file = ::CreateFile(a_filePath.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING,
        FileType::faNormal, nullptr);
    xTEST_EQ(file.get().isValid(), true);

    BOOL blRv = ::GetFileTime(file.get(), &timeCreate, &timeAccess, &timeModified);
    xTEST_DIFF(blRv, FALSE);

    Utils::ptrAssignT(a_create,   DateTime::fileToUnix(timeCreate));
    Utils::ptrAssignT(a_access,   DateTime::fileToUnix(timeAccess));
    Utils::ptrAssignT(a_modified, DateTime::fileToUnix(timeModified));
}
//-------------------------------------------------------------------------------------------------
/*static */
void_t
File::_setTime_impl(
    std::ctstring_t &a_filePath,
    const time_t    &a_create,
    const time_t    &a_access,
    const time_t    &a_modified
)
{
    FILETIME timeCreate = {0};
    DateTime::unixToFile(a_create, &timeCreate);

    FILETIME timeAccess = {0};
    DateTime::unixToFile(a_access, &timeAccess);

    FILETIME timeModified = {0};
    DateTime::unixToFile(a_modified, &timeModified);

    HandleNativeInvalid file;

    file = ::CreateFile(a_filePath.c_str(), GENERIC_WRITE, FILE_SHARE_WRITE, nullptr,
        OPEN_EXISTING, FileType::faNormal, nullptr);
    xTEST_EQ(file.get().isValid(), true);

    BOOL blRv = ::SetFileTime(file.get(), &timeCreate, &timeAccess, &timeModified);
    xTEST_DIFF(blRv, FALSE);
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, fs)
