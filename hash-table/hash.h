/*********
 * Hash table
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

#ifndef HASH_H
#define HASH_H

#include "aluno.h"

#define SIZE_OF_ARRAY 100

class Hash
{
public:
    Hash(int max_items = SIZE_OF_ARRAY);
    ~Hash();

    bool isFull() const;
    int getLength() const;

    void retrieveItem(Aluno& aluno, bool& found);
    void insertItem(Aluno aluno);
    void deleteItem(Aluno aluno);
    void updateItem(Aluno aluno, int novoRa, std::string novoNome);
    void print();


private:
    int getHash(Aluno aluno);
    int max_items;
    int length;
    Aluno* structure;
};
#endif  // end of " #ifndef "
