#include <aluno.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

Aluno::Aluno(const std::string& nome, int matricula, const std::vector<int>& notas)
    : nome(nome), matricula(matricula), notas(notas) {}


double Aluno::calcular_media() const {

    double soma = 0.0;
    for (const int& nota : notas) {
         soma += nota;
    }

    double media = soma/=notas.size();
    return media;
}


std::pair<int,int> Aluno::nota_max_min() const {

    int max = *std::max_element(notas.begin(), notas.end());
    int min = *std::min_element(notas.begin(), notas.end());

return {max, min};
}

