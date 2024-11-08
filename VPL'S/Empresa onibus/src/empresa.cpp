#include "Empresa.hpp"
#include <string>
#include <iostream>

//Construtor(Inicializa todos veículos como null)
Empresa::Empresa () {

    this->onibus_cadastrados = 0;
    for (int i = 0; i < 20; i++) {

        veiculos[i] = nullptr;
    }
}



Onibus* Empresa::adicionar_onibus(const std::string &placa, int max_passageiros) {

     for (int i = 0; i < onibus_cadastrados; i++) { 
       if (veiculos[i] != nullptr && veiculos[i]->getplaca() == placa) {

             return nullptr;

       }
    }
    
    if (onibus_cadastrados < 20) {
    veiculos[onibus_cadastrados] = new Onibus(placa, max_passageiros);

    onibus_cadastrados++;
    return veiculos[onibus_cadastrados - 1];

    }
    
    return nullptr;
}

Onibus* Empresa::buscar_onibus (const std::string &placa) {

    for (int i = 0; i < onibus_cadastrados; i++) { 
       if (veiculos[i] != nullptr && veiculos[i]->getplaca() == placa) {

            return veiculos[i];

       }
    }

    return nullptr;

}

void Empresa::imprimir_estado() const {
    for (int i = 0; i < onibus_cadastrados; i++) {
        if (veiculos[i] != nullptr) {
            veiculos[i]->imprimir_estado(); 
        }
    }
}

//Destrutor da classe
Empresa::~Empresa() {

    for (int i = 0; i < onibus_cadastrados; i++) {

        delete veiculos[i];
        veiculos[i] = nullptr;
    }

}


