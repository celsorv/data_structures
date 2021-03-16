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

int main()
{
    Hash alunoHash(10);
    int ras[8]       = {12704, 31300, 1234, 49001, 52202, 65606, 91234, 22884};
    string nomes[8] = {"Pedro", "Raul", "Paulo", "Carlos", "Lucas", "Maria", "Samanta", "Paty"};

    for (int i = 0; i < 8; i++) {
        Aluno aluno = Aluno(ras[i], nomes[i]);
        alunoHash.insertItem(aluno);
    }

    bool found;
    Aluno busca = Aluno(22884, "");
    alunoHash.retrieveItem(busca, found);

    Aluno aluno = Aluno(ras[1], "");
    alunoHash.updateItem(aluno, ras[1], "RAUL");


    cout << endl << endl;
    cout << "############################################" << endl;
    cout << "---->> found: " << (found != 0 ? "true" : "false") << " => " << busca.getNome() << endl;
    cout << "############################################" << endl;
    cout << endl << endl;

    alunoHash.print();
    cout << "----------------------------------" << endl << endl;

}
