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

int main()
{
    ItemType character;
    ItemType stackItem;
    Stack stack;

    cout << "\nAdicione uma String." << endl;
    cout << "?: ";
    cin.get(character);

    while (character != '\n')
    {
        stack.push(character);
        cin.get(character);
    }

    cout << "R: ";

    while (!stack.isEmpty())
    {
        stackItem = stack.pop();
        cout << stackItem;
    }

    cout << endl << endl;

}