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

#include "../../zlasdtest/heap/heap.hpp"
#include "../../zlasdtest/pq/pq.hpp"

/* ************************************************************************** */

#include "../../heap/vec/heapvec.hpp"
#include "../../pq/heap/pqheap.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void mypqhp_int(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        cout << endl<< "############################################################################"<< endl;
        cout << endl << "---------------------- Begin of MyPQHeap<int> tests: ----------------------" << endl;

        // Empty PQHeap (Default Constructor)
        {
            lasd::PQHeap<int> pq;

            Empty(loctestnum, loctesterr, pq, true);
            Size(loctestnum, loctesterr, pq, true, 0);

            Traverse(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<int>);

            Fold(loctestnum, loctesterr, pq, true, &FoldAdd<int>, 0, 0);
            FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldAdd<int>, 0, 0);
            FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldAdd<int>, 0, 0);
            
            Tip(loctestnum, loctesterr, pq, false, 0); 
            RemoveTip(loctestnum, loctesterr, pq, false); 
            TipNRemove(loctestnum, loctesterr, pq, false, 0); 

            GetFront(loctestnum, loctesterr, pq, false, 0); 
            GetBack(loctestnum, loctesterr, pq, false, 0);  
            GetAt(loctestnum, loctesterr, pq, false, 0, 0); 

            Exists(loctestnum, loctesterr, pq, false, 5); 

            Change(loctestnum, loctesterr, pq, false, 0, 100); 

            Empty(loctestnum, loctesterr, pq, true);
            Size(loctestnum, loctesterr, pq, true, 0);
        }

       // PQHeap with 1, 2, 3 elements (using Insert)
        {
            // Size 1
            {
                lasd::PQHeap<int> pq1;
                Insert(loctestnum, loctesterr, pq1, 10);

                Traverse(loctestnum, loctesterr, pq1, true, &TraversePrint<int>);
                TraversePreOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<int>);
                TraversePostOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<int>);

                Empty(loctestnum, loctesterr, pq1, false);
                Size(loctestnum, loctesterr, pq1, true, 1);

                Tip(loctestnum, loctesterr, pq1, true, 10);
                GetFront(loctestnum, loctesterr, pq1, true, 10);
                GetBack(loctestnum, loctesterr, pq1, true, 10);
                GetAt(loctestnum, loctesterr, pq1, true, 0, 10);

                Exists(loctestnum, loctesterr, pq1, true, 10);
                Exists(loctestnum, loctesterr, pq1, false, 5);

                Traverse(loctestnum, loctesterr, pq1, true, &TraversePrint<int>);
                TraversePreOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<int>);
                TraversePostOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<int>);
                
                Fold(loctestnum, loctesterr, pq1, true, &FoldAdd<int>, 0, 10);
                Change(loctestnum, loctesterr, pq1, true, 0, 5); 
                Tip(loctestnum, loctesterr, pq1, true, 5);
                TipNRemove(loctestnum, loctesterr, pq1, true, 5);
                Empty(loctestnum, loctesterr, pq1, true);
            }

            // Size 2
            {
                lasd::PQHeap<int> pq2;
                Insert(loctestnum, loctesterr, pq2, 20);
                Insert(loctestnum, loctesterr, pq2, 10); 

                Traverse(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);
                TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);
                TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);

                Empty(loctestnum, loctesterr, pq2, false);
                Size(loctestnum, loctesterr, pq2, true, 2);
                Tip(loctestnum, loctesterr, pq2, true, 20);

                GetAt(loctestnum, loctesterr, pq2, true, 0, 20); 
                Exists(loctestnum, loctesterr, pq2, true, 10);
                Change(loctestnum, loctesterr, pq2, true, 1, 30);

                Traverse(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);
                TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);
                TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);

                Tip(loctestnum, loctesterr, pq2, true, 30);
                Change(loctestnum, loctesterr, pq2, true, 0, 5);  

                Traverse(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);
                TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);
                TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<int>);

                Tip(loctestnum, loctesterr, pq2, true, 20);
                RemoveTip(loctestnum, loctesterr, pq2, true); 
                Tip(loctestnum, loctesterr, pq2, true, 5);
                RemoveTip(loctestnum, loctesterr, pq2, true);
                Empty(loctestnum, loctesterr, pq2, true);
            }

            // Size 3
            {
                lasd::PQHeap<int> pq3;
                Insert(loctestnum, loctesterr, pq3, 15);
                Insert(loctestnum, loctesterr, pq3, 25);
                Insert(loctestnum, loctesterr, pq3, 5); 

                Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<int>);
                TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<int>);
                TraversePostOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<int>);

                Empty(loctestnum, loctesterr, pq3, false);
                Size(loctestnum, loctesterr, pq3, true, 3);
                Tip(loctestnum, loctesterr, pq3, true, 25);
                FoldPostOrder(loctestnum, loctesterr, pq3, true, &FoldAdd<int>, 0, 45); 

                Change(loctestnum, loctesterr, pq3, true, 1, 30);
                Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<int>);
                TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<int>);
                TraversePostOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<int>);
                Tip(loctestnum, loctesterr, pq3, true, 30);

                Change(loctestnum, loctesterr, pq3, true, 0, 1);
                Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<int>);
                TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<int>);
                TraversePostOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<int>);
                Tip(loctestnum, loctesterr, pq3, true, 25);

                TipNRemove(loctestnum, loctesterr, pq3, true, 25);
                TipNRemove(loctestnum, loctesterr, pq3, true, 5);
                TipNRemove(loctestnum, loctesterr, pq3, true, 1);
                Empty(loctestnum, loctesterr, pq3, true);
            }
       }

       // Copy Constructor (from PQHeap)
       {
            // Empty Heap
            lasd::PQHeap<int> pq_orig_empty;
            lasd::PQHeap<int> pq_copy_empty(pq_orig_empty);
            Empty(loctestnum, loctesterr, pq_copy_empty, true);
            Size(loctestnum, loctesterr, pq_copy_empty, true, 0);
            EqualLinear(loctestnum, loctesterr, pq_orig_empty, pq_copy_empty, true);

            // Size 1 Heap
            lasd::PQHeap<int> pq_orig_s1;
            Insert(loctestnum, loctesterr, pq_orig_s1, 100);
            lasd::PQHeap<int> pq_copy_s1(pq_orig_s1);
            
            Size(loctestnum, loctesterr, pq_copy_s1, true, 1);
            Tip(loctestnum, loctesterr, pq_copy_s1, true, 100);
            EqualLinear(loctestnum, loctesterr, pq_orig_s1, pq_copy_s1, true);
            Insert(loctestnum, loctesterr, pq_orig_s1, 110);
            Tip(loctestnum, loctesterr, pq_copy_s1, true, 100);
            NonEqualLinear(loctestnum, loctesterr, pq_orig_s1, pq_copy_s1, true);

            // Size 3 Heap
            lasd::PQHeap<int> pq_orig_multi;
            Insert(loctestnum, loctesterr, pq_orig_multi, 50);
            Insert(loctestnum, loctesterr, pq_orig_multi, 60);
            Insert(loctestnum, loctesterr, pq_orig_multi, 40); 
            lasd::PQHeap<int> pq_copy_multi(pq_orig_multi);

            Size(loctestnum, loctesterr, pq_copy_multi, true, 3);
            Tip(loctestnum, loctesterr, pq_copy_multi, true, 60);
            EqualLinear(loctestnum, loctesterr, pq_orig_multi, pq_copy_multi, true);
            RemoveTip(loctestnum, loctesterr, pq_orig_multi, true); 
            Tip(loctestnum, loctesterr, pq_copy_multi, true, 60);  
            NonEqualLinear(loctestnum, loctesterr, pq_orig_multi, pq_copy_multi, true);
       }

       // Move Constructor (from PQHeap)
       {
            // Empty Heap
            lasd::PQHeap<int> pq_orig_empty_mv;
            lasd::PQHeap<int> pq_mv_empty(move(pq_orig_empty_mv));
            Empty(loctestnum, loctesterr, pq_mv_empty, true);
            Empty(loctestnum, loctesterr, pq_orig_empty_mv, true); 

            // Size 1 Heap
            lasd::PQHeap<int> pq_orig_s1_mv;
            Insert(loctestnum, loctesterr, pq_orig_s1_mv, 200);
            lasd::PQHeap<int> pq_orig_s1_mv_compare(pq_orig_s1_mv); 
            lasd::PQHeap<int> pq_mv_s1(move(pq_orig_s1_mv));

            Size(loctestnum, loctesterr, pq_mv_s1, true, 1);
            Tip(loctestnum, loctesterr, pq_mv_s1, true, 200);
            Empty(loctestnum, loctesterr, pq_orig_s1_mv, true);
            EqualLinear(loctestnum, loctesterr, pq_mv_s1, pq_orig_s1_mv_compare, true);

            // Size 3 Heap
            lasd::PQHeap<int> pq_orig_multi_mv;
            Insert(loctestnum, loctesterr, pq_orig_multi_mv, 70);
            Insert(loctestnum, loctesterr, pq_orig_multi_mv, 80);
            Insert(loctestnum, loctesterr, pq_orig_multi_mv, 90);
            lasd::PQHeap<int> pq_orig_multi_mv_compare(pq_orig_multi_mv); 
            lasd::PQHeap<int> pq_mv_multi(move(pq_orig_multi_mv));

            Size(loctestnum, loctesterr, pq_mv_multi, true, 3);
            Tip(loctestnum, loctesterr, pq_mv_multi, true, 90);
            Empty(loctestnum, loctesterr, pq_orig_multi_mv, true);
            EqualLinear(loctestnum, loctesterr, pq_mv_multi, pq_orig_multi_mv_compare, true);
       }

       // Copy Assignment (from PQHeap)
       {
            lasd::PQHeap<int> pq_assign_src_empty;
            lasd::PQHeap<int> pq_assign_dest_empty;

            // Empty = Empty
            pq_assign_dest_empty = pq_assign_src_empty; 
            Empty(loctestnum, loctesterr, pq_assign_dest_empty, true);

            lasd::PQHeap<int> pq_assign_src1;
            Insert(loctestnum, loctesterr, pq_assign_src1, 10);
            Insert(loctestnum, loctesterr, pq_assign_src1, 20);

            lasd::PQHeap<int> pq_assign_dest1;

            // Empty = Non-Empty
            pq_assign_dest1 = pq_assign_src1; 
            Size(loctestnum, loctesterr, pq_assign_dest1, true, 2);
            Tip(loctestnum, loctesterr, pq_assign_dest1, true, 20);
            EqualLinear(loctestnum, loctesterr, pq_assign_src1, pq_assign_dest1, true);

            lasd::PQHeap<int> pq_assign_dest2;
            Insert(loctestnum, loctesterr, pq_assign_dest2, 5);

            // Non-Empty = Empty
            pq_assign_dest2 = pq_assign_src_empty; 
            Empty(loctestnum, loctesterr, pq_assign_dest2, true);

            lasd::PQHeap<int> pq_assign_dest3;
            Insert(loctestnum, loctesterr, pq_assign_dest3, 33);
            Insert(loctestnum, loctesterr, pq_assign_dest3, 44);

            // Non-Empty = Non-Empty
            pq_assign_dest3 = pq_assign_src1; 
            Size(loctestnum, loctesterr, pq_assign_dest3, true, 2);
            Tip(loctestnum, loctesterr, pq_assign_dest3, true, 20);
            EqualLinear(loctestnum, loctesterr, pq_assign_src1, pq_assign_dest3, true);
            Insert(loctestnum, loctesterr, pq_assign_src1, 30);
            Tip(loctestnum, loctesterr, pq_assign_dest3, true, 20); 
            NonEqualLinear(loctestnum, loctesterr, pq_assign_src1, pq_assign_dest3, true);

            pq_assign_src1 = pq_assign_src1;
            Size(loctestnum, loctesterr, pq_assign_src1, true, 3);
            Tip(loctestnum, loctesterr, pq_assign_src1, true, 30);
       }

       // Move Assignment (from PQHeap)
        {
            lasd::PQHeap<int> pq_assign_src_empty_mv;
            lasd::PQHeap<int> pq_assign_dest_empty_mv;

            // Empty = Empty
            pq_assign_dest_empty_mv = move(pq_assign_src_empty_mv);
            Empty(loctestnum, loctesterr, pq_assign_dest_empty_mv, true);
            Empty(loctestnum, loctesterr, pq_assign_src_empty_mv, true);

            lasd::PQHeap<int> pq_assign_src1_mv;
            Insert(loctestnum, loctesterr, pq_assign_src1_mv, 15);
            Insert(loctestnum, loctesterr, pq_assign_src1_mv, 25); 
            lasd::PQHeap<int> pq_assign_src1_mv_compare(pq_assign_src1_mv);

            lasd::PQHeap<int> pq_assign_dest1_mv;

            // Empty = Non-Empty
            pq_assign_dest1_mv = move(pq_assign_src1_mv);
            Size(loctestnum, loctesterr, pq_assign_dest1_mv, true, 2);
            Tip(loctestnum, loctesterr, pq_assign_dest1_mv, true, 25);
            Empty(loctestnum, loctesterr, pq_assign_src1_mv, true);
            EqualLinear(loctestnum, loctesterr, pq_assign_dest1_mv, pq_assign_src1_mv_compare, true);

            lasd::PQHeap<int> pq_assign_dest2_mv;
            Insert(loctestnum, loctesterr, pq_assign_dest2_mv, 8);

            // Non-Empty = Empty
            pq_assign_dest2_mv = move(pq_assign_src_empty_mv); 
            Empty(loctestnum, loctesterr, pq_assign_dest2_mv, true);

            lasd::PQHeap<int> pq_assign_src2_mv; 
            Insert(loctestnum, loctesterr, pq_assign_src2_mv, 77);
            lasd::PQHeap<int> pq_assign_src2_mv_compare(pq_assign_src2_mv);
            lasd::PQHeap<int> pq_assign_dest3_mv;
            Insert(loctestnum, loctesterr, pq_assign_dest3_mv, 55);
            Insert(loctestnum, loctesterr, pq_assign_dest3_mv, 66);

            // Non-Empty = Non-Empty
            pq_assign_dest3_mv = move(pq_assign_src2_mv); 
            Size(loctestnum, loctesterr, pq_assign_dest3_mv, true, 1);
            Tip(loctestnum, loctesterr, pq_assign_dest3_mv, true, 77);
            Empty(loctestnum, loctesterr, pq_assign_src2_mv, false);
            EqualLinear(loctestnum, loctesterr, pq_assign_dest3_mv, pq_assign_src2_mv_compare, true);

            // lasd::PQHeap<int> pq_self_assign_mv;
            // Insert(loctestnum, loctesterr, pq_self_assign_mv, 90);
            // Insert(loctestnum, loctesterr, pq_self_assign_mv, 95);
            // lasd::PQHeap<int> pq_self_assign_mv_compare(pq_self_assign_mv);
            // pq_self_assign_mv = move(pq_self_assign_mv);
            // EqualLinear(loctestnum, loctesterr, pq_self_assign_mv, pq_self_assign_mv_compare, true);
            // Size(loctestnum, loctesterr, pq_self_assign_mv, true, 2);
            // Tip(loctestnum, loctesterr, pq_self_assign_mv, true, 95);
        }

        // Copy/Move Constructors from other containers
        {
           
            // From Vector
            {   
                // Copy constructors 

                // Empty Vector
                { 
                    lasd::Vector<int> vec_src_empty(0);
                    lasd::PQHeap<int> pq_copy(vec_src_empty);

                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, vec_src_empty, true); 
                }

                // Vector Size 1
                { 
                    lasd::Vector<int> vec_src_s1(1);
                    SetAt(loctestnum, loctesterr, vec_src_s1, true, 0, 10);

                    lasd::PQHeap<int> pq_copy(vec_src_s1);
                    Tip(loctestnum, loctesterr, pq_copy, true, 10);
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, vec_src_s1, true, 1); 
                }

                // Vector Size 3
                { 
                    lasd::Vector<int> vec_src_s3(3);
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 0, 5);
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 1, 15);
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 2, 10);

                    lasd::PQHeap<int> pq_copy(vec_src_s3);
                    Tip(loctestnum, loctesterr, pq_copy, true, 15);
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, vec_src_s3, true, 3);
                }

                // Move Constructors

                // Empty Vector
                { 
                    
                    lasd::Vector<int> vec_src_empty(0);
                    lasd::PQHeap<int> pq_move(move(vec_src_empty));
                    Empty(loctestnum, loctesterr, pq_move, true);
                    Empty(loctestnum, loctesterr, vec_src_empty, true);
                }

                // Vector Size 1
                {   
                    lasd::Vector<int> vec_src_s1(1);
                    SetAt(loctestnum, loctesterr, vec_src_s1, true, 0, 20);
                
                    lasd::PQHeap<int> pq_move(move(vec_src_s1));
                    Tip(loctestnum, loctesterr, pq_move, true, 20);
                    Size(loctestnum, loctesterr, pq_move, true, 1);
                    Empty(loctestnum, loctesterr, vec_src_s1, false); 
                }

                // Vector Size 3
                { 
                    lasd::Vector<int> vec_src_s3(3);
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 0, 25);
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 1, 35);
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 2, 20);

                    lasd::PQHeap<int> pq_move(move(vec_src_s3));
                    Tip(loctestnum, loctesterr, pq_move, true, 35);
                    Size(loctestnum, loctesterr, pq_move, true, 3);
                    Empty(loctestnum, loctesterr, vec_src_s3, false); 
                }
            }

            // From List
            {
                // Copy Constructor

                // Empty List
                { 
                    lasd::List<int> lst_src_empty;
                    lasd::PQHeap<int> pq_copy(lst_src_empty);
                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, lst_src_empty, true);
                }

                // List Size 1
                { 
                    lasd::List<int> lst_src_s1;
                    InsertAtBack(loctestnum, loctesterr, lst_src_s1, true, 40);

                    lasd::PQHeap<int> pq_copy(lst_src_s1);
                    Tip(loctestnum, loctesterr, pq_copy, true, 40);
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, lst_src_s1, true, 1);
                }

                // List Size 3
                { 
                    lasd::List<int> lst_src_s3;
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, 45);
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, 55);
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, 50); 

                    lasd::PQHeap<int> pq_copy(lst_src_s3);
                    Tip(loctestnum, loctesterr, pq_copy, true, 55);
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, lst_src_s3, true, 3);
                }

                // Move Constructor
                
                // Empty List
                { 
                    lasd::List<int> lst_src_empty;
                    lasd::PQHeap<int> pq_move(move(lst_src_empty));
                    Empty(loctestnum, loctesterr, pq_move, true);
                    Empty(loctestnum, loctesterr, lst_src_empty, true);
                }

                // List Size 1
                { 
                    lasd::List<int> lst_src_s1;
                    InsertAtBack(loctestnum, loctesterr, lst_src_s1, true, 60);

                    lasd::PQHeap<int> pq_move(move(lst_src_s1));
                    Tip(loctestnum, loctesterr, pq_move, true, 60);
                    Size(loctestnum, loctesterr, pq_move, true, 1);
                    Empty(loctestnum, loctesterr, lst_src_s1, false);
                }

                // List Size 3
                { 
                    lasd::List<int> lst_src_s3;
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, 65);
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, 75);
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, 70);

                    lasd::PQHeap<int> pq_move(move(lst_src_s3));
                    Tip(loctestnum, loctesterr, pq_move, true, 75);
                    Size(loctestnum, loctesterr, pq_move, true, 3);
                    Empty(loctestnum, loctesterr, lst_src_s3, false);
                }
            }

            // From SetVec
            {
                // Copy Constructor

                // Empty SetVec
                { 
                    lasd::SetVec<int> set_src_empty;
                    lasd::PQHeap<int> pq_copy(set_src_empty);
                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, set_src_empty, true);
                }

                // SetVec Size 1
                { 
                    lasd::SetVec<int> set_src_s1;
                    InsertC(loctestnum, loctesterr, set_src_s1, true, 80);
                    
                    lasd::PQHeap<int> pq_copy(set_src_s1);
                    Tip(loctestnum, loctesterr, pq_copy, true, 80);
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, set_src_s1, true, 1);
                }

                // SetVec Size 3
                { 
                    lasd::SetVec<int> set_src_s3;
                    InsertC(loctestnum, loctesterr, set_src_s3, true, 85);
                    InsertC(loctestnum, loctesterr, set_src_s3, true, 95);
                    InsertC(loctestnum, loctesterr, set_src_s3, true, 90);

                    lasd::PQHeap<int> pq_copy(set_src_s3);
                    Tip(loctestnum, loctesterr, pq_copy, true, 95);
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, set_src_s3, true, 3);
                }
            }

            // From SetLst
            {
                // Copy Constructor

                // Empty SetLst
                { 
                    lasd::SetLst<int> set_src_empty;
                    lasd::PQHeap<int> pq_copy(set_src_empty);
                    
                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, set_src_empty, true);
                }

                // SetLst Size 1
                { 
                    lasd::SetLst<int> set_src_s1;
                    InsertC(loctestnum, loctesterr, set_src_s1, true, 120);
                    lasd::PQHeap<int> pq_copy(set_src_s1);

                    Tip(loctestnum, loctesterr, pq_copy, true, 120);
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, set_src_s1, true, 1);
                }

                // SetLst Size 3
                { 
                    lasd::SetLst<int> set_src_s3;
                    InsertC(loctestnum, loctesterr, set_src_s3, true, 125);
                    InsertC(loctestnum, loctesterr, set_src_s3, true, 135);
                    InsertC(loctestnum, loctesterr, set_src_s3, true, 130); 

                    lasd::PQHeap<int> pq_copy(set_src_s3);
                    Tip(loctestnum, loctesterr, pq_copy, true, 135);
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, set_src_s3, true, 3);
                }
            }

            // From HeapVec
            {
                // Copy Constructor

                // Empty HeapVec
                { 
                    lasd::HeapVec<int> hp_src_empty;
                    lasd::PQHeap<int> pq_copy(hp_src_empty);

                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, hp_src_empty, true);
                }

                // HeapVec Size 1
                { 
                    lasd::Vector<int> vec_for_hp_s1(1);
                    SetAt(loctestnum, loctesterr, vec_for_hp_s1, true, 0, 160);

                    lasd::HeapVec<int> hp_src_s1(vec_for_hp_s1); 
                    lasd::PQHeap<int> pq_copy(hp_src_s1);

                    Tip(loctestnum, loctesterr, pq_copy, true, 160);
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, hp_src_s1, true, 1);
                }

                // HeapVec Size 3
                { 
                    lasd::Vector<int> vec_for_hp_s3(3); 
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 0, 165);
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 1, 175);
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 2, 170);
                    lasd::HeapVec<int> hp_src_s3(vec_for_hp_s3); 
                    lasd::PQHeap<int> pq_copy(hp_src_s3);

                    Tip(loctestnum, loctesterr, pq_copy, true, 175);
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, hp_src_s3, true, 3);
                }

                // Move Constructor

                // Empty HeapVec
                { 
                    lasd::HeapVec<int> hp_src_empty;
                    lasd::PQHeap<int> pq_move(move(hp_src_empty));

                    Empty(loctestnum, loctesterr, pq_move, true);
                    Empty(loctestnum, loctesterr, hp_src_empty, true);
                }

                // HeapVec Size 1
                { 
                    lasd::Vector<int> vec_for_hp_s1(1);
                    SetAt(loctestnum, loctesterr, vec_for_hp_s1, true, 0, 180);    
                    lasd::HeapVec<int> hp_src_s1(vec_for_hp_s1);
                    lasd::PQHeap<int> pq_move(move(hp_src_s1));

                    Tip(loctestnum, loctesterr, pq_move, true, 180);
                    Size(loctestnum, loctesterr, pq_move, true, 1);
                    Empty(loctestnum, loctesterr, hp_src_s1, false);
                }

                // HeapVec Size 3
                { 
                    lasd::Vector<int> vec_for_hp_s3(3);
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 0, 185);    
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 1, 195);    
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 2, 190);    
                    lasd::HeapVec<int> hp_src_s3(vec_for_hp_s3);
                    lasd::PQHeap<int> pq_move(move(hp_src_s3));

                    Tip(loctestnum, loctesterr, pq_move, true, 195);
                    Size(loctestnum, loctesterr, pq_move, true, 3);
                    Empty(loctestnum, loctesterr, hp_src_s3, false);
                }
            }
        }

        // Comparison Operators
        {
            lasd::PQHeap<int> pq_comp1, pq_comp2, pq_comp3, pq_comp_empty1, pq_comp_empty2;
            Insert(loctestnum, loctesterr, pq_comp1, 10); Insert(loctestnum, loctesterr, pq_comp1, 20);
            Insert(loctestnum, loctesterr, pq_comp2, 20); Insert(loctestnum, loctesterr, pq_comp2, 10);
            Insert(loctestnum, loctesterr, pq_comp3, 10); Insert(loctestnum, loctesterr, pq_comp3, 30);

            EqualLinear(loctestnum, loctesterr, pq_comp1, pq_comp2, true);
            NonEqualLinear(loctestnum, loctesterr, pq_comp1, pq_comp3, true);
            NonEqualLinear(loctestnum, loctesterr, pq_comp1, pq_comp_empty1, true);
            EqualLinear(loctestnum, loctesterr, pq_comp_empty1, pq_comp_empty2, true);
        }

         // Stress Tests
        {
            lasd::PQHeap<int> pq_stress;
            
            const int stress_n = 200;

            // 1.1: Inserimenti sequenziali e rimozioni ordinate
            for(int i = 0; i < stress_n; ++i) 
                Insert(loctestnum, loctesterr, pq_stress, i);

            Size(loctestnum, loctesterr, pq_stress, true, stress_n);
            Tip(loctestnum, loctesterr, pq_stress, true, stress_n - 1);

            int last_removed = stress_n;
            for(int i = 0; i < stress_n; ++i) 
            {
                int current_tip = pq_stress.Tip();
                TipNRemove(loctestnum, loctesterr, pq_stress, true, stress_n - 1 - i);
                if(current_tip > last_removed && i > 0) 
                {
                    loctestnum++;
                    loctesterr++;
                    cout << "Errore: Rimozione non in ordine (1.1)." << endl;
                }
                last_removed = current_tip;
            }
            Empty(loctestnum, loctesterr, pq_stress, true);

            // 1.2: Inserimenti con duplicati e rimozioni ordinate
            for(int i = 0; i < stress_n; ++i) 
                Insert(loctestnum, loctesterr, pq_stress, i % 10);

            Size(loctestnum, loctesterr, pq_stress, true, stress_n);
            Tip(loctestnum, loctesterr, pq_stress, true, 9);

            last_removed = 10; 
            for(int i = 0; i < stress_n; ++i) 
            {
                int current_tip = pq_stress.Tip();
                RemoveTip(loctestnum, loctesterr, pq_stress, true);
                if (current_tip > last_removed && i > 0) 
                {
                    loctestnum++;
                    loctesterr++;
                    cout << "Errore: Rimozione non in ordine (1.2)." << endl;
                }
                last_removed = current_tip;
            }
            Empty(loctestnum, loctesterr, pq_stress, true);

            // 2: Cicli di operazioni miste
            const int num_cycles = 5;
            const int ops_insert = 50;
            const int ops_remove = 10;
            const int ops_change = 5;

            for(int cycle = 0; cycle < num_cycles; ++cycle) 
            {
                for(int i = 0; i < ops_insert; ++i) 
                    Insert(loctestnum, loctesterr, pq_stress, (i * (cycle + 1)) % 100 - 50);

                Empty(loctestnum, loctesterr, pq_stress, false);

                for(int i = 0; i < ops_remove && !pq_stress.Empty(); ++i) 
                    RemoveTip(loctestnum, loctesterr, pq_stress, true);

                for(int i = 0; i < ops_change && pq_stress.Size() > 0; ++i) 
                {
                    ulong current_size = pq_stress.Size();
                    if(current_size == 0)
                        break;
                    
                    if(i % 4 == 0)                         
                        Change(loctestnum, loctesterr, pq_stress, true, 0, -1000); // Heapify down
                    else if(i % 4 == 1) 
                        Change(loctestnum, loctesterr, pq_stress, true, 0, 1000);
                    else if(i % 4 == 2 && current_size > 1) 
                        Change(loctestnum, loctesterr, pq_stress, true, current_size - 1, 1001 + i); // Heapify up
                    else if(current_size > 0) 
                        Change(loctestnum, loctesterr, pq_stress, true, 0, 50 + i);


                    if(!pq_stress.Empty())
                        Tip(loctestnum, loctesterr, pq_stress, true, pq_stress.Tip());
                }
                Change(loctestnum, loctesterr, pq_stress, false, pq_stress.Size() + 5, 0);
            }
            if(!pq_stress.Empty())
                Size(loctestnum, loctesterr, pq_stress, false, 0);

            // 3: Operazioni dopo Clear
            pq_stress.Clear();

            Empty(loctestnum, loctesterr, pq_stress, true);

            for(int i = 0; i < ops_insert / 2; ++i)
                Insert(loctestnum, loctesterr, pq_stress, i*5);
            
            if(!pq_stress.Empty()) 
            {
                for(int i = 0; i < ops_remove / 2 && !pq_stress.Empty(); ++i)
                    RemoveTip(loctestnum, loctesterr, pq_stress, true);

                if(pq_stress.Size() > 0) 
                {
                     Change(loctestnum, loctesterr, pq_stress, true, 0, -500);
                     if(!pq_stress.Empty())
                        Tip(loctestnum, loctesterr, pq_stress, true, pq_stress.Tip());
                }
            }
            
            // 4: Pulizia finale e test
            while(!pq_stress.Empty())
                RemoveTip(loctestnum, loctesterr, pq_stress, true);

            Empty(loctestnum, loctesterr, pq_stress, true);
            Tip(loctestnum, loctesterr, pq_stress, false, 0);
            RemoveTip(loctestnum, loctesterr, pq_stress, false);
            TipNRemove(loctestnum, loctesterr, pq_stress, false, 0);
            Change(loctestnum, loctesterr, pq_stress, false, 0, 100);
            Change(loctestnum, loctesterr, pq_stress, false, 1, 100); 
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MyPQHeap<int> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mypqhp_double(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        cout << endl<< "############################################################################"<< endl;
        cout << endl << "---------------------- Begin of MyPQHeap<double> tests: ----------------------" << endl;

        // PQHeap Default Constructor
        {
            lasd::PQHeap<double> pq;

            Empty(loctestnum, loctesterr, pq, true);
            Size(loctestnum, loctesterr, pq, true, 0);

            Traverse(loctestnum, loctesterr, pq, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<double>);

            Fold(loctestnum, loctesterr, pq, true, &FoldAdd<double>, 0.0, 0.0);
            FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldAdd<double>, 0.0, 0.0);
            FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldAdd<double>, 0.0, 0.0);
            
            Tip(loctestnum, loctesterr, pq, false, 0.0); 
            RemoveTip(loctestnum, loctesterr, pq, false); 
            TipNRemove(loctestnum, loctesterr, pq, false, 0.0); 

            GetFront(loctestnum, loctesterr, pq, false, 0.0); 
            GetBack(loctestnum, loctesterr, pq, false, 0.0);  
            GetAt(loctestnum, loctesterr, pq, false, 0, 0.0); 

            Exists(loctestnum, loctesterr, pq, false, 5.0); 

            Change(loctestnum, loctesterr, pq, false, 0, 100.0); 

            Empty(loctestnum, loctesterr, pq, true); 
            Size(loctestnum, loctesterr, pq, true, 0);
        }

       // PQHeap with 1, 2, 3 elements
        {
            // Size 1
            {
                lasd::PQHeap<double> pq1;
                Insert(loctestnum, loctesterr, pq1, 10.0);

                Traverse(loctestnum, loctesterr, pq1, true, &TraversePrint<double>);
                TraversePreOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<double>);
                TraversePostOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<double>);

                Empty(loctestnum, loctesterr, pq1, false);
                Size(loctestnum, loctesterr, pq1, true, 1);

                Tip(loctestnum, loctesterr, pq1, true, 10.0);
                GetFront(loctestnum, loctesterr, pq1, true, 10.0);
                GetBack(loctestnum, loctesterr, pq1, true, 10.0);
                GetAt(loctestnum, loctesterr, pq1, true, 0, 10.0);

                Exists(loctestnum, loctesterr, pq1, true, 10.0);
                Exists(loctestnum, loctesterr, pq1, false, 5.0);

                Traverse(loctestnum, loctesterr, pq1, true, &TraversePrint<double>);
                TraversePreOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<double>);
                TraversePostOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<double>);
                
                Fold(loctestnum, loctesterr, pq1, true, &FoldAdd<double>, 0.0, 10.0);
                Change(loctestnum, loctesterr, pq1, true, 0, 5.0); 
                Tip(loctestnum, loctesterr, pq1, true, 5.0);
                TipNRemove(loctestnum, loctesterr, pq1, true, 5.0);
                Empty(loctestnum, loctesterr, pq1, true);
            }

            // Size 2
            {
                lasd::PQHeap<double> pq2;
                Insert(loctestnum, loctesterr, pq2, 20.0);
                Insert(loctestnum, loctesterr, pq2, 10.0); 

                Traverse(loctestnum, loctesterr, pq2, true, &TraversePrint<double>);
                TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<double>);
                TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<double>);

                Empty(loctestnum, loctesterr, pq2, false);
                Size(loctestnum, loctesterr, pq2, true, 2);
                Tip(loctestnum, loctesterr, pq2, true, 20.0);

                GetAt(loctestnum, loctesterr, pq2, true, 0, 20.0); 
                Exists(loctestnum, loctesterr, pq2, true, 10.0);
                Change(loctestnum, loctesterr, pq2, true, 1, 30.0);

                Traverse(loctestnum, loctesterr, pq2, true, &TraversePrint<double>);
                TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<double>);
                TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<double>);

                Tip(loctestnum, loctesterr, pq2, true, 30.0);
                Change(loctestnum, loctesterr, pq2, true, 0, 5.0);  

                Traverse(loctestnum, loctesterr, pq2, true, &TraversePrint<double>);
                TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<double>);
                TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<double>);

                Tip(loctestnum, loctesterr, pq2, true, 20.0); 
                RemoveTip(loctestnum, loctesterr, pq2, true); 
                Tip(loctestnum, loctesterr, pq2, true, 5.0);
                RemoveTip(loctestnum, loctesterr, pq2, true);
                Empty(loctestnum, loctesterr, pq2, true);
            }

            // Size 3
            {
                lasd::PQHeap<double> pq3;
                Insert(loctestnum, loctesterr, pq3, 15.0);
                Insert(loctestnum, loctesterr, pq3, 25.0);
                Insert(loctestnum, loctesterr, pq3, 5.0); 

                Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<double>);
                TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<double>);
                TraversePostOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<double>);

                Empty(loctestnum, loctesterr, pq3, false);
                Size(loctestnum, loctesterr, pq3, true, 3);
                Tip(loctestnum, loctesterr, pq3, true, 25.0);
                FoldPostOrder(loctestnum, loctesterr, pq3, true, &FoldAdd<double>, 0.0, 45.0); 

                Change(loctestnum, loctesterr, pq3, true, 1, 30.0);
                Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<double>);
                TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<double>);
                TraversePostOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<double>);
                Tip(loctestnum, loctesterr, pq3, true, 30.0);

                Change(loctestnum, loctesterr, pq3, true, 0, 1.0);
                Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<double>);
                TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<double>);
                TraversePostOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<double>);
                Tip(loctestnum, loctesterr, pq3, true, 25.0);

                TipNRemove(loctestnum, loctesterr, pq3, true, 25.0);
                TipNRemove(loctestnum, loctesterr, pq3, true, 5.0);
                TipNRemove(loctestnum, loctesterr, pq3, true, 1.0);
                Empty(loctestnum, loctesterr, pq3, true);
            }
       }

       // Copy Constructor (from PQHeap)
       {
            // Empty Heap
            lasd::PQHeap<double> pq_orig_empty;
            lasd::PQHeap<double> pq_copy_empty(pq_orig_empty);
            Empty(loctestnum, loctesterr, pq_copy_empty, true);
            Size(loctestnum, loctesterr, pq_copy_empty, true, 0);
            EqualLinear(loctestnum, loctesterr, pq_orig_empty, pq_copy_empty, true);

            // Size 1 Heap
            lasd::PQHeap<double> pq_orig_s1;
            Insert(loctestnum, loctesterr, pq_orig_s1, 100.0);
            lasd::PQHeap<double> pq_copy_s1(pq_orig_s1);
            
            Size(loctestnum, loctesterr, pq_copy_s1, true, 1);
            Tip(loctestnum, loctesterr, pq_copy_s1, true, 100.0);
            EqualLinear(loctestnum, loctesterr, pq_orig_s1, pq_copy_s1, true);
            Insert(loctestnum, loctesterr, pq_orig_s1, 110.0);
            Tip(loctestnum, loctesterr, pq_copy_s1, true, 100.0);
            NonEqualLinear(loctestnum, loctesterr, pq_orig_s1, pq_copy_s1, true);

            // Size 3 Heap
            lasd::PQHeap<double> pq_orig_multi;
            Insert(loctestnum, loctesterr, pq_orig_multi, 50.0);
            Insert(loctestnum, loctesterr, pq_orig_multi, 60.0);
            Insert(loctestnum, loctesterr, pq_orig_multi, 40.0); 
            lasd::PQHeap<double> pq_copy_multi(pq_orig_multi);

            Size(loctestnum, loctesterr, pq_copy_multi, true, 3);
            Tip(loctestnum, loctesterr, pq_copy_multi, true, 60.0);
            EqualLinear(loctestnum, loctesterr, pq_orig_multi, pq_copy_multi, true);
            RemoveTip(loctestnum, loctesterr, pq_orig_multi, true); 
            Tip(loctestnum, loctesterr, pq_copy_multi, true, 60.0);  
            NonEqualLinear(loctestnum, loctesterr, pq_orig_multi, pq_copy_multi, true);
       }

       // Move Constructor (from PQHeap)
       {
            // Empty Heap
            lasd::PQHeap<double> pq_orig_empty_mv;
            lasd::PQHeap<double> pq_mv_empty(move(pq_orig_empty_mv));
            Empty(loctestnum, loctesterr, pq_mv_empty, true);
            Empty(loctestnum, loctesterr, pq_orig_empty_mv, true); 

            // Size 1 Heap
            lasd::PQHeap<double> pq_orig_s1_mv;
            Insert(loctestnum, loctesterr, pq_orig_s1_mv, 200.0);
            lasd::PQHeap<double> pq_orig_s1_mv_compare(pq_orig_s1_mv); 
            lasd::PQHeap<double> pq_mv_s1(move(pq_orig_s1_mv));

            Size(loctestnum, loctesterr, pq_mv_s1, true, 1);
            Tip(loctestnum, loctesterr, pq_mv_s1, true, 200.0);
            Empty(loctestnum, loctesterr, pq_orig_s1_mv, true);
            EqualLinear(loctestnum, loctesterr, pq_mv_s1, pq_orig_s1_mv_compare, true);

            // Size 3 Heap
            lasd::PQHeap<double> pq_orig_multi_mv;
            Insert(loctestnum, loctesterr, pq_orig_multi_mv, 70.0);
            Insert(loctestnum, loctesterr, pq_orig_multi_mv, 80.0);
            Insert(loctestnum, loctesterr, pq_orig_multi_mv, 90.0);
            lasd::PQHeap<double> pq_orig_multi_mv_compare(pq_orig_multi_mv); 
            lasd::PQHeap<double> pq_mv_multi(move(pq_orig_multi_mv));

            Size(loctestnum, loctesterr, pq_mv_multi, true, 3);
            Tip(loctestnum, loctesterr, pq_mv_multi, true, 90.0);
            Empty(loctestnum, loctesterr, pq_orig_multi_mv, true);
            EqualLinear(loctestnum, loctesterr, pq_mv_multi, pq_orig_multi_mv_compare, true);
       }

       // Copy Assignment (from PQHeap)
       {
            lasd::PQHeap<double> pq_assign_src_empty;
            lasd::PQHeap<double> pq_assign_dest_empty;

            // Empty = Empty
            pq_assign_dest_empty = pq_assign_src_empty; 
            Empty(loctestnum, loctesterr, pq_assign_dest_empty, true);

            lasd::PQHeap<double> pq_assign_src1;
            Insert(loctestnum, loctesterr, pq_assign_src1, 10.0);
            Insert(loctestnum, loctesterr, pq_assign_src1, 20.0);

            lasd::PQHeap<double> pq_assign_dest1;

            // Empty = Non-Empty
            pq_assign_dest1 = pq_assign_src1; 
            Size(loctestnum, loctesterr, pq_assign_dest1, true, 2);
            Tip(loctestnum, loctesterr, pq_assign_dest1, true, 20.0);
            EqualLinear(loctestnum, loctesterr, pq_assign_src1, pq_assign_dest1, true);

            lasd::PQHeap<double> pq_assign_dest2;
            Insert(loctestnum, loctesterr, pq_assign_dest2, 5.0);

            // Non-Empty = Empty
            pq_assign_dest2 = pq_assign_src_empty; 
            Empty(loctestnum, loctesterr, pq_assign_dest2, true);

            lasd::PQHeap<double> pq_assign_dest3;
            Insert(loctestnum, loctesterr, pq_assign_dest3, 33.0);
            Insert(loctestnum, loctesterr, pq_assign_dest3, 44.0);

            // Non-Empty = Non-Empty
            pq_assign_dest3 = pq_assign_src1; 
            Size(loctestnum, loctesterr, pq_assign_dest3, true, 2);
            Tip(loctestnum, loctesterr, pq_assign_dest3, true, 20.0);
            EqualLinear(loctestnum, loctesterr, pq_assign_src1, pq_assign_dest3, true);
            Insert(loctestnum, loctesterr, pq_assign_src1, 30.0);
            Tip(loctestnum, loctesterr, pq_assign_dest3, true, 20.0); 
            NonEqualLinear(loctestnum, loctesterr, pq_assign_src1, pq_assign_dest3, true);

            pq_assign_src1 = pq_assign_src1;
            Size(loctestnum, loctesterr, pq_assign_src1, true, 3);
            Tip(loctestnum, loctesterr, pq_assign_src1, true, 30.0);
       }

       // Move Assignment (from PQHeap)
        {
            lasd::PQHeap<double> pq_assign_src_empty_mv;
            lasd::PQHeap<double> pq_assign_dest_empty_mv;

            // Empty = Empty
            pq_assign_dest_empty_mv = move(pq_assign_src_empty_mv);
            Empty(loctestnum, loctesterr, pq_assign_dest_empty_mv, true);
            Empty(loctestnum, loctesterr, pq_assign_src_empty_mv, true);

            lasd::PQHeap<double> pq_assign_src1_mv;
            Insert(loctestnum, loctesterr, pq_assign_src1_mv, 15.0);
            Insert(loctestnum, loctesterr, pq_assign_src1_mv, 25.0); 
            lasd::PQHeap<double> pq_assign_src1_mv_compare(pq_assign_src1_mv);

            lasd::PQHeap<double> pq_assign_dest1_mv;

            // Empty = Non-Empty
            pq_assign_dest1_mv = move(pq_assign_src1_mv);
            Size(loctestnum, loctesterr, pq_assign_dest1_mv, true, 2);
            Tip(loctestnum, loctesterr, pq_assign_dest1_mv, true, 25.0);
            Empty(loctestnum, loctesterr, pq_assign_src1_mv, true);
            EqualLinear(loctestnum, loctesterr, pq_assign_dest1_mv, pq_assign_src1_mv_compare, true);

            lasd::PQHeap<double> pq_assign_dest2_mv;
            Insert(loctestnum, loctesterr, pq_assign_dest2_mv, 8.0);

            // Non-Empty = Empty
            pq_assign_dest2_mv = move(pq_assign_src_empty_mv); 
            Empty(loctestnum, loctesterr, pq_assign_dest2_mv, true);

            lasd::PQHeap<double> pq_assign_src2_mv; 
            Insert(loctestnum, loctesterr, pq_assign_src2_mv, 77.0);
            lasd::PQHeap<double> pq_assign_src2_mv_compare(pq_assign_src2_mv);
            lasd::PQHeap<double> pq_assign_dest3_mv;
            Insert(loctestnum, loctesterr, pq_assign_dest3_mv, 55.0);
            Insert(loctestnum, loctesterr, pq_assign_dest3_mv, 66.0);

            // Non-Empty = Non-Empty
            pq_assign_dest3_mv = move(pq_assign_src2_mv); 
            Size(loctestnum, loctesterr, pq_assign_dest3_mv, true, 1);
            Tip(loctestnum, loctesterr, pq_assign_dest3_mv, true, 77.0);
            Empty(loctestnum, loctesterr, pq_assign_src2_mv, false); 
            EqualLinear(loctestnum, loctesterr, pq_assign_dest3_mv, pq_assign_src2_mv_compare, true);

            // lasd::PQHeap<double> pq_self_assign_mv;
            // Insert(loctestnum, loctesterr, pq_self_assign_mv, 90.0);
            // Insert(loctestnum, loctesterr, pq_self_assign_mv, 95.0);
            // lasd::PQHeap<double> pq_self_assign_mv_compare(pq_self_assign_mv);
            // pq_self_assign_mv = move(pq_self_assign_mv);
            // EqualLinear(loctestnum, loctesterr, pq_self_assign_mv, pq_self_assign_mv_compare, true);
            // Size(loctestnum, loctesterr, pq_self_assign_mv, true, 2);
            // Tip(loctestnum, loctesterr, pq_self_assign_mv, true, 95.0);
        }

        // Copy/Move Constructors from other containers
        {
           
            // From Vector
            {   
                // Copy constructors 

                // Empty Vector
                { 
                    lasd::Vector<double> vec_src_empty(0);
                    lasd::PQHeap<double> pq_copy(vec_src_empty);

                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, vec_src_empty, true); 
                }

                // Vector Size 1
                { 
                    lasd::Vector<double> vec_src_s1(1);
                    SetAt(loctestnum, loctesterr, vec_src_s1, true, 0, 10.0);

                    lasd::PQHeap<double> pq_copy(vec_src_s1);
                    Tip(loctestnum, loctesterr, pq_copy, true, 10.0);
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, vec_src_s1, true, 1); 
                }

                // Vector Size 3
                { 
                    lasd::Vector<double> vec_src_s3(3);
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 0, 5.0);
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 1, 15.0);
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 2, 10.0);

                    lasd::PQHeap<double> pq_copy(vec_src_s3);
                    Tip(loctestnum, loctesterr, pq_copy, true, 15.0);
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, vec_src_s3, true, 3);
                }

                // Move Constructors

                // Empty Vector
                { 
                    
                    lasd::Vector<double> vec_src_empty(0);
                    lasd::PQHeap<double> pq_move(move(vec_src_empty));
                    Empty(loctestnum, loctesterr, pq_move, true);
                    Empty(loctestnum, loctesterr, vec_src_empty, true);
                }

                // Vector Size 1
                {   
                    lasd::Vector<double> vec_src_s1(1);
                    SetAt(loctestnum, loctesterr, vec_src_s1, true, 0, 20.0);
                
                    lasd::PQHeap<double> pq_move(move(vec_src_s1));
                    Tip(loctestnum, loctesterr, pq_move, true, 20.0);
                    Size(loctestnum, loctesterr, pq_move, true, 1);
                    Empty(loctestnum, loctesterr, vec_src_s1, false); 
                }

                // Vector Size 3
                { 
                    lasd::Vector<double> vec_src_s3(3);
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 0, 25.0);
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 1, 35.0);
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 2, 20.0);

                    lasd::PQHeap<double> pq_move(move(vec_src_s3));
                    Tip(loctestnum, loctesterr, pq_move, true, 35.0);
                    Size(loctestnum, loctesterr, pq_move, true, 3);
                    Empty(loctestnum, loctesterr, vec_src_s3, false); 
                }
            }

            // From List
            {
                // Copy Constructor

                // Empty List
                { 
                    lasd::List<double> lst_src_empty;
                    lasd::PQHeap<double> pq_copy(lst_src_empty);
                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, lst_src_empty, true);
                }

                // List Size 1
                { 
                    lasd::List<double> lst_src_s1;
                    InsertAtBack(loctestnum, loctesterr, lst_src_s1, true, 40.0);

                    lasd::PQHeap<double> pq_copy(lst_src_s1);
                    Tip(loctestnum, loctesterr, pq_copy, true, 40.0);
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, lst_src_s1, true, 1);
                }

                // List Size 3
                { 
                    lasd::List<double> lst_src_s3;
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, 45.0);
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, 55.0);
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, 50.0); 

                    lasd::PQHeap<double> pq_copy(lst_src_s3);
                    Tip(loctestnum, loctesterr, pq_copy, true, 55.0);
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, lst_src_s3, true, 3);
                }

                // Move Constructor
                
                // Empty List
                { 
                    lasd::List<double> lst_src_empty;
                    lasd::PQHeap<double> pq_move(move(lst_src_empty));
                    Empty(loctestnum, loctesterr, pq_move, true);
                    Empty(loctestnum, loctesterr, lst_src_empty, true);
                }

                // List Size 1
                { 
                    lasd::List<double> lst_src_s1;
                    InsertAtBack(loctestnum, loctesterr, lst_src_s1, true, 60.0);

                    lasd::PQHeap<double> pq_move(move(lst_src_s1));
                    Tip(loctestnum, loctesterr, pq_move, true, 60.0);
                    Size(loctestnum, loctesterr, pq_move, true, 1);
                    Empty(loctestnum, loctesterr, lst_src_s1, false);
                }

                // List Size 3
                { 
                    lasd::List<double> lst_src_s3;
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, 65.0);
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, 75.0);
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, 70.0);

                    lasd::PQHeap<double> pq_move(move(lst_src_s3));
                    Tip(loctestnum, loctesterr, pq_move, true, 75.0);
                    Size(loctestnum, loctesterr, pq_move, true, 3);
                    Empty(loctestnum, loctesterr, lst_src_s3, false);
                }
            }

            // From SetVec
            {
                // Copy Constructor

                // Empty SetVec
                { 
                    lasd::SetVec<double> set_src_empty;
                    lasd::PQHeap<double> pq_copy(set_src_empty);
                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, set_src_empty, true);
                }

                // SetVec Size 1
                { 
                    lasd::SetVec<double> set_src_s1;
                    InsertC(loctestnum, loctesterr, set_src_s1, true, 80.0);
                    
                    lasd::PQHeap<double> pq_copy(set_src_s1);
                    Tip(loctestnum, loctesterr, pq_copy, true, 80.0);
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, set_src_s1, true, 1);
                }

                // SetVec Size 3
                { 
                    lasd::SetVec<double> set_src_s3;
                    InsertC(loctestnum, loctesterr, set_src_s3, true, 85.0);
                    InsertC(loctestnum, loctesterr, set_src_s3, true, 95.0);
                    InsertC(loctestnum, loctesterr, set_src_s3, true, 90.0);

                    lasd::PQHeap<double> pq_copy(set_src_s3);
                    Tip(loctestnum, loctesterr, pq_copy, true, 95.0);
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, set_src_s3, true, 3);
                }
            }

            // From SetLst
            {
                // Copy Constructor

                // Empty SetLst
                { 
                    lasd::SetLst<double> set_src_empty;
                    lasd::PQHeap<double> pq_copy(set_src_empty);
                    
                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, set_src_empty, true);
                }

                // SetLst Size 1
                { 
                    lasd::SetLst<double> set_src_s1;
                    InsertC(loctestnum, loctesterr, set_src_s1, true, 120.0);
                    lasd::PQHeap<double> pq_copy(set_src_s1);

                    Tip(loctestnum, loctesterr, pq_copy, true, 120.0);
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, set_src_s1, true, 1);
                }

                // SetLst Size 3
                { 
                    lasd::SetLst<double> set_src_s3;
                    InsertC(loctestnum, loctesterr, set_src_s3, true, 125.0);
                    InsertC(loctestnum, loctesterr, set_src_s3, true, 135.0);
                    InsertC(loctestnum, loctesterr, set_src_s3, true, 130.0); 

                    lasd::PQHeap<double> pq_copy(set_src_s3);
                    Tip(loctestnum, loctesterr, pq_copy, true, 135.0);
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, set_src_s3, true, 3);
                }
            }

            // From HeapVec
            {
                // Copy Constructor

                // Empty HeapVec
                { 
                    lasd::HeapVec<double> hp_src_empty;
                    lasd::PQHeap<double> pq_copy(hp_src_empty);

                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, hp_src_empty, true);
                }

                // HeapVec Size 1
                { 
                    lasd::Vector<double> vec_for_hp_s1(1);
                    SetAt(loctestnum, loctesterr, vec_for_hp_s1, true, 0, 160.0);

                    lasd::HeapVec<double> hp_src_s1(vec_for_hp_s1); 
                    lasd::PQHeap<double> pq_copy(hp_src_s1);

                    Tip(loctestnum, loctesterr, pq_copy, true, 160.0);
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, hp_src_s1, true, 1);
                }

                // HeapVec Size 3
                { 
                    lasd::Vector<double> vec_for_hp_s3(3); 
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 0, 165.0);
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 1, 175.0);
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 2, 170.0);
                    lasd::HeapVec<double> hp_src_s3(vec_for_hp_s3); 
                    lasd::PQHeap<double> pq_copy(hp_src_s3);

                    Tip(loctestnum, loctesterr, pq_copy, true, 175.0);
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, hp_src_s3, true, 3);
                }

                // Move Constructor

                // Empty HeapVec
                { 
                    lasd::HeapVec<double> hp_src_empty;
                    lasd::PQHeap<double> pq_move(move(hp_src_empty));

                    Empty(loctestnum, loctesterr, pq_move, true);
                    Empty(loctestnum, loctesterr, hp_src_empty, true);
                }

                // HeapVec Size 1
                { 
                    lasd::Vector<double> vec_for_hp_s1(1);
                    SetAt(loctestnum, loctesterr, vec_for_hp_s1, true, 0, 180.0);    
                    lasd::HeapVec<double> hp_src_s1(vec_for_hp_s1);
                    lasd::PQHeap<double> pq_move(move(hp_src_s1));

                    Tip(loctestnum, loctesterr, pq_move, true, 180.0);
                    Size(loctestnum, loctesterr, pq_move, true, 1);
                    Empty(loctestnum, loctesterr, hp_src_s1, false);
                }

                // HeapVec Size 3
                { 
                    lasd::Vector<double> vec_for_hp_s3(3);
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 0, 185.0);    
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 1, 195.0);    
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 2, 190.0);    
                    lasd::HeapVec<double> hp_src_s3(vec_for_hp_s3);
                    lasd::PQHeap<double> pq_move(move(hp_src_s3));

                    Tip(loctestnum, loctesterr, pq_move, true, 195.0);
                    Size(loctestnum, loctesterr, pq_move, true, 3);
                    Empty(loctestnum, loctesterr, hp_src_s3, false);
                }
            }
        }

        // Comparison Operators
        {
            lasd::PQHeap<double> pq_comp1, pq_comp2, pq_comp3, pq_comp_empty1, pq_comp_empty2;
            Insert(loctestnum, loctesterr, pq_comp1, 10.0); Insert(loctestnum, loctesterr, pq_comp1, 20.0);
            Insert(loctestnum, loctesterr, pq_comp2, 20.0); Insert(loctestnum, loctesterr, pq_comp2, 10.0);
            Insert(loctestnum, loctesterr, pq_comp3, 10.0); Insert(loctestnum, loctesterr, pq_comp3, 30.0);

            EqualLinear(loctestnum, loctesterr, pq_comp1, pq_comp2, true);
            NonEqualLinear(loctestnum, loctesterr, pq_comp1, pq_comp3, true);
            NonEqualLinear(loctestnum, loctesterr, pq_comp1, pq_comp_empty1, true);
            EqualLinear(loctestnum, loctesterr, pq_comp_empty1, pq_comp_empty2, true);
        }

         // Stress Tests
        {
            lasd::PQHeap<double> pq_stress;
            
            const int stress_n = 200;

            // 1.1: Inserimenti sequenziali e rimozioni ordinate
            for(int i = 0; i < stress_n; ++i) 
                Insert(loctestnum, loctesterr, pq_stress, static_cast<double>(i));

            Size(loctestnum, loctesterr, pq_stress, true, stress_n);
            Tip(loctestnum, loctesterr, pq_stress, true, static_cast<double>(stress_n - 1));

            double last_removed = static_cast<double>(stress_n);
            for(int i = 0; i < stress_n; ++i) 
            {
                double current_tip = pq_stress.Tip();
                TipNRemove(loctestnum, loctesterr, pq_stress, true, static_cast<double>(stress_n - 1 - i));
                if(current_tip > last_removed && i > 0) 
                {
                    loctestnum++;
                    loctesterr++;
                    cout << "Errore: Rimozione non in ordine (1.1)." << endl;
                }
                last_removed = current_tip;
            }
            Empty(loctestnum, loctesterr, pq_stress, true);

            // 1.2: Inserimenti con duplicati e rimozioni ordinate
            for(int i = 0; i < stress_n; ++i) 
                Insert(loctestnum, loctesterr, pq_stress, static_cast<double>(i % 10));

            Size(loctestnum, loctesterr, pq_stress, true, stress_n);
            Tip(loctestnum, loctesterr, pq_stress, true, 9.0);

            last_removed = 10.0; 
            for(int i = 0; i < stress_n; ++i) 
            {
                double current_tip = pq_stress.Tip();
                RemoveTip(loctestnum, loctesterr, pq_stress, true);
                if (current_tip > last_removed && i > 0) 
                {
                    loctestnum++;
                    loctesterr++;
                    cout << "Errore: Rimozione non in ordine (1.2)." << endl;
                }
                last_removed = current_tip;
            }
            Empty(loctestnum, loctesterr, pq_stress, true);

            // 2: Cicli di operazioni miste
            const int num_cycles = 5;
            const int ops_insert = 50;
            const int ops_remove = 10;
            const int ops_change = 5;

            for(int cycle = 0; cycle < num_cycles; ++cycle) 
            {
                for(int i = 0; i < ops_insert; ++i) 
                    Insert(loctestnum, loctesterr, pq_stress, static_cast<double>((i * (cycle + 1)) % 100 - 50));

                Empty(loctestnum, loctesterr, pq_stress, false);

                for(int i = 0; i < ops_remove && !pq_stress.Empty(); ++i) 
                    RemoveTip(loctestnum, loctesterr, pq_stress, true);

                for(int i = 0; i < ops_change && pq_stress.Size() > 0; ++i) 
                {
                    ulong current_size = pq_stress.Size();
                    if(current_size == 0)
                        break;
                    
                    if(i % 4 == 0)                         
                        Change(loctestnum, loctesterr, pq_stress, true, 0, -1000.0); // Heapify down
                    else if(i % 4 == 1) 
                        Change(loctestnum, loctesterr, pq_stress, true, 0, 1000.0);
                    else if(i % 4 == 2 && current_size > 1) 
                        Change(loctestnum, loctesterr, pq_stress, true, current_size - 1, static_cast<double>(1001 + i)); // Heapify up
                    else if(current_size > 0) 
                        Change(loctestnum, loctesterr, pq_stress, true, 0, static_cast<double>(50 + i));


                    if(!pq_stress.Empty())
                        Tip(loctestnum, loctesterr, pq_stress, true, pq_stress.Tip());
                }
                Change(loctestnum, loctesterr, pq_stress, false, pq_stress.Size() + 5, 0.0);
            }
            if(!pq_stress.Empty())
                Size(loctestnum, loctesterr, pq_stress, false, 0);

            // 3: Operazioni dopo Clear
            pq_stress.Clear();

            Empty(loctestnum, loctesterr, pq_stress, true);

            for(int i = 0; i < ops_insert / 2; ++i)
                Insert(loctestnum, loctesterr, pq_stress, static_cast<double>(i*5));
            
            if(!pq_stress.Empty()) 
            {
                for(int i = 0; i < ops_remove / 2 && !pq_stress.Empty(); ++i)
                    RemoveTip(loctestnum, loctesterr, pq_stress, true);

                if(pq_stress.Size() > 0) 
                {
                     Change(loctestnum, loctesterr, pq_stress, true, 0, -500.0);
                     if(!pq_stress.Empty())
                        Tip(loctestnum, loctesterr, pq_stress, true, pq_stress.Tip());
                }
            }
            
            // 4: Pulizia finale e test
            while(!pq_stress.Empty())
                RemoveTip(loctestnum, loctesterr, pq_stress, true);

            Empty(loctestnum, loctesterr, pq_stress, true);
            Tip(loctestnum, loctesterr, pq_stress, false, 0.0);
            RemoveTip(loctestnum, loctesterr, pq_stress, false);
            TipNRemove(loctestnum, loctesterr, pq_stress, false, 0.0);
            Change(loctestnum, loctesterr, pq_stress, false, 0, 100.0);
            Change(loctestnum, loctesterr, pq_stress, false, 1, 100.0); 
        }
        
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MyPQHeap<double> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mypqhp_string(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        cout << endl<< "############################################################################"<< endl;
        cout << endl << "---------------------- Begin of MyPQHeap<string> tests: ----------------------" << endl;

        // Empty PQHeap (Default Constructor)
        {
            lasd::PQHeap<string> pq;

            Empty(loctestnum, loctesterr, pq, true);
            Size(loctestnum, loctesterr, pq, true, 0);

            Traverse(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
            TraversePreOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, pq, true, &TraversePrint<string>);

            Fold(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string(""), string(""));
            FoldPreOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string(""), string(""));
            FoldPostOrder(loctestnum, loctesterr, pq, true, &FoldStringConcatenate, string(""), string(""));
            
            Tip(loctestnum, loctesterr, pq, false, string("")); 
            RemoveTip(loctestnum, loctesterr, pq, false); 
            TipNRemove(loctestnum, loctesterr, pq, false, string("")); 

            GetFront(loctestnum, loctesterr, pq, false, string("")); 
            GetBack(loctestnum, loctesterr, pq, false, string(""));  
            GetAt(loctestnum, loctesterr, pq, false, 0, string("")); 

            Exists(loctestnum, loctesterr, pq, false, string("e")); 

            Change(loctestnum, loctesterr, pq, false, 0, string("test")); 

            Empty(loctestnum, loctesterr, pq, true);
            Size(loctestnum, loctesterr, pq, true, 0);
        }

       // PQHeap with 1, 2, 3 elements 
        {
            // Size 1
            {
                lasd::PQHeap<string> pq1;
                Insert(loctestnum, loctesterr, pq1, string("m"));

                Traverse(loctestnum, loctesterr, pq1, true, &TraversePrint<string>);
                TraversePreOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<string>);
                TraversePostOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<string>);

                Empty(loctestnum, loctesterr, pq1, false);
                Size(loctestnum, loctesterr, pq1, true, 1);

                Tip(loctestnum, loctesterr, pq1, true, string("m"));
                GetFront(loctestnum, loctesterr, pq1, true, string("m"));
                GetBack(loctestnum, loctesterr, pq1, true, string("m"));
                GetAt(loctestnum, loctesterr, pq1, true, 0, string("m"));

                Exists(loctestnum, loctesterr, pq1, true, string("m"));
                Exists(loctestnum, loctesterr, pq1, false, string("f"));

                Traverse(loctestnum, loctesterr, pq1, true, &TraversePrint<string>);
                TraversePreOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<string>);
                TraversePostOrder(loctestnum, loctesterr, pq1, true, &TraversePrint<string>);
                
                Fold(loctestnum, loctesterr, pq1, true, &FoldStringConcatenate, string(""), string("m"));
                Change(loctestnum, loctesterr, pq1, true, 0, string("g")); 
                Tip(loctestnum, loctesterr, pq1, true, string("g"));
                TipNRemove(loctestnum, loctesterr, pq1, true, string("g"));
                Empty(loctestnum, loctesterr, pq1, true);
            }

            // Size 2
            {
                lasd::PQHeap<string> pq2;
                Insert(loctestnum, loctesterr, pq2, string("y")); 
                Insert(loctestnum, loctesterr, pq2, string("l")); 

                Traverse(loctestnum, loctesterr, pq2, true, &TraversePrint<string>);
                TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<string>);
                TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<string>);

                Empty(loctestnum, loctesterr, pq2, false);
                Size(loctestnum, loctesterr, pq2, true, 2);
                Tip(loctestnum, loctesterr, pq2, true, string("y"));

                GetAt(loctestnum, loctesterr, pq2, true, 0, string("y")); 
                Exists(loctestnum, loctesterr, pq2, true, string("l"));
                Change(loctestnum, loctesterr, pq2, true, 1, string("z"));

                Traverse(loctestnum, loctesterr, pq2, true, &TraversePrint<string>);
                TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<string>);
                TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<string>);

                Tip(loctestnum, loctesterr, pq2, true, string("z"));
                Change(loctestnum, loctesterr, pq2, true, 0, string("a")); 

                Traverse(loctestnum, loctesterr, pq2, true, &TraversePrint<string>);
                TraversePreOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<string>);
                TraversePostOrder(loctestnum, loctesterr, pq2, true, &TraversePrint<string>);

                Tip(loctestnum, loctesterr, pq2, true, string("y")); 
                RemoveTip(loctestnum, loctesterr, pq2, true); 
                Tip(loctestnum, loctesterr, pq2, true, string("a"));
                RemoveTip(loctestnum, loctesterr, pq2, true);
                Empty(loctestnum, loctesterr, pq2, true);
            }

            // Size 3
            {
                lasd::PQHeap<string> pq3;
                Insert(loctestnum, loctesterr, pq3, string("o"));
                Insert(loctestnum, loctesterr, pq3, string("x")); // Tip
                Insert(loctestnum, loctesterr, pq3, string("f")); 

                Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<string>);
                TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<string>);
                TraversePostOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<string>);

                Empty(loctestnum, loctesterr, pq3, false);
                Size(loctestnum, loctesterr, pq3, true, 3);
                Tip(loctestnum, loctesterr, pq3, true, string("x"));
                
                FoldPostOrder(loctestnum, loctesterr, pq3, true, &FoldStringConcatenate, string(""), string("fox")); 

                Change(loctestnum, loctesterr, pq3, true, 1, string("z")); 
                Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<string>);
                TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<string>);
                TraversePostOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<string>);
                Tip(loctestnum, loctesterr, pq3, true, string("z"));

                Change(loctestnum, loctesterr, pq3, true, 0, string("a"));
                Traverse(loctestnum, loctesterr, pq3, true, &TraversePrint<string>);
                TraversePreOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<string>);
                TraversePostOrder(loctestnum, loctesterr, pq3, true, &TraversePrint<string>);
                Tip(loctestnum, loctesterr, pq3, true, string("x")); 

                TipNRemove(loctestnum, loctesterr, pq3, true, string("x"));
                TipNRemove(loctestnum, loctesterr, pq3, true, string("f"));
                TipNRemove(loctestnum, loctesterr, pq3, true, string("a"));
                Empty(loctestnum, loctesterr, pq3, true);
            }
       }

       // Copy Constructor (from PQHeap)
       {
            // Empty Heap
            lasd::PQHeap<string> pq_orig_empty;
            lasd::PQHeap<string> pq_copy_empty(pq_orig_empty);
            Empty(loctestnum, loctesterr, pq_copy_empty, true);
            Size(loctestnum, loctesterr, pq_copy_empty, true, 0);
            EqualLinear(loctestnum, loctesterr, pq_orig_empty, pq_copy_empty, true);

            // Size 1 Heap
            lasd::PQHeap<string> pq_orig_s1;
            Insert(loctestnum, loctesterr, pq_orig_s1, string("alpha"));
            lasd::PQHeap<string> pq_copy_s1(pq_orig_s1);
            
            Size(loctestnum, loctesterr, pq_copy_s1, true, 1);
            Tip(loctestnum, loctesterr, pq_copy_s1, true, string("alpha"));
            EqualLinear(loctestnum, loctesterr, pq_orig_s1, pq_copy_s1, true);
            Insert(loctestnum, loctesterr, pq_orig_s1, string("beta"));
            Tip(loctestnum, loctesterr, pq_copy_s1, true, string("alpha"));
            NonEqualLinear(loctestnum, loctesterr, pq_orig_s1, pq_copy_s1, true);

            // Size 3 Heap
            lasd::PQHeap<string> pq_orig_multi;
            Insert(loctestnum, loctesterr, pq_orig_multi, string("mid"));
            Insert(loctestnum, loctesterr, pq_orig_multi, string("top")); 
            Insert(loctestnum, loctesterr, pq_orig_multi, string("low")); 
            lasd::PQHeap<string> pq_copy_multi(pq_orig_multi);

            Size(loctestnum, loctesterr, pq_copy_multi, true, 3);
            Tip(loctestnum, loctesterr, pq_copy_multi, true, string("top"));
            EqualLinear(loctestnum, loctesterr, pq_orig_multi, pq_copy_multi, true);
            RemoveTip(loctestnum, loctesterr, pq_orig_multi, true); 
            Tip(loctestnum, loctesterr, pq_copy_multi, true, string("top"));  
            NonEqualLinear(loctestnum, loctesterr, pq_orig_multi, pq_copy_multi, true);
       }

       // Move Constructor (from PQHeap)
       {
            // Empty Heap
            lasd::PQHeap<string> pq_orig_empty_mv;
            lasd::PQHeap<string> pq_mv_empty(move(pq_orig_empty_mv));
            Empty(loctestnum, loctesterr, pq_mv_empty, true);
            Empty(loctestnum, loctesterr, pq_orig_empty_mv, true); 

            // Size 1 Heap
            lasd::PQHeap<string> pq_orig_s1_mv;
            Insert(loctestnum, loctesterr, pq_orig_s1_mv, string("zeta"));
            lasd::PQHeap<string> pq_orig_s1_mv_compare(pq_orig_s1_mv); 
            lasd::PQHeap<string> pq_mv_s1(move(pq_orig_s1_mv));

            Size(loctestnum, loctesterr, pq_mv_s1, true, 1);
            Tip(loctestnum, loctesterr, pq_mv_s1, true, string("zeta"));
            Empty(loctestnum, loctesterr, pq_orig_s1_mv, true);
            EqualLinear(loctestnum, loctesterr, pq_mv_s1, pq_orig_s1_mv_compare, true);

            // Size 3 Heap
            lasd::PQHeap<string> pq_orig_multi_mv;
            Insert(loctestnum, loctesterr, pq_orig_multi_mv, string("gamma"));
            Insert(loctestnum, loctesterr, pq_orig_multi_mv, string("delta"));
            Insert(loctestnum, loctesterr, pq_orig_multi_mv, string("epsilon")); 
            lasd::PQHeap<string> pq_orig_multi_mv_compare(pq_orig_multi_mv); 
            lasd::PQHeap<string> pq_mv_multi(move(pq_orig_multi_mv));

            Size(loctestnum, loctesterr, pq_mv_multi, true, 3);
            Tip(loctestnum, loctesterr, pq_mv_multi, true, string("gamma"));
            Empty(loctestnum, loctesterr, pq_orig_multi_mv, true);
            EqualLinear(loctestnum, loctesterr, pq_mv_multi, pq_orig_multi_mv_compare, true);
       }

       // Copy Assignment (from PQHeap)
       {
            lasd::PQHeap<string> pq_assign_src_empty;
            lasd::PQHeap<string> pq_assign_dest_empty;

            // Empty = Empty
            pq_assign_dest_empty = pq_assign_src_empty; 
            Empty(loctestnum, loctesterr, pq_assign_dest_empty, true);

            lasd::PQHeap<string> pq_assign_src1;
            Insert(loctestnum, loctesterr, pq_assign_src1, string("apple"));
            Insert(loctestnum, loctesterr, pq_assign_src1, string("banana")); 

            lasd::PQHeap<string> pq_assign_dest1;

            // Empty = Non-Empty
            pq_assign_dest1 = pq_assign_src1; 
            Size(loctestnum, loctesterr, pq_assign_dest1, true, 2);
            Tip(loctestnum, loctesterr, pq_assign_dest1, true, string("banana"));
            EqualLinear(loctestnum, loctesterr, pq_assign_src1, pq_assign_dest1, true);

            lasd::PQHeap<string> pq_assign_dest2;
            Insert(loctestnum, loctesterr, pq_assign_dest2, string("fig"));

            // Non-Empty = Empty
            pq_assign_dest2 = pq_assign_src_empty; 
            Empty(loctestnum, loctesterr, pq_assign_dest2, true);

            lasd::PQHeap<string> pq_assign_dest3;
            Insert(loctestnum, loctesterr, pq_assign_dest3, string("cat"));
            Insert(loctestnum, loctesterr, pq_assign_dest3, string("dog")); 

            // Non-Empty = Non-Empty
            pq_assign_dest3 = pq_assign_src1; 
            Size(loctestnum, loctesterr, pq_assign_dest3, true, 2);
            Tip(loctestnum, loctesterr, pq_assign_dest3, true, string("banana"));
            EqualLinear(loctestnum, loctesterr, pq_assign_src1, pq_assign_dest3, true);
            Insert(loctestnum, loctesterr, pq_assign_src1, string("cherry")); 
            Tip(loctestnum, loctesterr, pq_assign_dest3, true, string("banana")); 
            NonEqualLinear(loctestnum, loctesterr, pq_assign_src1, pq_assign_dest3, true);

            pq_assign_src1 = pq_assign_src1;
            Size(loctestnum, loctesterr, pq_assign_src1, true, 3);
            Tip(loctestnum, loctesterr, pq_assign_src1, true, string("cherry"));
       }

       // Move Assignment (from PQHeap)
        {
            lasd::PQHeap<string> pq_assign_src_empty_mv;
            lasd::PQHeap<string> pq_assign_dest_empty_mv;

            // Empty = Empty
            pq_assign_dest_empty_mv = move(pq_assign_src_empty_mv);
            Empty(loctestnum, loctesterr, pq_assign_dest_empty_mv, true);
            Empty(loctestnum, loctesterr, pq_assign_src_empty_mv, true);

            lasd::PQHeap<string> pq_assign_src1_mv;
            Insert(loctestnum, loctesterr, pq_assign_src1_mv, string("grape"));
            Insert(loctestnum, loctesterr, pq_assign_src1_mv, string("kiwi")); 
            lasd::PQHeap<string> pq_assign_src1_mv_compare(pq_assign_src1_mv);

            lasd::PQHeap<string> pq_assign_dest1_mv;

            // Empty = Non-Empty
            pq_assign_dest1_mv = move(pq_assign_src1_mv);
            Size(loctestnum, loctesterr, pq_assign_dest1_mv, true, 2);
            Tip(loctestnum, loctesterr, pq_assign_dest1_mv, true, string("kiwi"));
            Empty(loctestnum, loctesterr, pq_assign_src1_mv, true);
            EqualLinear(loctestnum, loctesterr, pq_assign_dest1_mv, pq_assign_src1_mv_compare, true);

            lasd::PQHeap<string> pq_assign_dest2_mv;
            Insert(loctestnum, loctesterr, pq_assign_dest2_mv, string("plum"));

            // Non-Empty = Empty
            pq_assign_dest2_mv = move(pq_assign_src_empty_mv); 
            Empty(loctestnum, loctesterr, pq_assign_dest2_mv, true);

            lasd::PQHeap<string> pq_assign_src2_mv; 
            Insert(loctestnum, loctesterr, pq_assign_src2_mv, string("pear"));
            lasd::PQHeap<string> pq_assign_src2_mv_compare(pq_assign_src2_mv);
            lasd::PQHeap<string> pq_assign_dest3_mv;
            Insert(loctestnum, loctesterr, pq_assign_dest3_mv, string("lime"));
            Insert(loctestnum, loctesterr, pq_assign_dest3_mv, string("lemon")); 

            // Non-Empty = Non-Empty
            pq_assign_dest3_mv = move(pq_assign_src2_mv); 
            Size(loctestnum, loctesterr, pq_assign_dest3_mv, true, 1);
            Tip(loctestnum, loctesterr, pq_assign_dest3_mv, true, string("pear"));
            Empty(loctestnum, loctesterr, pq_assign_src2_mv, false);
            EqualLinear(loctestnum, loctesterr, pq_assign_dest3_mv, pq_assign_src2_mv_compare, true);
        }

        // Copy/Move Constructors from other containers
        {
           
            // From Vector
            {   
                // Copy constructors 

                // Empty Vector
                { 
                    lasd::Vector<string> vec_src_empty(0);
                    lasd::PQHeap<string> pq_copy(vec_src_empty);

                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, vec_src_empty, true); 
                }

                // Vector Size 1
                { 
                    lasd::Vector<string> vec_src_s1(1);
                    SetAt(loctestnum, loctesterr, vec_src_s1, true, 0, string("vec_one"));

                    lasd::PQHeap<string> pq_copy(vec_src_s1);
                    Tip(loctestnum, loctesterr, pq_copy, true, string("vec_one"));
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, vec_src_s1, true, 1); 
                }

                // Vector Size 3
                { 
                    lasd::Vector<string> vec_src_s3(3);
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 0, string("vec_b"));
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 1, string("vec_c")); 
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 2, string("vec_a"));

                    lasd::PQHeap<string> pq_copy(vec_src_s3);
                    Tip(loctestnum, loctesterr, pq_copy, true, string("vec_c"));
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, vec_src_s3, true, 3);
                }

                // Move Constructors

                // Empty Vector
                { 
                    
                    lasd::Vector<string> vec_src_empty(0);
                    lasd::PQHeap<string> pq_move(move(vec_src_empty));
                    Empty(loctestnum, loctesterr, pq_move, true);
                    Empty(loctestnum, loctesterr, vec_src_empty, true);
                }

                // Vector Size 1
                {   
                    lasd::Vector<string> vec_src_s1(1);
                    SetAt(loctestnum, loctesterr, vec_src_s1, true, 0, string("move_vec_one"));
                
                    lasd::PQHeap<string> pq_move(move(vec_src_s1));
                    Tip(loctestnum, loctesterr, pq_move, true, string("move_vec_one"));
                    Size(loctestnum, loctesterr, pq_move, true, 1);
                    Empty(loctestnum, loctesterr, vec_src_s1, false); 
                }

                // Vector Size 3
                { 
                    lasd::Vector<string> vec_src_s3(3);
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 0, string("move_vec_y"));
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 1, string("move_vec_z")); 
                    SetAt(loctestnum, loctesterr, vec_src_s3, true, 2, string("move_vec_x"));

                    lasd::PQHeap<string> pq_move(move(vec_src_s3));
                    Tip(loctestnum, loctesterr, pq_move, true, string("move_vec_z"));
                    Size(loctestnum, loctesterr, pq_move, true, 3);
                    Empty(loctestnum, loctesterr, vec_src_s3, false); 
                }
            }

            // From List
            {
                // Copy Constructor

                // Empty List
                { 
                    lasd::List<string> lst_src_empty;
                    lasd::PQHeap<string> pq_copy(lst_src_empty);
                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, lst_src_empty, true);
                }

                // List Size 1
                { 
                    lasd::List<string> lst_src_s1;
                    InsertAtBack(loctestnum, loctesterr, lst_src_s1, true, string("list_one"));

                    lasd::PQHeap<string> pq_copy(lst_src_s1);
                    Tip(loctestnum, loctesterr, pq_copy, true, string("list_one"));
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, lst_src_s1, true, 1);
                }

                // List Size 3
                { 
                    lasd::List<string> lst_src_s3;
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, string("list_b"));
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, string("list_c")); 
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, string("list_a")); 

                    lasd::PQHeap<string> pq_copy(lst_src_s3);
                    Tip(loctestnum, loctesterr, pq_copy, true, string("list_c"));
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, lst_src_s3, true, 3);
                }

                // Move Constructor
                
                // Empty List
                { 
                    lasd::List<string> lst_src_empty;
                    lasd::PQHeap<string> pq_move(move(lst_src_empty));
                    Empty(loctestnum, loctesterr, pq_move, true);
                    Empty(loctestnum, loctesterr, lst_src_empty, true);
                }

                // List Size 1
                { 
                    lasd::List<string> lst_src_s1;
                    InsertAtBack(loctestnum, loctesterr, lst_src_s1, true, string("move_list_one"));

                    lasd::PQHeap<string> pq_move(move(lst_src_s1));
                    Tip(loctestnum, loctesterr, pq_move, true, string("move_list_one"));
                    Size(loctestnum, loctesterr, pq_move, true, 1);
                    Empty(loctestnum, loctesterr, lst_src_s1, false);
                }

                // List Size 3
                { 
                    lasd::List<string> lst_src_s3;
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, string("move_list_y"));
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, string("move_list_z")); 
                    InsertAtBack(loctestnum, loctesterr, lst_src_s3, true, string("move_list_x"));

                    lasd::PQHeap<string> pq_move(move(lst_src_s3));
                    Tip(loctestnum, loctesterr, pq_move, true, string("move_list_z"));
                    Size(loctestnum, loctesterr, pq_move, true, 3);
                    Empty(loctestnum, loctesterr, lst_src_s3, false);
                }
            }

            // From SetVec
            {
                // Copy Constructor

                // Empty SetVec
                { 
                    lasd::SetVec<string> set_src_empty;
                    lasd::PQHeap<string> pq_copy(set_src_empty);
                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, set_src_empty, true);
                }

                // SetVec Size 1
                { 
                    lasd::SetVec<string> set_src_s1;
                    InsertC(loctestnum, loctesterr, set_src_s1, true, string("setvec_one"));
                    
                    lasd::PQHeap<string> pq_copy(set_src_s1);
                    Tip(loctestnum, loctesterr, pq_copy, true, string("setvec_one"));
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, set_src_s1, true, 1);
                }

                // SetVec Size 3
                { 
                    lasd::SetVec<string> set_src_s3;
                    InsertC(loctestnum, loctesterr, set_src_s3, true, string("setvec_b"));
                    InsertC(loctestnum, loctesterr, set_src_s3, true, string("setvec_c")); 
                    InsertC(loctestnum, loctesterr, set_src_s3, true, string("setvec_a"));

                    lasd::PQHeap<string> pq_copy(set_src_s3);
                    Tip(loctestnum, loctesterr, pq_copy, true, string("setvec_c"));
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, set_src_s3, true, 3);
                }
            }

            // From SetLst
            {
                // Copy Constructor

                // Empty SetLst
                { 
                    lasd::SetLst<string> set_src_empty;
                    lasd::PQHeap<string> pq_copy(set_src_empty);
                    
                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, set_src_empty, true);
                }

                // SetLst Size 1
                { 
                    lasd::SetLst<string> set_src_s1;
                    InsertC(loctestnum, loctesterr, set_src_s1, true, string("setlst_one"));
                    lasd::PQHeap<string> pq_copy(set_src_s1);

                    Tip(loctestnum, loctesterr, pq_copy, true, string("setlst_one"));
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, set_src_s1, true, 1);
                }

                // SetLst Size 3
                { 
                    lasd::SetLst<string> set_src_s3;
                    InsertC(loctestnum, loctesterr, set_src_s3, true, string("setlst_b"));
                    InsertC(loctestnum, loctesterr, set_src_s3, true, string("setlst_c"));
                    InsertC(loctestnum, loctesterr, set_src_s3, true, string("setlst_a")); 

                    lasd::PQHeap<string> pq_copy(set_src_s3);
                    Tip(loctestnum, loctesterr, pq_copy, true, string("setlst_c"));
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, set_src_s3, true, 3);
                }
            }

            // From HeapVec
            {
                // Copy Constructor

                // Empty HeapVec
                { 
                    lasd::HeapVec<string> hp_src_empty;
                    lasd::PQHeap<string> pq_copy(hp_src_empty);

                    Empty(loctestnum, loctesterr, pq_copy, true);
                    Empty(loctestnum, loctesterr, hp_src_empty, true);
                }

                // HeapVec Size 1
                { 
                    lasd::Vector<string> vec_for_hp_s1(1);
                    SetAt(loctestnum, loctesterr, vec_for_hp_s1, true, 0, string("heapvec_one"));

                    lasd::HeapVec<string> hp_src_s1(vec_for_hp_s1); 
                    lasd::PQHeap<string> pq_copy(hp_src_s1);

                    Tip(loctestnum, loctesterr, pq_copy, true, string("heapvec_one"));
                    Size(loctestnum, loctesterr, pq_copy, true, 1);
                    Size(loctestnum, loctesterr, hp_src_s1, true, 1);
                }

                // HeapVec Size 3
                { 
                    lasd::Vector<string> vec_for_hp_s3(3); 
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 0, string("heapvec_b"));
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 1, string("heapvec_c")); 
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 2, string("heapvec_a"));
                    lasd::HeapVec<string> hp_src_s3(vec_for_hp_s3); 
                    lasd::PQHeap<string> pq_copy(hp_src_s3);

                    Tip(loctestnum, loctesterr, pq_copy, true, string("heapvec_c"));
                    Size(loctestnum, loctesterr, pq_copy, true, 3);
                    Size(loctestnum, loctesterr, hp_src_s3, true, 3);
                }

                // Move Constructor

                // Empty HeapVec
                { 
                    lasd::HeapVec<string> hp_src_empty;
                    lasd::PQHeap<string> pq_move(move(hp_src_empty));

                    Empty(loctestnum, loctesterr, pq_move, true);
                    Empty(loctestnum, loctesterr, hp_src_empty, true);
                }

                // HeapVec Size 1
                { 
                    lasd::Vector<string> vec_for_hp_s1(1);
                    SetAt(loctestnum, loctesterr, vec_for_hp_s1, true, 0, string("move_hp_one"));    
                    lasd::HeapVec<string> hp_src_s1(vec_for_hp_s1);
                    lasd::PQHeap<string> pq_move(move(hp_src_s1));

                    Tip(loctestnum, loctesterr, pq_move, true, string("move_hp_one"));
                    Size(loctestnum, loctesterr, pq_move, true, 1);
                    Empty(loctestnum, loctesterr, hp_src_s1, false);
                }

                // HeapVec Size 3
                { 
                    lasd::Vector<string> vec_for_hp_s3(3);
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 0, string("move_hp_y"));    
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 1, string("move_hp_z"));  
                    SetAt(loctestnum, loctesterr, vec_for_hp_s3, true, 2, string("move_hp_x"));    
                    lasd::HeapVec<string> hp_src_s3(vec_for_hp_s3);
                    lasd::PQHeap<string> pq_move(move(hp_src_s3));

                    Tip(loctestnum, loctesterr, pq_move, true, string("move_hp_z"));
                    Size(loctestnum, loctesterr, pq_move, true, 3);
                    Empty(loctestnum, loctesterr, hp_src_s3, false);
                }
            }
        }

        // Comparison Operators
        {
            lasd::PQHeap<string> pq_comp1, pq_comp2, pq_comp3, pq_comp_empty1, pq_comp_empty2;
            Insert(loctestnum, loctesterr, pq_comp1, string("k")); Insert(loctestnum, loctesterr, pq_comp1, string("t"));
            Insert(loctestnum, loctesterr, pq_comp2, string("t")); Insert(loctestnum, loctesterr, pq_comp2, string("k"));
            Insert(loctestnum, loctesterr, pq_comp3, string("k")); Insert(loctestnum, loctesterr, pq_comp3, string("w"));

            EqualLinear(loctestnum, loctesterr, pq_comp1, pq_comp2, true);
            NonEqualLinear(loctestnum, loctesterr, pq_comp1, pq_comp3, true);
            NonEqualLinear(loctestnum, loctesterr, pq_comp1, pq_comp_empty1, true);
            EqualLinear(loctestnum, loctesterr, pq_comp_empty1, pq_comp_empty2, true);
        }

        // Stress Tests
        {
            lasd::PQHeap<string> pq_stress;
            
            const int stress_n = 200;
            string base_str = "s";

            // 1.1: Inserimenti sequenziali e rimozioni ordinate
            for(int i = 0; i < stress_n; ++i) 
                Insert(loctestnum, loctesterr, pq_stress, base_str + to_string(i));

            Size(loctestnum, loctesterr, pq_stress, true, stress_n);
            
            pq_stress = lasd::PQHeap<string>();
            for(int i = 0; i < stress_n; ++i)
            {
                string temp = "s";
                if (i < 10) 
                    temp += "00";
                else if (i < 100)
                    temp += "0";
                temp += to_string(i);
                Insert(loctestnum, loctesterr, pq_stress, temp);
            }

            string expected_tip_1_1 = "s";
            if (stress_n - 1 < 10)
                expected_tip_1_1 += "00";
            else if (stress_n - 1 < 100)
                expected_tip_1_1 += "0";
            expected_tip_1_1 += to_string(stress_n-1);
            Tip(loctestnum, loctesterr, pq_stress, true, expected_tip_1_1);


            string last_removed = "s" + to_string(stress_n); 
            for(int i = 0; i < stress_n; ++i) 
            {
                string current_tip = pq_stress.Tip();
                string expected_current_tip = "s";

                if(stress_n - 1 - i < 10)
                    expected_current_tip += "00";
                else if(stress_n - 1 - i < 100)
                    expected_current_tip += "0";

                expected_current_tip += to_string(stress_n - 1 - i);
                TipNRemove(loctestnum, loctesterr, pq_stress, true, expected_current_tip);
                if(current_tip > last_removed && i > 0) 
                {
                    loctestnum++;
                    loctesterr++;
                    cout << "Errore: Rimozione non in ordine (1.1)." << endl;
                }
                last_removed = current_tip;
            }
            Empty(loctestnum, loctesterr, pq_stress, true);

            // 1.2: Inserimenti con duplicati e rimozioni ordinate
            for(int i = 0; i < stress_n; ++i) 
                Insert(loctestnum, loctesterr, pq_stress, base_str + to_string(i % 10)); 

            Size(loctestnum, loctesterr, pq_stress, true, stress_n);
            Tip(loctestnum, loctesterr, pq_stress, true, string("s9"));

            last_removed = string("sA");
            for(int i = 0; i < stress_n; ++i) 
            {
                string current_tip = pq_stress.Tip();
                RemoveTip(loctestnum, loctesterr, pq_stress, true);
                if (current_tip > last_removed && i > 0) 
                {
                    loctestnum++;
                    loctesterr++;
                    cout << "Errore: Rimozione non in ordine (1.2)." << endl;
                }
                last_removed = current_tip;
            }
            Empty(loctestnum, loctesterr, pq_stress, true);

            // 2: Cicli di operazioni miste
            const int num_cycles = 5;
            const int ops_insert = 50;
            const int ops_remove = 10;
            const int ops_change = 5;

            for(int cycle = 0; cycle < num_cycles; ++cycle) 
            {
                for(int i = 0; i < ops_insert; ++i) 
                    Insert(loctestnum, loctesterr, pq_stress, base_str + to_string((i * (cycle + 1)) % 100 - 50));

                Empty(loctestnum, loctesterr, pq_stress, false);

                for(int i = 0; i < ops_remove && !pq_stress.Empty(); ++i) 
                    RemoveTip(loctestnum, loctesterr, pq_stress, true);

                for(int i = 0; i < ops_change && pq_stress.Size() > 0; ++i) 
                {
                    ulong current_size = pq_stress.Size();
                    if(current_size == 0)
                        break;
                    
                    if(i % 4 == 0)                         
                        Change(loctestnum, loctesterr, pq_stress, true, 0, string("aaa_low_val")); 
                    else if(i % 4 == 1) 
                        Change(loctestnum, loctesterr, pq_stress, true, 0, string("zzz_high_val"));
                    else if(i % 4 == 2 && current_size > 1) 
                        Change(loctestnum, loctesterr, pq_stress, true, current_size - 1, string("zzz_very_high_") + to_string(i)); 
                    else if(current_size > 0) 
                        Change(loctestnum, loctesterr, pq_stress, true, 0, string("mid_val_") + to_string(i));


                    if(!pq_stress.Empty())
                        Tip(loctestnum, loctesterr, pq_stress, true, pq_stress.Tip());
                }
                Change(loctestnum, loctesterr, pq_stress, false, pq_stress.Size() + 5, string(""));
            }
            if(!pq_stress.Empty())
                Size(loctestnum, loctesterr, pq_stress, false, 0);

            // 3: Operazioni dopo Clear
            pq_stress.Clear();

            Empty(loctestnum, loctesterr, pq_stress, true);

            for(int i = 0; i < ops_insert / 2; ++i)
                Insert(loctestnum, loctesterr, pq_stress, base_str + to_string(i*5));
            
            if(!pq_stress.Empty()) 
            {
                for(int i = 0; i < ops_remove / 2 && !pq_stress.Empty(); ++i)
                    RemoveTip(loctestnum, loctesterr, pq_stress, true);

                if(pq_stress.Size() > 0) 
                {
                     Change(loctestnum, loctesterr, pq_stress, true, 0, string("aaa_very_low"));
                     if(!pq_stress.Empty())
                        Tip(loctestnum, loctesterr, pq_stress, true, pq_stress.Tip());
                }
            }
            
            // 4: Pulizia finale e test
            while(!pq_stress.Empty())
                RemoveTip(loctestnum, loctesterr, pq_stress, true);

            Empty(loctestnum, loctesterr, pq_stress, true);
            Tip(loctestnum, loctesterr, pq_stress, false, string(""));
            RemoveTip(loctestnum, loctesterr, pq_stress, false);
            TipNRemove(loctestnum, loctesterr, pq_stress, false, string(""));
            Change(loctestnum, loctesterr, pq_stress, false, 0, string("test1"));
            Change(loctestnum, loctesterr, pq_stress, false, 1, string("test2")); 
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MyPQHeap<string> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

/* ************************************************************************** */

void pqhp_test(uint &testnum, uint &testerr)
{
    mypqhp_int(testnum, testerr);
    mypqhp_double(testnum, testerr);
    mypqhp_string(testnum, testerr);
}