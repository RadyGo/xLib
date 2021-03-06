/**
 * \file   ProcessInfo.inl
 * \brief  process information
 */


xNAMESPACE_BEGIN2(xl, system)

/**************************************************************************************************
*   public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
std::tstring_t
ProcessInfo::_exeName_impl() const
{
    std::string asRv;

    std::ctstring_t procFile = Format::str(xT("/proc/{}/exe"), _id);

    bool_t bRv = File::isExists(procFile);
    xCHECK_RET(!bRv, std::tstring_t());

    ssize_t readed = - 1;
    asRv.resize(xPATH_MAX);

    for ( ; ; ) {
        readed = ::readlink(xT2A(procFile).c_str(), &asRv.at(0), asRv.size() *
            sizeof(std::string::value_type));
        xTEST_DIFF(readed, ssize_t(- 1));

        xCHECK_DO(asRv.size() * sizeof(std::string::value_type) > static_cast<size_t>( readed ), break);

        asRv.resize(asRv.size() * 2);
    }

    asRv.resize( static_cast<std::size_t>(readed) );

    return xA2T(asRv);
}
//-------------------------------------------------------------------------------------------------
/* static */
void_t
ProcessInfo::_commandLine_impl(
    std::vec_tstring_t *a_args
) const
{
    std::vec_tstring_t args;

    // TODO: [skynowa] ProcessInfo::commandLine() - review
    std::ctstring_t procPath = Format::str(xT("/proc/{}/cmdline"), _id);

#if 0
	file_unique_ptr_t procFile {std::fopen(xT2A(procPath).c_str(), "r"), std::fclose};
	xTEST_PTR(procFile.get());
#else
	auto procFile = autoFile(procPath, "r");
	xTEST_PTR(procFile.get());
#endif

    std::csize_t bufferSize       = 2048;
    char         buff[bufferSize] = {0};

    while ( std::fgets(buff, static_cast<int_t>(bufferSize), procFile.get()) ) {
        for (size_t pos = 0; pos < bufferSize && buff[pos] != '\0'; ) {
            args.push_back( xA2T(buff + pos) );

            pos += std::strlen(buff + pos) + 1;
        }
    }

    // out
    a_args->swap(args);
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, system)
