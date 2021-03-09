/*********
 * Stack using linked list
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

#include "stack.h"
#include <cstddef>  // to work NULL
#include <new>

#include <iostream>
using namespace std;

Stack::Stack()
{
    top = NULL;
}

Stack::~Stack()
{
    NodeType* tempPtr;
    while (top != NULL)
    {
        tempPtr = top;
        top = top -> next;
        delete tempPtr;
    }
}

bool Stack::isEmpty() const
{
    return (top == NULL);
}

bool Stack::isFull() const
{
    NodeType* location;
    try
    {
        location = new NodeType;    
        delete location;            // instantiated, memory is not full!
        return false;

    } catch (bad_alloc exception)   
    {                               // fail, memory is full!
        return true;
    }
}

void Stack::push(ItemType item)
{
    if (isFull())
    {
        throw "Stack is already full!";
    }

    NodeType* location;
    location = new NodeType;
    location->info = item;
    location->next = top;
    top = location;
}

ItemType Stack::pop()
{
    if (isEmpty())
    {
        throw "Stack is empty!";
    }

    NodeType* tempPtr;
    tempPtr = top;
    ItemType item = top->info;
    top = top->next;
    delete tempPtr;
    return item;
}

void Stack::print() const
{

    NodeType* tempPtr = top;
    while (tempPtr != NULL)
    {
        cout << tempPtr->info;
        tempPtr = tempPtr->next;
    }
    cout << endl;
}

