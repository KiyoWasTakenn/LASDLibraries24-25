
namespace lasd {

/* ************************************************************************** */

/* ---------------------------SetLst: Specific Constructors/Destructors-------------------------- */

// Specific constructors
template <typename Data>
SetLst<Data>::SetLst(const TraversableContainer<Data> &) // A set obtained from a TraversableContainer
{

}

template <typename Data>
SetLst<Data>::SetLst(MappableContainer<Data> &&) noexcept // A set obtained from a MappableContainer non mette noexcept? 
{

}


// Copy constructor
template <typename Data>
SetLst<Data>::SetLst(const SetLst &)
{

}

// Move constructor
template <typename Data>
SetLst<Data>::SetLst(SetLst &&) noexcept
{

}

template <typename Data>
SetLst<Data>::~SetLst()
{

}

/* ---------------------------SetLst: Assignments-------------------------- */

// Copy assignment
template <typename Data>
SetLst<Data> & SetLst<Data>::operator=(const SetLst &)
{

}

// Move assignment
template <typename Data>
SetLst<Data> & SetLst<Data>::operator=(SetLst &&) noexcept
{

}

/* ---------------------------SetLst: Comparison Operators-------------------------- */

template <typename Data>
bool SetLst<Data>::operator==(const SetLst &) const noexcept
{

}

template <typename Data>
inline bool SetLst<Data>::operator!=(const SetLst &) const noexcept
{

}

/* ---------------------------SetLst: Specific member functions (inherited from OrderedDictionaryContainer)------------------------- */

template <typename Data>
const Data & SetLst<Data>::Min() const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{

}

template <typename Data>
Data SetLst<Data>::MinNRemove() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{

}

template <typename Data>
void SetLst<Data>::RemoveMin() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{

}

template <typename Data>
const Data & SetLst<Data>::Max() const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{

}

template <typename Data>
Data SetLst<Data>::MaxNRemove() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{

}

template <typename Data>
void SetLst<Data>::RemoveMax() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{

}

template <typename Data>
const Data & SetLst<Data>::Predecessor(const Data &) const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{

}

template <typename Data>
Data SetLst<Data>::PredecessorNRemove(const Data &) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{

}

template <typename Data>
void SetLst<Data>::RemovePredecessor(const Data &) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{

}

template <typename Data>
const Data & SetLst<Data>::Successor(const Data &) const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{

}

template <typename Data>
Data SetLst<Data>::SuccessorNRemove(const Data &) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{

}

template <typename Data>
void SetLst<Data>::RemoveSuccessor(const Data &) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{

}
/* ---------------------------SetLst: Specific member functions (inherited from DictionaryContainer)------------------------- */

template <typename Data>
bool SetLst<Data>::Insert(const Data &) // Override DictionaryContainer member (copy of the value)
{

}

template <typename Data>
bool SetLst<Data>::Insert(Data &&) // Override DictionaryContainer member (move of the value)
{

}

template <typename Data>
bool SetLst<Data>::Remove(const Data &) // Override DictionaryContainer member
{

}

/* ---------------------------SetLst: Specific member functions (inherited from LinearContainer)------------------------- */

template <typename Data>
const Data & SetLst<Data>::operator[](const ulong) const
{

}

/* ---------------------------SetLst: Specific member functions (inherited from TestableContainer)------------------------- */

template <typename Data>
bool SetLst<Data>::Exists(const Data &) const noexcept
{

}

/* ---------------------------SetLst: Specific member functions (inherited from ClearableContainer)------------------------- */

template <typename Data>
void SetLst<Data>::Clear()
{

}

/* ---------------------------SetLst: Protected auxilary functions (inherited from)------------------------- */



/* ************************************************************************** */

}
