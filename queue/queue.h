/*********
 * Queue using a circular array
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

#ifndef QUEUE_H      // Include this block only if QUEUE_H is not defined
#define QUEUE_H

#include "item_type.h"

const int MAX_ITEMS = 100;

class Queue 
{
private:
    int front;
    int back;
    ItemType* structure;

public:
    
    Queue();            // constructor
    ~Queue();           // destructor

    bool isEmpty() const;
    bool isFull() const;
    void print() const;

    void enqueue(ItemType);
    ItemType dequeue();

};
#endif  // end of " #ifndef "
