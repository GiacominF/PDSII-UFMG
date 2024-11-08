#ifndef EMPRESA_H
#define EMPRESA_H

#include "Onibus.hpp"
#include <string>

class Empresa{
public:

    Empresa ();
    ~Empresa();


    Onibus* adicionar_onibus (const std::string &placa, int max_passageiros);
    Onibus* buscar_onibus (const std::string &placa);
    void imprimir_estado () const;


 private:

    int onibus_cadastrados = 0;
    Onibus* veiculos[20];
};

#endif
