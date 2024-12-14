#include <iostream>
#include <vector>


class Ponto {

public:
Ponto(float x, float y) : _x(x), _y(y) {}

float get_x () const {
    return _x;
}
    
float get_y () const {
    return _y;
}

private:
float _x;
float _y;

};

class Figura_geometrica {

public:
Figura_geometrica(const Ponto& centro) : centro(centro) {}

virtual void desenhar() {

};
virtual float calcular_area() = 0;
const Ponto& get_centro() const {
    return centro;
}

virtual ~Figura_geometrica() = default;

private:
Ponto centro;

};


class Retangulo : public Figura_geometrica {

public:
Retangulo(int lado1, int lado2, float x, float y)
    : Figura_geometrica(Ponto(x, y)), _lado1(lado1), _lado2(lado2) {}


float calcular_area() override {

    float area_ret;
    return area_ret;
}
void desenhar() override {

    Figura_geometrica::desenhar();
    std::cout << " RETANGULO" << std::endl;
}

private:
int _lado1;
int _lado2;


};

class Triangulo : public Figura_geometrica {

public:
Triangulo(int base, int altura, float x, float y) 
    : Figura_geometrica(Ponto(x, y)), _base(base), _altura(altura) {}

float calcular_area() override {

    float area_tri;
    return area_tri;
}

void desenhar() override {

    Figura_geometrica::desenhar();
    std::cout << " TRIANGULO" << std::endl;
}

private:
int _base;
int _altura;

};

class Circulo : public Figura_geometrica {

public:
Circulo(int raio, float x, float y) 
    : Figura_geometrica(Ponto(x, y)), _raio(raio) {}

float calcular_area() override {

    float area_circ;
    return area_circ; 
}

void desenhar() override {

    Figura_geometrica::desenhar();
    std::cout << " CIRCULO" << std::endl;
}

private:
int _raio;

};



int main() {

std::vector<Figura_geometrica*> figuras;
char entrada;


while(true) {

    std::cin >> entrada;
    if (entrada == 'E') {
        break;
    }

    else if (entrada == 'A'){

    }

    else if (entrada == 'R'){

    }

    else if (entrada == 'C'){


    }

    else if (entrada == 'T'){

    }

    else if (entrada == 'D'){

    }

}

    

    for (auto& fig : figuras) {
        figuras.clear();
        delete fig;
    }

return 0;
}