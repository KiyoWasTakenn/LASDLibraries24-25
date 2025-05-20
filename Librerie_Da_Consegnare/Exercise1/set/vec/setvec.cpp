#include "setvec.hpp"

namespace lasd {

/* ************************************************************************** */

/* ---------------------------SetVec: Specific Constructors/Destructors-------------------------- */

template <typename Data>
SetVec<Data>::SetVec(): Vector<Data>(2)
{  
    capacity = size; 
    size = 0;
}

// Specific constructors
template <typename Data>
SetVec<Data>::SetVec(const TraversableContainer<Data> &cont) : Vector<Data>(cont.Size()) // A set obtained from a TraversableContainer
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
SetVec<Data>::SetVec(MappableContainer<Data> &&cont) noexcept : Vector<Data>(cont.Size()) // A set obtained from a MappableContainer non mette noexcept? 
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
SetVec<Data>::SetVec(const SetVec &vec) : Vector<Data>(vec.Size())
    {
        this->capacity = vec.capacity;
        this->head = vec.head;

        for(ulong i = 0; i < capacity ; i++)
            (*this)[i] = vec[i];
    }

// Move constructor
template <typename Data>
SetVec<Data>::SetVec(SetVec &&vec) noexcept
{
    std::swap(this->Elements, vec.Elements);
    std::swap(this->size, vec.size);
    std::swap(this->head, vec.head);
    std::swap(this->capacity, vec.capacity);
}

/* ---------------------------SetVec: Assignments-------------------------- */

// Copy assignment
template <typename Data>
SetVec<Data> & SetVec<Data>::operator=(const SetVec &vec)
{
    SetVec<Data> * tmp = new SetVec<Data>(vec);

    std::swap(*tmp, *this);
    delete tmp;

    return *this;
}

// Move assignment
template <typename Data>
SetVec<Data> & SetVec<Data>::operator=(SetVec &&vec) noexcept
{
    std::swap(this->Elements, vec.Elements);
    std::swap(this->size, vec.size);
    std::swap(this->head, vec.head);
    std::swap(this->capacity, vec.capacity);

    return *this;
}

/* ---------------------------SetVec: Comparison Operators-------------------------- */

template <typename Data>
bool SetVec<Data>::operator==(const SetVec &vec) const noexcept
{
    if(this->capacity == vec.capacity)
    {
        for(ulong i = 0; i < this->capacity ; i++)
            if( (*this)[i] != vec[i])
                return false;
        return true;
    }
    return false;
}

template <typename Data>
inline bool SetVec<Data>::operator!=(const SetVec &vec) const noexcept
{
    return !((*this) == vec);
}

/* ---------------------------SetVec: Specific member functions (inherited from OrderedDictionaryContainer)------------------------- */

template <typename Data>
const Data & SetVec<Data>::Min() const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec\n");
    
    return (*this)[0];
}

template <typename Data>
Data SetVec<Data>::MinNRemove() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec\n");

    Data tmpMin = (*this)[0];

    head = (head + 1) % size; 
    capacity--;

    checkResize();
    
    return tmpMin;
}

template <typename Data>
void SetVec<Data>::RemoveMin() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec\n");

    head = (head + 1) % size;
    capacity--;
   
    checkResize();
}

template <typename Data>
const Data & SetVec<Data>::Max() const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec\n");
    
    return (*this)[capacity - 1];
}

template <typename Data>
Data SetVec<Data>::MaxNRemove() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec\n");

    Data tmpMax = (*this)[capacity - 1];

    if(capacity == 1)
        head = 0;

    capacity--;
    checkResize();

    return tmpMax;
}

template <typename Data>
void SetVec<Data>::RemoveMax() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec\n");

    if(capacity == 1)
        head = 0;
    
    capacity--;
    checkResize();
}

template <typename Data>
const Data & SetVec<Data>::Predecessor(const Data &key) const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    ulong index = BSearchPred(key);

    if(index == capacity)
        throw std::length_error("Predecessor Not Found from SetVec");

    return (*this)[index];    
}

template <typename Data>
Data SetVec<Data>::PredecessorNRemove(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    ulong index = BSearchPred(key);

    if(index == capacity)
        throw std::length_error("Predecessor Not Found from SetVec");

    Data tmpPred = (*this)[index];

    IndexedRemove(index);

    return tmpPred;
}

template <typename Data>
void SetVec<Data>::RemovePredecessor(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    ulong index = BSearchPred(key);

    if(index == capacity)
        throw std::length_error("Predecessor Not Found from SetVec");

    IndexedRemove(index);
}

template <typename Data>
const Data & SetVec<Data>::Successor(const Data &key) const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    ulong index = BSearchSucc(key);

    if(index == capacity)
        throw std::length_error("Predecessor Not Found from SetVec");

    return (*this)[index];   
}

template <typename Data>
Data SetVec<Data>::SuccessorNRemove(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    ulong index = BSearchSucc(key);

    if(index == capacity)
        throw std::length_error("Predecessor Not Found from SetVec");

    Data tmpSucc = (*this)[index];

    IndexedRemove(index);

    return tmpSucc;
}

template <typename Data>
void SetVec<Data>::RemoveSuccessor(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    ulong index = BSearchSucc(key);

    if(index == capacity)
        throw std::length_error("Predecessor Not Found from SetVec");

    IndexedRemove(index);
}

/* ---------------------------SetVec: Specific member functions (inherited from DictionaryContainer)------------------------- */

template <typename Data>
bool SetVec<Data>::Insert(const Data &key) // Override DictionaryContainer member (copy of the value)
{
    checkResize();
    
    ulong i = BinarySearchEqPred(key);
    
    if(i != capacity && (*this)[i] == key)
        return false;
    
    if(i == capacity)    // Devo inserire in testa prima di head (capacity == 0 o pred trovato)
    {
        head = (head == 0) ? size - 1 : head - 1;
        (*this)[0] = key;
    }
    else if (i == capacity - 1) // Devo inserire in coda dopo tail (binary va su capacity - 1)
    {
        (*this)[capacity] = key;
    }
    else
    {
        ulong left_elems = i + 1;
        ulong right_elems = capacity - left_elems;

        if(left_elems >= right_elems)
        {

            RightShift(i + 1, right_elems);
            (*this)[i + 1] = key;
        } 
        else
        {
            head = (head == 0) ? size - 1 : head - 1;
            LeftShift(0, left_elems);
            (*this)[i] = key;
        }
    }

    capacity++;
    return true;
}

template <typename Data>
bool SetVec<Data>::Insert(Data &&key) // Override DictionaryContainer member (move of the value)
{
    checkResize();
    
    ulong i = BinarySearchEqPred(key);
    
    if(i != capacity && (*this)[i] == key)
        return false;
    
    if(i == capacity)    // Devo inserire in testa prima di head (capacity == 0 o pred trovato)
    {
        head = (head == 0) ? size - 1 : head - 1;
        (*this)[0] = std::move(key);
    }
    else if (i == capacity - 1) // Devo inserire in coda dopo tail (binary va su capacity - 1)
    {
        (*this)[capacity] = std::move(key);
    }
    else
    {
        ulong left_elems = i + 1;
        ulong right_elems = capacity - left_elems;

        if(left_elems >= right_elems)
        {

            RightShift(i + 1, right_elems);
            (*this)[i + 1] = std::move(key);
        } 
        else
        {
            head = (head == 0) ? size - 1 : head - 1;
            LeftShift(0, left_elems);
            (*this)[i] = std::move(key);
        }
    }

    capacity++;
    return true;
}

template <typename Data>
bool SetVec<Data>::Remove(const Data &key) // Override DictionaryContainer member
{
    ulong i = BSearchExists(key);
    
    if(i == capacity)
        return false;
    
    return IndexedRemove(i);
}

/* ---------------------------SetVec: Specific member functions (inherited from LinearContainer)------------------------- */

template <typename Data>
const Data & SetVec<Data>::operator[](const ulong offset) const
{
    if(offset >= capacity)
        throw std::out_of_range("Out Of Range Exception from LinearContainer(SetVec) \n");

    return Elements[(head + offset) % size];
}
/* ---------------------------SetVec: Specific member functions (inherited from TestableContainer)------------------------- */

template <typename Data>
bool SetVec<Data>::Exists(const Data &key) const noexcept
{
    return (BSearchExists(key) != capacity);
}

/* ---------------------------SetVec: Specific member functions (inherited from ClearableContainer)------------------------- */

template <typename Data>
void SetVec<Data>::Clear()
{
    Vector<Data>::Clear();
    capacity = 0;
    head = 0;
}

/* ---------------------------SetVec: Protected auxilary functions------------------------- */

template<typename Data>
void SetVec<Data>::RightShift(ulong index, ulong to_shift)
{
    for(ulong i = to_shift; i > 0; i--)
        (*this)[index + i] = (*this)[index + i - 1];
}

template<typename Data>
void SetVec<Data>::LeftShift(ulong index, ulong to_shift)
{
    for(ulong i = 0 ; i < to_shift; i++)
        (*this)[index + i - 1 + size] = (*this)[index + i];
}

template <typename Data>
bool SetVec<Data>::IndexedRemove(ulong to_remove) // Quando ho già la posizione
{
    ulong left_elems = to_remove;
    ulong right_elems = capacity - to_remove - 1;

    if(left_elems >= right_elems)
    {

    }
    else
    {

    }
}

template <typename Data>
void SetVec<Data>::checkResize()
{ 
    if(size == 0) // controllare 
        {
            Elements = new Data[2] {};
            size = 2;
            head = 0;
            capacity = 0;
        }
    
    if(static_cast<double>(capacity) / size <= 0.25 && size > 2)
        Resize(std::max(size / 2, 2UL));
    else if(static_cast<double>(capacity) / size >= 0.9)
        Resize(size * 2);
}

// From ResizableContainer
template <typename Data>
void SetVec<Data>::Resize(ulong newSize)
{
    Data * resElements = new Data[newSize] {};

    if(newSize > size)
    {
        ulong l_spaces = (newSize - size) / 2 - 1; 
        ulong r_spaces = (newSize - size) / 2 - 1 
        for(ulong i = 0 + l_spaces; i < newSize - spaces; i++)
        {

        }
    }
    else
    {

    }

    std::swap(Elements, resElements)

    delete[] resElements;
}

// Ricerche specializzate per evitare confronti di uguaglianza nelle funzioni 

template <typename Data>
ulong SetVec<Data>::BSearchExists(const Data &key) const // Cerca == Key
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec : BSearch\n");
    
    ulong i = 0;
    ulong j = capacity - 1;

    while(i <= j)
    {
        ulong q = i + (j - i) / 2;

        if((*this)[q] == key)
            return q; 
        if((*this)[q] < key)
            {
                i = q + 1;
            }
        else
        {
            if(q==0)
                break;
            
            j = q - 1;
        }
    }
    return capacity;
}

template<typename Data>
ulong SetVec<Data>::BSearchEqPred(const Data &key) const // Cerca <= key
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec : BSearch\n");
    
    ulong i = 0;
    ulong j = capacity - 1;
    ulong pred_idx = capacity;

    while(i <= j)
    {
        ulong q = i + (j - i) / 2;

        if((*this)[q] == key)
            return q; 
        if((*this)[q] < key)
            {
                pred_idx = q;
                i = q + 1;
            }
        else
        {
            if(q==0)
                break;
            
            j = q - 1;
        }
    }
    return pred_idx;
}


template<typename Data>
ulong SetVec<Data>::BSearchPred(const Data &key) const
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec : BSearch\n");

    ulong i = 0;
    ulong j = capacity - 1;
    ulong pred_idx = capacity;

    while (i <= j)
    {
        ulong q = i + (j - i) / 2;

        if ((*this)[q] < key)
        {
            pred_idx = q;
            i = q + 1;
        } 
        else
        {
            if (q == 0)
                break;

            j = q - 1;
        }
    }
    return pred_idx;
}

template<typename Data>
ulong SetVec<Data>::BSearchSucc(const Data &key) const
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec : BSearch\n");

    ulong i = 0;
    ulong j = capacity - 1;
    ulong succ_idx = capacity;

    while (i <= j) 
    {
        ulong q = i + (j - i) / 2;

        if ((*this)[q] > key)
        {
            succ_idx = q;
            if (q == 0) 
                break;

            j = q - 1;
        } 
        else
        {
            i = q + 1;
        }
    }
    return succ_idx;
}

}
/* ************************************************************************** */



