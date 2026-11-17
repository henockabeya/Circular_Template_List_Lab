//
// Created by Henoc Kabeya on 11/14/26.
//

#ifndef CIRCULAR_TEMPLATE_LIST_LAB_LINKEDLIST_H
#define CIRCULAR_TEMPLATE_LIST_LAB_LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {

    // Data is now hard-coded to the BASE CLASS pointer: Media*
    T data;
    Node<T>* next;

    // Constructor initializes data and pointer
    Node(T item) : data(item), next(nullptr) {}
};

// Templated Circular Singly Linked List
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current;

public:
    // Constructor: Initializes an empty circular list
    LinkedList(): head(nullptr), tail(nullptr), current(nullptr) {}
    // Destructor: Cleans up all nodes and the objects they point to in a circular structure
    ~LinkedList() {
        if (head == nullptr) {
            cout << "n/[Playlist cleanup complete. List was already empty.]" << endl;
            return;
        }

        // Break the circular link so traversal stops cleanly at nullptr
        tail->next = nullptr;

        Node<T>* temp = head;
        Node<T>* next_node = nullptr;
        while (temp != nullptr) {
            next_node = temp->next;

            // Delete the dynamically allocated object
            delete temp->data;

            // Delete the node container itself
            delete temp;
        }
    }


    // Insertion: Adds a new Media pointer to the end of the list.
    void insert(T newItem) {
        Node<T>* newNode = new Node<T>(newItem);

        if (head == nullptr) {
            // Case 1: List is empty. New node becomes the head.
            head = newNode;
            tail = newNode;
            newNode->next = head;
            current = head;
        } else {
            // Case 2: Traverse to the end and link the new node.
            tail -> next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    // Traversal: Displays all media items in the list.
    void displayList() const {
        if (head == nullptr) {
            cout << "\n[Playlist is empty.]" <<endl;
            return;
        }

        cout << "\n--- Current Playlist ---" << endl;
        Node<T>* temp = head;
        int index = 1;
        do {
            cout << index++ << ". " <<temp->data->toString() << endl;
            temp = temp->next;
        } while (temp != head);
        cout << "------------------------" << endl;
    }

    // Plays the current item without advancing
    void playCurrent() const {
        if (current != nullptr) {
            current->data->play();
        } else {
            std::cout << "[Playlist is empty. Nothing to play.]" << std::endl;
        }
    }

    // Advances the current pointer one step (wrapping around at the tail) and plays it
    void playNext() {
        if (head == nullptr) {
            std::cout << "[Playlist is empty. Nothing to play.]" << std::endl;
            return;
        }

        if (current == nullptr) {
            current = head;
        } else {
            current = current->next; // Wraps from tail back to head automatically
        }
        current->data->play();
    }
};
#endif //CIRCULAR_TEMPLATE_LIST_LAB_LINKEDLIST_H
