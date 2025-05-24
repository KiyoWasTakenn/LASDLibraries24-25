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

        //Single Element Set
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

        // 3. Multi-Element Set
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

        // 5. Removals
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

        // 6. Wrap-around
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

        // 7. Copy constructor
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

        // 8. Move constructor
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

        // 9. Copy assignment
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

        // 10. Move assignment

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
            
            lasd::SetVec<int> s_self_move;
            InsertC(loctestnum, loctesterr, s_self_move, true, 55);
            s_self_move = std::move(s_self_move); 
            Size(loctestnum, loctesterr, s_self_move, true, 1); 
            Exists(loctestnum, loctesterr, s_self_move, true, 55);
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
                    cout << endl << "Error! s_main_dict.RemoveSome(list_empty_dict)" 
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
        // 16. Clear
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