
#ifndef HEAPVEC_HPP
#define HEAPVEC_HPP

/* ************************************************************************** */

#include "../heap.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HeapVec {
  // Must extend Heap<Data>,
  // Could extend SortableVector<Data>

private:

  // ...

protected:

  // using Container::???;

  // ...

public:

  // Default constructor
  HeapVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  // ! HeapVec(argument) specifiers; // A heap obtained from a TraversableContainer COSTRUTTORE SPECIFICO DELLA SOVRACLASSE sortable E POI NEL CORPO CI VUOLE LA CHIAMATA A HEAPIFY(BUILDHEAP)
  // ! HeapVec(argument) specifiers; // A heap obtained from a MappableContainer same as sopra 

  /* ************************************************************************ */

  // Copy constructor
  // HeapVec(argument) specifiers;

  // Move constructor
  // HeapVec(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  ~HeapVec() = default;

  /* ************************************************************************ */

  // Copy assignment 
  // ! type operator=(argument) specifiers; CHIAMARE SOLO QUELLO CHE FA LE COSE PER BENE PERCHè STO COPIANDO GIA DA UNO HEAP NON SERVE SORTARE DEVO RICHIAMARLO DENTRO QUELLO DI SORTABLE VECTOR

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; COME LAVORAVANO PER IL VETTORE 
  // type operator!=(argument) specifiers; IDEM

  /* ************************************************************************ */

  // Specific member functions (inherited from Heap)

  // ! type IsHeap(argument) specifiers; // Override Heap member CICLO CON LA FUNZIONE AUSILIARIA CHE TESTA SE TRA I TRE INDICI IL MASSIMO STA IN HTESTA

  // ! type Heapify(argument) specifiers; // Override Heap member CHIAMERA FOR DALL ULTIMO PADRE A 0 E CHIAMIAMO HEAPIFY PROTECTED HA UNA SIZE INTEGRATA non so se questa o l'altra

  /* ************************************************************************ */

  // Specific member function (inherited from SortableLinearContainer)

  // ! type Sort(argument) specifiers; // Override SortableLinearContainer member HEAPSORT 

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "heapvec.cpp"

#endif
