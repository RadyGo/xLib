/**
 * \file  FeatureFlag.cpp
 * \brief Feature flag / toggle
 */


#include "FeatureFlag.h"


xNAMESPACE_BEGIN2(xl, package)

/**************************************************************************************************
*   public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
void
FeatureFlag::setIntervalTs(
	const DateTime &a_start,
	const DateTime &a_stop
)
{
	_start = a_start;
	_stop  = a_stop;
}
//-------------------------------------------------------------------------------------------------
void
FeatureFlag::setStop(
	const DateTime &a_stop
)
{
	_start = DateTime().current();
	_stop  = a_stop;
}
//-------------------------------------------------------------------------------------------------
void
FeatureFlag::setPermissions()
{
	// IMPL: setPermissions
}
//-------------------------------------------------------------------------------------------------
void
FeatureFlag::alert() const
{
	// IMPL: alert
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, package)