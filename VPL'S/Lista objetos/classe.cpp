#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

class Objeto {

    public:

    //Construtor padrão
    Objeto() {
        objetos_existentes++;
        id = id_incremento++;
    }


    //Construtor parametros
    Objeto(int id) {
      this-> id = id; 
      objetos_existentes++; 
    }



    int get_id () const {
        return id;
    }

    static int get_objetos_existentes () {
        return objetos_existentes;
    }

    const void* get_memory_adress () const {
        return this;
    }

    //Destrutor
    ~Objeto() {

        objetos_existentes--;


    }


    //Atributos
    private:
    int id;
    static int objetos_existentes;
    static int id_incremento;

};

// Inicialização das variáveis estáticas 
int Objeto::objetos_existentes = 0;
int Objeto::id_incremento = 1;


int main () {


std::list<Objeto*> Objetos;
char entrada;

    while (true) {
        std::cin >> entrada;

    if (entrada == 'E') {
        break;
    }

    else if (entrada == 'A') {
        Objeto* object = new Objeto();
        Objetos.push_back(object);

    std::cout << object->get_id() << " " << object ->get_memory_adress() << std::endl;
    }

    else if (entrada == 'C') {
        int id;
        std::cin >> id;

        if(id < 0) {
            Objeto* object = new Objeto(id);
            Objetos.push_front(object);

            std::cout << object->get_id() << " " << object->get_memory_adress() << std::endl;
        }

        else std::cout << "ERRO" << std::endl;
    }

    else if(entrada == 'N') {
        std::cout << Objeto::get_objetos_existentes() << std::endl;
    }

    else if (entrada == 'R') {
        Objeto* object = Objetos.front();

        std::cout << object->get_id() << " " << object->get_memory_adress() << std::endl;

        delete object;
        Objetos.pop_front();
    }

    else if (entrada == 'P') {
        int id;
        std::cin >> id;

        if(id < 1 || id > Objeto::get_objetos_existentes()) {
            std::cout << "ERRO" << std::endl;
        }

        for (auto it = Objetos.begin(); it != Objetos.end(); it++) {
            if((*it)->get_id() == id) {
                std::cout << (*it)->get_id() << " " << (*it)->get_memory_adress() << std::endl;
            }
        }
    }

    else if (entrada == 'L') {
        for (auto it = Objetos.begin(); it!= Objetos.end(); it++) {
            std::cout << (*it)->get_id() << " " << (*it)->get_memory_adress() << std::endl;
        }
    }

    }

    
    for (auto it = Objetos.begin(); it != Objetos.end(); ++it) {
    delete *it;  // Deleta o objeto apontado pelo ponteiro
    }
    
    
    Objetos.clear();  // Limpa a lista 


    return 0;
}