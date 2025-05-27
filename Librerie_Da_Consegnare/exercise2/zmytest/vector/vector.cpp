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

            Size(loctestnum, loctesterr, vec, true, 3);
            GetAt(loctestnum, loctesterr, vec, true, 0, 7);


            MapPreOrder(loctestnum, loctesterr, copyvec, true, &MapIncrement<int>);
            NonEqualVector(loctestnum, loctesterr, vec, copyvec, true);
            NonEqualLinear(loctestnum, loctesterr, vec, copyvec, true);
            GetAt(loctestnum, loctesterr, vec, true, 0, 7);


            lasd::SortableVector<int> empty_vec;
            lasd::SortableVector<int> copy_of_empty(empty_vec);
            Empty(loctestnum, loctesterr, copy_of_empty, true);
            Size(loctestnum, loctesterr, copy_of_empty, true, 0);
            
            Empty(loctestnum, loctesterr, empty_vec, true);
            Size(loctestnum, loctesterr, empty_vec, true, 0);
        }
        // Move constructor
        {
            lasd::SortableVector<int> vec_source_non_empty(3);
            SetAt(loctestnum, loctesterr, vec_source_non_empty, true, 0, 56);
            SetAt(loctestnum, loctesterr, vec_source_non_empty, true, 1, 23);
            SetAt(loctestnum, loctesterr, vec_source_non_empty, true, 2, 10);
            vec_source_non_empty.Sort(); 

            lasd::SortableVector<int> vec_moved(std::move(vec_source_non_empty));
            Size(loctestnum, loctesterr, vec_moved, true, 3);
            GetAt(loctestnum, loctesterr, vec_moved, true, 0, 10);
            FoldPreOrder(loctestnum, loctesterr, vec_moved, true, &FoldAdd<int>, 0, 89);

            Empty(loctestnum, loctesterr, vec_source_non_empty, true);
            Size(loctestnum, loctesterr, vec_source_non_empty, true, 0);

            
            lasd::SortableVector<int> vec_source_empty;
            lasd::SortableVector<int> vec_moved_from_empty(std::move(vec_source_empty));
            Empty(loctestnum, loctesterr, vec_moved_from_empty, true);
            Size(loctestnum, loctesterr, vec_moved_from_empty, true, 0);

            Empty(loctestnum, loctesterr, vec_source_empty, true);
            Size(loctestnum, loctesterr, vec_source_empty, true, 0);
        }
        // Copy Assignment
        {
            lasd::SortableVector<int> vec_s1(3); // Source 1 (non-empty)
            SetAt(loctestnum, loctesterr, vec_s1, true, 0, 10);
            SetAt(loctestnum, loctesterr, vec_s1, true, 1, 20);
            SetAt(loctestnum, loctesterr, vec_s1, true, 2, 30);
            vec_s1.Sort();

            lasd::SortableVector<int> vec_s2(2); // Source 2 (non-empty, different size)
            SetAt(loctestnum, loctesterr, vec_s2, true, 0, 5);
            SetAt(loctestnum, loctesterr, vec_s2, true, 1, 15);
            vec_s2.Sort();
            
            lasd::SortableVector<int> vec_empty_s; // Source empty

            lasd::SortableVector<int> vec_d1(1);   // Destination 1 (non-empty)
            SetAt(loctestnum, loctesterr, vec_d1, true, 0, 99);

            lasd::SortableVector<int> vec_d_empty; // Destination empty

            // Case 1: Non-empty to Non-empty (different content/size)
            vec_d1 = vec_s1;
            EqualVector(loctestnum, loctesterr, vec_d1, vec_s1, true);
            EqualLinear(loctestnum, loctesterr, vec_d1, vec_s1, true);
            Size(loctestnum, loctesterr, vec_d1, true, 3);
            GetAt(loctestnum, loctesterr, vec_d1, true, 1, 20);
            Size(loctestnum, loctesterr, vec_s1, true, 3);

            // Case 2: Non-empty to Empty
            vec_d_empty = vec_s2;
            EqualVector(loctestnum, loctesterr, vec_d_empty, vec_s2, true);
            EqualLinear(loctestnum, loctesterr, vec_d_empty, vec_s2, true);
            Size(loctestnum, loctesterr, vec_d_empty, true, 2);
            GetAt(loctestnum, loctesterr, vec_d_empty, true, 0, 5);

            // Case 3: Empty to Non-empty
            vec_d1 = vec_empty_s;
            Empty(loctestnum, loctesterr, vec_d1, true);
            Size(loctestnum, loctesterr, vec_d1, true, 0);

            // Case 4: Empty to Empty
            vec_d_empty = vec_empty_s;
            Empty(loctestnum, loctesterr, vec_d_empty, true);
            Size(loctestnum, loctesterr, vec_d_empty, true, 0);
            
            // Case 5: Self-assignment (non-empty)
            lasd::SortableVector<int> vec_self_assign(vec_s1);
            vec_self_assign = vec_self_assign;
            EqualVector(loctestnum, loctesterr, vec_self_assign, vec_s1, true);
            EqualLinear(loctestnum, loctesterr, vec_self_assign, vec_s1, true);

            // Case 6: Self-assignment (empty)
            lasd::SortableVector<int> vec_empty_self_assign;
            vec_empty_self_assign = vec_empty_self_assign;
            Empty(loctestnum, loctesterr, vec_empty_self_assign, true);

            // Check independence after copy
            lasd::SortableVector<int> vec_orig_ind(vec_s1);
            lasd::SortableVector<int> vec_assign_ind;
            vec_assign_ind = vec_orig_ind;
            Map(loctestnum, loctesterr, vec_orig_ind, true, &MapIncrement<int>); 
            NonEqualVector(loctestnum, loctesterr, vec_orig_ind, vec_assign_ind, true);
            NonEqualLinear(loctestnum, loctesterr, vec_orig_ind, vec_assign_ind, true);
            GetAt(loctestnum, loctesterr, vec_assign_ind, true, 0, 10); 
        }
        // Move Assignment
        {
            // Case 1: Non-empty to Non-empty
            lasd::SortableVector<int> vec_s1_move(3);
            SetAt(loctestnum, loctesterr, vec_s1_move, true, 0, 100);
            SetAt(loctestnum, loctesterr, vec_s1_move, true, 1, 300);
            SetAt(loctestnum, loctesterr, vec_s1_move, true, 2, 200);
            vec_s1_move.Sort();
            lasd::SortableVector<int> vec_d1_move(1); 
            SetAt(loctestnum, loctesterr, vec_d1_move, true, 0, 50);
            vec_d1_move = std::move(vec_s1_move);
            Size(loctestnum, loctesterr, vec_d1_move, true, 3);
            GetAt(loctestnum, loctesterr, vec_d1_move, true, 1, 200);
            Empty(loctestnum, loctesterr, vec_s1_move, false);
            Size(loctestnum, loctesterr, vec_s1_move, true, 1);

            // Case 2: Non-empty to Empty
            lasd::SortableVector<int> vec_s2_move(2);
            SetAt(loctestnum, loctesterr, vec_s2_move, true, 0, 55);
            SetAt(loctestnum, loctesterr, vec_s2_move, true, 1, 66);
            vec_s2_move.Sort();
            lasd::SortableVector<int> vec_d_empty_move;
            vec_d_empty_move = std::move(vec_s2_move);
            Size(loctestnum, loctesterr, vec_d_empty_move, true, 2);
            GetAt(loctestnum, loctesterr, vec_d_empty_move, true, 0, 55);
            Empty(loctestnum, loctesterr, vec_s2_move, true);
            Size(loctestnum, loctesterr, vec_s2_move, true, 0);

            // Case 3: Empty to Non-empty
            lasd::SortableVector<int> vec_empty_s_move;
            lasd::SortableVector<int> vec_d3_move(2);
            SetAt(loctestnum, loctesterr, vec_d3_move, true, 0, 77);
            SetAt(loctestnum, loctesterr, vec_d3_move, true, 1, 88);
            vec_d3_move = std::move(vec_empty_s_move);
            Empty(loctestnum, loctesterr, vec_d3_move, true);
            Size(loctestnum, loctesterr, vec_d3_move, true, 0);
            Empty(loctestnum, loctesterr, vec_empty_s_move, false);
            Size(loctestnum, loctesterr, vec_empty_s_move, true, 2);

            // Case 4: Empty to Empty
            lasd::SortableVector<int> vec_empty_s2_move;
            lasd::SortableVector<int> vec_d_empty2_move;
            vec_d_empty2_move = std::move(vec_empty_s2_move);
            Empty(loctestnum, loctesterr, vec_d_empty2_move, true);
            Size(loctestnum, loctesterr, vec_d_empty2_move, true, 0);
            Empty(loctestnum, loctesterr, vec_empty_s2_move, true);
            Size(loctestnum, loctesterr, vec_empty_s2_move, true, 0);

            // Case 5: Self-move assignment
            // lasd::SortableVector<int> vec_self_move(3);
            // SetAt(loctestnum, loctesterr, vec_self_move, true, 0, 11);
            // SetAt(loctestnum, loctesterr, vec_self_move, true, 1, 22);
            // SetAt(loctestnum, loctesterr, vec_self_move, true, 2, 33);
            // vec_self_move.Sort();
            // vec_self_move = std::move(vec_self_move); 
            // Size(loctestnum, loctesterr, vec_self_move, true, 3); 
            // GetAt(loctestnum, loctesterr, vec_self_move, true, 0, 11);
        }
        // Copy/Move from TraversableContainer (LIST)
        {
            lasd::List<int> lst_empty_src;
            lasd::SortableVector<int> vec_from_empty_list_copy(lst_empty_src);
            Empty(loctestnum, loctesterr, vec_from_empty_list_copy, true);
            Size(loctestnum, loctesterr, vec_from_empty_list_copy, true, 0);
            Empty(loctestnum, loctesterr, lst_empty_src, true); 
            Size(loctestnum, loctesterr, lst_empty_src, true, 0);
         
            lasd::List<int> lst_non_empty_src;
            InsertAtBack(loctestnum, loctesterr, lst_non_empty_src, true, 70); 
            InsertAtFront(loctestnum, loctesterr, lst_non_empty_src, true, 50); 
            InsertAtBack(loctestnum, loctesterr, lst_non_empty_src, true, 60); 
            
            lasd::SortableVector<int> vec_from_list_copy(lst_non_empty_src);
            Size(loctestnum, loctesterr, vec_from_list_copy, true, 3);
            EqualLinear(loctestnum, loctesterr, vec_from_list_copy, lst_non_empty_src, true);        
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 0, 50);
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 1, 70);
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 2, 60);
            
            Size(loctestnum, loctesterr, lst_non_empty_src, true, 3); 
            GetFront(loctestnum, loctesterr, lst_non_empty_src, true, 50); 
            GetBack(loctestnum, loctesterr, lst_non_empty_src, true, 60);
            
            vec_from_list_copy.Sort(); 
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 0, 50);
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 1, 60);
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 2, 70);

            Map(loctestnum, loctesterr, vec_from_list_copy, true, &MapDecrement<int>);
            NonEqualLinear(loctestnum, loctesterr, vec_from_list_copy, lst_non_empty_src, true);       
        }
        // Move from MappableContainer (LIST - int)
        {
            lasd::List<int> lst_empty_src_move;
            lasd::SortableVector<int> vec_from_empty_list_move(std::move(lst_empty_src_move)); 
            Empty(loctestnum, loctesterr, vec_from_empty_list_move, true);
            Size(loctestnum, loctesterr, vec_from_empty_list_move, true, 0);
            Empty(loctestnum, loctesterr, lst_empty_src_move, true); 
            Size(loctestnum, loctesterr, lst_empty_src_move, true, 0);
         
            lasd::List<int> lst_non_empty_src_move; 
            InsertAtBack(loctestnum, loctesterr, lst_non_empty_src_move, true, 6); 
            InsertAtFront(loctestnum, loctesterr, lst_non_empty_src_move, true, 4); 
            InsertAtBack(loctestnum, loctesterr, lst_non_empty_src_move, true, 5); 
            
            lasd::SortableVector<int> vec_from_list_move(std::move(lst_non_empty_src_move)); 
            Size(loctestnum, loctesterr, vec_from_list_move, true, 3);
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 0, 4); 
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 1, 6);
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 2, 5);
            
            Empty(loctestnum, loctesterr, lst_non_empty_src_move, false);
            Size(loctestnum, loctesterr, lst_non_empty_src_move, true, 3); 
            GetFront(loctestnum, loctesterr, lst_non_empty_src_move, true, 4);
            
            vec_from_list_move.Sort(); 
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 0, 4);
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 1, 5);
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 2, 6);
        }
        // Copy from TraversableContainer (SETVEC - int)
        {
            lasd::SetVec<int> set_v_empty_src;
            lasd::SortableVector<int> vec_from_empty_setvec_copy(set_v_empty_src);
            Empty(loctestnum, loctesterr, vec_from_empty_setvec_copy, true);
            Size(loctestnum, loctesterr, vec_from_empty_setvec_copy, true, 0);
            Empty(loctestnum, loctesterr, set_v_empty_src, true); 
            Size(loctestnum, loctesterr, set_v_empty_src, true, 0);

            lasd::SetVec<int> set_v_non_empty_src;
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, 300);
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, 100);
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, 200); 

            lasd::SortableVector<int> vec_from_setvec_copy(set_v_non_empty_src);
            Size(loctestnum, loctesterr, vec_from_setvec_copy, true, 3);
            GetAt(loctestnum, loctesterr, vec_from_setvec_copy, true, 0, 100);
            GetAt(loctestnum, loctesterr, vec_from_setvec_copy, true, 1, 200);
            GetAt(loctestnum, loctesterr, vec_from_setvec_copy, true, 2, 300);
            EqualLinear(loctestnum, loctesterr, vec_from_setvec_copy, set_v_non_empty_src, true);

            Size(loctestnum, loctesterr, set_v_non_empty_src, true, 3); 
            Exists(loctestnum, loctesterr, set_v_non_empty_src, true, 100);

            vec_from_setvec_copy.Sort(); 
            GetAt(loctestnum, loctesterr, vec_from_setvec_copy, true, 0, 100);
        }
        // Copy from TraversableContainer (SETLST - int)
        {
            lasd::SetLst<int> set_l_empty_src;
            lasd::SortableVector<int> vec_from_empty_setlst_copy(set_l_empty_src);
            Empty(loctestnum, loctesterr, vec_from_empty_setlst_copy, true);
            Size(loctestnum, loctesterr, vec_from_empty_setlst_copy, true, 0);
            Empty(loctestnum, loctesterr, set_l_empty_src, true);
            Size(loctestnum, loctesterr, set_l_empty_src, true, 0);

            lasd::SetLst<int> set_l_non_empty_src;
            InsertC(loctestnum, loctesterr, set_l_non_empty_src, true, 90);
            InsertC(loctestnum, loctesterr, set_l_non_empty_src, true, 70);
            InsertC(loctestnum, loctesterr, set_l_non_empty_src, true, 80); 

            lasd::SortableVector<int> vec_from_setlst_copy(set_l_non_empty_src);
            Size(loctestnum, loctesterr, vec_from_setlst_copy, true, 3);
            GetAt(loctestnum, loctesterr, vec_from_setlst_copy, true, 0, 70);
            GetAt(loctestnum, loctesterr, vec_from_setlst_copy, true, 1, 80);
            GetAt(loctestnum, loctesterr, vec_from_setlst_copy, true, 2, 90);
            EqualLinear(loctestnum, loctesterr, vec_from_setlst_copy, set_l_non_empty_src, true);
            
            Size(loctestnum, loctesterr, set_l_non_empty_src, true, 3);
            Exists(loctestnum, loctesterr, set_l_non_empty_src, true, 70);

            vec_from_setlst_copy.Sort(); 
            GetAt(loctestnum, loctesterr, vec_from_setlst_copy, true, 0, 70);
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

            SetAt(loctestnum, loctesterr, vec, true, 0, 0.5);
            SetAt(loctestnum, loctesterr, vec, true, 1, -4.2);
            SetAt(loctestnum, loctesterr, vec, true, 2, 6.0);
            SetAt(loctestnum, loctesterr, vec, true, 3, 0.8);
            SetAt(loctestnum, loctesterr, vec, true, 4, 10.1);
            SetAt(loctestnum, loctesterr, vec, true, 5, -11.5);
            SetAt(loctestnum, loctesterr, vec, true, 6, 13.0);
            SetAt(loctestnum, loctesterr, vec, true, 7, -0.05);
            SetAt(loctestnum, loctesterr, vec, true, 8, 17.7);
            SetAt(loctestnum, loctesterr, vec, true, 9, 21.21);
            SetAt(loctestnum, loctesterr, vec, false, 10, 20.0); 

            GetAt(loctestnum, loctesterr, vec, true, 9, 21.21); 
            GetAt(loctestnum, loctesterr, vec, false, 10, 20.0); 
            GetFront(loctestnum, loctesterr, vec, true, 0.5); 
            GetBack(loctestnum, loctesterr, vec, true, 21.21); 

            SetFront(loctestnum, loctesterr, vec, true, 0.0); 
            SetBack(loctestnum, loctesterr, vec, true, 25.0); 
            GetFront(loctestnum, loctesterr, vec, true, 0.0);
            GetBack(loctestnum, loctesterr, vec, true, 25.0);

            Exists(loctestnum, loctesterr, vec, true, 25.0);
            Exists(loctestnum, loctesterr, vec, false, 7.77);

            Traverse(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            
            FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldMultiply<double>, 1.0, 0.0); 

            vec.Resize(4); 
            Map(loctestnum, loctesterr, vec, true, &MapIncrement<double>); 
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 6.6);
            FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldMultiply<double>, 1.0, -40.32); 
        
            vec.Resize(2);
            SetAt(loctestnum, loctesterr, vec, true, 0, 15.5); 
            MapPreOrder(loctestnum, loctesterr, vec, true, &MapIncrement<double>); 
            GetAt(loctestnum, loctesterr, vec, true, 0, 16.5);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            MapPostOrder(loctestnum, loctesterr, vec, true, &MapDouble<double>); 
            GetAt(loctestnum, loctesterr, vec, true, 0, 33.0);
            Fold(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 28.6); 

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

            Size(loctestnum, loctesterr, vec, true, 3);
            GetAt(loctestnum, loctesterr, vec, true, 0, -8.8);

            MapPreOrder(loctestnum, loctesterr, copyvec, true, &MapIncrement<double>); 
            NonEqualVector(loctestnum, loctesterr, vec, copyvec, true);
            NonEqualLinear(loctestnum, loctesterr, vec, copyvec, true);
            GetAt(loctestnum, loctesterr, vec, true, 0, -8.8);

            lasd::SortableVector<double> empty_vec;
            lasd::SortableVector<double> copy_of_empty(empty_vec);
            Empty(loctestnum, loctesterr, copy_of_empty, true);
            Size(loctestnum, loctesterr, copy_of_empty, true, 0);
            
            Empty(loctestnum, loctesterr, empty_vec, true);
            Size(loctestnum, loctesterr, empty_vec, true, 0);
        }
        // Move constructor
        {
            lasd::SortableVector<double> vec_source_non_empty(3);
            SetAt(loctestnum, loctesterr, vec_source_non_empty, true, 0, 56.1);
            SetAt(loctestnum, loctesterr, vec_source_non_empty, true, 1, -23.2);
            SetAt(loctestnum, loctesterr, vec_source_non_empty, true, 2, 10.0);
            vec_source_non_empty.Sort(); 

            lasd::SortableVector<double> vec_moved(std::move(vec_source_non_empty));
            Size(loctestnum, loctesterr, vec_moved, true, 3);
            GetAt(loctestnum, loctesterr, vec_moved, true, 0, -23.2);

            Empty(loctestnum, loctesterr, vec_source_non_empty, true); 
            Size(loctestnum, loctesterr, vec_source_non_empty, true, 0);
            
            lasd::SortableVector<double> vec_source_empty;
            lasd::SortableVector<double> vec_moved_from_empty(std::move(vec_source_empty));
            Empty(loctestnum, loctesterr, vec_moved_from_empty, true);
            Size(loctestnum, loctesterr, vec_moved_from_empty, true, 0);

            Empty(loctestnum, loctesterr, vec_source_empty, true); 
            Size(loctestnum, loctesterr, vec_source_empty, true, 0);
        }
        // Copy Assignment
        {
            lasd::SortableVector<double> vec_s1(3); 
            SetAt(loctestnum, loctesterr, vec_s1, true, 0, 10.1);
            SetAt(loctestnum, loctesterr, vec_s1, true, 1, 20.2);
            SetAt(loctestnum, loctesterr, vec_s1, true, 2, 30.3);
            vec_s1.Sort();
            lasd::SortableVector<double> vec_s2(2); 
            SetAt(loctestnum, loctesterr, vec_s2, true, 0, 5.5);
            SetAt(loctestnum, loctesterr, vec_s2, true, 1, 15.5);
            vec_s2.Sort();
            lasd::SortableVector<double> vec_empty_s; 
            lasd::SortableVector<double> vec_d1(1);   
            SetAt(loctestnum, loctesterr, vec_d1, true, 0, 99.9);
            lasd::SortableVector<double> vec_d_empty; 

            vec_d1 = vec_s1;
            EqualVector(loctestnum, loctesterr, vec_d1, vec_s1, true);
            EqualLinear(loctestnum, loctesterr, vec_d1, vec_s1, true);
            Size(loctestnum, loctesterr, vec_d1, true, 3);
            GetAt(loctestnum, loctesterr, vec_d1, true, 1, 20.2);
            Size(loctestnum, loctesterr, vec_s1, true, 3);

            vec_d_empty = vec_s2;
            EqualVector(loctestnum, loctesterr, vec_d_empty, vec_s2, true);
            EqualLinear(loctestnum, loctesterr, vec_d_empty, vec_s2, true);
            Size(loctestnum, loctesterr, vec_d_empty, true, 2);
            GetAt(loctestnum, loctesterr, vec_d_empty, true, 0, 5.5);

            vec_d1 = vec_empty_s;
            Empty(loctestnum, loctesterr, vec_d1, true);
            Size(loctestnum, loctesterr, vec_d1, true, 0);

            vec_d_empty = vec_empty_s;
            Empty(loctestnum, loctesterr, vec_d_empty, true);
            Size(loctestnum, loctesterr, vec_d_empty, true, 0);
            
            lasd::SortableVector<double> vec_self_assign(vec_s1);
            vec_self_assign = vec_self_assign;
            EqualVector(loctestnum, loctesterr, vec_self_assign, vec_s1, true);
            EqualLinear(loctestnum, loctesterr, vec_self_assign, vec_s1, true);

            lasd::SortableVector<double> vec_empty_self_assign;
            vec_empty_self_assign = vec_empty_self_assign;
            Empty(loctestnum, loctesterr, vec_empty_self_assign, true);

            lasd::SortableVector<double> vec_orig_ind(vec_s1);
            lasd::SortableVector<double> vec_assign_ind;
            vec_assign_ind = vec_orig_ind;
            Map(loctestnum, loctesterr, vec_orig_ind, true, &MapIncrement<double>); 
            NonEqualVector(loctestnum, loctesterr, vec_orig_ind, vec_assign_ind, true);
            NonEqualLinear(loctestnum, loctesterr, vec_orig_ind, vec_assign_ind, true);
            GetAt(loctestnum, loctesterr, vec_assign_ind, true, 0, 10.1); 
        }
        // Move Assignment
        {
            lasd::SortableVector<double> vec_s1_move(3); 
            SetAt(loctestnum, loctesterr, vec_s1_move, true, 0, 100.1);
            SetAt(loctestnum, loctesterr, vec_s1_move, true, 1, 300.3);
            SetAt(loctestnum, loctesterr, vec_s1_move, true, 2, 200.2);
            vec_s1_move.Sort();
            lasd::SortableVector<double> vec_d1_move(1); 
            SetAt(loctestnum, loctesterr, vec_d1_move, true, 0, 50.5);
            
            vec_d1_move = std::move(vec_s1_move); 
            Size(loctestnum, loctesterr, vec_d1_move, true, 3);
            GetAt(loctestnum, loctesterr, vec_d1_move, true, 1, 200.2); 
            Empty(loctestnum, loctesterr, vec_s1_move, false); 
            Size(loctestnum, loctesterr, vec_s1_move, true, 1); 

            lasd::SortableVector<double> vec_s2_move(2); 
            SetAt(loctestnum, loctesterr, vec_s2_move, true, 0, 55.5);
            SetAt(loctestnum, loctesterr, vec_s2_move, true, 1, 66.6);
            vec_s2_move.Sort();
            lasd::SortableVector<double> vec_d_empty_move; 
            
            vec_d_empty_move = std::move(vec_s2_move); 
            Size(loctestnum, loctesterr, vec_d_empty_move, true, 2);
            GetAt(loctestnum, loctesterr, vec_d_empty_move, true, 0, 55.5);
            Empty(loctestnum, loctesterr, vec_s2_move, true); 
            Size(loctestnum, loctesterr, vec_s2_move, true, 0); 

            lasd::SortableVector<double> vec_empty_s_move; 
            lasd::SortableVector<double> vec_d3_move(2); 
            SetAt(loctestnum, loctesterr, vec_d3_move, true, 0, 77.7);
            SetAt(loctestnum, loctesterr, vec_d3_move, true, 1, 88.8);
            
            vec_d3_move = std::move(vec_empty_s_move); 
            Empty(loctestnum, loctesterr, vec_d3_move, true); 
            Size(loctestnum, loctesterr, vec_d3_move, true, 0);
            Empty(loctestnum, loctesterr, vec_empty_s_move, false); 
            Size(loctestnum, loctesterr, vec_empty_s_move, true, 2); 

            lasd::SortableVector<double> vec_empty_s2_move; 
            lasd::SortableVector<double> vec_d_empty2_move; 
            vec_d_empty2_move = std::move(vec_empty_s2_move); 
            Empty(loctestnum, loctesterr, vec_d_empty2_move, true);
            Size(loctestnum, loctesterr, vec_d_empty2_move, true, 0);
            Empty(loctestnum, loctesterr, vec_empty_s2_move, true);
            Size(loctestnum, loctesterr, vec_empty_s2_move, true, 0);

            // lasd::SortableVector<double> vec_self_move(3);
            // SetAt(loctestnum, loctesterr, vec_self_move, true, 0, 11.1);
            // SetAt(loctestnum, loctesterr, vec_self_move, true, 1, 22.2);
            // SetAt(loctestnum, loctesterr, vec_self_move, true, 2, 33.3);
            // vec_self_move.Sort();
            // vec_self_move = std::move(vec_self_move); 
            // Size(loctestnum, loctesterr, vec_self_move, true, 3); 
            // GetAt(loctestnum, loctesterr, vec_self_move, true, 0, 11.1);
        }
        // Copy from TraversableContainer (LIST - double)
        {
            lasd::List<double> lst_empty_src;
            lasd::SortableVector<double> vec_from_empty_list_copy(lst_empty_src);
            Empty(loctestnum, loctesterr, vec_from_empty_list_copy, true);
            Size(loctestnum, loctesterr, vec_from_empty_list_copy, true, 0);
            Empty(loctestnum, loctesterr, lst_empty_src, true); 
            Size(loctestnum, loctesterr, lst_empty_src, true, 0);
         
            lasd::List<double> lst_non_empty_src;
            InsertAtBack(loctestnum, loctesterr, lst_non_empty_src, true, 70.0); 
            InsertAtFront(loctestnum, loctesterr, lst_non_empty_src, true, 50.0); 
            InsertAtBack(loctestnum, loctesterr, lst_non_empty_src, true, 60.0); 
            
            lasd::SortableVector<double> vec_from_list_copy(lst_non_empty_src); 
            Size(loctestnum, loctesterr, vec_from_list_copy, true, 3);
            EqualLinear(loctestnum, loctesterr, vec_from_list_copy, lst_non_empty_src, true);        
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 0, 50.0);
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 1, 70.0);
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 2, 60.0);
            
            Empty(loctestnum, loctesterr, lst_non_empty_src, false); 
            Size(loctestnum, loctesterr, lst_non_empty_src, true, 3); 
            GetFront(loctestnum, loctesterr, lst_non_empty_src, true, 50.0); 
            GetBack(loctestnum, loctesterr, lst_non_empty_src, true, 60.0);
            
            vec_from_list_copy.Sort(); 
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 0, 50.0);
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 1, 60.0);
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 2, 70.0);

            Map(loctestnum, loctesterr, vec_from_list_copy, true, &MapDecrement<double>);
            NonEqualLinear(loctestnum, loctesterr, vec_from_list_copy, lst_non_empty_src, true);
        }
        // Move from MappableContainer (LIST - double)
        {
            lasd::List<double> lst_empty_src_move;
            lasd::SortableVector<double> vec_from_empty_list_move(std::move(lst_empty_src_move)); 
            Empty(loctestnum, loctesterr, vec_from_empty_list_move, true);
            Size(loctestnum, loctesterr, vec_from_empty_list_move, true, 0);
            Empty(loctestnum, loctesterr, lst_empty_src_move, true); 
            Size(loctestnum, loctesterr, lst_empty_src_move, true, 0);
         
            lasd::List<double> lst_non_empty_src_move; 
            InsertAtBack(loctestnum, loctesterr, lst_non_empty_src_move, true, 1.6); 
            InsertAtFront(loctestnum, loctesterr, lst_non_empty_src_move, true, 1.4); 
            InsertAtBack(loctestnum, loctesterr, lst_non_empty_src_move, true, 1.5); 
            
            lasd::SortableVector<double> vec_from_list_move(std::move(lst_non_empty_src_move)); 
            Size(loctestnum, loctesterr, vec_from_list_move, true, 3);
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 0, 1.4);
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 1, 1.6);
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 2, 1.5);
            
            Empty(loctestnum, loctesterr, lst_non_empty_src_move, false); 
            Size(loctestnum, loctesterr, lst_non_empty_src_move, true, 3); 
            GetFront(loctestnum, loctesterr, lst_non_empty_src_move, true, 1.4);
            
            vec_from_list_move.Sort(); 
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 0, 1.4);
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 1, 1.5);
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 2, 1.6);
        }
        // Copy from TraversableContainer (SETVEC - double)
        {
            lasd::SetVec<double> set_v_empty_src;
            lasd::SortableVector<double> vec_from_empty_setvec_copy(set_v_empty_src);
            Empty(loctestnum, loctesterr, vec_from_empty_setvec_copy, true);
            Size(loctestnum, loctesterr, vec_from_empty_setvec_copy, true, 0);
            Empty(loctestnum, loctesterr, set_v_empty_src, true);
            Size(loctestnum, loctesterr, set_v_empty_src, true, 0);

            lasd::SetVec<double> set_v_non_empty_src;
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, 30.3);
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, 10.1);
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, 20.2);

            lasd::SortableVector<double> vec_from_setvec_copy(set_v_non_empty_src);
            Size(loctestnum, loctesterr, vec_from_setvec_copy, true, 3);
            GetAt(loctestnum, loctesterr, vec_from_setvec_copy, true, 0, 10.1);
            GetAt(loctestnum, loctesterr, vec_from_setvec_copy, true, 1, 20.2);
            GetAt(loctestnum, loctesterr, vec_from_setvec_copy, true, 2, 30.3);
            EqualLinear(loctestnum, loctesterr, vec_from_setvec_copy, set_v_non_empty_src, true);

            Size(loctestnum, loctesterr, set_v_non_empty_src, true, 3);
            Exists(loctestnum, loctesterr, set_v_non_empty_src, true, 10.1);

            vec_from_setvec_copy.Sort();
            GetAt(loctestnum, loctesterr, vec_from_setvec_copy, true, 0, 10.1);
        }
        // Copy from TraversableContainer (SETLST - double)
        {
            lasd::SetLst<double> set_l_empty_src;
            lasd::SortableVector<double> vec_from_empty_setlst_copy(set_l_empty_src);
            Empty(loctestnum, loctesterr, vec_from_empty_setlst_copy, true);
            Size(loctestnum, loctesterr, vec_from_empty_setlst_copy, true, 0);
            Empty(loctestnum, loctesterr, set_l_empty_src, true);
            Size(loctestnum, loctesterr, set_l_empty_src, true, 0);

            lasd::SetLst<double> set_l_non_empty_src;
            InsertC(loctestnum, loctesterr, set_l_non_empty_src, true, 9.9);
            InsertC(loctestnum, loctesterr, set_l_non_empty_src, true, 7.7);
            InsertC(loctestnum, loctesterr, set_l_non_empty_src, true, 8.8);

            lasd::SortableVector<double> vec_from_setlst_copy(set_l_non_empty_src);
            Size(loctestnum, loctesterr, vec_from_setlst_copy, true, 3);
            GetAt(loctestnum, loctesterr, vec_from_setlst_copy, true, 0, 7.7);
            GetAt(loctestnum, loctesterr, vec_from_setlst_copy, true, 1, 8.8);
            GetAt(loctestnum, loctesterr, vec_from_setlst_copy, true, 2, 9.9);
            EqualLinear(loctestnum, loctesterr, vec_from_setlst_copy, set_l_non_empty_src, true);

            Size(loctestnum, loctesterr, set_l_non_empty_src, true, 3);
            Exists(loctestnum, loctesterr, set_l_non_empty_src, true, 7.7);

            vec_from_setlst_copy.Sort();
            GetAt(loctestnum, loctesterr, vec_from_setlst_copy, true, 0, 7.7);
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
            vec.Sort(); 

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
            lasd::SortableVector<string> vec_source(3);
            SetAt(loctestnum, loctesterr, vec_source, true, 0, string("movable_C"));
            SetAt(loctestnum, loctesterr, vec_source, true, 1, string("movable_A"));
            SetAt(loctestnum, loctesterr, vec_source, true, 2, string("movable_B"));
            vec_source.Sort(); 

            lasd::SortableVector<string> vec_moved(std::move(vec_source));
            Size(loctestnum, loctesterr, vec_moved, true, 3);
            GetAt(loctestnum, loctesterr, vec_moved, true, 0, string("movable_A"));
            string fold_move_val = "movable_Amovable_Bmovable_C";
            FoldPreOrder(loctestnum, loctesterr, vec_moved, true, &FoldStringConcatenate, string(""), fold_move_val);

            Empty(loctestnum, loctesterr, vec_source, true); 
            Size(loctestnum, loctesterr, vec_source, true, 0);
        }
        // Copy Assignment
        {
            lasd::SortableVector<string> vec_s1(3); 
            SetAt(loctestnum, loctesterr, vec_s1, true, 0, string("copyAssignA"));
            SetAt(loctestnum, loctesterr, vec_s1, true, 1, string("copyAssignB"));
            SetAt(loctestnum, loctesterr, vec_s1, true, 2, string("copyAssignC"));
            vec_s1.Sort();
            lasd::SortableVector<string> vec_s2(2); 
            SetAt(loctestnum, loctesterr, vec_s2, true, 0, string("copyAssignX"));
            SetAt(loctestnum, loctesterr, vec_s2, true, 1, string("copyAssignY"));
            vec_s2.Sort();
            lasd::SortableVector<string> vec_empty_s; 
            lasd::SortableVector<string> vec_d1(1);   
            SetAt(loctestnum, loctesterr, vec_d1, true, 0, string("old_value_D1"));
            lasd::SortableVector<string> vec_d_empty; 

            vec_d1 = vec_s1;
            EqualVector(loctestnum, loctesterr, vec_d1, vec_s1, true);
            EqualLinear(loctestnum, loctesterr, vec_d1, vec_s1, true);
            Size(loctestnum, loctesterr, vec_d1, true, 3);
            GetAt(loctestnum, loctesterr, vec_d1, true, 1, string("copyAssignB"));
            Size(loctestnum, loctesterr, vec_s1, true, 3);

            vec_d_empty = vec_s2;
            EqualVector(loctestnum, loctesterr, vec_d_empty, vec_s2, true);
            EqualLinear(loctestnum, loctesterr, vec_d_empty, vec_s2, true);
            Size(loctestnum, loctesterr, vec_d_empty, true, 2);
            GetAt(loctestnum, loctesterr, vec_d_empty, true, 0, string("copyAssignX"));

            vec_d1 = vec_empty_s;
            Empty(loctestnum, loctesterr, vec_d1, true);
            Size(loctestnum, loctesterr, vec_d1, true, 0);

            vec_d_empty = vec_empty_s;
            Empty(loctestnum, loctesterr, vec_d_empty, true);
            Size(loctestnum, loctesterr, vec_d_empty, true, 0);
            
            lasd::SortableVector<string> vec_self_assign(vec_s1);
            vec_self_assign = vec_self_assign;
            EqualVector(loctestnum, loctesterr, vec_self_assign, vec_s1, true);
            EqualLinear(loctestnum, loctesterr, vec_self_assign, vec_s1, true);

            lasd::SortableVector<string> vec_empty_self_assign;
            vec_empty_self_assign = vec_empty_self_assign;
            Empty(loctestnum, loctesterr, vec_empty_self_assign, true);

            lasd::SortableVector<string> vec_orig_ind(vec_s1);
            lasd::SortableVector<string> vec_assign_ind;
            vec_assign_ind = vec_orig_ind;
            Map(loctestnum, loctesterr, vec_orig_ind, true, [](string &str){ MapStringAppend(str, "_modified"); }); 
            NonEqualVector(loctestnum, loctesterr, vec_orig_ind, vec_assign_ind, true);
            NonEqualLinear(loctestnum, loctesterr, vec_orig_ind, vec_assign_ind, true);
            GetAt(loctestnum, loctesterr, vec_assign_ind, true, 0, string("copyAssignA")); 
        }
        // Move Assignment
        {
            lasd::SortableVector<string> vec_s1_move(3); 
            SetAt(loctestnum, loctesterr, vec_s1_move, true, 0, string("moveAssignC"));
            SetAt(loctestnum, loctesterr, vec_s1_move, true, 1, string("moveAssignA"));
            SetAt(loctestnum, loctesterr, vec_s1_move, true, 2, string("moveAssignB"));
            vec_s1_move.Sort();
            lasd::SortableVector<string> vec_d1_move(1); 
            SetAt(loctestnum, loctesterr, vec_d1_move, true, 0, string("old_D1_str"));
            
            vec_d1_move = std::move(vec_s1_move); 
            Size(loctestnum, loctesterr, vec_d1_move, true, 3);
            GetAt(loctestnum, loctesterr, vec_d1_move, true, 1, string("moveAssignB"));
            Empty(loctestnum, loctesterr, vec_s1_move, false);
            Size(loctestnum, loctesterr, vec_s1_move, true, 1); 

            lasd::SortableVector<string> vec_s2_move(2); 
            SetAt(loctestnum, loctesterr, vec_s2_move, true, 0, string("moveAssignX"));
            SetAt(loctestnum, loctesterr, vec_s2_move, true, 1, string("moveAssignY"));
            vec_s2_move.Sort();
            lasd::SortableVector<string> vec_d_empty_move; 
            
            vec_d_empty_move = std::move(vec_s2_move); 
            Size(loctestnum, loctesterr, vec_d_empty_move, true, 2);
            GetAt(loctestnum, loctesterr, vec_d_empty_move, true, 0, string("moveAssignX"));
            Empty(loctestnum, loctesterr, vec_s2_move, true);
            Size(loctestnum, loctesterr, vec_s2_move, true, 0);

            lasd::SortableVector<string> vec_empty_s_move; 
            lasd::SortableVector<string> vec_d3_move(2);
            SetAt(loctestnum, loctesterr, vec_d3_move, true, 0, string("old_D3_str1"));
            SetAt(loctestnum, loctesterr, vec_d3_move, true, 1, string("old_D3_str2"));
            
            vec_d3_move = std::move(vec_empty_s_move); 
            Empty(loctestnum, loctesterr, vec_d3_move, true);
            Size(loctestnum, loctesterr, vec_d3_move, true, 0);
            Empty(loctestnum, loctesterr, vec_empty_s_move, false); 
            Size(loctestnum, loctesterr, vec_empty_s_move, true, 2);

            lasd::SortableVector<string> vec_empty_s2_move; 
            lasd::SortableVector<string> vec_d_empty2_move; 
            vec_d_empty2_move = std::move(vec_empty_s2_move); 
            Empty(loctestnum, loctesterr, vec_d_empty2_move, true);
            Size(loctestnum, loctesterr, vec_d_empty2_move, true, 0);
            Empty(loctestnum, loctesterr, vec_empty_s2_move, true);
            Size(loctestnum, loctesterr, vec_empty_s2_move, true, 0);

            // lasd::SortableVector<string> vec_self_move(3);
            // SetAt(loctestnum, loctesterr, vec_self_move, true, 0, string("selfMove1"));
            // SetAt(loctestnum, loctesterr, vec_self_move, true, 1, string("selfMove2"));
            // SetAt(loctestnum, loctesterr, vec_self_move, true, 2, string("selfMove3"));
            // vec_self_move.Sort();
            // vec_self_move = std::move(vec_self_move); 
            // Size(loctestnum, loctesterr, vec_self_move, true, 3); 
            // GetAt(loctestnum, loctesterr, vec_self_move, true, 0, string("selfMove1"));
        }
        // Copy from TraversableContainer (LIST - string)
        {
            lasd::List<string> lst_empty_src;
            lasd::SortableVector<string> vec_from_empty_list_copy(lst_empty_src);
            Empty(loctestnum, loctesterr, vec_from_empty_list_copy, true);
            Size(loctestnum, loctesterr, vec_from_empty_list_copy, true, 0);
            Empty(loctestnum, loctesterr, lst_empty_src, true); 
            Size(loctestnum, loctesterr, lst_empty_src, true, 0);
         
            lasd::List<string> lst_non_empty_src; 
            InsertAtBack(loctestnum, loctesterr, lst_non_empty_src, true, string("CharlieList")); 
            InsertAtFront(loctestnum, loctesterr, lst_non_empty_src, true, string("AlphaList"));   
            InsertAtBack(loctestnum, loctesterr, lst_non_empty_src, true, string("BravoList")); 
            
            lasd::SortableVector<string> vec_from_list_copy(lst_non_empty_src); 
            Size(loctestnum, loctesterr, vec_from_list_copy, true, 3);
            EqualLinear(loctestnum, loctesterr, vec_from_list_copy, lst_non_empty_src, true);        
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 0, string("AlphaList"));
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 1, string("CharlieList"));
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 2, string("BravoList"));
            
            Empty(loctestnum, loctesterr, lst_non_empty_src, false); 
            Size(loctestnum, loctesterr, lst_non_empty_src, true, 3); 
            GetFront(loctestnum, loctesterr, lst_non_empty_src, true, string("AlphaList")); 
            GetBack(loctestnum, loctesterr, lst_non_empty_src, true, string("BravoList"));
            
            vec_from_list_copy.Sort(); 
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 0, string("AlphaList"));
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 1, string("BravoList"));
            GetAt(loctestnum, loctesterr, vec_from_list_copy, true, 2, string("CharlieList"));

            Map(loctestnum, loctesterr, vec_from_list_copy, true, [](string &str){ MapStringAppend(str, "_copy"); });
            NonEqualLinear(loctestnum, loctesterr, vec_from_list_copy, lst_non_empty_src, true);
        }
        // Move from MappableContainer (LIST - string)
        {
            lasd::List<string> lst_empty_src_move;
            lasd::SortableVector<string> vec_from_empty_list_move(std::move(lst_empty_src_move)); 
            Empty(loctestnum, loctesterr, vec_from_empty_list_move, true);
            Size(loctestnum, loctesterr, vec_from_empty_list_move, true, 0);
            Empty(loctestnum, loctesterr, lst_empty_src_move, true); 
            Size(loctestnum, loctesterr, lst_empty_src_move, true, 0);
         
            lasd::List<string> lst_non_empty_src_move; 
            InsertAtBack(loctestnum, loctesterr, lst_non_empty_src_move, true, string("XrayMove")); 
            InsertAtFront(loctestnum, loctesterr, lst_non_empty_src_move, true, string("VictorMove"));   
            InsertAtBack(loctestnum, loctesterr, lst_non_empty_src_move, true, string("WhiskeyMove")); 
            
            lasd::SortableVector<string> vec_from_list_move(std::move(lst_non_empty_src_move));
            Size(loctestnum, loctesterr, vec_from_list_move, true, 3);
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 0, string("VictorMove"));
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 1, string("XrayMove"));
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 2, string("WhiskeyMove"));
        
            Empty(loctestnum, loctesterr, lst_non_empty_src_move, false); 
            Size(loctestnum, loctesterr, lst_non_empty_src_move, true, 3); 
            GetFront(loctestnum, loctesterr, lst_non_empty_src_move, false, string("VictorMove"));
            
            vec_from_list_move.Sort(); 
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 0, string("VictorMove"));
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 1, string("WhiskeyMove"));
            GetAt(loctestnum, loctesterr, vec_from_list_move, true, 2, string("XrayMove"));
        }
        // Copy from TraversableContainer (SETVEC)
        {
            lasd::SetVec<string> set_v_empty_src;
            lasd::SortableVector<string> vec_from_empty_setvec_copy(set_v_empty_src);
            Empty(loctestnum, loctesterr, vec_from_empty_setvec_copy, true);
            Size(loctestnum, loctesterr, vec_from_empty_setvec_copy, true, 0);
            Empty(loctestnum, loctesterr, set_v_empty_src, true);
            Size(loctestnum, loctesterr, set_v_empty_src, true, 0);

            lasd::SetVec<string> set_v_non_empty_src;
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, string("CCC_sv"));
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, string("AAA_sv"));
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, string("BBB_sv")); 

            lasd::SortableVector<string> vec_from_setvec_copy(set_v_non_empty_src);
            Size(loctestnum, loctesterr, vec_from_setvec_copy, true, 3);
            GetAt(loctestnum, loctesterr, vec_from_setvec_copy, true, 0, string("AAA_sv"));
            GetAt(loctestnum, loctesterr, vec_from_setvec_copy, true, 1, string("BBB_sv"));
            GetAt(loctestnum, loctesterr, vec_from_setvec_copy, true, 2, string("CCC_sv"));
            EqualLinear(loctestnum, loctesterr, vec_from_setvec_copy, set_v_non_empty_src, true);

            Size(loctestnum, loctesterr, set_v_non_empty_src, true, 3);
            Exists(loctestnum, loctesterr, set_v_non_empty_src, true, string("AAA_sv"));

            vec_from_setvec_copy.Sort();
            GetAt(loctestnum, loctesterr, vec_from_setvec_copy, true, 0, string("AAA_sv"));
        }
        // Copy from TraversableContainer (SETLST)
        {
            lasd::SetLst<string> set_l_empty_src;
            lasd::SortableVector<string> vec_from_empty_setlst_copy(set_l_empty_src);
            Empty(loctestnum, loctesterr, vec_from_empty_setlst_copy, true);
            Size(loctestnum, loctesterr, vec_from_empty_setlst_copy, true, 0);
            Empty(loctestnum, loctesterr, set_l_empty_src, true);
            Size(loctestnum, loctesterr, set_l_empty_src, true, 0);

            lasd::SetLst<string> set_l_non_empty_src;
            InsertC(loctestnum, loctesterr, set_l_non_empty_src, true, string("gamma_sl"));
            InsertC(loctestnum, loctesterr, set_l_non_empty_src, true, string("alpha_sl"));
            InsertC(loctestnum, loctesterr, set_l_non_empty_src, true, string("beta_sl"));

            lasd::SortableVector<string> vec_from_setlst_copy(set_l_non_empty_src);
            Size(loctestnum, loctesterr, vec_from_setlst_copy, true, 3);
            GetAt(loctestnum, loctesterr, vec_from_setlst_copy, true, 0, string("alpha_sl"));
            GetAt(loctestnum, loctesterr, vec_from_setlst_copy, true, 1, string("beta_sl"));
            GetAt(loctestnum, loctesterr, vec_from_setlst_copy, true, 2, string("gamma_sl"));
            EqualLinear(loctestnum, loctesterr, vec_from_setlst_copy, set_l_non_empty_src, true);

            Size(loctestnum, loctesterr, set_l_non_empty_src, true, 3);
            Exists(loctestnum, loctesterr, set_l_non_empty_src, true, string("alpha_sl"));

            vec_from_setlst_copy.Sort();
            GetAt(loctestnum, loctesterr, vec_from_setlst_copy, true, 0, string("alpha_sl"));
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