/*********
 * Queue using linked list
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

#include "node_type.h"

class Queue
{
public:

    Queue();    // constructor
    ~Queue();   // destructor

    bool isEmpty() const;
    bool isFull() const;
    
    void print() const;

    void enqueue(ItemType);
    ItemType dequeue();

private:
    NodeType* front;
    NodeType* rear;

};
