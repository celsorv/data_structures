/*********
 * Stack using linked list
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

#include "node_type.h"

class Stack
{
public:

    Stack();    // constructor
    ~Stack();   // destructor

    bool isEmpty() const;
    bool isFull() const;
    
    void print() const;

    void push(ItemType);
    ItemType pop();

private:
    NodeType* top;

};
