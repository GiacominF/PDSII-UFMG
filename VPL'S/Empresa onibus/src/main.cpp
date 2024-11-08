#include "Onibus.hpp"
#include "Empresa.hpp"
#include <iostream>

int main() {
    Empresa empresa;

    std::cout << "teste\n";
   

    while (true) {
        std::string entrada;
        std::cin >> entrada;  

        if (entrada == "F")
            break; 

        if (entrada == "C") {
            std::string placa;
            int max_passageiros;
            std::cin >> placa >> max_passageiros;  

            if (empresa.adicionar_onibus(placa, max_passageiros) == nullptr) {
                std::cout << "ERRO : onibus repetido\n";
            } 
            
            else {
                std::cout << "novo onibus cadastrado\n";
            }
        } 
        
        
        else if (entrada == "S") {
            std::string placa;
            int passageiros;
            std::cin >> placa >> passageiros; 

            Onibus* onibus_encontrado = empresa.buscar_onibus(placa);

            if (onibus_encontrado == nullptr) {
                std::cout << "ERRO: onibus inexistente\n";
            } 
            
            else {
                onibus_encontrado->subir_passageiros(passageiros); 
            }
        } 
        
        else if (entrada == "D") {

            std::string placa;
            int passageiros;
            std::cin >> placa >> passageiros;

            Onibus* onibus_encontrado = empresa.buscar_onibus(placa);

            if (onibus_encontrado == nullptr) {
                std::cout << "ERRO: onibus inexistente\n";
            }

            else {
            
                onibus_encontrado->descer_passageiros(passageiros);
            }
        }


        else if (entrada == "T") {
            std::string placa_original;
            std::string placa_nova;
            int passageiros;
            
            std::cin >> placa_original >> placa_nova >> passageiros;

            Onibus* onibus_encontrado_1 = empresa.buscar_onibus(placa_original);

            Onibus* onibus_encontrado_2 = empresa.buscar_onibus(placa_nova);

            if (onibus_encontrado_1 == nullptr || onibus_encontrado_2 == nullptr) {
                std::cout << "ERRO: onibus inexistente\n";
            }

            else {

                onibus_encontrado_1->transferir_passageiros(onibus_encontrado_2, passageiros);

            } 
        }


        else if (entrada == "I") {

            empresa.imprimir_estado();

        }
       
    }

    return 0;
}
