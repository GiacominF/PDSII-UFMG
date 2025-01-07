#ifndef VETOR_H
#define VETOR_H
#include <vector>
#include <algorithm>

template<typename T>
class Vetor {

public:
    Vetor(int n) : tamanho(n), vetor_int(n) {}

    Vetor(const std::vector<T>& vector) : tamanho(vector.size()), vetor_int(vector) {}

    void SetElemento(int i, T elemento) {
        vetor_int.at(i) = elemento;
    }

    T GetElemento(int i) const {
        return vetor_int.at(i);
    }

    void AdicionaElemento(T n) {
        vetor_int.push_back(n);
        tamanho++;
    }

    void ImprimeElementos() {
        for (const auto& i : vetor_int) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }

    ~Vetor() {
        vetor_int.clear();
    }

private:
    int tamanho;
    std::vector<T> vetor_int;
};
