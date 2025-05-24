#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/linear.hpp"

/* ************************************************************************** */

#include "../../zlasdtest/vector/vector.hpp"
#include "../../zlasdtest/list/list.hpp"
#include "../../zlasdtest/set/set.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void myvec_int(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        cout << endl<< "############################################################################"<< endl;
        cout << endl << "---------------------- Begin of MyVec<int> tests: ----------------------" << endl;

        //EmptyVectorDefaultConstructor
        {
            lasd::SortableVector<int> vec;

            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            GetFront(loctestnum, loctesterr, vec, false, 0);
            GetBack(loctestnum, loctesterr, vec, false, 0);
            GetAt(loctestnum, loctesterr, vec, false, 0, 0);
            SetAt(loctestnum, loctesterr, vec, false, 0, 0);

            Exists(loctestnum, loctesterr, vec, false, 0);

            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

            Fold(loctestnum, loctesterr, vec, true, &FoldMultiply<int>, 0, 0);
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldMultiply<int>, 0, 0);
            FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldMultiply<int>, 0, 0);

            Map(loctestnum, loctesterr, vec, true, &MapIncrement<int>);
            MapPreOrder(loctestnum, loctesterr, vec, true, &MapIncrement<int>);
            MapPostOrder(loctestnum, loctesterr, vec, true, &MapIncrement<int>);

            vec.Sort();
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            vec.Clear();
            Empty(loctestnum, loctesterr, vec, true);
        }
        //EmptyVectorSizeConstructor
        {
            lasd::SortableVector<int> vec(0);

            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            GetFront(loctestnum, loctesterr, vec, false, 0);
            GetBack(loctestnum, loctesterr, vec, false, 0);
            GetAt(loctestnum, loctesterr, vec, false, 0, 0);
            SetAt(loctestnum, loctesterr, vec, false, 0, 0);

            Exists(loctestnum, loctesterr, vec, false, 0);

            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

            Fold(loctestnum, loctesterr, vec, true, &FoldMultiply<int>, 0, 0);
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldMultiply<int>, 0, 0);
            FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldMultiply<int>, 0, 0);

            Map(loctestnum, loctesterr, vec, true, &MapIncrement<int>);
            MapPreOrder(loctestnum, loctesterr, vec, true, &MapIncrement<int>);
            MapPostOrder(loctestnum, loctesterr, vec, true, &MapIncrement<int>);

            vec.Sort();
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            vec.Clear();
            Empty(loctestnum, loctesterr, vec, true);
        }
        //NonEmptyVectorSizeConstructor
        {
            lasd::SortableVector<int> vec(10);

            Empty(loctestnum, loctesterr, vec, false);
            Size(loctestnum, loctesterr, vec, true, 10);

            SetAt(loctestnum, loctesterr, vec, true, 0, 2);
            SetAt(loctestnum, loctesterr, vec, true, 1, 4);
            SetAt(loctestnum, loctesterr, vec, true, 2, 6);
            SetAt(loctestnum, loctesterr, vec, true, 3, 8);
            SetAt(loctestnum, loctesterr, vec, true, 4, 10);
            SetAt(loctestnum, loctesterr, vec, true, 5, 11);
            SetAt(loctestnum, loctesterr, vec, true, 6, 13);
            SetAt(loctestnum, loctesterr, vec, true, 7, 15);
            SetAt(loctestnum, loctesterr, vec, true, 8, 17);
            SetAt(loctestnum, loctesterr, vec, true, 9, 19);
            SetAt(loctestnum, loctesterr, vec, false, 10, 20);

            GetAt(loctestnum, loctesterr, vec, true, 9, 19);
            GetAt(loctestnum, loctesterr, vec, false, 10, 20);
            GetFront(loctestnum, loctesterr, vec, true, 2);
            GetBack(loctestnum, loctesterr, vec, true, 19);

            SetFront(loctestnum, loctesterr, vec, true, 0);
            SetBack(loctestnum, loctesterr, vec, true, 21);
            GetFront(loctestnum, loctesterr, vec, true, 0);
            GetBack(loctestnum, loctesterr, vec, true, 21);

            Exists(loctestnum, loctesterr, vec, true, 21);
            Exists(loctestnum, loctesterr, vec, false, 7);

            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

            Fold(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 105);
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 105);
            FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldMultiply<int>, 1, 0);

            vec.Resize(4);
            Fold(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 18);
            Map(loctestnum, loctesterr, vec, true, &MapIncrement<int>);
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 22);
            FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldMultiply<int>, 1, 315);

        
            vec.Resize(2);
            SetAt(loctestnum, loctesterr, vec, true, 0, 15);
            MapPreOrder(loctestnum, loctesterr, vec, true, &MapIncrement<int>);
            GetAt(loctestnum, loctesterr, vec, true, 0, 16);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            MapPostOrder(loctestnum, loctesterr, vec, true, &MapDouble<int>);
            GetAt(loctestnum, loctesterr, vec, true, 0, 32);
            Fold(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 44);

            vec.Resize(0);
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);
        }
        // Some Resize and clears
        {
            lasd::SortableVector<int> vec(3);
            SetAt(loctestnum, loctesterr, vec, true, 0, 1);
            SetAt(loctestnum, loctesterr, vec, true, 1, 2);
            SetAt(loctestnum, loctesterr, vec, true, 2, 3);
            
            vec.Resize(5); 
            Size(loctestnum, loctesterr, vec, true, 5);
            GetAt(loctestnum, loctesterr, vec, true, 0, 1);
            GetAt(loctestnum, loctesterr, vec, true, 2, 3);
            GetAt(loctestnum, loctesterr, vec, true, 3, 0);
            GetAt(loctestnum, loctesterr, vec, true, 4, 0);
            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            vec.Sort();
            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            GetAt(loctestnum, loctesterr, vec, true, 0, 0);
            GetAt(loctestnum, loctesterr, vec, true, 4, 3);

            vec.Resize(2); 
            Size(loctestnum, loctesterr, vec, true, 2);
            GetAt(loctestnum, loctesterr, vec, true, 0, 0);
            GetAt(loctestnum, loctesterr, vec, true, 1, 0);
            GetAt(loctestnum, loctesterr, vec, false, 2, 0); 

            vec.Resize(0); 
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            lasd::SortableVector<int> vec_to_clear(3);
            SetAt(loctestnum, loctesterr, vec_to_clear, true, 0, 10);
            vec_to_clear.Clear();
            Empty(loctestnum, loctesterr, vec_to_clear, true);
            Size(loctestnum, loctesterr, vec_to_clear, true, 0);
        }
        // SortTest
        {
            lasd::SortableVector<int> svec_unsorted(5);
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 0, 50);
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 1, 20);
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 2, 40);
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 3, 10);
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 4, 30);
            Traverse(loctestnum, loctesterr, svec_unsorted, true, &TraversePrint<int>);
            svec_unsorted.Sort();
            Traverse(loctestnum, loctesterr, svec_unsorted, true, &TraversePrint<int>);

            GetAt(loctestnum, loctesterr, svec_unsorted, true, 0, 10);
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 1, 20);
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 2, 30);
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 3, 40);
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 4, 50);

            svec_unsorted.Sort();
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 0, 10);
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 4, 50);

            lasd::SortableVector<int> svec_rev(3);
            SetAt(loctestnum, loctesterr, svec_rev, true, 0, 30);
            SetAt(loctestnum, loctesterr, svec_rev, true, 1, 20);
            SetAt(loctestnum, loctesterr, svec_rev, true, 2, 10);
            svec_rev.Sort();
            GetAt(loctestnum, loctesterr, svec_rev, true, 0, 10);
            GetAt(loctestnum, loctesterr, svec_rev, true, 2, 30);

            lasd::SortableVector<int> svec_dup(5);
            SetAt(loctestnum, loctesterr, svec_dup, true, 0, 5);
            SetAt(loctestnum, loctesterr, svec_dup, true, 1, 2);
            SetAt(loctestnum, loctesterr, svec_dup, true, 2, 5);
            SetAt(loctestnum, loctesterr, svec_dup, true, 3, 1);
            SetAt(loctestnum, loctesterr, svec_dup, true, 4, 2);
            svec_dup.Sort();
            GetAt(loctestnum, loctesterr, svec_dup, true, 0, 1); 
            GetAt(loctestnum, loctesterr, svec_dup, true, 1, 2);
            GetAt(loctestnum, loctesterr, svec_dup, true, 2, 2); 
            GetAt(loctestnum, loctesterr, svec_dup, true, 3, 5);
            GetAt(loctestnum, loctesterr, svec_dup, true, 4, 5);
        }
        // Copy Constructor
        {
            lasd::SortableVector<int> vec(3);
            SetAt(loctestnum, loctesterr, vec, true, 0, 7);
            SetAt(loctestnum, loctesterr, vec, true, 1, 8);
            SetAt(loctestnum, loctesterr, vec, true, 2, 9);
            vec.Sort();

            lasd::SortableVector<int> copyvec(vec);
            EqualVector(loctestnum, loctesterr, vec, copyvec, true);
            EqualLinear(loctestnum, loctesterr, vec, copyvec, true);
            TraversePreOrder(loctestnum, loctesterr, copyvec, true, &TraversePrint<int>);
            Size(loctestnum, loctesterr, copyvec, true, 3);
            GetAt(loctestnum, loctesterr, copyvec, true, 0, 7);

            MapPreOrder(loctestnum, loctesterr, copyvec, true, &MapIncrement<int>);
            NonEqualVector(loctestnum, loctesterr, vec, copyvec, true);
            NonEqualLinear(loctestnum, loctesterr, vec, copyvec, true);

            lasd::SortableVector<int> empty_vec;
            lasd::SortableVector<int> copy_of_empty(empty_vec);
            Empty(loctestnum, loctesterr, copy_of_empty, true);
        }
        // Move constructor
        {
            lasd::SortableVector<int> vec(3);
            SetAt(loctestnum, loctesterr, vec, true, 0, 56);
            SetAt(loctestnum, loctesterr, vec, true, 1, 23);
            SetAt(loctestnum, loctesterr, vec, true, 2, 10);
            vec.Sort(); 

            lasd::SortableVector<int> vec_moved(std::move(vec));
            Size(loctestnum, loctesterr, vec_moved, true, 3);
            GetAt(loctestnum, loctesterr, vec_moved, true, 0, 10);
            FoldPreOrder(loctestnum, loctesterr, vec_moved, true, &FoldAdd<int>, 0, 89);

            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);
        }
        // Copy Assignment
        {
            lasd::SortableVector<int> vec_orig(2);
            SetAt(loctestnum, loctesterr, vec_orig, true, 0, -4100);
            SetAt(loctestnum, loctesterr, vec_orig, true, 1, 20);
            SetAt(loctestnum, loctesterr, vec_orig, true, 1, 33);
            SetAt(loctestnum, loctesterr, vec_orig, true, 1, 243);
            SetAt(loctestnum, loctesterr, vec_orig, true, 1, 2033);
            vec_orig.Sort(); 

            lasd::SortableVector<int> vec_assign;
            vec_assign = vec_orig;
            EqualVector(loctestnum, loctesterr, vec_orig, vec_assign, true);
            EqualLinear(loctestnum, loctesterr, vec_orig, vec_assign, true);
            GetAt(loctestnum, loctesterr, vec_assign, true, 0, -4100);
            vec_assign = vec_assign;
            EqualVector(loctestnum, loctesterr, vec_orig, vec_assign, true);
            Map(loctestnum, loctesterr, vec_orig, true, &MapIncrement<int>);
            NonEqualVector(loctestnum, loctesterr, vec_orig, vec_assign, true);
            NonEqualLinear(loctestnum, loctesterr, vec_orig, vec_assign, true);

            lasd::SortableVector<int> empty_svec;
            vec_assign = empty_svec; 
            Empty(loctestnum, loctesterr, vec_assign, true);
            Size(loctestnum, loctesterr, vec_assign, true, 0);
        }
        // Move Assignment
        {
            lasd::SortableVector<int> vec_orig(2);
            SetAt(loctestnum, loctesterr, vec_orig, true, 0, 300);
            SetAt(loctestnum, loctesterr, vec_orig, true, 1, 120);
            vec_orig.Sort();

            lasd::SortableVector<int> vec_assign;
            vec_assign = std::move(vec_orig);
            Size(loctestnum, loctesterr, vec_assign, true, 2);
            GetAt(loctestnum, loctesterr, vec_assign, true, 0, 120);
            Empty(loctestnum, loctesterr, vec_orig, true);

            vec_assign = std::move(vec_assign); 
            Size(loctestnum, loctesterr, vec_assign, true, 2); 
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MyVec<int> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

void myvec_double(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        cout << endl<< "############################################################################"<< endl;
        cout << endl << "---------------------- Begin of MyVec<double> tests: ----------------------" << endl;

        //EmptyVectorDefaultConstructor
        {
            lasd::SortableVector<double> vec;

            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            GetFront(loctestnum, loctesterr, vec, false, 0.0);
            GetBack(loctestnum, loctesterr, vec, false, 0.0);
            GetAt(loctestnum, loctesterr, vec, false, 0, 0.0);
            SetAt(loctestnum, loctesterr, vec, false, 0, 0.0);

            Exists(loctestnum, loctesterr, vec, false, 0.0);

            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

            Fold(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 0.0);
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldMultiply<double>, 1.0, 1.0); 
            FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 5.5, 5.5);


            Map(loctestnum, loctesterr, vec, true, &MapIncrement<double>);
            MapPreOrder(loctestnum, loctesterr, vec, true, &MapIncrement<double>);
            MapPostOrder(loctestnum, loctesterr, vec, true, &MapIncrement<double>);

            vec.Sort();
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            vec.Clear();
            Empty(loctestnum, loctesterr, vec, true);
        }
        //EmptyVectorSizeConstructor
        {
            lasd::SortableVector<double> vec(0);

            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            GetFront(loctestnum, loctesterr, vec, false, 0.0);
            GetBack(loctestnum, loctesterr, vec, false, 0.0);
            GetAt(loctestnum, loctesterr, vec, false, 0, 0.0);
            SetAt(loctestnum, loctesterr, vec, false, 0, 0.0);

            Exists(loctestnum, loctesterr, vec, false, 0.0);

            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

            Fold(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 0.0);
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldMultiply<double>, 1.0, 1.0);
            FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 0.0);

            Map(loctestnum, loctesterr, vec, true, &MapIncrement<double>);
            MapPreOrder(loctestnum, loctesterr, vec, true, &MapIncrement<double>);
            MapPostOrder(loctestnum, loctesterr, vec, true, &MapIncrement<double>);

            vec.Sort();
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            vec.Clear();
            Empty(loctestnum, loctesterr, vec, true);
        }
        //NonEmptyVectorSizeConstructor
        {
            lasd::SortableVector<double> vec(10);

            Empty(loctestnum, loctesterr, vec, false);
            Size(loctestnum, loctesterr, vec, true, 10);

            SetAt(loctestnum, loctesterr, vec, true, 0, 2.5);
            SetAt(loctestnum, loctesterr, vec, true, 1, -4.2);
            SetAt(loctestnum, loctesterr, vec, true, 2, 6.0);
            SetAt(loctestnum, loctesterr, vec, true, 3, 0.8);
            SetAt(loctestnum, loctesterr, vec, true, 4, 10.1);
            SetAt(loctestnum, loctesterr, vec, true, 5, -11.5);
            SetAt(loctestnum, loctesterr, vec, true, 6, 13.0);
            SetAt(loctestnum, loctesterr, vec, true, 7, -0.05);
            SetAt(loctestnum, loctesterr, vec, true, 8, 17.7);
            SetAt(loctestnum, loctesterr, vec, true, 9, 1.9);
            SetAt(loctestnum, loctesterr, vec, false, 10, 20.0); 

            GetAt(loctestnum, loctesterr, vec, true, 9, 1.9);
            GetAt(loctestnum, loctesterr, vec, false, 10, 20.0); 
            GetFront(loctestnum, loctesterr, vec, true, 2.5);
            GetBack(loctestnum, loctesterr, vec, true, 1.9);

            SetFront(loctestnum, loctesterr, vec, true, 0.5);
            SetBack(loctestnum, loctesterr, vec, true, 21.21);
            GetFront(loctestnum, loctesterr, vec, true, 0.5);
            GetBack(loctestnum, loctesterr, vec, true, 21.21);

            Exists(loctestnum, loctesterr, vec, true, 21.21);
            Exists(loctestnum, loctesterr, vec, false, 7.77);

            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

            SetAt(loctestnum, loctesterr, vec, true, 0, 2.0); 
            SetAt(loctestnum, loctesterr, vec, true, 1, 1.0); 
            SetAt(loctestnum, loctesterr, vec, true, 2, 0.5);

            lasd::SortableVector<double> vecProd(3);
            SetAt(loctestnum, loctesterr, vecProd, true, 0, 2.0);
            SetAt(loctestnum, loctesterr, vecProd, true, 1, 1.0);
            SetAt(loctestnum, loctesterr, vecProd, true, 2, 0.5);
            FoldPostOrder(loctestnum, loctesterr, vecProd, true, &FoldMultiply<double>, 1.0, 1.0);


            vec.Resize(4); 
            Fold(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 4.3);
            Map(loctestnum, loctesterr, vec, true, &MapIncrement<double>); 
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 8.3);

            vec.Resize(2); 
            SetAt(loctestnum, loctesterr, vec, true, 0, 15.5); 
            MapPreOrder(loctestnum, loctesterr, vec, true, &MapIncrement<double>); 
            GetAt(loctestnum, loctesterr, vec, true, 0, 16.5);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            MapPostOrder(loctestnum, loctesterr, vec, true, &MapDouble<double>); 
            GetAt(loctestnum, loctesterr, vec, true, 0, 33.0);
            Fold(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 39.0); 

            vec.Resize(0);
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);
        }
        // Some Resize and clears
        {
            lasd::SortableVector<double> vec(3);
            SetAt(loctestnum, loctesterr, vec, true, 0, 1.1);
            SetAt(loctestnum, loctesterr, vec, true, 1, -2.2);
            SetAt(loctestnum, loctesterr, vec, true, 2, 3.3);
            
            vec.Resize(5); 
            Size(loctestnum, loctesterr, vec, true, 5);
            GetAt(loctestnum, loctesterr, vec, true, 0, 1.1);
            GetAt(loctestnum, loctesterr, vec, true, 2, 3.3);
            GetAt(loctestnum, loctesterr, vec, true, 3, 0.0); 
            GetAt(loctestnum, loctesterr, vec, true, 4, 0.0); 
            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            vec.Sort();
            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            GetAt(loctestnum, loctesterr, vec, true, 0, -2.2);
            GetAt(loctestnum, loctesterr, vec, true, 4, 3.3);

            vec.Resize(2); 
            Size(loctestnum, loctesterr, vec, true, 2);
            GetAt(loctestnum, loctesterr, vec, true, 0, -2.2);
            GetAt(loctestnum, loctesterr, vec, true, 1, 0.0);
            GetAt(loctestnum, loctesterr, vec, false, 2, 0.0); 

            vec.Resize(0); 
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            lasd::SortableVector<double> vec_to_clear(3);
            SetAt(loctestnum, loctesterr, vec_to_clear, true, 0, 10.5);
            vec_to_clear.Clear();
            Empty(loctestnum, loctesterr, vec_to_clear, true);
            Size(loctestnum, loctesterr, vec_to_clear, true, 0);
        }
        // SortTest
        {
            lasd::SortableVector<double> svec_unsorted(5);
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 0, 50.5);
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 1, -20.2);
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 2, 40.4);
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 3, 0.0);
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 4, -30.3);
            Traverse(loctestnum, loctesterr, svec_unsorted, true, &TraversePrint<double>);
            svec_unsorted.Sort(); 
            Traverse(loctestnum, loctesterr, svec_unsorted, true, &TraversePrint<double>);

            GetAt(loctestnum, loctesterr, svec_unsorted, true, 0, -30.3);
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 1, -20.2);
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 2, 0.0);
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 3, 40.4);
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 4, 50.5);

            svec_unsorted.Sort(); 
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 0, -30.3);
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 4, 50.5);

            lasd::SortableVector<double> svec_rev(3);
            SetAt(loctestnum, loctesterr, svec_rev, true, 0, 3.3);
            SetAt(loctestnum, loctesterr, svec_rev, true, 1, 2.2);
            SetAt(loctestnum, loctesterr, svec_rev, true, 2, 1.1);
            svec_rev.Sort(); 
            GetAt(loctestnum, loctesterr, svec_rev, true, 0, 1.1);
            GetAt(loctestnum, loctesterr, svec_rev, true, 2, 3.3);

            lasd::SortableVector<double> svec_dup(5);
            SetAt(loctestnum, loctesterr, svec_dup, true, 0, 5.5);
            SetAt(loctestnum, loctesterr, svec_dup, true, 1, 2.2);
            SetAt(loctestnum, loctesterr, svec_dup, true, 2, 5.5);
            SetAt(loctestnum, loctesterr, svec_dup, true, 3, 1.1);
            SetAt(loctestnum, loctesterr, svec_dup, true, 4, 2.2);
            svec_dup.Sort(); 
            GetAt(loctestnum, loctesterr, svec_dup, true, 0, 1.1); 
            GetAt(loctestnum, loctesterr, svec_dup, true, 1, 2.2);
            GetAt(loctestnum, loctesterr, svec_dup, true, 2, 2.2); 
            GetAt(loctestnum, loctesterr, svec_dup, true, 3, 5.5);
            GetAt(loctestnum, loctesterr, svec_dup, true, 4, 5.5);
        }
        // Copy Constructor
        {
            lasd::SortableVector<double> vec(3);
            SetAt(loctestnum, loctesterr, vec, true, 0, 7.7);
            SetAt(loctestnum, loctesterr, vec, true, 1, -8.8);
            SetAt(loctestnum, loctesterr, vec, true, 2, 0.9);
            vec.Sort(); 

            lasd::SortableVector<double> copyvec(vec);
            EqualVector(loctestnum, loctesterr, vec, copyvec, true);
            EqualLinear(loctestnum, loctesterr, vec, copyvec, true);
            TraversePreOrder(loctestnum, loctesterr, copyvec, true, &TraversePrint<double>);
            Size(loctestnum, loctesterr, copyvec, true, 3);
            GetAt(loctestnum, loctesterr, copyvec, true, 0, -8.8);

            MapPreOrder(loctestnum, loctesterr, copyvec, true, &MapIncrement<double>); 
            NonEqualVector(loctestnum, loctesterr, vec, copyvec, true);
            NonEqualLinear(loctestnum, loctesterr, vec, copyvec, true);

            lasd::SortableVector<double> empty_vec;
            lasd::SortableVector<double> copy_of_empty(empty_vec);
            Empty(loctestnum, loctesterr, copy_of_empty, true);
        }
        // Move constructor
        {
            lasd::SortableVector<double> vec(3);
            SetAt(loctestnum, loctesterr, vec, true, 0, 56.1);
            SetAt(loctestnum, loctesterr, vec, true, 1, -23.2);
            SetAt(loctestnum, loctesterr, vec, true, 2, 10.0);
            vec.Sort(); 

            lasd::SortableVector<double> vec_moved(std::move(vec));
            Size(loctestnum, loctesterr, vec_moved, true, 3);
            GetAt(loctestnum, loctesterr, vec_moved, true, 0, -23.2);

            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0); 
        }
        // Copy Assignment
        {
            lasd::SortableVector<double> vec_orig(2);
            SetAt(loctestnum, loctesterr, vec_orig, true, 0, -4100.5);
            SetAt(loctestnum, loctesterr, vec_orig, true, 1, 2033.1);
            vec_orig.Sort(); 

            lasd::SortableVector<double> vec_assign;
            vec_assign = vec_orig;
            EqualVector(loctestnum, loctesterr, vec_orig, vec_assign, true);
            EqualLinear(loctestnum, loctesterr, vec_orig, vec_assign, true);
            GetAt(loctestnum, loctesterr, vec_assign, true, 0, -4100.5);
            
            vec_assign = vec_assign; 
            EqualVector(loctestnum, loctesterr, vec_orig, vec_assign, true);
            
            Map(loctestnum, loctesterr, vec_orig, true, &MapIncrement<double>); 
            NonEqualVector(loctestnum, loctesterr, vec_orig, vec_assign, true);
            NonEqualLinear(loctestnum, loctesterr, vec_orig, vec_assign, true);

            lasd::SortableVector<double> empty_svec;
            vec_assign = empty_svec; 
            Empty(loctestnum, loctesterr, vec_assign, true);
            Size(loctestnum, loctesterr, vec_assign, true, 0);
        }
        // Move Assignment
        {
            lasd::SortableVector<double> vec_orig(2);
            SetAt(loctestnum, loctesterr, vec_orig, true, 0, 300.3);
            SetAt(loctestnum, loctesterr, vec_orig, true, 1, -120.1);
            vec_orig.Sort(); 

            lasd::SortableVector<double> vec_assign;
            vec_assign = std::move(vec_orig);
            Size(loctestnum, loctesterr, vec_assign, true, 2);
            GetAt(loctestnum, loctesterr, vec_assign, true, 0, -120.1);
            Empty(loctestnum, loctesterr, vec_orig, true); 

            vec_assign = std::move(vec_assign); 
            Size(loctestnum, loctesterr, vec_assign, true, 2); 
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MyVec<double> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

void myvec_string(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        cout << endl<< "############################################################################"<< endl;
        cout << endl << "---------------------- Begin of MyVec<string> tests: ----------------------" << endl;

        // Default Constructor
        {
            lasd::SortableVector<string> vec;

            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            GetFront(loctestnum, loctesterr, vec, false, string(""));
            GetBack(loctestnum, loctesterr, vec, false, string(""));
            GetAt(loctestnum, loctesterr, vec, false, 0, string(""));
            SetAt(loctestnum, loctesterr, vec, false, 0, string("oops"));

            Exists(loctestnum, loctesterr, vec, false, string("anything"));

            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);

            Fold(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("empty_fold"), string("empty_fold"));
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("empty_pre"), string("empty_pre"));
            FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("empty_post"), string("empty_post"));

            Map(loctestnum, loctesterr, vec, true, [](string &str){ MapStringAppend(str, "_mapped"); });
            MapPreOrder(loctestnum, loctesterr, vec, true, [](string &str){ MapStringAppend(str, "_pre_mapped"); });
            MapPostOrder(loctestnum, loctesterr, vec, true, [](string &str){ MapStringAppend(str, "_post_mapped"); });

            vec.Sort();
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            vec.Clear();
            Empty(loctestnum, loctesterr, vec, true);
        }
        // Size 0 Constructor
        {
            lasd::SortableVector<string> vec(0);

            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            GetFront(loctestnum, loctesterr, vec, false, string(""));
            GetBack(loctestnum, loctesterr, vec, false, string(""));
            GetAt(loctestnum, loctesterr, vec, false, 0, string(""));
            SetAt(loctestnum, loctesterr, vec, false, 0, string("fail_set"));

            Exists(loctestnum, loctesterr, vec, false, string("nothing_here"));

            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);

            Fold(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("zero_fold"), string("zero_fold"));
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("zero_pre"), string("zero_pre"));
            FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("zero_post"), string("zero_post"));

            Map(loctestnum, loctesterr, vec, true, [](string &str){ MapStringAppend(str, "_map_attempt"); });
            MapPreOrder(loctestnum, loctesterr, vec, true, [](string &str){ MapStringAppend(str, "_pre_map_attempt"); });
            MapPostOrder(loctestnum, loctesterr, vec, true, [](string &str){ MapStringAppend(str, "_post_map_attempt"); });

            vec.Sort();
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            vec.Clear();
            Empty(loctestnum, loctesterr, vec, true);
        }
        //NonEmptyVectorSizeConstructor
        {
            lasd::SortableVector<string> vec(10); 

            Empty(loctestnum, loctesterr, vec, false);
            Size(loctestnum, loctesterr, vec, true, 10);

            SetAt(loctestnum, loctesterr, vec, true, 0, string("Python")); 
            SetAt(loctestnum, loctesterr, vec, true, 1, string("Java")); 
            SetAt(loctestnum, loctesterr, vec, true, 2, string("C++")); 
            SetAt(loctestnum, loctesterr, vec, true, 3, string("Rust")); 
            SetAt(loctestnum, loctesterr, vec, true, 4, string("Go")); 
            SetAt(loctestnum, loctesterr, vec, true, 5, string("Swift")); 
            SetAt(loctestnum, loctesterr, vec, true, 6, string("Kotlin")); 
            SetAt(loctestnum, loctesterr, vec, true, 7, string("Scala")); 
            SetAt(loctestnum, loctesterr, vec, true, 8, string("Ruby")); 
            SetAt(loctestnum, loctesterr, vec, true, 9, string("Perl")); 
            SetAt(loctestnum, loctesterr, vec, false, 10, string("OutOfBounds")); 

            GetAt(loctestnum, loctesterr, vec, true, 9, string("Perl"));
            GetAt(loctestnum, loctesterr, vec, false, 10, string("OutOfBounds"));
            GetFront(loctestnum, loctesterr, vec, true, string("Python"));
            GetBack(loctestnum, loctesterr, vec, true, string("Perl"));

            SetFront(loctestnum, loctesterr, vec, true, string("Ada")); 
            SetBack(loctestnum, loctesterr, vec, true, string("Zig"));  
            GetFront(loctestnum, loctesterr, vec, true, string("Ada"));
            GetBack(loctestnum, loctesterr, vec, true, string("Zig"));

            Exists(loctestnum, loctesterr, vec, true, string("Zig"));
            Exists(loctestnum, loctesterr, vec, false, string("Lisp")); 
            Exists(loctestnum, loctesterr, vec, true, string("Java"));


            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);

            
            string fold_val = "AdaJavaC++RustGoSwiftKotlinScalaRubyZig";
            Fold(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string(""), fold_val);
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string(""), fold_val);
            string fold_post_val = "ZigRubyScalaKotlinSwiftGoRustC++JavaAda";
            FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string(""), fold_post_val);


            vec.Resize(4); 
            string fold_resize4 = "AdaJavaC++Rust";
            Fold(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string(""), fold_resize4);
            
            Map(loctestnum, loctesterr, vec, true, [](string &str){ MapStringAppend(str, "_v1"); }); 
            string fold_map_val = "Ada_v1Java_v1C++_v1Rust_v1";
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string(""), fold_map_val);
            string fold_map_post_val = "Rust_v1C++_v1Java_v1Ada_v1";
            FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string(""), fold_map_post_val);

        
            vec.Resize(2);
            SetAt(loctestnum, loctesterr, vec, true, 0, string("NewLang")); 
            MapPreOrder(loctestnum, loctesterr, vec, true, [](string &str){ MapStringAppend(str, "_beta"); }); 
            GetAt(loctestnum, loctesterr, vec, true, 0, string("NewLang_beta"));
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
            MapPostOrder(loctestnum, loctesterr, vec, true, [](string &str){ MapStringAppend(str, "_final"); });
            GetAt(loctestnum, loctesterr, vec, true, 0, string("NewLang_beta_final"));
            string fold_final_val = "NewLang_beta_finalJava_v1_beta_final";
            Fold(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string(""), fold_final_val);

            vec.Resize(0);
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);
        }
        // Some Resize and Clear
        {
            lasd::SortableVector<string> vec(3);
            SetAt(loctestnum, loctesterr, vec, true, 0, string("alpha_ver"));
            SetAt(loctestnum, loctesterr, vec, true, 1, string("beta_ver"));
            SetAt(loctestnum, loctesterr, vec, true, 2, string("gamma_ver"));
            
            vec.Resize(5); 
            Size(loctestnum, loctesterr, vec, true, 5);
            GetAt(loctestnum, loctesterr, vec, true, 0, string("alpha_ver"));
            GetAt(loctestnum, loctesterr, vec, true, 2, string("gamma_ver"));
            GetAt(loctestnum, loctesterr, vec, true, 3, string("")); 
            GetAt(loctestnum, loctesterr, vec, true, 4, string("")); 
            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
            vec.Sort(); 
            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
            GetAt(loctestnum, loctesterr, vec, true, 0, string(""));
            GetAt(loctestnum, loctesterr, vec, true, 1, string(""));
            GetAt(loctestnum, loctesterr, vec, true, 2, string("alpha_ver"));
            GetAt(loctestnum, loctesterr, vec, true, 3, string("beta_ver"));
            GetAt(loctestnum, loctesterr, vec, true, 4, string("gamma_ver"));


            vec.Resize(2); 
            Size(loctestnum, loctesterr, vec, true, 2);
            GetAt(loctestnum, loctesterr, vec, true, 0, string(""));
            GetAt(loctestnum, loctesterr, vec, true, 1, string(""));
            GetAt(loctestnum, loctesterr, vec, false, 2, string("any_string")); 

            vec.Resize(0); 
            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);

            lasd::SortableVector<string> vec_to_clear(3);
            SetAt(loctestnum, loctesterr, vec_to_clear, true, 0, string("temp_data"));
            vec_to_clear.Clear();
            Empty(loctestnum, loctesterr, vec_to_clear, true);
            Size(loctestnum, loctesterr, vec_to_clear, true, 0);
        }
        // SortTest
        {
            lasd::SortableVector<string> svec_unsorted(5);
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 0, string("Zephyr"));
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 1, string("apple"));
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 2, string("Banana"));
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 3, string("cherry"));
            SetAt(loctestnum, loctesterr, svec_unsorted, true, 4, string("Date"));
            Traverse(loctestnum, loctesterr, svec_unsorted, true, &TraversePrint<string>);
            svec_unsorted.Sort();
            Traverse(loctestnum, loctesterr, svec_unsorted, true, &TraversePrint<string>);
           
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 0, string("Banana"));
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 1, string("Date"));
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 2, string("Zephyr"));
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 3, string("apple"));
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 4, string("cherry"));

            svec_unsorted.Sort(); 
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 0, string("Banana"));
            GetAt(loctestnum, loctesterr, svec_unsorted, true, 4, string("cherry"));

            lasd::SortableVector<string> svec_rev(3);
            SetAt(loctestnum, loctesterr, svec_rev, true, 0, string("gamma"));
            SetAt(loctestnum, loctesterr, svec_rev, true, 1, string("beta"));
            SetAt(loctestnum, loctesterr, svec_rev, true, 2, string("alpha"));
            svec_rev.Sort(); 
            GetAt(loctestnum, loctesterr, svec_rev, true, 0, string("alpha"));
            GetAt(loctestnum, loctesterr, svec_rev, true, 2, string("gamma"));

            lasd::SortableVector<string> svec_dup(5);
            SetAt(loctestnum, loctesterr, svec_dup, true, 0, string("echo"));
            SetAt(loctestnum, loctesterr, svec_dup, true, 1, string("delta"));
            SetAt(loctestnum, loctesterr, svec_dup, true, 2, string("echo"));
            SetAt(loctestnum, loctesterr, svec_dup, true, 3, string("alpha"));
            SetAt(loctestnum, loctesterr, svec_dup, true, 4, string("delta"));
            svec_dup.Sort();
            GetAt(loctestnum, loctesterr, svec_dup, true, 0, string("alpha")); 
            GetAt(loctestnum, loctesterr, svec_dup, true, 1, string("delta"));
            GetAt(loctestnum, loctesterr, svec_dup, true, 2, string("delta")); 
            GetAt(loctestnum, loctesterr, svec_dup, true, 3, string("echo"));
            GetAt(loctestnum, loctesterr, svec_dup, true, 4, string("echo"));
        }
        // Copy Constructor
        {
            lasd::SortableVector<string> vec(3);
            SetAt(loctestnum, loctesterr, vec, true, 0, string("source_two"));
            SetAt(loctestnum, loctesterr, vec, true, 1, string("source_one"));
            SetAt(loctestnum, loctesterr, vec, true, 2, string("source_three"));
            vec.Sort(); // source_one, source_three, source_two (lexicographical)

            lasd::SortableVector<string> copyvec(vec);
            EqualVector(loctestnum, loctesterr, vec, copyvec, true);
            EqualLinear(loctestnum, loctesterr, vec, copyvec, true);
            TraversePreOrder(loctestnum, loctesterr, copyvec, true, &TraversePrint<string>);
            Size(loctestnum, loctesterr, copyvec, true, 3);
            GetAt(loctestnum, loctesterr, copyvec, true, 0, string("source_one"));

            MapPreOrder(loctestnum, loctesterr, copyvec, true, [](string &str){ MapStringAppend(str, "_copied"); });
            NonEqualVector(loctestnum, loctesterr, vec, copyvec, true);
            NonEqualLinear(loctestnum, loctesterr, vec, copyvec, true);

            lasd::SortableVector<string> empty_vec;
            lasd::SortableVector<string> copy_of_empty(empty_vec);
            Empty(loctestnum, loctesterr, copy_of_empty, true);
            Size(loctestnum, loctesterr, copy_of_empty, true, 0);
        }
        // Move constructor
        {
            lasd::SortableVector<string> vec(3);
            SetAt(loctestnum, loctesterr, vec, true, 0, string("movable_C"));
            SetAt(loctestnum, loctesterr, vec, true, 1, string("movable_A"));
            SetAt(loctestnum, loctesterr, vec, true, 2, string("movable_B"));
            vec.Sort(); 

            lasd::SortableVector<string> vec_moved(std::move(vec));
            Size(loctestnum, loctesterr, vec_moved, true, 3);
            GetAt(loctestnum, loctesterr, vec_moved, true, 0, string("movable_A"));
            string fold_move_val = "movable_Amovable_Bmovable_C";
            FoldPreOrder(loctestnum, loctesterr, vec_moved, true, &FoldStringConcatenate, string(""), fold_move_val);

            Empty(loctestnum, loctesterr, vec, true);
            Size(loctestnum, loctesterr, vec, true, 0);
        }
        // Copy Assignment
        {
            lasd::SortableVector<string> vec_orig(2);
            SetAt(loctestnum, loctesterr, vec_orig, true, 0, string("assign_Z"));
            SetAt(loctestnum, loctesterr, vec_orig, true, 1, string("assign_A"));
            vec_orig.Sort(); 

            lasd::SortableVector<string> vec_assign;
            vec_assign = vec_orig;
            EqualVector(loctestnum, loctesterr, vec_orig, vec_assign, true);
            EqualLinear(loctestnum, loctesterr, vec_orig, vec_assign, true);
            GetAt(loctestnum, loctesterr, vec_assign, true, 0, string("assign_A"));
            
            vec_assign = vec_assign; 
            EqualVector(loctestnum, loctesterr, vec_orig, vec_assign, true);
            
            Map(loctestnum, loctesterr, vec_orig, true, [](string &str){ MapStringAppend(str, "_modified"); }); // assign_A_modified, assign_Z_modified
            NonEqualVector(loctestnum, loctesterr, vec_orig, vec_assign, true); 
            NonEqualLinear(loctestnum, loctesterr, vec_orig, vec_assign, true);

            lasd::SortableVector<string> empty_svec;
            vec_assign = empty_svec; 
            Empty(loctestnum, loctesterr, vec_assign, true);
            Size(loctestnum, loctesterr, vec_assign, true, 0);
        }
        // Move Assignment
        {
            lasd::SortableVector<string> vec_orig(2);
            SetAt(loctestnum, loctesterr, vec_orig, true, 0, string("move_src_Y"));
            SetAt(loctestnum, loctesterr, vec_orig, true, 1, string("move_src_X"));
            vec_orig.Sort(); 

            lasd::SortableVector<string> vec_assign;
            vec_assign = std::move(vec_orig);
            Size(loctestnum, loctesterr, vec_assign, true, 2);
            GetAt(loctestnum, loctesterr, vec_assign, true, 0, string("move_src_X"));
            Empty(loctestnum, loctesterr, vec_orig, true);
            Size(loctestnum, loctesterr, vec_orig, true, 0);

            vec_assign = std::move(vec_assign); 
            Size(loctestnum, loctesterr, vec_assign, true, 2); 
            GetAt(loctestnum, loctesterr, vec_assign, true, 0, string("move_src_X"));
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MyVec<string> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}


/* ************************************************************************** */

void vec_test(uint &testnum, uint &testerr)
{
    myvec_int(testnum, testerr);
    myvec_double(testnum, testerr);
    myvec_string(testnum, testerr);
}

//! TODO copy/move tra vec e list 