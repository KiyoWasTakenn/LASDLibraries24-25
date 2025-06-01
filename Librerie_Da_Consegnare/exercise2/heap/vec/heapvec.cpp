
namespace lasd {

/* ************************************************************************** */

/* ---------------------------HeapVec: Constructors/Destructors -------------------------- */

// A heap obtained from a TraversableContainer
template <typename Data>
HeapVec<Data>::HeapVec(const TraversableContainer<Data> &cont) : Vector<Data>::Vector(cont)
{
    Heapify();
}

// A heap obtained from a MappableContainer
template <typename Data>
HeapVec<Data>::HeapVec(MappableContainer<Data> &&cont) : Vector<Data>::Vector(std::move(cont))
{
    Heapify();
}

// Copy constructor
template <typename Data>
HeapVec<Data>::HeapVec(const HeapVec<Data> &hvec) : Vector<Data>::Vector(hvec) {}

// Move constructor
template <typename Data>
HeapVec<Data>::HeapVec(HeapVec<Data> &&hvec) noexcept : Vector<Data>::Vector(std::move(hvec)) {}

/* ---------------------------HeapVec: Assignments -------------------------- */

// Copy assignment
template <typename Data>
HeapVec<Data> & HeapVec<Data>::operator=(const HeapVec<Data> &hvec)
{
    SortableVector<Data>::operator=(hvec);

    return *this;
}

// Move assignment
template <typename Data>
HeapVec<Data> & HeapVec<Data>::operator=(HeapVec<Data> &&hvec) noexcept
{
    SortableVector<Data>::operator=(std::move(hvec));

    return *this;
}

/* ---------------------------HeapVec: Comparison Operators-------------------------- */

template <typename Data>
bool HeapVec<Data>::operator==(const HeapVec<Data> &hvec) const noexcept
{
    return SortableVector<Data>::operator==(hvec);
}

template <typename Data>
inline bool HeapVec<Data>::operator!=(const HeapVec<Data> &hvec) const noexcept
{
    return !((*this) == hvec);
}

/* ---------------------------HeapVec: Specific member functions (inherited from Heap)-------------------------- */

template <typename Data>
bool HeapVec<Data>::IsHeap() const noexcept
{
    if(size > 1)
        {
            for(ulong i = 0; i < size/2; i++)
            {
                ulong fsx = 2 * i + 1;
                ulong fdx = 2 * i + 2;

                if((*this)[fsx] > (*this)[i])
                    return false;
                
                if(fdx < size && (*this)[fdx] > (*this)[i])
                    return false;  
            }
        }
    return true; 
} 

template <typename Data>
void HeapVec<Data>::Heapify()
{
    for(ulong i = size/2; i>0; i--)
        HeapifyDown(size, i-1);
}

/* ---------------------------HeapVec: Specific member function (inherited from SortableLinearContainer)-------------------------- */

template <typename Data>
inline void HeapVec<Data>::Sort() noexcept
{
    HeapSort();
}

/* ---------------------------HeapVec: Auxilary functions -------------------------- */

template <typename Data>
void HeapVec<Data>::HeapifyDown(ulong length, ulong root)
{
    ulong max = root;

    ulong fsx = 2 * root + 1;
    ulong fdx = 2 * root + 2;

    if(fsx < length && (*this)[fsx] > (*this)[max] )
            max = fsx;

    if(fdx < length && (*this)[fdx] > (*this)[max] )
            max = fdx;

    if(root != max)
        {
            std::swap((*this)[root], (*this)[max]);
            HeapifyDown(length, max);
        }
}

template <typename Data>
void HeapVec<Data>::HeapSort()
{
    if(size > 1)
    {
        Heapify();

        for(ulong i = size - 1; i>=1; i--)
            {
                std::swap((*this)[0], (*this)[i]);
                HeapifyDown(i, 0);
            }
    }
}

/* ************************************************************************** */

}