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

void myhpvec_int(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        cout << endl<< "############################################################################"<< endl;
        cout << endl << "---------------------- Begin of MyHeapVec<int> tests: ----------------------" << endl;
        
        // EmptyHeapVecDefaultConstructor
        {
            lasd::HeapVec<int> hpvec;

            Empty(loctestnum, loctesterr, hpvec, true);
            Size(loctestnum, loctesterr, hpvec, true, 0);

            IsHeap(loctestnum, loctesterr, hpvec, true);
            hpvec.Heapify();
            IsHeap(loctestnum, loctesterr, hpvec, true);

            GetFront(loctestnum, loctesterr, hpvec, false, 0);
            GetBack(loctestnum, loctesterr, hpvec, false, 0);
            GetAt(loctestnum, loctesterr, hpvec, false, 0, 0);
            SetAt(loctestnum, loctesterr, hpvec, false, 0, 0);

            Exists(loctestnum, loctesterr, hpvec, false, 0);

            Traverse(loctestnum, loctesterr, hpvec, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, hpvec, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, hpvec, true, &TraversePrint<int>);
            Fold(loctestnum, loctesterr, hpvec, true, &FoldMultiply<int>, 1, 1);
            FoldPreOrder(loctestnum, loctesterr, hpvec, true, &FoldMultiply<int>, 1, 1);
            FoldPostOrder(loctestnum, loctesterr, hpvec, true, &FoldMultiply<int>, 1, 1);

            Fold(loctestnum, loctesterr, hpvec, true, &FoldMultiply<int>, 0, 0);
            FoldPreOrder(loctestnum, loctesterr, hpvec, true, &FoldMultiply<int>, 0, 0);
            FoldPostOrder(loctestnum, loctesterr, hpvec, true, &FoldMultiply<int>, 0, 0);

            Map(loctestnum, loctesterr, hpvec, true, &MapIncrement<int>);
            MapPreOrder(loctestnum, loctesterr, hpvec, true, &MapIncrement<int>);
            MapPostOrder(loctestnum, loctesterr, hpvec, true, &MapIncrement<int>);

            hpvec.Sort();
            IsHeap(loctestnum, loctesterr, hpvec, true);
            Empty(loctestnum, loctesterr, hpvec, true);
            Size(loctestnum, loctesterr, hpvec, true, 0);

            hpvec.Clear();
            Empty(loctestnum, loctesterr, hpvec, true);
        }
        // ConstructorWithSize(from Vec)
        {
            // SIZE 0 
            lasd::SortableVector<int> emptyvec(0);
            lasd::HeapVec<int> emptyhp(emptyvec);

            Empty(loctestnum, loctesterr, emptyhp, true);
            Size(loctestnum, loctesterr, emptyhp, true, 0);

            IsHeap(loctestnum, loctesterr, emptyhp, true);
            emptyhp.Heapify();
            IsHeap(loctestnum, loctesterr, emptyhp, true);

            GetFront(loctestnum, loctesterr, emptyhp, false, 0);
            GetBack(loctestnum, loctesterr, emptyhp, false, 0);
            GetAt(loctestnum, loctesterr, emptyhp, false, 0, 0);
            SetAt(loctestnum, loctesterr, emptyhp, false, 0, 0);

            Exists(loctestnum, loctesterr, emptyhp, false, 0);

            Traverse(loctestnum, loctesterr, emptyhp, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, emptyhp, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, emptyhp, true, &TraversePrint<int>);

            Fold(loctestnum, loctesterr, emptyhp, true, &FoldMultiply<int>, 0, 0);
            FoldPreOrder(loctestnum, loctesterr, emptyhp, true, &FoldMultiply<int>, 0, 0);
            FoldPostOrder(loctestnum, loctesterr, emptyhp, true, &FoldMultiply<int>, 0, 0);

            Map(loctestnum, loctesterr, emptyhp, true, &MapIncrement<int>);
            MapPreOrder(loctestnum, loctesterr, emptyhp, true, &MapIncrement<int>);
            MapPostOrder(loctestnum, loctesterr, emptyhp, true, &MapIncrement<int>);

            emptyhp.Sort();
            Empty(loctestnum, loctesterr, emptyhp, true);
            Size(loctestnum, loctesterr, emptyhp, true, 0);

            emptyhp.Clear();
            Empty(loctestnum, loctesterr, emptyhp, true);

            // SIZE 1
            lasd::SortableVector<int> singlevec(1);
            SetAt(loctestnum, loctesterr, singlevec, true, 0, 7);
            lasd::HeapVec<int> singlehp(singlevec);

            Empty(loctestnum, loctesterr, singlehp, false);
            Size(loctestnum, loctesterr, singlehp, true, 1);

            IsHeap(loctestnum, loctesterr, singlehp, true);
            singlehp.Heapify();
            IsHeap(loctestnum, loctesterr, singlehp, true);

            GetFront(loctestnum, loctesterr, singlehp, true, 7);
            GetBack(loctestnum, loctesterr, singlehp, true, 7);
            GetAt(loctestnum, loctesterr, singlehp, true, 0, 7);
            GetAt(loctestnum, loctesterr, singlehp, false, 1, 7);
            SetAt(loctestnum, loctesterr, singlehp, true, 0, 10);

            Exists(loctestnum, loctesterr, singlehp, false, 0);
            Exists(loctestnum, loctesterr, singlehp, true, 10);

            Traverse(loctestnum, loctesterr, singlehp, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, singlehp, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, singlehp, true, &TraversePrint<int>);

            Fold(loctestnum, loctesterr, singlehp, true, &FoldMultiply<int>, 1, 10);
            FoldPreOrder(loctestnum, loctesterr, singlehp, true, &FoldMultiply<int>, 1, 10);
            FoldPostOrder(loctestnum, loctesterr, singlehp, true, &FoldMultiply<int>, 1, 10);

            Map(loctestnum, loctesterr, singlehp, true, &MapIncrement<int>);
            MapPreOrder(loctestnum, loctesterr, singlehp, true, &MapIncrement<int>);
            MapPostOrder(loctestnum, loctesterr, singlehp, true, &MapIncrement<int>);

            singlehp.Sort();
            Empty(loctestnum, loctesterr, singlehp, false);
            Size(loctestnum, loctesterr, singlehp, true, 1);
            IsHeap(loctestnum, loctesterr, singlehp, true);

            singlehp.Clear();
            Empty(loctestnum, loctesterr, singlehp, true);
            Size(loctestnum, loctesterr, singlehp, true, 0);
            IsHeap(loctestnum, loctesterr, singlehp, true);

            // SIZE 3
            lasd::SortableVector<int> multivec(3);
            SetAt(loctestnum, loctesterr, multivec, true, 0, 7);
            SetAt(loctestnum, loctesterr, multivec, true, 1, 8);
            SetAt(loctestnum, loctesterr, multivec, true, 2, 9);
            lasd::HeapVec<int> multihp(multivec);

            Empty(loctestnum, loctesterr, multihp, false);
            Size(loctestnum, loctesterr, multihp, true, 3);

            IsHeap(loctestnum, loctesterr, multihp, true);
            multihp.Heapify();
            IsHeap(loctestnum, loctesterr, multihp, true);

            GetFront(loctestnum, loctesterr, multihp, true, 9);
            GetBack(loctestnum, loctesterr, multihp, true, 7);
            GetAt(loctestnum, loctesterr, multihp, true, 0, 9);
            GetAt(loctestnum, loctesterr, multihp, true, 2, 7);
            GetAt(loctestnum, loctesterr, singlehp, false, 3, 7);
            SetAt(loctestnum, loctesterr, multihp, true, 0, 10);

            Exists(loctestnum, loctesterr, multihp, false, 0);
            Exists(loctestnum, loctesterr, multihp, true, 10);

            Traverse(loctestnum, loctesterr, multihp, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, multihp, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, multihp, true, &TraversePrint<int>);

            Fold(loctestnum, loctesterr, multihp, true, &FoldMultiply<int>, 1, 560);
            FoldPreOrder(loctestnum, loctesterr, multihp, true, &FoldMultiply<int>, 1, 560);
            FoldPostOrder(loctestnum, loctesterr, multihp, true, &FoldMultiply<int>, 1, 560);

            Map(loctestnum, loctesterr, multihp, true, &MapIncrement<int>);
            MapPreOrder(loctestnum, loctesterr, multihp, true, &MapIncrement<int>);
            MapPostOrder(loctestnum, loctesterr, multihp, true, &MapIncrement<int>);

            multihp.Sort();
            Traverse(loctestnum, loctesterr, multihp, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, multihp, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, multihp, true, &TraversePrint<int>);

            Empty(loctestnum, loctesterr, multihp, false);
            Size(loctestnum, loctesterr, multihp, true, 3);
            IsHeap(loctestnum, loctesterr, multihp, false);

            multihp.Heapify();
            Traverse(loctestnum, loctesterr, multihp, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, multihp, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, multihp, true, &TraversePrint<int>);
            IsHeap(loctestnum, loctesterr, multihp, true);

            multihp.Clear();
            Empty(loctestnum, loctesterr, multihp, true);
            Size(loctestnum, loctesterr, multihp, true, 0);
            IsHeap(loctestnum, loctesterr, multihp, true);
        }
        // Copy Constructor
        {
            // HeapVec empty
            lasd::SortableVector<int> vec_empty_src(0);
            lasd::HeapVec<int> h_empty_src(vec_empty_src); 
            lasd::HeapVec<int> h_copy_empty(h_empty_src);
            Empty(loctestnum, loctesterr, h_copy_empty, true);
            Size(loctestnum, loctesterr, h_copy_empty, true, 0);
            IsHeap(loctestnum, loctesterr, h_copy_empty, true); 
            EqualLinear(loctestnum, loctesterr, h_empty_src, h_copy_empty, true);

            // HeapVec size 1
            lasd::SortableVector<int> vec_single_src(1);
            SetAt(loctestnum, loctesterr, vec_single_src, true, 0, 10);
            lasd::HeapVec<int> h_single_src(vec_single_src); 
            lasd::HeapVec<int> h_copy_single(h_single_src);
            Size(loctestnum, loctesterr, h_copy_single, true, 1);
            IsHeap(loctestnum, loctesterr, h_copy_single, true); 
            EqualLinear(loctestnum, loctesterr, h_single_src, h_copy_single, true);
            GetAt(loctestnum, loctesterr, h_copy_single, true, 0, 10);

            // HeapVec size > 1 (Heap)
            lasd::SortableVector<int> vec_multi_src(3);
            SetAt(loctestnum, loctesterr, vec_multi_src, true, 0, 5);
            SetAt(loctestnum, loctesterr, vec_multi_src, true, 1, 15);
            SetAt(loctestnum, loctesterr, vec_multi_src, true, 2, 10);
            lasd::HeapVec<int> h_multi_src(vec_multi_src); 
            lasd::HeapVec<int> h_copy_multi(h_multi_src);
            Size(loctestnum, loctesterr, h_copy_multi, true, 3);
            IsHeap(loctestnum, loctesterr, h_copy_multi, true); 
            EqualLinear(loctestnum, loctesterr, h_multi_src, h_copy_multi, true);
            GetFront(loctestnum, loctesterr, h_copy_multi, true, 15);

            SetAt(loctestnum, loctesterr, h_multi_src, true, 0, 99);
            NonEqualLinear(loctestnum, loctesterr, h_multi_src, h_copy_multi, true);
            GetFront(loctestnum, loctesterr, h_copy_multi, true, 15);

            // HeapVec size > 1 (not a Heap)
            lasd::SortableVector<int> vec_sorted_src_data(3);
            SetAt(loctestnum, loctesterr, vec_sorted_src_data, true, 0, 20);
            SetAt(loctestnum, loctesterr, vec_sorted_src_data, true, 1, 5);
            SetAt(loctestnum, loctesterr, vec_sorted_src_data, true, 2, 10);
            lasd::HeapVec<int> h_sorted_src(vec_sorted_src_data); 
            h_sorted_src.Sort();
            IsHeap(loctestnum, loctesterr, h_sorted_src, false);
            lasd::HeapVec<int> h_copy_sorted(h_sorted_src);
            Size(loctestnum, loctesterr, h_copy_sorted, true, 3);
            IsHeap(loctestnum, loctesterr, h_copy_sorted, false); 
            EqualLinear(loctestnum, loctesterr, h_sorted_src, h_copy_sorted, true);
            h_copy_sorted.Heapify();
            EqualLinear(loctestnum, loctesterr, h_sorted_src, h_copy_sorted, false);
            GetAt(loctestnum, loctesterr, h_copy_sorted, true, 0, 20);
        }
        // Move Constructor 
        {
            // HeapVec empty
            lasd::SortableVector<int> vec_empty_src_mv_data(0);
            lasd::HeapVec<int> h_empty_src_mv(vec_empty_src_mv_data);
            lasd::HeapVec<int> h_move_empty(move(h_empty_src_mv));
            Empty(loctestnum, loctesterr, h_move_empty, true);
            IsHeap(loctestnum, loctesterr, h_move_empty, true);
            Empty(loctestnum, loctesterr, h_empty_src_mv, true); 

            // HeapVec size 1
            lasd::SortableVector<int> vec_single_src_mv_data(1);
            SetAt(loctestnum, loctesterr, vec_single_src_mv_data, true, 0, 10);
            lasd::HeapVec<int> h_single_src_mv(vec_single_src_mv_data);
            lasd::HeapVec<int> h_single_src_mv_compare(h_single_src_mv); 
            lasd::HeapVec<int> h_move_single(move(h_single_src_mv));
            Size(loctestnum, loctesterr, h_move_single, true, 1);
            IsHeap(loctestnum, loctesterr, h_move_single, true);
            EqualLinear(loctestnum, loctesterr, h_single_src_mv_compare, h_move_single, true);
            GetAt(loctestnum, loctesterr, h_move_single, true, 0, 10);
            Empty(loctestnum, loctesterr, h_single_src_mv, true);

            // HeapVec size > 1 (Heap)
            lasd::SortableVector<int> vec_multi_src_mv_data(3); 
            SetAt(loctestnum, loctesterr, vec_multi_src_mv_data, true, 0, 5);
            SetAt(loctestnum, loctesterr, vec_multi_src_mv_data, true, 1, 15);
            SetAt(loctestnum, loctesterr, vec_multi_src_mv_data, true, 2, 10);
            lasd::HeapVec<int> h_multi_src_mv(vec_multi_src_mv_data); 
            lasd::HeapVec<int> h_multi_src_mv_compare(h_multi_src_mv); 
            lasd::HeapVec<int> h_move_multi(move(h_multi_src_mv));
            Size(loctestnum, loctesterr, h_move_multi, true, 3);
            IsHeap(loctestnum, loctesterr, h_move_multi, true);
            EqualLinear(loctestnum, loctesterr, h_multi_src_mv_compare, h_move_multi, true);
            GetFront(loctestnum, loctesterr, h_move_multi, true, 15);
            Empty(loctestnum, loctesterr, h_multi_src_mv, true);

            // HeapVec size > 1 (not a Heap)
            lasd::SortableVector<int> vec_sorted_src_mv_data_init(3); 
            SetAt(loctestnum, loctesterr, vec_sorted_src_mv_data_init, true, 0, 20);
            SetAt(loctestnum, loctesterr, vec_sorted_src_mv_data_init, true, 1, 5);
            SetAt(loctestnum, loctesterr, vec_sorted_src_mv_data_init, true, 2, 10);
            lasd::HeapVec<int> h_sorted_src_mv(vec_sorted_src_mv_data_init);
            h_sorted_src_mv.Sort();
            lasd::HeapVec<int> h_sorted_src_mv_compare(h_sorted_src_mv); 
            lasd::HeapVec<int> h_move_sorted(move(h_sorted_src_mv));
            Size(loctestnum, loctesterr, h_move_sorted, true, 3);
            IsHeap(loctestnum, loctesterr, h_move_sorted, false);
            EqualLinear(loctestnum, loctesterr, h_sorted_src_mv_compare, h_move_sorted, true);
            GetAt(loctestnum, loctesterr, h_move_sorted, true, 0, 5);
            Empty(loctestnum, loctesterr, h_sorted_src_mv, true);
        }
        
        // Copy Assignment
        {
            lasd::HeapVec<int> h_assign_dest; 

            // HeapVec empty
            lasd::SortableVector<int> vec_empty_assign_data(0);
            lasd::HeapVec<int> h_empty_assign_src(vec_empty_assign_data);
            h_assign_dest = h_empty_assign_src;
            Empty(loctestnum, loctesterr, h_assign_dest, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest, true);
            EqualLinear(loctestnum, loctesterr, h_empty_assign_src, h_assign_dest, true);

            // HeapVec size 1
            lasd::SortableVector<int> vec_s1_assign_data(1);
            SetAt(loctestnum, loctesterr, vec_s1_assign_data, true, 0, 100);
            lasd::HeapVec<int> h_s1_assign_src(vec_s1_assign_data);
            
            h_assign_dest = h_s1_assign_src; 
            Size(loctestnum, loctesterr, h_assign_dest, true, 1);
            IsHeap(loctestnum, loctesterr, h_assign_dest, true);
            EqualLinear(loctestnum, loctesterr, h_s1_assign_src, h_assign_dest, true);
            GetFront(loctestnum, loctesterr, h_assign_dest, true, 100);
            SetAt(loctestnum, loctesterr, h_s1_assign_src, true, 0, 101); 
            GetFront(loctestnum, loctesterr, h_assign_dest, true, 100); 
            NonEqualLinear(loctestnum, loctesterr, h_s1_assign_src, h_assign_dest, true);

            // HeapVec size > 1 (Heap)
            lasd::SortableVector<int> vec_s3_assign_data(3);
            SetAt(loctestnum, loctesterr, vec_s3_assign_data, true, 0, 5);
            SetAt(loctestnum, loctesterr, vec_s3_assign_data, true, 1, 15);
            SetAt(loctestnum, loctesterr, vec_s3_assign_data, true, 2, 10);
            lasd::HeapVec<int> h_s3_assign_src(vec_s3_assign_data); 
            
            h_assign_dest = h_s3_assign_src; 
            Size(loctestnum, loctesterr, h_assign_dest, true, 3);
            IsHeap(loctestnum, loctesterr, h_assign_dest, true);
            EqualLinear(loctestnum, loctesterr, h_s3_assign_src, h_assign_dest, true);
            GetFront(loctestnum, loctesterr, h_assign_dest, true, 15);
            SetAt(loctestnum, loctesterr, h_s3_assign_src, true, 0, 111); 
            GetFront(loctestnum, loctesterr, h_assign_dest, true, 15); 
            NonEqualLinear(loctestnum, loctesterr, h_s3_assign_src, h_assign_dest, true);

            // HeapVec size > 1 (not a Heap)
            lasd::SortableVector<int> vec_s3_sorted_assign_data(3);
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_data, true, 0, 20);
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_data, true, 1, 5);
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_data, true, 2, 10);
            lasd::HeapVec<int> h_s3_sorted_assign_src(vec_s3_sorted_assign_data);
            h_s3_sorted_assign_src.Sort(); 
            
            h_assign_dest = h_s3_sorted_assign_src; 
            Size(loctestnum, loctesterr, h_assign_dest, true, 3);
            IsHeap(loctestnum, loctesterr, h_assign_dest, false);
            EqualLinear(loctestnum, loctesterr, h_s3_sorted_assign_src, h_assign_dest, true);
            GetAt(loctestnum, loctesterr, h_assign_dest, true, 0, 5);
            SetAt(loctestnum, loctesterr, h_s3_sorted_assign_src, true, 0, 1); 
            GetAt(loctestnum, loctesterr, h_assign_dest, true, 0, 5); 
            NonEqualLinear(loctestnum, loctesterr, h_s3_sorted_assign_src, h_assign_dest, true);

            // Self-assignment
            lasd::SortableVector<int> vec_self_assign_data(3);
            SetAt(loctestnum, loctesterr, vec_self_assign_data, true, 0, 5);
            SetAt(loctestnum, loctesterr, vec_self_assign_data, true, 1, 15);
            SetAt(loctestnum, loctesterr, vec_self_assign_data, true, 2, 10);
            lasd::HeapVec<int> h_self_heap(vec_self_assign_data);
            lasd::HeapVec<int> h_self_heap_compare(h_self_heap);
            h_self_heap = h_self_heap; 
            EqualLinear(loctestnum, loctesterr, h_self_heap_compare, h_self_heap, true);
            IsHeap(loctestnum, loctesterr, h_self_heap, true);
            GetFront(loctestnum, loctesterr, h_self_heap, true, 15);
            lasd::HeapVec<int> h_self_sorted(vec_self_assign_data);
            h_self_sorted.Sort(); 
            lasd::HeapVec<int> h_self_sorted_compare(h_self_sorted);
            h_self_sorted = h_self_sorted; 
            EqualLinear(loctestnum, loctesterr, h_self_sorted_compare, h_self_sorted, true);
            IsHeap(loctestnum, loctesterr, h_self_sorted, false);
            GetAt(loctestnum, loctesterr, h_self_sorted, true, 0, 5);
        }

        // Move Assignment
        {
            lasd::HeapVec<int> h_assign_dest_mv; 

            // HeapVec empty
            lasd::SortableVector<int> vec_empty_assign_mv_data(0);
            lasd::HeapVec<int> h_empty_assign_src_mv(vec_empty_assign_mv_data);
            h_assign_dest_mv = move(h_empty_assign_src_mv);
            Empty(loctestnum, loctesterr, h_assign_dest_mv, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_mv, true);
            Empty(loctestnum, loctesterr, h_empty_assign_src_mv, true);
    
            // HeapVec size 1
            lasd::SortableVector<int> vec_s1_assign_mv_data(1);
            SetAt(loctestnum, loctesterr, vec_s1_assign_mv_data, true, 0, 100);
            lasd::HeapVec<int> h_s1_assign_src_mv(vec_s1_assign_mv_data);
            lasd::HeapVec<int> h_s1_assign_src_mv_compare(h_s1_assign_src_mv);
            h_assign_dest_mv = move(h_s1_assign_src_mv);
            EqualLinear(loctestnum, loctesterr, h_s1_assign_src_mv_compare, h_assign_dest_mv, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_mv, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_mv, true, 100);
            Empty(loctestnum, loctesterr, h_s1_assign_src_mv, true);
        
            // HeapVec size > 1 (Heap)
            lasd::SortableVector<int> vec_s3_assign_mv_data(3);
            SetAt(loctestnum, loctesterr, vec_s3_assign_mv_data, true, 0, 5);
            SetAt(loctestnum, loctesterr, vec_s3_assign_mv_data, true, 1, 15);
            SetAt(loctestnum, loctesterr, vec_s3_assign_mv_data, true, 2, 10);
            lasd::HeapVec<int> h_s3_assign_src_mv(vec_s3_assign_mv_data);
            lasd::HeapVec<int> h_s3_assign_src_mv_compare(h_s3_assign_src_mv);
            h_assign_dest_mv = move(h_s3_assign_src_mv);
            EqualLinear(loctestnum, loctesterr, h_s3_assign_src_mv_compare, h_assign_dest_mv, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_mv, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_mv, true, 15);
            Empty(loctestnum, loctesterr, h_s3_assign_src_mv, false);
        
            // HeapVec size > 1 (Not a Heap)
            lasd::SortableVector<int> vec_s3_sorted_assign_mv_data(3);
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_mv_data, true, 0, 20);
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_mv_data, true, 1, 5);
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_mv_data, true, 2, 10);
            lasd::HeapVec<int> h_s3_sorted_assign_src_mv(vec_s3_sorted_assign_mv_data); 
            h_s3_sorted_assign_src_mv.Sort();
            lasd::HeapVec<int> h_s3_sorted_assign_src_mv_compare(h_s3_sorted_assign_src_mv);
            h_assign_dest_mv = move(h_s3_sorted_assign_src_mv);
            EqualLinear(loctestnum, loctesterr, h_s3_sorted_assign_src_mv_compare, h_assign_dest_mv, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_mv, false);
            GetAt(loctestnum, loctesterr, h_assign_dest_mv, true, 0, 5);
            Empty(loctestnum, loctesterr, h_s3_sorted_assign_src_mv, false);
        
            // Self-assignment
            // lasd::SortableVector<int> vec_self_assign_mv_data(3);
            // vec_self_assign_mv_data[0]=5;
            // vec_self_assign_mv_data[1]=15;
            // vec_self_assign_mv_data[2]=10;
            // lasd::HeapVec<int> h_self_mv_heap(vec_self_assign_mv_data);
            // lasd::HeapVec<int> h_self_mv_heap_compare(h_self_mv_heap);
            // h_self_mv_heap = move(h_self_mv_heap); 
            // EqualLinear(loctestnum, loctesterr, h_self_mv_heap_compare, h_self_mv_heap, true); 
            // IsHeap(loctestnum, loctesterr, h_self_mv_heap, true);
            // GetFront(loctestnum, loctesterr, h_self_mv_heap, true, 15);
        }
        
        // Copy/Move Constructors from SortableVector
        {
            // Copy
            lasd::SortableVector<int> vec_empty(0);
            lasd::HeapVec<int> hv_from_vec_empty(vec_empty);
            Empty(loctestnum, loctesterr, hv_from_vec_empty, true);
            IsHeap(loctestnum, loctesterr, hv_from_vec_empty, true);

            lasd::SortableVector<int> vec_single(1);
            SetAt(loctestnum, loctesterr, vec_single, true, 0, 42);
            lasd::HeapVec<int> hv_from_vec_single(vec_single);
            Size(loctestnum, loctesterr, hv_from_vec_single, true, 1);
            IsHeap(loctestnum, loctesterr, hv_from_vec_single, true);
            GetFront(loctestnum, loctesterr, hv_from_vec_single, true, 42);

            lasd::SortableVector<int> vec_multi(5);
            SetAt(loctestnum, loctesterr, vec_multi, true, 0, 3);
            SetAt(loctestnum, loctesterr, vec_multi, true, 1, 1);
            SetAt(loctestnum, loctesterr, vec_multi, true, 2, 4);
            SetAt(loctestnum, loctesterr, vec_multi, true, 3, 1);
            SetAt(loctestnum, loctesterr, vec_multi, true, 4, 5);
            lasd::HeapVec<int> hv_from_vec_multi(vec_multi); 
            Size(loctestnum, loctesterr, hv_from_vec_multi, true, 5);
            IsHeap(loctestnum, loctesterr, hv_from_vec_multi, true);
            GetFront(loctestnum, loctesterr, hv_from_vec_multi, true, 5); 

            // Move
            lasd::SortableVector<int> vec_empty_mv(0);
            lasd::HeapVec<int> hv_from_vec_empty_mv(move(vec_empty_mv));
            Empty(loctestnum, loctesterr, hv_from_vec_empty_mv, true);
            IsHeap(loctestnum, loctesterr, hv_from_vec_empty_mv, true);
            Empty(loctestnum, loctesterr, vec_empty_mv, true);

            lasd::SortableVector<int> vec_single_mv(1);
            SetAt(loctestnum, loctesterr, vec_single_mv, true, 0, 42);
            lasd::HeapVec<int> hv_from_vec_single_mv(move(vec_single_mv));
            Size(loctestnum, loctesterr, hv_from_vec_single_mv, true, 1);
            IsHeap(loctestnum, loctesterr, hv_from_vec_single_mv, true);
            GetFront(loctestnum, loctesterr, hv_from_vec_single_mv, true, 42);
            Empty(loctestnum, loctesterr, vec_single_mv, false);
            
            lasd::SortableVector<int> vec_multi_mv(5);
            SetAt(loctestnum, loctesterr, vec_multi_mv, true, 0, 3);
            SetAt(loctestnum, loctesterr, vec_multi_mv, true, 1, 1);
            SetAt(loctestnum, loctesterr, vec_multi_mv, true, 2, 4);
            SetAt(loctestnum, loctesterr, vec_multi_mv, true, 3, 1);
            SetAt(loctestnum, loctesterr, vec_multi_mv, true, 4, 5);

            lasd::HeapVec<int> hv_from_vec_multi_mv(move(vec_multi_mv));
            Size(loctestnum, loctesterr, hv_from_vec_multi_mv, true, 5);
            IsHeap(loctestnum, loctesterr, hv_from_vec_multi_mv, true);
            GetFront(loctestnum, loctesterr, hv_from_vec_multi_mv, true, 5);
            Empty(loctestnum, loctesterr, vec_multi_mv, false);
        }
        // Copy/Move Constructors from List
        {
            // Copy
            lasd::List<int> lst_empty;
            lasd::HeapVec<int> hv_from_lst_empty(lst_empty);
            Empty(loctestnum, loctesterr, hv_from_lst_empty, true);
            IsHeap(loctestnum, loctesterr, hv_from_lst_empty, true);

            lasd::List<int> lst_single;
            InsertAtBack(loctestnum, loctesterr, lst_single, true, 77);
            lasd::HeapVec<int> hv_from_lst_single(lst_single);
            Size(loctestnum, loctesterr, hv_from_lst_single, true, 1);
            IsHeap(loctestnum, loctesterr, hv_from_lst_single, true);
            GetFront(loctestnum, loctesterr, hv_from_lst_single, true, 77);

            lasd::List<int> lst_multi;
            InsertAtBack(loctestnum, loctesterr, lst_multi, true, 30);
            InsertAtBack(loctestnum, loctesterr, lst_multi, true, 10);
            InsertAtBack(loctestnum, loctesterr, lst_multi, true, 40);
            InsertAtBack(loctestnum, loctesterr, lst_multi, true, 10);
            InsertAtBack(loctestnum, loctesterr, lst_multi, true, 50);
            lasd::HeapVec<int> hv_from_lst_multi(lst_multi); 
            Size(loctestnum, loctesterr, hv_from_lst_multi, true, 5);
            IsHeap(loctestnum, loctesterr, hv_from_lst_multi, true);
            GetFront(loctestnum, loctesterr, hv_from_lst_multi, true, 50); 
        
            // Move
            lasd::List<int> lst_empty_mv;
            lasd::HeapVec<int> hv_from_lst_empty_mv(move(lst_empty_mv));
            Empty(loctestnum, loctesterr, hv_from_lst_empty_mv, true);
            IsHeap(loctestnum, loctesterr, hv_from_lst_empty_mv, true);
            Empty(loctestnum, loctesterr, lst_empty_mv, true);

            lasd::List<int> lst_single_mv;
            InsertAtBack(loctestnum, loctesterr, lst_single_mv, true, 77);
            lasd::HeapVec<int> hv_from_lst_single_mv(move(lst_single_mv));
            Size(loctestnum, loctesterr, hv_from_lst_single_mv, true, 1);
            IsHeap(loctestnum, loctesterr, hv_from_lst_single_mv, true);
            GetFront(loctestnum, loctesterr, hv_from_lst_single_mv, true, 77);
            Empty(loctestnum, loctesterr, lst_single_mv, false);
            
            lasd::List<int> lst_multi_mv;
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv, true, 30);
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv, true, 10);
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv, true, 40);
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv, true, 10);
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv, true, 50);

            lasd::HeapVec<int> hv_from_lst_multi_mv(move(lst_multi_mv));
            Size(loctestnum, loctesterr, hv_from_lst_multi_mv, true, 5);
            IsHeap(loctestnum, loctesterr, hv_from_lst_multi_mv, true);
            GetFront(loctestnum, loctesterr, hv_from_lst_multi_mv, true, 50);
            Empty(loctestnum, loctesterr, lst_multi_mv, false);
        }
        // Copy constructor from SetVec
        {
            lasd::SetVec<int> setvec_empty;
            lasd::HeapVec<int> hv_from_setvec_empty(setvec_empty);
            Empty(loctestnum, loctesterr, hv_from_setvec_empty, true);
            IsHeap(loctestnum, loctesterr, hv_from_setvec_empty, true);

            lasd::SetVec<int> setvec_single;
            InsertC(loctestnum, loctesterr, setvec_single, true, 88);
            lasd::HeapVec<int> hv_from_setvec_single(setvec_single);
            Size(loctestnum, loctesterr, hv_from_setvec_single, true, 1);
            IsHeap(loctestnum, loctesterr, hv_from_setvec_single, true);
            GetFront(loctestnum, loctesterr, hv_from_setvec_single, true, 88);

            lasd::SetVec<int> setvec_multi;
            InsertC(loctestnum, loctesterr, setvec_multi, true, 3);
            InsertC(loctestnum, loctesterr, setvec_multi, true, 1);
            InsertC(loctestnum, loctesterr, setvec_multi, true, 4);
            InsertC(loctestnum, loctesterr, setvec_multi, false, 1);
            InsertC(loctestnum, loctesterr, setvec_multi, true, 5);
            
            lasd::HeapVec<int> hv_from_setvec_multi(setvec_multi);
            Size(loctestnum, loctesterr, hv_from_setvec_multi, true, 4);
            IsHeap(loctestnum, loctesterr, hv_from_setvec_multi, true);
            GetFront(loctestnum, loctesterr, hv_from_setvec_multi, true, 5); 
        }
        // Copy Constructor from SetLst
        {
            lasd::List<int> setlst_data_empty_init;
            lasd::SetLst<int> setlst_empty(setlst_data_empty_init);
            lasd::HeapVec<int> hv_from_setlst_empty(setlst_empty);
            Empty(loctestnum, loctesterr, hv_from_setlst_empty, true);
            IsHeap(loctestnum, loctesterr, hv_from_setlst_empty, true);

            lasd::SetLst<int> setlst_single;
            InsertC(loctestnum, loctesterr, setlst_single, true, 99);
            lasd::HeapVec<int> hv_from_setlst_single(setlst_single);
            Size(loctestnum, loctesterr, hv_from_setlst_single, true, 1);
            IsHeap(loctestnum, loctesterr, hv_from_setlst_single, true);
            GetFront(loctestnum, loctesterr, hv_from_setlst_single, true, 99);

            lasd::SetLst<int> setlst_multi;
            InsertC(loctestnum, loctesterr, setlst_multi, true, 30);
            InsertC(loctestnum, loctesterr, setlst_multi, true, 10);
            InsertC(loctestnum, loctesterr, setlst_multi, true, 40);
            InsertC(loctestnum, loctesterr, setlst_multi, false, 10);
            InsertC(loctestnum, loctesterr, setlst_multi, true, 50);

            lasd::HeapVec<int> hv_from_setlst_multi(setlst_multi);
            Size(loctestnum, loctesterr, hv_from_setlst_multi, true, 4);
            IsHeap(loctestnum, loctesterr, hv_from_setlst_multi, true);
            GetFront(loctestnum, loctesterr, hv_from_setlst_multi, true, 50); 
        }
        // Copy/Move Assignments from SortableVector
        {
            lasd::HeapVec<int> h_assign_dest_from_vec;

            // Copy Assignment 
            lasd::SortableVector<int> sv_empty_src(0);
            h_assign_dest_from_vec = sv_empty_src;
            Empty(loctestnum, loctesterr, h_assign_dest_from_vec, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_vec, true);

            lasd::SortableVector<int> sv_single_src(1);
            SetAt(loctestnum, loctesterr, sv_single_src, true, 0, 55);
            h_assign_dest_from_vec = sv_single_src;
            Size(loctestnum, loctesterr, h_assign_dest_from_vec, true, 1);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_vec, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_vec, true, 55);
            SetAt(loctestnum, loctesterr, sv_single_src, true, 0, 56); 
            GetFront(loctestnum, loctesterr, h_assign_dest_from_vec, true, 55);

            lasd::SortableVector<int> sv_multi_src(3);
            SetAt(loctestnum, loctesterr, sv_multi_src, true, 0, 10);
            SetAt(loctestnum, loctesterr, sv_multi_src, true, 1, 30);
            SetAt(loctestnum, loctesterr, sv_multi_src, true, 2, 20); 
            lasd::HeapVec<int> h_non_empty_dest_vec(sv_single_src); 
            h_non_empty_dest_vec = sv_multi_src;
            Size(loctestnum, loctesterr, h_non_empty_dest_vec, true, 3);
            IsHeap(loctestnum, loctesterr, h_non_empty_dest_vec, true);
            GetFront(loctestnum, loctesterr, h_non_empty_dest_vec, true, 30);

            // Move Assignment 
            lasd::SortableVector<int> sv_empty_mv_src(0);
            h_assign_dest_from_vec = move(sv_empty_mv_src); 
            Empty(loctestnum, loctesterr, h_assign_dest_from_vec, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_vec, true);
            Empty(loctestnum, loctesterr, sv_empty_mv_src, true);

            lasd::SortableVector<int> sv_single_mv_src(1);
            SetAt(loctestnum, loctesterr, sv_single_mv_src, true, 0, 66);
            h_assign_dest_from_vec = move(sv_single_mv_src);
            Size(loctestnum, loctesterr, h_assign_dest_from_vec, true, 1);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_vec, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_vec, true, 66);
            Empty(loctestnum, loctesterr, sv_single_mv_src, false);

            lasd::SortableVector<int> sv_multi_mv_src(3);
            SetAt(loctestnum, loctesterr, sv_multi_mv_src, true, 0, 10);
            SetAt(loctestnum, loctesterr, sv_multi_mv_src, true, 1, 30);
            SetAt(loctestnum, loctesterr, sv_multi_mv_src, true, 2, 20);
            lasd::HeapVec<int> h_non_empty_dest_vec_mv;
            SetAt(loctestnum,loctesterr, h_non_empty_dest_vec_mv, false, 0, 123);

            h_non_empty_dest_vec_mv = move(sv_multi_mv_src);
            Size(loctestnum, loctesterr, h_non_empty_dest_vec_mv, true, 3);
            IsHeap(loctestnum, loctesterr, h_non_empty_dest_vec_mv, true);
            GetFront(loctestnum, loctesterr, h_non_empty_dest_vec_mv, true, 30);
            Empty(loctestnum, loctesterr, sv_multi_mv_src, false);  
        }
       // Copy/Move Assignments from List
        {
            lasd::HeapVec<int> h_assign_dest_from_lst;

            // Copy Assignment    
            lasd::List<int> lst_empty_src;
            h_assign_dest_from_lst = lst_empty_src;
            Empty(loctestnum, loctesterr, h_assign_dest_from_lst, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_lst, true);

            lasd::List<int> lst_single_src;
            InsertAtBack(loctestnum, loctesterr, lst_single_src, true, 77);
            h_assign_dest_from_lst = lst_single_src;
            Size(loctestnum, loctesterr, h_assign_dest_from_lst, true, 1);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_lst, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_lst, true, 77);
            InsertAtBack(loctestnum, loctesterr, lst_single_src, true, 78); 
            Size(loctestnum, loctesterr, h_assign_dest_from_lst, true, 1);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_lst, true, 77);


            lasd::List<int> lst_multi_src;
            InsertAtBack(loctestnum, loctesterr, lst_multi_src, true, 10);
            InsertAtBack(loctestnum, loctesterr, lst_multi_src, true, 30);
            InsertAtBack(loctestnum, loctesterr, lst_multi_src, true, 20);
            lasd::HeapVec<int> h_non_empty_dest_lst(lst_single_src);
            h_non_empty_dest_lst = lst_multi_src;
            Size(loctestnum, loctesterr, h_non_empty_dest_lst, true, 3);
            IsHeap(loctestnum, loctesterr, h_non_empty_dest_lst, true);
            GetFront(loctestnum, loctesterr, h_non_empty_dest_lst, true, 30);
        
            // Move Assignment
            lasd::List<int> lst_empty_mv_src;
            h_assign_dest_from_lst = move(lst_empty_mv_src);
            Empty(loctestnum, loctesterr, h_assign_dest_from_lst, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_lst, true);
            Empty(loctestnum, loctesterr, lst_empty_mv_src, true);

            lasd::List<int> lst_single_mv_src;
            InsertAtBack(loctestnum, loctesterr, lst_single_mv_src, true, 88);
            h_assign_dest_from_lst = move(lst_single_mv_src);
            Size(loctestnum, loctesterr, h_assign_dest_from_lst, true, 1);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_lst, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_lst, true, 88);
            Empty(loctestnum, loctesterr, lst_single_mv_src, false);
            
            lasd::List<int> lst_multi_mv_src;
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv_src, true, 10);
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv_src, true, 30);
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv_src, true, 20);
            lasd::HeapVec<int> h_non_empty_dest_lst_mv;
            h_non_empty_dest_lst_mv = move(lst_multi_mv_src);
            Size(loctestnum, loctesterr, h_non_empty_dest_lst_mv, true, 3);
            IsHeap(loctestnum, loctesterr, h_non_empty_dest_lst_mv, true);
            GetFront(loctestnum, loctesterr, h_non_empty_dest_lst_mv, true, 30);
            Empty(loctestnum, loctesterr, lst_multi_mv_src, false);
        }
        // Copy Assignment SetVec 
        {
            lasd::HeapVec<int> h_assign_dest_from_setvec;

            lasd::SetVec<int> setvec_empty_src;
            h_assign_dest_from_setvec = setvec_empty_src;
            Empty(loctestnum, loctesterr, h_assign_dest_from_setvec, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_setvec, true);

            lasd::SetVec<int> setvec_single_src;
            InsertC(loctestnum, loctesterr, setvec_single_src, true, 111);
            h_assign_dest_from_setvec = setvec_single_src;
            Size(loctestnum, loctesterr, h_assign_dest_from_setvec, true, 1);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_setvec, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_setvec, true, 111);
            InsertC(loctestnum, loctesterr, setvec_single_src, true, 112);
            Size(loctestnum, loctesterr, h_assign_dest_from_setvec, true, 1);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_setvec, true, 111);

            lasd::SetVec<int> setvec_multi_src;
            InsertC(loctestnum, loctesterr, setvec_multi_src, true, 10);
            InsertC(loctestnum, loctesterr, setvec_multi_src, true, 30);
            InsertC(loctestnum, loctesterr, setvec_multi_src, true, 20);
            InsertC(loctestnum, loctesterr, setvec_multi_src, false, 10); 
            lasd::HeapVec<int> h_non_empty_dest_setvec(setvec_single_src); 
            h_non_empty_dest_setvec = setvec_multi_src;
            Size(loctestnum, loctesterr, h_non_empty_dest_setvec, true, 3);
            IsHeap(loctestnum, loctesterr, h_non_empty_dest_setvec, true);
            GetFront(loctestnum, loctesterr, h_non_empty_dest_setvec, true, 30);
        }

        // Copy Assignment SetLst
        {
            lasd::HeapVec<int> h_assign_dest_from_setlst;

            lasd::SetLst<int> setlst_empty_src;
            h_assign_dest_from_setlst = setlst_empty_src;
            Empty(loctestnum, loctesterr, h_assign_dest_from_setlst, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_setlst, true);

            lasd::SetLst<int> setlst_single_src;
            InsertC(loctestnum, loctesterr, setlst_single_src, true, 222);
            h_assign_dest_from_setlst = setlst_single_src;
            Size(loctestnum, loctesterr, h_assign_dest_from_setlst, true, 1);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_setlst, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_setlst, true, 222);
            InsertC(loctestnum, loctesterr, setlst_single_src, true, 223);
            Size(loctestnum, loctesterr, h_assign_dest_from_setlst, true, 1);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_setlst, true, 222);

            lasd::SetLst<int> setlst_multi_src;
            InsertC(loctestnum, loctesterr, setlst_multi_src, true, 10);
            InsertC(loctestnum, loctesterr, setlst_multi_src, true, 30);
            InsertC(loctestnum, loctesterr, setlst_multi_src, true, 20);
            InsertC(loctestnum, loctesterr, setlst_multi_src, false, 10);
            lasd::HeapVec<int> h_non_empty_dest_setlst(setlst_single_src);
            h_non_empty_dest_setlst = setlst_multi_src;
            Size(loctestnum, loctesterr, h_non_empty_dest_setlst, true, 3);
            IsHeap(loctestnum, loctesterr, h_non_empty_dest_setlst, true);
            GetFront(loctestnum, loctesterr, h_non_empty_dest_setlst, true, 30);
        }

        // Comparison Operators with sort 
        {
            lasd::SortableVector<int> vec_data1(3);
            SetAt(loctestnum, loctesterr, vec_data1, true, 0, 10);
            SetAt(loctestnum, loctesterr, vec_data1, true, 1, 20);
            SetAt(loctestnum, loctesterr, vec_data1, true, 2, 5); 

            lasd::SortableVector<int> vec_data2(3);
            SetAt(loctestnum, loctesterr, vec_data2, true, 0, 10);
            SetAt(loctestnum, loctesterr, vec_data2, true, 1, 20);
            SetAt(loctestnum, loctesterr, vec_data2, true, 2, 5);

            lasd::SortableVector<int> vec_data3(3);
            SetAt(loctestnum, loctesterr, vec_data3, true, 0, 10);
            SetAt(loctestnum, loctesterr, vec_data3, true, 1, 25);
            SetAt(loctestnum, loctesterr, vec_data3, true, 2, 5);

            lasd::SortableVector<int> vec_data4(2);
            SetAt(loctestnum, loctesterr, vec_data4, true, 0, 10);
            SetAt(loctestnum, loctesterr, vec_data4, true, 1, 20);

            lasd::HeapVec<int> h1(vec_data1);
            lasd::HeapVec<int> h2(vec_data2);
            lasd::HeapVec<int> h3(vec_data1);
            h3.Sort();
            lasd::HeapVec<int> h4(vec_data3);
            lasd::HeapVec<int> h5(vec_data4);
            lasd::HeapVec<int> h_empty1;
            lasd::HeapVec<int> h_empty2;

            EqualLinear(loctestnum, loctesterr, h1, h2, true);   
            NonEqualLinear(loctestnum, loctesterr, h1, h3, true);
            
            lasd::HeapVec<int> h1_sorted_copy(vec_data1);
            h1_sorted_copy.Sort();
            EqualLinear(loctestnum, loctesterr, h3, h1_sorted_copy, true);

            NonEqualLinear(loctestnum, loctesterr, h1, h4, true);
            NonEqualLinear(loctestnum, loctesterr, h1, h5, true);
            EqualLinear(loctestnum, loctesterr, h_empty1, h_empty2, true);
            NonEqualLinear(loctestnum, loctesterr, h1, h_empty1, true);
        }

        //  Sort, Heapify, operator[]
        {
            lasd::SortableVector<int> s_vec_data(5);
            SetAt(loctestnum, loctesterr, s_vec_data, true, 0, 30);
            SetAt(loctestnum, loctesterr, s_vec_data, true, 1, 10);
            SetAt(loctestnum, loctesterr, s_vec_data, true, 2, 50);
            SetAt(loctestnum, loctesterr, s_vec_data, true, 3, 20);
            SetAt(loctestnum, loctesterr, s_vec_data, true, 4, 40);
           
            lasd::HeapVec<int> hv_ops(s_vec_data);
            IsHeap(loctestnum, loctesterr, hv_ops, true);
            GetFront(loctestnum, loctesterr, hv_ops, true, 50);

            hv_ops.Sort();
            IsHeap(loctestnum, loctesterr, hv_ops, false);
            GetAt(loctestnum, loctesterr, hv_ops, true, 0, 10);
            GetAt(loctestnum, loctesterr, hv_ops, true, 4, 50);

            // Heapify su un heap sorted
            hv_ops.Heapify();
            IsHeap(loctestnum, loctesterr, hv_ops, true);
            GetFront(loctestnum, loctesterr, hv_ops, true, 50);

            // Rompo l'heap
            SetAt(loctestnum, loctesterr, hv_ops, true, 1, 5);
            IsHeap(loctestnum, loctesterr, hv_ops, false);
            
            hv_ops.Heapify();
            IsHeap(loctestnum, loctesterr, hv_ops, true);
            GetFront(loctestnum, loctesterr, hv_ops, true, 50); 

            SetAt(loctestnum, loctesterr, hv_ops, true, 0, 1); 
            IsHeap(loctestnum, loctesterr, hv_ops, false);
            hv_ops.Heapify();
            IsHeap(loctestnum, loctesterr, hv_ops, true);
            GetFront(loctestnum, loctesterr, hv_ops, true, 30);

            // Sort su un heap con duplicati
            lasd::SortableVector<int> s_vec_dupl_data(5);
            SetAt(loctestnum, loctesterr, s_vec_dupl_data, true, 0, 20);
            SetAt(loctestnum, loctesterr, s_vec_dupl_data, true, 1, 10);
            SetAt(loctestnum, loctesterr, s_vec_dupl_data, true, 2, 20);
            SetAt(loctestnum, loctesterr, s_vec_dupl_data, true, 3, 5);
            SetAt(loctestnum, loctesterr, s_vec_dupl_data, true, 4, 20);
            lasd::HeapVec<int> hv_dupl(s_vec_dupl_data); 
            IsHeap(loctestnum, loctesterr, hv_dupl, true);
            hv_dupl.Sort();
            IsHeap(loctestnum, loctesterr, hv_dupl, false);
            GetAt(loctestnum, loctesterr, hv_dupl, true, 0, 5);
            GetAt(loctestnum, loctesterr, hv_dupl, true, 2, 20);
            GetAt(loctestnum, loctesterr, hv_dupl, true, 4, 20);
        }

        // Test su const + eccezioni a caso
        {
            lasd::SortableVector<int> const_vec_data(3);
            SetAt(loctestnum, loctesterr, const_vec_data, true, 0, 10);
            SetAt(loctestnum, loctesterr, const_vec_data, true, 1, 5);
            SetAt(loctestnum, loctesterr, const_vec_data, true, 2, 15); 

            const lasd::HeapVec<int> const_hv_empty;

            Empty(loctestnum, loctesterr, const_hv_empty, true);
            Size(loctestnum, loctesterr, const_hv_empty, true, 0);
            IsHeap(loctestnum, loctesterr, const_hv_empty, true);
            Exists(loctestnum, loctesterr, const_hv_empty, false, 1);
            
            const lasd::HeapVec<int> const_hv(const_vec_data);

            Empty(loctestnum, loctesterr, const_hv, false);
            Size(loctestnum, loctesterr, const_hv, true, 3);
            IsHeap(loctestnum, loctesterr, const_hv, true);
            GetFront(loctestnum, loctesterr, const_hv, true, 15);
            GetAt(loctestnum, loctesterr, const_hv, true, 1, 5);
            Exists(loctestnum, loctesterr, const_hv, true, 10);
            Exists(loctestnum, loctesterr, const_hv, false, 100);
            Traverse(loctestnum, loctesterr, const_hv, true, &TraversePrint<int>);
            Fold(loctestnum, loctesterr, const_hv, true, &FoldAdd<int>, 0, 30);
        
            lasd::HeapVec<int> hv_exc;
            GetFront(loctestnum, loctesterr, hv_exc, false, 0);

            lasd::SortableVector<int> vec_exc_data(1);
            SetAt(loctestnum, loctesterr, vec_exc_data, true, 0, 10);
            lasd::HeapVec<int> hv_exc_one(vec_exc_data);

            GetAt(loctestnum, loctesterr, hv_exc_one, false, 1, 0); 
            GetAt(loctestnum, loctesterr, hv_exc_one, false, 5, 0);

            SetAt(loctestnum, loctesterr, hv_exc_one, false, 1, 20);
            SetAt(loctestnum, loctesterr, hv_exc_one, false, 5, 20);
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MyHeapVec<int> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

void myhpvec_double(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        cout << endl<< "############################################################################"<< endl;
        cout << endl << "---------------------- Begin of MyHeapVec<double> tests: ----------------------" << endl;

        // EmptyHeapVecDefaultConstructor
        {
            lasd::HeapVec<double> hpvec;

            Empty(loctestnum, loctesterr, hpvec, true);
            Size(loctestnum, loctesterr, hpvec, true, 0);

            IsHeap(loctestnum, loctesterr, hpvec, true);
            hpvec.Heapify();
            IsHeap(loctestnum, loctesterr, hpvec, true);

            GetFront(loctestnum, loctesterr, hpvec, false, 0.0);
            GetBack(loctestnum, loctesterr, hpvec, false, 0.0);
            GetAt(loctestnum, loctesterr, hpvec, false, 0, 0.0);
            SetAt(loctestnum, loctesterr, hpvec, false, 0, 0.0);

            Exists(loctestnum, loctesterr, hpvec, false, 0.0);

            Traverse(loctestnum, loctesterr, hpvec, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, hpvec, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, hpvec, true, &TraversePrint<double>);
            Fold(loctestnum, loctesterr, hpvec, true, &FoldMultiply<double>, 1.0, 1.0);
            FoldPreOrder(loctestnum, loctesterr, hpvec, true, &FoldMultiply<double>, 1.0, 1.0);
            FoldPostOrder(loctestnum, loctesterr, hpvec, true, &FoldMultiply<double>, 1.0, 1.0);

            Fold(loctestnum, loctesterr, hpvec, true, &FoldMultiply<double>, 0.0, 0.0);
            FoldPreOrder(loctestnum, loctesterr, hpvec, true, &FoldMultiply<double>, 0.0, 0.0);
            FoldPostOrder(loctestnum, loctesterr, hpvec, true, &FoldMultiply<double>, 0.0, 0.0);

            Map(loctestnum, loctesterr, hpvec, true, &MapIncrement<double>);
            MapPreOrder(loctestnum, loctesterr, hpvec, true, &MapIncrement<double>);
            MapPostOrder(loctestnum, loctesterr, hpvec, true, &MapIncrement<double>);

            hpvec.Sort();
            IsHeap(loctestnum, loctesterr, hpvec, true);
            Empty(loctestnum, loctesterr, hpvec, true);
            Size(loctestnum, loctesterr, hpvec, true, 0);

            hpvec.Clear();
            Empty(loctestnum, loctesterr, hpvec, true);
        }
        // ConstructorWithSize(from Vec)
        {
            // SIZE 0 

            lasd::SortableVector<double> emptyvec(0);
            lasd::HeapVec<double> emptyhp(emptyvec);

            Empty(loctestnum, loctesterr, emptyhp, true);
            Size(loctestnum, loctesterr, emptyhp, true, 0);

            IsHeap(loctestnum, loctesterr, emptyhp, true);
            emptyhp.Heapify();
            IsHeap(loctestnum, loctesterr, emptyhp, true);

            GetFront(loctestnum, loctesterr, emptyhp, false, 0.0);
            GetBack(loctestnum, loctesterr, emptyhp, false, 0.0);
            GetAt(loctestnum, loctesterr, emptyhp, false, 0, 0.0);
            SetAt(loctestnum, loctesterr, emptyhp, false, 0, 0.0);

            Exists(loctestnum, loctesterr, emptyhp, false, 0.0);

            Traverse(loctestnum, loctesterr, emptyhp, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, emptyhp, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, emptyhp, true, &TraversePrint<double>);

            Fold(loctestnum, loctesterr, emptyhp, true, &FoldMultiply<double>, 0.0, 0.0);
            FoldPreOrder(loctestnum, loctesterr, emptyhp, true, &FoldMultiply<double>, 0.0, 0.0);
            FoldPostOrder(loctestnum, loctesterr, emptyhp, true, &FoldMultiply<double>, 0.0, 0.0);

            Map(loctestnum, loctesterr, emptyhp, true, &MapIncrement<double>);
            MapPreOrder(loctestnum, loctesterr, emptyhp, true, &MapIncrement<double>);
            MapPostOrder(loctestnum, loctesterr, emptyhp, true, &MapIncrement<double>);

            emptyhp.Sort();
            Empty(loctestnum, loctesterr, emptyhp, true);
            Size(loctestnum, loctesterr, emptyhp, true, 0);

            emptyhp.Clear();
            Empty(loctestnum, loctesterr, emptyhp, true);

            // SIZE 1

            lasd::SortableVector<double> singlevec(1);
            SetAt(loctestnum, loctesterr, singlevec, true, 0, 7.0);
            lasd::HeapVec<double> singlehp(singlevec);

            Empty(loctestnum, loctesterr, singlehp, false);
            Size(loctestnum, loctesterr, singlehp, true, 1);

            IsHeap(loctestnum, loctesterr, singlehp, true);
            singlehp.Heapify();
            IsHeap(loctestnum, loctesterr, singlehp, true);

            GetFront(loctestnum, loctesterr, singlehp, true, 7.0);
            GetBack(loctestnum, loctesterr, singlehp, true, 7.0);
            GetAt(loctestnum, loctesterr, singlehp, true, 0, 7.0);
            GetAt(loctestnum, loctesterr, singlehp, false, 1, 7.0);
            SetAt(loctestnum, loctesterr, singlehp, true, 0, 10.0);

            Exists(loctestnum, loctesterr, singlehp, false, 0.0);
            Exists(loctestnum, loctesterr, singlehp, true, 10.0);

            Traverse(loctestnum, loctesterr, singlehp, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, singlehp, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, singlehp, true, &TraversePrint<double>);

            Fold(loctestnum, loctesterr, singlehp, true, &FoldMultiply<double>, 1.0, 10.0);
            FoldPreOrder(loctestnum, loctesterr, singlehp, true, &FoldMultiply<double>, 1.0, 10.0);
            FoldPostOrder(loctestnum, loctesterr, singlehp, true, &FoldMultiply<double>, 1.0, 10.0);

            Map(loctestnum, loctesterr, singlehp, true, &MapIncrement<double>);
            MapPreOrder(loctestnum, loctesterr, singlehp, true, &MapIncrement<double>);
            MapPostOrder(loctestnum, loctesterr, singlehp, true, &MapIncrement<double>);

            singlehp.Sort();
            Empty(loctestnum, loctesterr, singlehp, false);
            Size(loctestnum, loctesterr, singlehp, true, 1);
            IsHeap(loctestnum, loctesterr, singlehp, true);

            singlehp.Clear();
            Empty(loctestnum, loctesterr, singlehp, true);
            Size(loctestnum, loctesterr, singlehp, true, 0);
            IsHeap(loctestnum, loctesterr, singlehp, true);

            // SIZE 3

            lasd::SortableVector<double> multivec(3);
            SetAt(loctestnum, loctesterr, multivec, true, 0, 7.0);
            SetAt(loctestnum, loctesterr, multivec, true, 1, 8.0);
            SetAt(loctestnum, loctesterr, multivec, true, 2, 9.0);
            lasd::HeapVec<double> multihp(multivec);

            Empty(loctestnum, loctesterr, multihp, false);
            Size(loctestnum, loctesterr, multihp, true, 3);

            IsHeap(loctestnum, loctesterr, multihp, true);
            multihp.Heapify();
            IsHeap(loctestnum, loctesterr, multihp, true);

            GetFront(loctestnum, loctesterr, multihp, true, 9.0);
            GetBack(loctestnum, loctesterr, multihp, true, 7.0);
            GetAt(loctestnum, loctesterr, multihp, true, 0, 9.0);
            GetAt(loctestnum, loctesterr, multihp, true, 2, 7.0);
            GetAt(loctestnum, loctesterr, singlehp, false, 3, 7.0);
            SetAt(loctestnum, loctesterr, multihp, true, 0, 10.0);

            Exists(loctestnum, loctesterr, multihp, false, 0.0);
            Exists(loctestnum, loctesterr, multihp, true, 10.0);

            Traverse(loctestnum, loctesterr, multihp, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, multihp, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, multihp, true, &TraversePrint<double>);

            Fold(loctestnum, loctesterr, multihp, true, &FoldMultiply<double>, 1.0, 560.0);
            FoldPreOrder(loctestnum, loctesterr, multihp, true, &FoldMultiply<double>, 1.0, 560.0);
            FoldPostOrder(loctestnum, loctesterr, multihp, true, &FoldMultiply<double>, 1.0, 560.0);

            Map(loctestnum, loctesterr, multihp, true, &MapIncrement<double>);
            MapPreOrder(loctestnum, loctesterr, multihp, true, &MapIncrement<double>);
            MapPostOrder(loctestnum, loctesterr, multihp, true, &MapIncrement<double>);

            multihp.Sort();
            Traverse(loctestnum, loctesterr, multihp, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, multihp, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, multihp, true, &TraversePrint<double>);

            Empty(loctestnum, loctesterr, multihp, false);
            Size(loctestnum, loctesterr, multihp, true, 3);
            IsHeap(loctestnum, loctesterr, multihp, false);

            multihp.Heapify();
            Traverse(loctestnum, loctesterr, multihp, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, multihp, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, multihp, true, &TraversePrint<double>);
            IsHeap(loctestnum, loctesterr, multihp, true);

            multihp.Clear();
            Empty(loctestnum, loctesterr, multihp, true);
            Size(loctestnum, loctesterr, multihp, true, 0);
            IsHeap(loctestnum, loctesterr, multihp, true);
        }
        // Copy Constructor
        {
            // HeapVec empty
            lasd::SortableVector<double> vec_empty_src(0);
            lasd::HeapVec<double> h_empty_src(vec_empty_src); 
            lasd::HeapVec<double> h_copy_empty(h_empty_src);
            Empty(loctestnum, loctesterr, h_copy_empty, true);
            Size(loctestnum, loctesterr, h_copy_empty, true, 0);
            IsHeap(loctestnum, loctesterr, h_copy_empty, true); 
            EqualLinear(loctestnum, loctesterr, h_empty_src, h_copy_empty, true);

            // HeapVec size 1
            lasd::SortableVector<double> vec_single_src(1);
            SetAt(loctestnum, loctesterr, vec_single_src, true, 0, 10.0);
            lasd::HeapVec<double> h_single_src(vec_single_src); 
            lasd::HeapVec<double> h_copy_single(h_single_src);
            Size(loctestnum, loctesterr, h_copy_single, true, 1);
            IsHeap(loctestnum, loctesterr, h_copy_single, true); 
            EqualLinear(loctestnum, loctesterr, h_single_src, h_copy_single, true);
            GetAt(loctestnum, loctesterr, h_copy_single, true, 0, 10.0);

            // HeapVec size > 1 (Heap)
            lasd::SortableVector<double> vec_multi_src(3);
            SetAt(loctestnum, loctesterr, vec_multi_src, true, 0, 5.0);
            SetAt(loctestnum, loctesterr, vec_multi_src, true, 1, 15.0);
            SetAt(loctestnum, loctesterr, vec_multi_src, true, 2, 10.0);
            lasd::HeapVec<double> h_multi_src(vec_multi_src); 
            lasd::HeapVec<double> h_copy_multi(h_multi_src);
            Size(loctestnum, loctesterr, h_copy_multi, true, 3);
            IsHeap(loctestnum, loctesterr, h_copy_multi, true); 
            EqualLinear(loctestnum, loctesterr, h_multi_src, h_copy_multi, true);
            GetFront(loctestnum, loctesterr, h_copy_multi, true, 15.0);

            SetAt(loctestnum, loctesterr, h_multi_src, true, 0, 99.0);
            NonEqualLinear(loctestnum, loctesterr, h_multi_src, h_copy_multi, true);
            GetFront(loctestnum, loctesterr, h_copy_multi, true, 15.0);

            // HeapVec size > 1 (not a Heap)
            lasd::SortableVector<double> vec_sorted_src_data(3);
            SetAt(loctestnum, loctesterr, vec_sorted_src_data, true, 0, 20.0);
            SetAt(loctestnum, loctesterr, vec_sorted_src_data, true, 1, 5.0);
            SetAt(loctestnum, loctesterr, vec_sorted_src_data, true, 2, 10.0);
            lasd::HeapVec<double> h_sorted_src(vec_sorted_src_data); 
            h_sorted_src.Sort();
            IsHeap(loctestnum, loctesterr, h_sorted_src, false);
            lasd::HeapVec<double> h_copy_sorted(h_sorted_src);
            Size(loctestnum, loctesterr, h_copy_sorted, true, 3);
            IsHeap(loctestnum, loctesterr, h_copy_sorted, false); 
            EqualLinear(loctestnum, loctesterr, h_sorted_src, h_copy_sorted, true);
            h_copy_sorted.Heapify();
            EqualLinear(loctestnum, loctesterr, h_sorted_src, h_copy_sorted, false);
            GetAt(loctestnum, loctesterr, h_copy_sorted, true, 0, 20.0);
        }
        // Move Constructor 
        {
            // HeapVec empty
            lasd::SortableVector<double> vec_empty_src_mv_data(0);
            lasd::HeapVec<double> h_empty_src_mv(vec_empty_src_mv_data);
            lasd::HeapVec<double> h_move_empty(move(h_empty_src_mv));
            Empty(loctestnum, loctesterr, h_move_empty, true);
            IsHeap(loctestnum, loctesterr, h_move_empty, true);
            Empty(loctestnum, loctesterr, h_empty_src_mv, true); 

            // HeapVec size 1
            lasd::SortableVector<double> vec_single_src_mv_data(1);
            SetAt(loctestnum, loctesterr, vec_single_src_mv_data, true, 0, 10.0);
            lasd::HeapVec<double> h_single_src_mv(vec_single_src_mv_data);
            lasd::HeapVec<double> h_single_src_mv_compare(h_single_src_mv); 
            lasd::HeapVec<double> h_move_single(move(h_single_src_mv));
            Size(loctestnum, loctesterr, h_move_single, true, 1);
            IsHeap(loctestnum, loctesterr, h_move_single, true);
            EqualLinear(loctestnum, loctesterr, h_single_src_mv_compare, h_move_single, true);
            GetAt(loctestnum, loctesterr, h_move_single, true, 0, 10.0);
            Empty(loctestnum, loctesterr, h_single_src_mv, true);

            // HeapVec size > 1 (Heap)
            lasd::SortableVector<double> vec_multi_src_mv_data(3); 
            SetAt(loctestnum, loctesterr, vec_multi_src_mv_data, true, 0, 5.0);
            SetAt(loctestnum, loctesterr, vec_multi_src_mv_data, true, 1, 15.0);
            SetAt(loctestnum, loctesterr, vec_multi_src_mv_data, true, 2, 10.0);
            lasd::HeapVec<double> h_multi_src_mv(vec_multi_src_mv_data); 
            lasd::HeapVec<double> h_multi_src_mv_compare(h_multi_src_mv); 
            lasd::HeapVec<double> h_move_multi(move(h_multi_src_mv));
            Size(loctestnum, loctesterr, h_move_multi, true, 3);
            IsHeap(loctestnum, loctesterr, h_move_multi, true);
            EqualLinear(loctestnum, loctesterr, h_multi_src_mv_compare, h_move_multi, true);
            GetFront(loctestnum, loctesterr, h_move_multi, true, 15.0);
            Empty(loctestnum, loctesterr, h_multi_src_mv, true);

            // HeapVec size > 1 (not a Heap)
            lasd::SortableVector<double> vec_sorted_src_mv_data_init(3); 
            SetAt(loctestnum, loctesterr, vec_sorted_src_mv_data_init, true, 0, 20.0);
            SetAt(loctestnum, loctesterr, vec_sorted_src_mv_data_init, true, 1, 5.0);
            SetAt(loctestnum, loctesterr, vec_sorted_src_mv_data_init, true, 2, 10.0);
            lasd::HeapVec<double> h_sorted_src_mv(vec_sorted_src_mv_data_init);
            h_sorted_src_mv.Sort();
            lasd::HeapVec<double> h_sorted_src_mv_compare(h_sorted_src_mv); 
            lasd::HeapVec<double> h_move_sorted(move(h_sorted_src_mv));
            Size(loctestnum, loctesterr, h_move_sorted, true, 3);
            IsHeap(loctestnum, loctesterr, h_move_sorted, false);
            EqualLinear(loctestnum, loctesterr, h_sorted_src_mv_compare, h_move_sorted, true);
            GetAt(loctestnum, loctesterr, h_move_sorted, true, 0, 5.0);
            Empty(loctestnum, loctesterr, h_sorted_src_mv, true);
        }
        
        // Copy Assignment
        {
            lasd::HeapVec<double> h_assign_dest; 

            // HeapVec empty
            lasd::SortableVector<double> vec_empty_assign_data(0);
            lasd::HeapVec<double> h_empty_assign_src(vec_empty_assign_data);
            h_assign_dest = h_empty_assign_src;
            Empty(loctestnum, loctesterr, h_assign_dest, true); IsHeap(loctestnum, loctesterr, h_assign_dest, true);
            EqualLinear(loctestnum, loctesterr, h_empty_assign_src, h_assign_dest, true);

            // HeapVec size 1
            lasd::SortableVector<double> vec_s1_assign_data(1);
            SetAt(loctestnum, loctesterr, vec_s1_assign_data, true, 0, 100.0);
            lasd::HeapVec<double> h_s1_assign_src(vec_s1_assign_data);
            
            h_assign_dest = h_s1_assign_src; 
            Size(loctestnum, loctesterr, h_assign_dest, true, 1);
            IsHeap(loctestnum, loctesterr, h_assign_dest, true);
            EqualLinear(loctestnum, loctesterr, h_s1_assign_src, h_assign_dest, true);
            GetFront(loctestnum, loctesterr, h_assign_dest, true, 100.0);
            SetAt(loctestnum, loctesterr, h_s1_assign_src, true, 0, 101.0); 
            GetFront(loctestnum, loctesterr, h_assign_dest, true, 100.0); 
            NonEqualLinear(loctestnum, loctesterr, h_s1_assign_src, h_assign_dest, true);

            // HeapVec size > 1 (Heap)
            lasd::SortableVector<double> vec_s3_assign_data(3);
            SetAt(loctestnum, loctesterr, vec_s3_assign_data, true, 0, 5.0);
            SetAt(loctestnum, loctesterr, vec_s3_assign_data, true, 1, 15.0);
            SetAt(loctestnum, loctesterr, vec_s3_assign_data, true, 2, 10.0);;
            lasd::HeapVec<double> h_s3_assign_src(vec_s3_assign_data); 
            
            h_assign_dest = h_s3_assign_src; 
            Size(loctestnum, loctesterr, h_assign_dest, true, 3);
            IsHeap(loctestnum, loctesterr, h_assign_dest, true);
            EqualLinear(loctestnum, loctesterr, h_s3_assign_src, h_assign_dest, true);
            GetFront(loctestnum, loctesterr, h_assign_dest, true, 15.0);
            SetAt(loctestnum, loctesterr, h_s3_assign_src, true, 0, 111.0); 
            GetFront(loctestnum, loctesterr, h_assign_dest, true, 15.0); 
            NonEqualLinear(loctestnum, loctesterr, h_s3_assign_src, h_assign_dest, true);

            // HeapVec size > 1 (not a Heap)
            lasd::SortableVector<double> vec_s3_sorted_assign_data(3);
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_data, true, 0, 20.0);
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_data, true, 1, 5.0);
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_data, true, 2, 10.0);
            lasd::HeapVec<double> h_s3_sorted_assign_src(vec_s3_sorted_assign_data);
            h_s3_sorted_assign_src.Sort(); 
            
            h_assign_dest = h_s3_sorted_assign_src; 
            Size(loctestnum, loctesterr, h_assign_dest, true, 3);
            IsHeap(loctestnum, loctesterr, h_assign_dest, false);
            EqualLinear(loctestnum, loctesterr, h_s3_sorted_assign_src, h_assign_dest, true);
            GetAt(loctestnum, loctesterr, h_assign_dest, true, 0, 5.0);
            SetAt(loctestnum, loctesterr, h_s3_sorted_assign_src, true, 0, 1.0); 
            GetAt(loctestnum, loctesterr, h_assign_dest, true, 0, 5.0); 
            NonEqualLinear(loctestnum, loctesterr, h_s3_sorted_assign_src, h_assign_dest, true);

            // Self-assignment
            lasd::SortableVector<double> vec_self_assign_data(3);
            SetAt(loctestnum, loctesterr, vec_self_assign_data, true, 0, 5.0);
            SetAt(loctestnum, loctesterr, vec_self_assign_data, true, 1, 15.0);
            SetAt(loctestnum, loctesterr, vec_self_assign_data, true, 2, 10.0);
            lasd::HeapVec<double> h_self_heap(vec_self_assign_data);
            lasd::HeapVec<double> h_self_heap_compare(h_self_heap);
            h_self_heap = h_self_heap; 
            EqualLinear(loctestnum, loctesterr, h_self_heap_compare, h_self_heap, true);
            IsHeap(loctestnum, loctesterr, h_self_heap, true);
            GetFront(loctestnum, loctesterr, h_self_heap, true, 15.0);
            lasd::HeapVec<double> h_self_sorted(vec_self_assign_data);
            h_self_sorted.Sort(); 
            lasd::HeapVec<double> h_self_sorted_compare(h_self_sorted);
            h_self_sorted = h_self_sorted; 
            EqualLinear(loctestnum, loctesterr, h_self_sorted_compare, h_self_sorted, true);
            IsHeap(loctestnum, loctesterr, h_self_sorted, false);
            GetAt(loctestnum, loctesterr, h_self_sorted, true, 0, 5.0);
        }

        // Move Assignment
        {
            lasd::HeapVec<double> h_assign_dest_mv; 

            // HeapVec empty
            lasd::SortableVector<double> vec_empty_assign_mv_data(0);
            lasd::HeapVec<double> h_empty_assign_src_mv(vec_empty_assign_mv_data);
            h_assign_dest_mv = move(h_empty_assign_src_mv);
            Empty(loctestnum, loctesterr, h_assign_dest_mv, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_mv, true);
            Empty(loctestnum, loctesterr, h_empty_assign_src_mv, true);
    
            // HeapVec size 1
            lasd::SortableVector<double> vec_s1_assign_mv_data(1);
            SetAt(loctestnum, loctesterr, vec_s1_assign_mv_data, true, 0, 100.0);
            lasd::HeapVec<double> h_s1_assign_src_mv(vec_s1_assign_mv_data);
            lasd::HeapVec<double> h_s1_assign_src_mv_compare(h_s1_assign_src_mv);
            h_assign_dest_mv = move(h_s1_assign_src_mv);
            EqualLinear(loctestnum, loctesterr, h_s1_assign_src_mv_compare, h_assign_dest_mv, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_mv, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_mv, true, 100.0);
            Empty(loctestnum, loctesterr, h_s1_assign_src_mv, true);
        
            // HeapVec size > 1 (Heap)
            lasd::SortableVector<double> vec_s3_assign_mv_data(3);
            SetAt(loctestnum, loctesterr, vec_s3_assign_mv_data, true, 0, 5.0);
            SetAt(loctestnum, loctesterr, vec_s3_assign_mv_data, true, 1, 15.0);
            SetAt(loctestnum, loctesterr, vec_s3_assign_mv_data, true, 2, 10.0);
            lasd::HeapVec<double> h_s3_assign_src_mv(vec_s3_assign_mv_data);
            lasd::HeapVec<double> h_s3_assign_src_mv_compare(h_s3_assign_src_mv);
            h_assign_dest_mv = move(h_s3_assign_src_mv);
            EqualLinear(loctestnum, loctesterr, h_s3_assign_src_mv_compare, h_assign_dest_mv, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_mv, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_mv, true, 15.0);
            Empty(loctestnum, loctesterr, h_s3_assign_src_mv, false);
        
            // HeapVec size > 1 (Not a Heap)
            lasd::SortableVector<double> vec_s3_sorted_assign_mv_data(3);
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_mv_data, true, 0, 20.0);
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_mv_data, true, 1, 5.0);
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_mv_data, true, 2, 10.0);
            lasd::HeapVec<double> h_s3_sorted_assign_src_mv(vec_s3_sorted_assign_mv_data); 
            h_s3_sorted_assign_src_mv.Sort();
            lasd::HeapVec<double> h_s3_sorted_assign_src_mv_compare(h_s3_sorted_assign_src_mv);
            h_assign_dest_mv = move(h_s3_sorted_assign_src_mv);
            EqualLinear(loctestnum, loctesterr, h_s3_sorted_assign_src_mv_compare, h_assign_dest_mv, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_mv, false);
            GetAt(loctestnum, loctesterr, h_assign_dest_mv, true, 0, 5.0);
            Empty(loctestnum, loctesterr, h_s3_sorted_assign_src_mv, false);
        
            // Self-assignment
            // lasd::SortableVector<double> vec_self_assign_mv_data(3);
            // vec_self_assign_mv_data[0]=5.0;
            // vec_self_assign_mv_data[1]=15.0;
            // vec_self_assign_mv_data[2]=10.0;
            // lasd::HeapVec<double> h_self_mv_heap(vec_self_assign_mv_data);
            // lasd::HeapVec<double> h_self_mv_heap_compare(h_self_mv_heap);
            // h_self_mv_heap = move(h_self_mv_heap); 
            // EqualLinear(loctestnum, loctesterr, h_self_mv_heap_compare, h_self_mv_heap, true); 
            // IsHeap(loctestnum, loctesterr, h_self_mv_heap, true);
            // GetFront(loctestnum, loctesterr, h_self_mv_heap, true, 15.0);
        }
        
        // Copy/Move Constructors from SortableVector
        {
            // Copy
            lasd::SortableVector<double> vec_empty(0);
            lasd::HeapVec<double> hv_from_vec_empty(vec_empty);
            Empty(loctestnum, loctesterr, hv_from_vec_empty, true);
            IsHeap(loctestnum, loctesterr, hv_from_vec_empty, true);

            lasd::SortableVector<double> vec_single(1);
            SetAt(loctestnum, loctesterr, vec_single, true, 0, 42.0);
            lasd::HeapVec<double> hv_from_vec_single(vec_single);
            Size(loctestnum, loctesterr, hv_from_vec_single, true, 1);
            IsHeap(loctestnum, loctesterr, hv_from_vec_single, true);
            GetFront(loctestnum, loctesterr, hv_from_vec_single, true, 42.0);

            lasd::SortableVector<double> vec_multi(5);
            SetAt(loctestnum, loctesterr, vec_multi, true, 0, 3.0);
            SetAt(loctestnum, loctesterr, vec_multi, true, 1, 1.0);
            SetAt(loctestnum, loctesterr, vec_multi, true, 2, 4.0);
            SetAt(loctestnum, loctesterr, vec_multi, true, 3, 1.0);
            SetAt(loctestnum, loctesterr, vec_multi, true, 4, 5.0);
            lasd::HeapVec<double> hv_from_vec_multi(vec_multi); 
            Size(loctestnum, loctesterr, hv_from_vec_multi, true, 5);
            IsHeap(loctestnum, loctesterr, hv_from_vec_multi, true);
            GetFront(loctestnum, loctesterr, hv_from_vec_multi, true, 5.0); 

            // Move
            lasd::SortableVector<double> vec_empty_mv(0);
            lasd::HeapVec<double> hv_from_vec_empty_mv(move(vec_empty_mv));
            Empty(loctestnum, loctesterr, hv_from_vec_empty_mv, true);
            IsHeap(loctestnum, loctesterr, hv_from_vec_empty_mv, true);
            Empty(loctestnum, loctesterr, vec_empty_mv, true);

            lasd::SortableVector<double> vec_single_mv(1);
            SetAt(loctestnum, loctesterr, vec_single_mv, true, 0, 42.0);
            lasd::HeapVec<double> hv_from_vec_single_mv(move(vec_single_mv));
            Size(loctestnum, loctesterr, hv_from_vec_single_mv, true, 1);
            IsHeap(loctestnum, loctesterr, hv_from_vec_single_mv, true);
            GetFront(loctestnum, loctesterr, hv_from_vec_single_mv, true, 42.0);
            Empty(loctestnum, loctesterr, vec_single_mv, false);
            
            lasd::SortableVector<double> vec_multi_mv(5);
            SetAt(loctestnum, loctesterr, vec_multi_mv, true, 0, 3.0);
            SetAt(loctestnum, loctesterr, vec_multi_mv, true, 1, 1.0);
            SetAt(loctestnum, loctesterr, vec_multi_mv, true, 2, 4.0);
            SetAt(loctestnum, loctesterr, vec_multi_mv, true, 3, 1.0);
            SetAt(loctestnum, loctesterr, vec_multi_mv, true, 4, 5.0);

            lasd::HeapVec<double> hv_from_vec_multi_mv(move(vec_multi_mv));
            Size(loctestnum, loctesterr, hv_from_vec_multi_mv, true, 5);
            IsHeap(loctestnum, loctesterr, hv_from_vec_multi_mv, true);
            GetFront(loctestnum, loctesterr, hv_from_vec_multi_mv, true, 5.0);
            Empty(loctestnum, loctesterr, vec_multi_mv, false);
        }
        // Copy/Move Constructors from List
        {
            // Copy
            lasd::List<double> lst_empty;
            lasd::HeapVec<double> hv_from_lst_empty(lst_empty);
            Empty(loctestnum, loctesterr, hv_from_lst_empty, true);
            IsHeap(loctestnum, loctesterr, hv_from_lst_empty, true);

            lasd::List<double> lst_single;
            InsertAtBack(loctestnum, loctesterr, lst_single, true, 77.0);
            lasd::HeapVec<double> hv_from_lst_single(lst_single);
            Size(loctestnum, loctesterr, hv_from_lst_single, true, 1);
            IsHeap(loctestnum, loctesterr, hv_from_lst_single, true);
            GetFront(loctestnum, loctesterr, hv_from_lst_single, true, 77.0);

            lasd::List<double> lst_multi;
            InsertAtBack(loctestnum, loctesterr, lst_multi, true, 30.0);
            InsertAtBack(loctestnum, loctesterr, lst_multi, true, 10.0);
            InsertAtBack(loctestnum, loctesterr, lst_multi, true, 40.0);
            InsertAtBack(loctestnum, loctesterr, lst_multi, true, 10.0);
            InsertAtBack(loctestnum, loctesterr, lst_multi, true, 50.0);
            lasd::HeapVec<double> hv_from_lst_multi(lst_multi); 
            Size(loctestnum, loctesterr, hv_from_lst_multi, true, 5);
            IsHeap(loctestnum, loctesterr, hv_from_lst_multi, true);
            GetFront(loctestnum, loctesterr, hv_from_lst_multi, true, 50.0); 
        
            // Move
            lasd::List<double> lst_empty_mv;
            lasd::HeapVec<double> hv_from_lst_empty_mv(move(lst_empty_mv));
            Empty(loctestnum, loctesterr, hv_from_lst_empty_mv, true);
            IsHeap(loctestnum, loctesterr, hv_from_lst_empty_mv, true);
            Empty(loctestnum, loctesterr, lst_empty_mv, true);

            lasd::List<double> lst_single_mv;
            InsertAtBack(loctestnum, loctesterr, lst_single_mv, true, 77.0);
            lasd::HeapVec<double> hv_from_lst_single_mv(move(lst_single_mv));
            Size(loctestnum, loctesterr, hv_from_lst_single_mv, true, 1);
            IsHeap(loctestnum, loctesterr, hv_from_lst_single_mv, true);
            GetFront(loctestnum, loctesterr, hv_from_lst_single_mv, true, 77.0);
            Empty(loctestnum, loctesterr, lst_single_mv, false);
            
            lasd::List<double> lst_multi_mv;
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv, true, 30.0);
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv, true, 10.0);
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv, true, 40.0);
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv, true, 10.0);
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv, true, 50.0);

            lasd::HeapVec<double> hv_from_lst_multi_mv(move(lst_multi_mv));
            Size(loctestnum, loctesterr, hv_from_lst_multi_mv, true, 5);
            IsHeap(loctestnum, loctesterr, hv_from_lst_multi_mv, true);
            GetFront(loctestnum, loctesterr, hv_from_lst_multi_mv, true, 50.0);
            Empty(loctestnum, loctesterr, lst_multi_mv, false);
        }
        // Copy constructor from SetVec
        {
            lasd::SetVec<double> setvec_empty;
            lasd::HeapVec<double> hv_from_setvec_empty(setvec_empty);
            Empty(loctestnum, loctesterr, hv_from_setvec_empty, true);
            IsHeap(loctestnum, loctesterr, hv_from_setvec_empty, true);

            lasd::SetVec<double> setvec_single;
            InsertC(loctestnum, loctesterr, setvec_single, true, 88.0);
            lasd::HeapVec<double> hv_from_setvec_single(setvec_single);
            Size(loctestnum, loctesterr, hv_from_setvec_single, true, 1);
            IsHeap(loctestnum, loctesterr, hv_from_setvec_single, true);
            GetFront(loctestnum, loctesterr, hv_from_setvec_single, true, 88.0);

            lasd::SetVec<double> setvec_multi;
            InsertC(loctestnum, loctesterr, setvec_multi, true, 3.0);
            InsertC(loctestnum, loctesterr, setvec_multi, true, 1.0);
            InsertC(loctestnum, loctesterr, setvec_multi, true, 4.0);
            InsertC(loctestnum, loctesterr, setvec_multi, false, 1.0);
            InsertC(loctestnum, loctesterr, setvec_multi, true, 5.0);
            
            lasd::HeapVec<double> hv_from_setvec_multi(setvec_multi);
            Size(loctestnum, loctesterr, hv_from_setvec_multi, true, 4);
            IsHeap(loctestnum, loctesterr, hv_from_setvec_multi, true);
            GetFront(loctestnum, loctesterr, hv_from_setvec_multi, true, 5.0); 
        }
        // Copy Constructor from SetLst
        {
            lasd::List<double> setlst_data_empty_init;
            lasd::SetLst<double> setlst_empty(setlst_data_empty_init);
            lasd::HeapVec<double> hv_from_setlst_empty(setlst_empty);
            Empty(loctestnum, loctesterr, hv_from_setlst_empty, true);
            IsHeap(loctestnum, loctesterr, hv_from_setlst_empty, true);

            lasd::SetLst<double> setlst_single;
            InsertC(loctestnum, loctesterr, setlst_single, true, 99.0);
            lasd::HeapVec<double> hv_from_setlst_single(setlst_single);
            Size(loctestnum, loctesterr, hv_from_setlst_single, true, 1);
            IsHeap(loctestnum, loctesterr, hv_from_setlst_single, true);
            GetFront(loctestnum, loctesterr, hv_from_setlst_single, true, 99.0);

            lasd::SetLst<double> setlst_multi;
            InsertC(loctestnum, loctesterr, setlst_multi, true, 30.0);
            InsertC(loctestnum, loctesterr, setlst_multi, true, 10.0);
            InsertC(loctestnum, loctesterr, setlst_multi, true, 40.0);
            InsertC(loctestnum, loctesterr, setlst_multi, false, 10.0);
            InsertC(loctestnum, loctesterr, setlst_multi, true, 50.0);

            lasd::HeapVec<double> hv_from_setlst_multi(setlst_multi);
            Size(loctestnum, loctesterr, hv_from_setlst_multi, true, 4);
            IsHeap(loctestnum, loctesterr, hv_from_setlst_multi, true);
            GetFront(loctestnum, loctesterr, hv_from_setlst_multi, true, 50.0); 
        }
        // Copy/Move Assignments from SortableVector
        {
            lasd::HeapVec<double> h_assign_dest_from_vec;

            // Copy Assignment 
            lasd::SortableVector<double> sv_empty_src(0);
            h_assign_dest_from_vec = sv_empty_src;
            Empty(loctestnum, loctesterr, h_assign_dest_from_vec, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_vec, true);

            lasd::SortableVector<double> sv_single_src(1);
            SetAt(loctestnum, loctesterr, sv_single_src, true, 0, 55.0);
            h_assign_dest_from_vec = sv_single_src;
            Size(loctestnum, loctesterr, h_assign_dest_from_vec, true, 1);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_vec, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_vec, true, 55.0);
            SetAt(loctestnum, loctesterr, sv_single_src, true, 0, 56.0); 
            GetFront(loctestnum, loctesterr, h_assign_dest_from_vec, true, 55.0);

            lasd::SortableVector<double> sv_multi_src(3);
            SetAt(loctestnum, loctesterr, sv_multi_src, true, 0, 10.0);
            SetAt(loctestnum, loctesterr, sv_multi_src, true, 1, 30.0);
            SetAt(loctestnum, loctesterr, sv_multi_src, true, 2, 20.0); 
            lasd::HeapVec<double> h_non_empty_dest_vec(sv_single_src); 
            h_non_empty_dest_vec = sv_multi_src;
            Size(loctestnum, loctesterr, h_non_empty_dest_vec, true, 3);
            IsHeap(loctestnum, loctesterr, h_non_empty_dest_vec, true);
            GetFront(loctestnum, loctesterr, h_non_empty_dest_vec, true, 30.0);

            // Move Assignment 
            lasd::SortableVector<double> sv_empty_mv_src(0);
            h_assign_dest_from_vec = move(sv_empty_mv_src); 
            Empty(loctestnum, loctesterr, h_assign_dest_from_vec, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_vec, true);
            Empty(loctestnum, loctesterr, sv_empty_mv_src, true);

            lasd::SortableVector<double> sv_single_mv_src(1);
            SetAt(loctestnum, loctesterr, sv_single_mv_src, true, 0, 66.0);
            h_assign_dest_from_vec = move(sv_single_mv_src);
            Size(loctestnum, loctesterr, h_assign_dest_from_vec, true, 1);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_vec, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_vec, true, 66.0);
            Empty(loctestnum, loctesterr, sv_single_mv_src, false);

            lasd::SortableVector<double> sv_multi_mv_src(3);
            SetAt(loctestnum, loctesterr, sv_multi_mv_src, true, 0, 10.0);
            SetAt(loctestnum, loctesterr, sv_multi_mv_src, true, 1, 30.0);
            SetAt(loctestnum, loctesterr, sv_multi_mv_src, true, 2, 20.0);
            lasd::HeapVec<double> h_non_empty_dest_vec_mv;
            SetAt(loctestnum,loctesterr, h_non_empty_dest_vec_mv, false, 0, 123.0);

            h_non_empty_dest_vec_mv = move(sv_multi_mv_src);
            Size(loctestnum, loctesterr, h_non_empty_dest_vec_mv, true, 3);
            IsHeap(loctestnum, loctesterr, h_non_empty_dest_vec_mv, true);
            GetFront(loctestnum, loctesterr, h_non_empty_dest_vec_mv, true, 30.0);
            Empty(loctestnum, loctesterr, sv_multi_mv_src, false);  
        }
       // Copy/Move Assignments from List
        {
            lasd::HeapVec<double> h_assign_dest_from_lst;

            // Copy Assignment    
            lasd::List<double> lst_empty_src;
            h_assign_dest_from_lst = lst_empty_src;
            Empty(loctestnum, loctesterr, h_assign_dest_from_lst, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_lst, true);

            lasd::List<double> lst_single_src;
            InsertAtBack(loctestnum, loctesterr, lst_single_src, true, 77.0);
            h_assign_dest_from_lst = lst_single_src;
            Size(loctestnum, loctesterr, h_assign_dest_from_lst, true, 1);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_lst, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_lst, true, 77.0);
            InsertAtBack(loctestnum, loctesterr, lst_single_src, true, 78.0); 
            Size(loctestnum, loctesterr, h_assign_dest_from_lst, true, 1);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_lst, true, 77.0);


            lasd::List<double> lst_multi_src;
            InsertAtBack(loctestnum, loctesterr, lst_multi_src, true, 10.0);
            InsertAtBack(loctestnum, loctesterr, lst_multi_src, true, 30.0);
            InsertAtBack(loctestnum, loctesterr, lst_multi_src, true, 20.0);
            lasd::HeapVec<double> h_non_empty_dest_lst(lst_single_src);
            h_non_empty_dest_lst = lst_multi_src;
            Size(loctestnum, loctesterr, h_non_empty_dest_lst, true, 3);
            IsHeap(loctestnum, loctesterr, h_non_empty_dest_lst, true);
            GetFront(loctestnum, loctesterr, h_non_empty_dest_lst, true, 30.0);
        
            // Move Assignment
            lasd::List<double> lst_empty_mv_src;
            h_assign_dest_from_lst = move(lst_empty_mv_src);
            Empty(loctestnum, loctesterr, h_assign_dest_from_lst, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_lst, true);
            Empty(loctestnum, loctesterr, lst_empty_mv_src, true);

            lasd::List<double> lst_single_mv_src;
            InsertAtBack(loctestnum, loctesterr, lst_single_mv_src, true, 88.0);
            h_assign_dest_from_lst = move(lst_single_mv_src);
            Size(loctestnum, loctesterr, h_assign_dest_from_lst, true, 1);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_lst, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_lst, true, 88.0);
            Empty(loctestnum, loctesterr, lst_single_mv_src, false);
            
            lasd::List<double> lst_multi_mv_src;
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv_src, true, 10.0);
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv_src, true, 30.0);
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv_src, true, 20.0);
            lasd::HeapVec<double> h_non_empty_dest_lst_mv;
            h_non_empty_dest_lst_mv = move(lst_multi_mv_src);
            Size(loctestnum, loctesterr, h_non_empty_dest_lst_mv, true, 3);
            IsHeap(loctestnum, loctesterr, h_non_empty_dest_lst_mv, true);
            GetFront(loctestnum, loctesterr, h_non_empty_dest_lst_mv, true, 30.0);
            Empty(loctestnum, loctesterr, lst_multi_mv_src, false);
        }
        // Copy Assignment SetVec 
        {
            lasd::HeapVec<double> h_assign_dest_from_setvec;

            lasd::SetVec<double> setvec_empty_src;
            h_assign_dest_from_setvec = setvec_empty_src;
            Empty(loctestnum, loctesterr, h_assign_dest_from_setvec, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_setvec, true);

            lasd::SetVec<double> setvec_single_src;
            InsertC(loctestnum, loctesterr, setvec_single_src, true, 111.0);
            h_assign_dest_from_setvec = setvec_single_src;
            Size(loctestnum, loctesterr, h_assign_dest_from_setvec, true, 1);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_setvec, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_setvec, true, 111.0);
            InsertC(loctestnum, loctesterr, setvec_single_src, true, 112.0);
            Size(loctestnum, loctesterr, h_assign_dest_from_setvec, true, 1);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_setvec, true, 111.0);

            lasd::SetVec<double> setvec_multi_src;
            InsertC(loctestnum, loctesterr, setvec_multi_src, true, 10.0);
            InsertC(loctestnum, loctesterr, setvec_multi_src, true, 30.0);
            InsertC(loctestnum, loctesterr, setvec_multi_src, true, 20.0);
            InsertC(loctestnum, loctesterr, setvec_multi_src, false, 10.0); 
            lasd::HeapVec<double> h_non_empty_dest_setvec(setvec_single_src); 
            h_non_empty_dest_setvec = setvec_multi_src;
            Size(loctestnum, loctesterr, h_non_empty_dest_setvec, true, 3);
            IsHeap(loctestnum, loctesterr, h_non_empty_dest_setvec, true);
            GetFront(loctestnum, loctesterr, h_non_empty_dest_setvec, true, 30.0);
        }

        // Copy Assignment SetLst
        {
            lasd::HeapVec<double> h_assign_dest_from_setlst;

            lasd::SetLst<double> setlst_empty_src;
            h_assign_dest_from_setlst = setlst_empty_src;
            Empty(loctestnum, loctesterr, h_assign_dest_from_setlst, true);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_setlst, true);

            lasd::SetLst<double> setlst_single_src;
            InsertC(loctestnum, loctesterr, setlst_single_src, true, 222.0);
            h_assign_dest_from_setlst = setlst_single_src;
            Size(loctestnum, loctesterr, h_assign_dest_from_setlst, true, 1);
            IsHeap(loctestnum, loctesterr, h_assign_dest_from_setlst, true);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_setlst, true, 222.0);
            InsertC(loctestnum, loctesterr, setlst_single_src, true, 223.0);
            Size(loctestnum, loctesterr, h_assign_dest_from_setlst, true, 1);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_setlst, true, 222.0);

            lasd::SetLst<double> setlst_multi_src;
            InsertC(loctestnum, loctesterr, setlst_multi_src, true, 10.0);
            InsertC(loctestnum, loctesterr, setlst_multi_src, true, 30.0);
            InsertC(loctestnum, loctesterr, setlst_multi_src, true, 20.0);
            InsertC(loctestnum, loctesterr, setlst_multi_src, false, 10.0);
            lasd::HeapVec<double> h_non_empty_dest_setlst(setlst_single_src);
            h_non_empty_dest_setlst = setlst_multi_src;
            Size(loctestnum, loctesterr, h_non_empty_dest_setlst, true, 3);
            IsHeap(loctestnum, loctesterr, h_non_empty_dest_setlst, true);
            GetFront(loctestnum, loctesterr, h_non_empty_dest_setlst, true, 30.0);
        }

        // Comparison Operators with sort 
        {
            lasd::SortableVector<double> vec_data1(3);
            SetAt(loctestnum, loctesterr, vec_data1, true, 0, 10.0);
            SetAt(loctestnum, loctesterr, vec_data1, true, 1, 20.0);
            SetAt(loctestnum, loctesterr, vec_data1, true, 2, 5.0); 

            lasd::SortableVector<double> vec_data2(3);
            SetAt(loctestnum, loctesterr, vec_data2, true, 0, 10.0);
            SetAt(loctestnum, loctesterr, vec_data2, true, 1, 20.0);
            SetAt(loctestnum, loctesterr, vec_data2, true, 2, 5.0);

            lasd::SortableVector<double> vec_data3(3);
            SetAt(loctestnum, loctesterr, vec_data3, true, 0, 10.0);
            SetAt(loctestnum, loctesterr, vec_data3, true, 1, 25.0);
            SetAt(loctestnum, loctesterr, vec_data3, true, 2, 5.0);

            lasd::SortableVector<double> vec_data4(2);
            SetAt(loctestnum, loctesterr, vec_data4, true, 0, 10.0);
            SetAt(loctestnum, loctesterr, vec_data4, true, 1, 20.0);

            lasd::HeapVec<double> h1(vec_data1);
            lasd::HeapVec<double> h2(vec_data2);
            lasd::HeapVec<double> h3(vec_data1);
            h3.Sort();
            lasd::HeapVec<double> h4(vec_data3);
            lasd::HeapVec<double> h5(vec_data4);
            lasd::HeapVec<double> h_empty1;
            lasd::HeapVec<double> h_empty2;

            EqualLinear(loctestnum, loctesterr, h1, h2, true);   
            NonEqualLinear(loctestnum, loctesterr, h1, h3, true);
            
            lasd::HeapVec<double> h1_sorted_copy(vec_data1);
            h1_sorted_copy.Sort();
            EqualLinear(loctestnum, loctesterr, h3, h1_sorted_copy, true);

            NonEqualLinear(loctestnum, loctesterr, h1, h4, true);
            NonEqualLinear(loctestnum, loctesterr, h1, h5, true);
            EqualLinear(loctestnum, loctesterr, h_empty1, h_empty2, true);
            NonEqualLinear(loctestnum, loctesterr, h1, h_empty1, true);
        }

        //  Sort, Heapify, operator[]
        {
            lasd::SortableVector<double> s_vec_data(5);
            SetAt(loctestnum, loctesterr, s_vec_data, true, 0, 30.0);
            SetAt(loctestnum, loctesterr, s_vec_data, true, 1, 10.0);
            SetAt(loctestnum, loctesterr, s_vec_data, true, 2, 50.0);
            SetAt(loctestnum, loctesterr, s_vec_data, true, 3, 20.0);
            SetAt(loctestnum, loctesterr, s_vec_data, true, 4, 40.0);
           
            lasd::HeapVec<double> hv_ops(s_vec_data);
            IsHeap(loctestnum, loctesterr, hv_ops, true);
            GetFront(loctestnum, loctesterr, hv_ops, true, 50.0);

            hv_ops.Sort();
            IsHeap(loctestnum, loctesterr, hv_ops, false);
            GetAt(loctestnum, loctesterr, hv_ops, true, 0, 10.0);
            GetAt(loctestnum, loctesterr, hv_ops, true, 4, 50.0);

            // Heapify su un heap sorted
            hv_ops.Heapify();
            IsHeap(loctestnum, loctesterr, hv_ops, true);
            GetFront(loctestnum, loctesterr, hv_ops, true, 50.0);

            // Rompo l'heap
            SetAt(loctestnum, loctesterr, hv_ops, true, 1, 5.0);
            IsHeap(loctestnum, loctesterr, hv_ops, false);
            
            hv_ops.Heapify();
            IsHeap(loctestnum, loctesterr, hv_ops, true);
            GetFront(loctestnum, loctesterr, hv_ops, true, 50.0); 

            SetAt(loctestnum, loctesterr, hv_ops, true, 0, 1.0); 
            IsHeap(loctestnum, loctesterr, hv_ops, false);
            hv_ops.Heapify();
            IsHeap(loctestnum, loctesterr, hv_ops, true);
            GetFront(loctestnum, loctesterr, hv_ops, true, 30.0);

            // Sort su un heap con duplicati
            lasd::SortableVector<double> s_vec_dupl_data(5);
            SetAt(loctestnum, loctesterr, s_vec_dupl_data, true, 0, 20.0);
            SetAt(loctestnum, loctesterr, s_vec_dupl_data, true, 1, 10.0);
            SetAt(loctestnum, loctesterr, s_vec_dupl_data, true, 2, 20.0);
            SetAt(loctestnum, loctesterr, s_vec_dupl_data, true, 3, 5.0);
            SetAt(loctestnum, loctesterr, s_vec_dupl_data, true, 4, 20.0);
            lasd::HeapVec<double> hv_dupl(s_vec_dupl_data); 
            IsHeap(loctestnum, loctesterr, hv_dupl, true);
            hv_dupl.Sort();
            IsHeap(loctestnum, loctesterr, hv_dupl, false);
            GetAt(loctestnum, loctesterr, hv_dupl, true, 0, 5.0);
            GetAt(loctestnum, loctesterr, hv_dupl, true, 2, 20.0);
            GetAt(loctestnum, loctesterr, hv_dupl, true, 4, 20.0);
        }

        // Test su const + eccezioni a caso
        {
            lasd::SortableVector<double> const_vec_data(3);
            SetAt(loctestnum, loctesterr, const_vec_data, true, 0, 10.0);
            SetAt(loctestnum, loctesterr, const_vec_data, true, 1, 5.0);
            SetAt(loctestnum, loctesterr, const_vec_data, true, 2, 15.0); 

            const lasd::HeapVec<double> const_hv_empty;

            Empty(loctestnum, loctesterr, const_hv_empty, true);
            Size(loctestnum, loctesterr, const_hv_empty, true, 0);
            IsHeap(loctestnum, loctesterr, const_hv_empty, true);
            Exists(loctestnum, loctesterr, const_hv_empty, false, 1.0);
            
            const lasd::HeapVec<double> const_hv(const_vec_data);

            Empty(loctestnum, loctesterr, const_hv, false);
            Size(loctestnum, loctesterr, const_hv, true, 3);
            IsHeap(loctestnum, loctesterr, const_hv, true);
            GetFront(loctestnum, loctesterr, const_hv, true, 15.0);
            GetAt(loctestnum, loctesterr, const_hv, true, 1, 5.0);
            Exists(loctestnum, loctesterr, const_hv, true, 10.0);
            Exists(loctestnum, loctesterr, const_hv, false, 100.0);
            Traverse(loctestnum, loctesterr, const_hv, true, &TraversePrint<double>);
            Fold(loctestnum, loctesterr, const_hv, true, &FoldAdd<double>, 0.0, 30.0);
        
            lasd::HeapVec<double> hv_exc;
            GetFront(loctestnum, loctesterr, hv_exc, false, 0.0);

            lasd::SortableVector<double> vec_exc_data(1);
            SetAt(loctestnum, loctesterr, vec_exc_data, true, 0, 10.0);
            lasd::HeapVec<double> hv_exc_one(vec_exc_data);

            GetAt(loctestnum, loctesterr, hv_exc_one, false, 1, 0.0); 
            GetAt(loctestnum, loctesterr, hv_exc_one, false, 5, 0.0);

            SetAt(loctestnum, loctesterr, hv_exc_one, false, 1, 20.0);
            SetAt(loctestnum, loctesterr, hv_exc_one, false, 5, 20.0);
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MyHeapVec<double> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

void myhpvec_string(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        cout << endl<< "############################################################################"<< endl;
        cout << endl << "---------------------- Begin of MyHeapVec<string> tests: ----------------------" << endl;

        // EmptyHeapVecDefaultConstructor
        {
            lasd::HeapVec<string> hpvec;
            Empty(loctestnum, loctesterr, hpvec, true);
            Size(loctestnum, loctesterr, hpvec, true, 0);
            IsHeap(loctestnum, loctesterr, hpvec, true);
            hpvec.Heapify();
            IsHeap(loctestnum, loctesterr, hpvec, true);
            GetFront(loctestnum, loctesterr, hpvec, false, string(""));
            GetBack(loctestnum, loctesterr, hpvec, false, string(""));
            GetAt(loctestnum, loctesterr, hpvec, false, 0, string(""));
            SetAt(loctestnum, loctesterr, hpvec, false, 0, string(""));
            Exists(loctestnum, loctesterr, hpvec, false, string("bug"));
            Traverse(loctestnum, loctesterr, hpvec, true, &TraversePrint<string>);
            TraversePreOrder(loctestnum, loctesterr, hpvec, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, hpvec, true, &TraversePrint<string>);
            Fold(loctestnum, loctesterr, hpvec, true, &FoldStringConcatenate, string(""), string(""));
            FoldPreOrder(loctestnum, loctesterr, hpvec, true, &FoldStringConcatenate, string(""), string(""));
            FoldPostOrder(loctestnum, loctesterr, hpvec, true, &FoldStringConcatenate, string(""), string(""));
            Map(loctestnum, loctesterr, hpvec, true, [](string& s){ s += '*'; });
            MapPreOrder(loctestnum, loctesterr, hpvec, true, [](string& s){ s += '*'; });
            MapPostOrder(loctestnum, loctesterr, hpvec, true, [](string& s){ s += '*'; });
            hpvec.Sort();
            IsHeap(loctestnum, loctesterr, hpvec, true);
            hpvec.Clear(); 
            Empty(loctestnum, loctesterr, hpvec, true);
        }

        // ConstructorWithSize(from Vec)
        {
            // SIZE 0 
            lasd::SortableVector<string> emptyvec(0);
            lasd::HeapVec<string> emptyhp(emptyvec);
            Empty(loctestnum, loctesterr, emptyhp, true);
            Size(loctestnum, loctesterr, emptyhp, true, 0);
            IsHeap(loctestnum, loctesterr, emptyhp, true);
            emptyhp.Heapify();
            IsHeap(loctestnum, loctesterr, emptyhp, true);
            GetFront(loctestnum, loctesterr, emptyhp, false, string(""));
            GetAt(loctestnum, loctesterr, emptyhp, false, 0, string(""));
            SetAt(loctestnum, loctesterr, emptyhp, false, 0, string(""));
            Exists(loctestnum, loctesterr, emptyhp, false, string("feature"));
            Fold(loctestnum, loctesterr, emptyhp, true, &FoldStringConcatenate, string("P:"), string("P:"));
            Map(loctestnum, loctesterr, emptyhp, true, [](string& s){ s += '+'; });
            emptyhp.Sort();
            Empty(loctestnum, loctesterr, emptyhp, true);
            emptyhp.Clear();
            Empty(loctestnum, loctesterr, emptyhp, true);

            // SIZE 1
            lasd::SortableVector<string> singlevec(1);
            SetAt(loctestnum, loctesterr, singlevec, true, 0, string("foo"));
            lasd::HeapVec<string> singlehp(singlevec);
            Empty(loctestnum, loctesterr, singlehp, false); Size(loctestnum, loctesterr, singlehp, true, 1);
            IsHeap(loctestnum, loctesterr, singlehp, true);
            GetFront(loctestnum, loctesterr, singlehp, true, string("foo"));
            SetAt(loctestnum, loctesterr, singlehp, true, 0, string("bar")); 
            Exists(loctestnum, loctesterr, singlehp, true, string("bar"));
            Fold(loctestnum, loctesterr, singlehp, true, &FoldStringConcatenate, string("P:"), string("P:bar"));
            Map(loctestnum, loctesterr, singlehp, true, [](string& s){ s += '*'; }); 
            MapPreOrder(loctestnum, loctesterr, singlehp, true, [](string& s){ s += '*'; }); 
            MapPostOrder(loctestnum, loctesterr, singlehp, true, [](string& s){ s += '*'; }); 
            Fold(loctestnum, loctesterr, singlehp, true, &FoldStringConcatenate, string("S:"), string("S:bar***"));
            singlehp.Sort();
            IsHeap(loctestnum, loctesterr, singlehp, true); 
            singlehp.Clear();
            Empty(loctestnum, loctesterr, singlehp, true);

            // SIZE 3
            lasd::SortableVector<string> multivec_init(3);
            SetAt(loctestnum, loctesterr, multivec_init, true, 0, string("nullptr"));
            SetAt(loctestnum, loctesterr, multivec_init, true, 1, string("undefined"));
            SetAt(loctestnum, loctesterr, multivec_init, true, 2, string("NaN"));
            lasd::HeapVec<string> multihp(multivec_init); 
            IsHeap(loctestnum, loctesterr, multihp, true); 
            GetFront(loctestnum, loctesterr, multihp, true, string("undefined"));
            SetAt(loctestnum, loctesterr, multihp, true, 0, string("bug")); 
            multihp.Heapify();
            IsHeap(loctestnum, loctesterr, multihp, true); 
            GetFront(loctestnum, loctesterr, multihp, true, string("nullptr")); 
            FoldPreOrder(loctestnum, loctesterr, multihp, true, &FoldStringConcatenate, string(""), string("nullptrbugNaN")); 
            Map(loctestnum, loctesterr, multihp, true, [](string& s){ s += '*'; }); 
            MapPreOrder(loctestnum, loctesterr, multihp, true, [](string& s){ s += '*'; }); 
            MapPostOrder(loctestnum, loctesterr, multihp, true, [](string& s){ s += '*'; }); 
            FoldPreOrder(loctestnum, loctesterr, multihp, true, &FoldStringConcatenate, string("F:"), string("F:nullptr***bug***NaN***")); 
            multihp.Sort(); 
            GetAt(loctestnum, loctesterr, multihp, true, 0, string("NaN***"));
            GetAt(loctestnum, loctesterr, multihp, true, 1, string("bug***"));
            GetAt(loctestnum, loctesterr, multihp, true, 2, string("nullptr***"));
            IsHeap(loctestnum, loctesterr, multihp, false); 
            multihp.Heapify();
            IsHeap(loctestnum, loctesterr, multihp, true);
            GetFront(loctestnum, loctesterr, multihp, true, string("nullptr***"));
            multihp.Clear();
            Empty(loctestnum, loctesterr, multihp, true);
        }

        // Copy Constructor
        {
            lasd::SortableVector<string> vec_empty_src_data(0);
            lasd::HeapVec<string> h_empty_src(vec_empty_src_data); 
            lasd::HeapVec<string> h_copy_empty(h_empty_src);
            Empty(loctestnum, loctesterr, h_copy_empty, true);
            EqualLinear(loctestnum, loctesterr, h_empty_src, h_copy_empty, true);

            lasd::SortableVector<string> vec_single_src_data(1);
            SetAt(loctestnum, loctesterr, vec_single_src_data, true, 0, string("commit"));
            lasd::HeapVec<string> h_single_src(vec_single_src_data); 
            lasd::HeapVec<string> h_copy_single(h_single_src);
            Size(loctestnum, loctesterr, h_copy_single, true, 1);
            EqualLinear(loctestnum, loctesterr, h_single_src, h_copy_single, true);

            lasd::SortableVector<string> vec_multi_src_data(3);
            SetAt(loctestnum, loctesterr, vec_multi_src_data, true, 0, string("push"));
            SetAt(loctestnum, loctesterr, vec_multi_src_data, true, 1, string("merge"));
            SetAt(loctestnum, loctesterr, vec_multi_src_data, true, 2, string("rebase")); 
            lasd::HeapVec<string> h_multi_src(vec_multi_src_data); 
            lasd::HeapVec<string> h_copy_multi(h_multi_src);
            Size(loctestnum, loctesterr, h_copy_multi, true, 3);
            EqualLinear(loctestnum, loctesterr, h_multi_src, h_copy_multi, true);
            GetFront(loctestnum, loctesterr, h_copy_multi, true, string("rebase"));
            SetAt(loctestnum, loctesterr, h_multi_src, true, 0, string("cherry-pick")); 
            NonEqualLinear(loctestnum, loctesterr, h_multi_src, h_copy_multi, true);
            GetFront(loctestnum, loctesterr, h_copy_multi, true, string("rebase")); 

            lasd::SortableVector<string> vec_sorted_src_data(3);
            SetAt(loctestnum, loctesterr, vec_sorted_src_data, true, 0, string("stack_overflow"));
            SetAt(loctestnum, loctesterr, vec_sorted_src_data, true, 1, string("heap_corruption"));
            SetAt(loctestnum, loctesterr, vec_sorted_src_data, true, 2, string("segfault"));
            lasd::HeapVec<string> h_sorted_src(vec_sorted_src_data); 
            h_sorted_src.Sort(); 
            IsHeap(loctestnum, loctesterr, h_sorted_src, false);
            lasd::HeapVec<string> h_copy_sorted(h_sorted_src);
            IsHeap(loctestnum, loctesterr, h_copy_sorted, false);
            EqualLinear(loctestnum, loctesterr, h_sorted_src, h_copy_sorted, true);
            h_copy_sorted.Heapify();
            EqualLinear(loctestnum, loctesterr, h_sorted_src, h_copy_sorted, false); 
            GetFront(loctestnum, loctesterr, h_copy_sorted, true, string("stack_overflow"));
        }

        // Move Constructor 
        {
            lasd::SortableVector<string> vec_empty_src_mv_data(0);
            lasd::HeapVec<string> h_empty_src_mv(vec_empty_src_mv_data);
            lasd::HeapVec<string> h_move_empty(move(h_empty_src_mv));
            Empty(loctestnum, loctesterr, h_move_empty, true);
            Empty(loctestnum, loctesterr, h_empty_src_mv, true);

            lasd::SortableVector<string> vec_single_src_mv_data(1);
            SetAt(loctestnum, loctesterr, vec_single_src_mv_data, true, 0, string("git"));
            lasd::HeapVec<string> h_single_src_mv(vec_single_src_mv_data);
            lasd::HeapVec<string> h_single_src_mv_compare(h_single_src_mv);
            lasd::HeapVec<string> h_move_single(move(h_single_src_mv));
            EqualLinear(loctestnum, loctesterr, h_single_src_mv_compare, h_move_single, true);
            Empty(loctestnum, loctesterr, h_single_src_mv, true); 

            lasd::SortableVector<string> vec_multi_src_mv_data(3);
            SetAt(loctestnum, loctesterr, vec_multi_src_mv_data, true, 0, string("branch"));
            SetAt(loctestnum, loctesterr, vec_multi_src_mv_data, true, 1, string("tag"));
            SetAt(loctestnum, loctesterr, vec_multi_src_mv_data, true, 2, string("HEAD")); 
            lasd::HeapVec<string> h_multi_src_mv(vec_multi_src_mv_data);
            lasd::HeapVec<string> h_multi_src_mv_compare(h_multi_src_mv);
            lasd::HeapVec<string> h_move_multi(move(h_multi_src_mv));
            EqualLinear(loctestnum, loctesterr, h_multi_src_mv_compare, h_move_multi, true);
            Empty(loctestnum, loctesterr, h_multi_src_mv, true); 

            lasd::SortableVector<string> vec_sorted_src_mv_data_init(3);
            SetAt(loctestnum, loctesterr, vec_sorted_src_mv_data_init, true, 0, string("kernel_panic"));
            SetAt(loctestnum, loctesterr, vec_sorted_src_mv_data_init, true, 1, string("blue_screen"));
            SetAt(loctestnum, loctesterr, vec_sorted_src_mv_data_init, true, 2, string("core_dump"));
            lasd::HeapVec<string> h_sorted_src_mv(vec_sorted_src_mv_data_init);
            h_sorted_src_mv.Sort(); 
            lasd::HeapVec<string> h_sorted_src_mv_compare(h_sorted_src_mv);
            lasd::HeapVec<string> h_move_sorted(move(h_sorted_src_mv));
            EqualLinear(loctestnum, loctesterr, h_sorted_src_mv_compare, h_move_sorted, true);
            Empty(loctestnum, loctesterr, h_sorted_src_mv, true); 
        }

        // Copy Assignment
        {
            lasd::HeapVec<string> h_assign_dest; 
            lasd::SortableVector<string> vec_empty_assign_data(0);
            lasd::HeapVec<string> h_empty_assign_src(vec_empty_assign_data);
            h_assign_dest = h_empty_assign_src;
            Empty(loctestnum, loctesterr, h_assign_dest, true);
            EqualLinear(loctestnum, loctesterr, h_empty_assign_src, h_assign_dest, true);

            lasd::SortableVector<string> vec_s1_assign_data(1);
            SetAt(loctestnum, loctesterr, vec_s1_assign_data, true, 0, string("variable"));
            lasd::HeapVec<string> h_s1_assign_src(vec_s1_assign_data);
            h_assign_dest = h_s1_assign_src; 
            EqualLinear(loctestnum, loctesterr, h_s1_assign_src, h_assign_dest, true);
            SetAt(loctestnum, loctesterr, h_s1_assign_src, true, 0, string("constant")); 
            GetFront(loctestnum, loctesterr, h_assign_dest, true, string("variable")); 
            NonEqualLinear(loctestnum, loctesterr, h_s1_assign_src, h_assign_dest, true);

            lasd::SortableVector<string> vec_s3_assign_data(3);
            SetAt(loctestnum, loctesterr, vec_s3_assign_data, true, 0, string("kernel"));
            SetAt(loctestnum, loctesterr, vec_s3_assign_data, true, 1, string("driver"));
            SetAt(loctestnum, loctesterr, vec_s3_assign_data, true, 2, string("module"));
            lasd::HeapVec<string> h_s3_assign_src(vec_s3_assign_data); 
            h_assign_dest = h_s3_assign_src; 
            EqualLinear(loctestnum, loctesterr, h_s3_assign_src, h_assign_dest, true);
            SetAt(loctestnum, loctesterr, h_s3_assign_src, true, 0, string("interrupt")); 
            GetFront(loctestnum, loctesterr, h_assign_dest, true, string("module")); 
            NonEqualLinear(loctestnum, loctesterr, h_s3_assign_src, h_assign_dest, true);

            lasd::SortableVector<string> vec_s3_sorted_assign_data(3);
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_data, true, 0, string("syntax"));
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_data, true, 1, string("runtime"));
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_data, true, 2, string("logic"));
            lasd::HeapVec<string> h_s3_sorted_assign_src(vec_s3_sorted_assign_data);
            h_s3_sorted_assign_src.Sort();
            h_assign_dest = h_s3_sorted_assign_src; 
            EqualLinear(loctestnum, loctesterr, h_s3_sorted_assign_src, h_assign_dest, true);
            SetAt(loctestnum, loctesterr, h_s3_sorted_assign_src, true, 0, string("algorithm")); 
            GetAt(loctestnum, loctesterr, h_assign_dest, true, 0, string("logic")); 
            NonEqualLinear(loctestnum, loctesterr, h_s3_sorted_assign_src, h_assign_dest, true);
            
            lasd::SortableVector<string> vec_self_assign_data(3);
            SetAt(loctestnum, loctesterr, vec_self_assign_data, true, 0, string("frontend"));
            SetAt(loctestnum, loctesterr, vec_self_assign_data, true, 1, string("backend"));
            SetAt(loctestnum, loctesterr, vec_self_assign_data, true, 2, string("fullstack")); 
            lasd::HeapVec<string> h_self_heap(vec_self_assign_data);
            lasd::HeapVec<string> h_self_heap_compare(h_self_heap);
            h_self_heap = h_self_heap; 
            EqualLinear(loctestnum, loctesterr, h_self_heap_compare, h_self_heap, true);
            GetFront(loctestnum, loctesterr, h_self_heap, true, string("fullstack")); 
        }

        // Move Assignment
        {
            lasd::HeapVec<string> h_assign_dest_mv;
            lasd::SortableVector<string> vec_empty_assign_mv_data(0);
            lasd::HeapVec<string> h_empty_assign_src_mv(vec_empty_assign_mv_data);
            h_assign_dest_mv = move(h_empty_assign_src_mv);
            Empty(loctestnum, loctesterr, h_assign_dest_mv, true);
            Empty(loctestnum, loctesterr, h_empty_assign_src_mv, true);
    
            lasd::SortableVector<string> vec_s1_assign_mv_data(1);
            SetAt(loctestnum, loctesterr, vec_s1_assign_mv_data, true, 0, string("pointer"));
            lasd::HeapVec<string> h_s1_assign_src_mv(vec_s1_assign_mv_data);
            lasd::HeapVec<string> h_s1_assign_src_mv_compare(h_s1_assign_src_mv);
            h_assign_dest_mv = move(h_s1_assign_src_mv);
            EqualLinear(loctestnum, loctesterr, h_s1_assign_src_mv_compare, h_assign_dest_mv, true);
            Empty(loctestnum, loctesterr, h_s1_assign_src_mv, true);
        
            lasd::SortableVector<string> vec_s3_assign_mv_data(3);
            SetAt(loctestnum, loctesterr, vec_s3_assign_mv_data, true, 0, string("reference"));
            SetAt(loctestnum, loctesterr, vec_s3_assign_mv_data, true, 1, string("value"));
            SetAt(loctestnum, loctesterr, vec_s3_assign_mv_data, true, 2, string("address")); 
            lasd::HeapVec<string> h_s3_assign_src_mv(vec_s3_assign_mv_data); 
            lasd::HeapVec<string> h_s3_assign_src_mv_compare(h_s3_assign_src_mv);
            h_assign_dest_mv = move(h_s3_assign_src_mv);
            EqualLinear(loctestnum, loctesterr, h_s3_assign_src_mv_compare, h_assign_dest_mv, true);
            Empty(loctestnum, loctesterr, h_s3_assign_src_mv, false);
        
            lasd::SortableVector<string> vec_s3_sorted_assign_mv_data(3);
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_mv_data, true, 0, string("compile"));
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_mv_data, true, 1, string("link"));
            SetAt(loctestnum, loctesterr, vec_s3_sorted_assign_mv_data, true, 2, string("execute"));
            lasd::HeapVec<string> h_s3_sorted_assign_src_mv(vec_s3_sorted_assign_mv_data);
            h_s3_sorted_assign_src_mv.Sort();
            lasd::HeapVec<string> h_s3_sorted_assign_src_mv_compare(h_s3_sorted_assign_src_mv);
            h_assign_dest_mv = move(h_s3_sorted_assign_src_mv);
            EqualLinear(loctestnum, loctesterr, h_s3_sorted_assign_src_mv_compare, h_assign_dest_mv, true);
            Empty(loctestnum, loctesterr, h_s3_sorted_assign_src_mv, false); 
        
            // lasd::SortableVector<string> vec_self_mv_data(3);
            // SetAt(loctestnum, loctesterr, vec_self_mv_data, true, 0, string("debug")); 
            // SetAt(loctestnum, loctesterr, vec_self_mv_data, true, 1, string("test")); 
            // SetAt(loctestnum, loctesterr, vec_self_mv_data, true, 2, string("deploy"));
            // lasd::HeapVec<string> h_self_mv_heap(vec_self_mv_data); 
            // lasd::HeapVec<string> h_self_mv_heap_compare(h_self_mv_heap);
            // h_self_mv_heap = move(h_self_mv_heap); 
            // EqualLinear(loctestnum, loctesterr, h_self_mv_heap_compare, h_self_mv_heap, true); 
            // IsHeap(loctestnum, loctesterr, h_self_mv_heap, true);
            // GetFront(loctestnum, loctesterr, h_self_mv_heap, true, string("test"));
        }

        // Copy/Move Constructors from SortableVector
        {
            lasd::SortableVector<string> vec_empty(0);
            lasd::HeapVec<string> hv_from_vec_empty(vec_empty);
            Empty(loctestnum, loctesterr, hv_from_vec_empty, true);
            lasd::SortableVector<string> vec_single(1);
            SetAt(loctestnum, loctesterr, vec_single, true, 0, string("lambda"));
            lasd::HeapVec<string> hv_from_vec_single(vec_single);
            GetFront(loctestnum, loctesterr, hv_from_vec_single, true, string("lambda"));
            lasd::SortableVector<string> vec_multi(3);
            SetAt(loctestnum, loctesterr, vec_multi, true, 0, string("template"));
            SetAt(loctestnum, loctesterr, vec_multi, true, 1, string("class"));
            SetAt(loctestnum, loctesterr, vec_multi, true, 2, string("struct"));
            lasd::HeapVec<string> hv_from_vec_multi(vec_multi);
            GetFront(loctestnum, loctesterr, hv_from_vec_multi, true, string("template"));

            lasd::SortableVector<string> vec_empty_mv(0);
            lasd::HeapVec<string> hv_from_vec_empty_mv(move(vec_empty_mv));
            Empty(loctestnum, loctesterr, hv_from_vec_empty_mv, true);
            Empty(loctestnum, loctesterr, vec_empty_mv, true);
            lasd::SortableVector<string> vec_single_mv(1);
            SetAt(loctestnum, loctesterr, vec_single_mv, true, 0, string("override"));
            lasd::HeapVec<string> hv_from_vec_single_mv(move(vec_single_mv));
            GetFront(loctestnum, loctesterr, hv_from_vec_single_mv, true, string("override"));
            Empty(loctestnum, loctesterr, vec_single_mv, false); 
            lasd::SortableVector<string> vec_multi_mv(3);
            SetAt(loctestnum, loctesterr, vec_multi_mv, true, 0, string("virtual")); 
            SetAt(loctestnum, loctesterr, vec_multi_mv, true, 1, string("static"));
            SetAt(loctestnum, loctesterr, vec_multi_mv, true, 2, string("const"));
            lasd::HeapVec<string> hv_from_vec_multi_mv(move(vec_multi_mv));
            GetFront(loctestnum, loctesterr, hv_from_vec_multi_mv, true, string("virtual"));
            Empty(loctestnum, loctesterr, vec_multi_mv, false); 
        }

        // Copy/Move Constructors from List
        {
            lasd::List<string> lst_empty;
            lasd::HeapVec<string> hv_from_lst_empty(lst_empty);
            Empty(loctestnum, loctesterr, hv_from_lst_empty, true);
            lasd::List<string> lst_single;
            InsertAtBack(loctestnum, loctesterr, lst_single, true, string("API"));
            lasd::HeapVec<string> hv_from_lst_single(lst_single);
            GetFront(loctestnum, loctesterr, hv_from_lst_single, true, string("API"));
            lasd::List<string> lst_multi;
            InsertAtBack(loctestnum, loctesterr, lst_multi, true, string("SDK"));
            InsertAtBack(loctestnum, loctesterr, lst_multi, true, string("IDE"));
            InsertAtBack(loctestnum, loctesterr, lst_multi, true, string("VCS"));
            lasd::HeapVec<string> hv_from_lst_multi(lst_multi);
            GetFront(loctestnum, loctesterr, hv_from_lst_multi, true, string("VCS"));
        
            lasd::List<string> lst_empty_mv;
            lasd::HeapVec<string> hv_from_lst_empty_mv(move(lst_empty_mv));
            Empty(loctestnum, loctesterr, hv_from_lst_empty_mv, true);
            Empty(loctestnum, loctesterr, lst_empty_mv, true);
            lasd::List<string> lst_single_mv;
            InsertAtBack(loctestnum, loctesterr, lst_single_mv, true, string("JSON"));
            lasd::HeapVec<string> hv_from_lst_single_mv(move(lst_single_mv));
            GetFront(loctestnum, loctesterr, hv_from_lst_single_mv, true, string("JSON"));
            Empty(loctestnum, loctesterr, lst_single_mv, false); 
            lasd::List<string> lst_multi_mv;
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv, true, string("XML"));
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv, true, string("YAML"));
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv, true, string("CSV"));
            lasd::HeapVec<string> hv_from_lst_multi_mv(move(lst_multi_mv));
            GetFront(loctestnum, loctesterr, hv_from_lst_multi_mv, true, string("YAML"));
            Empty(loctestnum, loctesterr, lst_multi_mv, false); 
        }

        // Copy constructor from SetVec
        {
            lasd::SetVec<string> setvec_empty;
            lasd::HeapVec<string> hv_from_setvec_empty(setvec_empty);
            Empty(loctestnum, loctesterr, hv_from_setvec_empty, true);
            lasd::SetVec<string> setvec_single;
            InsertC(loctestnum, loctesterr, setvec_single, true, string("algorithm"));
            lasd::HeapVec<string> hv_from_setvec_single(setvec_single);
            GetFront(loctestnum, loctesterr, hv_from_setvec_single, true, string("algorithm"));
            lasd::SetVec<string> setvec_multi;
            InsertC(loctestnum, loctesterr, setvec_multi, true, string("data_structure"));
            InsertC(loctestnum, loctesterr, setvec_multi, true, string("array"));
            InsertC(loctestnum, loctesterr, setvec_multi, true, string("list"));
            InsertC(loctestnum, loctesterr, setvec_multi, true, string("tree")); 
            lasd::HeapVec<string> hv_from_setvec_multi(setvec_multi);
            GetFront(loctestnum, loctesterr, hv_from_setvec_multi, true, string("tree"));
            Size(loctestnum, loctesterr, hv_from_setvec_multi, true, 4);
        }

        // Copy Constructor from SetLst
        {
            lasd::SetLst<string> setlst_empty;
            lasd::HeapVec<string> hv_from_setlst_empty(setlst_empty);
            Empty(loctestnum, loctesterr, hv_from_setlst_empty, true);
            lasd::SetLst<string> setlst_single;
            InsertC(loctestnum, loctesterr, setlst_single, true, string("singleton"));
            lasd::HeapVec<string> hv_from_setlst_single(setlst_single);
            GetFront(loctestnum, loctesterr, hv_from_setlst_single, true, string("singleton"));
            lasd::SetLst<string> setlst_multi;
            InsertC(loctestnum, loctesterr, setlst_multi, true, string("factory"));
            InsertC(loctestnum, loctesterr, setlst_multi, true, string("builder"));
            InsertC(loctestnum, loctesterr, setlst_multi, true, string("prototype"));
            InsertC(loctestnum, loctesterr, setlst_multi, true, string("adapter")); 
            lasd::HeapVec<string> hv_from_setlst_multi(setlst_multi);
            GetFront(loctestnum, loctesterr, hv_from_setlst_multi, true, string("prototype"));
            Size(loctestnum, loctesterr, hv_from_setlst_multi, true, 4);
        }

        // Copy/Move Assignments from SortableVector
        {
            lasd::HeapVec<string> h_assign_dest_from_vec;
            lasd::SortableVector<string> sv_empty_src(0);
            h_assign_dest_from_vec = sv_empty_src;
            Empty(loctestnum, loctesterr, h_assign_dest_from_vec, true);
            lasd::SortableVector<string> sv_single_src(1);
            SetAt(loctestnum, loctesterr, sv_single_src, true, 0, string("polymorphism"));
            h_assign_dest_from_vec = sv_single_src;
            GetFront(loctestnum, loctesterr, h_assign_dest_from_vec, true, string("polymorphism"));
            SetAt(loctestnum, loctesterr, sv_single_src, true, 0, string("inheritance"));
            GetFront(loctestnum, loctesterr, h_assign_dest_from_vec, true, string("polymorphism"));
            lasd::SortableVector<string> sv_multi_src(3);
            SetAt(loctestnum, loctesterr, sv_multi_src, true, 0, string("encapsulation"));
            SetAt(loctestnum, loctesterr, sv_multi_src, true, 1, string("abstraction"));
            SetAt(loctestnum, loctesterr, sv_multi_src, true, 2, string("interface")); 
            h_assign_dest_from_vec = sv_multi_src;
            GetFront(loctestnum, loctesterr, h_assign_dest_from_vec, true, string("interface"));
 
            lasd::SortableVector<string> sv_empty_mv_src(0); 
            h_assign_dest_from_vec = move(sv_empty_mv_src); 
            Empty(loctestnum, loctesterr, h_assign_dest_from_vec, true); 
            Empty(loctestnum, loctesterr, sv_empty_mv_src, true);
            lasd::SortableVector<string> sv_single_mv_src(1); 
            SetAt(loctestnum, loctesterr, sv_single_mv_src, true, 0, string("SOLID"));
            h_assign_dest_from_vec = move(sv_single_mv_src); 
            GetFront(loctestnum, loctesterr, h_assign_dest_from_vec, true, string("SOLID")); 
            Empty(loctestnum, loctesterr, sv_single_mv_src, false); 
            lasd::SortableVector<string> sv_multi_mv_src(3); 
            SetAt(loctestnum, loctesterr, sv_multi_mv_src, true, 0, string("DRY")); 
            SetAt(loctestnum, loctesterr, sv_multi_mv_src, true, 1, string("KISS")); 
            SetAt(loctestnum, loctesterr, sv_multi_mv_src, true, 2, string("YAGNI")); 
            h_assign_dest_from_vec = move(sv_multi_mv_src); 
            GetFront(loctestnum, loctesterr, h_assign_dest_from_vec, true, string("YAGNI")); 
            Empty(loctestnum, loctesterr, sv_multi_mv_src, false); 
        }

        // Copy/Move Assignments from List
        {
            lasd::HeapVec<string> h_assign_dest_from_lst;
            lasd::List<string> lst_empty_src; 
            h_assign_dest_from_lst = lst_empty_src; 
            Empty(loctestnum, loctesterr, h_assign_dest_from_lst, true);
            lasd::List<string> lst_single_src; 
            InsertAtBack(loctestnum, loctesterr, lst_single_src, true, string("refactor"));
            h_assign_dest_from_lst = lst_single_src;
            GetFront(loctestnum, loctesterr, h_assign_dest_from_lst, true, string("refactor"));
            InsertAtBack(loctestnum, loctesterr, lst_single_src, true, string("optimize")); 
            GetFront(loctestnum, loctesterr, h_assign_dest_from_lst, true, string("refactor"));
            lasd::List<string> lst_multi_src; 
            InsertAtBack(loctestnum, loctesterr, lst_multi_src, true, string("code_review")); 
            InsertAtBack(loctestnum, loctesterr, lst_multi_src, true, string("pair_programming")); 
            InsertAtBack(loctestnum, loctesterr, lst_multi_src, true, string("TDD")); 
            h_assign_dest_from_lst = lst_multi_src; 
            GetFront(loctestnum, loctesterr, h_assign_dest_from_lst, true, string("pair_programming"));
        
            lasd::List<string> lst_empty_mv_src;
            h_assign_dest_from_lst = move(lst_empty_mv_src); 
            Empty(loctestnum, loctesterr, h_assign_dest_from_lst, true); 
            Empty(loctestnum, loctesterr, lst_empty_mv_src, true);
            lasd::List<string> lst_single_mv_src; 
            InsertAtBack(loctestnum, loctesterr, lst_single_mv_src, true, string("CI_CD"));
            h_assign_dest_from_lst = move(lst_single_mv_src);
            GetFront(loctestnum, loctesterr, h_assign_dest_from_lst, true, string("CI_CD")); 
            Empty(loctestnum, loctesterr, lst_single_mv_src, false); 
            lasd::List<string> lst_multi_mv_src; 
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv_src, true, string("devops")); 
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv_src, true, string("SRE")); 
            InsertAtBack(loctestnum, loctesterr, lst_multi_mv_src, true, string("monitoring")); 
            h_assign_dest_from_lst = move(lst_multi_mv_src); 
            GetFront(loctestnum, loctesterr, h_assign_dest_from_lst, true, string("monitoring"));
            Empty(loctestnum, loctesterr, lst_multi_mv_src, false); 
        }

        // Copy Assignment SetVec 
        {
            lasd::HeapVec<string> h_assign_dest_from_setvec;
            lasd::SetVec<string> setvec_empty_src; 
            h_assign_dest_from_setvec = setvec_empty_src; 
            Empty(loctestnum, loctesterr, h_assign_dest_from_setvec, true);
            lasd::SetVec<string> setvec_single_src; 
            InsertC(loctestnum, loctesterr, setvec_single_src, true, string("recursion"));
            h_assign_dest_from_setvec = setvec_single_src; 
            GetFront(loctestnum, loctesterr, h_assign_dest_from_setvec, true, string("recursion"));
            InsertC(loctestnum, loctesterr, setvec_single_src, true, string("iteration")); 
            GetFront(loctestnum, loctesterr, h_assign_dest_from_setvec, true, string("recursion"));
            lasd::SetVec<string> setvec_multi_src; 
            InsertC(loctestnum, loctesterr, setvec_multi_src, true, string("binary_search")); 
            InsertC(loctestnum, loctesterr, setvec_multi_src, true, string("hash_table")); 
            InsertC(loctestnum, loctesterr, setvec_multi_src, true, string("graph"));
            h_assign_dest_from_setvec = setvec_multi_src; 
            GetFront(loctestnum, loctesterr, h_assign_dest_from_setvec, true, string("hash_table")); 
            Size(loctestnum, loctesterr, h_assign_dest_from_setvec, true, 3);
        }

        // Copy Assignment SetLst
        {
            lasd::HeapVec<string> h_assign_dest_from_setlst;
            lasd::SetLst<string> setlst_empty_src; 
            h_assign_dest_from_setlst = setlst_empty_src; 
            Empty(loctestnum, loctesterr, h_assign_dest_from_setlst, true);
            lasd::SetLst<string> setlst_single_src; 
            InsertC(loctestnum, loctesterr, setlst_single_src, true, string("mutex"));
            h_assign_dest_from_setlst = setlst_single_src; 
            GetFront(loctestnum, loctesterr, h_assign_dest_from_setlst, true, string("mutex"));
            InsertC(loctestnum, loctesterr, setlst_single_src, true, string("semaphore")); 
            GetFront(loctestnum, loctesterr, h_assign_dest_from_setlst, true, string("mutex"));
            lasd::SetLst<string> setlst_multi_src; 
            InsertC(loctestnum, loctesterr, setlst_multi_src, true, string("thread")); 
            InsertC(loctestnum, loctesterr, setlst_multi_src, true, string("process")); 
            InsertC(loctestnum, loctesterr, setlst_multi_src, true, string("coroutine"));
            h_assign_dest_from_setlst = setlst_multi_src; 
            GetFront(loctestnum, loctesterr, h_assign_dest_from_setlst, true, string("thread")); 
            Size(loctestnum, loctesterr, h_assign_dest_from_setlst, true, 3);
        }

        // Comparison Operators with sort 
        {
            lasd::SortableVector<string> vec_data1(3);
            SetAt(loctestnum, loctesterr, vec_data1, true, 0, string("beta")); 
            SetAt(loctestnum, loctesterr, vec_data1, true, 1, string("gamma")); 
            SetAt(loctestnum, loctesterr, vec_data1, true, 2, string("alpha")); 
            lasd::SortableVector<string> vec_data2(3); 
            SetAt(loctestnum, loctesterr, vec_data2, true, 0, string("beta")); 
            SetAt(loctestnum, loctesterr, vec_data2, true, 1, string("gamma")); 
            SetAt(loctestnum, loctesterr, vec_data2, true, 2, string("alpha"));
            lasd::SortableVector<string> vec_data3(3); 
            SetAt(loctestnum, loctesterr, vec_data3, true, 0, string("beta")); 
            SetAt(loctestnum, loctesterr, vec_data3, true, 1, string("delta")); 
            SetAt(loctestnum, loctesterr, vec_data3, true, 2, string("alpha"));

            lasd::HeapVec<string> h1(vec_data1); 
            lasd::HeapVec<string> h2(vec_data2); 
            lasd::HeapVec<string> h3(vec_data1); 

            h3.Sort(); 

            lasd::HeapVec<string> h4(vec_data3); 
            lasd::HeapVec<string> h_empty1; 
            lasd::HeapVec<string> h_empty2;

            EqualLinear(loctestnum, loctesterr, h1, h2, true); 
            NonEqualLinear(loctestnum, loctesterr, h1, h3, true);
            lasd::HeapVec<string> h1_sorted_copy(vec_data1); 
            h1_sorted_copy.Sort(); 
            EqualLinear(loctestnum, loctesterr, h3, h1_sorted_copy, true);
            NonEqualLinear(loctestnum, loctesterr, h1, h4, true);
            NonEqualLinear(loctestnum, loctesterr, h1, h_empty1, true);
            EqualLinear(loctestnum, loctesterr, h_empty1, h_empty2, true);
        }

        //  Sort, Heapify, operator[]
        {
            lasd::SortableVector<string> s_vec_data(5);
            SetAt(loctestnum, loctesterr, s_vec_data, true, 0, string("echo"));
            SetAt(loctestnum, loctesterr, s_vec_data, true, 1, string("alpha"));
            SetAt(loctestnum, loctesterr, s_vec_data, true, 2, string("golf"));
            SetAt(loctestnum, loctesterr, s_vec_data, true, 3, string("charlie"));
            SetAt(loctestnum, loctesterr, s_vec_data, true, 4, string("foxtrot"));
            lasd::HeapVec<string> hv_ops(s_vec_data);
            GetFront(loctestnum, loctesterr, hv_ops, true, string("golf")); 
            hv_ops.Sort();
            GetAt(loctestnum, loctesterr, hv_ops, true, 0, string("alpha"));
            IsHeap(loctestnum, loctesterr, hv_ops, false);
            hv_ops.Heapify();
            GetFront(loctestnum, loctesterr, hv_ops, true, string("golf"));
            IsHeap(loctestnum, loctesterr, hv_ops, true);
            SetAt(loctestnum, loctesterr, hv_ops, true, 1, string("zulu"));
            IsHeap(loctestnum, loctesterr, hv_ops, false); 
            hv_ops.Heapify();
            GetFront(loctestnum, loctesterr, hv_ops, true, string("zulu"));
            IsHeap(loctestnum, loctesterr, hv_ops, true); 
            SetAt(loctestnum, loctesterr, hv_ops, true, 0, string("aaa"));
            IsHeap(loctestnum, loctesterr, hv_ops, false); 
            hv_ops.Heapify();
            GetFront(loctestnum, loctesterr, hv_ops, true, string("golf"));
            IsHeap(loctestnum, loctesterr, hv_ops, true);
            
            lasd::SortableVector<string> s_vec_dupl_data(3); 
            SetAt(loctestnum, loctesterr, s_vec_dupl_data, true, 0, string("delta")); 
            SetAt(loctestnum, loctesterr, s_vec_dupl_data, true, 1, string("bravo")); 
            SetAt(loctestnum, loctesterr, s_vec_dupl_data, true, 2, string("delta"));
            lasd::HeapVec<string> hv_dupl(s_vec_dupl_data); 
            hv_dupl.Sort();
            GetAt(loctestnum, loctesterr, hv_dupl, true, 0, string("bravo")); 
            GetAt(loctestnum, loctesterr, hv_dupl, true, 2, string("delta"));
        }

        // Test su const + eccezioni
        {
            lasd::SortableVector<string> const_vec_data(3); 
            SetAt(loctestnum, loctesterr, const_vec_data, true, 0, string("final")); 
            SetAt(loctestnum, loctesterr, const_vec_data, true, 1, string("const")); 
            SetAt(loctestnum, loctesterr, const_vec_data, true, 2, string("static_final")); 
            
            const lasd::HeapVec<std::string> const_hv_empty; 
            Empty(loctestnum, loctesterr, const_hv_empty, true); 
            Size(loctestnum, loctesterr, const_hv_empty, true, 0);
            IsHeap(loctestnum, loctesterr, const_hv_empty, true); 
            
            const lasd::HeapVec<string> const_hv(const_vec_data); 
            GetFront(loctestnum, loctesterr, const_hv, true, string("static_final")); 
            Exists(loctestnum, loctesterr, const_hv, true, string("final"));
            Traverse(loctestnum,loctesterr,const_hv,true,&TraversePrint<string>);
            Fold(loctestnum, loctesterr, const_hv, true, &FoldStringConcatenate, string("P:"), string("P:static_finalconstfinal")); 
        
            lasd::HeapVec<string> hv_exc;
            GetFront(loctestnum, loctesterr, hv_exc, false, string("")); 
            lasd::SortableVector<string> vec_exc_data(1);
            SetAt(loctestnum, loctesterr, vec_exc_data, true, 0, string("exception"));
            lasd::HeapVec<string> hv_exc_one(vec_exc_data);
            GetAt(loctestnum, loctesterr, hv_exc_one, false, 1, string("")); 
            SetAt(loctestnum, loctesterr, hv_exc_one, false, 5, string("")); 
            SetAt(loctestnum, loctesterr, hv_exc_one, false, 1, string("no_throw")); 
            SetAt(loctestnum, loctesterr, hv_exc_one, false, 5, string("no_throw_either"));
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MyHeapVec<string> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

/* ************************************************************************** */

void hpvec_test(uint &testnum, uint &testerr)
{
    myhpvec_int(testnum, testerr);
    myhpvec_double(testnum, testerr);
    myhpvec_string(testnum, testerr);
}