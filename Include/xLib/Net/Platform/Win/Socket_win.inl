/**
 * \file  ISocket.inl
 * \brief blocking socket
 */


xNAMESPACE_BEGIN2(xl, net)

/**************************************************************************************************
*    public
*
**************************************************************************************************/

/**************************************************************************************************
* I/O
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
ssize_t
ISocket::_send_impl(
    cptr_ctchar_t *a_buff,
    std::csize_t  &a_buffSize,
    cint_t        &a_flags
)
{
    ssize_t iRv = ::send(_handle.get(), (LPCSTR)a_buff, a_buffSize * sizeof(tchar_t), a_flags);
    xTEST_EQ(iRv != xSOCKET_ERROR && ISocket::nativeError() != WSAEWOULDBLOCK, true);
    xTEST_GR_EQ(ssize_t(a_buffSize * sizeof(tchar_t)), iRv);

    return iRv / sizeof(tchar_t);
}
//-------------------------------------------------------------------------------------------------
ssize_t
ISocket::_receive_impl(
    tchar_t      *a_buff,
    std::csize_t &a_buffSize,
    cint_t       &a_flags
)
{
    int_t iRv = ::recv(_handle.get(), (LPSTR)a_buff, a_buffSize * sizeof(tchar_t), a_flags);
    xTEST_EQ(iRv != xSOCKET_ERROR && ISocket::nativeError() != WSAEWOULDBLOCK, true);
    xTEST_DIFF(iRv, 0);  // gracefully closed
    xTEST_GR_EQ(int_t(a_buffSize * sizeof(tchar_t)), iRv);

    return iRv / sizeof(tchar_t);
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
* ...
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
void_t
ISocket::_peerName_impl(
    std::tstring_t *a_peerAddr,
    ushort_t       *a_peerPort
)
{
    SOCKADDR_IN sockAddr    = {0};
    int_t       sockAddrLen = sizeof(sockAddr);

    int_t iRv = ::getpeername(_handle.get(), Utils::reinterpretCastT<SOCKADDR *>( &sockAddr ),
        &sockAddrLen);
    xTEST_DIFF(iRv, xSOCKET_ERROR);

    // out
    if (a_peerAddr != nullptr) {
        std::string peerAddr = ::inet_ntoa(sockAddr.sin_addr);

        *a_peerAddr = xA2T(peerAddr);
    }

    if (a_peerPort != nullptr) {
        *a_peerPort = ntohs(sockAddr.sin_port);
    }
}
//-------------------------------------------------------------------------------------------------
void_t
ISocket::_socketName_impl(
    std::tstring_t *a_socketAddr,
    ushort_t       *a_socketPort
)
{
    SOCKADDR_IN sockAddr     = {0};
    int_t       sockAddrLen = sizeof(sockAddr);

    int_t iRv = ::getsockname(_handle.get(), Utils::reinterpretCastT<SOCKADDR *>( &sockAddr ),
        &sockAddrLen);
    xTEST_DIFF(iRv, xSOCKET_ERROR);

    // out
    if (a_socketAddr != nullptr) {
        std::string socketAddr = ::inet_ntoa(sockAddr.sin_addr);

        *a_socketAddr = xA2T(socketAddr);
    }

    if (a_socketPort != nullptr) {
        *a_socketPort = ntohs(sockAddr.sin_port);
    }
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
* static
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
int_t
ISocket::_nativeError_impl()
{
    return ::WSAGetLastError();
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, net)
