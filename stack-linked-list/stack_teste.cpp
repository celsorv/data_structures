/*********
 * Stack using linked list
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

#include "stack.h"
#include <iostream>
using namespace std;

int indexOf(char &, const char[], int);
bool inArray(char &, const char[], int);

int main()
{

    ItemType character;
    ItemType stackItem;
    Stack stack;

    // left... curly bracket, square bracket, round bracket and angle bracket
    const char leftBrackets[4]  = { '{', '[', '(', '<' };

    // right... curly bracket, square bracket, round bracket and angle bracket
    const char rightBrackets[4] = { '}', ']', ')', '>' };

    const int numberOfBrackets = 4;

    bool isMatched = true;

    cout << "\nInsira uma String." << endl;
    cout << "?: ";
    cin.get(character);

    while (isMatched && character != '\n')
    {

        if (inArray(character, leftBrackets, numberOfBrackets))  // is a left bracket
            stack.push(character);

        else
        {
            int index = indexOf(character, rightBrackets, numberOfBrackets);

            if (index != -1)  // is a right bracket
            {
                if (stack.isEmpty())    // started with the right bracket
                    isMatched = false;
                else
                {
                    stackItem = stack.pop();
                    isMatched = (stackItem == leftBrackets[index]);  // paired with last
                }
            }
        }

        cin.get(character);
    }

    if (isMatched && stack.isEmpty())
        cout << "Bem formada\n";
    else
        cout << "Mal formada\n";

}

bool inArray(char &character, const char brackets[], int sizeOfArray)
{
    return indexOf(character, brackets, sizeOfArray) != -1;
}

int indexOf(char &character, const char brackets[], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        if (character == brackets[i]) return i;
    }

    return -1;
}
