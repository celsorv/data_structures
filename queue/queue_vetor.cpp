/*********
 * Queue using a circular array
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue()      // constructor
{
    front = 0;
    back = 0;
    structure = new ItemType[MAX_ITEMS];
}

Queue::~Queue()    // destructor
{
    delete [] structure;
}

bool Queue::isEmpty() const
{
    return (front == back);
}

bool Queue::isFull() const
{
    return (back - front == MAX_ITEMS);
}

void Queue::enqueue(ItemType item)
{
    if (isFull()) throw "Queue is already full!";

    structure[back % MAX_ITEMS] = item;
    back++;
}

ItemType Queue::dequeue()
{
    if (isEmpty()) throw "Queue is empty!";

    front++;
    return structure[(front - 1) % MAX_ITEMS];
}

void Queue::print() const
{
    cout << "Fila = ";
    for (int i = front; i < back; i++)
    {
        cout << structure[i % MAX_ITEMS];
    }
    cout << endl;
}

 
 /*

    Example: MAX_ITEM = 5 (constant)

               0 1 2        <<--- back % MAX_ITEM
     0 1 2 3 4 5 6 7        <<--- back (variable)
    +-+-+-+-+-+
    |a|b|c|d|e|F G H
    +-+-+-+-+-+

               0 1 2 3 4    <<--- back % MAX_ITEM
              +-+-+-+-+-+
              |F|b|c|d|e|
              +-+-+-+-+-+
              |F|G|c|d|e|
              +-+-+-+-+-+
              |F|G|H|d|e|
              +-+-+-+-+-+
                     ^
                     |
                     +--------- front = 3 (variable)

 */
