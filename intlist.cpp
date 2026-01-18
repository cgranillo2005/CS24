// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    if (source.head == nullptr) {
        return;
    }
    head = new Node;
    head->info = source.head->info;
    head->next = nullptr;
    tail = head;

    Node* curr = source.head->next;

    while (curr != nullptr) {
        Node* newNode = new Node;
        newNode->info = curr->info;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = tail->next;
        curr = curr->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}


// return sum of values in list
int IntList::sum() const {
    Node* curr = head;
    int sum = 0;
    while (curr != nullptr) {
        sum += curr->info;
        curr = curr->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
   Node* curr = head;
   while (curr != nullptr) {
    if (curr->info == value) {return true;}
    curr = curr->next;
   }
   return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (head == nullptr) {return 0;}
    Node* curr = head;
    int maxVal = curr->info;
    while (curr != nullptr) {
        if (curr->info > maxVal) {maxVal = curr->info;}
        curr = curr->next;
    }
    return maxVal;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (head == nullptr) {return 0;}
    Node* curr = head;
    double avg = 0.0;
    int count = 0;
    while (curr != nullptr){
        avg += curr->info;
        count += 1;
        curr = curr->next;
    }
    avg = avg / count;

    return avg;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;
    Node* temp = head;
    head = newNode;
    head->next = temp;
    if (tail == nullptr) {
        tail = newNode;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    
}

// return count of values
int IntList::count() const {
   int count = 0;
   Node* curr = head;

   while (curr != nullptr) {
    count += 1;
    curr = curr->next;
   }
   return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) {return *this;}
    Node* temp = this->head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    this->head = nullptr;
    this->tail = nullptr;
    
    if (source.head == nullptr){
        return *this;
    }
    this->head = new Node;
    head->info = source.head->info;
    head->next = nullptr;
    tail = this->head;

    Node* curr = source.head->next;


    while (curr != nullptr){
        Node* newNode = new Node;
        newNode->info = curr->info;
        newNode->next = nullptr;

        tail->next = newNode;
        tail = tail->next;

        curr = curr->next;
    }
    return *this;
}


// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

