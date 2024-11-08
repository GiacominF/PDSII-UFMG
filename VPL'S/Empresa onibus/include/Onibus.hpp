#ifndef ONIBUS_H
#define ONIBUS_H

#include <string>

class Onibus{
public:
    Onibus (const std::string &placa, int max_passageiros);

    void subir_passageiros (int passageiros);
    void descer_passageiros (int passageiros);
    void transferir_passageiros (Onibus* outro_onibus, int passageiros);
    void imprimir_estado () const;

    const std::string& getplaca() const;
    int get_lot_atual() const;
    int get_max_passageiros() const;

    private:
    std::string placa;
    int lotacao_atual = 0;
    int max_passageiros;
};


#endif 



