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

void mysetvec_int(uint &testnum, uint &testerr)
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

void mysetvec_double(uint &testnum, uint &testerr)
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

void mysetvec_string(uint &testnum, uint &testerr)
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

void setvec_test(uint &testnum, uint &testerr)
{
    mysetvec_int(testnum, testerr);
    mysetvec_double(testnum, testerr);
    mysetvec_string(testnum, testerr);
}