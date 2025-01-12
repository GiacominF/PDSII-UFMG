#ifndef HEAP_H
#define HEAP_H

#include <iostream>

class HeapInt {
protected:
    int* valor;

public:
    HeapInt();
    HeapInt(int x);
    HeapInt(const HeapInt& outro);

    HeapInt& operator=(int novo_valor);
    HeapInt& operator=(const HeapInt& outro);
    HeapInt operator+(const HeapInt& outro) const;
    HeapInt operator-(const HeapInt& outro) const;
    bool operator==(const HeapInt& outro) const;
    friend std::istream& operator>>(std::istream& is, HeapInt& obj);
    friend std::ostream& operator<<(std::ostream& os, const HeapInt& obj);

    virtual ~HeapInt();
};

#endif