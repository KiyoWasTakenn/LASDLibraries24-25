
#ifndef PQHEAP_HPP
#define PQHEAP_HPP

/* ************************************************************************** */

#include "../pq.hpp"
#include "../../heap/vec/heapvec.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class PQHeap : virtual public PQ<Data>
               virtual protected HeapVec<Data> {
  // Must extend PQ<Data>,
  // Could extend HeapVec<Data>

private:

  // ...

protected:

  // using Container::???;

  // ...

public:

  // Default constructor
  // PQHeap() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  // PQHeap(argument) specifiers; // ! A priority queue obtained from a TraversableContainer PUNTO CHE SEMBRA UNA SCEMENZA MA è DELICATO, 
  // ! SI POTREBBE PENSARE DI CHIAMARE SEMPLICEMENTE IL COSTRUTTORE DI HEAPVEC, MA IL COSTRUTTORE DI HEAPVEC NON FA LE COSE PER BENE SE NON METTIAMO 
  // ! L'EREDITà IN MODO NON VIRTUALE IN HEAPVEC DA SORTABLEVECTOR<DATA>. NEL MOMENTO IN CUI è INCAPSULATO, PQHEAP QUANDO ANDRA AD ESTENDERE HEAPVEC 
  // ! AVRA ALL'INTERNO VECTOR. SE INVECE LO DICHIARIAMO VIRTUAL NON SARà HEAPVEC CHE SE NE ACCORGERà, NON CHIAMA I COSTRUTTORI. SE NON CHIAMASSI VIRTUALE DOVREI FARE A(CONT)B(CONT)

  // PQHeap(argument) specifiers; // A priority queue obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  // PQHeap(argument) specifiers;

  // Move constructor
  // PQHeap(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~PQHeap() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from PQ)

  // type Tip(argument) override; // Override PQ member (must throw std::length_error when empty)
  // type RemoveTip(argument) override; // Override PQ member (must throw std::length_error when empty)
  // type TipNRemove(argument) override; // Override PQ member (must throw std::length_error when empty)

  // type Insert(argument) override; // Override PQ member (Copy of the value)
  // type Insert(argument) override; // Override PQ member (Move of the value)

  // type Change(argument) override; // Override PQ member (Copy of the value)
  // type Change(argument) override; // Override PQ member (Move of the value)

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "pqheap.cpp"

#endif
