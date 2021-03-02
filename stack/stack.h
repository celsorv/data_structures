/*********
 * Stack
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

#ifndef STACK_H      // Include this block only if STACK_H is not defined
#define STACK_H

#include "item_type.h"

const int MAX_ITEMS = 100;

class Stack 
{
private:
    int length;
    ItemType* structure;

public:
    
    Stack();            // constructor
    ~Stack();           // destructor

    bool isEmpty() const;
    bool isFull() const;
    void print() const;

    void push(ItemType);
    ItemType pop();

};
#endif  // end of " #ifndef "
