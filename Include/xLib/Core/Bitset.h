/**
 * \file  Bitset.h
 * \brief bit mask flags
 *
 * like std::bitset
 * https://codereview.stackexchange.com/questions/86623/c-bitset-implementation
 */


#pragma once

#include <xLib/Core/Core.h>
//-------------------------------------------------------------------------------------------------
xNAMESPACE_BEGIN2(xl, core)

template<typename T>
class Bitset
    /// bit mask flags
{
public:
             Bitset() = default;
        ///< constructor
    explicit Bitset(const Bitset &values);
        ///< constructor
    explicit Bitset(const T &values);
        ///< constructor
    virtual ~Bitset() = default;
        ///< destructor

    Bitset &  operator = (const Bitset &values);
        ///< operator =
	T &      operator [] (const std::size_t index);
		///<

    T &      get() const;
        ///< get all flags
    void_t   set(const T &values);
        ///< set all flags
    void_t   clear();
        ///< reset all flags

    bool_t   test(const std::size_t index) const;
        ///< check bit at position is set
    bool_t   isSetFlag(const T &value) const;
        ///< flag is set
    bool_t   isSetAnyFlag(const T &value) const;
        ///< is any flag set
    void_t   setFlag(const T &value);
        ///< set flag
    void_t   unsetFlag(const T &value);
        ///< unset flag
    void_t   flipFlag(const T &value);
        ///< flip flag

	constexpr
	std::size_t size() const;
		///< get number of bits

    template<typename StreamT>
    void_t   print(StreamT &os) const;
        ///< print object to stream

private:
    T        _flags {};
};

xNAMESPACE_END2(xl, core)

//-------------------------------------------------------------------------------------------------
#include "Bitset.inl"