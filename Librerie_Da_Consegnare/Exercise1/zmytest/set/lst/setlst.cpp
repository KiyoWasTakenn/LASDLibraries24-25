#include <iostream>

/* ************************************************************************** */

#include "../../../zlasdtest/container/container.hpp"
#include "../../../zlasdtest/container/testable.hpp"
#include "../../../zlasdtest/container/traversable.hpp"
#include "../../../zlasdtest/container/dictionary.hpp"
#include "../../../zlasdtest/container/mappable.hpp"
#include "../../../zlasdtest/container/linear.hpp"

/* ************************************************************************** */

#include "../../../zlasdtest/vector/vector.hpp"
#include "../../../zlasdtest/list/list.hpp"
#include "../../../zlasdtest/set/set.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void mysetlst_int(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {

    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }
}

void mysetlst_double(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {

    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }
}

void mysetlst_string(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {

    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }
}


/* ************************************************************************** */

void setlst_test(uint &testnum, uint &testerr)
{
    mysetlst_int(testnum, testerr);
    mysetlst_double(testnum, testerr);
    mysetlst_string(testnum, testerr);
}