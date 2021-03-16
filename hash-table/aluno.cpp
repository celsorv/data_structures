/*********
 * Hash table
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

#include <string>
#include "aluno.h"

using namespace std;

Aluno::Aluno()
{
    this->ra = -1;
    this->nome = "";
}

Aluno::Aluno(int ra, string nome)
{
    this->ra = ra;
    this->nome = nome;
}

string Aluno::getNome() const
{
    return nome;
}

int Aluno::getRa() const
{
    return ra;
}
