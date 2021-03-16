/*********
 * Hash table
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno
{
public:
    Aluno();
    Aluno(int ra, std::string nome);

    std::string getNome() const;
    int getRa() const;

private:
    int ra;
    std::string nome;
};
#endif  // end of " #ifndef "
