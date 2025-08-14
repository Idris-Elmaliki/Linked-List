#include <iostream>

template<class T>
class Node {
public: // everything must be public
    T value; 
    Node* next; 

    // Node constructor
    Node(const T &value)
    : value(value) {
        next = nullptr;
    }
}; 

// class that creates the methods to create a linked list
template<class T>
class LinkedList {
    Node<T> *head, *tail; 
    int length;

public: 
    // constructor that creates the first node
    LinkedList(const T &value) { 
        Node* newNode = new Node(value); 
        head = newNode; 
        tail = newNode;  
        length = 1; 
    }

    // inserts a new value for tail
    void append(const T &value) { 
        Node* newNode = new Node(value); 
        
        tail->next = newNode; 
        tail = newNode; 
        length++; 
    }
    
    // inserts a new value for head
    void prepend(const T &value) { 
        Node* newNode = new Node(value);

        if(length == 0) {
            head = newNode;
            tail = newNode;  
        }
        else {
            newNode->next = head; 
            head = newNode; 
        }
        ++length; 
    }
    
    // deletes head and moves head to the next index
    void deleteFirst() { 
        if(length == 0) {
            std::cout << "Everything has already been removed!\n"; 
            return; 
        }
        else if(length == 1) {
            head = nullptr; 
            tail = nullptr; 
            std::cout << "Everything is deleted!\n";
        }
        else {
            Node *temp = head->next; 

            head = nullptr; 
            head = temp; 
        }
        --length;
    }
    
    // deletes tail and moves tail to the previous index   
    void deleteLast() { 
        if(length == 0) 
            return; 
        else if(length == 1) {
            head = nullptr; 
            tail = nullptr; 
        }
        else {
            Node *temp = head, *previous_temp; 
            
            while(temp->next) {
                previous_temp = temp; 
                temp = temp->next; 
            }
            tail = previous_temp; 
            tail->next = nullptr; 
        }
         delete temp; 
        --length; 
    }
    
    // prints the entire linked list
    void printLL() { 
        Node* temp = head; 

        while(temp != nullptr)  {
            std::cout << temp->value << ' '; 
            temp = temp->next;
        }
    
        std::cout << '\n'; 
    }
    
    // returns a node's address at a specific index 
    Node* getNode(const int &index) { 
        Node* temp = head;

        if(index < 0 || index >= length) {
            std::cout << "Invalid index, returning to the closes index: "; 
            
            // sends either the address for head or tails depending on where the out of bound index is 
            if(index < 0)
                return head;
            else 
                return tail;  
        }
        else     
            for(int i = 0; i < index; i++) 
                temp = temp->next; 

        return temp; 
    }
    
    // can replace a node's value at any and returns true if the operation went through
    bool setNode(const int &index, const T &value) { 
        if(index < 0 || index >= length) {
            std::cout << "Invalid index!\n"; 
            return false; 
        }
        
        Node* temp = getNode(index);
        
        if(temp != nullptr) {
            temp->value = value; 
            return true; 
        } 
        return false; 
    }
    
    // creates a new node at a set index and returns true if the operation was possible
    bool insertNode(const int &index, const T &value) { 
        if(index < 0 || index > length) {
            std::cout << "Invalid index!\n"; 
            return false; 
        }

        if(index == 0) {
            prepend(value); 
        }
        else if(index == length) {
            append(value); 
        }
        else {
            Node *temp = getNode(index - 1);
            Node *newNode = new Node(value); 

            newNode->next = temp->next; 
            temp->next = newNode; 
        }
        ++length; 
        return true; 
    }
    
    // deletes a node at any specific index
    void deleteNode(const int &index) {
        if(index < 0 || index >= length) {
            std::cout << "Invalid index!"; 
            return; 
        }

        if(index == 0) {
            return deleteFirst();  
        }
        else if(index == (length-1)) {
            return deleteLast(); 
        }
        else {
            Node* temp = getNode(index); 
            Node* previous_temp = getNode(index-1); 

            previous_temp->next = temp->next; 
        }
         delete temp; 
        --length; 
    }

    // completely reverses the linked list, it's similar to a swap function in 
    void reverse_LinkedList() {
        Node* temp = head; 
        head = tail; 
        tail = temp; 

        Node *before = nullptr, *after = temp->next; 
        while(temp) {
            after = temp->next; 
            temp->next = before; 
            
            before = temp; 
            temp = after; 
        }
    }

    // destructor where we manually delete every Node (for memory allocation purpose)! 
    ~LinkedList() {
        Node* temp = head; 

        while(head != nullptr) {
            head = temp->next; 
            delete temp; 
            temp = head; 
        }
    }

}; 
