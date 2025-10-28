# LASD Libraries 24-25

Implementazioni C++ delle librerie di strutture dati per il corso di **Laboratorio di Algoritmi e Strutture Dati (LASD)** - Anno Accademico 2024/2025.

Questo repository contiene le soluzioni per gli esercizi 1 e 2, proposti come prove intermedie del corso.

---

## 📚 Strutture Dati Implementate

Questo progetto include implementazioni personalizzate delle seguenti strutture dati fondamentali in C++:

### Esercizio 1:
* **Contenitori di Base:**
    * `Container`, `ClearableContainer`, `ResizableContainer`
    * `TestableContainer`, `TraversableContainer`, `MappableContainer` (con relative varianti PreOrder/PostOrder)
    * `DictionaryContainer`, `OrderedDictionaryContainer`
    * `LinearContainer`, `MutableLinearContainer`, `SortableLinearContainer`
* **Strutture Lineari:**
    * `Vector` / `SortableVector`: Implementazione di un vettore ridimensionabile e ordinabile.
    * `List`: Implementazione di una lista concatenata.
* **Insiemi Ordinati:**
    * `SetVec`: Implementazione di un insieme ordinato basato su `Vector`.
    * `SetLst`: Implementazione di un insieme ordinato basato su `List`.

### Esercizio 2 (Aggiunte):
* **Heap:**
    * `Heap`: Interfaccia per Heap.
    * `HeapVec`: Implementazione di un Heap basato su `SortableVector`.
* **Priority Queue (Coda di Priorità):**
    * `PQ`: Interfaccia per Priority Queue.
    * `PQHeap`: Implementazione di una Priority Queue basata su `HeapVec`.

---

## 📁 Struttura del Progetto

Il codice è organizzato nelle seguenti directory principali:

* `Librerie_Da_Consegnare/Exercise1/`: Contiene le implementazioni relative all'Esercizio 1.
    * `container/`: Interfacce e implementazioni di base dei contenitori.
    * `vector/`: Implementazione di `Vector` e `SortableVector`.
    * `list/`: Implementazione di `List`.
    * `set/`: Implementazioni di `SetVec` e `SetLst`.
    * `zlasdtest/`: Suite di test fornita dal corso per l'Esercizio 1.
    * `zmytest/`: Suite di test personalizzata per l'Esercizio 1.
* `Librerie_Da_Consegnare/exercise2/`: Contiene le implementazioni relative all'Esercizio 2 (che includono ed estendono quelle dell'Esercizio 1).
    * Include le stesse directory dell'Esercizio 1, aggiornate.
    * `heap/`: Aggiunge l'implementazione di `HeapVec`.
    * `pq/`: Aggiunge l'implementazione di `PQHeap`.
    * `zlasdtest/`: Suite di test fornita dal corso per l'Esercizio 2.
    * `zmytest/`: Suite di test personalizzata per l'Esercizio 2.

---

## ⚙️ Compilazione ed Esecuzione

Per compilare ed eseguire il progetto, utilizzare il `makefile` fornito all'interno della directory `Librerie_Da_Consegnare/exercise2/` (o `Exercise1/` per il solo Esercizio 1).

1.  **Navigare nella directory:**
    ```bash
    cd Librerie_Da_Consegnare/exercise2/
    ```
2.  **Compilare:**
    ```bash
    make
    ```
    Questo comando userà `g++` con flag specifici (`-Wall -pedantic -O3 -std=c++20 -fsanitize=address`) per creare l'eseguibile `main`.
3.  **Pulire i file compilati (opzionale):**
    ```bash
    make clean
    ```
4.  **Eseguire:**
    ```bash
    ./main
    ```
    L'eseguibile `main` permette di scegliere quale suite di test eseguire:
    * `0`: Esegue la suite di test fornita (`lasdtest`).
    * `1`: Esegue la suite di test personalizzata (`mytest`).
    * Qualsiasi altro numero per uscire.

---

## ✅ Testing

Il progetto include due suite di test:

1.  **`zlasdtest`**: La suite di test ufficiale fornita per il corso LASD.
2.  **`zmytest`**: Una suite di test personalizzata per verificare ulteriormente la correttezza delle implementazioni.

È possibile scegliere quale suite eseguire tramite l'interfaccia da riga di comando fornita da `main.cpp`.
