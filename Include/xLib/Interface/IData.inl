/**
 * \file  IData.inl
 * \brief Data struct
 */


xNAMESPACE_BEGIN2(xl, interface)

/**************************************************************************************************
*    public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
inline core::OStream &
operator << (
	core::OStream    &a_os,
	const IDataPrint &a_data
)
{
	a_data.print(a_os);

	return a_os;
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, interface)
