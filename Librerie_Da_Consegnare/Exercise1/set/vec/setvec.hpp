
#ifndef SETVEC_HPP
#define SETVEC_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetVec : virtual public Set<Data>,
               virtual protected Vector<Data>,
               virtual protected ResizableContainer
               {
  // Must extend Set<Data>,
  //             ResizableContainer

private:

  // ...

protected:

  using Container::size;
  using Vector<Data>::Elements; // ATTENTOOOOOOOOOOOOOOOOOOO

  ulong head = 0;
  ulong capacity = 0;


public:

  // Default constructor
  SetVec() : SetVec(2); // ATTENTOOOOOOOOOOOOOOOOOOO

  /* ************************************************************************ */

  // Specific constructors
  SetVec(const TraversableContainer<Data> &); // A set obtained from a TraversableContainer
  SetVec(MappableContainer<Data> &&) noexcept; // A set obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  SetVec(const SetVec &);

  // Move constructor
  SetVec(SetVec &&) noexcept;


  /* ************************************************************************ */

  // Destructor
  virtual ~SetVec() = default; // ATTENTOOOOOOOOOOOOOOOOOOO

  /* ************************************************************************ */

  // Copy assignment
  SetVec & operator=(const SetVec &);

  // Move assignment
  SetVec & operator=(SetVec &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const SetVec &) const noexcept;
  inline bool operator!=(const SetVec &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from OrderedDictionaryContainer)

  const Data & Min() const override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  Data MinNRemove() override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  void RemoveMin() override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  const Data & Max() const override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  Data MaxNRemove() override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  void RemoveMax() override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  const Data & Predecessor(const Data &) const override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(const Data &) override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  void RemovePredecessor(const Data &) override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  const Data & Successor(const Data &) const override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(const Data &) override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(const Data &) override; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data &) override; // Override DictionaryContainer member (copy of the value)
  bool Insert(Data &&) override; // Override DictionaryContainer member (move of the value)
  bool Remove(const Data &) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data & operator[](const ulong) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************** */

  // Specific member function (inherited from TestableContainer)

  bool Exists(const Data &) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:
  
  SetVec(ulong);

  void RightShift(ulong, ulong);

  void LeftShift(ulong, ulong);

  bool IndexedRemove(ulong);

  void checkResize();

  void Resize(ulong) override; 

  ulong BSearchExists(const Data &) const;  
  ulong BSearchEqPred(const Data &) const; // Per Insert
  ulong BSearchPred(const Data &) const;
  ulong BSearchSucc(const Data &) const;

};

/* ************************************************************************** */

}

#include "setvec.cpp"

#endif
