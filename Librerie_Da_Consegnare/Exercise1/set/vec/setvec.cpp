#include "setvec.hpp"

namespace lasd {

/* ************************************************************************** */

/* ---------------------------SetVec: Specific Constructors/Destructors-------------------------- */

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
    
    return Elements[0];
}

template <typename Data>
Data SetVec<Data>::MinNRemove() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec\n");

    Data tmpMin = Elements[0];

    capacity--;
    head = (head + 1) % size;

    checkResize();
    
    return tmpMin;
}

template <typename Data>
void SetVec<Data>::RemoveMin() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec\n");

    capacity--;
    head = (head + 1) % size;

    checkResize();
}

template <typename Data>
const Data & SetVec<Data>::Max() const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec\n");
    
    return Elements[capacity - 1];
}

template <typename Data>
Data SetVec<Data>::MaxNRemove() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec\n");

    Data tmpMax = Elements[capacity - 1];

    capacity--;
    checkResize();

    return tmpMax;
}

template <typename Data>
void SetVec<Data>::RemoveMax() // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
{
    if(capacity == 0)
        throw std::length_error("Empty Exception from SetVec\n");

    capacity--;
    checkResize();
}

template <typename Data>
const Data & SetVec<Data>::Predecessor(const Data &key) const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    ulong index = BSearchPred(key);

    if(index == size)
        throw std::length_error("Predecessor Not Found from SetVec");
    
}

template <typename Data>
Data SetVec<Data>::PredecessorNRemove(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    
}

template <typename Data>
void SetVec<Data>::RemovePredecessor(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    
}

template <typename Data>
const Data & SetVec<Data>::Successor(const Data &key) const // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    
}

template <typename Data>
Data SetVec<Data>::SuccessorNRemove(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    
}

template <typename Data>
void SetVec<Data>::RemoveSuccessor(const Data &key) // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
{
    
}

/* ---------------------------SetVec: Specific member functions (inherited from DictionaryContainer)------------------------- */

template <typename Data>
bool SetVec<Data>::Insert(const Data &key) // Override DictionaryContainer member (copy of the value)
{
    checkResize();
    ulong i = BinarySearch(key);
    ulong tail = (head + capacity - 1) % size;

    if(i != size && Elements[i] == key)
        return false;

    if(i == size) // Devo inserire in testa prima di head perchè la BS non da risultati di <= 
    {
        head = (head == 0) ? size - 1 : head - 1;
        Elements[head] = key;
    }
    else
    {
        if(Elements[tail] < key) // Se sto inserendo il massimo allora basta inserire dopo tail 
            Elements[(tail + 1) % size] = key;
        else // sto inserendo in mezzo all' array
        {
            if(head < tail) // Array non wrappato
            {
                ulong headSize = i - head + 1;        
                ulong tailSize = tail - i;

                if((headSize) >= (tailSize))
                {
                    RightShift((i+1) % size, tailSize);
                    Elements[(i+1) % size] = key;
                }
                else
                {
                    head = (head == 0) ? size - 1 : head - 1;
                    LeftShift(i, headSize);
                    Elements[i] = key;
                }
            }
            else    // Array con wrap around
            {
                if(i<=tail) // i sta a sinistra
                {
                    ulong tailSize = tail - i;            // Elementi tra tail e i
                    ulong headSize = capacity - tailSize; // Elementi tra i e head
                   
                    if((tailSize) >= (headSize))
                    {
                        head = (head == 0) ? size - 1 : head - 1;
                        LeftShift(i, headSize);
                        Elements[i] = key;
                    }
                    else
                    {
                        RightShift((i+1) % size, tailSize);
                        Elements[(i+1) % size] = key;
                    }
                }
                else    // i sta a destra
                {
                    ulong headSize = i - head + 1;                   // Elementi tra head e i
                    ulong tailSize = capacity - headSize;            // Elementi a i e tail

                    if((headSize) >= (tailSize))
                    {
                        RightShift((i+1) % size, tailSize);
                        Elements[(i+1) % size] = key;
                    }
                    else
                    {
                        head = (head == 0) ? size - 1 : head - 1;
                        LeftShift(i, headSize);
                        Elements[i] = key;
                    }
                }
            }
        }
    }
    capacity++;
    return true;
}

template <typename Data>
bool SetVec<Data>::Insert(Data &&key) // Override DictionaryContainer member (move of the value)
{
    
}

template <typename Data>
bool SetVec<Data>::Remove(const Data &key) // Override DictionaryContainer member
{

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
    return (BSearchExists(key) != size);
}

/* ---------------------------SetVec: Specific member functions (inherited from ClearableContainer)------------------------- */

template <typename Data>
void SetVec<Data>::Clear()
{
    Vector<Data>::Clear();
    capacity = 0;
    head = 0;
}

/* ---------------------------SetVec: Protected auxilary functions (inherited from)------------------------- */

template<typename Data>
void SetVec<Data>::RightShift(ulong index, ulong to_shift)
{
   for(ulong i = to_shift ; i > 0; i--)
        Elements[(index + i) % size] = Elements[(index + i + 1) % size];
}

template<typename Data>
void SetVec<Data>::LeftShift(ulong index, ulong to_shift)
{
   for(ulong i = 0 ; i < to_shift; i++)
        Elements[(index + i + size - 1) % size] = Elements[(index + i) % size]; // CHECK
}

template <typename Data>
bool SetVec<Data>::IndexedRemove(ulong to_remove) // Quando ho già la posizione
{
    

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
    if(static_cast<double>(capacity / size) <= 0.25)
        Resize(size/2);
    else if(static_cast<double>(capacity / size) >= 0.9)
        Resize(size * 2);
}

// From ResizableContainer
template <typename Data>
void SetVec<Data>::Resize(ulong)
{
    

}


// Ricerche specializzate per evitare confronti di uguaglianza nelle funzioni 

template <typename Data>
ulong SetVec<Data>::BSearchExists(const Data &key) const // Cerca == Key
{
    
    
}

template<typename Data>
ulong SetVec<Data>::BSearchEqPred(const Data &key) const // Cerca <= key
{
    if (capacity == 0)
        return size;

    ulong left = 0;
    ulong right = (capacity) ? (capacity - 1) : 0;
    ulong result = size;

    while (left <= right)
    {
        ulong mid = left + (right - left) / 2;
        ulong mapped = (head + mid) % size;
        if (Elements[mapped] <= key)
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            if (mid == 0) break;
            right = mid - 1;
        }
    }

    if (result == size)
        return size;
    else
        return (head + result) % size;
}


template<typename Data>
ulong SetVec<Data>::BSearchPred(const Data &key) const
{
    if (capacity == 0)
        return capacity;

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
    if (capacity == 0)
        return capacity;

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



