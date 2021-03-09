/*********
 * Queue using linked list
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

#include "queue.h"
#include <cstddef>  // to work NULL
#include <new>

#include <iostream>
using namespace std;

Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

Queue::~Queue()
{
    NodeType* tempPtr;
    while (front != NULL) {
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    rear = NULL;
}

bool Queue::isEmpty() const
{
    return (front == NULL);
}

bool Queue::isFull() const
{
    NodeType* location;
    try {
        location = new NodeType;    
        delete location;             // instantiated, memory is not full!
        return false;
    
    } catch (bad_alloc exception) {  // fail, memory is full!
        return true;
    
    }
}

void Queue::enqueue(ItemType newItem)
{
    if (isFull()) {
        throw "Queue is already full!";
    }

    NodeType* newNode;
    newNode = new NodeType;
    newNode->info = newItem;
    newNode->next = NULL;

    if (rear != NULL)
        rear->next = newNode;
    else
        front = newNode;

    rear = newNode;    
}

ItemType Queue::dequeue()
{
    if (isEmpty()) {
        throw "Queue is empty!";
    }

    NodeType* tempPtr;
    tempPtr = front;
    ItemType item = front->info;
    front = front->next;
    delete tempPtr;

    if (front == NULL)
        rear = NULL;

    return item;
}

void Queue::print() const
{
    NodeType* tempPtr = front;
    while (tempPtr != NULL) {
        cout << tempPtr->info;
        tempPtr = tempPtr->next;
    }
    cout << endl;
}
