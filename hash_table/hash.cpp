/*********
 * Hash table
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

#include <iostream>
#include "hash.h"

using namespace std;

Hash::Hash(int max)
{
    length = 0;
    max_items = max;
    structure = new Aluno[max_items];    // dynamic allocation array
}

Hash::~Hash()
{
  delete [] structure;
}

bool Hash::isFull() const 
{
    return (length == max_items);
}

int Hash::getLength() const
{
    return length;
}

void Hash::retrieveItem(Aluno& aluno, bool& found)
{
    int startLoc = getHash(aluno);
    int location = startLoc;

    do {

        // found
        if (structure[location].getRa() == aluno.getRa() || structure[location].getRa() == -1)
            break;

        location = (location + 1) % max_items;

    } while (location != startLoc);     // while not returning to the starting position

    found = (structure[location].getRa() == aluno.getRa());

    if (found) aluno = structure[location];
}

void Hash::insertItem(Aluno aluno)
{
    int startLoc = getHash(aluno);
    int location = startLoc;

    while (structure[location].getRa() > 0) {
        location = (location + 1) % max_items;

        // returned to the starting position
        if (location == startLoc) throw "Hash table is already full!";
    }

    structure[location] = aluno;
    length++;
}

void Hash::deleteItem(Aluno aluno)
{
    int startLoc = getHash(aluno);
    int location = startLoc;

    do {

        // found
        if (structure[location].getRa() == aluno.getRa() || structure[location].getRa() == -1)
            break;

        location = (location + 1) % max_items;

    } while (location != startLoc);     // while not returning to the starting position

    if (structure[location].getRa() == aluno.getRa()) {
        structure[location] = Aluno(-2, "");
        length--;
    }
}

void Hash::print()
{
    for (int i = 0; i < max_items; i++) {
        cout << i << ":" << structure[i].getRa() 
                  << ", " << structure[i].getNome() << endl;
    }
}

int Hash::getHash(Aluno aluno) {
    return aluno.getRa() % max_items;
}

void Hash::updateItem(Aluno aluno, int novoRa, string novoNome)
{

    bool found = true;

/*
    // if not found, add it.
    // uncomment the lines below to change this.

    retrieveItem(aluno, found);
    if (!found) return;
*/

    if (found) deleteItem(aluno);
    Aluno aux = Aluno(novoRa, novoNome);
    insertItem(aux);

}
