/*********
 * Stack
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack()  // constructor
{
    length = 0;
    structure = new ItemType[MAX_ITEMS];
}

Stack::~Stack() // destructor
{
    delete [] structure;
}

bool Stack::isEmpty() const
{
    return (length == 0);
}

bool Stack::isFull() const
{
    return (length == MAX_ITEMS);
}

void Stack::push(ItemType item)
{
    if (isFull()) throw "Stack is already full!";

    structure[length] = item;
    length++;
}

ItemType Stack::pop()
{
    if (isEmpty()) throw "Stack is empty!";

    ItemType aux = structure[length - 1];
    length--;

    return aux;
}

void Stack::print() const
{
    cout << "Pilha = ";
    for (int i = 0; i < length; i++)
    {
        cout << structure[i];
    }
    cout << endl;
}
