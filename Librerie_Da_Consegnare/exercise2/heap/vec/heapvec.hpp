
#ifndef HEAPVEC_HPP
#define HEAPVEC_HPP

/* ************************************************************************** */

#include "../heap.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HeapVec : virtual public Heap<Data>,
                virtual protected SortableVector<Data>{
  // Must extend Heap<Data>,
  // Could extend SortableVector<Data>

private:


protected:

  using Container::size;
  using SortableVector<Data>::Elements;

  using SortableVector<Data>::Front;
  using SortableVector<Data>::Back;
  using SortableVector<Data>::operator[];

public:

  // Default constructor
  HeapVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  HeapVec(const TraversableContainer<Data> &); //! A heap obtained from a TraversableContainer COSTRUTTORE SPECIFICO DELLA SOVRACLASSE sortable E POI NEL CORPO CI VUOLE LA CHIAMATA A HEAPIFY(BUILDHEAP)
  HeapVec(MappableContainer<Data> &&); // A heap obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HeapVec(const HeapVec &);

  // Move constructor
  HeapVec(HeapVec &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~HeapVec() = default;

  /* ************************************************************************ */

  // Copy assignment 
  HeapVec & operator=(const HeapVec &); //!CHIAMARE SOLO QUELLO CHE FA LE COSE PER BENE PERCHè STO COPIANDO GIA DA UNO HEAP NON SERVE SORTARE DEVO RICHIAMARLO DENTRO QUELLO DI SORTABLE VECTOR

  // Move assignment
  HeapVec & operator=(HeapVec &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HeapVec &) const noexcept; // ! COME LAVORAVANO PER IL VETTORE 
  inline bool operator!=(const HeapVec &) const noexcept; //! IDEM

  /* ************************************************************************ */

  // Specific member functions (inherited from Heap)

  bool IsHeap() const noexcept override; //! Override Heap member CICLO CON LA FUNZIONE AUSILIARIA CHE TESTA SE TRA I TRE INDICI IL MASSIMO STA IN HTESTA

  void Heapify() override; //! Override Heap member CHIAMERA FOR DALL ULTIMO PADRE A 0 E CHIAMIAMO HEAPIFY PROTECTED HA UNA SIZE INTEGRATA non so se questa o l'altra

  /* ************************************************************************ */

  // Specific member function (inherited from SortableLinearContainer)

  inline void Sort() noexcept override; // Override SortableLinearContainer member

protected:
  
  HeapVec(const ulong);
  void Heapify(ulong, ulong);
  void HeapSort();
  
};

/* ************************************************************************** */

}

#include "heapvec.cpp"

#endif
