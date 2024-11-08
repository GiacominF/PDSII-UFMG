#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>


int main(){

    std::ifstream arquivo("palavras.txt");

    if (!arquivo.is_open()){
        std::cout << "Erro ao abrir";
    }

        int num_palavras;
        arquivo >> num_palavras;
        arquivo.ignore();

        std::vector<std::string> palavras(num_palavras);

        for (int i = 0; i < num_palavras; i++){
            arquivo >> palavras[i];
        }
        
        arquivo.close();

        int indice_palavra_chave;
        std::cin >> indice_palavra_chave;

        std::string palavra_chave = palavras[indice_palavra_chave - 1];

        int tentativas = 0;
        std::string letras_nao_presentes;

        while (tentativas < 5){
        
        std::string palavra_fornecida;
        std::cin >> palavra_fornecida;


        if (palavra_fornecida == palavra_chave) {
            
            std::cout << palavra_fornecida << " (" << letras_nao_presentes << ")" << std::endl;
            std::cout << "GANHOU!" << std::endl;
            return 0;
        }

        std::string resultado = "";
        for (int i = 0; i < 5; i++) {
            if (palavra_fornecida[i] == palavra_chave[i]) {
                resultado += palavra_fornecida[i]; 


            } else if (palavra_chave.find(palavra_fornecida[i]) != std::string::npos) {
                resultado += tolower(palavra_fornecida[i]); 


            } else {
                resultado += '*'; 
               
                if (letras_nao_presentes.find(palavra_fornecida[i]) == std::string::npos) {
                    letras_nao_presentes += palavra_fornecida[i]; 
                }
            }
        }


        std::cout << resultado;

        if (!letras_nao_presentes.empty()){
            std::cout << " (";
            for(char letra : letras_nao_presentes){
                std::cout << letra;
            }
            std::cout << ")";
        }

        std::cout << '\n';
        
        tentativas++;
        }

        std::cout << "PERDEU! " << palavra_chave << std::endl;
            
    return 0;
}