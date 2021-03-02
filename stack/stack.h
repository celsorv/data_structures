/*********
 * Stack
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

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
