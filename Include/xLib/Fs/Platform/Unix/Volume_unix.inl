/**
 * \file  Volume.inl
 * \brief volume
 */


xNAMESPACE_BEGIN2(xl, fs)

/**************************************************************************************************
*    public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
std::tstring_t
Volume::_label_impl() const
{
    std::tstring_t sRv;

    // REVIEW: just get the dir name ??
    if (path() == Const::unixSlash()) {
        sRv = Const::unixSlash();
    } else {
        sRv = Path( path() ).fileName();
    }

    return sRv;
}
//-------------------------------------------------------------------------------------------------
bool_t
Volume::_isValid_impl() const
{
    xCHECK_RET(path().empty(),                         false);
    xCHECK_RET(path().at(0) != Const::slash().at(0), false);

    return true;
}
//-------------------------------------------------------------------------------------------------
bool_t
Volume::_isReady_impl() const
{
    bool_t         bRv           = false;
    std::tstring_t volumeDirPath = Path( path() ).slashAppend();
    std::tstring_t dirPathOld;

    dirPathOld = Dir::current();
    xTEST_NA(dirPathOld);

    int_t iRv = ::chdir(xT2A(volumeDirPath).c_str());
    xTEST_NA(iRv);
    bRv = (iRv != - 1);

    Dir::setCurrent(dirPathOld);

    return bRv;
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*    public, static
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
/* static */
void_t
Volume::_space_impl(
    std::ctstring_t &a_dirPath,     ///< directory path
    ulonglong_t*    &a_available,   ///< available space (for unprivileged users)
    ulonglong_t*    &a_total,       ///< total space
    ulonglong_t*    &a_free         ///< free space
)
{
    struct xSTATVFS info;   Utils::structZeroT(info);

    int_t iRv = xSTATVFS(xT2A(a_dirPath).c_str(), &info);
    xTEST_DIFF(iRv, - 1);

    Utils::ptrAssignT(a_available, static_cast<ulonglong_t>( info.f_bavail * static_cast<ulonglong_t>(info.f_bsize) ));
    Utils::ptrAssignT(a_total,     static_cast<ulonglong_t>( info.f_blocks * static_cast<ulonglong_t>(info.f_bsize) ));
    Utils::ptrAssignT(a_free,      static_cast<ulonglong_t>( info.f_bfree  * static_cast<ulonglong_t>(info.f_bsize) ));
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, fs)
