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
        // Default constructor and basic checks
        {
            lasd::SetLst<int> s_default;
            Empty(loctestnum, loctesterr, s_default, true);
            Size(loctestnum, loctesterr, s_default, true, 0);
            Min(loctestnum, loctesterr, s_default, false, 0); 
            Max(loctestnum, loctesterr, s_default, false, 0); 
            MinNRemove(loctestnum, loctesterr, s_default, false, 0);
            Size(loctestnum, loctesterr, s_default, true, 0);
            MaxNRemove(loctestnum, loctesterr, s_default, false, 0);
            Size(loctestnum, loctesterr, s_default, true, 0);
            GetAt(loctestnum, loctesterr, s_default, false, 0, 0); 
            Predecessor(loctestnum, loctesterr, s_default, false, 10, 0);
            Successor(loctestnum, loctesterr, s_default, false, 10, 0);
            Exists(loctestnum, loctesterr, s_default, false, 5);
            PredecessorNRemove(loctestnum, loctesterr, s_default, false, 10, 0);
            Size(loctestnum, loctesterr, s_default, true, 0);
            SuccessorNRemove(loctestnum, loctesterr, s_default, false, 10, 0);
            Size(loctestnum, loctesterr, s_default, true, 0);
        }

        // Single Element Set
        {
            lasd::SetLst<int> s_single;
            InsertC(loctestnum, loctesterr, s_single, true, 10);
            Empty(loctestnum, loctesterr, s_single, false);
            Size(loctestnum, loctesterr, s_single, true, 1);
            Min(loctestnum, loctesterr, s_single, true, 10);
            Max(loctestnum, loctesterr, s_single, true, 10);
            GetAt(loctestnum, loctesterr, s_single, true, 0, 10);
            Exists(loctestnum, loctesterr, s_single, true, 10);
            Exists(loctestnum, loctesterr, s_single, false, 5);
            
            Predecessor(loctestnum, loctesterr, s_single, false, 10, 0); 
            Successor(loctestnum, loctesterr, s_single, false, 10, 0);   
            Predecessor(loctestnum, loctesterr, s_single, false, 5, 0);
            Successor(loctestnum, loctesterr, s_single, false, 15, 0);

            PredecessorNRemove(loctestnum, loctesterr, s_single, false, 10, 0);
            Size(loctestnum, loctesterr, s_single, true, 1);
            SuccessorNRemove(loctestnum, loctesterr, s_single, false, 10, 0);
            Size(loctestnum, loctesterr, s_single, true, 1);

            try { loctestnum++; s_single.RemovePredecessor(10); testerr++; cout << endl << "s_single.RemovePredecessor(10) did not throw" << endl;} catch (const std::logic_error&) {} catch (...) {loctestnum++; testerr++; cout << endl << "ERR! s_single.RemovePredecessor(10) wrong exception" << endl;}
            try { loctestnum++; s_single.RemoveSuccessor(10); testerr++; cout << endl << "s_single.RemoveSuccessor(10) did not throw" << endl;} catch (const std::logic_error&) {} catch (...) {loctestnum++; testerr++; cout << endl << "ERR! s_single.RemoveSuccessor(10) wrong exception" << endl;}
            Size(loctestnum, loctesterr, s_single, true, 1);

            Remove(loctestnum, loctesterr, s_single, true, 10);
            Empty(loctestnum, loctesterr, s_single, true);
            s_single.Clear();
        }

        // Multi-Element Set
        {
            lasd::SetLst<int> s1;
            InsertC(loctestnum, loctesterr, s1, true, 10); 
            InsertC(loctestnum, loctesterr, s1, true, 5);  
            InsertC(loctestnum, loctesterr, s1, true, 15); 
            InsertC(loctestnum, loctesterr, s1, true, 20); 
            Size(loctestnum, loctesterr, s1, true, 4); 
            GetAt(loctestnum, loctesterr, s1, true, 0, 5);
            GetAt(loctestnum, loctesterr, s1, true, 3, 20);
            Min(loctestnum, loctesterr, s1, true, 5);
            Max(loctestnum, loctesterr, s1, true, 20);

            Predecessor(loctestnum, loctesterr, s1, true, 15, 10);
            Successor(loctestnum, loctesterr, s1, true, 10, 15);
            PredecessorNRemove(loctestnum, loctesterr, s1, true, 20, 15); 
            Size(loctestnum, loctesterr, s1, true, 3);
            Exists(loctestnum, loctesterr, s1, false, 15);
            SuccessorNRemove(loctestnum, loctesterr, s1, true, 5, 10);  
            Size(loctestnum, loctesterr, s1, true, 2);
            Exists(loctestnum, loctesterr, s1, false, 10);

            s1.Clear();
            InsertC(loctestnum, loctesterr, s1, true, 10);
            InsertC(loctestnum, loctesterr, s1, true, 20);
            InsertC(loctestnum, loctesterr, s1, true, 30);
            try { loctestnum++; s1.RemovePredecessor(20); } catch(...) {loctestnum++; testerr++; cout << endl << "s1.RemovePredecessor(20) threw an unexpected exception" << endl;} 
            Size(loctestnum, loctesterr, s1, true, 2);
            Exists(loctestnum, loctesterr, s1, false, 10);

            try { loctestnum++; s1.RemoveSuccessor(20); } catch(...) {loctestnum++; testerr++; cout << endl << "s1.RemoveSuccessor(20) threw an unexpected exception" << endl;} 
            Size(loctestnum, loctesterr, s1, true, 1);
            Exists(loctestnum, loctesterr, s1, false, 30);
            s1.Clear();
        }

        // Insertions
        {
            lasd::SetLst<int> s_ins;
            for (int i = 0; i < 50; ++i)
                InsertC(loctestnum, loctesterr, s_ins, true, i * 3);

            for (int i = 0; i < 50; ++i)
                InsertC(loctestnum, loctesterr, s_ins, false, i * 3); 

            Size(loctestnum, loctesterr, s_ins, true, 50);
            Exists(loctestnum, loctesterr, s_ins, true, 0);
            Exists(loctestnum, loctesterr, s_ins, true, 147);
            Min(loctestnum, loctesterr, s_ins, true, 0);
            Max(loctestnum, loctesterr, s_ins, true, 147);
        }

        // Removals
        {
            lasd::SetLst<int> s_rem;
            for (int i = 0; i < 50; ++i)
                InsertC(loctestnum, loctesterr, s_rem, true, i);

            for (int i = 0; i < 25; ++i)
                Remove(loctestnum, loctesterr, s_rem, true, i * 2); 
            Size(loctestnum, loctesterr, s_rem, true, 25);

            for (int i = 0; i < 25; ++i)
                Exists(loctestnum, loctesterr, s_rem, true, i * 2 + 1); 

            for (int i = 0; i < 25; ++i)
                Exists(loctestnum, loctesterr, s_rem, false, i * 2); 

            Min(loctestnum, loctesterr, s_rem, true, 1);
            Max(loctestnum, loctesterr, s_rem, true, 49);
        }

        // List Stress
        {
            lasd::SetLst<int> s_stress;
  
            for(int i=0; i<100; ++i)
                InsertC(loctestnum, loctesterr, s_stress, true, i);
            Size(loctestnum, loctesterr, s_stress, true, 100);

            for(int i=0; i<10; ++i)
                MinNRemove(loctestnum, loctesterr, s_stress, true, i);
            Size(loctestnum, loctesterr, s_stress, true, 90);
            Min(loctestnum, loctesterr, s_stress, true, 10);

            for(int i=0; i<10; ++i)
                MaxNRemove(loctestnum, loctesterr, s_stress, true, 99-i);

            Size(loctestnum, loctesterr, s_stress, true, 80);
            Max(loctestnum, loctesterr, s_stress, true, 89);

            for(int i=10; i<90; ++i)
                InsertC(loctestnum, loctesterr, s_stress, false, i); 
            Size(loctestnum, loctesterr, s_stress, true, 80);

            for(int i=10; i<90; ++i)
                Remove(loctestnum, loctesterr, s_stress, true, i);
            Empty(loctestnum, loctesterr, s_stress, true);
        }

        // Copy constructor
        {
            lasd::SetLst<int> s_orig;
            InsertC(loctestnum, loctesterr, s_orig, true, 10);
            InsertC(loctestnum, loctesterr, s_orig, true, 20);
            lasd::SetLst<int> s_copy(s_orig);
            EqualSetLst(loctestnum, loctesterr, s_orig, s_copy, true);
            InsertC(loctestnum, loctesterr, s_copy, true, 30);
            NonEqualSetLst(loctestnum, loctesterr, s_orig, s_copy, true);
            Size(loctestnum, loctesterr, s_orig, true, 2);

            lasd::SetLst<int> s_empty_orig;
            lasd::SetLst<int> s_empty_copy(s_empty_orig);
            Empty(loctestnum, loctesterr, s_empty_copy, true);
            EqualSetLst(loctestnum, loctesterr, s_empty_orig, s_empty_copy, true);
        }

        // Move constructor
        {
            lasd::SetLst<int> s_orig_move;
            InsertC(loctestnum, loctesterr, s_orig_move, true, 100);
            InsertC(loctestnum, loctesterr, s_orig_move, true, 200);
            lasd::SetLst<int> s_dest_move(std::move(s_orig_move));
            Size(loctestnum, loctesterr, s_dest_move, true, 2);
            Exists(loctestnum, loctesterr, s_dest_move, true, 100);
            Empty(loctestnum, loctesterr, s_orig_move, true);

            lasd::SetLst<int> s_empty_orig_move;
            lasd::SetLst<int> s_empty_dest_move(std::move(s_empty_orig_move));
            Empty(loctestnum, loctesterr, s_empty_dest_move, true);
            Empty(loctestnum, loctesterr, s_empty_orig_move, true);
        }

        // Copy assignment
        {
            lasd::SetLst<int> s_assign_src;
            InsertC(loctestnum, loctesterr, s_assign_src, true, 5);
            InsertC(loctestnum, loctesterr, s_assign_src, true, 15);
            lasd::SetLst<int> s_assign_dest;
            InsertC(loctestnum, loctesterr, s_assign_dest, true, 1);
            s_assign_dest = s_assign_src;
            EqualSetLst(loctestnum, loctesterr, s_assign_src, s_assign_dest, true);
            InsertC(loctestnum, loctesterr, s_assign_dest, true, 25);
            NonEqualSetLst(loctestnum, loctesterr, s_assign_src, s_assign_dest, true);
            Size(loctestnum, loctesterr, s_assign_src, true, 2);

            s_assign_dest = s_assign_dest;
            Size(loctestnum, loctesterr, s_assign_dest, true, 3);
            Exists(loctestnum, loctesterr, s_assign_dest, true, 25);
        }

        // Move assignment
        {
            lasd::SetLst<int> s_massign_src;
            InsertC(loctestnum, loctesterr, s_massign_src, true, 50);
            InsertC(loctestnum, loctesterr, s_massign_src, true, 60);
            lasd::SetLst<int> s_massign_dest;
            InsertC(loctestnum, loctesterr, s_massign_dest, true, 10);
            s_massign_dest = std::move(s_massign_src);
            Size(loctestnum, loctesterr, s_massign_dest, true, 2);
            Exists(loctestnum, loctesterr, s_massign_dest, true, 50);
            Empty(loctestnum, loctesterr, s_massign_src, false);
           
            // lasd::SetLst<int> s_self_move; InsertC(loctestnum, loctesterr, s_self_move, true, 55);
            // s_self_move = std::move(s_self_move);
            // Size(loctestnum, loctesterr, s_self_move, true, 1); Exists(loctestnum, loctesterr, s_self_move, true, 55);
        }

      // Constructor from TraversableContainer (Copy)
        {
            lasd::SortableVector<int> svec_empty_src(0);
            lasd::SetLst<int> set_from_svec_empty_copy(svec_empty_src);
            Empty(loctestnum, loctesterr, set_from_svec_empty_copy, true);

            lasd::SortableVector<int> svec_src(5);
            SetAt(loctestnum, loctesterr, svec_src, true, 0, 30);
            SetAt(loctestnum, loctesterr, svec_src, true, 1, 10);
            SetAt(loctestnum, loctesterr, svec_src, true, 2, 20);
            SetAt(loctestnum, loctesterr, svec_src, true, 3, 10); 
            SetAt(loctestnum, loctesterr, svec_src, true, 4, 30); 
            
            lasd::SetLst<int> set_from_svec_copy(svec_src);
            Size(loctestnum, loctesterr, set_from_svec_copy, true, 3); 
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, 10);
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, 30);
            GetAt(loctestnum, loctesterr, set_from_svec_copy, true, 0, 10); 
            Size(loctestnum, loctesterr, svec_src, true, 5); 

            lasd::List<int> list_empty_src;
            lasd::SetLst<int> set_from_list_empty_copy(list_empty_src);
            Empty(loctestnum, loctesterr, set_from_list_empty_copy, true);

            lasd::List<int> list_src; 

            InsertAtBack(loctestnum, loctesterr, list_src, true, 50); 
            InsertAtFront(loctestnum, loctesterr, list_src, true, 40); 
            InsertAtBack(loctestnum, loctesterr, list_src, true, 50);
            InsertAtFront(loctestnum, loctesterr, list_src, true, 60); 
            
            lasd::SetLst<int> set_from_list_copy(list_src);
            Size(loctestnum, loctesterr, set_from_list_copy, true, 3); 
            Exists(loctestnum, loctesterr, set_from_list_copy, true, 40);
            Exists(loctestnum, loctesterr, set_from_list_copy, true, 60);
            GetAt(loctestnum, loctesterr, set_from_list_copy, true, 1, 50); 
            Size(loctestnum, loctesterr, list_src, true, 4); 

            lasd::SetVec<int> setvec_empty_src;
            lasd::SetLst<int> set_from_setvec_empty_copy(setvec_empty_src);
            Empty(loctestnum, loctesterr, set_from_setvec_empty_copy, true);

            lasd::SetVec<int> setvec_src;
            setvec_src.Insert(80);
            setvec_src.Insert(70);
            setvec_src.Insert(90);
            lasd::SetLst<int> set_from_setvec_copy(setvec_src);

            Size(loctestnum, loctesterr, set_from_setvec_copy, true, 3);
            Exists(loctestnum, loctesterr, set_from_setvec_copy, true, 70);
            Exists(loctestnum, loctesterr, set_from_setvec_copy, true, 90);
            GetAt(loctestnum, loctesterr, set_from_setvec_copy, true, 1, 80);
            Size(loctestnum, loctesterr, setvec_src, true, 3); 
        }

        // Constructor from MappableContainer (Move)
        {
            lasd::SortableVector<int> svec_empty_src_move(0);
            lasd::SetLst<int> set_from_svec_empty_move(std::move(svec_empty_src_move));
            Empty(loctestnum, loctesterr, set_from_svec_empty_move, true);
            Empty(loctestnum, loctesterr, svec_empty_src_move, true);

            lasd::SortableVector<int> svec_src_move(5);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 0, 30);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 1, 10);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 2, 20);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 3, 10); 
            SetAt(loctestnum, loctesterr, svec_src_move, true, 4, 30); 
      
            lasd::SetLst<int> set_from_svec_move(std::move(svec_src_move));
            Size(loctestnum, loctesterr, set_from_svec_move, true, 3); 
            Exists(loctestnum, loctesterr, set_from_svec_move, true, 10);
            GetAt(loctestnum, loctesterr, set_from_svec_move, true, 2, 30);
            Empty(loctestnum, loctesterr, svec_src_move, false);

            lasd::List<int> list_empty_src_move;
            lasd::SetLst<int> set_from_list_empty_move(std::move(list_empty_src_move));
            Empty(loctestnum, loctesterr, set_from_list_empty_move, true);
            Empty(loctestnum, loctesterr, list_empty_src_move, true);

            lasd::List<int> list_src_move;
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, 50);
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, 40);
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, 50);
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, 60);
   
            lasd::SetLst<int> set_from_list_move(std::move(list_src_move));
            Size(loctestnum, loctesterr, set_from_list_move, true, 3); 
            Exists(loctestnum, loctesterr, set_from_list_move, true, 50);
            GetAt(loctestnum, loctesterr, set_from_list_move, true, 0, 40);
            Empty(loctestnum, loctesterr, list_src_move, false); 
        }

        // Comparison
        {
            lasd::SetLst<int> s_comp1, s_comp2, s_comp3;
            InsertC(loctestnum, loctesterr, s_comp1, true, 1);
            InsertC(loctestnum, loctesterr, s_comp1, true, 2);
            InsertC(loctestnum, loctesterr, s_comp2, true, 2);
            InsertC(loctestnum, loctesterr, s_comp2, true, 1);
            InsertC(loctestnum, loctesterr, s_comp3, true, 1);
            InsertC(loctestnum, loctesterr, s_comp3, true, 3);
            EqualSetLst(loctestnum, loctesterr, s_comp1, s_comp2, true);
            NonEqualSetLst(loctestnum, loctesterr, s_comp1, s_comp3, true);
        }

        // Dictionary operations (InsertAll, RemoveAll, InsertSome, RemoveSome)
        {
            lasd::SetLst<int> s_main_dict;
            lasd::List<int> list_ins_dict, list_rem_dict, list_empty_dict;
            
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, 10); 
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, 20); 
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, 10); 
            
            InsertAtBack(loctestnum, loctesterr, list_rem_dict, true, 20); 
            InsertAtBack(loctestnum, loctesterr, list_rem_dict, true, 30);

            InsertAllC(loctestnum, loctesterr, s_main_dict, false, list_ins_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 2);
            Exists(loctestnum, loctesterr, s_main_dict, true, 10);
            Exists(loctestnum, loctesterr, s_main_dict, true, 20);
            
          
            InsertAllC(loctestnum, loctesterr, s_main_dict, false, list_ins_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 2); 

            RemoveAll(loctestnum, loctesterr, s_main_dict, false, list_rem_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 1);
            Exists(loctestnum, loctesterr, s_main_dict, false, 20); 
            Exists(loctestnum, loctesterr, s_main_dict, true, 10);
            
          
            RemoveAll(loctestnum, loctesterr, s_main_dict, false, list_rem_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 1); 

            s_main_dict.Clear(); InsertC(loctestnum, loctesterr, s_main_dict, true, 5); 

            InsertSomeC(loctestnum, loctesterr, s_main_dict, true, list_ins_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 3); 
            Exists(loctestnum, loctesterr, s_main_dict, true, 10); 
            Exists(loctestnum, loctesterr, s_main_dict, true, 20);
            
            
            InsertSomeC(loctestnum, loctesterr, s_main_dict, false, list_ins_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 3);

            RemoveSome(loctestnum, loctesterr, s_main_dict, true, list_rem_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 2);
            Exists(loctestnum, loctesterr, s_main_dict, false, 20); 
            Exists(loctestnum, loctesterr, s_main_dict, true, 10); 
            Exists(loctestnum, loctesterr, s_main_dict, true, 5);
            
            
            lasd::List<int> list_rem_dict_for_throw;
            InsertAtBack(loctestnum, loctesterr, list_rem_dict_for_throw, true, 30); 
            InsertAtBack(loctestnum, loctesterr, list_rem_dict_for_throw, true, 5); 

            loctestnum++;
            s_main_dict.RemoveSome(list_rem_dict_for_throw); 
            
            Size(loctestnum, loctesterr, s_main_dict, false, 2);
            Exists(loctestnum, loctesterr, s_main_dict, false, 5);
            Exists(loctestnum, loctesterr, s_main_dict, true, 10);
        }

        // Traversable/Mappable operations
        {
            lasd::SetLst<int> s_trav, s_empty_trav;
            InsertC(loctestnum, loctesterr, s_trav, true, 10);
            InsertC(loctestnum, loctesterr, s_trav, true, 30);
            InsertC(loctestnum, loctesterr, s_trav, true, 20); 
            
            TraversePreOrder(loctestnum, loctesterr, s_trav, true, &TraversePrint<int>); 
            TraversePostOrder(loctestnum, loctesterr, s_trav, true, &TraversePrint<int>); 

            FoldPreOrder(loctestnum, loctesterr, s_trav, true, &FoldAdd<int>, 0, 60); 
            FoldPostOrder(loctestnum, loctesterr, s_trav, true, &FoldAdd<int>, 0, 60); 

            TraversePreOrder(loctestnum, loctesterr, s_empty_trav, true, &TraversePrint<int>); 
            FoldPreOrder(loctestnum, loctesterr, s_empty_trav, true, &FoldAdd<int>, 0, 0);
        }
        
        // 14. Clear
        {
            lasd::SetLst<int> s_clear_reuse;
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 100);
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 50);
            s_clear_reuse.Clear();
            Empty(loctestnum, loctesterr, s_clear_reuse, true);
            Size(loctestnum, loctesterr, s_clear_reuse, true, 0);
            Min(loctestnum, loctesterr, s_clear_reuse, false, 0); 

            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 1);
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 2);
            Size(loctestnum, loctesterr, s_clear_reuse, true, 2);
            GetAt(loctestnum, loctesterr, s_clear_reuse, true, 0, 1);
            s_clear_reuse.Clear();
            Empty(loctestnum, loctesterr, s_clear_reuse, true);
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MySetLst<int> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mysetlst_double(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        // Default constructor and basic checks
        {
            lasd::SetLst<double> s_default;
            Empty(loctestnum, loctesterr, s_default, true);
            Size(loctestnum, loctesterr, s_default, true, 0);
            Min(loctestnum, loctesterr, s_default, false, 0.0); 
            Max(loctestnum, loctesterr, s_default, false, 0.0); 
            MinNRemove(loctestnum, loctesterr, s_default, false, 0.0);
            Size(loctestnum, loctesterr, s_default, true, 0);
            MaxNRemove(loctestnum, loctesterr, s_default, false, 0.0);
            Size(loctestnum, loctesterr, s_default, true, 0);
            GetAt(loctestnum, loctesterr, s_default, false, 0, 0.0); 
            Predecessor(loctestnum, loctesterr, s_default, false, 10.0, 0.0);
            Successor(loctestnum, loctesterr, s_default, false, 10.0, 0.0);
            Exists(loctestnum, loctesterr, s_default, false, 5.0);
            PredecessorNRemove(loctestnum, loctesterr, s_default, false, 10.0, 0.0);
            Size(loctestnum, loctesterr, s_default, true, 0);
            SuccessorNRemove(loctestnum, loctesterr, s_default, false, 10.0, 0.0);
            Size(loctestnum, loctesterr, s_default, true, 0);
    
            try { loctestnum++; s_default.RemovePredecessor(10.0); testerr++; cout << endl << "s_default.RemovePredecessor(10.0) on empty set did not throw" << endl;} catch (const std::length_error&) {} catch (...) {loctestnum++; testerr++; cout << endl << "s_default.RemovePredecessor(10.0) on empty set wrong exception" << endl;}
            try { loctestnum++; s_default.RemoveSuccessor(10.0); testerr++; cout << endl << "s_default.RemoveSuccessor(10.0) on empty set did not throw" << endl;} catch (const std::length_error&) {} catch (...) {loctestnum++; testerr++; cout << endl << "s_default.RemoveSuccessor(10.0) on empty set wrong exception" << endl;}
        }

        // Single Element Set
        {
            lasd::SetLst<double> s_single;
            InsertC(loctestnum, loctesterr, s_single, true, 10.0);
            Empty(loctestnum, loctesterr, s_single, false);
            Size(loctestnum, loctesterr, s_single, true, 1);
            Min(loctestnum, loctesterr, s_single, true, 10.0);
            Max(loctestnum, loctesterr, s_single, true, 10.0);
            GetAt(loctestnum, loctesterr, s_single, true, 0, 10.0);
            Exists(loctestnum, loctesterr, s_single, true, 10.0);
            Exists(loctestnum, loctesterr, s_single, false, 5.0);
            
            Predecessor(loctestnum, loctesterr, s_single, false, 10.0, 0.0); 
            Successor(loctestnum, loctesterr, s_single, false, 10.0, 0.0);   
            Predecessor(loctestnum, loctesterr, s_single, false, 5.0, 0.0);
            Successor(loctestnum, loctesterr, s_single, false, 15.0, 0.0);

            PredecessorNRemove(loctestnum, loctesterr, s_single, false, 10.0, 0.0);
            Size(loctestnum, loctesterr, s_single, true, 1);
            SuccessorNRemove(loctestnum, loctesterr, s_single, false, 10.0, 0.0);
            Size(loctestnum, loctesterr, s_single, true, 1);

            try { loctestnum++; s_single.RemovePredecessor(10.0); testerr++; cout << endl << "s_single.RemovePredecessor(10.0) did not throw" << endl;} catch (const std::logic_error&) {} catch (...) {loctestnum++; testerr++; cout << endl << "ERR! s_single.RemovePredecessor(10.0) wrong exception" << endl;}
            try { loctestnum++; s_single.RemoveSuccessor(10.0); testerr++; cout << endl << "s_single.RemoveSuccessor(10.0) did not throw" << endl;} catch (const std::logic_error&) {} catch (...) {loctestnum++; testerr++; cout << endl << "ERR! s_single.RemoveSuccessor(10.0) wrong exception" << endl;}
            Size(loctestnum, loctesterr, s_single, true, 1);

            Remove(loctestnum, loctesterr, s_single, true, 10.0);
            Empty(loctestnum, loctesterr, s_single, true);
            s_single.Clear();
        }

        // Multi-Element Set
        {
            lasd::SetLst<double> s1;
            InsertC(loctestnum, loctesterr, s1, true, 10.5); 
            InsertC(loctestnum, loctesterr, s1, true, 5.5);  
            InsertC(loctestnum, loctesterr, s1, true, 15.5); 
            InsertC(loctestnum, loctesterr, s1, true, 20.5); 
            Size(loctestnum, loctesterr, s1, true, 4); 
            GetAt(loctestnum, loctesterr, s1, true, 0, 5.5);
            GetAt(loctestnum, loctesterr, s1, true, 3, 20.5);
            Min(loctestnum, loctesterr, s1, true, 5.5);
            Max(loctestnum, loctesterr, s1, true, 20.5);

            Predecessor(loctestnum, loctesterr, s1, true, 15.5, 10.5);
            Successor(loctestnum, loctesterr, s1, true, 10.5, 15.5);
            PredecessorNRemove(loctestnum, loctesterr, s1, true, 20.5, 15.5); 
            Size(loctestnum, loctesterr, s1, true, 3);
            Exists(loctestnum, loctesterr, s1, false, 15.5);
            SuccessorNRemove(loctestnum, loctesterr, s1, true, 5.5, 10.5);  
            Size(loctestnum, loctesterr, s1, true, 2);
            Exists(loctestnum, loctesterr, s1, false, 10.5);

            s1.Clear();
            InsertC(loctestnum, loctesterr, s1, true, 10.1);
            InsertC(loctestnum, loctesterr, s1, true, 20.2);
            InsertC(loctestnum, loctesterr, s1, true, 30.3);
            try { loctestnum++; s1.RemovePredecessor(20.2); } catch(...) {loctestnum++; testerr++; cout << endl << "s1.RemovePredecessor(20.2) threw an unexpected exception" << endl;} 
            Size(loctestnum, loctesterr, s1, true, 2); 
            Exists(loctestnum, loctesterr, s1, false, 10.1);

            try { loctestnum++; s1.RemoveSuccessor(20.2); } catch(...) {loctestnum++; testerr++; cout << endl << "s1.RemoveSuccessor(20.2) threw an unexpected exception" << endl;} 
            Size(loctestnum, loctesterr, s1, true, 1); 
            Exists(loctestnum, loctesterr, s1, false, 30.3); 
            s1.Clear();
        }

        // Insertions
        {
            lasd::SetLst<double> s_ins;
            for (int i = 0; i < 50; ++i)
                InsertC(loctestnum, loctesterr, s_ins, true, i * 3.3);

            for (int i = 0; i < 50; ++i)
                InsertC(loctestnum, loctesterr, s_ins, false, i * 3.3); 

            Size(loctestnum, loctesterr, s_ins, true, 50);
            Exists(loctestnum, loctesterr, s_ins, true, 0.0);
            Exists(loctestnum, loctesterr, s_ins, true, 49 * 3.3);
            Min(loctestnum, loctesterr, s_ins, true, 0.0);
            Max(loctestnum, loctesterr, s_ins, true, 49 * 3.3);
        }

        // Removals
        {
            lasd::SetLst<double> s_rem;
            for (int i = 0; i < 50; ++i)
                InsertC(loctestnum, loctesterr, s_rem, true, (double)i);

            for (int i = 0; i < 25; ++i)
                Remove(loctestnum, loctesterr, s_rem, true, (double)(i * 2)); 
            Size(loctestnum, loctesterr, s_rem, true, 25);

            for (int i = 0; i < 25; ++i)
                Exists(loctestnum, loctesterr, s_rem, true, (double)(i * 2 + 1)); 

            for (int i = 0; i < 25; ++i)
                Exists(loctestnum, loctesterr, s_rem, false, (double)(i * 2)); 

            Min(loctestnum, loctesterr, s_rem, true, 1.0);
            Max(loctestnum, loctesterr, s_rem, true, 49.0);
        }

        // List Stress
        {
            lasd::SetLst<double> s_stress;
  
            for(int i=0; i<100; ++i)
                InsertC(loctestnum, loctesterr, s_stress, true, (double)i + 0.1);
            Size(loctestnum, loctesterr, s_stress, true, 100);

            for(int i=0; i<10; ++i)
                MinNRemove(loctestnum, loctesterr, s_stress, true, (double)i + 0.1);
            Size(loctestnum, loctesterr, s_stress, true, 90);
            Min(loctestnum, loctesterr, s_stress, true, 10.1);

            for(int i=0; i<10; ++i)
                MaxNRemove(loctestnum, loctesterr, s_stress, true, (double)(99-i) + 0.1);

            Size(loctestnum, loctesterr, s_stress, true, 80);
            Max(loctestnum, loctesterr, s_stress, true, 89.1);

            for(int i=10; i<90; ++i) 
                InsertC(loctestnum, loctesterr, s_stress, false, (double)i + 0.1); 
            Size(loctestnum, loctesterr, s_stress, true, 80);

            for(int i=10; i<90; ++i)
                Remove(loctestnum, loctesterr, s_stress, true, (double)i + 0.1);
            Empty(loctestnum, loctesterr, s_stress, true);
        }

        // Copy constructor
        {
            lasd::SetLst<double> s_orig;
            InsertC(loctestnum, loctesterr, s_orig, true, 10.1);
            InsertC(loctestnum, loctesterr, s_orig, true, 20.2);
            lasd::SetLst<double> s_copy(s_orig);
            EqualSetLst(loctestnum, loctesterr, s_orig, s_copy, true);
            InsertC(loctestnum, loctesterr, s_copy, true, 30.3);
            NonEqualSetLst(loctestnum, loctesterr, s_orig, s_copy, true);
            Size(loctestnum, loctesterr, s_orig, true, 2);

            lasd::SetLst<double> s_empty_orig;
            lasd::SetLst<double> s_empty_copy(s_empty_orig);
            Empty(loctestnum, loctesterr, s_empty_copy, true);
            EqualSetLst(loctestnum, loctesterr, s_empty_orig, s_empty_copy, true);
        }

        // Move constructor
        {
            lasd::SetLst<double> s_orig_move;
            InsertC(loctestnum, loctesterr, s_orig_move, true, 100.1);
            InsertC(loctestnum, loctesterr, s_orig_move, true, 200.2);
            lasd::SetLst<double> s_dest_move(std::move(s_orig_move));
            Size(loctestnum, loctesterr, s_dest_move, true, 2);
            Exists(loctestnum, loctesterr, s_dest_move, true, 100.1);
            Empty(loctestnum, loctesterr, s_orig_move, true); 

            lasd::SetLst<double> s_empty_orig_move;
            lasd::SetLst<double> s_empty_dest_move(std::move(s_empty_orig_move));
            Empty(loctestnum, loctesterr, s_empty_dest_move, true);
            Empty(loctestnum, loctesterr, s_empty_orig_move, true);
        }

        // Copy assignment
        {
            lasd::SetLst<double> s_assign_src;
            InsertC(loctestnum, loctesterr, s_assign_src, true, 5.1);
            InsertC(loctestnum, loctesterr, s_assign_src, true, 15.2);
            lasd::SetLst<double> s_assign_dest;
            InsertC(loctestnum, loctesterr, s_assign_dest, true, 1.3);
            s_assign_dest = s_assign_src;
            EqualSetLst(loctestnum, loctesterr, s_assign_src, s_assign_dest, true);
            InsertC(loctestnum, loctesterr, s_assign_dest, true, 25.4);
            NonEqualSetLst(loctestnum, loctesterr, s_assign_src, s_assign_dest, true);
            Size(loctestnum, loctesterr, s_assign_src, true, 2);

            s_assign_dest = s_assign_dest; 
            Size(loctestnum, loctesterr, s_assign_dest, true, 3);
            Exists(loctestnum, loctesterr, s_assign_dest, true, 25.4);
        }

        // Move assignment
        {
            lasd::SetLst<double> s_massign_src;
            InsertC(loctestnum, loctesterr, s_massign_src, true, 50.1);
            InsertC(loctestnum, loctesterr, s_massign_src, true, 60.2);
            lasd::SetLst<double> s_massign_dest;
            InsertC(loctestnum, loctesterr, s_massign_dest, true, 10.3);
            s_massign_dest = std::move(s_massign_src);
            Size(loctestnum, loctesterr, s_massign_dest, true, 2);
            Exists(loctestnum, loctesterr, s_massign_dest, true, 50.1);
            Empty(loctestnum, loctesterr, s_massign_src, false);
           
            // lasd::SetLst<double> s_self_move; 
            // InsertC(loctestnum, loctesterr, s_self_move, true, 55.5);
            // InsertC(loctestnum, loctesterr, s_self_move, true, 65.5);
            // s_self_move = std::move(s_self_move); 
            // Size(loctestnum, loctesterr, s_self_move, true, 2); 
            // Exists(loctestnum, loctesterr, s_self_move, true, 55.5);
        }

      // Constructor from TraversableContainer (Copy)
        {
            lasd::SortableVector<double> svec_empty_src(0);
            lasd::SetLst<double> set_from_svec_empty_copy(svec_empty_src);
            Empty(loctestnum, loctesterr, set_from_svec_empty_copy, true);

            lasd::SortableVector<double> svec_src(5);
            SetAt(loctestnum, loctesterr, svec_src, true, 0, 30.1);
            SetAt(loctestnum, loctesterr, svec_src, true, 1, 10.2);
            SetAt(loctestnum, loctesterr, svec_src, true, 2, 20.3);
            SetAt(loctestnum, loctesterr, svec_src, true, 3, 10.2); 
            SetAt(loctestnum, loctesterr, svec_src, true, 4, 30.1); 
            
            lasd::SetLst<double> set_from_svec_copy(svec_src);
            Size(loctestnum, loctesterr, set_from_svec_copy, true, 3); 
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, 10.2);
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, 30.1);
            GetAt(loctestnum, loctesterr, set_from_svec_copy, true, 0, 10.2); 
            Size(loctestnum, loctesterr, svec_src, true, 5); 

            lasd::List<double> list_empty_src;
            lasd::SetLst<double> set_from_list_empty_copy(list_empty_src);
            Empty(loctestnum, loctesterr, set_from_list_empty_copy, true);

            lasd::List<double> list_src; 
            InsertAtBack(loctestnum, loctesterr, list_src, true, 50.1); 
            InsertAtFront(loctestnum, loctesterr, list_src, true, 40.2); 
            InsertAtBack(loctestnum, loctesterr, list_src, true, 50.1);
            InsertAtFront(loctestnum, loctesterr, list_src, true, 60.3); 
            
            lasd::SetLst<double> set_from_list_copy(list_src);
            Size(loctestnum, loctesterr, set_from_list_copy, true, 3); 
            Exists(loctestnum, loctesterr, set_from_list_copy, true, 40.2);
            Exists(loctestnum, loctesterr, set_from_list_copy, true, 60.3);
            GetAt(loctestnum, loctesterr, set_from_list_copy, true, 1, 50.1); 
            Size(loctestnum, loctesterr, list_src, true, 4); 

            lasd::SetVec<double> setvec_empty_src_copy; 
            lasd::SetLst<double> set_from_setvec_empty_copy(setvec_empty_src_copy);
            Empty(loctestnum, loctesterr, set_from_setvec_empty_copy, true);

            lasd::SetVec<double> setvec_src_copy_data; 
            InsertC(loctestnum, loctesterr, setvec_src_copy_data, true, 80.1); 
            InsertC(loctestnum, loctesterr, setvec_src_copy_data, true, 70.2);
            InsertC(loctestnum, loctesterr, setvec_src_copy_data, true, 90.3);
            lasd::SetLst<double> set_from_setvec_copy(setvec_src_copy_data);

            Size(loctestnum, loctesterr, set_from_setvec_copy, true, 3);
            Exists(loctestnum, loctesterr, set_from_setvec_copy, true, 70.2);
            Exists(loctestnum, loctesterr, set_from_setvec_copy, true, 90.3);
            GetAt(loctestnum, loctesterr, set_from_setvec_copy, true, 1, 80.1);
            Size(loctestnum, loctesterr, setvec_src_copy_data, true, 3); 
        }

        // Constructor from MappableContainer (Move)
        {
            lasd::SortableVector<double> svec_empty_src_move(0);
            lasd::SetLst<double> set_from_svec_empty_move(std::move(svec_empty_src_move));
            Empty(loctestnum, loctesterr, set_from_svec_empty_move, true);
            Empty(loctestnum, loctesterr, svec_empty_src_move, true);

            lasd::SortableVector<double> svec_src_move(5);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 0, 30.1);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 1, 10.2);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 2, 20.3);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 3, 10.2); 
            SetAt(loctestnum, loctesterr, svec_src_move, true, 4, 30.1); 
      
            lasd::SetLst<double> set_from_svec_move(std::move(svec_src_move));
            Size(loctestnum, loctesterr, set_from_svec_move, true, 3); 
            Exists(loctestnum, loctesterr, set_from_svec_move, true, 10.2);
            GetAt(loctestnum, loctesterr, set_from_svec_move, true, 2, 30.1);

            lasd::List<double> list_empty_src_move;
            lasd::SetLst<double> set_from_list_empty_move(std::move(list_empty_src_move));
            Empty(loctestnum, loctesterr, set_from_list_empty_move, true);
            Empty(loctestnum, loctesterr, list_empty_src_move, true);

            lasd::List<double> list_src_move;
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, 50.1);
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, 40.2);
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, 50.1);
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, 60.3);
   
            lasd::SetLst<double> set_from_list_move(std::move(list_src_move));
            Size(loctestnum, loctesterr, set_from_list_move, true, 3); 
            Exists(loctestnum, loctesterr, set_from_list_move, true, 50.1);
            GetAt(loctestnum, loctesterr, set_from_list_move, true, 0, 40.2);
            Empty(loctestnum, loctesterr, list_src_move, false); 

        }

        // Comparison
        {
            lasd::SetLst<double> s_comp1, s_comp2, s_comp3;
            InsertC(loctestnum, loctesterr, s_comp1, true, 1.1);
            InsertC(loctestnum, loctesterr, s_comp1, true, 2.2);
            InsertC(loctestnum, loctesterr, s_comp2, true, 2.2);
            InsertC(loctestnum, loctesterr, s_comp2, true, 1.1);
            InsertC(loctestnum, loctesterr, s_comp3, true, 1.1);
            InsertC(loctestnum, loctesterr, s_comp3, true, 3.3);
            EqualSetLst(loctestnum, loctesterr, s_comp1, s_comp2, true);
            NonEqualSetLst(loctestnum, loctesterr, s_comp1, s_comp3, true);
        }

        // Dictionary operations (InsertAll, RemoveAll, InsertSome, RemoveSome)
        {
            lasd::SetLst<double> s_main_dict;
            lasd::List<double> list_ins_dict, list_rem_dict, list_empty_dict;
            
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, 10.1); 
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, 20.2); 
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, 10.1); 
            
            InsertAtBack(loctestnum, loctesterr, list_rem_dict, true, 20.2); 
            InsertAtBack(loctestnum, loctesterr, list_rem_dict, true, 30.3);

            InsertAllC(loctestnum, loctesterr, s_main_dict, false, list_ins_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 2);
            Exists(loctestnum, loctesterr, s_main_dict, true, 10.1);
            Exists(loctestnum, loctesterr, s_main_dict, true, 20.2);
            
            InsertAllC(loctestnum, loctesterr, s_main_dict, false, list_ins_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 2); 

            RemoveAll(loctestnum, loctesterr, s_main_dict, false, list_rem_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 1);
            Exists(loctestnum, loctesterr, s_main_dict, false, 20.2); 
            Exists(loctestnum, loctesterr, s_main_dict, true, 10.1);
            
            RemoveAll(loctestnum, loctesterr, s_main_dict, false, list_rem_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 1); 

            s_main_dict.Clear(); InsertC(loctestnum, loctesterr, s_main_dict, true, 5.5); 

            InsertSomeC(loctestnum, loctesterr, s_main_dict, true, list_ins_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 3); 
            Exists(loctestnum, loctesterr, s_main_dict, true, 10.1); 
            Exists(loctestnum, loctesterr, s_main_dict, true, 20.2);
            
            InsertSomeC(loctestnum, loctesterr, s_main_dict, false, list_ins_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 3);

            RemoveSome(loctestnum, loctesterr, s_main_dict, true, list_rem_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 2); 
            Exists(loctestnum, loctesterr, s_main_dict, false, 20.2); 
            Exists(loctestnum, loctesterr, s_main_dict, true, 10.1); 
            Exists(loctestnum, loctesterr, s_main_dict, true, 5.5);
        }

        // Traversable/Mappable operations
        {
            lasd::SetLst<double> s_trav, s_empty_trav;
            InsertC(loctestnum, loctesterr, s_trav, true, 10.1);
            InsertC(loctestnum, loctesterr, s_trav, true, 30.3);
            InsertC(loctestnum, loctesterr, s_trav, true, 20.2); 
            
            TraversePreOrder(loctestnum, loctesterr, s_trav, true, &TraversePrint<double>); 
            TraversePostOrder(loctestnum, loctesterr, s_trav, true, &TraversePrint<double>); 
 
            FoldPostOrder(loctestnum, loctesterr, s_trav, true, &FoldAdd<double>, 0.0, 60.6); 

            TraversePreOrder(loctestnum, loctesterr, s_empty_trav, true, &TraversePrint<double>); 
            FoldPreOrder(loctestnum, loctesterr, s_empty_trav, true, &FoldAdd<double>, 0.0, 0.0);
        }
        
        // 14. Clear
        {
            lasd::SetLst<double> s_clear_reuse;
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 100.1);
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 50.2);
            s_clear_reuse.Clear();
            Empty(loctestnum, loctesterr, s_clear_reuse, true);
            Size(loctestnum, loctesterr, s_clear_reuse, true, 0);
            Min(loctestnum, loctesterr, s_clear_reuse, false, 0.0); 

            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 1.1);
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 2.2);
            Size(loctestnum, loctesterr, s_clear_reuse, true, 2);
            GetAt(loctestnum, loctesterr, s_clear_reuse, true, 0, 1.1);
            s_clear_reuse.Clear();
            Empty(loctestnum, loctesterr, s_clear_reuse, true);
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MySetLst<double> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mysetlst_string(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        // Default constructor and basic checks
        {
            lasd::SetLst<string> s_default;
            Empty(loctestnum, loctesterr, s_default, true);
            Size(loctestnum, loctesterr, s_default, true, 0);
            Min(loctestnum, loctesterr, s_default, false, string("")); 
            Max(loctestnum, loctesterr, s_default, false, string("")); 
            MinNRemove(loctestnum, loctesterr, s_default, false, string(""));
            Size(loctestnum, loctesterr, s_default, true, 0);
            MaxNRemove(loctestnum, loctesterr, s_default, false, string(""));
            Size(loctestnum, loctesterr, s_default, true, 0);
            GetAt(loctestnum, loctesterr, s_default, false, 0, string("")); 
            Predecessor(loctestnum, loctesterr, s_default, false, string("10"), string(""));
            Successor(loctestnum, loctesterr, s_default, false, string("10"), string(""));
            Exists(loctestnum, loctesterr, s_default, false, string("05"));
            PredecessorNRemove(loctestnum, loctesterr, s_default, false, string("10"), string(""));
            Size(loctestnum, loctesterr, s_default, true, 0);
            SuccessorNRemove(loctestnum, loctesterr, s_default, false, string("10"), string(""));
            Size(loctestnum, loctesterr, s_default, true, 0);
            try { loctestnum++; s_default.RemovePredecessor(string("10")); testerr++; cout << endl << "s_default.RemovePredecessor(\"10\") on empty set did not throw" << endl;} catch (const std::length_error&) {} catch (...) {loctestnum++; testerr++; cout << endl << "s_default.RemovePredecessor(\"10\") on empty set wrong exception" << endl;}
            try { loctestnum++; s_default.RemoveSuccessor(string("10")); testerr++; cout << endl << "s_default.RemoveSuccessor(\"10\") on empty set did not throw" << endl;} catch (const std::length_error&) {} catch (...) {loctestnum++; testerr++; cout << endl << "s_default.RemoveSuccessor(\"10\") on empty set wrong exception" << endl;}
        }

        // Single Element Set
        {
            lasd::SetLst<string> s_single;
            InsertC(loctestnum, loctesterr, s_single, true, string("10"));
            Empty(loctestnum, loctesterr, s_single, false);
            Size(loctestnum, loctesterr, s_single, true, 1);
            Min(loctestnum, loctesterr, s_single, true, string("10"));
            Max(loctestnum, loctesterr, s_single, true, string("10"));
            GetAt(loctestnum, loctesterr, s_single, true, 0, string("10"));
            Exists(loctestnum, loctesterr, s_single, true, string("10"));
            Exists(loctestnum, loctesterr, s_single, false, string("05"));
            
            Predecessor(loctestnum, loctesterr, s_single, false, string("10"), string("")); 
            Successor(loctestnum, loctesterr, s_single, false, string("10"), string(""));   
            Predecessor(loctestnum, loctesterr, s_single, false, string("05"), string(""));
            Successor(loctestnum, loctesterr, s_single, false, string("15"), string(""));   

            PredecessorNRemove(loctestnum, loctesterr, s_single, false, string("10"), string(""));
            Size(loctestnum, loctesterr, s_single, true, 1);
            SuccessorNRemove(loctestnum, loctesterr, s_single, false, string("10"), string(""));
            Size(loctestnum, loctesterr, s_single, true, 1);

            try { loctestnum++; s_single.RemovePredecessor(string("10")); testerr++; cout << endl << "s_single.RemovePredecessor(\"10\") did not throw" << endl;} catch (const std::logic_error&) {} catch (...) {loctestnum++; testerr++; cout << endl << "s_single.RemovePredecessor(\"10\") wrong exception" << endl;}
            try { loctestnum++; s_single.RemoveSuccessor(string("10")); testerr++; cout << endl << "s_single.RemoveSuccessor(\"10\") did not throw" << endl;} catch (const std::logic_error&) {} catch (...) {loctestnum++; testerr++; cout << endl << "s_single.RemoveSuccessor(\"10\") wrong exception" << endl;}
            Size(loctestnum, loctesterr, s_single, true, 1);

            Remove(loctestnum, loctesterr, s_single, true, string("10"));
            Empty(loctestnum, loctesterr, s_single, true);
            s_single.Clear();
        }

        // Multi-Element Set
        {
            lasd::SetLst<string> s1;
            InsertC(loctestnum, loctesterr, s1, true, string("10")); 
            InsertC(loctestnum, loctesterr, s1, true, string("05"));  
            InsertC(loctestnum, loctesterr, s1, true, string("15")); 
            InsertC(loctestnum, loctesterr, s1, true, string("20")); 
            Size(loctestnum, loctesterr, s1, true, 4); 
            GetAt(loctestnum, loctesterr, s1, true, 0, string("05")); 
            GetAt(loctestnum, loctesterr, s1, true, 3, string("20"));
            Min(loctestnum, loctesterr, s1, true, string("05"));
            Max(loctestnum, loctesterr, s1, true, string("20"));

            Predecessor(loctestnum, loctesterr, s1, true, string("15"), string("10"));
            Successor(loctestnum, loctesterr, s1, true, string("10"), string("15"));
            PredecessorNRemove(loctestnum, loctesterr, s1, true, string("20"), string("15")); 
            Size(loctestnum, loctesterr, s1, true, 3); 
            Exists(loctestnum, loctesterr, s1, false, string("15"));
            SuccessorNRemove(loctestnum, loctesterr, s1, true, string("05"), string("10"));  
            Size(loctestnum, loctesterr, s1, true, 2); 
            Exists(loctestnum, loctesterr, s1, false, string("10"));

            s1.Clear();
            InsertC(loctestnum, loctesterr, s1, true, string("10"));
            InsertC(loctestnum, loctesterr, s1, true, string("20"));
            InsertC(loctestnum, loctesterr, s1, true, string("30")); 
            try { loctestnum++; s1.RemovePredecessor(string("20")); } catch(...) {loctestnum++; testerr++; cout << endl << "s1.RemovePredecessor(string(\"20\")) threw an unexpected exception" << endl;} // Removes "10", Set: {"20", "30"}
            Size(loctestnum, loctesterr, s1, true, 2);
            Exists(loctestnum, loctesterr, s1, false, string("10"));

            try { loctestnum++; s1.RemoveSuccessor(string("20")); } catch(...) {loctestnum++; testerr++; cout << endl << "s1.RemoveSuccessor(string(\"20\")) threw an unexpected exception" << endl;} // Removes "30", Set: {"20"}
            Size(loctestnum, loctesterr, s1, true, 1);
            Exists(loctestnum, loctesterr, s1, false, string("30"));
            s1.Clear();
        }

        // Insertions
        {
            lasd::SetLst<string> s_ins;
            for (int i = 0; i < 50; ++i) {
                int val = i * 3;
                string s_val;
                if (val < 10)
                    s_val = "00" + std::to_string(val);
                else if(val < 100)
                    s_val = "0" + std::to_string(val);
                else
                    s_val = std::to_string(val);
                InsertC(loctestnum, loctesterr, s_ins, true, s_val);
            }

            for (int i = 0; i < 50; ++i) {
                int val = i * 3;
                string s_val;
                if (val < 10)
                    s_val = "00" + std::to_string(val);
                else if (val < 100)
                    s_val = "0" + std::to_string(val);
                else
                    s_val = std::to_string(val);
                InsertC(loctestnum, loctesterr, s_ins, false, s_val); 
            }

            Size(loctestnum, loctesterr, s_ins, true, 50);
            Exists(loctestnum, loctesterr, s_ins, true, string("000"));
            Exists(loctestnum, loctesterr, s_ins, true, string("147"));
            Min(loctestnum, loctesterr, s_ins, true, string("000"));
            Max(loctestnum, loctesterr, s_ins, true, string("147"));
        }

        // Removals
        {
            lasd::SetLst<string> s_rem;
            for (int i = 0; i < 50; ++i)
            {
                string s_val = (i < 10 ? "0" : "") + std::to_string(i);
                InsertC(loctestnum, loctesterr, s_rem, true, s_val);
            }

            for (int i = 0; i < 25; ++i)
            {
                int val_to_remove = i * 2;
                string s_val_remove = (val_to_remove < 10 ? "0" : "") + std::to_string(val_to_remove);
                Remove(loctestnum, loctesterr, s_rem, true, s_val_remove); 
            }
            Size(loctestnum, loctesterr, s_rem, true, 25);

            for (int i = 0; i < 25; ++i)
            {
                int val_exists = i * 2 + 1;
                string s_val_exists = (val_exists < 10 ? "0" : "") + std::to_string(val_exists);
                Exists(loctestnum, loctesterr, s_rem, true, s_val_exists); 
            }

            for (int i = 0; i < 25; ++i)
            {
                int val_not_exists = i * 2;
                string s_val_not_exists = (val_not_exists < 10 ? "0" : "") + std::to_string(val_not_exists);
                Exists(loctestnum, loctesterr, s_rem, false, s_val_not_exists); 
            }

            Min(loctestnum, loctesterr, s_rem, true, string("01"));
            Max(loctestnum, loctesterr, s_rem, true, string("49"));
        }

        // List Stress
        {
            lasd::SetLst<string> s_stress;
  
            for(int i=0; i<100; ++i)
            {
                string s_val = (i < 10 ? "0" : "") + std::to_string(i);
                InsertC(loctestnum, loctesterr, s_stress, true, s_val);
            }
            Size(loctestnum, loctesterr, s_stress, true, 100);

            for(int i=0; i<10; ++i)
            {
                string s_val_remove = (i < 10 ? "0" : "") + std::to_string(i);
                MinNRemove(loctestnum, loctesterr, s_stress, true, s_val_remove);
            }
            Size(loctestnum, loctesterr, s_stress, true, 90);
            Min(loctestnum, loctesterr, s_stress, true, string("10"));

            for(int i=0; i<10; ++i)
            { 
                string s_val_remove = std::to_string(99-i);
                MaxNRemove(loctestnum, loctesterr, s_stress, true, s_val_remove);
            }
            Size(loctestnum, loctesterr, s_stress, true, 80); 
            Max(loctestnum, loctesterr, s_stress, true, string("89"));

            for(int i=10; i<90; ++i)
            { 
                string s_val = (i < 10 ? "0" : "") + std::to_string(i); 
                if (i >= 10 && i < 100)
                { 
                     s_val = std::to_string(i);
                }
                InsertC(loctestnum, loctesterr, s_stress, false, s_val); 
            }
            Size(loctestnum, loctesterr, s_stress, true, 80);

            for(int i=10; i<90; ++i)
            { 
                string s_val = std::to_string(i);
                Remove(loctestnum, loctesterr, s_stress, true, s_val);
            }
            Empty(loctestnum, loctesterr, s_stress, true);
        }

        // Copy constructor
        {
            lasd::SetLst<string> s_orig;
            InsertC(loctestnum, loctesterr, s_orig, true, string("10"));
            InsertC(loctestnum, loctesterr, s_orig, true, string("20"));
            lasd::SetLst<string> s_copy(s_orig);
            EqualSetLst(loctestnum, loctesterr, s_orig, s_copy, true);
            InsertC(loctestnum, loctesterr, s_copy, true, string("30"));
            NonEqualSetLst(loctestnum, loctesterr, s_orig, s_copy, true);
            Size(loctestnum, loctesterr, s_orig, true, 2);

            lasd::SetLst<string> s_empty_orig;
            lasd::SetLst<string> s_empty_copy(s_empty_orig);
            Empty(loctestnum, loctesterr, s_empty_copy, true);
            EqualSetLst(loctestnum, loctesterr, s_empty_orig, s_empty_copy, true);
        }

        // Move constructor
        {
            lasd::SetLst<string> s_orig_move;
            InsertC(loctestnum, loctesterr, s_orig_move, true, string("str100"));
            InsertC(loctestnum, loctesterr, s_orig_move, true, string("str200"));
            lasd::SetLst<string> s_dest_move(std::move(s_orig_move));
            Size(loctestnum, loctesterr, s_dest_move, true, 2);
            Exists(loctestnum, loctesterr, s_dest_move, true, string("str100"));
            Empty(loctestnum, loctesterr, s_orig_move, true);

            lasd::SetLst<string> s_empty_orig_move;
            lasd::SetLst<string> s_empty_dest_move(std::move(s_empty_orig_move));
            Empty(loctestnum, loctesterr, s_empty_dest_move, true);
            Empty(loctestnum, loctesterr, s_empty_orig_move, true);
        }

        // Copy assignment
        {
            lasd::SetLst<string> s_assign_src;
            InsertC(loctestnum, loctesterr, s_assign_src, true, string("s05"));
            InsertC(loctestnum, loctesterr, s_assign_src, true, string("s15"));
            lasd::SetLst<string> s_assign_dest;
            InsertC(loctestnum, loctesterr, s_assign_dest, true, string("s01"));
            s_assign_dest = s_assign_src;
            EqualSetLst(loctestnum, loctesterr, s_assign_src, s_assign_dest, true);
            InsertC(loctestnum, loctesterr, s_assign_dest, true, string("s25"));
            NonEqualSetLst(loctestnum, loctesterr, s_assign_src, s_assign_dest, true);
            Size(loctestnum, loctesterr, s_assign_src, true, 2);

            s_assign_dest = s_assign_dest;
            Size(loctestnum, loctesterr, s_assign_dest, true, 3);
            Exists(loctestnum, loctesterr, s_assign_dest, true, string("s25"));
        }

        // Move assignment
        {
            lasd::SetLst<string> s_massign_src;
            InsertC(loctestnum, loctesterr, s_massign_src, true, string("move50"));
            InsertC(loctestnum, loctesterr, s_massign_src, true, string("move60"));
            lasd::SetLst<string> s_massign_dest;
            InsertC(loctestnum, loctesterr, s_massign_dest, true, string("move10"));
            s_massign_dest = std::move(s_massign_src);
            Size(loctestnum, loctesterr, s_massign_dest, true, 2);
            Exists(loctestnum, loctesterr, s_massign_dest, true, string("move50"));
            Empty(loctestnum, loctesterr, s_massign_src, false);
           
            // lasd::SetLst<string> s_self_move; InsertC(loctestnum, loctesterr, s_self_move, true, string("self55"));
            // s_self_move = std::move(s_self_move);
            // Size(loctestnum, loctesterr, s_self_move, true, 1); Exists(loctestnum, loctesterr, s_self_move, true, string("self55"));
        }

      // Constructor from TraversableContainer (Copy)
        {
            lasd::SortableVector<string> svec_empty_src(0);
            lasd::SetLst<string> set_from_svec_empty_copy(svec_empty_src);
            Empty(loctestnum, loctesterr, set_from_svec_empty_copy, true);

            lasd::SortableVector<string> svec_src(5);
            SetAt(loctestnum, loctesterr, svec_src, true, 0, string("30"));
            SetAt(loctestnum, loctesterr, svec_src, true, 1, string("10"));
            SetAt(loctestnum, loctesterr, svec_src, true, 2, string("20"));
            SetAt(loctestnum, loctesterr, svec_src, true, 3, string("10")); 
            SetAt(loctestnum, loctesterr, svec_src, true, 4, string("30")); 
            
            lasd::SetLst<string> set_from_svec_copy(svec_src);
            Size(loctestnum, loctesterr, set_from_svec_copy, true, 3); 
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, string("10"));
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, string("30"));
            GetAt(loctestnum, loctesterr, set_from_svec_copy, true, 0, string("10")); 
            Size(loctestnum, loctesterr, svec_src, true, 5); 

            lasd::List<string> list_empty_src;
            lasd::SetLst<string> set_from_list_empty_copy(list_empty_src);
            Empty(loctestnum, loctesterr, set_from_list_empty_copy, true);

            lasd::List<string> list_src; 
            InsertAtBack(loctestnum, loctesterr, list_src, true, string("50")); 
            InsertAtFront(loctestnum, loctesterr, list_src, true, string("40")); 
            InsertAtBack(loctestnum, loctesterr, list_src, true, string("50"));
            InsertAtFront(loctestnum, loctesterr, list_src, true, string("60")); 
            
            lasd::SetLst<string> set_from_list_copy(list_src);
            Size(loctestnum, loctesterr, set_from_list_copy, true, 3); 
            Exists(loctestnum, loctesterr, set_from_list_copy, true, string("40"));
            Exists(loctestnum, loctesterr, set_from_list_copy, true, string("60"));
            GetAt(loctestnum, loctesterr, set_from_list_copy, true, 1, string("50")); 
            Size(loctestnum, loctesterr, list_src, true, 4); 

            cout << endl << "  - From SetVec (Copy):" << endl;
            lasd::SetVec<string> setvec_empty_src;
            lasd::SetLst<string> set_from_setvec_empty_copy(setvec_empty_src);
            Empty(loctestnum, loctesterr, set_from_setvec_empty_copy, true);

            lasd::SetVec<string> setvec_src;
            setvec_src.Insert(string("80"));
            setvec_src.Insert(string("70"));
            setvec_src.Insert(string("90"));
            lasd::SetLst<string> set_from_setvec_copy(setvec_src);

            Size(loctestnum, loctesterr, set_from_setvec_copy, true, 3);
            Exists(loctestnum, loctesterr, set_from_setvec_copy, true, string("70"));
            Exists(loctestnum, loctesterr, set_from_setvec_copy, true, string("90"));
            GetAt(loctestnum, loctesterr, set_from_setvec_copy, true, 1, string("80"));
            Size(loctestnum, loctesterr, setvec_src, true, 3); 
        }

        // Constructor from MappableContainer (Move)
        {
            lasd::SortableVector<string> svec_empty_src_move(0);
            lasd::SetLst<string> set_from_svec_empty_move(std::move(svec_empty_src_move));
            Empty(loctestnum, loctesterr, set_from_svec_empty_move, true);
            Empty(loctestnum, loctesterr, svec_empty_src_move, true);

            lasd::SortableVector<string> svec_src_move(5);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 0, string("str30"));
            SetAt(loctestnum, loctesterr, svec_src_move, true, 1, string("str10"));
            SetAt(loctestnum, loctesterr, svec_src_move, true, 2, string("str20"));
            SetAt(loctestnum, loctesterr, svec_src_move, true, 3, string("str10")); 
            SetAt(loctestnum, loctesterr, svec_src_move, true, 4, string("str30")); 
      
            lasd::SetLst<string> set_from_svec_move(std::move(svec_src_move));
            Size(loctestnum, loctesterr, set_from_svec_move, true, 3); 
            Exists(loctestnum, loctesterr, set_from_svec_move, true, string("str10"));
            GetAt(loctestnum, loctesterr, set_from_svec_move, true, 2, string("str30")); 
            Empty(loctestnum, loctesterr, svec_src_move, false);

            lasd::List<string> list_empty_src_move;
            lasd::SetLst<string> set_from_list_empty_move(std::move(list_empty_src_move));
            Empty(loctestnum, loctesterr, set_from_list_empty_move, true);
            Empty(loctestnum, loctesterr, list_empty_src_move, true);

            lasd::List<string> list_src_move;
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, string("move50"));
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, string("move40"));
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, string("move50"));
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, string("move60"));
   
            lasd::SetLst<string> set_from_list_move(std::move(list_src_move));
            Size(loctestnum, loctesterr, set_from_list_move, true, 3); 
            Exists(loctestnum, loctesterr, set_from_list_move, true, string("move50"));
            GetAt(loctestnum, loctesterr, set_from_list_move, true, 0, string("move40")); 
            Empty(loctestnum, loctesterr, list_src_move, false); 
        }

        // Comparison
        {
            lasd::SetLst<string> s_comp1, s_comp2, s_comp3;
            InsertC(loctestnum, loctesterr, s_comp1, true, string("01"));
            InsertC(loctestnum, loctesterr, s_comp1, true, string("02"));
            InsertC(loctestnum, loctesterr, s_comp2, true, string("02"));
            InsertC(loctestnum, loctesterr, s_comp2, true, string("01"));
            InsertC(loctestnum, loctesterr, s_comp3, true, string("01"));
            InsertC(loctestnum, loctesterr, s_comp3, true, string("03"));
            EqualSetLst(loctestnum, loctesterr, s_comp1, s_comp2, true);
            NonEqualSetLst(loctestnum, loctesterr, s_comp1, s_comp3, true);
        }

        // Dictionary operations (InsertAll, RemoveAll, InsertSome, RemoveSome)
        {
            lasd::SetLst<string> s_main_dict;
            lasd::List<string> list_ins_dict, list_rem_dict, list_empty_dict;
            
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, string("10")); 
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, string("20")); 
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, string("10")); 
            
            InsertAtBack(loctestnum, loctesterr, list_rem_dict, true, string("20")); 
            InsertAtBack(loctestnum, loctesterr, list_rem_dict, true, string("30"));

            InsertAllC(loctestnum, loctesterr, s_main_dict, false, list_ins_dict); 
            Exists(loctestnum, loctesterr, s_main_dict, true, string("10"));
            Exists(loctestnum, loctesterr, s_main_dict, true, string("20"));
            
            InsertAllC(loctestnum, loctesterr, s_main_dict, false, list_ins_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 2); 

            RemoveAll(loctestnum, loctesterr, s_main_dict, false, list_rem_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 1);
            Exists(loctestnum, loctesterr, s_main_dict, false, string("20")); 
            Exists(loctestnum, loctesterr, s_main_dict, true, string("10"));
            
            RemoveAll(loctestnum, loctesterr, s_main_dict, false, list_rem_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 1); 

            s_main_dict.Clear(); InsertC(loctestnum, loctesterr, s_main_dict, true, string("05")); 

            InsertSomeC(loctestnum, loctesterr, s_main_dict, true, list_ins_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 3); 
            Exists(loctestnum, loctesterr, s_main_dict, true, string("10")); 
            Exists(loctestnum, loctesterr, s_main_dict, true, string("20"));
            
            InsertSomeC(loctestnum, loctesterr, s_main_dict, false, list_ins_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 3);

            RemoveSome(loctestnum, loctesterr, s_main_dict, true, list_rem_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 2);
            Exists(loctestnum, loctesterr, s_main_dict, false, string("20")); 
            Exists(loctestnum, loctesterr, s_main_dict, true, string("10")); 
            Exists(loctestnum, loctesterr, s_main_dict, true, string("05"));
            
            lasd::List<string> list_rem_dict_for_throw;
            InsertAtBack(loctestnum, loctesterr, list_rem_dict_for_throw, true, string("30")); 
            InsertAtBack(loctestnum, loctesterr, list_rem_dict_for_throw, true, string("05")); 
          
            loctestnum++;
            s_main_dict.RemoveSome(list_rem_dict_for_throw); 
            
            Size(loctestnum, loctesterr, s_main_dict, false, 2); 
            Exists(loctestnum, loctesterr, s_main_dict, false, string("05")); 
            Exists(loctestnum, loctesterr, s_main_dict, true, string("10")); 
        }

        // Traversable/Mappable operations
        {
            lasd::SetLst<string> s_trav, s_empty_trav;
            InsertC(loctestnum, loctesterr, s_trav, true, string("10"));
            InsertC(loctestnum, loctesterr, s_trav, true, string("30"));
            InsertC(loctestnum, loctesterr, s_trav, true, string("20")); 
            
            TraversePreOrder(loctestnum, loctesterr, s_trav, true, &TraversePrint<string>); 
            TraversePostOrder(loctestnum, loctesterr, s_trav, true, &TraversePrint<string>); 

            FoldPreOrder(loctestnum, loctesterr, s_trav, true, &FoldAdd<string>, string(""), string("102030")); 
            FoldPostOrder(loctestnum, loctesterr, s_trav, true, &FoldAdd<string>, string(""), string("302010")); 

            TraversePreOrder(loctestnum, loctesterr, s_empty_trav, true, &TraversePrint<string>); 
            FoldPreOrder(loctestnum, loctesterr, s_empty_trav, true, &FoldAdd<string>, string(""), string(""));
        }
        
        // 14. Clear
        {
            lasd::SetLst<string> s_clear_reuse;
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, string("str100"));
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, string("str050"));
            s_clear_reuse.Clear();
            Empty(loctestnum, loctesterr, s_clear_reuse, true);
            Size(loctestnum, loctesterr, s_clear_reuse, true, 0);
            Min(loctestnum, loctesterr, s_clear_reuse, false, string("")); 

            InsertC(loctestnum, loctesterr, s_clear_reuse, true, string("s01"));
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, string("s02"));
            Size(loctestnum, loctesterr, s_clear_reuse, true, 2);
            GetAt(loctestnum, loctesterr, s_clear_reuse, true, 0, string("s01")); 
            s_clear_reuse.Clear();
            Empty(loctestnum, loctesterr, s_clear_reuse, true);
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MySetLst<string> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}


/* ************************************************************************** */

void setlst_test(uint &testnum, uint &testerr)
{
    mysetlst_int(testnum, testerr);
    mysetlst_double(testnum, testerr);
    mysetlst_string(testnum, testerr);
}