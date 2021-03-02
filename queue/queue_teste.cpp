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

int main()
{
    ItemType character;
    ItemType queueItem;
    Queue queue;

    cout << "\nAdicione uma String" << endl;
    cout << "?: ";
    cin.get(character);
    
    while (character != '\n' && !queue.isFull())
    {
        queue.enqueue(character);
        cin.get(character);
    }

    cout << "R: ";

    while (!queue.isEmpty())
    {
        queueItem = queue.dequeue();
        cout << queueItem;
    }

    cout << endl << endl;

}
