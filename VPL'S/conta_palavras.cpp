#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <map>

std::string lower_case (std::string& palavra) {

    std::string resultado = palavra;
     for (char& caracter : resultado) {
        caracter = std::tolower(static_cast<unsigned char>(caracter));
    }

    return resultado;
}


int main () {
std::string entrada;
std::cin >> entrada;
std::ifstream in_arquivo(entrada);

if (!in_arquivo.is_open()) {
    std::cout << "Erro ao abrir";
}


std::string linha;
std::vector<std::string> palavras;

while(std::getline(in_arquivo, linha)) { //Enquanto ler linha
    std::istringstream iss(linha);
    std::string palavra;

    while (iss >> palavra) { //Ler todas "palavras" e armazenar no vetor palavras
        lower_case(palavra);
        palavras.push_back(palavra);
    }
}

//Organizar em ordem alfabética
std::sort(palavras.begin(), palavras.end());


std::map<std::string, int> contagem_palavras;

for (const auto& palavra : palavras) {
    contagem_palavras[palavra]++;
}

for (const auto& par : contagem_palavras) {
    std::cout << par.first << " " << par.second << std::endl;
}




return 0;
} 

