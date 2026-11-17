# CMPSC 272: Circular Templated Linked List Lab

**Author:** Henoc Kabeya  
**Course:** CMPSC 272  
**Date:** November 2026  

---

## Project Overview: The Universal Playlist Manager

This project is a C++ command-line application implementing a **Universal Media Player Playlist** manager. It combines **C++ Class Templates** with **Object-Oriented Polymorphism**—using an abstract base class (`Media`) and derived classes (`Song`, `Podcast`)—so that multiple media types can coexist inside a single, generic, circular linked list.

The starter non-circular, hard-coded singly linked list has been refactored into a **Circular Templated Linked List** (`LinkedList<T>`) capable of continuous wrap-around playback and automatic dynamic memory cleanup.

---

## Project Architecture

| Component | Files | Role & Implementation Details |
| :--- | :--- | :--- |
| **Base Class (Polymorphism)** | `Media.h`, `Media.cpp` | Defines the abstract interface (`play()`, `toString()`), virtual destructor, and shared attributes (`title`, `durationSeconds`). |
| **Derived Classes** | `Song.h/cpp`, `Podcast.h/cpp` | Inherit from `Media` and override `play()` and `toString()` with media-specific formatting and member initialization. |
| **Templated Circular List** | `LinkedList.h` *(and `LinkedList.cpp`)* | Defines the generic `Node<T>` struct and `LinkedList<T>` class template with `head`, `tail`, and `current` pointers, wrap-around traversal, `playNext()`, and RAII destructor cleanup. |
| **Client Driver** | `main.cpp` | Instantiates `LinkedList<Song*>` and `LinkedList<Media*>`, inserts dynamic media items, tests circular `playNext()` wrap-around, and verifies memory cleanup. |

---

## Phase 1: Templatization

The hard-coded `Node` and `LinkedList` structures were converted into generic C++ class templates so the list can manage any pointer type (`Song*`, `Media*`, etc.):

1. **Templated `Node<T>` Structure (`LinkedList.h`):** Added `template <typename T>` to `struct Node` and replaced the hard-coded `Media*` data member with the generic type `T` (instantiated with pointer types such as `Song*` or `Media*`) and `Node<T>* next`.
2. **Templated `LinkedList<T>` Class (`LinkedList.h`):** Added `template <typename T>` to `LinkedList` and updated `head`, `tail`, and `current` to `Node<T>*`.
3. **Header-Based Template Definitions:** Moved all templated method definitions (`insert()`, `displayList()`, `playCurrent()`, `playNext()`, and `~LinkedList()`) into `LinkedList.h` so the compiler can instantiate them at compile time.

---

## Phase 2: Circular Linked List Mechanics

The list was converted from a `nullptr`-terminated linear chain into a continuous circular structure:

1. **`tail` and `current` Pointers:** Added `Node<T>* tail` to track the end of the list for $O(1)$ circular insertion and `Node<T>* current` to track the active media item during playback.
2. **Circular Insertion (`insert()`):**
   * When the list is empty (`head == nullptr`), `head`, `tail`, and `current` all point to `newNode`, and `newNode->next` points back to `head`.
   * For subsequent insertions, `tail->next` links to `newNode`, `tail` advances to `newNode`, and `tail->next` wraps back to `head`.
3. **Wrap-Around Traversal (`displayList()`):** Uses a `do { ... } while (temp != head);` loop so traversal starts at `head` and terminates cleanly upon completing one full cycle back to `head`.
4. **Continuous Playback (`playCurrent()` & `playNext()`):** `playCurrent()` plays the active item without advancing, while `playNext()` advances `current = current->next` (wrapping seamlessly from `tail` back to `head`) and invokes virtual `play()`.
5. **Safe Circular Cleanup (`~LinkedList()`):** Breaks the circular link (`tail->next = nullptr`) before traversing and deleting each dynamically allocated media object (`delete temp->data`) and node (`delete temp`), preventing infinite loops and memory leaks.

---

## Compilation & Execution

### Using `g++`:
```bash
g++ -std=c++11 main.cpp Media.cpp Song.cpp Podcast.cpp LinkedList.cpp -o CircularPlaylist
./CircularPlaylist
