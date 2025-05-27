#include <iostream>
#include <functional>

/* ************************************************************************** */

#include "test.hpp"

#include "vector/vector.hpp"
#include "list/list.hpp"

#include "set/vec/setvec.hpp"
#include "set/lst/setlst.hpp"

/* ************************************************************************** */

using namespace std;
using TFun = function<void(uint &, uint &)>;

/* ************************************************************************** */

uint testnum = 0;
uint testerr = 0;

void check(TFun test)
{
  uint loctestnum = 0, loctesterr = 0;
  test(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void MyTestExercise1A()
{
    check(vec_test);
    check(lst_test);
}

void MyTestExercise1B()
{
    check(setvec_test);
    check(setlst_test);
}

void mytest()
{
    cout << endl << "---------------------- STARTING MyTests ...----------------------" << endl;

    cout << endl << "---------------------- STARTING MyTestExercise1A ----------------------" << endl;
    MyTestExercise1A();
    cout << endl << "MyTestExercise1: Errors/Tests: " << testerr << "/" << testnum << endl;
    uint testnum1 = testnum;
    uint testerr1 = testerr;
    cout << endl << "---------------------- END OF MyTestExercise1A ---------------------- " << endl;


    testnum = testerr = 0;


    cout << endl << "---------------------- STARTING MyTestExercise1B ----------------------" << endl;
    MyTestExercise1B();
    cout << endl << "MyTestExercise2: Errors/Tests: " << testerr << "/" << testnum << endl;
    uint testnum2 = testnum;
    uint testerr2 = testerr;
    cout << endl << "---------------------- END OF MyTestExercise1B ---------------------- " << endl;


    testnum = testerr = 0;


    cout << endl << "---------------------- SUMMARY OF ALL TESTS ----------------------" << endl;

    cout << endl << "MyTestExercise1A: Errors/Tests: " << testerr1 << "/" << testnum1 << endl;
    cout << endl << "MyTestExercise1B: Errors/Tests: " << testerr2 << "/" << testnum2 << endl;
    cout << endl << "Total Errors: Errors/Tests: " << testerr1 + testerr2 << "/" << testnum1 + testnum2 << endl;

    cout << endl << "---------------------- END OF MyTests ----------------------" << endl;
}