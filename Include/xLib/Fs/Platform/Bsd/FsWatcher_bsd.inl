/**
 * \file  FsWatcher_bsd.inl
 * \brief File system watcher
 */


#include <xLib/System/Shell.h>


xNAMESPACE_BEGIN2(xl, fs)

/**************************************************************************************************
*    public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
void_t
FsWatcher::_watch_impl()
{
    _kQueue = ::kqueue();
    if ( !_kQueue.isValid() ) {
        std::tcout << "[FsWatcher] kqueue: fail, " << NativeError::format() << std::endl;
        return;
    }

    struct kevent change[ _filePaths.size() ];
    const int     changeSize = static_cast<int>( _filePaths.size() );

    for (size_t i = 0; i < _filePaths.size(); ++ i) {
        auto &itFilePath = _filePaths[i];

        EV_SET(&change[i], _fileHandles[i], EVFILT_VNODE,
                EV_ADD | EV_ENABLE | EV_ONESHOT,
                NOTE_DELETE | NOTE_EXTEND | NOTE_WRITE | NOTE_ATTRIB,
                0, (void_t *)itFilePath.c_str());
    }

    bool_t isLogEnable = true;

    for ( ; ; ) {
        if (isLogEnable) {
            std::tcout << "[FsWatcher] Watch changes...\n" << std::endl;
        } else {
            isLogEnable = false;
        }

        struct kevent event {};
        int_t kEvent = ::kevent(_kQueue.get(), change, changeSize, &event, 1, nullptr);
        if (kEvent == - 1 || kEvent == 0) {
            std::tcout << "[FsWatcher] kevent: fail - " << kEvent << ", " << NativeError::format() << std::endl;
            return;
        }

        if (event.flags & EV_ERROR) {
            std::tcout << "[FsWatcher] Event error: " << strerror((int)event.data);
            return;
        }

        std::ctstring_t data = event.udata ? (const char *)event.udata : "<null>";

        if (event.fflags & NOTE_DELETE) {
            std::tcout << "[FsWatcher] File deleted: " << data << std::endl;
            // File deleted - reopen files
            return;
        }

        if (event.fflags & NOTE_EXTEND ||
            event.fflags & NOTE_WRITE)
        {
            // std::tcout << "[FsWatcher] File modified: " << data << std::endl;

            for (auto &itCmd : _cmds) {
                std::ctstring_t &modulePath = itCmd.first;
                std::ctstring_t &scriptPath = itCmd.second;

                if (data.find(modulePath) == std::tstring_t::npos) {
                    continue;
                }

                std::tstring_t subProjectName;
                {
                    subProjectName = modulePath;
                    subProjectName.resize(subProjectName.size() - 1);
                    std::transform(subProjectName.begin(), subProjectName.end(),
                            subProjectName.begin(), ::toupper);
                }

                std::tcout << "\n\n::::::::::::::: " << subProjectName << " :::::::::::::::\n" << std::endl;
                std::tcout << "[FsWatcher] File modified: " << data << std::endl << std::endl;

                ::sleep(1);

            #if 0
                int_t ret = std::system( scriptPath.c_str() );
            #else
                Shell shell;
                int_t ret = shell.execute(scriptPath.c_str(), std::tstring_t());
            #endif
                if (WIFSIGNALED(ret) && (WTERMSIG(ret) == SIGINT || WTERMSIG(ret) == SIGQUIT) /* iRv != 0 */) {
                    std::tcout << "[FsWatcher] "
                        << "System error: " << strerror(errno) << ", "
                        << "Error code: " << ret << std::endl;
                    exit(0);
                    break;
                }

                break;
            } // for (_cmds)

            std::tcout << "[FsWatcher] Done!" << std::endl;
        }

        if (event.fflags & NOTE_ATTRIB) {
            // std::tcout << "[FsWatcher] File attributes modified" << std::endl;

            isLogEnable = true;
        }
    } // for ( ; ; )
}
//-------------------------------------------------------------------------------------------------
void_t
FsWatcher::_close_impl()
{
    _kQueue.close();

    for (size_t i = 0; i < _fileHandles.size(); ++ i) {
        if (_fileHandles[i] <= 0) {
            continue;
        }

        ::close(_fileHandles[i]);
        _fileHandles[i] = - 1;
    }
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, fs)