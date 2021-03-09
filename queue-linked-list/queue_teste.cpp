/*********
 * Queeue and Stack using linked list
 *        Checks if word is a palindrome
 *
 * -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
 * Palindrome examples
 *        Portughese: arara, osso, ovo, oco, ele, radar
 *        English   : civic, level, solos, kayak, stats
 * -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 *
 */

#include <iostream>
#include "queue.h"
#include "stack.h"

using namespace std;

int main()
{

    bool palindrome = true;

    char character;
    char stackChar;
    char queueChar;

    Stack stack;
    Queue queue;

    cout << "\nAdd a String" << endl;
    cout << "?: ";
    cin.get(character);

    while (character != '\n') {
        stack.push(character);
        queue.enqueue(character);
        cin.get(character);
    }

    while (palindrome && !queue.isEmpty()) {
        stackChar = stack.pop();
        queueChar = queue.dequeue();

        if (stackChar != queueChar)
            palindrome = false;
    }

    if (palindrome)
        cout << "\nString is a palindrome!" << endl;
    else
        cout << "\nString is not a palindrome!" << endl;

    cout << endl << endl;

}
