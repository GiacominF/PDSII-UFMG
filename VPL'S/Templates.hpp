#ifndef VETOR_H
#define VETOR_H
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Vetor {
private:
    T* elementos;
    int tamanhoMaximo;
    int tamanhoAtual;

public:
    Vetor(int n) {
        tamanhoMaximo = n;
        tamanhoAtual = 0;
        elementos = new T[tamanhoMaximo];
    }

    Vetor(const Vetor& outro) {
        tamanhoMaximo = outro.tamanhoMaximo;
        tamanhoAtual = outro.tamanhoAtual;
        elementos = new T[tamanhoMaximo];
        for (int i = 0; i < tamanhoAtual; ++i) {
            elementos[i] = outro.elementos[i];
        }
    }

    ~Vetor() {
        delete[] elementos;
    }

    void SetElemento(int i, T x) {
        elementos[i] = x;
    }

    T GetElemento(int i) const {
        return elementos[i];
    }

    void AdicionaElemento(T x) {
        if (tamanhoAtual < tamanhoMaximo) {
            elementos[tamanhoAtual++] = x;
        } else {
            std::cerr << "Vetor cheio!" << std::endl;
        }
    }

    void Imprime() const {
        for (int i = 0; i < tamanhoAtual; ++i) {
            std::cout << elementos[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif