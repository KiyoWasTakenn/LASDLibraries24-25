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
       // Default constructor and basic checks
        {
            lasd::SetVec<int> s_default;
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
            lasd::SetVec<int> s_single;
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

            PredecessorNRemove(loctestnum, loctesterr, s_single, false, 5, 0);
            Size(loctestnum, loctesterr, s_single, true, 1);
            SuccessorNRemove(loctestnum, loctesterr, s_single, false, 15, 0);
            Size(loctestnum, loctesterr, s_single, true, 1);
            
            
            try
            {
                loctestnum++;
                s_single.RemovePredecessor(10);
                testerr++; cout << endl << "Error! s_single.RemovePredecessor(10)" << endl;
            }
            catch (const std::logic_error& ){}
            catch (...)
            {
                testerr++; cout << endl << "Error! s_single.RemovePredecessor(10)" << endl;
            }

            Size(loctestnum, loctesterr, s_single, true, 1); 

            try
            {
                loctestnum++;
                s_single.RemoveSuccessor(10);
                testerr++; cout << endl << "Error! s_single.RemoveSuccessor(10)" << endl;
            }
            catch (const std::logic_error& ){}
            catch (...)
            {
                testerr++; cout << endl << "Error! s_single.RemoveSuccessor(10)" << endl;
            }
            Size(loctestnum, loctesterr, s_single, true, 1); 

            try
            {
                loctestnum++;
                s_single.RemovePredecessor(5);
                testerr++; cout << endl << "Error! s_single.RemovePredecessor(5)" << endl;
            }
            catch (const std::logic_error& ){}
            catch (...) { testerr++; cout << endl << "Error! s_single.RemovePredecessor(5)" << endl; }
            Size(loctestnum, loctesterr, s_single, true, 1); 


            try
            {
                loctestnum++;
                s_single.RemoveSuccessor(15);
                testerr++; cout << endl << "Error! s_single.RemoveSuccessor(15)" << endl;
            }
            catch (const std::logic_error& ){}
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_single.RemoveSuccessor(15)" << endl;
            }
            Size(loctestnum, loctesterr, s_single, true, 1);

            Remove(loctestnum, loctesterr, s_single, true, 10);
            Empty(loctestnum, loctesterr, s_single, true);
            Size(loctestnum, loctesterr, s_single, true, 0);
            s_single.Clear();
        }

        // Multi-Element Set
        {
            lasd::SetVec<int> s1;
            InsertC(loctestnum, loctesterr, s1, true, 10); 
            InsertC(loctestnum, loctesterr, s1, true, 5);  
            InsertC(loctestnum, loctesterr, s1, true, 15); 
            InsertC(loctestnum, loctesterr, s1, true, 20);
            Size(loctestnum, loctesterr, s1, true, 4); 
            GetAt(loctestnum, loctesterr, s1, true, 0, 5);
            GetAt(loctestnum, loctesterr, s1, true, 1, 10);
            GetAt(loctestnum, loctesterr, s1, true, 2, 15);
            GetAt(loctestnum, loctesterr, s1, true, 3, 20);
            Exists(loctestnum, loctesterr, s1, true, 15);
            Exists(loctestnum, loctesterr, s1, false, 25);
            Min(loctestnum, loctesterr, s1, true, 5);
            Max(loctestnum, loctesterr, s1, true, 20);

            Predecessor(loctestnum, loctesterr, s1, true, 10, 5);
            Successor(loctestnum, loctesterr, s1, true, 10, 15);
            Predecessor(loctestnum, loctesterr, s1, false, 5, 0);
            Successor(loctestnum, loctesterr, s1, false, 20, 0);
            Predecessor(loctestnum, loctesterr, s1, false, 7, 0);
            Successor(loctestnum, loctesterr, s1, false, 7, 0);
            Predecessor(loctestnum, loctesterr, s1, true, 12, 10);
            Successor(loctestnum, loctesterr, s1, true, 12, 15);

            PredecessorNRemove(loctestnum, loctesterr, s1, true, 15, 10); 
            Size(loctestnum, loctesterr, s1, true, 3); 
            Exists(loctestnum, loctesterr, s1, false, 10); 
            GetAt(loctestnum, loctesterr, s1, true, 1, 15); 

            SuccessorNRemove(loctestnum, loctesterr, s1, true, 5, 15); 
            Size(loctestnum, loctesterr, s1, true, 2); 
            Exists(loctestnum, loctesterr, s1, false, 15);
            GetAt(loctestnum, loctesterr, s1, true, 1, 20); 

            PredecessorNRemove(loctestnum, loctesterr, s1, false, 5, 0);
            Size(loctestnum, loctesterr, s1, true, 2);
            SuccessorNRemove(loctestnum, loctesterr, s1, false, 20, 0);
            Size(loctestnum, loctesterr, s1, true, 2);

            PredecessorNRemove(loctestnum, loctesterr, s1, false, 3, 0);
            Size(loctestnum, loctesterr, s1, true, 2);
            SuccessorNRemove(loctestnum, loctesterr, s1, false, 25, 0); 
            Size(loctestnum, loctesterr, s1, true, 2);

            InsertC(loctestnum, loctesterr, s1, true, 30); 
            PredecessorNRemove(loctestnum, loctesterr, s1, true, 25, 20); 
            Size(loctestnum, loctesterr, s1, true, 2);
            Exists(loctestnum, loctesterr, s1, false, 20);
            GetAt(loctestnum, loctesterr, s1, true, 1, 30);

            InsertC(loctestnum, loctesterr, s1, true, 15); 
            SuccessorNRemove(loctestnum, loctesterr, s1, true, 10, 15);
            Size(loctestnum, loctesterr, s1, true, 2);
            Exists(loctestnum, loctesterr, s1, false, 15);
            GetAt(loctestnum, loctesterr, s1, true, 0, 5);
            
            s1.Clear(); 
            InsertC(loctestnum, loctesterr, s1, true, 10);
            InsertC(loctestnum, loctesterr, s1, true, 20);
            InsertC(loctestnum, loctesterr, s1, true, 30); 
            
            try
            {
                loctestnum++;
                s1.RemovePredecessor(5);
                testerr++; cout << endl << "Error! s1.RemovePredecessor(5)" << endl;
            }
            catch (const std::logic_error& ) {}
            catch (...) { testerr++; cout << endl << "Error! s1.RemovePredecessor(5)" << endl; }
            Size(loctestnum, loctesterr, s1, true, 3); 

            try
            {
                loctestnum++;
                s1.RemoveSuccessor(35);
                testerr++; cout << endl << "Error! s1.RemoveSuccessor(35)" << endl;
            }
            catch (const std::logic_error& ) {}
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s1.RemoveSuccessor(35)" << endl;
            }
            Size(loctestnum, loctesterr, s1, true, 3); 

            try
            {
                loctestnum++;
                s1.RemovePredecessor(10);
                testerr++; cout << endl << "Error! s1.RemovePredecessor(10)" << endl;
            }
            catch (const std::logic_error& ) {}
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s1.RemovePredecessor(10)" << endl;
            }
            Size(loctestnum, loctesterr, s1, true, 3); 

            try
            {
                loctestnum++;
                s1.RemoveSuccessor(30);
                testerr++; cout << endl << "Error! s1.RemoveSuccessor(30)" << endl;
            }
            catch (const std::logic_error& ) {}
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s1.RemoveSuccessor(30)" << endl;
            }
            Size(loctestnum, loctesterr, s1, true, 3);

            try
            {
                loctestnum++;
                s1.RemovePredecessor(20); 
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s1.RemovePredecessor(20)" << e.what() << endl;
            }
            catch (...) 
            { 
                testerr++;
                cout << endl << "Error! s1.RemovePredecessor(20)" << endl; 
            }
            Size(loctestnum, loctesterr, s1, true, 2);
            Exists(loctestnum, loctesterr, s1, false, 10);
            Exists(loctestnum, loctesterr, s1, true, 20);
            Exists(loctestnum, loctesterr, s1, true, 30);
            GetAt(loctestnum, loctesterr, s1, true, 0, 20);

            try
            {
                loctestnum++;
                s1.RemoveSuccessor(20);
            }
            catch (const std::exception& e)
            { 
                testerr++;
                cout << endl << "Error! s1.RemoveSuccessor(20)" << e.what() << endl;
            }
            catch (...)
            { 
                testerr++;
                cout << endl << "Error! s1.RemoveSuccessor(20)" << endl; 
            }
            Size(loctestnum, loctesterr, s1, true, 1);
            Exists(loctestnum, loctesterr, s1, false, 30);
            Exists(loctestnum, loctesterr, s1, true, 20);
            GetAt(loctestnum, loctesterr, s1, true, 0, 20);
            
            s1.Clear();
        }

        // Insertions 
        {
            lasd::SetVec<int> s_resize;
            for (int i = 0; i < 20; ++i)
                InsertC(loctestnum, loctesterr, s_resize, true, i * 10);

            Size(loctestnum, loctesterr, s_resize, true, 20);
            Exists(loctestnum, loctesterr, s_resize, true, 190);
            GetAt(loctestnum, loctesterr, s_resize, true, 10, 100);
        }

        // Removals
        {
            lasd::SetVec<int> s_resize_rem;
            for (int i = 0; i < 30; ++i) 
                InsertC(loctestnum, loctesterr, s_resize_rem, true, i);
            
            Size(loctestnum, loctesterr, s_resize_rem, true, 30);
            for (int i = 0; i < 25; ++i) 
                Remove(loctestnum, loctesterr, s_resize_rem, true, i);
            
            Size(loctestnum, loctesterr, s_resize_rem, true, 5);
            Exists(loctestnum, loctesterr, s_resize_rem, true, 29);
            Exists(loctestnum, loctesterr, s_resize_rem, false, 0);
        }

        // Wrap-around
        {
            lasd::SetVec<int> s_wrap1; 
            InsertC(loctestnum, loctesterr, s_wrap1, true, 20);
            InsertC(loctestnum, loctesterr, s_wrap1, true, 30); 
            InsertC(loctestnum, loctesterr, s_wrap1, true, 40);
            InsertC(loctestnum, loctesterr, s_wrap1, true, 50); 
            InsertC(loctestnum, loctesterr, s_wrap1, true, 10); 
            
            MinNRemove(loctestnum, loctesterr, s_wrap1, true, 10); 
            MinNRemove(loctestnum, loctesterr, s_wrap1, true, 20); 
            
            InsertC(loctestnum, loctesterr, s_wrap1, true, 5);  
            Size(loctestnum, loctesterr, s_wrap1, true, 4);
            GetAt(loctestnum, loctesterr, s_wrap1, true, 0, 5); 
            GetAt(loctestnum, loctesterr, s_wrap1, true, 1, 30);

            InsertC(loctestnum, loctesterr, s_wrap1, true, 15); 
            Size(loctestnum, loctesterr, s_wrap1, true, 5);
            GetAt(loctestnum, loctesterr, s_wrap1, true, 1, 15);
            InsertC(loctestnum, loctesterr, s_wrap1, true, 1); 
            Size(loctestnum, loctesterr, s_wrap1, true, 6);
            GetAt(loctestnum, loctesterr, s_wrap1, true, 0, 1);

            s_wrap1.Clear(); 
            for(int i=0; i<5; ++i)
                InsertC(loctestnum, loctesterr, s_wrap1, true, (i+1)*10); 

            Remove(loctestnum, loctesterr, s_wrap1, true, 10); 
            GetAt(loctestnum, loctesterr, s_wrap1, true, 0, 20);
            Remove(loctestnum, loctesterr, s_wrap1, true, 50); 
            GetAt(loctestnum, loctesterr, s_wrap1, true, 2, 40);
            Max(loctestnum, loctesterr, s_wrap1, true, 40);
            Size(loctestnum, loctesterr, s_wrap1, true, 3);

            lasd::SetVec<int> s_idx_rem; 
            InsertC(loctestnum, loctesterr, s_idx_rem, true, 1);
            InsertC(loctestnum, loctesterr, s_idx_rem, true, 2); 
            InsertC(loctestnum, loctesterr, s_idx_rem, true, 3);
            InsertC(loctestnum, loctesterr, s_idx_rem, true, 4); 
            InsertC(loctestnum, loctesterr, s_idx_rem, true, 5); 
            Remove(loctestnum, loctesterr, s_idx_rem, true, 1); 
            GetAt(loctestnum, loctesterr, s_idx_rem, true, 0, 2);
            Remove(loctestnum, loctesterr, s_idx_rem, true, 5); 
            GetAt(loctestnum, loctesterr, s_idx_rem, true, 2, 4);
            Max(loctestnum, loctesterr, s_idx_rem, true, 4);
            Remove(loctestnum, loctesterr, s_idx_rem, true, 3); 
            GetAt(loctestnum, loctesterr, s_idx_rem, true, 0, 2);
            GetAt(loctestnum, loctesterr, s_idx_rem, true, 1, 4);

            lasd::SetVec<int> s_empty_reuse;
            InsertC(loctestnum, loctesterr, s_empty_reuse, true, 10);
            InsertC(loctestnum, loctesterr, s_empty_reuse, true, 20);
            InsertC(loctestnum, loctesterr, s_empty_reuse, true, 30);
            Remove(loctestnum, loctesterr, s_empty_reuse, true, 10); 
            Remove(loctestnum, loctesterr, s_empty_reuse, true, 20); 
            Remove(loctestnum, loctesterr, s_empty_reuse, true, 30); 
            Empty(loctestnum, loctesterr, s_empty_reuse, true);
            InsertC(loctestnum, loctesterr, s_empty_reuse, true, 5); 
            GetAt(loctestnum, loctesterr, s_empty_reuse, true, 0, 5);
            s_empty_reuse.Clear();
        }

        // Copy constructor
        {
            lasd::SetVec<int> s_orig;
            InsertC(loctestnum, loctesterr, s_orig, true, 1);
            InsertC(loctestnum, loctesterr, s_orig, true, 2);
            InsertC(loctestnum, loctesterr, s_orig, true, 3);
            lasd::SetVec<int> s_copy(s_orig);
            Size(loctestnum, loctesterr, s_copy, true, 3);
            EqualSetVec(loctestnum, loctesterr, s_orig, s_copy, true);
            Remove(loctestnum, loctesterr, s_copy, true, 2);
            Size(loctestnum, loctesterr, s_orig, true, 3); 
            Exists(loctestnum, loctesterr, s_orig, true, 2);
            Exists(loctestnum, loctesterr, s_copy, false, 2);
        }

        // Move constructor
        {
            lasd::SetVec<int> s_orig_move;
            InsertC(loctestnum, loctesterr, s_orig_move, true, 10);
            InsertC(loctestnum, loctesterr, s_orig_move, true, 20);
            lasd::SetVec<int> s_moved(std::move(s_orig_move));
            Size(loctestnum, loctesterr, s_moved, true, 2);
            Exists(loctestnum, loctesterr, s_moved, true, 10);
            Empty(loctestnum, loctesterr, s_orig_move, true); 
            Size(loctestnum, loctesterr, s_orig_move, true, 0);
        }

        // Copy assignment
        {
            lasd::SetVec<int> s_orig_assign, s_assigned;
            InsertC(loctestnum, loctesterr, s_orig_assign, true, 100);
            InsertC(loctestnum, loctesterr, s_orig_assign, true, 200);
            InsertC(loctestnum, loctesterr, s_assigned, true, 5); 
            s_assigned = s_orig_assign;
            Size(loctestnum, loctesterr, s_assigned, true, 2);
            EqualSetVec(loctestnum, loctesterr, s_orig_assign, s_assigned, true);
            Remove(loctestnum, loctesterr, s_assigned, true, 100);
            Size(loctestnum, loctesterr, s_orig_assign, true, 2); 
            Exists(loctestnum, loctesterr, s_orig_assign, true, 100);
            s_assigned = s_assigned; 
            Size(loctestnum, loctesterr, s_assigned, true, 1);
            Exists(loctestnum, loctesterr, s_assigned, true, 200);
        }

        // Move assignment

        {
            lasd::SetVec<int> s_orig_move_assign, s_moved_assign;
            InsertC(loctestnum, loctesterr, s_orig_move_assign, true, 30);
            InsertC(loctestnum, loctesterr, s_orig_move_assign, true, 40);
            InsertC(loctestnum, loctesterr, s_moved_assign, true, 7); 
            s_moved_assign = std::move(s_orig_move_assign);
            Size(loctestnum, loctesterr, s_moved_assign, true, 2);
            Exists(loctestnum, loctesterr, s_moved_assign, true, 30);
            Empty(loctestnum, loctesterr, s_orig_move_assign, false); 
            Size(loctestnum, loctesterr, s_orig_move_assign, true, 1);
            
            // lasd::SetVec<int> s_self_move;
            // InsertC(loctestnum, loctesterr, s_self_move, true, 55);
            // s_self_move = std::move(s_self_move); 
            // Size(loctestnum, loctesterr, s_self_move, true, 1); 
            // Exists(loctestnum, loctesterr, s_self_move, true, 55);
        }
        {
            lasd::SortableVector<int> svec_empty_src(0);
            lasd::SetVec<int> set_from_svec_empty_copy(svec_empty_src);
            Empty(loctestnum, loctesterr, set_from_svec_empty_copy, true);
            Size(loctestnum, loctesterr, set_from_svec_empty_copy, true, 0);

            lasd::SortableVector<int> svec_src(5);
            SetAt(loctestnum, loctesterr, svec_src, true, 0, 30);
            SetAt(loctestnum, loctesterr, svec_src, true, 1, 10);
            SetAt(loctestnum, loctesterr, svec_src, true, 2, 20);
            SetAt(loctestnum, loctesterr, svec_src, true, 3, 10);
            SetAt(loctestnum, loctesterr, svec_src, true, 4, 30);
            lasd::SetVec<int> set_from_svec_copy(svec_src);
            Size(loctestnum, loctesterr, set_from_svec_copy, true, 3);
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, 10);
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, 20);
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, 30);
            GetAt(loctestnum, loctesterr, set_from_svec_copy, true, 0, 10); 
            Size(loctestnum, loctesterr, svec_src, true, 5); 

            lasd::List<int> list_empty_src;
            lasd::SetVec<int> set_from_list_empty_copy(list_empty_src);
            Empty(loctestnum, loctesterr, set_from_list_empty_copy, true);

            lasd::List<int> list_src;
            InsertAtBack(loctestnum, loctesterr, list_src, true, 50);
            InsertAtFront(loctestnum, loctesterr, list_src, true, 40);
            InsertAtBack(loctestnum, loctesterr, list_src, true, 50);
            InsertAtFront(loctestnum, loctesterr, list_src, true, 60); 
            lasd::SetVec<int> set_from_list_copy(list_src);
            Size(loctestnum, loctesterr, set_from_list_copy, true, 3); 
            Exists(loctestnum, loctesterr, set_from_list_copy, true, 40);
            Exists(loctestnum, loctesterr, set_from_list_copy, true, 60);
            GetAt(loctestnum, loctesterr, set_from_list_copy, true, 1, 50); 
            Size(loctestnum, loctesterr, list_src, true, 4); 

            lasd::SetLst<int> setlst_empty_src;
            lasd::SetVec<int> set_from_setlst_empty_copy(setlst_empty_src);
            Empty(loctestnum, loctesterr, set_from_setlst_empty_copy, true);

            lasd::SetLst<int> setlst_src;
            InsertC(loctestnum, loctesterr, setlst_src, true, 80);
            InsertC(loctestnum, loctesterr, setlst_src, true, 70);
            InsertC(loctestnum, loctesterr, setlst_src, true, 90); 
            lasd::SetVec<int> set_from_setlst_copy(setlst_src);
            Size(loctestnum, loctesterr, set_from_setlst_copy, true, 3);
            Exists(loctestnum, loctesterr, set_from_setlst_copy, true, 70);
            Exists(loctestnum, loctesterr, set_from_setlst_copy, true, 90);
            GetAt(loctestnum, loctesterr, set_from_setlst_copy, true, 1, 80);
            Size(loctestnum, loctesterr, setlst_src, true, 3);
        }

        {
            lasd::SortableVector<int> svec_empty_src_move(0);
            lasd::SetVec<int> set_from_svec_empty_move(std::move(svec_empty_src_move));
            Empty(loctestnum, loctesterr, set_from_svec_empty_move, true);
            Empty(loctestnum, loctesterr, svec_empty_src_move, true); 

            lasd::SortableVector<int> svec_src_move(5);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 0, 30);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 1, 10);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 2, 20);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 3, 10);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 4, 30);
            lasd::SetVec<int> set_from_svec_move(std::move(svec_src_move));
            Size(loctestnum, loctesterr, set_from_svec_move, true, 3);
            Exists(loctestnum, loctesterr, set_from_svec_move, true, 10);
            GetAt(loctestnum, loctesterr, set_from_svec_move, true, 2, 30);
            Empty(loctestnum, loctesterr, svec_src_move, false);

            lasd::List<int> list_empty_src_move;
            lasd::SetVec<int> set_from_list_empty_move(std::move(list_empty_src_move));
            Empty(loctestnum, loctesterr, set_from_list_empty_move, true);
            Empty(loctestnum, loctesterr, list_empty_src_move, true);

            lasd::List<int> list_src_move;
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, 50);
            InsertAtFront(loctestnum, loctesterr, list_src_move, true, 40);
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, 50);
            InsertAtFront(loctestnum, loctesterr, list_src_move, true, 60);
            lasd::SetVec<int> set_from_list_move(std::move(list_src_move));
            Size(loctestnum, loctesterr, set_from_list_move, true, 3); 
            Exists(loctestnum, loctesterr, set_from_list_move, true, 50);
            GetAt(loctestnum, loctesterr, set_from_list_move, true, 0, 40);
            Empty(loctestnum, loctesterr, list_src_move, false); 
        }
        {
            lasd::SetVec<int> s1_comp, s2_comp, s3_order_comp, s4_diff_val_comp, s5_diff_size_comp;
            InsertC(loctestnum, loctesterr, s1_comp, true, 1);
            InsertC(loctestnum, loctesterr, s1_comp, true, 2);
            InsertC(loctestnum, loctesterr, s1_comp, true, 3);

            InsertC(loctestnum, loctesterr, s2_comp, true, 1);
            InsertC(loctestnum, loctesterr, s2_comp, true, 2);
            InsertC(loctestnum, loctesterr, s2_comp, true, 3);
            EqualSetVec(loctestnum, loctesterr, s1_comp, s2_comp, true);

            InsertC(loctestnum, loctesterr, s3_order_comp, true, 3);
            InsertC(loctestnum, loctesterr, s3_order_comp, true, 1);
            InsertC(loctestnum, loctesterr, s3_order_comp, true, 2);
            EqualSetVec(loctestnum, loctesterr, s1_comp, s3_order_comp, true);

            InsertC(loctestnum, loctesterr, s4_diff_val_comp, true, 1);
            InsertC(loctestnum, loctesterr, s4_diff_val_comp, true, 2);
            InsertC(loctestnum, loctesterr, s4_diff_val_comp, true, 4);
            NonEqualSetVec(loctestnum, loctesterr, s1_comp, s4_diff_val_comp, true);

            InsertC(loctestnum, loctesterr, s5_diff_size_comp, true, 1);
            InsertC(loctestnum, loctesterr, s5_diff_size_comp, true, 2);
            NonEqualSetVec(loctestnum, loctesterr, s1_comp, s5_diff_size_comp, true);

            lasd::SetVec<int> empty1_comp, empty2_comp;
            EqualSetVec(loctestnum, loctesterr, empty1_comp, empty2_comp, true);
            NonEqualSetVec(loctestnum, loctesterr, empty1_comp, s1_comp, true);
        }
        {
            lasd::SetVec<int> s_main_dict;
            lasd::SortableVector<int> vec_ins_dict(5);
            lasd::SortableVector<int> vec_rem_dict(3);
            lasd::SortableVector<int> vec_empty_dict(0);
            lasd::List<int> list_ins_dict, list_rem_dict, list_empty_dict;

            InsertC(loctestnum, loctesterr, s_main_dict, true, 10);
            InsertC(loctestnum, loctesterr, s_main_dict, true, 20);
            
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 0, 20); 
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 1, 30);
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 2, 40);
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 3, 5);
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 4, 30); 

            s_main_dict.InsertAll(vec_ins_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 5);
            Exists(loctestnum, loctesterr, s_main_dict, true, 5);
            Exists(loctestnum, loctesterr, s_main_dict, true, 40);

            s_main_dict.InsertAll(vec_empty_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 5);
            
            SetAt(loctestnum, loctesterr, vec_rem_dict, true, 0, 15); 
            SetAt(loctestnum, loctesterr, vec_rem_dict, true, 1, 20); 
            SetAt(loctestnum, loctesterr, vec_rem_dict, true, 2, 40); 
            s_main_dict.RemoveAll(vec_rem_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 3);
            Exists(loctestnum, loctesterr, s_main_dict, false, 20);
            Exists(loctestnum, loctesterr, s_main_dict, false, 40);

            s_main_dict.RemoveAll(vec_empty_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 3);

            s_main_dict.Clear(); 
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, 1);
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, 2);
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, 1); 
            
            try
            {
                loctestnum++;
                bool result = s_main_dict.InsertSome(list_ins_dict);
                if (result != true)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict) [1]";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict) [1]";
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict) [1] ";
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 2);

            try
            {
                loctestnum++;
                bool result = s_main_dict.InsertSome(list_ins_dict);
                if (result != false)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict) [2] returned ";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict) [2]";
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict) [2]";
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 2);

            try
            {
                loctestnum++;
                bool result = s_main_dict.InsertSome(list_empty_dict);
                if (result != false)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.InsertSome(list_empty_dict)";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_empty_dict)" << e.what() << endl;
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_empty_dict)" << endl;
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 2);
            
            InsertAtBack(loctestnum, loctesterr, list_rem_dict, true, 2); 
            InsertAtBack(loctestnum, loctesterr, list_rem_dict, true, 3); 

            try
            {
                loctestnum++;
                bool result = s_main_dict.RemoveSome(list_rem_dict);
                if (result != true)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict) [1]";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict) [1]" << e.what() << endl;
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict) [1]" << endl;
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 1);

            try
            {
                loctestnum++;
                bool result = s_main_dict.RemoveSome(list_rem_dict);
                if (result != false)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict) [2]";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict) [2] threw an unexpected exception: " << e.what() << endl;
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict) [2] " << endl;
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 1);

            try
            {
                loctestnum++;
                bool result = s_main_dict.RemoveSome(list_empty_dict);
                if (result != false)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.RemoveSome(list_empty_dict)";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_empty_dict)" << e.what() << endl;
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_empty_dict)" << endl;
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 1);
        }
        {
            lasd::SetVec<int> s_trav, s_empty_trav; 
            InsertC(loctestnum, loctesterr, s_trav, true, 30);
            InsertC(loctestnum, loctesterr, s_trav, true, 10);
            InsertC(loctestnum, loctesterr, s_trav, true, 20); 
            
            TraversePreOrder(loctestnum, loctesterr, s_trav, true, &TraversePrint<int>); 
            TraversePostOrder(loctestnum, loctesterr, s_trav, true, &TraversePrint<int>);

            FoldPreOrder(loctestnum, loctesterr, s_trav, true, &FoldAdd<int>, 0, 60); 
            FoldPostOrder(loctestnum, loctesterr, s_trav, true, &FoldAdd<int>, 0, 60); 

            TraversePreOrder(loctestnum, loctesterr, s_empty_trav, true, &TraversePrint<int>); 
            FoldPreOrder(loctestnum, loctesterr, s_empty_trav, true, &FoldAdd<int>, 0, 0);
        }
        // Clear
        {
            lasd::SetVec<int> s_clear_reuse;
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 100);
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 200);
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 50);
            Remove(loctestnum, loctesterr, s_clear_reuse, true, 50);
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
            Size(loctestnum, loctesterr, s_clear_reuse, true, 0);
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MySetVec<int> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mysetvec_double(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        cout << endl<< "############################################################################"<< endl;
        cout << endl << "---------------------- Begin of MySetVec<double> tests: ----------------------" << endl;

        // Default constructor and basic checks
        {
            lasd::SetVec<double> s_default;
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
        }

        // Single Element Set
        {
            lasd::SetVec<double> s_single;
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

            PredecessorNRemove(loctestnum, loctesterr, s_single, false, 5.0, 0.0);
            Size(loctestnum, loctesterr, s_single, true, 1);
            SuccessorNRemove(loctestnum, loctesterr, s_single, false, 15.0, 0.0);
            Size(loctestnum, loctesterr, s_single, true, 1);
            
            
            try
            {
                loctestnum++;
                s_single.RemovePredecessor(10.0);
                testerr++; cout << endl << "Error! s_single.RemovePredecessor(10.0)" << endl;
            }
            catch (const std::logic_error& ){}
            catch (...)
            {
                testerr++; cout << endl << "Error! s_single.RemovePredecessor(10.0) wrong exception" << endl;
            }

            Size(loctestnum, loctesterr, s_single, true, 1); 

            try
            {
                loctestnum++;
                s_single.RemoveSuccessor(10.0);
                testerr++; cout << endl << "Error! s_single.RemoveSuccessor(10.0)" << endl;
            }
            catch (const std::logic_error& ){}
            catch (...)
            {
                testerr++; cout << endl << "Error! s_single.RemoveSuccessor(10.0) wrong exception" << endl;
            }
            Size(loctestnum, loctesterr, s_single, true, 1); 

            try
            {
                loctestnum++;
                s_single.RemovePredecessor(5.0);
                testerr++; cout << endl << "Error! s_single.RemovePredecessor(5.0)" << endl;
            }
            catch (const std::logic_error& ){}
            catch (...) { testerr++; cout << endl << "Error! s_single.RemovePredecessor(5.0) wrong exception" << endl; }
            Size(loctestnum, loctesterr, s_single, true, 1); 


            try
            {
                loctestnum++;
                s_single.RemoveSuccessor(15.0);
                testerr++; cout << endl << "Error! s_single.RemoveSuccessor(15.0)" << endl;
            }
            catch (const std::logic_error& ){}
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_single.RemoveSuccessor(15.0) wrong exception" << endl;
            }
            Size(loctestnum, loctesterr, s_single, true, 1);

            Remove(loctestnum, loctesterr, s_single, true, 10.0);
            Empty(loctestnum, loctesterr, s_single, true);
            Size(loctestnum, loctesterr, s_single, true, 0);
            s_single.Clear();
        }

        // Multi-Element Set
        {
            lasd::SetVec<double> s1;
            InsertC(loctestnum, loctesterr, s1, true, 10.0); 
            InsertC(loctestnum, loctesterr, s1, true, 5.0);  
            InsertC(loctestnum, loctesterr, s1, true, 15.0); 
            InsertC(loctestnum, loctesterr, s1, true, 20.0);
            Size(loctestnum, loctesterr, s1, true, 4); 
            GetAt(loctestnum, loctesterr, s1, true, 0, 5.0);
            GetAt(loctestnum, loctesterr, s1, true, 1, 10.0);
            GetAt(loctestnum, loctesterr, s1, true, 2, 15.0);
            GetAt(loctestnum, loctesterr, s1, true, 3, 20.0);
            Exists(loctestnum, loctesterr, s1, true, 15.0);
            Exists(loctestnum, loctesterr, s1, false, 25.0);
            Min(loctestnum, loctesterr, s1, true, 5.0);
            Max(loctestnum, loctesterr, s1, true, 20.0);

            Predecessor(loctestnum, loctesterr, s1, true, 10.0, 5.0);
            Successor(loctestnum, loctesterr, s1, true, 10.0, 15.0);
            Predecessor(loctestnum, loctesterr, s1, false, 5.0, 0.0);
            Successor(loctestnum, loctesterr, s1, false, 20.0, 0.0);
            Predecessor(loctestnum, loctesterr, s1, false, 7.0, 0.0);
            Successor(loctestnum, loctesterr, s1, false, 7.0, 0.0);
            Predecessor(loctestnum, loctesterr, s1, true, 12.0, 10.0);
            Successor(loctestnum, loctesterr, s1, true, 12.0, 15.0);

            PredecessorNRemove(loctestnum, loctesterr, s1, true, 15.0, 10.0); 
            Size(loctestnum, loctesterr, s1, true, 3); 
            Exists(loctestnum, loctesterr, s1, false, 10.0); 
            GetAt(loctestnum, loctesterr, s1, true, 1, 15.0); 

            SuccessorNRemove(loctestnum, loctesterr, s1, true, 5.0, 15.0); 
            Size(loctestnum, loctesterr, s1, true, 2); 
            Exists(loctestnum, loctesterr, s1, false, 15.0);
            GetAt(loctestnum, loctesterr, s1, true, 1, 20.0); 

            PredecessorNRemove(loctestnum, loctesterr, s1, false, 5.0, 0.0);
            Size(loctestnum, loctesterr, s1, true, 2);
            SuccessorNRemove(loctestnum, loctesterr, s1, false, 20.0, 0.0);
            Size(loctestnum, loctesterr, s1, true, 2);

            PredecessorNRemove(loctestnum, loctesterr, s1, false, 3.0, 0.0);
            Size(loctestnum, loctesterr, s1, true, 2);
            SuccessorNRemove(loctestnum, loctesterr, s1, false, 25.0, 0.0); 
            Size(loctestnum, loctesterr, s1, true, 2);

            InsertC(loctestnum, loctesterr, s1, true, 30.0); 
            PredecessorNRemove(loctestnum, loctesterr, s1, true, 25.0, 20.0); 
            Size(loctestnum, loctesterr, s1, true, 2);
            Exists(loctestnum, loctesterr, s1, false, 20.0);
            GetAt(loctestnum, loctesterr, s1, true, 1, 30.0);

            InsertC(loctestnum, loctesterr, s1, true, 15.0); 
            SuccessorNRemove(loctestnum, loctesterr, s1, true, 10.0, 15.0);
            Size(loctestnum, loctesterr, s1, true, 2);
            Exists(loctestnum, loctesterr, s1, false, 15.0);
            GetAt(loctestnum, loctesterr, s1, true, 0, 5.0);
            
            s1.Clear(); 
            InsertC(loctestnum, loctesterr, s1, true, 10.0);
            InsertC(loctestnum, loctesterr, s1, true, 20.0);
            InsertC(loctestnum, loctesterr, s1, true, 30.0); 
            
            try
            {
                loctestnum++;
                s1.RemovePredecessor(5.0);
                testerr++; cout << endl << "Error! s1.RemovePredecessor(5.0)" << endl;
            }
            catch (const std::logic_error& ) {}
            catch (...) { testerr++; cout << endl << "Error! s1.RemovePredecessor(5.0) wrong exception" << endl; }
            Size(loctestnum, loctesterr, s1, true, 3); 

            try
            {
                loctestnum++;
                s1.RemoveSuccessor(35.0);
                testerr++; cout << endl << "Error! s1.RemoveSuccessor(35.0)" << endl;
            }
            catch (const std::logic_error& ) {}
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s1.RemoveSuccessor(35.0) wrong exception" << endl;
            }
            Size(loctestnum, loctesterr, s1, true, 3); 

            try
            {
                loctestnum++;
                s1.RemovePredecessor(10.0);
                testerr++; cout << endl << "Error! s1.RemovePredecessor(10.0)" << endl;
            }
            catch (const std::logic_error& ) {}
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s1.RemovePredecessor(10.0) wrong exception" << endl;
            }
            Size(loctestnum, loctesterr, s1, true, 3); 

            try
            {
                loctestnum++;
                s1.RemoveSuccessor(30.0);
                testerr++; cout << endl << "Error! s1.RemoveSuccessor(30.0)" << endl;
            }
            catch (const std::logic_error& ) {}
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s1.RemoveSuccessor(30.0) wrong exception" << endl;
            }
            Size(loctestnum, loctesterr, s1, true, 3);

            try
            {
                loctestnum++;
                s1.RemovePredecessor(20.0); 
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s1.RemovePredecessor(20.0) " << e.what() << endl;
            }
            catch (...) 
            { 
                testerr++;
                cout << endl << "Error! s1.RemovePredecessor(20.0) unknown exception" << endl; 
            }
            Size(loctestnum, loctesterr, s1, true, 2);
            Exists(loctestnum, loctesterr, s1, false, 10.0);
            Exists(loctestnum, loctesterr, s1, true, 20.0);
            Exists(loctestnum, loctesterr, s1, true, 30.0);
            GetAt(loctestnum, loctesterr, s1, true, 0, 20.0);

            try
            {
                loctestnum++;
                s1.RemoveSuccessor(20.0);
            }
            catch (const std::exception& e)
            { 
                testerr++;
                cout << endl << "Error! s1.RemoveSuccessor(20.0) " << e.what() << endl;
            }
            catch (...)
            { 
                testerr++;
                cout << endl << "Error! s1.RemoveSuccessor(20.0) unknown exception" << endl; 
            }
            Size(loctestnum, loctesterr, s1, true, 1);
            Exists(loctestnum, loctesterr, s1, false, 30.0);
            Exists(loctestnum, loctesterr, s1, true, 20.0);
            GetAt(loctestnum, loctesterr, s1, true, 0, 20.0);
            
            s1.Clear();
        }

        // Insertions 
        {
            lasd::SetVec<double> s_resize;
            for (int i = 0; i < 20; ++i)
                InsertC(loctestnum, loctesterr, s_resize, true, static_cast<double>(i * 10));

            Size(loctestnum, loctesterr, s_resize, true, 20);
            Exists(loctestnum, loctesterr, s_resize, true, 190.0);
            GetAt(loctestnum, loctesterr, s_resize, true, 10, 100.0);
        }

        // Removals
        {
            lasd::SetVec<double> s_resize_rem;
            for (int i = 0; i < 30; ++i) 
                InsertC(loctestnum, loctesterr, s_resize_rem, true, static_cast<double>(i));
            
            Size(loctestnum, loctesterr, s_resize_rem, true, 30);
            for (int i = 0; i < 25; ++i) 
                Remove(loctestnum, loctesterr, s_resize_rem, true, static_cast<double>(i));
            
            Size(loctestnum, loctesterr, s_resize_rem, true, 5);
            Exists(loctestnum, loctesterr, s_resize_rem, true, 29.0);
            Exists(loctestnum, loctesterr, s_resize_rem, false, 0.0);
        }

        // Wrap-around
        {
            lasd::SetVec<double> s_wrap1; 
            InsertC(loctestnum, loctesterr, s_wrap1, true, 20.0);
            InsertC(loctestnum, loctesterr, s_wrap1, true, 30.0); 
            InsertC(loctestnum, loctesterr, s_wrap1, true, 40.0);
            InsertC(loctestnum, loctesterr, s_wrap1, true, 50.0); 
            InsertC(loctestnum, loctesterr, s_wrap1, true, 10.0); 
            
            MinNRemove(loctestnum, loctesterr, s_wrap1, true, 10.0); 
            MinNRemove(loctestnum, loctesterr, s_wrap1, true, 20.0); 
            
            InsertC(loctestnum, loctesterr, s_wrap1, true, 5.0);  
            Size(loctestnum, loctesterr, s_wrap1, true, 4);
            GetAt(loctestnum, loctesterr, s_wrap1, true, 0, 5.0); 
            GetAt(loctestnum, loctesterr, s_wrap1, true, 1, 30.0);

            InsertC(loctestnum, loctesterr, s_wrap1, true, 15.0); 
            Size(loctestnum, loctesterr, s_wrap1, true, 5);
            GetAt(loctestnum, loctesterr, s_wrap1, true, 1, 15.0);
            InsertC(loctestnum, loctesterr, s_wrap1, true, 1.0); 
            Size(loctestnum, loctesterr, s_wrap1, true, 6);
            GetAt(loctestnum, loctesterr, s_wrap1, true, 0, 1.0);

            s_wrap1.Clear(); 
            for(int i=0; i<5; ++i)
                InsertC(loctestnum, loctesterr, s_wrap1, true, static_cast<double>((i+1)*10)); 

            Remove(loctestnum, loctesterr, s_wrap1, true, 10.0); 
            GetAt(loctestnum, loctesterr, s_wrap1, true, 0, 20.0);
            Remove(loctestnum, loctesterr, s_wrap1, true, 50.0); 
            GetAt(loctestnum, loctesterr, s_wrap1, true, 2, 40.0);
            Max(loctestnum, loctesterr, s_wrap1, true, 40.0);
            Size(loctestnum, loctesterr, s_wrap1, true, 3);

            lasd::SetVec<double> s_idx_rem; 
            InsertC(loctestnum, loctesterr, s_idx_rem, true, 1.0);
            InsertC(loctestnum, loctesterr, s_idx_rem, true, 2.0); 
            InsertC(loctestnum, loctesterr, s_idx_rem, true, 3.0);
            InsertC(loctestnum, loctesterr, s_idx_rem, true, 4.0); 
            InsertC(loctestnum, loctesterr, s_idx_rem, true, 5.0); 
            Remove(loctestnum, loctesterr, s_idx_rem, true, 1.0); 
            GetAt(loctestnum, loctesterr, s_idx_rem, true, 0, 2.0);
            Remove(loctestnum, loctesterr, s_idx_rem, true, 5.0); 
            GetAt(loctestnum, loctesterr, s_idx_rem, true, 2, 4.0);
            Max(loctestnum, loctesterr, s_idx_rem, true, 4.0);
            Remove(loctestnum, loctesterr, s_idx_rem, true, 3.0); 
            GetAt(loctestnum, loctesterr, s_idx_rem, true, 0, 2.0);
            GetAt(loctestnum, loctesterr, s_idx_rem, true, 1, 4.0);

            lasd::SetVec<double> s_empty_reuse;
            InsertC(loctestnum, loctesterr, s_empty_reuse, true, 10.0);
            InsertC(loctestnum, loctesterr, s_empty_reuse, true, 20.0);
            InsertC(loctestnum, loctesterr, s_empty_reuse, true, 30.0);
            Remove(loctestnum, loctesterr, s_empty_reuse, true, 10.0); 
            Remove(loctestnum, loctesterr, s_empty_reuse, true, 20.0); 
            Remove(loctestnum, loctesterr, s_empty_reuse, true, 30.0); 
            Empty(loctestnum, loctesterr, s_empty_reuse, true);
            InsertC(loctestnum, loctesterr, s_empty_reuse, true, 5.0); 
            GetAt(loctestnum, loctesterr, s_empty_reuse, true, 0, 5.0);
            s_empty_reuse.Clear();
        }

        // Copy constructor
        {
            lasd::SetVec<double> s_orig;
            InsertC(loctestnum, loctesterr, s_orig, true, 1.0);
            InsertC(loctestnum, loctesterr, s_orig, true, 2.0);
            InsertC(loctestnum, loctesterr, s_orig, true, 3.0);
            lasd::SetVec<double> s_copy(s_orig);
            Size(loctestnum, loctesterr, s_copy, true, 3);
            EqualSetVec(loctestnum, loctesterr, s_orig, s_copy, true);
            Remove(loctestnum, loctesterr, s_copy, true, 2.0);
            Size(loctestnum, loctesterr, s_orig, true, 3); 
            Exists(loctestnum, loctesterr, s_orig, true, 2.0);
            Exists(loctestnum, loctesterr, s_copy, false, 2.0);
        }

        // Move constructor
        {
            lasd::SetVec<double> s_orig_move;
            InsertC(loctestnum, loctesterr, s_orig_move, true, 10.0);
            InsertC(loctestnum, loctesterr, s_orig_move, true, 20.0);
            lasd::SetVec<double> s_moved(std::move(s_orig_move));
            Size(loctestnum, loctesterr, s_moved, true, 2);
            Exists(loctestnum, loctesterr, s_moved, true, 10.0);
            Empty(loctestnum, loctesterr, s_orig_move, true); 
            Size(loctestnum, loctesterr, s_orig_move, true, 0);
        }

        // Copy assignment
        {
            lasd::SetVec<double> s_orig_assign, s_assigned;
            InsertC(loctestnum, loctesterr, s_orig_assign, true, 100.0);
            InsertC(loctestnum, loctesterr, s_orig_assign, true, 200.0);
            InsertC(loctestnum, loctesterr, s_assigned, true, 5.0); 
            s_assigned = s_orig_assign;
            Size(loctestnum, loctesterr, s_assigned, true, 2);
            EqualSetVec(loctestnum, loctesterr, s_orig_assign, s_assigned, true);
            Remove(loctestnum, loctesterr, s_assigned, true, 100.0);
            Size(loctestnum, loctesterr, s_orig_assign, true, 2); 
            Exists(loctestnum, loctesterr, s_orig_assign, true, 100.0);
            s_assigned = s_assigned; 
            Size(loctestnum, loctesterr, s_assigned, true, 1);
            Exists(loctestnum, loctesterr, s_assigned, true, 200.0);
        }

        // Move assignment
        {
            lasd::SetVec<double> s_orig_move_assign, s_moved_assign;
            InsertC(loctestnum, loctesterr, s_orig_move_assign, true, 30.0);
            InsertC(loctestnum, loctesterr, s_orig_move_assign, true, 40.0);
            InsertC(loctestnum, loctesterr, s_moved_assign, true, 7.0); 
            s_moved_assign = std::move(s_orig_move_assign);
            Size(loctestnum, loctesterr, s_moved_assign, true, 2);
            Exists(loctestnum, loctesterr, s_moved_assign, true, 30.0);
        
            Empty(loctestnum, loctesterr, s_orig_move_assign, false); 
            Size(loctestnum, loctesterr, s_orig_move_assign, true, 1); 
            
            // lasd::SetVec<double> s_self_move;
            // InsertC(loctestnum, loctesterr, s_self_move, true, 55.0);
            // s_self_move = std::move(s_self_move); 
            // Size(loctestnum, loctesterr, s_self_move, true, 1); 
            // Exists(loctestnum, loctesterr, s_self_move, true, 55.0);
        }

        // Constructor from MappableContainer (Copy)
        {
            lasd::SortableVector<double> svec_empty_src(0);
            lasd::SetVec<double> set_from_svec_empty_copy(svec_empty_src);
            Empty(loctestnum, loctesterr, set_from_svec_empty_copy, true);
            Size(loctestnum, loctesterr, set_from_svec_empty_copy, true, 0);

            lasd::SortableVector<double> svec_src(5);
            SetAt(loctestnum, loctesterr, svec_src, true, 0, 30.0);
            SetAt(loctestnum, loctesterr, svec_src, true, 1, 10.0);
            SetAt(loctestnum, loctesterr, svec_src, true, 2, 20.0);
            SetAt(loctestnum, loctesterr, svec_src, true, 3, 10.0);
            SetAt(loctestnum, loctesterr, svec_src, true, 4, 30.0);
            lasd::SetVec<double> set_from_svec_copy(svec_src);
            Size(loctestnum, loctesterr, set_from_svec_copy, true, 3);
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, 10.0);
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, 20.0);
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, 30.0);
            GetAt(loctestnum, loctesterr, set_from_svec_copy, true, 0, 10.0); 
            Size(loctestnum, loctesterr, svec_src, true, 5); 

            lasd::List<double> list_empty_src;
            lasd::SetVec<double> set_from_list_empty_copy(list_empty_src);
            Empty(loctestnum, loctesterr, set_from_list_empty_copy, true);

            lasd::List<double> list_src;
            InsertAtBack(loctestnum, loctesterr, list_src, true, 50.0);
            InsertAtFront(loctestnum, loctesterr, list_src, true, 40.0);
            InsertAtBack(loctestnum, loctesterr, list_src, true, 50.0);
            InsertAtFront(loctestnum, loctesterr, list_src, true, 60.0); 
            lasd::SetVec<double> set_from_list_copy(list_src);
            Size(loctestnum, loctesterr, set_from_list_copy, true, 3); 
            Exists(loctestnum, loctesterr, set_from_list_copy, true, 40.0);
            Exists(loctestnum, loctesterr, set_from_list_copy, true, 60.0);
            GetAt(loctestnum, loctesterr, set_from_list_copy, true, 1, 50.0); 
            Size(loctestnum, loctesterr, list_src, true, 4); 

            lasd::SetLst<double> setlst_empty_src;
            lasd::SetVec<double> set_from_setlst_empty_copy(setlst_empty_src);
            Empty(loctestnum, loctesterr, set_from_setlst_empty_copy, true);

            lasd::SetLst<double> setlst_src;
            InsertC(loctestnum, loctesterr, setlst_src, true, 80.0);
            InsertC(loctestnum, loctesterr, setlst_src, true, 70.0);
            InsertC(loctestnum, loctesterr, setlst_src, true, 90.0); 
            lasd::SetVec<double> set_from_setlst_copy(setlst_src);
            Size(loctestnum, loctesterr, set_from_setlst_copy, true, 3);
            Exists(loctestnum, loctesterr, set_from_setlst_copy, true, 70.0);
            Exists(loctestnum, loctesterr, set_from_setlst_copy, true, 90.0);
            GetAt(loctestnum, loctesterr, set_from_setlst_copy, true, 1, 80.0);
            Size(loctestnum, loctesterr, setlst_src, true, 3);
        }

        // Constructor from MappableContainer (Move)
        {
            lasd::SortableVector<double> svec_empty_src_move(0);
            lasd::SetVec<double> set_from_svec_empty_move(std::move(svec_empty_src_move));
            Empty(loctestnum, loctesterr, set_from_svec_empty_move, true);
            Empty(loctestnum, loctesterr, svec_empty_src_move, true); 

            lasd::SortableVector<double> svec_src_move(5);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 0, 30.0);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 1, 10.0);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 2, 20.0);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 3, 10.0);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 4, 30.0);
            lasd::SetVec<double> set_from_svec_move(std::move(svec_src_move));
            Size(loctestnum, loctesterr, set_from_svec_move, true, 3);
            Exists(loctestnum, loctesterr, set_from_svec_move, true, 10.0);
            GetAt(loctestnum, loctesterr, set_from_svec_move, true, 2, 30.0);
            Empty(loctestnum, loctesterr, svec_src_move, false); 

            lasd::List<double> list_empty_src_move;
            lasd::SetVec<double> set_from_list_empty_move(std::move(list_empty_src_move));
            Empty(loctestnum, loctesterr, set_from_list_empty_move, true);
            Empty(loctestnum, loctesterr, list_empty_src_move, true);

            lasd::List<double> list_src_move;
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, 50.0);
            InsertAtFront(loctestnum, loctesterr, list_src_move, true, 40.0);
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, 50.0);
            InsertAtFront(loctestnum, loctesterr, list_src_move, true, 60.0);
            lasd::SetVec<double> set_from_list_move(std::move(list_src_move));
            Size(loctestnum, loctesterr, set_from_list_move, true, 3); 
            Exists(loctestnum, loctesterr, set_from_list_move, true, 50.0);
            GetAt(loctestnum, loctesterr, set_from_list_move, true, 0, 40.0);
            Empty(loctestnum, loctesterr, list_src_move, false); 
        }

        // Comparison
        {
            lasd::SetVec<double> s1_comp, s2_comp, s3_order_comp, s4_diff_val_comp, s5_diff_size_comp;
            InsertC(loctestnum, loctesterr, s1_comp, true, 1.0);
            InsertC(loctestnum, loctesterr, s1_comp, true, 2.0);
            InsertC(loctestnum, loctesterr, s1_comp, true, 3.0);

            InsertC(loctestnum, loctesterr, s2_comp, true, 1.0);
            InsertC(loctestnum, loctesterr, s2_comp, true, 2.0);
            InsertC(loctestnum, loctesterr, s2_comp, true, 3.0);
            EqualSetVec(loctestnum, loctesterr, s1_comp, s2_comp, true);

            InsertC(loctestnum, loctesterr, s3_order_comp, true, 3.0);
            InsertC(loctestnum, loctesterr, s3_order_comp, true, 1.0);
            InsertC(loctestnum, loctesterr, s3_order_comp, true, 2.0);
            EqualSetVec(loctestnum, loctesterr, s1_comp, s3_order_comp, true);

            InsertC(loctestnum, loctesterr, s4_diff_val_comp, true, 1.0);
            InsertC(loctestnum, loctesterr, s4_diff_val_comp, true, 2.0);
            InsertC(loctestnum, loctesterr, s4_diff_val_comp, true, 4.0);
            NonEqualSetVec(loctestnum, loctesterr, s1_comp, s4_diff_val_comp, true);

            InsertC(loctestnum, loctesterr, s5_diff_size_comp, true, 1.0);
            InsertC(loctestnum, loctesterr, s5_diff_size_comp, true, 2.0);
            NonEqualSetVec(loctestnum, loctesterr, s1_comp, s5_diff_size_comp, true);

            lasd::SetVec<double> empty1_comp, empty2_comp;
            EqualSetVec(loctestnum, loctesterr, empty1_comp, empty2_comp, true);
            NonEqualSetVec(loctestnum, loctesterr, empty1_comp, s1_comp, true);
        }

        // Dictionary Operations
        {
            lasd::SetVec<double> s_main_dict;
            lasd::SortableVector<double> vec_ins_dict(5);
            lasd::SortableVector<double> vec_rem_dict(3);
            lasd::SortableVector<double> vec_empty_dict(0);
            lasd::List<double> list_ins_dict, list_rem_dict, list_empty_dict;

            InsertC(loctestnum, loctesterr, s_main_dict, true, 10.0);
            InsertC(loctestnum, loctesterr, s_main_dict, true, 20.0);
            
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 0, 20.0); 
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 1, 30.0);
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 2, 40.0);
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 3, 5.0);
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 4, 30.0); 

            s_main_dict.InsertAll(vec_ins_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 5);
            Exists(loctestnum, loctesterr, s_main_dict, true, 5.0);
            Exists(loctestnum, loctesterr, s_main_dict, true, 40.0);

            s_main_dict.InsertAll(vec_empty_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 5);
            
            SetAt(loctestnum, loctesterr, vec_rem_dict, true, 0, 15.0); 
            SetAt(loctestnum, loctesterr, vec_rem_dict, true, 1, 20.0); 
            SetAt(loctestnum, loctesterr, vec_rem_dict, true, 2, 40.0); 
            s_main_dict.RemoveAll(vec_rem_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 3);
            Exists(loctestnum, loctesterr, s_main_dict, false, 20.0);
            Exists(loctestnum, loctesterr, s_main_dict, false, 40.0);

            s_main_dict.RemoveAll(vec_empty_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 3);

            s_main_dict.Clear(); 
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, 1.0);
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, 2.0);
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, 1.0); 
            
            try
            {
                loctestnum++;
                bool result = s_main_dict.InsertSome(list_ins_dict);
                if (result != true)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict<double>) [1] did not return true";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict<double>) [1] threw " << e.what();
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict<double>) [1] threw an unknown exception";
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 2);

            try
            {
                loctestnum++;
                bool result = s_main_dict.InsertSome(list_ins_dict);
                if (result != false)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict<double>) [2] did not return false";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict<double>) [2] threw " << e.what();
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict<double>) [2] threw an unknown exception";
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 2);

            try
            {
                loctestnum++;
                bool result = s_main_dict.InsertSome(list_empty_dict);
                if (result != false)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.InsertSome(list_empty_dict<double>) did not return false";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_empty_dict<double>) threw " << e.what() << endl;
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_empty_dict<double>) threw an unknown exception" << endl;
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 2);
            
            InsertAtBack(loctestnum, loctesterr, list_rem_dict, true, 2.0); 
            InsertAtBack(loctestnum, loctesterr, list_rem_dict, true, 3.0); 

            try
            {
                loctestnum++;
                bool result = s_main_dict.RemoveSome(list_rem_dict); 
                if (result != true) 
                {                   
                    testerr++;
                    cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict<double>) [1] did not return true";
                }
            }
            catch (const std::length_error& ) 
            {
                 cout << endl << "Info: s_main_dict.RemoveSome(list_rem_dict<double>) [1] threw length_error (element 3.0 not found)." << endl;
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict<double>) [1] threw " << e.what() << endl;
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict<double>) [1] threw an unknown exception" << endl;
            }
            
            Size(loctestnum, loctesterr, s_main_dict, true, 1); 

            try
            {
                loctestnum++;
                bool result = s_main_dict.RemoveSome(list_rem_dict); 
                if (result != false) 
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict<double>) [2] did not return false";
                }
            }
            catch (const std::length_error& ) 
            {
                 cout << endl << "Info: s_main_dict.RemoveSome(list_rem_dict<double>) [2] threw length_error as expected." << endl;
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict<double>) [2] threw an unexpected exception: " << e.what() << endl;
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict<double>) [2] threw an unknown exception" << endl;
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 1);

            try
            {
                loctestnum++;
                bool result = s_main_dict.RemoveSome(list_empty_dict);
                if (result != false)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.RemoveSome(list_empty_dict<double>) did not return false";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_empty_dict<double>) threw " << e.what() << endl;
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_empty_dict<double>) threw an unknown exception" << endl;
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 1);
        }

        // Traversals and Folds
        {
            lasd::SetVec<double> s_trav, s_empty_trav; 
            InsertC(loctestnum, loctesterr, s_trav, true, 30.0);
            InsertC(loctestnum, loctesterr, s_trav, true, 10.0);
            InsertC(loctestnum, loctesterr, s_trav, true, 20.0); 
            
            TraversePreOrder(loctestnum, loctesterr, s_trav, true, &TraversePrint<double>); 
            TraversePostOrder(loctestnum, loctesterr, s_trav, true, &TraversePrint<double>);

            FoldPreOrder(loctestnum, loctesterr, s_trav, true, &FoldAdd<double>, 0.0, 60.0); 
            FoldPostOrder(loctestnum, loctesterr, s_trav, true, &FoldAdd<double>, 0.0, 60.0); 

            TraversePreOrder(loctestnum, loctesterr, s_empty_trav, true, &TraversePrint<double>); 
            FoldPreOrder(loctestnum, loctesterr, s_empty_trav, true, &FoldAdd<double>, 0.0, 0.0);
        }
        // Clear
        {
            lasd::SetVec<double> s_clear_reuse;
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 100.0);
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 200.0);
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 50.0);
            Remove(loctestnum, loctesterr, s_clear_reuse, true, 50.0);
            s_clear_reuse.Clear();
            Empty(loctestnum, loctesterr, s_clear_reuse, true);
            Size(loctestnum, loctesterr, s_clear_reuse, true, 0);
            Min(loctestnum, loctesterr, s_clear_reuse, false, 0.0); 

            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 1.0);
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, 2.0);
            Size(loctestnum, loctesterr, s_clear_reuse, true, 2);
            GetAt(loctestnum, loctesterr, s_clear_reuse, true, 0, 1.0);

            s_clear_reuse.Clear();
            Empty(loctestnum, loctesterr, s_clear_reuse, true);
            Size(loctestnum, loctesterr, s_clear_reuse, true, 0);
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MySetVec<double> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mysetvec_string(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        cout << endl<< "############################################################################"<< endl;
        cout << endl << "---------------------- Begin of MySetVec<string> tests: ----------------------" << endl; 

        // Default constructor and basic checks
        {
            lasd::SetVec<string> s_default;
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
            Exists(loctestnum, loctesterr, s_default, false, string("5"));
            PredecessorNRemove(loctestnum, loctesterr, s_default, false, string("10"), string(""));
            Size(loctestnum, loctesterr, s_default, true, 0);
            SuccessorNRemove(loctestnum, loctesterr, s_default, false, string("10"), string(""));
            Size(loctestnum, loctesterr, s_default, true, 0);
        }

        // Single Element Set
        {
            lasd::SetVec<string> s_single;
            InsertC(loctestnum, loctesterr, s_single, true, string("10"));
            Empty(loctestnum, loctesterr, s_single, false);
            Size(loctestnum, loctesterr, s_single, true, 1);
            Min(loctestnum, loctesterr, s_single, true, string("10"));
            Max(loctestnum, loctesterr, s_single, true, string("10"));
            GetAt(loctestnum, loctesterr, s_single, true, 0, string("10"));
            Exists(loctestnum, loctesterr, s_single, true, string("10"));
            Exists(loctestnum, loctesterr, s_single, false, string("5"));
            
            Predecessor(loctestnum, loctesterr, s_single, false, string("10"), string("")); 
            Successor(loctestnum, loctesterr, s_single, false, string("10"), string(""));   
            Predecessor(loctestnum, loctesterr, s_single, false, string("5"), string(""));
            Successor(loctestnum, loctesterr, s_single, false, string("15"), string(""));

            PredecessorNRemove(loctestnum, loctesterr, s_single, false, string("10"), string(""));
            Size(loctestnum, loctesterr, s_single, true, 1);
            SuccessorNRemove(loctestnum, loctesterr, s_single, false, string("10"), string(""));
            Size(loctestnum, loctesterr, s_single, true, 1);

            PredecessorNRemove(loctestnum, loctesterr, s_single, false, string("5"), string(""));
            Size(loctestnum, loctesterr, s_single, true, 0);
            SuccessorNRemove(loctestnum, loctesterr, s_single, false, string("15"), string(""));
            Size(loctestnum, loctesterr, s_single, true, 0);
            
            try
            {
                loctestnum++;
                s_single.RemovePredecessor(string("10"));
                testerr++; cout << endl << "Error! s_single.RemovePredecessor(\"10\")" << endl;
            }
            catch (const std::logic_error& ){}
            catch (...)
            {
                testerr++; cout << endl << "Error! s_single.RemovePredecessor(\"10\") wrong exception" << endl;
            }

            Size(loctestnum, loctesterr, s_single, true, 0); 

            try
            {
                loctestnum++;
                s_single.RemoveSuccessor(string("10"));
                testerr++; cout << endl << "Error! s_single.RemoveSuccessor(\"10\")" << endl;
            }
            catch (const std::logic_error& ){}
            catch (...)
            {
                testerr++; cout << endl << "Error! s_single.RemoveSuccessor(\"10\") wrong exception" << endl;
            }
            Size(loctestnum, loctesterr, s_single, true, 0); 

            try
            {
                loctestnum++;
                s_single.RemovePredecessor(string("5"));
                testerr++; cout << endl << "Error! s_single.RemovePredecessor(\"5\")" << endl;
            }
            catch (const std::logic_error& ){}
            catch (...) { testerr++; cout << endl << "Error! s_single.RemovePredecessor(\"5\") wrong exception" << endl; }
            Size(loctestnum, loctesterr, s_single, true, 0); 

            TraversePreOrder(loctestnum, loctesterr, s_single, true, &TraversePrint<string>);

            try
            {
                loctestnum++;
                s_single.RemoveSuccessor(string("15"));
                testerr++; cout << endl << "Error! s_single.RemoveSuccessor(\"15\")" << endl;
            }
            catch (const std::logic_error& ){}
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_single.RemoveSuccessor(\"15\") wrong exception" << endl;
            }
            Size(loctestnum, loctesterr, s_single, true, 0);

            Remove(loctestnum, loctesterr, s_single, false, string("10"));
            Empty(loctestnum, loctesterr, s_single, true);
            Size(loctestnum, loctesterr, s_single, true, 0);
            s_single.Clear();
        }

        // Multi-Element Set
        {
            lasd::SetVec<string> s1;
            InsertC(loctestnum, loctesterr, s1, true, string("10")); 
            InsertC(loctestnum, loctesterr, s1, true, string("05"));  
            InsertC(loctestnum, loctesterr, s1, true, string("15")); 
            InsertC(loctestnum, loctesterr, s1, true, string("20"));
            Size(loctestnum, loctesterr, s1, true, 4); 
            GetAt(loctestnum, loctesterr, s1, true, 0, string("05"));
            GetAt(loctestnum, loctesterr, s1, true, 1, string("10"));
            GetAt(loctestnum, loctesterr, s1, true, 2, string("15"));
            GetAt(loctestnum, loctesterr, s1, true, 3, string("20"));
            Exists(loctestnum, loctesterr, s1, true, string("15"));
            Exists(loctestnum, loctesterr, s1, false, string("25"));
            Min(loctestnum, loctesterr, s1, true, string("05"));
            Max(loctestnum, loctesterr, s1, true, string("20"));

            Predecessor(loctestnum, loctesterr, s1, true, string("10"), string("05"));
            Successor(loctestnum, loctesterr, s1, true, string("10"), string("15"));
            Predecessor(loctestnum, loctesterr, s1, false, string("05"), string(""));
            Successor(loctestnum, loctesterr, s1, false, string("20"), string(""));
            Predecessor(loctestnum, loctesterr, s1, false, string("07"), string(""));
            Successor(loctestnum, loctesterr, s1, false, string("07"), string(""));
            Predecessor(loctestnum, loctesterr, s1, true, string("12"), string("10"));
            Successor(loctestnum, loctesterr, s1, true, string("12"), string("15"));

            PredecessorNRemove(loctestnum, loctesterr, s1, true, string("15"), string("10")); 
            Size(loctestnum, loctesterr, s1, true, 3); 
            Exists(loctestnum, loctesterr, s1, false, string("10")); 
            GetAt(loctestnum, loctesterr, s1, true, 1, string("15")); 

            SuccessorNRemove(loctestnum, loctesterr, s1, true, string("05"), string("15")); 
            Size(loctestnum, loctesterr, s1, true, 2); 
            Exists(loctestnum, loctesterr, s1, false, string("15"));
            GetAt(loctestnum, loctesterr, s1, true, 1, string("20")); 

            PredecessorNRemove(loctestnum, loctesterr, s1, false, string("05"), string(""));
            Size(loctestnum, loctesterr, s1, true, 2);
            SuccessorNRemove(loctestnum, loctesterr, s1, false, string("20"), string(""));
            Size(loctestnum, loctesterr, s1, true, 2);

            PredecessorNRemove(loctestnum, loctesterr, s1, false, string("03"), string(""));
            Size(loctestnum, loctesterr, s1, true, 2);
            SuccessorNRemove(loctestnum, loctesterr, s1, false, string("25"), string("")); 
            Size(loctestnum, loctesterr, s1, true, 2);

            InsertC(loctestnum, loctesterr, s1, true, string("30")); 
            PredecessorNRemove(loctestnum, loctesterr, s1, true, string("25"), string("20")); 
            Size(loctestnum, loctesterr, s1, true, 2);
            Exists(loctestnum, loctesterr, s1, false, string("20"));
            GetAt(loctestnum, loctesterr, s1, true, 1, string("30"));

            InsertC(loctestnum, loctesterr, s1, true, string("15")); 
            SuccessorNRemove(loctestnum, loctesterr, s1, true, string("10"), string("15"));
            Size(loctestnum, loctesterr, s1, true, 2);
            Exists(loctestnum, loctesterr, s1, false, string("15"));
            GetAt(loctestnum, loctesterr, s1, true, 0, string("05"));
            
            s1.Clear(); 
            InsertC(loctestnum, loctesterr, s1, true, string("10"));
            InsertC(loctestnum, loctesterr, s1, true, string("20"));
            InsertC(loctestnum, loctesterr, s1, true, string("30")); 
            
            try
            {
                loctestnum++;
                s1.RemovePredecessor(string("05"));
                testerr++; cout << endl << "Error! s1.RemovePredecessor(\"05\")" << endl;
            }
            catch (const std::logic_error& ) {}
            catch (...) { testerr++; cout << endl << "Error! s1.RemovePredecessor(\"05\") wrong exception" << endl; }
            Size(loctestnum, loctesterr, s1, true, 3); 

            try
            {
                loctestnum++;
                s1.RemoveSuccessor(string("35"));
                testerr++; cout << endl << "Error! s1.RemoveSuccessor(\"35\")" << endl;
            }
            catch (const std::logic_error& ) {}
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s1.RemoveSuccessor(\"35\") wrong exception" << endl;
            }
            Size(loctestnum, loctesterr, s1, true, 3); 

            try
            {
                loctestnum++;
                s1.RemovePredecessor(string("10"));
                testerr++; cout << endl << "Error! s1.RemovePredecessor(\"10\")" << endl;
            }
            catch (const std::logic_error& ) {}
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s1.RemovePredecessor(\"10\") wrong exception" << endl;
            }
            Size(loctestnum, loctesterr, s1, true, 3); 

            try
            {
                loctestnum++;
                s1.RemoveSuccessor(string("30"));
                testerr++; cout << endl << "Error! s1.RemoveSuccessor(\"30\")" << endl;
            }
            catch (const std::logic_error& ) {}
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s1.RemoveSuccessor(\"30\") wrong exception" << endl;
            }
            Size(loctestnum, loctesterr, s1, true, 3);

            try
            {
                loctestnum++;
                s1.RemovePredecessor(string("20")); 
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s1.RemovePredecessor(\"20\") " << e.what() << endl;
            }
            catch (...) 
            { 
                testerr++;
                cout << endl << "Error! s1.RemovePredecessor(\"20\") unknown exception" << endl; 
            }
            Size(loctestnum, loctesterr, s1, true, 2);
            Exists(loctestnum, loctesterr, s1, false, string("10"));
            Exists(loctestnum, loctesterr, s1, true, string("20"));
            Exists(loctestnum, loctesterr, s1, true, string("30"));
            GetAt(loctestnum, loctesterr, s1, true, 0, string("20"));

            try
            {
                loctestnum++;
                s1.RemoveSuccessor(string("20"));
            }
            catch (const std::exception& e)
            { 
                testerr++;
                cout << endl << "Error! s1.RemoveSuccessor(\"20\") " << e.what() << endl;
            }
            catch (...)
            { 
                testerr++;
                cout << endl << "Error! s1.RemoveSuccessor(\"20\") unknown exception" << endl; 
            }
            Size(loctestnum, loctesterr, s1, true, 1);
            Exists(loctestnum, loctesterr, s1, false, string("30"));
            Exists(loctestnum, loctesterr, s1, true, string("20"));
            GetAt(loctestnum, loctesterr, s1, true, 0, string("20"));
            
            s1.Clear();
        }

        // Insertions 
        {
            lasd::SetVec<string> s_resize;
            for (int i = 0; i < 20; ++i)
                InsertC(loctestnum, loctesterr, s_resize, true, string("val") + std::to_string(i * 10));

            Size(loctestnum, loctesterr, s_resize, true, 20);
            Exists(loctestnum, loctesterr, s_resize, true, string("val190"));
            GetAt(loctestnum, loctesterr, s_resize, true, 10, string("val180"));
        }

        // Removals
        {
            lasd::SetVec<string> s_resize_rem;
            for (int i = 0; i < 30; ++i) 
                InsertC(loctestnum, loctesterr, s_resize_rem, true, string("val") + std::to_string(i));
            
            Size(loctestnum, loctesterr, s_resize_rem, true, 30);
            for (int i = 0; i < 25; ++i) 
                Remove(loctestnum, loctesterr, s_resize_rem, true, string("val") + std::to_string(i));
            
            Size(loctestnum, loctesterr, s_resize_rem, true, 5);
            Exists(loctestnum, loctesterr, s_resize_rem, true, string("val29"));
            Exists(loctestnum, loctesterr, s_resize_rem, false, string("val0"));
        }

        // Wrap-around
        {
            lasd::SetVec<string> s_wrap1; 
            InsertC(loctestnum, loctesterr, s_wrap1, true, string("20"));
            InsertC(loctestnum, loctesterr, s_wrap1, true, string("30")); 
            InsertC(loctestnum, loctesterr, s_wrap1, true, string("40"));
            InsertC(loctestnum, loctesterr, s_wrap1, true, string("50")); 
            InsertC(loctestnum, loctesterr, s_wrap1, true, string("10")); 
            
            MinNRemove(loctestnum, loctesterr, s_wrap1, true, string("10")); 
            MinNRemove(loctestnum, loctesterr, s_wrap1, true, string("20")); 
            
            InsertC(loctestnum, loctesterr, s_wrap1, true, string("05"));  
            Size(loctestnum, loctesterr, s_wrap1, true, 4);
            GetAt(loctestnum, loctesterr, s_wrap1, true, 0, string("05")); 
            GetAt(loctestnum, loctesterr, s_wrap1, true, 1, string("30"));

            InsertC(loctestnum, loctesterr, s_wrap1, true, string("15")); 
            Size(loctestnum, loctesterr, s_wrap1, true, 5);
            GetAt(loctestnum, loctesterr, s_wrap1, true, 1, string("15"));
            InsertC(loctestnum, loctesterr, s_wrap1, true, string("01")); 
            Size(loctestnum, loctesterr, s_wrap1, true, 6);
            GetAt(loctestnum, loctesterr, s_wrap1, true, 0, string("01"));

            s_wrap1.Clear(); 
            for(int i=0; i<5; ++i)
                InsertC(loctestnum, loctesterr, s_wrap1, true, std::to_string((i+1)*10)); 

            Remove(loctestnum, loctesterr, s_wrap1, true, string("10")); 
            GetAt(loctestnum, loctesterr, s_wrap1, true, 0, string("20"));
            Remove(loctestnum, loctesterr, s_wrap1, true, string("50")); 
            GetAt(loctestnum, loctesterr, s_wrap1, true, 2, string("40"));
            Max(loctestnum, loctesterr, s_wrap1, true, string("40"));
            Size(loctestnum, loctesterr, s_wrap1, true, 3);

            lasd::SetVec<string> s_idx_rem; 
            InsertC(loctestnum, loctesterr, s_idx_rem, true, string("1"));
            InsertC(loctestnum, loctesterr, s_idx_rem, true, string("2")); 
            InsertC(loctestnum, loctesterr, s_idx_rem, true, string("3"));
            InsertC(loctestnum, loctesterr, s_idx_rem, true, string("4")); 
            InsertC(loctestnum, loctesterr, s_idx_rem, true, string("5")); 
            Remove(loctestnum, loctesterr, s_idx_rem, true, string("1")); 
            GetAt(loctestnum, loctesterr, s_idx_rem, true, 0, string("2"));
            Remove(loctestnum, loctesterr, s_idx_rem, true, string("5")); 
            GetAt(loctestnum, loctesterr, s_idx_rem, true, 2, string("4"));
            Max(loctestnum, loctesterr, s_idx_rem, true, string("4"));
            Remove(loctestnum, loctesterr, s_idx_rem, true, string("3")); 
            GetAt(loctestnum, loctesterr, s_idx_rem, true, 0, string("2"));
            GetAt(loctestnum, loctesterr, s_idx_rem, true, 1, string("4"));

            lasd::SetVec<string> s_empty_reuse;
            InsertC(loctestnum, loctesterr, s_empty_reuse, true, string("10"));
            InsertC(loctestnum, loctesterr, s_empty_reuse, true, string("20"));
            InsertC(loctestnum, loctesterr, s_empty_reuse, true, string("30"));
            Remove(loctestnum, loctesterr, s_empty_reuse, true, string("10")); 
            Remove(loctestnum, loctesterr, s_empty_reuse, true, string("20")); 
            Remove(loctestnum, loctesterr, s_empty_reuse, true, string("30")); 
            Empty(loctestnum, loctesterr, s_empty_reuse, true);
            InsertC(loctestnum, loctesterr, s_empty_reuse, true, string("05")); 
            GetAt(loctestnum, loctesterr, s_empty_reuse, true, 0, string("05"));
            s_empty_reuse.Clear();
        }

        // Copy constructor
        {
            lasd::SetVec<string> s_orig;
            InsertC(loctestnum, loctesterr, s_orig, true, string("1"));
            InsertC(loctestnum, loctesterr, s_orig, true, string("2"));
            InsertC(loctestnum, loctesterr, s_orig, true, string("3"));
            lasd::SetVec<string> s_copy(s_orig);
            Size(loctestnum, loctesterr, s_copy, true, 3);
            EqualSetVec(loctestnum, loctesterr, s_orig, s_copy, true);
            Remove(loctestnum, loctesterr, s_copy, true, string("2"));
            Size(loctestnum, loctesterr, s_orig, true, 3); 
            Exists(loctestnum, loctesterr, s_orig, true, string("2"));
            Exists(loctestnum, loctesterr, s_copy, false, string("2"));
        }

        // Move constructor
        {
            lasd::SetVec<string> s_orig_move;
            InsertC(loctestnum, loctesterr, s_orig_move, true, string("10"));
            InsertC(loctestnum, loctesterr, s_orig_move, true, string("20"));
            lasd::SetVec<string> s_moved(std::move(s_orig_move));
            Size(loctestnum, loctesterr, s_moved, true, 2);
            Exists(loctestnum, loctesterr, s_moved, true, string("10"));
            Empty(loctestnum, loctesterr, s_orig_move, true); 
            Size(loctestnum, loctesterr, s_orig_move, true, 0);
        }

        // Copy assignment
        {
            lasd::SetVec<string> s_orig_assign, s_assigned;
            InsertC(loctestnum, loctesterr, s_orig_assign, true, string("100"));
            InsertC(loctestnum, loctesterr, s_orig_assign, true, string("200"));
            InsertC(loctestnum, loctesterr, s_assigned, true, string("05")); 
            s_assigned = s_orig_assign;
            Size(loctestnum, loctesterr, s_assigned, true, 2);
            EqualSetVec(loctestnum, loctesterr, s_orig_assign, s_assigned, true);
            Remove(loctestnum, loctesterr, s_assigned, true, string("100"));
            Size(loctestnum, loctesterr, s_orig_assign, true, 2); 
            Exists(loctestnum, loctesterr, s_orig_assign, true, string("100"));
            s_assigned = s_assigned; 
            Size(loctestnum, loctesterr, s_assigned, true, 1);
            Exists(loctestnum, loctesterr, s_assigned, true, string("200"));
        }

        // Move assignment
        {
            lasd::SetVec<string> s_orig_move_assign, s_moved_assign;
            InsertC(loctestnum, loctesterr, s_orig_move_assign, true, string("30"));
            InsertC(loctestnum, loctesterr, s_orig_move_assign, true, string("40"));
            InsertC(loctestnum, loctesterr, s_moved_assign, true, string("07")); 
            s_moved_assign = std::move(s_orig_move_assign);
            Size(loctestnum, loctesterr, s_moved_assign, true, 2);
            Exists(loctestnum, loctesterr, s_moved_assign, true, string("30"));
            Empty(loctestnum, loctesterr, s_orig_move_assign, false); 
            Size(loctestnum, loctesterr, s_orig_move_assign, true, 1);
            
            // lasd::SetVec<string> s_self_move;
            // InsertC(loctestnum, loctesterr, s_self_move, true, string("55"));
            // s_self_move = std::move(s_self_move); 
            // Size(loctestnum, loctesterr, s_self_move, true, 1); 
            // Exists(loctestnum, loctesterr, s_self_move, true, string("55"));
        }

        // Constructor from MappableContainer (Copy)
        {
            lasd::SortableVector<string> svec_empty_src(0);
            lasd::SetVec<string> set_from_svec_empty_copy(svec_empty_src);
            Empty(loctestnum, loctesterr, set_from_svec_empty_copy, true);
            Size(loctestnum, loctesterr, set_from_svec_empty_copy, true, 0);

            lasd::SortableVector<string> svec_src(5);
            SetAt(loctestnum, loctesterr, svec_src, true, 0, string("30"));
            SetAt(loctestnum, loctesterr, svec_src, true, 1, string("10"));
            SetAt(loctestnum, loctesterr, svec_src, true, 2, string("20"));
            SetAt(loctestnum, loctesterr, svec_src, true, 3, string("10"));
            SetAt(loctestnum, loctesterr, svec_src, true, 4, string("30"));
            lasd::SetVec<string> set_from_svec_copy(svec_src);
            Size(loctestnum, loctesterr, set_from_svec_copy, true, 3);
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, string("10"));
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, string("20"));
            Exists(loctestnum, loctesterr, set_from_svec_copy, true, string("30"));
            GetAt(loctestnum, loctesterr, set_from_svec_copy, true, 0, string("10")); 
            Size(loctestnum, loctesterr, svec_src, true, 5); 

            lasd::List<string> list_empty_src;
            lasd::SetVec<string> set_from_list_empty_copy(list_empty_src);
            Empty(loctestnum, loctesterr, set_from_list_empty_copy, true);

            lasd::List<string> list_src;
            InsertAtBack(loctestnum, loctesterr, list_src, true, string("50"));
            InsertAtFront(loctestnum, loctesterr, list_src, true, string("40"));
            InsertAtBack(loctestnum, loctesterr, list_src, true, string("50"));
            InsertAtFront(loctestnum, loctesterr, list_src, true, string("60")); 
            lasd::SetVec<string> set_from_list_copy(list_src);
            Size(loctestnum, loctesterr, set_from_list_copy, true, 3); 
            Exists(loctestnum, loctesterr, set_from_list_copy, true, string("40"));
            Exists(loctestnum, loctesterr, set_from_list_copy, true, string("60"));
            GetAt(loctestnum, loctesterr, set_from_list_copy, true, 1, string("50")); 
            Size(loctestnum, loctesterr, list_src, true, 4); 

            lasd::SetLst<string> setlst_empty_src;
            lasd::SetVec<string> set_from_setlst_empty_copy(setlst_empty_src);
            Empty(loctestnum, loctesterr, set_from_setlst_empty_copy, true);

            lasd::SetLst<string> setlst_src;
            InsertC(loctestnum, loctesterr, setlst_src, true, string("80"));
            InsertC(loctestnum, loctesterr, setlst_src, true, string("70"));
            InsertC(loctestnum, loctesterr, setlst_src, true, string("90")); 
            lasd::SetVec<string> set_from_setlst_copy(setlst_src);
            Size(loctestnum, loctesterr, set_from_setlst_copy, true, 3);
            Exists(loctestnum, loctesterr, set_from_setlst_copy, true, string("70"));
            Exists(loctestnum, loctesterr, set_from_setlst_copy, true, string("90"));
            GetAt(loctestnum, loctesterr, set_from_setlst_copy, true, 1, string("80"));
            Size(loctestnum, loctesterr, setlst_src, true, 3);
        }

        // Constructor from MappableContainer (Move)
        {
            lasd::SortableVector<string> svec_empty_src_move(0);
            lasd::SetVec<string> set_from_svec_empty_move(std::move(svec_empty_src_move));
            Empty(loctestnum, loctesterr, set_from_svec_empty_move, true);
            Empty(loctestnum, loctesterr, svec_empty_src_move, true); 

            lasd::SortableVector<string> svec_src_move(5);
            SetAt(loctestnum, loctesterr, svec_src_move, true, 0, string("30"));
            SetAt(loctestnum, loctesterr, svec_src_move, true, 1, string("10"));
            SetAt(loctestnum, loctesterr, svec_src_move, true, 2, string("20"));
            SetAt(loctestnum, loctesterr, svec_src_move, true, 3, string("10"));
            SetAt(loctestnum, loctesterr, svec_src_move, true, 4, string("30"));
            lasd::SetVec<string> set_from_svec_move(std::move(svec_src_move));
            Size(loctestnum, loctesterr, set_from_svec_move, true, 3);
            Exists(loctestnum, loctesterr, set_from_svec_move, true, string("10"));
            GetAt(loctestnum, loctesterr, set_from_svec_move, true, 2, string("30"));
            Empty(loctestnum, loctesterr, svec_src_move, false);

            lasd::List<string> list_empty_src_move;
            lasd::SetVec<string> set_from_list_empty_move(std::move(list_empty_src_move));
            Empty(loctestnum, loctesterr, set_from_list_empty_move, true);
            Empty(loctestnum, loctesterr, list_empty_src_move, true);

            lasd::List<string> list_src_move;
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, string("50"));
            InsertAtFront(loctestnum, loctesterr, list_src_move, true, string("40"));
            InsertAtBack(loctestnum, loctesterr, list_src_move, true, string("50"));
            InsertAtFront(loctestnum, loctesterr, list_src_move, true, string("60"));
            lasd::SetVec<string> set_from_list_move(std::move(list_src_move));
            Size(loctestnum, loctesterr, set_from_list_move, true, 3); 
            Exists(loctestnum, loctesterr, set_from_list_move, true, string("50"));
            GetAt(loctestnum, loctesterr, set_from_list_move, true, 0, string("40"));
            Empty(loctestnum, loctesterr, list_src_move, false); 
        }

        // Comparison
        {
            lasd::SetVec<string> s1_comp, s2_comp, s3_order_comp, s4_diff_val_comp, s5_diff_size_comp;
            InsertC(loctestnum, loctesterr, s1_comp, true, string("01"));
            InsertC(loctestnum, loctesterr, s1_comp, true, string("02"));
            InsertC(loctestnum, loctesterr, s1_comp, true, string("03"));

            InsertC(loctestnum, loctesterr, s2_comp, true, string("01"));
            InsertC(loctestnum, loctesterr, s2_comp, true, string("02"));
            InsertC(loctestnum, loctesterr, s2_comp, true, string("03"));
            EqualSetVec(loctestnum, loctesterr, s1_comp, s2_comp, true);

            InsertC(loctestnum, loctesterr, s3_order_comp, true, string("03"));
            InsertC(loctestnum, loctesterr, s3_order_comp, true, string("01"));
            InsertC(loctestnum, loctesterr, s3_order_comp, true, string("02"));
            EqualSetVec(loctestnum, loctesterr, s1_comp, s3_order_comp, true);

            InsertC(loctestnum, loctesterr, s4_diff_val_comp, true, string("01"));
            InsertC(loctestnum, loctesterr, s4_diff_val_comp, true, string("02"));
            InsertC(loctestnum, loctesterr, s4_diff_val_comp, true, string("04"));
            NonEqualSetVec(loctestnum, loctesterr, s1_comp, s4_diff_val_comp, true);

            InsertC(loctestnum, loctesterr, s5_diff_size_comp, true, string("01"));
            InsertC(loctestnum, loctesterr, s5_diff_size_comp, true, string("02"));
            NonEqualSetVec(loctestnum, loctesterr, s1_comp, s5_diff_size_comp, true);

            lasd::SetVec<string> empty1_comp, empty2_comp;
            EqualSetVec(loctestnum, loctesterr, empty1_comp, empty2_comp, true);
            NonEqualSetVec(loctestnum, loctesterr, empty1_comp, s1_comp, true);
        }

        // Dictionary Operations
        {
            lasd::SetVec<string> s_main_dict;
            lasd::SortableVector<string> vec_ins_dict(5);
            lasd::SortableVector<string> vec_rem_dict(3);
            lasd::SortableVector<string> vec_empty_dict(0);
            lasd::List<string> list_ins_dict, list_rem_dict, list_empty_dict;

            InsertC(loctestnum, loctesterr, s_main_dict, true, string("10"));
            InsertC(loctestnum, loctesterr, s_main_dict, true, string("20"));
            
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 0, string("20")); 
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 1, string("30"));
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 2, string("40"));
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 3, string("05"));
            SetAt(loctestnum, loctesterr, vec_ins_dict, true, 4, string("30")); 

            s_main_dict.InsertAll(vec_ins_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 5);
            Exists(loctestnum, loctesterr, s_main_dict, true, string("05"));
            Exists(loctestnum, loctesterr, s_main_dict, true, string("40"));

            s_main_dict.InsertAll(vec_empty_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 5);
            
            SetAt(loctestnum, loctesterr, vec_rem_dict, true, 0, string("15"));
            SetAt(loctestnum, loctesterr, vec_rem_dict, true, 1, string("20")); 
            SetAt(loctestnum, loctesterr, vec_rem_dict, true, 2, string("40")); 
            s_main_dict.RemoveAll(vec_rem_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 3); 
            Exists(loctestnum, loctesterr, s_main_dict, false, string("20"));
            Exists(loctestnum, loctesterr, s_main_dict, false, string("40"));

            s_main_dict.RemoveAll(vec_empty_dict); 
            Size(loctestnum, loctesterr, s_main_dict, true, 3);

            s_main_dict.Clear(); 
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, string("01"));
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, string("02"));
            InsertAtBack(loctestnum, loctesterr, list_ins_dict, true, string("01")); 
            
            try
            {
                loctestnum++;
                bool result = s_main_dict.InsertSome(list_ins_dict);
                if (result != true)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict<string>) [1] did not return true";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict<string>) [1] threw " << e.what();
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict<string>) [1] threw an unknown exception";
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 2); 

            try
            {
                loctestnum++;
                bool result = s_main_dict.InsertSome(list_ins_dict); 
                if (result != false)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict<string>) [2] did not return false";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict<string>) [2] threw " << e.what();
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_ins_dict<string>) [2] threw an unknown exception";
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 2);

            try
            {
                loctestnum++;
                bool result = s_main_dict.InsertSome(list_empty_dict);
                if (result != false)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.InsertSome(list_empty_dict<string>) did not return false";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_empty_dict<string>) threw " << e.what() << endl;
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.InsertSome(list_empty_dict<string>) threw an unknown exception" << endl;
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 2);
            
            InsertAtBack(loctestnum, loctesterr, list_rem_dict, true, string("02")); 
            InsertAtBack(loctestnum, loctesterr, list_rem_dict, true, string("03"));

            try
            {
                loctestnum++;
                bool result = s_main_dict.RemoveSome(list_rem_dict);
                if (result != true)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict<string>) [1] did not return true";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict<string>) [1] threw " << e.what() << endl;
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict<string>) [1] threw an unknown exception" << endl;
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 1);

            try
            {
                loctestnum++;
                bool result = s_main_dict.RemoveSome(list_rem_dict);
                if (result != false)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict<string>) [2] did not return false";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict<string>) [2] threw an unexpected exception: " << e.what() << endl;
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_rem_dict<string>) [2] threw an unknown exception" << endl;
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 1);

            try
            {
                loctestnum++;
                bool result = s_main_dict.RemoveSome(list_empty_dict);
                if (result != false)
                {
                    testerr++;
                    cout << endl << "Error! s_main_dict.RemoveSome(list_empty_dict<string>) did not return false";
                }
            }
            catch (const std::exception& e)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_empty_dict<string>) threw " << e.what() << endl;
            }
            catch (...)
            {
                testerr++;
                cout << endl << "Error! s_main_dict.RemoveSome(list_empty_dict<string>) threw an unknown exception" << endl;
            }
            Size(loctestnum, loctesterr, s_main_dict, true, 1);
        }

        // Traversals and Folds
        {
            lasd::SetVec<string> s_trav, s_empty_trav; 
            InsertC(loctestnum, loctesterr, s_trav, true, string("30"));
            InsertC(loctestnum, loctesterr, s_trav, true, string("10"));
            InsertC(loctestnum, loctesterr, s_trav, true, string("20")); 
            
            TraversePreOrder(loctestnum, loctesterr, s_trav, true, &TraversePrint<string>); 
            TraversePostOrder(loctestnum, loctesterr, s_trav, true, &TraversePrint<string>);

            FoldPreOrder(loctestnum, loctesterr, s_trav, true, &FoldAdd<string>, string(""), string("102030")); 
            FoldPostOrder(loctestnum, loctesterr, s_trav, true, &FoldAdd<string>, string(""), string("302010")); 

            TraversePreOrder(loctestnum, loctesterr, s_empty_trav, true, &TraversePrint<string>); 
            FoldPreOrder(loctestnum, loctesterr, s_empty_trav, true, &FoldAdd<string>, string(""), string(""));
        }
        // Clear
        {
            lasd::SetVec<string> s_clear_reuse;
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, string("100"));
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, string("200"));
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, string("050"));
            Remove(loctestnum, loctesterr, s_clear_reuse, true, string("050"));
            s_clear_reuse.Clear();
            Empty(loctestnum, loctesterr, s_clear_reuse, true);
            Size(loctestnum, loctesterr, s_clear_reuse, true, 0);
            Min(loctestnum, loctesterr, s_clear_reuse, false, string("")); 

            InsertC(loctestnum, loctesterr, s_clear_reuse, true, string("01"));
            InsertC(loctestnum, loctesterr, s_clear_reuse, true, string("02"));
            Size(loctestnum, loctesterr, s_clear_reuse, true, 2);
            GetAt(loctestnum, loctesterr, s_clear_reuse, true, 0, string("01"));

            s_clear_reuse.Clear();
            Empty(loctestnum, loctesterr, s_clear_reuse, true);
            Size(loctestnum, loctesterr, s_clear_reuse, true, 0);
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MySetVec<string> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}


/* ************************************************************************** */

void setvec_test(uint &testnum, uint &testerr)
{
    mysetvec_int(testnum, testerr);
    mysetvec_double(testnum, testerr);
    mysetvec_string(testnum, testerr);
}