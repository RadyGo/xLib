/**
 * \file  StdStream.h
 * \brief overload operators << for std::basic_ostream
 */


#pragma once

#include <xLib/Core/Defines.h>
//-------------------------------------------------------------------------------------------------
xNAMESPACE_BEGIN2(xlib, core)
//-------------------------------------------------------------------------------------------------
///@name Sequence containers
///@{

template<class T1, class T2>
inline std::tostream_t &
operator << (std::tostream_t &os, const std::pair<T1, T2> &value);
    ///< for std::pair

// TODO: for std::array (C++11)

template<class T>
inline std::tostream_t &
operator << (std::tostream_t &os, const std::vector<T> &value);
    ///< for std::vector

// TODO: for std::deque
// TODO: for std::forward_list (C++11)

template<class T>
inline std::tostream_t &
operator << (std::tostream_t &os, const std::list<T> &value);
    ///< for std::list
///@}
//-------------------------------------------------------------------------------------------------
///@name Container adaptors
///@{

// TODO: for std::stack
// TODO: for std::queue
// TODO: for std::priority_queue

///@}
//-------------------------------------------------------------------------------------------------
///@name Associative containers
///@{

template<class T>
inline std::tostream_t &
operator << (std::tostream_t &os, const std::set<T> &value);
    ///< for std::set

template<class T>
inline std::tostream_t &
operator << (std::tostream_t &os, const std::multiset<T> &value);
    ///< for std::multiset

template<class T1, class T2>
inline std::tostream_t &
operator << (std::tostream_t &os, const std::map<T1, T2> &value);
    ///< for std::map

template<class T1, class T2>
inline std::tostream_t &
operator << (std::tostream_t &os, const std::multimap<T1, T2> &value);
    ///< for std::multimap
///@}
//-------------------------------------------------------------------------------------------------
///@name Unordered associative containers
///@{

// TODO: for std::unordered_set (C++11)
// TODO: for std::unordered_multiset (C++11)
// TODO: for std::unordered_map (C++11)
// TODO: for std::unordered_multimap (C++11)

///@}
//-------------------------------------------------------------------------------------------------
///@name Etc
///@{
inline std::tostream_t &
operator << (std::tostream_t &os, std::custring_t &value);
    ///< for std::ustring_t
///@}
//-------------------------------------------------------------------------------------------------
xNAMESPACE_END2(xlib, core)
//-------------------------------------------------------------------------------------------------
#include "StdStream.inl"