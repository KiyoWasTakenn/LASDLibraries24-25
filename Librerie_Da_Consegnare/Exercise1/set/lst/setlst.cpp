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
SetLst<Data>::SetLst(const SetLst &lst)
{
    List<Data>::List(lst);
}

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
    return List<Data>::operator=(lst);
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
    return List<Data>operator==(lst);
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
    RemoveFromFront();

    return tmpMin;
}

template <typename Data>
void SetLst<Data>::RemoveMin() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(!head)
        throw std::length_error("Empty Exception from SetList");
    
    RemoveFromFront();
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

    RemoveFromBack();

    return tmpMax;
}

template <typename Data>
void SetLst<Data>::RemoveMax() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(!head)
        throw std::length_error("Empty Exception from SetList");

    RemoveFromBack();
}

template <typename Data>
const Data & SetLst<Data>::Predecessor(const Data &key) const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    if()
        throw std::length_error("Predecessor not found: SetLst");
}

template <typename Data>
Data SetLst<Data>::PredecessorNRemove(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    if()
        throw std::length_error("Predecessor not found: SetLst");

    
}

template <typename Data>
void SetLst<Data>::RemovePredecessor(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    if()
        throw std::length_error("Predecessor not found: SetLst");

    
}

template <typename Data>
const Data & SetLst<Data>::Successor(const Data &key) const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    if()
        throw std::length_error("Successor not found: SetLst");

    
}

template <typename Data>
Data SetLst<Data>::SuccessorNRemove(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    if()
        throw std::length_error("Successor not found: SetLst");

    
}

template <typename Data>
void SetLst<Data>::RemoveSuccessor(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    if()
        throw std::length_error("Successor not found: SetLst");

    
}
/* ---------------------------SetLst: Specific member functions (inherited from DictionaryContainer)------------------------- */

template <typename Data>
bool SetLst<Data>::Insert(const Data &key) // Override DictionaryContainer member (copy of the value)
{

}

template <typename Data>
bool SetLst<Data>::Insert(Data &&key) // Override DictionaryContainer member (move of the value)
{

}

template <typename Data>
bool SetLst<Data>::Remove(const Data &key) // Override DictionaryContainer member
{

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
    
}

/* ---------------------------SetLst: Specific member functions (inherited from ClearableContainer)------------------------- */

template <typename Data>
void SetLst<Data>::Clear()
{
    List<Data>::Clear();
}

/* ---------------------------SetLst: Protected auxilary functions (inherited from)------------------------- */

template <typename Data>
typename SetLst<Data>::Node*& SetLst<Data>::Reach(Node * ptr, const ulong n)
{
    if(!ptr)
        

    Node **walk_ptr = &ptr;
    
    ()

}


template <typename Data>
typename SetLst<Data>::Node*& SetLst<Data>::BSearchExists(const Data &key) const
{
    

}

template <typename Data>
typename SetLst<Data>::Node*& SetLst<Data>::BSearchEqPred(const Data &key) const
{

}

template <typename Data>
typename SetLst<Data>::Node*& SetLst<Data>::BSearchPred(const Data &key) const
{

}

template <typename Data>
typename SetLst<Data>::Node*& SetLst<Data>::BSearchPred(const Data &key) const
{

}

/* ************************************************************************** */

}
