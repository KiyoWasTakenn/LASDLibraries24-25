#include <iostream>
#include <functional>

/* ************************************************************************** */

#include "test.hpp"

#include "vector/vector.hpp"
#include "list/list.hpp"

#include "set/vec/setvec.hpp"
#include "set/lst/setlst.hpp"

#include "heap/heapvec.hpp"
#include "pq/pqheap.hpp"

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

void MyTestExercise2A()
{
    check(hpvec_test);
}

// void MyTestExercise2B()
// {
//     check(pqhp_test);
// }

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


    cout << endl << "---------------------- STARTING MyTestExercise2A ----------------------" << endl;
    MyTestExercise2A();
    cout << endl << "MyTestExercise2: Errors/Tests: " << testerr << "/" << testnum << endl;
    uint testnum3 = testnum;
    uint testerr3 = testerr;
    cout << endl << "---------------------- END OF MyTestExercise2A ---------------------- " << endl;


    // testnum = testerr = 0;


    // cout << endl << "---------------------- STARTING MyTestExercise2B ----------------------" << endl;
    // MyTestExercise2B();
    // cout << endl << "MyTestExercise2: Errors/Tests: " << testerr << "/" << testnum << endl;
    // uint testnum4 = testnum;
    // uint testerr4 = testerr;
    // cout << endl << "---------------------- END OF MyTestExercise2B ---------------------- " << endl;


    testnum = testerr = 0;

    cout << endl << "---------------------- SUMMARY OF ALL TESTS ----------------------" << endl;

    cout << endl << "MyTestExercise1A: Errors/Tests: " << testerr1 << "/" << testnum1 << endl;
    cout << endl << "MyTestExercise1B: Errors/Tests: " << testerr2 << "/" << testnum2 << endl;
    cout << endl << "Total Errors Exercise1: Errors/Tests: " << testerr1 + testerr2 << "/" << testnum1 + testnum2 << endl;

    cout << endl << "MyTestExercise2A: Errors/Tests: " << testerr3 << "/" << testnum3 << endl;
    // cout << endl << "MyTestExercise2B: Errors/Tests: " << testerr4 << "/" << testnum4 << endl;
    // cout << endl << "Total Errors Exercise2: Errors/Tests: " << testerr3 + testerr4 << "/" << testnum3 + testnum4 << endl;

    cout << endl << "---------------------- END OF MyTests ----------------------" << endl;
}