/**
 * \file  Manager.h
 * \brief manage tests (Test)
 */


#pragma once

#include <xLib/Core/Core.h>
#include <xLib/Core/Const.h>
#include <xLib/Test/Test.h>
//-------------------------------------------------------------------------------------------------
xNAMESPACE_BEGIN2(xl, test)

struct ManagerData
    /// manager data
{
    bool_t      isUseTracing {false};
    std::size_t allLoops     {1};
    std::size_t unitLoops    {1};
    std::size_t caseLoops    {1};
};
xUSING_CONST(ManagerData);

class Unit;

class Manager
    /// manager
{
public:
             Manager(cint_t &argsNum, cptr_ctchar_t args[]);
        ///< constructor
    explicit Manager(cManagerData &data = cManagerData());
        ///< constructor
    virtual ~Manager();
        ///< destructor

    void_t   add(Unit *unit);
        ///< add unit
    bool_t   run();
        ///< run all units

private:
    using units_t = std::vector<Unit *>;

    ManagerData _data;              ///< data
    units_t     _units {};          ///< units
    bool_t      _isConstructed {};  ///< is object constructed

    void_t   _construct(cint_t &a_argsNum, cptr_ctchar_t a_args[]);

    xNO_COPY_ASSIGN(Manager)
};

xNAMESPACE_END2(xl, test)
//-------------------------------------------------------------------------------------------------
