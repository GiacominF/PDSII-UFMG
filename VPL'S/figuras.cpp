#include <iostream>
#include <vector>
#include <cmath>


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
    std::cout << centro.get_x() << " " << centro.get_y();
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

    float area_ret = _lado1 * _lado2;
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
    area_tri = _base * _altura * 0.5;
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
    area_circ = M_PI *_raio * _raio;
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

        float x, y;
        int lado1, lado2;
        std::cin >> x >> y >> lado1 >> lado2;
        Retangulo* ret = new Retangulo(lado1, lado2, x, y); 
        figuras.push_back(ret); 

        ret->calcular_area();
    }

    else if (entrada == 'C'){

        float x, y;
        int raio;
        std::cin >> x >> y >> raio;
        
        Circulo* circ = new Circulo(raio, x, y);
        figuras.push_back(circ);

        circ->calcular_area();
    }

    else if (entrada == 'T'){

        float x, y;
        int base, altura;
        std::cin >> x >> y >> base >> altura;

        Triangulo* tri = new Triangulo(base, altura, x, y);
        figuras.push_back(tri);

        tri->calcular_area();
    }

    else if (entrada == 'D') {
    
        for (std::vector<Figura_geometrica*>::const_iterator it = figuras.cbegin(); it != figuras.cend(); ++it) {
        (*it)->desenhar(); 
    }
}


}

    for (auto& fig : figuras) {
        delete fig;
    }

    figuras.clear();

return 0;
}