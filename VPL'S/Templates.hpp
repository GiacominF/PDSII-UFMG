#ifndef VETOR_H
#define VETOR_H
#include <vector>
#include <algorithm>

template<typename T>
class Vetor {

public:
    Vetor(int n) : tamanho(n), vetor_int(n) {}

    Vetor(const std::vector<T>& vector) : tamanho(vector.size()), vetor_int(vector) {}

    ~Vetor() {
        vetor_int.clear();
    }

private:
    int tamanho;
    std::vector<T> vetor_int;
};
