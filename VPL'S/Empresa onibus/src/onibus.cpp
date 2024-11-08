#include "Onibus.hpp"
#include <iostream>

//Construtor da classe
Onibus::Onibus (const std::string &placa, int max_passageiros) {

    this->placa = placa;
    this->max_passageiros = max_passageiros;
    this->lotacao_atual = 0;

}


void Onibus::subir_passageiros (int passageiros){

    if (lotacao_atual + passageiros <= max_passageiros) {

    lotacao_atual += passageiros;
    std::cout << "passageiros subiram com sucesso\n";
    }

    else {
        std::cout << "ERRO : onibus lotado\n";
    }

}

void Onibus::descer_passageiros (int passageiros){

    if (passageiros <= lotacao_atual) {

    lotacao_atual -= passageiros;
    std::cout << "passageiros desceram com sucesso\n";

    }

    else {

        std::cout << "ERRO : faltam passageiros\n";
    }

}

void Onibus::transferir_passageiros(Onibus* outro_onibus, int passageiros){

    if (passageiros <=lotacao_atual && outro_onibus->lotacao_atual + passageiros <= outro_onibus->max_passageiros) {
    
    lotacao_atual -= passageiros;
    outro_onibus->lotacao_atual += passageiros;     

    std::cout << "transferencia de passageiros efetuada\n";
    }
    
    else {

        std::cout << "ERRO : transferencia cancelada\n";
    }

}

void Onibus::imprimir_estado () const {

    std::cout << placa << " (" << lotacao_atual << "/" << max_passageiros << ")" << std::endl;

}

const std::string& Onibus::getplaca() const {
    return placa;
}

int Onibus::get_lot_atual() const {
    return lotacao_atual;
}

int Onibus::get_max_passageiros() const {
    return max_passageiros;
}