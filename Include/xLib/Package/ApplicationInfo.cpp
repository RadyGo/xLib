/**
 * \file   ApplicationInfo.cpp
 * \brief  [Comments]
 */


#include "ApplicationInfo.h"

#include <xLib/Core/Format.h>


xNAMESPACE_BEGIN2(xl, core)

/**************************************************************************************************
*   public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
std::tstring_t
ApplicationInfoData::versionFull() const
{
    return Format::str(xT("{}.{}.{} {} {}"),
        versionMajor, versionMinor, versionPatch, versionType, versionRevision);
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*   public
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
ApplicationInfo::ApplicationInfo()
{
}
//-------------------------------------------------------------------------------------------------
ApplicationInfo::ApplicationInfo(
    cApplicationInfoData &a_data
) :
    _data(a_data)
{
}
//-------------------------------------------------------------------------------------------------
ApplicationInfo::~ApplicationInfo()
{
}
//-------------------------------------------------------------------------------------------------

xNAMESPACE_END2(xl, core)