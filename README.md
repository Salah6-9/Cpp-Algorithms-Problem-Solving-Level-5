<div align="center">

# 🚀 Algorithms & Problem Solving - Level 5
### Advanced Data Structures & Practical Implementations in C++

![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data%20Structures-From%20Scratch-blue?style=for-the-badge)
![OOP](https://img.shields.io/badge/OOP-Inheritance%20%26%20Templates-brightgreen?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

<p align="center">
  A comprehensive collection of fundamental and advanced data structures implemented completely from scratch using modern C++, generic programming (Templates), and object-oriented design patterns.
</p>

</div>

---

## 📌 Overview

This repository demonstrates the low-level implementation of core data structures and real-world simulation systems without relying on the C++ Standard Template Library (STL) containers. 

### Key Engineering Highlights:
- **Generic Programming (`template <class T>`)**: All data structures are fully templated to handle any primitive or user-defined data type.
- **Manual Memory Management**: Proper heap allocations (`new` / `delete[]`) with deep copy semantics, destructor cleanup, and leak prevention.
- **Design Patterns & OOP**: Applying composition, class inheritance, and adapter patterns (e.g., building Stacks and Queues by adapting underlying Linked Lists and Dynamic Arrays).
- **Real-World Applications**: Building practical systems such as an **Undo/Redo text buffer** and a **Bank/Service Queue Line ticketing system**.

---

## 📂 Projects & Data Structures Breakdown

```
.
├── Project1/   # Generic Doubly Linked List
├── Project2/   # Queue backed by Doubly Linked List
├── Project3/   # Stack backed by Doubly Linked List
├── Project4/   # Custom Dynamic Array (Vector-like)
├── Project5/   # Queue backed by Dynamic Array
├── Project6/   # Stack backed by Dynamic Array
├── Project7/   # String class with Undo / Redo history
└── Project8/   # Service Queue Line & Ticket Simulation System
```

---

### 🔹 Project 1: Doubly Linked List (`clsDblLinkedList<T>`)
A bidirectional linked list where each node contains pointers to both the next and previous nodes.
- **Key Operations**:
  - `InsertAtBeginning(T)`, `InsertAtEnd(T)`, `InsertAfter(Node*, T)`, `InsertAfterIndex(index, T)`
  - `DeleteFirstNode()`, `DeleteLastNode()`, `DeleteNode(Node*)`
  - `Find(T)`, `GetNode(index)`, `GetItem(index)`
  - `UpdateValue(index, T)`, `Reverse()`, `Clear()`, `size()`, `IsEmpty()`
- **Use Cases**: Fast insertions/deletions at both ends without memory reallocation.

---

### 🔹 Project 2: Queue using Linked List (`clsMyQueue<T>`)
A First-In-First-Out (**FIFO**) container implemented via composition using `clsDblLinkedList`.
- **Key Operations**:
  - `push(T)`: Enqueue element to the back.
  - `pop()`: Dequeue element from the front.
  - `front()` & `back()`: Access elements at boundaries.
  - `GetItem(index)`, `Reverse()`, `UpdateItem(index, T)`, `InsertAfter(index, T)`, `Clear()`

---

### 🔹 Project 3: Stack using Linked List (`clsMyStack<T>`)
A Last-In-First-Out (**LIFO**) container implemented by inheriting from `clsMyQueue` (Adapter Pattern).
- **Key Operations**:
  - `push(T)`: Insert element at the top.
  - `pop()`: Remove top element.
  - `Top()` & `Bottom()`: Peek at stack extremes.

---

### 🔹 Project 4: Custom Dynamic Array (`clsDynamicArray<T>`)
A growable array implementation managing continuous memory blocks on the heap.
- **Key Operations**:
  - `Resize(NewSize)`: Dynamically reallocates memory to fit changing sizes.
  - `InsertAt(index, T)`, `InsertAtBeginning(T)`, `InsertAtEnd(T)`, `InsertBefore(index, T)`, `InsertAfter(index, T)`
  - `DeleteAt(index)`, `DeletFirstItem()`, `DeletLastItem()`, `DeleteItem(value)`
  - `Find(value)`, `Reverse()`, `Clear()`, `UpdateItem(index, T)`
- **Trade-offs**: $O(1)$ random access by index vs. $O(n)$ overhead during memory expansion.

---

### 🔹 Project 5: Queue using Dynamic Array (`clsMyQueueArr<T>`)
FIFO Queue implemented using `clsDynamicArray` as the underlying storage.
- Demonstrates algorithmic differences in memory locality and cache performance compared to pointer-based linked list queues.

---

### 🔹 Project 6: Stack using Dynamic Array (`clsMyStackArr<T>`)
LIFO Stack implemented using `clsDynamicArray`.
- Efficient top-of-stack operations using array indexing.

---

### 🔹 Project 7: Custom String with Undo / Redo (`clsMyString`)
A practical application of the Stack data structure simulating text editor history.
- **Mechanism**:
  - Uses two separate `clsMyStack<string>` instances (`_Undo` and `_Redo`).
  - When changing string value, current state is pushed to `_Undo`.
  - `Undo()` reverts to previous state and stores current in `_Redo`.
  - `Redo()` reapplies reverted states.

---

### 🔹 Project 8: Queue Line System Simulation (`clsQueueLine`)
A comprehensive simulation of a service center / bank branch ticket management system.
- **Features**:
  - **Ticket Generation**: Automatic prefixing (e.g., `A001`), timestamping, waiting client counter.
  - **Wait Time Calculations**: Computes expected serving times based on average service duration.
  - **Visualizers**:
    - `PrintTicketsLineRTL()` & `PrintTicketsLineLTR()` displays the line flow.
    - `PrintInfo()` displays summary stats (Total Tickets, Served, Waiting).
    - `PrintAllTickets()` prints individual customer ticket details.
  - **Service Dispatch**: `ServeNextClient()` transitions clients from waiting to served queue.

---

## 📊 Comparison: Linked List vs. Dynamic Array

| Feature | Doubly Linked List (`Project 1`) | Dynamic Array (`Project 4`) |
| :--- | :--- | :--- |
| **Random Access** | $O(n)$ traversal | $O(1)$ constant time |
| **Insert / Delete at Ends** | $O(1)$ pointer update | $O(1)$ amortized (end), $O(n)$ (beginning) |
| **Memory Locality / Cache** | Scattered heap nodes | Contiguous memory (cache-friendly) |
| **Memory Overhead** | Extra 2 pointers per node (`Next`, `Prev`) | Buffer resizing overhead |

---

## 🛠️ How to Compile & Run

Make sure you have a C++ compiler supporting **C++17** or later (such as `g++` or `clang++`).

### Compiling Any Project:
```bash
# 1. Navigate to the project directory:
cd Project8

# 2. Compile with g++:
g++ -std=c++17 main.cpp -o main

# 3. Run the executable:
./main
```

---

## 💻 Tech Stack & Concepts

- **Language**: C++ (C++17)
- **Compiler**: GCC / G++ (Linux)
- **Concepts**:
  - Object-Oriented Programming (OOP)
  - Generic Programming & C++ Templates
  - Dynamic Memory & Pointer Arithmetic
  - Algorithm Analysis & Big-O Complexity
  - Abstract Data Types (ADT)

---

## 👤 Author

- **Salah**
- GitHub: [@Salah6-9](https://github.com/Salah6-9)
