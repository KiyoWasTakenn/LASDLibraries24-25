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

void mylst_int(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        cout << endl<< "############################################################################"<< endl;
        cout << endl << "---------------------- Begin of MyList<int> tests: ----------------------" << endl;
        //EmptyListDefaultConstructor
        {
            lasd::List<int> lst;

            Empty(loctestnum, loctesterr, lst, true);
            Size(loctestnum, loctesterr, lst, true, 0);

            GetFront(loctestnum, loctesterr, lst, false, 0); 
            GetBack(loctestnum, loctesterr, lst, false, 0);  
            GetAt(loctestnum, loctesterr, lst, false, 0, 0); 
            SetAt(loctestnum, loctesterr, lst, false, 0, 0); 
            SetFront(loctestnum, loctesterr, lst, false, 0); 
            SetBack(loctestnum, loctesterr, lst, false, 0); 


            Exists(loctestnum, loctesterr, lst, false, 0);

            Traverse(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);

            Fold(loctestnum, loctesterr, lst, true, &FoldMultiply<int>, 1, 1); 
            FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldMultiply<int>, 1, 1);
            FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 0);

            Map(loctestnum, loctesterr, lst, true, &MapIncrement<int>); 
            MapPreOrder(loctestnum, loctesterr, lst, true, &MapIncrement<int>); 
            MapPostOrder(loctestnum, loctesterr, lst, true, &MapIncrement<int>); 

            RemoveFromFront(loctestnum, loctesterr, lst, false); 
            FrontNRemove(loctestnum, loctesterr, lst, false, 0);
            RemoveFromBack(loctestnum, loctesterr, lst, false); 
            BackNRemove(loctestnum, loctesterr, lst, false, 0); 

            lst.Clear(); 
            Empty(loctestnum, loctesterr, lst, true);
        }
        
        //NonEmptyListOperations
        {
            lasd::List<int> lst;
            InsertAtBack(loctestnum, loctesterr, lst, true, 2); 
            InsertAtBack(loctestnum, loctesterr, lst, true, 4); 
            InsertAtFront(loctestnum, loctesterr, lst, true, 6);  
            InsertAtFront(loctestnum, loctesterr, lst, true, 8);  
            InsertAtBack(loctestnum, loctesterr, lst, true, 10); 
            InsertAtFront(loctestnum, loctesterr, lst, true, 11); 
            InsertAtBack(loctestnum, loctesterr, lst, true, 13); 
            InsertAtFront(loctestnum, loctesterr, lst, true, 15); 
            InsertAtBack(loctestnum, loctesterr, lst, true, 17); 
            InsertAtFront(loctestnum, loctesterr, lst, true, 19);

            Empty(loctestnum, loctesterr, lst, false);
            Size(loctestnum, loctesterr, lst, true, 10);

            GetAt(loctestnum, loctesterr, lst, true, 0, 19); 
            GetAt(loctestnum, loctesterr, lst, true, 9, 17);
            GetAt(loctestnum, loctesterr, lst, false, 10, 0); 
            GetFront(loctestnum, loctesterr, lst, true, 19);
            GetBack(loctestnum, loctesterr, lst, true, 17);

            SetFront(loctestnum, loctesterr, lst, true, 0);  
            SetBack(loctestnum, loctesterr, lst, true, 21);  
            GetFront(loctestnum, loctesterr, lst, true, 0);
            GetBack(loctestnum, loctesterr, lst, true, 21);
            SetAt(loctestnum, loctesterr, lst, true, 5, 99); 

            Exists(loctestnum, loctesterr, lst, true, 21);
            Exists(loctestnum, loctesterr, lst, false, 7);

            Traverse(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
            TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>); 
            TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>); 

            Fold(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 187); 
            FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 187);
            FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldMultiply<int>, 1, 0);

            // Removals
            FrontNRemove(loctestnum, loctesterr, lst, true, 0); 
            RemoveFromFront(loctestnum, loctesterr, lst, true); 
            BackNRemove(loctestnum, loctesterr, lst, true, 21);
            RemoveFromBack(loctestnum, loctesterr, lst, true); 
            Size(loctestnum, loctesterr, lst, true, 6);
            Fold(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 138);
            
            Map(loctestnum, loctesterr, lst, true, &MapIncrement<int>); 
            FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<int>, 0, 144);
            FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldMultiply<int>, 1, 4158000); 
        
            lst.Clear(); 
            Empty(loctestnum, loctesterr, lst, true);
            Size(loctestnum, loctesterr, lst, true, 0);
        }
        // Copy Constructor
        {
            lasd::List<int> lst1;
            InsertAtBack(loctestnum, loctesterr, lst1, true, 7);
            InsertAtFront(loctestnum, loctesterr, lst1, true, 8); 
            InsertAtBack(loctestnum, loctesterr, lst1, true, 9);  

            lasd::List<int> copylst(lst1);
            EqualList(loctestnum, loctesterr, lst1, copylst, true);
            EqualLinear(loctestnum, loctesterr, lst1, copylst, true);
            TraversePreOrder(loctestnum, loctesterr, copylst, true, &TraversePrint<int>);
            Size(loctestnum, loctesterr, copylst, true, 3);
            GetAt(loctestnum, loctesterr, copylst, true, 0, 8);

            Size(loctestnum, loctesterr, lst1, true, 3); 
            GetAt(loctestnum, loctesterr, lst1, true, 0, 8);

            MapPreOrder(loctestnum, loctesterr, copylst, true, &MapIncrement<int>);
            NonEqualList(loctestnum, loctesterr, lst1, copylst, true);
            NonEqualLinear(loctestnum, loctesterr, lst1, copylst, true);
            GetAt(loctestnum, loctesterr, lst1, true, 0, 8); 

            lasd::List<int> empty_lst;
            lasd::List<int> copy_of_empty(empty_lst);
            Empty(loctestnum, loctesterr, copy_of_empty, true);
            Size(loctestnum, loctesterr, copy_of_empty, true, 0);
            
            Empty(loctestnum, loctesterr, empty_lst, true); 
            Size(loctestnum, loctesterr, empty_lst, true, 0);
        }
        // Move constructor
        {
            lasd::List<int> lst_source_non_empty;
            InsertAtBack(loctestnum, loctesterr, lst_source_non_empty, true, 56);
            InsertAtFront(loctestnum, loctesterr, lst_source_non_empty, true, 23); 
            InsertAtBack(loctestnum, loctesterr, lst_source_non_empty, true, 10); 

            lasd::List<int> lst_moved(std::move(lst_source_non_empty));
            Size(loctestnum, loctesterr, lst_moved, true, 3);
            GetAt(loctestnum, loctesterr, lst_moved, true, 0, 23);
            FoldPreOrder(loctestnum, loctesterr, lst_moved, true, &FoldAdd<int>, 0, 89); 

            Empty(loctestnum, loctesterr, lst_source_non_empty, true); 
            Size(loctestnum, loctesterr, lst_source_non_empty, true, 0);
            
            lasd::List<int> lst_source_empty;
            lasd::List<int> lst_moved_from_empty(std::move(lst_source_empty));
            Empty(loctestnum, loctesterr, lst_moved_from_empty, true);
            Size(loctestnum, loctesterr, lst_moved_from_empty, true, 0);

            Empty(loctestnum, loctesterr, lst_source_empty, true); 
            Size(loctestnum, loctesterr, lst_source_empty, true, 0);
        }
        // Copy Assignment
        {
            lasd::List<int> lst_s1; 
            InsertAtBack(loctestnum, loctesterr, lst_s1, true, 10);
            InsertAtFront(loctestnum, loctesterr, lst_s1, true, 20);
            InsertAtBack(loctestnum, loctesterr, lst_s1, true, 30); 

            lasd::List<int> lst_s2; 
            InsertAtBack(loctestnum, loctesterr, lst_s2, true, 5);
            InsertAtFront(loctestnum, loctesterr, lst_s2, true, 15); 
            
            lasd::List<int> lst_empty_s; 

            lasd::List<int> lst_d1;   
            InsertAtBack(loctestnum, loctesterr, lst_d1, true, 99);

            lasd::List<int> lst_d_empty; 

            lst_d1 = lst_s1; // Non-empty to Non-empty
            EqualList(loctestnum, loctesterr, lst_d1, lst_s1, true);
            Size(loctestnum, loctesterr, lst_d1, true, 3);
            GetAt(loctestnum, loctesterr, lst_d1, true, 1, 10);
            Size(loctestnum, loctesterr, lst_s1, true, 3); 

            lst_d_empty = lst_s2; // Non-empty to Empty
            EqualList(loctestnum, loctesterr, lst_d_empty, lst_s2, true);
            Size(loctestnum, loctesterr, lst_d_empty, true, 2);
            GetAt(loctestnum, loctesterr, lst_d_empty, true, 0, 15);

            lst_d1 = lst_empty_s; // Empty to Non-empty
            Empty(loctestnum, loctesterr, lst_d1, true);
            Size(loctestnum, loctesterr, lst_d1, true, 0);

            lst_d_empty = lst_empty_s; // Empty to Empty
            Empty(loctestnum, loctesterr, lst_d_empty, true);
            
            // lasd::List<int> lst_self_assign(lst_s1); // Self-assignment (non-empty)
            // lst_self_assign = lst_self_assign;
            // EqualList(loctestnum, loctesterr, lst_self_assign, lst_s1, true);

            lasd::List<int> lst_orig_ind(lst_s1);
            lasd::List<int> lst_assign_ind;
            lst_assign_ind = lst_orig_ind;
            Map(loctestnum, loctesterr, lst_orig_ind, true, &MapIncrement<int>); 
            NonEqualList(loctestnum, loctesterr, lst_orig_ind, lst_assign_ind, true);
            GetAt(loctestnum, loctesterr, lst_assign_ind, true, 0, 20); 
        }
        // Move Assignment
        {
            lasd::List<int> lst_s1_move;
            InsertAtBack(loctestnum, loctesterr, lst_s1_move, true, 100);
            InsertAtFront(loctestnum, loctesterr, lst_s1_move, true, 200); 
            InsertAtBack(loctestnum, loctesterr, lst_s1_move, true, 300);  
            lasd::List<int> lst_d1_move; 
            InsertAtBack(loctestnum, loctesterr, lst_d1_move, true, 50);
            
            lst_d1_move = std::move(lst_s1_move); 
            Size(loctestnum, loctesterr, lst_d1_move, true, 3);
            GetAt(loctestnum, loctesterr, lst_d1_move, true, 1, 100);
            Empty(loctestnum, loctesterr, lst_s1_move, false); 
            Size(loctestnum, loctesterr, lst_s1_move, true, 1);

            lasd::List<int> lst_s2_move;
            InsertAtBack(loctestnum, loctesterr, lst_s2_move, true, 55);
            InsertAtFront(loctestnum, loctesterr, lst_s2_move, true, 66); 
            lasd::List<int> lst_d_empty_move;
            
            lst_d_empty_move = std::move(lst_s2_move); 
            Size(loctestnum, loctesterr, lst_d_empty_move, true, 2);
            GetAt(loctestnum, loctesterr, lst_d_empty_move, true, 0, 66);
            Empty(loctestnum, loctesterr, lst_s2_move, true); 

            lasd::List<int> lst_empty_s_move;
            lasd::List<int> lst_d3_move;
            InsertAtBack(loctestnum, loctesterr, lst_d3_move, true, 77);
            
            lst_d3_move = std::move(lst_empty_s_move); 
            Empty(loctestnum, loctesterr, lst_d3_move, true); 
            Empty(loctestnum, loctesterr, lst_empty_s_move, false); 

            // lasd::List<int> lst_self_move;
            // InsertAtBack(loctestnum, loctesterr, lst_self_move, true, 11);
            // lst_self_move = std::move(lst_self_move); 
            // Empty(loctestnum, loctesterr, lst_self_move, true); 
        }
        // Copy from TraversableContainer (SortableVector)
        {
            lasd::SortableVector<int> svec_empty_src(0);
            lasd::List<int> lst_from_empty_svec_copy(svec_empty_src);
            Empty(loctestnum, loctesterr, lst_from_empty_svec_copy, true);
            Empty(loctestnum, loctesterr, svec_empty_src, true); 
         
            lasd::SortableVector<int> svec_non_empty_src(3);
            SetAt(loctestnum, loctesterr, svec_non_empty_src, true, 0, 70); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src, true, 1, 50); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src, true, 2, 60); 
            
            lasd::List<int> lst_from_svec_copy(svec_non_empty_src);
            Size(loctestnum, loctesterr, lst_from_svec_copy, true, 3);
            EqualLinear(loctestnum, loctesterr, lst_from_svec_copy, svec_non_empty_src, true);        
            GetAt(loctestnum, loctesterr, lst_from_svec_copy, true, 0, 70); 
            GetAt(loctestnum, loctesterr, lst_from_svec_copy, true, 1, 50);
            GetAt(loctestnum, loctesterr, lst_from_svec_copy, true, 2, 60);
            
            Size(loctestnum, loctesterr, svec_non_empty_src, true, 3); 
            GetAt(loctestnum, loctesterr, svec_non_empty_src, true, 0, 70); 
            
            Map(loctestnum, loctesterr, lst_from_svec_copy, true, &MapDecrement<int>); 
            GetAt(loctestnum, loctesterr, svec_non_empty_src, true, 0, 70); 
        }
        // Move from MappableContainer (SortableVector)
        {
            lasd::SortableVector<int> svec_empty_src_move(0);
            lasd::List<int> lst_from_empty_svec_move(std::move(svec_empty_src_move)); 
            Empty(loctestnum, loctesterr, lst_from_empty_svec_move, true);
            Empty(loctestnum, loctesterr, svec_empty_src_move, true); 
         
            lasd::SortableVector<int> svec_non_empty_src_move(3); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src_move, true, 0, 4); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src_move, true, 1, 6); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src_move, true, 2, 5); 
            
            lasd::List<int> lst_from_svec_move(std::move(svec_non_empty_src_move)); 
            Size(loctestnum, loctesterr, lst_from_svec_move, true, 3);
            GetAt(loctestnum, loctesterr, lst_from_svec_move, true, 0, 4); 
            GetAt(loctestnum, loctesterr, lst_from_svec_move, true, 1, 6);
            GetAt(loctestnum, loctesterr, lst_from_svec_move, true, 2, 5);
            
            Empty(loctestnum, loctesterr, svec_non_empty_src_move, false);
            Size(loctestnum, loctesterr, svec_non_empty_src_move, true, 3); 
            GetAt(loctestnum, loctesterr, svec_non_empty_src_move, true, 0, 4);
        }
        // Copy from TraversableContainer (SETVEC - int)
        {
            lasd::SetVec<int> set_v_empty_src;
            lasd::List<int> lst_from_empty_setvec_copy(set_v_empty_src);
            Empty(loctestnum, loctesterr, lst_from_empty_setvec_copy, true);
            Empty(loctestnum, loctesterr, set_v_empty_src, true); 

            lasd::SetVec<int> set_v_non_empty_src;
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, 300);
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, 100);
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, 200); 

            lasd::List<int> lst_from_setvec_copy(set_v_non_empty_src);
            Size(loctestnum, loctesterr, lst_from_setvec_copy, true, 3);
            GetAt(loctestnum, loctesterr, lst_from_setvec_copy, true, 0, 100);
            GetAt(loctestnum, loctesterr, lst_from_setvec_copy, true, 1, 200);
            GetAt(loctestnum, loctesterr, lst_from_setvec_copy, true, 2, 300);
            EqualLinear(loctestnum, loctesterr, lst_from_setvec_copy, set_v_non_empty_src, true);

            Size(loctestnum, loctesterr, set_v_non_empty_src, true, 3); 
            Exists(loctestnum, loctesterr, set_v_non_empty_src, true, 100);
        }  
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MyList<int> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mylst_double(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        cout << endl<< "############################################################################"<< endl;
        cout << endl << "---------------------- Begin of MyList<double> tests: ----------------------" << endl;

        //EmptyListDefaultConstructor
        {
            lasd::List<double> lst;

            Empty(loctestnum, loctesterr, lst, true);
            Size(loctestnum, loctesterr, lst, true, 0);

            GetFront(loctestnum, loctesterr, lst, false, 0.0); 
            GetBack(loctestnum, loctesterr, lst, false, 0.0);  
            GetAt(loctestnum, loctesterr, lst, false, 0, 0.0); 
            SetAt(loctestnum, loctesterr, lst, false, 0, 0.0); 
            SetFront(loctestnum, loctesterr, lst, false, 0.0); 
            SetBack(loctestnum, loctesterr, lst, false, 0.0); 

            Exists(loctestnum, loctesterr, lst, false, 0.0);

            Traverse(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);

            Fold(loctestnum, loctesterr, lst, true, &FoldMultiply<double>, 1.0, 1.0); 
            FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldMultiply<double>, 1.0, 1.0);
            FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldAdd<double>, 0.0, 0.0);

            Map(loctestnum, loctesterr, lst, true, &MapIncrement<double>); 
            MapPreOrder(loctestnum, loctesterr, lst, true, &MapIncrement<double>); 
            MapPostOrder(loctestnum, loctesterr, lst, true, &MapIncrement<double>); 

            RemoveFromFront(loctestnum, loctesterr, lst, false); 
            FrontNRemove(loctestnum, loctesterr, lst, false, 0.0);
            RemoveFromBack(loctestnum, loctesterr, lst, false); 
            BackNRemove(loctestnum, loctesterr, lst, false, 0.0); 

            lst.Clear(); 
            Empty(loctestnum, loctesterr, lst, true);
        }
        
        //NonEmptyListOperations
        {
            lasd::List<double> lst;
            InsertAtBack(loctestnum, loctesterr, lst, true, 2.2); 
            InsertAtBack(loctestnum, loctesterr, lst, true, 4.4); 
            InsertAtFront(loctestnum, loctesterr, lst, true, 6.6);  
            InsertAtFront(loctestnum, loctesterr, lst, true, 8.8);  
            InsertAtBack(loctestnum, loctesterr, lst, true, 10.1); 
            InsertAtFront(loctestnum, loctesterr, lst, true, 11.11); 
            InsertAtBack(loctestnum, loctesterr, lst, true, 13.13); 
            InsertAtFront(loctestnum, loctesterr, lst, true, 15.15); 
            InsertAtBack(loctestnum, loctesterr, lst, true, 17.17); 
            InsertAtFront(loctestnum, loctesterr, lst, true, 19.19);

            Empty(loctestnum, loctesterr, lst, false);
            Size(loctestnum, loctesterr, lst, true, 10);

            GetAt(loctestnum, loctesterr, lst, true, 0, 19.19); 
            GetAt(loctestnum, loctesterr, lst, true, 9, 17.17);
            GetAt(loctestnum, loctesterr, lst, false, 10, 0.0); 
            GetFront(loctestnum, loctesterr, lst, true, 19.19);
            GetBack(loctestnum, loctesterr, lst, true, 17.17);

            SetFront(loctestnum, loctesterr, lst, true, 0.5);  
            SetBack(loctestnum, loctesterr, lst, true, 21.5);  
            GetFront(loctestnum, loctesterr, lst, true, 0.5);
            GetBack(loctestnum, loctesterr, lst, true, 21.5);
            SetAt(loctestnum, loctesterr, lst, true, 5, 99.9); 

            Exists(loctestnum, loctesterr, lst, true, 21.5);
            Exists(loctestnum, loctesterr, lst, false, 7.7);

            Traverse(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
            TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>); 
            TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>); 

            Fold(loctestnum, loctesterr, lst, true, &FoldAdd<double>, 0.0, 0.5+15.15+11.11+8.8+6.6+99.9+4.4+10.1+13.13+21.5); 
            FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<double>, 0.0, 0.5+15.15+11.11+8.8+6.6+99.9+4.4+10.1+13.13+21.5);
            FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldMultiply<double>, 1.0, 0.5*15.15*11.11*8.8*6.6*99.9*4.4*10.1*13.13*21.5);

            // Removals
            FrontNRemove(loctestnum, loctesterr, lst, true, 0.5); 
            RemoveFromFront(loctestnum, loctesterr, lst, true); 
            BackNRemove(loctestnum, loctesterr, lst, true, 21.5);
            RemoveFromBack(loctestnum, loctesterr, lst, true); 
            Size(loctestnum, loctesterr, lst, true, 6);
            Fold(loctestnum, loctesterr, lst, true, &FoldAdd<double>, 0.0, 11.11+8.8+6.6+99.9+4.4+10.1);
            
            Map(loctestnum, loctesterr, lst, true, &MapIncrement<double>); 
            FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldAdd<double>, 0.0, (11.11+1)+(8.8+1)+(6.6+1)+(99.9+1)+(4.4+1)+(10.1+1));
        
            lst.Clear(); 
            Empty(loctestnum, loctesterr, lst, true);
            Size(loctestnum, loctesterr, lst, true, 0);
        }
        // Copy Constructor
        {
            lasd::List<double> lst1;
            InsertAtBack(loctestnum, loctesterr, lst1, true, 7.7);
            InsertAtFront(loctestnum, loctesterr, lst1, true, 8.8); 
            InsertAtBack(loctestnum, loctesterr, lst1, true, 9.9);  

            lasd::List<double> copylst(lst1);
            EqualList(loctestnum, loctesterr, lst1, copylst, true);
            EqualLinear(loctestnum, loctesterr, lst1, copylst, true);
            TraversePreOrder(loctestnum, loctesterr, copylst, true, &TraversePrint<double>);
            Size(loctestnum, loctesterr, copylst, true, 3);
            GetAt(loctestnum, loctesterr, copylst, true, 0, 8.8);

            Size(loctestnum, loctesterr, lst1, true, 3); 
            GetAt(loctestnum, loctesterr, lst1, true, 0, 8.8);

            MapPreOrder(loctestnum, loctesterr, copylst, true, &MapIncrement<double>);
            NonEqualList(loctestnum, loctesterr, lst1, copylst, true);
            NonEqualLinear(loctestnum, loctesterr, lst1, copylst, true);
            GetAt(loctestnum, loctesterr, lst1, true, 0, 8.8); 

            lasd::List<double> empty_lst;
            lasd::List<double> copy_of_empty(empty_lst);
            Empty(loctestnum, loctesterr, copy_of_empty, true);
            Size(loctestnum, loctesterr, copy_of_empty, true, 0);
            
            Empty(loctestnum, loctesterr, empty_lst, true); 
            Size(loctestnum, loctesterr, empty_lst, true, 0);
        }
        // Move constructor
        {
            lasd::List<double> lst_source_non_empty;
            InsertAtBack(loctestnum, loctesterr, lst_source_non_empty, true, 56.56);
            InsertAtFront(loctestnum, loctesterr, lst_source_non_empty, true, 23.23); 
            InsertAtBack(loctestnum, loctesterr, lst_source_non_empty, true, 10.1); 

            lasd::List<double> lst_moved(std::move(lst_source_non_empty));
            Size(loctestnum, loctesterr, lst_moved, true, 3);
            GetAt(loctestnum, loctesterr, lst_moved, true, 0, 23.23);
            FoldPreOrder(loctestnum, loctesterr, lst_moved, true, &FoldAdd<double>, 0.0, 23.23+56.56+10.1); 

            Empty(loctestnum, loctesterr, lst_source_non_empty, true); 
            Size(loctestnum, loctesterr, lst_source_non_empty, true, 0);
            
            lasd::List<double> lst_source_empty;
            lasd::List<double> lst_moved_from_empty(std::move(lst_source_empty));
            Empty(loctestnum, loctesterr, lst_moved_from_empty, true);
            Size(loctestnum, loctesterr, lst_moved_from_empty, true, 0);

            Empty(loctestnum, loctesterr, lst_source_empty, true); 
            Size(loctestnum, loctesterr, lst_source_empty, true, 0);
        }
        // Copy Assignment
        {
            lasd::List<double> lst_s1; 
            InsertAtBack(loctestnum, loctesterr, lst_s1, true, 10.1);
            InsertAtFront(loctestnum, loctesterr, lst_s1, true, 20.2);
            InsertAtBack(loctestnum, loctesterr, lst_s1, true, 30.3); 

            lasd::List<double> lst_s2; 
            InsertAtBack(loctestnum, loctesterr, lst_s2, true, 5.5);
            InsertAtFront(loctestnum, loctesterr, lst_s2, true, 15.15); 
            
            lasd::List<double> lst_empty_s; 

            lasd::List<double> lst_d1;   
            InsertAtBack(loctestnum, loctesterr, lst_d1, true, 99.9);

            lasd::List<double> lst_d_empty; 

            lst_d1 = lst_s1; 
            EqualList(loctestnum, loctesterr, lst_d1, lst_s1, true);
            Size(loctestnum, loctesterr, lst_d1, true, 3);
            GetAt(loctestnum, loctesterr, lst_d1, true, 1, 10.1);
            Size(loctestnum, loctesterr, lst_s1, true, 3); 

            lst_d_empty = lst_s2; 
            EqualList(loctestnum, loctesterr, lst_d_empty, lst_s2, true);
            Size(loctestnum, loctesterr, lst_d_empty, true, 2);
            GetAt(loctestnum, loctesterr, lst_d_empty, true, 0, 15.15);

            lst_d1 = lst_empty_s; 
            Empty(loctestnum, loctesterr, lst_d1, true);
            Size(loctestnum, loctesterr, lst_d1, true, 0);

            lst_d_empty = lst_empty_s; 
            Empty(loctestnum, loctesterr, lst_d_empty, true);
            
            // lasd::List<double> lst_self_assign(lst_s1); 
            // lst_self_assign = lst_self_assign;
            // EqualList(loctestnum, loctesterr, lst_self_assign, lst_s1, true);

            lasd::List<double> lst_orig_ind(lst_s1);
            lasd::List<double> lst_assign_ind;
            lst_assign_ind = lst_orig_ind;
            Map(loctestnum, loctesterr, lst_orig_ind, true, &MapIncrement<double>); 
            NonEqualList(loctestnum, loctesterr, lst_orig_ind, lst_assign_ind, true);
            GetAt(loctestnum, loctesterr, lst_assign_ind, true, 0, 20.2); 
        }
        // Move Assignment
        {
            lasd::List<double> lst_s1_move;
            InsertAtBack(loctestnum, loctesterr, lst_s1_move, true, 100.1);
            InsertAtFront(loctestnum, loctesterr, lst_s1_move, true, 200.2); 
            InsertAtBack(loctestnum, loctesterr, lst_s1_move, true, 300.3);  
            lasd::List<double> lst_d1_move; 
            InsertAtBack(loctestnum, loctesterr, lst_d1_move, true, 50.5);
            
            lst_d1_move = std::move(lst_s1_move); 
            Size(loctestnum, loctesterr, lst_d1_move, true, 3);
            GetAt(loctestnum, loctesterr, lst_d1_move, true, 1, 100.1);
            Empty(loctestnum, loctesterr, lst_s1_move, false); 
            Size(loctestnum, loctesterr, lst_s1_move, true, 1);

            lasd::List<double> lst_s2_move;
            InsertAtBack(loctestnum, loctesterr, lst_s2_move, true, 55.5);
            InsertAtFront(loctestnum, loctesterr, lst_s2_move, true, 66.6); 
            lasd::List<double> lst_d_empty_move;
            
            lst_d_empty_move = std::move(lst_s2_move); 
            Size(loctestnum, loctesterr, lst_d_empty_move, true, 2);
            GetAt(loctestnum, loctesterr, lst_d_empty_move, true, 0, 66.6);
            Empty(loctestnum, loctesterr, lst_s2_move, true); 

            lasd::List<double> lst_empty_s_move;
            lasd::List<double> lst_d3_move;
            InsertAtBack(loctestnum, loctesterr, lst_d3_move, true, 77.7);
            
            lst_d3_move = std::move(lst_empty_s_move); 
            Empty(loctestnum, loctesterr, lst_d3_move, true); 
            Empty(loctestnum, loctesterr, lst_empty_s_move, false); 

            // lasd::List<double> lst_self_move;
            // InsertAtBack(loctestnum, loctesterr, lst_self_move, true, 11.1);
            // lst_self_move = std::move(lst_self_move); 
            // Empty(loctestnum, loctesterr, lst_self_move, true); 
        }
        // Copy from TraversableContainer (SortableVector)
        {
            lasd::SortableVector<double> svec_empty_src(0);
            lasd::List<double> lst_from_empty_svec_copy(svec_empty_src);
            Empty(loctestnum, loctesterr, lst_from_empty_svec_copy, true);
            Empty(loctestnum, loctesterr, svec_empty_src, true); 
         
            lasd::SortableVector<double> svec_non_empty_src(3);
            SetAt(loctestnum, loctesterr, svec_non_empty_src, true, 0, 70.7); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src, true, 1, 50.5); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src, true, 2, 60.6); 
            
            lasd::List<double> lst_from_svec_copy(svec_non_empty_src);
            Size(loctestnum, loctesterr, lst_from_svec_copy, true, 3);
            EqualLinear(loctestnum, loctesterr, lst_from_svec_copy, svec_non_empty_src, true);        
            GetAt(loctestnum, loctesterr, lst_from_svec_copy, true, 0, 70.7); 
            
            Size(loctestnum, loctesterr, svec_non_empty_src, true, 3); 
            GetAt(loctestnum, loctesterr, svec_non_empty_src, true, 0, 70.7); 
            
            Map(loctestnum, loctesterr, lst_from_svec_copy, true, &MapDecrement<double>); 
            GetAt(loctestnum, loctesterr, svec_non_empty_src, true, 0, 70.7); 
        }
        // Move from MappableContainer (SortableVector)
        {
            lasd::SortableVector<double> svec_empty_src_move(0);
            lasd::List<double> lst_from_empty_svec_move(std::move(svec_empty_src_move)); 
            Empty(loctestnum, loctesterr, lst_from_empty_svec_move, true);
            Empty(loctestnum, loctesterr, svec_empty_src_move, true); 
         
            lasd::SortableVector<double> svec_non_empty_src_move(3); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src_move, true, 0, 4.4); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src_move, true, 1, 6.6); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src_move, true, 2, 5.5); 
            
            lasd::List<double> lst_from_svec_move(std::move(svec_non_empty_src_move)); 
            Size(loctestnum, loctesterr, lst_from_svec_move, true, 3);
            GetAt(loctestnum, loctesterr, lst_from_svec_move, true, 0, 4.4); 
            
            Empty(loctestnum, loctesterr, svec_non_empty_src_move, false);
            Size(loctestnum, loctesterr, svec_non_empty_src_move, true, 3); 
            GetAt(loctestnum, loctesterr, svec_non_empty_src_move, true, 0, 4.4);
        }
        // Copy from TraversableContainer (SETVEC - double)
        {
            lasd::SetVec<double> set_v_empty_src;
            lasd::List<double> lst_from_empty_setvec_copy(set_v_empty_src);
            Empty(loctestnum, loctesterr, lst_from_empty_setvec_copy, true);
            Empty(loctestnum, loctesterr, set_v_empty_src, true); 

            lasd::SetVec<double> set_v_non_empty_src;
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, 300.3);
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, 100.1);
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, 200.2); 

            lasd::List<double> lst_from_setvec_copy(set_v_non_empty_src);
            Size(loctestnum, loctesterr, lst_from_setvec_copy, true, 3);
            GetAt(loctestnum, loctesterr, lst_from_setvec_copy, true, 0, 100.1);
            EqualLinear(loctestnum, loctesterr, lst_from_setvec_copy, set_v_non_empty_src, true);

            Size(loctestnum, loctesterr, set_v_non_empty_src, true, 3); 
            Exists(loctestnum, loctesterr, set_v_non_empty_src, true, 100.1);
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MyList<double> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mylst_string(uint &testnum, uint &testerr)
{
    uint loctestnum = 0;
    uint loctesterr = 0;

    try
    {
        cout << endl<< "############################################################################"<< endl;
        cout << endl << "---------------------- Begin of MyList<string> tests: ----------------------" << endl;

        //EmptyListDefaultConstructor
        {
            lasd::List<string> lst;

            Empty(loctestnum, loctesterr, lst, true);
            Size(loctestnum, loctesterr, lst, true, 0);

            GetFront(loctestnum, loctesterr, lst, false, string("")); 
            GetBack(loctestnum, loctesterr, lst, false, string(""));  
            GetAt(loctestnum, loctesterr, lst, false, 0, string("")); 
            SetAt(loctestnum, loctesterr, lst, false, 0, string("a")); 
            SetFront(loctestnum, loctesterr, lst, false, string("b")); 
            SetBack(loctestnum, loctesterr, lst, false, string("c")); 


            Exists(loctestnum, loctesterr, lst, false, string("any"));

            Traverse(loctestnum, loctesterr, lst, true, &TraversePrint<string>);
            TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>);

            Fold(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string(""), string("")); 
            FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string("start:"), string("start:"));
            FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string("end:"), string("end:"));

            Map(loctestnum, loctesterr, lst, true, [](string& s){ MapStringAppend(s, "map"); }); 
            MapPreOrder(loctestnum, loctesterr, lst, true, [](string& s){ MapStringAppend(s, "mapPre"); }); 
            MapPostOrder(loctestnum, loctesterr, lst, true, [](string& s){ MapStringAppend(s, "mapPost"); }); 

            RemoveFromFront(loctestnum, loctesterr, lst, false); 
            FrontNRemove(loctestnum, loctesterr, lst, false, string("x"));
            RemoveFromBack(loctestnum, loctesterr, lst, false); 
            BackNRemove(loctestnum, loctesterr, lst, false, string("y")); 

            lst.Clear(); 
            Empty(loctestnum, loctesterr, lst, true);
        }
        
        //NonEmptyListOperations
        {
            lasd::List<string> lst;
            InsertAtBack(loctestnum, loctesterr, lst, true, string("is")); 
            InsertAtBack(loctestnum, loctesterr, lst, true, string("a")); 
            InsertAtFront(loctestnum, loctesterr, lst, true, string("This"));  
            InsertAtFront(loctestnum, loctesterr, lst, true, string("Hello"));  
            InsertAtBack(loctestnum, loctesterr, lst, true, string("test")); 
            InsertAtFront(loctestnum, loctesterr, lst, true, string("Greeting:")); 
            InsertAtBack(loctestnum, loctesterr, lst, true, string("!")); 
            InsertAtFront(loctestnum, loctesterr, lst, true, string("Start")); 
            InsertAtBack(loctestnum, loctesterr, lst, true, string("End")); 
            InsertAtFront(loctestnum, loctesterr, lst, true, string("Begin"));

            Empty(loctestnum, loctesterr, lst, false);
            Size(loctestnum, loctesterr, lst, true, 10);

            GetAt(loctestnum, loctesterr, lst, true, 0, string("Begin")); 
            GetAt(loctestnum, loctesterr, lst, true, 9, string("End")); 
            GetAt(loctestnum, loctesterr, lst, false, 10, string("")); 
            GetFront(loctestnum, loctesterr, lst, true, string("Begin"));
            GetBack(loctestnum, loctesterr, lst, true, string("End"));

            SetFront(loctestnum, loctesterr, lst, true, string("NewBegin"));  
            SetBack(loctestnum, loctesterr, lst, true, string("NewEnd"));  
            GetFront(loctestnum, loctesterr, lst, true, string("NewBegin"));
            GetBack(loctestnum, loctesterr, lst, true, string("NewEnd"));
            SetAt(loctestnum, loctesterr, lst, true, 5, string("REPLACED")); 

            Exists(loctestnum, loctesterr, lst, true, string("NewEnd"));
            Exists(loctestnum, loctesterr, lst, false, string("missing"));

            Traverse(loctestnum, loctesterr, lst, true, &TraversePrint<string>);
            TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>); 
            TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>); 

            Fold(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string("Prefix:"), string("Prefix:NewBeginStartGreeting:HelloThisREPLACEDatest!NewEnd")); 
            FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string(""), string("NewBeginStartGreeting:HelloThisREPLACEDatest!NewEnd"));
            FoldPostOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string(""), string("NewEnd!testaREPLACEDThisHelloGreeting:StartNewBegin"));

            // Removals
            FrontNRemove(loctestnum, loctesterr, lst, true, string("NewBegin")); 
            RemoveFromFront(loctestnum, loctesterr, lst, true); 
            BackNRemove(loctestnum, loctesterr, lst, true, string("NewEnd"));
            RemoveFromBack(loctestnum, loctesterr, lst, true); 
            Size(loctestnum, loctesterr, lst, true, 6); 
            Fold(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string(""), string("Greeting:HelloThisREPLACEDatest"));
            
            Map(loctestnum, loctesterr, lst, true, [](string& s){ MapStringAppend(s, "++"); }); 
            FoldPreOrder(loctestnum, loctesterr, lst, true, &FoldStringConcatenate, string(""), string("Greeting:++Hello++This++REPLACED++a++test++"));
        
            lst.Clear(); 
            Empty(loctestnum, loctesterr, lst, true);
            Size(loctestnum, loctesterr, lst, true, 0);
        }
        // Copy Constructor
        {
            lasd::List<string> lst1;
            InsertAtBack(loctestnum, loctesterr, lst1, true, string("One"));
            InsertAtFront(loctestnum, loctesterr, lst1, true, string("Two")); 
            InsertAtBack(loctestnum, loctesterr, lst1, true, string("Three")); 

            lasd::List<string> copylst(lst1);
            EqualList(loctestnum, loctesterr, lst1, copylst, true);
            EqualLinear(loctestnum, loctesterr, lst1, copylst, true);
            TraversePreOrder(loctestnum, loctesterr, copylst, true, &TraversePrint<string>); 
            Size(loctestnum, loctesterr, copylst, true, 3);
            GetAt(loctestnum, loctesterr, copylst, true, 0, string("Two"));

            MapPreOrder(loctestnum, loctesterr, copylst, true, [](string& s){ MapStringAppend(s, "_copy"); }); 
            NonEqualList(loctestnum, loctesterr, lst1, copylst, true);
            GetAt(loctestnum, loctesterr, lst1, true, 0, string("Two")); 

            lasd::List<string> empty_lst;
            lasd::List<string> copy_of_empty(empty_lst);
            Empty(loctestnum, loctesterr, copy_of_empty, true);
        }
        // Move constructor
        {
            lasd::List<string> lst_source_non_empty;
            InsertAtBack(loctestnum, loctesterr, lst_source_non_empty, true, string("Move"));
            InsertAtFront(loctestnum, loctesterr, lst_source_non_empty, true, string("Please")); 
            InsertAtBack(loctestnum, loctesterr, lst_source_non_empty, true, string("Me"));  

            lasd::List<string> lst_moved(std::move(lst_source_non_empty));
            Size(loctestnum, loctesterr, lst_moved, true, 3);
            GetAt(loctestnum, loctesterr, lst_moved, true, 0, string("Please"));
            FoldPreOrder(loctestnum, loctesterr, lst_moved, true, &FoldStringConcatenate, string(""), string("PleaseMoveMe")); 

            Empty(loctestnum, loctesterr, lst_source_non_empty, true); 
            
            lasd::List<string> lst_source_empty;
            lasd::List<string> lst_moved_from_empty(std::move(lst_source_empty));
            Empty(loctestnum, loctesterr, lst_moved_from_empty, true);
        }
        // Copy Assignment
        {
            lasd::List<string> lst_s1; 
            InsertAtBack(loctestnum, loctesterr, lst_s1, true, string("S1_B"));
            InsertAtFront(loctestnum, loctesterr, lst_s1, true, string("S1_A")); 
            InsertAtBack(loctestnum, loctesterr, lst_s1, true, string("S1_C")); 

            lasd::List<string> lst_s2; 
            InsertAtBack(loctestnum, loctesterr, lst_s2, true, string("S2_Y"));
            InsertAtFront(loctestnum, loctesterr, lst_s2, true, string("S2_X"));
            
            lasd::List<string> lst_empty_s; 
            lasd::List<string> lst_d1;   
            InsertAtBack(loctestnum, loctesterr, lst_d1, true, string("DestOriginal"));
            lasd::List<string> lst_d_empty; 

            lst_d1 = lst_s1; 
            EqualList(loctestnum, loctesterr, lst_d1, lst_s1, true);
            Size(loctestnum, loctesterr, lst_d1, true, 3);
            GetAt(loctestnum, loctesterr, lst_d1, true, 1, string("S1_B"));

            lst_d_empty = lst_s2; 
            EqualList(loctestnum, loctesterr, lst_d_empty, lst_s2, true);
            Size(loctestnum, loctesterr, lst_d_empty, true, 2);

            lst_d1 = lst_empty_s; 
            Empty(loctestnum, loctesterr, lst_d1, true);
            
            lasd::List<string> lst_orig_ind(lst_s1);
            lasd::List<string> lst_assign_ind;
            lst_assign_ind = lst_orig_ind;
            Map(loctestnum, loctesterr, lst_orig_ind, true, [](string& s){ MapStringAppend(s, "_mod"); }); 
            NonEqualList(loctestnum, loctesterr, lst_orig_ind, lst_assign_ind, true);
            GetAt(loctestnum, loctesterr, lst_assign_ind, true, 0, string("S1_A")); 
        }
        // Move Assignment
        {
            lasd::List<string> lst_s1_move;
            InsertAtBack(loctestnum, loctesterr, lst_s1_move, true, string("Move_B"));
            InsertAtFront(loctestnum, loctesterr, lst_s1_move, true, string("Move_A")); 
            InsertAtBack(loctestnum, loctesterr, lst_s1_move, true, string("Move_C"));  
            lasd::List<string> lst_d1_move; 
            InsertAtBack(loctestnum, loctesterr, lst_d1_move, true, string("Dest_Orig"));
            
            lst_d1_move = std::move(lst_s1_move); 
            Size(loctestnum, loctesterr, lst_d1_move, true, 3);
            GetAt(loctestnum, loctesterr, lst_d1_move, true, 1, string("Move_B"));
            Empty(loctestnum, loctesterr, lst_s1_move, false); 

            lasd::List<string> lst_s2_move;
            InsertAtBack(loctestnum, loctesterr, lst_s2_move, true, string("Another_Y"));
            InsertAtFront(loctestnum, loctesterr, lst_s2_move, true, string("Another_X")); 
            lasd::List<string> lst_d_empty_move;
            
            lst_d_empty_move = std::move(lst_s2_move); 
            Size(loctestnum, loctesterr, lst_d_empty_move, true, 2);
            Empty(loctestnum, loctesterr, lst_s2_move, true); 

            lasd::List<string> lst_empty_s_move;
            lasd::List<string> lst_d3_move;
            InsertAtBack(loctestnum, loctesterr, lst_d3_move, true, string("Content"));
            lst_d3_move = std::move(lst_empty_s_move); 
            Empty(loctestnum, loctesterr, lst_d3_move, true); 
        }
        // Copy from TraversableContainer (SortableVector<string>)
        {
            lasd::SortableVector<string> svec_empty_src(0);
            lasd::List<string> lst_from_empty_svec_copy(svec_empty_src);
            Empty(loctestnum, loctesterr, lst_from_empty_svec_copy, true);
         
            lasd::SortableVector<string> svec_non_empty_src(3);
            SetAt(loctestnum, loctesterr, svec_non_empty_src, true, 0, string("Vec0")); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src, true, 1, string("Vec1")); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src, true, 2, string("Vec2")); 
            
            lasd::List<string> lst_from_svec_copy(svec_non_empty_src);
            Size(loctestnum, loctesterr, lst_from_svec_copy, true, 3);
            EqualLinear(loctestnum, loctesterr, lst_from_svec_copy, svec_non_empty_src, true);        
            GetAt(loctestnum, loctesterr, lst_from_svec_copy, true, 1, string("Vec1"));
            
            Map(loctestnum, loctesterr, lst_from_svec_copy, true, [](string& s){ MapStringAppend(s, "_list"); }); 
            GetAt(loctestnum, loctesterr, svec_non_empty_src, true, 1, string("Vec1")); 
        }
        // Move from MappableContainer (SortableVector<string>)
        {
            lasd::SortableVector<string> svec_empty_src_move(0);
            lasd::List<string> lst_from_empty_svec_move(std::move(svec_empty_src_move)); 
            Empty(loctestnum, loctesterr, lst_from_empty_svec_move, true);
         
            lasd::SortableVector<string> svec_non_empty_src_move(3); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src_move, true, 0, string("MVec0")); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src_move, true, 1, string("MVec1")); 
            SetAt(loctestnum, loctesterr, svec_non_empty_src_move, true, 2, string("MVec2")); 
            
            lasd::List<string> lst_from_svec_move(std::move(svec_non_empty_src_move)); 
            Size(loctestnum, loctesterr, lst_from_svec_move, true, 3);
            GetAt(loctestnum, loctesterr, lst_from_svec_move, true, 1, string("MVec1"));
            
            Size(loctestnum, loctesterr, svec_non_empty_src_move, true, 3); 
            GetAt(loctestnum, loctesterr, svec_non_empty_src_move, false, 1, string("MVec1"));
        }
        // Copy from TraversableContainer (SetVec<string>)
        {
            lasd::SetVec<string> set_v_empty_src;
            lasd::List<string> lst_from_empty_setvec_copy(set_v_empty_src);
            Empty(loctestnum, loctesterr, lst_from_empty_setvec_copy, true);

            lasd::SetVec<string> set_v_non_empty_src;
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, string("Zeta"));
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, string("Alpha"));
            InsertC(loctestnum, loctesterr, set_v_non_empty_src, true, string("Gamma")); 

            lasd::List<string> lst_from_setvec_copy(set_v_non_empty_src);
            Size(loctestnum, loctesterr, lst_from_setvec_copy, true, 3);
            GetAt(loctestnum, loctesterr, lst_from_setvec_copy, true, 0, string("Alpha"));
            GetAt(loctestnum, loctesterr, lst_from_setvec_copy, true, 1, string("Gamma"));
            GetAt(loctestnum, loctesterr, lst_from_setvec_copy, true, 2, string("Zeta"));
            EqualLinear(loctestnum, loctesterr, lst_from_setvec_copy, set_v_non_empty_src, true);
        }
    }
    catch(...)
    {
        loctestnum++;
        loctesterr++;
        cout << endl << "../Unmanaged error! " << endl;
    }

    cout << endl << "---------------------- End of MyList<string> tests! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;;
    testnum += loctestnum;
    testerr += loctesterr;
}

/* ************************************************************************** */

void lst_test(uint &testnum, uint &testerr)
{
    mylst_int(testnum, testerr);
    mylst_double(testnum, testerr);
    mylst_string(testnum, testerr);
}