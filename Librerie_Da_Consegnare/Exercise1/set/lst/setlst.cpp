#include "setlst.hpp"

namespace lasd {

/* ************************************************************************** */

/* ---------------------------SetLst: Specific Constructors/Destructors-------------------------- */

// Specific constructors
template <typename Data>
SetLst<Data>::SetLst(const TraversableContainer<Data> &cont) // A set obtained from a TraversableContainer
{
    cont.Traverse
    (
        [this] (const Data &curr)
        {   
            Insert(curr);
        }
    );
}

template <typename Data>
SetLst<Data>::SetLst(MappableContainer<Data> &&cont) noexcept // A set obtained from a MappableContainer non mette noexcept? 
{
    cont.Map
    (
        [this] (Data &curr)
        {   
            Insert(std::move(curr));
        }
    );
}

// Copy constructor
template <typename Data>
SetLst<Data>::SetLst(const SetLst &lst) : List<Data>::List(lst) { }

// Move constructor
template <typename Data>
SetLst<Data>::SetLst(SetLst &&lst) noexcept
{
    std::swap(this->head, lst.head);
    std::swap(this->tail, lst.tail);
    std::swap(this->size, lst.size);  
}

/* ---------------------------SetLst: Assignments-------------------------- */

// Copy assignment
template <typename Data>
SetLst<Data> & SetLst<Data>::operator=(const SetLst &lst)
{
    List<Data>::operator=(lst);
    return *this;
}

// Move assignment
template <typename Data>
SetLst<Data> & SetLst<Data>::operator=(SetLst &&lst) noexcept
{
    std::swap(this->head, lst.head);
    std::swap(this->tail, lst.tail);
    std::swap(this->size, lst.size); 

    return *this;
}

/* ---------------------------SetLst: Comparison Operators-------------------------- */

template <typename Data>
bool SetLst<Data>::operator==(const SetLst &lst) const noexcept
{
    return List<Data>::operator==(lst);
}

template <typename Data>
inline bool SetLst<Data>::operator!=(const SetLst &lst) const noexcept
{
    return !((*this) == lst);
}

/* ---------------------------SetLst: Specific member functions (inherited from OrderedDictionaryContainer)------------------------- */

template <typename Data>
const Data & SetLst<Data>::Min() const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(!head)
        throw std::length_error("Empty Exception from SetList");
    
    return head->elem;
}

template <typename Data>
Data SetLst<Data>::MinNRemove() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(!head)
        throw std::length_error("Empty Exception from SetList");

    Data tmpMin = std::move(head->elem);
    List<Data>::RemoveFromFront();

    return tmpMin;
}

template <typename Data>
void SetLst<Data>::RemoveMin() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(!head)
        throw std::length_error("Empty Exception from SetList");
    
    List<Data>::RemoveFromFront();
}

template <typename Data>
const Data & SetLst<Data>::Max() const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(!head)
        throw std::length_error("Empty Exception from SetList");
    
    return tail->elem;
}

template <typename Data>
Data SetLst<Data>::MaxNRemove() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(!head)
        throw std::length_error("Empty Exception from SetList");
    
    Data tmpMax = tail->elem;

    List<Data>::RemoveFromBack();

    return tmpMax;
}

template <typename Data>
void SetLst<Data>::RemoveMax() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(!head)
        throw std::length_error("Empty Exception from SetList");

    List<Data>::RemoveFromBack();
}

template <typename Data>
const Data & SetLst<Data>::Predecessor(const Data &key) const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    bool check = false;
    Node * prev = BSearchPred(key, &check);

    if(!prev)
        throw std::length_error("Predecessor not found: SetLst");
    
    return prev->elem;
}

template <typename Data>
Data SetLst<Data>::PredecessorNRemove(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{



    if(0)
        throw std::length_error("Predecessor not found: SetLst");

    
}

template <typename Data>
void SetLst<Data>::RemovePredecessor(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    
    
    
    
    
    if(0)
        throw std::length_error("Predecessor not found: SetLst");

    
}

template <typename Data>
const Data & SetLst<Data>::Successor(const Data &key) const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    Node * succ = BSearchSucc(key);
    if(!succ)
        throw std::length_error("Successor not found: SetLst");

    return succ->elem;
}

template <typename Data>
Data SetLst<Data>::SuccessorNRemove(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    
    
    
    if(0)
        throw std::length_error("Successor not found: SetLst");

    
}

template <typename Data>
void SetLst<Data>::RemoveSuccessor(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{


    if(0)
        throw std::length_error("Successor not found: SetLst");

    
}
/* ---------------------------SetLst: Specific member functions (inherited from DictionaryContainer)------------------------- */

template <typename Data>
bool SetLst<Data>::Insert(const Data &key) // Override DictionaryContainer member (copy of the value)
{
    if(size == 0)
        List<Data>::InsertAtFront(key);
    else
    {
        bool check = false;
        Node * prev = BSearchEqPred(key, &check);

        if(check)
            return false;
        else
        {
            if(!prev)
                List<Data>::InsertAtFront(key);
            else
                {
                    Node * tmp = new Node(key);

                    tmp->next = prev->next;
                    prev->next = tmp;
                    
                    if(!tmp->next)
                        tail = tmp;

                    size++;
                }
        }
    }
    return true;
}

template <typename Data>
bool SetLst<Data>::Insert(Data &&key) // Override DictionaryContainer member (move of the value)
{
    if(size == 0)
        List<Data>::InsertAtFront(key);
    else
    {
        bool check = false;
        Node * pred = BSearchEqPred(key, &check);

        if(check)
            return false;
        else
        {
            if(!pred)
                List<Data>::InsertAtFront(key);
            else
                {
                    Node * tmp = new Node(std::move(key));

                    tmp->next = pred->next;
                    pred->next = tmp;
                    
                    if(!tmp->next)
                        tail = tmp;

                    size++;
                }
        }
    }
    return true;
}

template <typename Data>
bool SetLst<Data>::Remove(const Data &key) // Override DictionaryContainer member
{
    if(size != 0)
    {
        bool check = false;
        Node * pred = BSearchPred(key, &check);

        if(check)
        {
            if(!pred)
                List<Data>::RemoveFromFront();
            else
            {
                Node * tmp = pred->next;
                pred->next = tmp->next;

                if(!tmp->next)
                    tail = pred;
                else
                    tmp->next = nullptr;

                delete tmp;
                size--;
            }
            return true;
        }
    }
    return false;
}

/* ---------------------------SetLst: Specific member functions (inherited from LinearContainer)------------------------- */

template <typename Data>
const Data & SetLst<Data>::operator[](const ulong index) const
{
    return List<Data>::operator[](index);
}

/* ---------------------------SetLst: Specific member functions (inherited from TestableContainer)------------------------- */

template <typename Data>
bool SetLst<Data>::Exists(const Data &key) const noexcept
{
    bool check = false;

    BSearchEqPred(key, &check);

    return check;
} 

/* ---------------------------SetLst: Specific member functions (inherited from ClearableContainer)------------------------- */

template <typename Data>
void SetLst<Data>::Clear()
{
    List<Data>::Clear();
}

/* ---------------------------SetLst: Protected auxilary functions (inherited from)------------------------- */

template <typename Data>
typename SetLst<Data>::Node* SetLst<Data>::BSearchEqPred(const Data &key, bool * check) const
{
    ulong length = size;

    Node * reminder = head;
    Node * pred = nullptr;

    while(length > 0)
    {
       ulong mid = length/2;
       Node * walk_ptr = reminder;

       for(ulong i = 0; i < mid; i++)
            walk_ptr = walk_ptr->next;

       if(!walk_ptr) 
            break;

       if(walk_ptr->elem < key)
       {
            pred = walk_ptr;
            reminder = walk_ptr->next;
            length -= mid+1;
       }
       else if(walk_ptr->elem > key)
       {
            length = mid;
       }
       else 
       {
            *check = true;
            return walk_ptr;
       }  
    }
    return pred;
} 

template <typename Data>
typename SetLst<Data>::Node* SetLst<Data>::BSearchPred(const Data &key, bool * check) const
{
    ulong length = size;

    Node * reminder = head;
    Node * pred = nullptr;

    while(length > 0)
    {
       ulong mid = length/2;
       Node * walk_ptr = reminder;

       for(ulong i = 0; i < mid; i++)
            walk_ptr = walk_ptr->next;

       if(!walk_ptr) 
            break;

       if(walk_ptr->elem < key)
       {
            pred = walk_ptr;
            reminder = walk_ptr->next;
            length -= mid+1;
       }
       else if(walk_ptr->elem > key)
       {
            length = mid;
       }
       else 
       {
            *check = true;
            return pred;
       }  
    }
    return pred;
} 

template <typename Data>
typename SetLst<Data>::Node* SetLst<Data>::BSearchSucc(const Data &key) const
{
    ulong length = size;

    Node * reminder = head;
    Node * succ = nullptr;

    while(length > 0)
    {
       ulong mid = length/2;
       Node * walk_ptr = reminder;

       for(ulong i = 0; i < mid; i++)
            walk_ptr = walk_ptr->next;

       if(!walk_ptr) 
            break;

       if(walk_ptr->elem > key)
       {
            succ = walk_ptr;
            length = mid;
       }
       else
       {
            reminder = walk_ptr->next;
            length -= mid+1;
       }
       
    }
    return succ;
} 

/* ************************************************************************** */

}
