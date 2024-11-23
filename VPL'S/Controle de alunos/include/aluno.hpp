#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>

class Aluno {
public:

    Aluno(const std::string& nome, int matricula ,const std::vector<int>& notas);

    double calcular_media () const;
    std::pair<int,int> nota_max_min () const;

private:
    std::string nome;
    int matricula;
    std::vector<int> notas;

};

#endif
