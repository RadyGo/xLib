/**
 * \file  StdStream.inl
 * \brief overload operators << for std::std::basic_ostream
 */


#include <xLib/Test/Test.h>
#include <xLib/Debug/Debug.h>
#include <xLib/Debug/NativeError.h>
#include <xLib/Debug/StdError.h>
#include <xLib/Debug/ErrorReport.h>
#include <xLib/Debug/Debugger.h>
#include <xLib/Debug/StackTrace.h>


xNAMESPACE_BEGIN2(xlib, core)

/**************************************************************************************************
*   Sequence containers
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<class T1, class T2>
inline std::tostream_t &
operator << (
    std::tostream_t         &a_os,
    const std::pair<T1, T2> &a_value
)
{
    a_os << xT("std::pair: {") << a_value.first << xT(", ") << a_value.second << "}";

    return a_os;
}
//-------------------------------------------------------------------------------------------------
template<class T>
inline std::tostream_t &
operator << (
    std::tostream_t      &a_os,
    const std::vector<T> &a_value
)
{
    a_os << xT("std::vector (") << a_value.size() << xT(" elements)");

    if ( a_value.empty() )  {
        return a_os;
    }

    a_os << xT(":") << std::endl;

    typename std::vector<T>::const_iterator it;
    for (it = a_value.begin(); it != a_value.end(); ++ it) {
        a_os << xT("    value[") << std::distance(a_value.begin(), it) << xT("]: ") << *it;

        if (it + 1 != a_value.end()) {
             a_os << std::endl;
        }
    }

    return a_os;
}
//-------------------------------------------------------------------------------------------------
template<class T>
inline std::tostream_t &
operator << (
    std::tostream_t    &a_os,
    const std::list<T> &a_value
)
{
    a_os << xT("std::list (") << a_value.size() << xT(" elements)");

    if ( a_value.empty() ) {
        return a_os;
    }

    a_os << xT(":") << std::endl;

    typename std::list<T>::const_iterator it;
    for (it = a_value.begin(); it != a_value.end(); ++ it) {
        a_os << xT("    value[") << std::distance(a_value.begin(), it) << xT("]: ") << *it;

        if (++ it != a_value.end()) {
             a_os << std::endl;
        }

        -- it;
    }

    return a_os;
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*   Container adaptors
*
**************************************************************************************************/


/**************************************************************************************************
*   Associative containers
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<class T>
inline std::tostream_t &
operator << (
    std::tostream_t   &a_os,
    const std::set<T> &a_value
)
{
    a_os << xT("std::set (") << a_value.size() << xT(" elements)");

    if ( a_value.empty() )  {
        return a_os;
    }

    a_os << xT(":") << std::endl;

    typename std::set<T>::const_iterator it;
    for (it = a_value.begin(); it != a_value.end(); ++ it) {
        a_os << xT("    value[") << std::distance(a_value.begin(), it) << xT("]: ") << *it;
        a_os << std::endl;
    }

    a_os.seekp(- 1, a_os.cur); a_os << " ";

    return a_os;
}
//-------------------------------------------------------------------------------------------------
template<class T>
inline std::tostream_t &
operator << (
    std::tostream_t        &a_os,
    const std::multiset<T> &a_value
)
{
    a_os << xT("std::multiset (") << a_value.size() << xT(" elements)");

    if ( a_value.empty() )  {
        return a_os;
    }

    a_os << xT(":") << std::endl;

    typename std::multiset<T>::const_iterator it;
    for (it = a_value.begin(); it != a_value.end(); ++ it) {
        a_os << xT("    value[") << std::distance(a_value.begin(), it) << xT("]: ") << *it;
        a_os << std::endl;
    }

    a_os.seekp(- 1, a_os.cur); a_os << " ";

    return a_os;
}
//-------------------------------------------------------------------------------------------------
template<class T1, class T2>
inline std::tostream_t &
operator << (
    std::tostream_t        &a_os,
    const std::map<T1, T2> &a_value
)
{
    a_os << xT("std::map (") << a_value.size() << xT(" elements)");

    if ( a_value.empty() ) {
        return a_os;
    }

    a_os << xT(":") << std::endl;

    typename std::map<T1, T2>::const_iterator it;
    for (it = a_value.begin(); it != a_value.end(); ++ it) {
        a_os << *it;

        if (++ it != a_value.end()) {
             a_os << std::endl;
        }

        -- it;
    }

    return a_os;
}
//-------------------------------------------------------------------------------------------------
template<class T1, class T2>
inline std::tostream_t &
operator << (
    std::tostream_t             &a_os,
    const std::multimap<T1, T2> &a_value
)
{
    a_os << std::endl;
    a_os << xT("std::multimap (") << a_value.size() << xT(" elements):") << std::endl;
    a_os << std::endl;

    typename std::multimap<T1, T2>::const_iterator it;
    for (it = a_value.begin(); it != a_value.end(); ++ it) {
        a_os << *it;

        if (++ it != a_value.end()) {
             a_os << std::endl;
        }

        -- it;
    }

    return a_os;
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*   Unordered associative containers
*
**************************************************************************************************/


/**************************************************************************************************
*   Etc
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
inline std::tostream_t &
operator << (
    std::tostream_t &a_os,
    std::custring_t &a_value
)
{
    std::tstring_t sRv(a_value.begin(), a_value.end());

    a_os << sRv;

    return a_os;
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xlib, core)