/**
 * \file  CurlBuffer.cpp
 * \brief CURL client
 */


#include "CurlBuffer.h"

#include <xLib/Core/Utils.h>


xNAMESPACE_BEGIN2(xl, package)

/**************************************************************************************************
*   public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
CurlBuffer::CurlBuffer()
{
}
//-------------------------------------------------------------------------------------------------
CurlBuffer::~CurlBuffer()
{
	clear();
}
//-------------------------------------------------------------------------------------------------
bool
CurlBuffer::isEmpty() const
{
	return (_buff == nullptr || _size == 0);
}
//-------------------------------------------------------------------------------------------------
std::string
CurlBuffer::buffer() const
{
	return {_buff, _size};
}
//-------------------------------------------------------------------------------------------------
std::size_t
CurlBuffer::size() const
{
	return _size;
}
//-------------------------------------------------------------------------------------------------
size_t
CurlBuffer::get(
	char         *a_buff,
	const size_t  a_buffSize
) const
{
	if (_read_pos < _size) {
		const size_t size = (_size - _read_pos < a_buffSize) ? (_size - _read_pos) : a_buffSize;
		::memcpy(a_buff, _buff + _read_pos, size);
		_read_pos += size;

		return size;
	}

	return 0;
}
//-------------------------------------------------------------------------------------------------
void
CurlBuffer::set(
	const char   *a_buff,
	const size_t  a_buffSize
)
{
	_buff = (char *)::realloc(_buff, _size + a_buffSize + 1);
	if (_buff) {
		::memcpy(_buff + _size, a_buff, a_buffSize);
		_size       += a_buffSize;
		_buff[_size] = '\0';
	}
}
//-------------------------------------------------------------------------------------------------
void
CurlBuffer::clear()
{
	if ( isEmpty() ) {
		return;
	}

	Utils::bufferFreeT(_buff);
	_size = 0;
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, package)