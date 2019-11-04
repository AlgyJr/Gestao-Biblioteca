//
//  Exemplar.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/21/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef Exemplar_hpp
#define Exemplar_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Exemplar {
public:
    //Construtor
    Exemplar(short codigo, short ratingConser, short bloco);
    //Segundo Construtor
    Exemplar();
    //Destrutor
    ~Exemplar();
    //toString
    string toString();
private:
    short codigo;
    short ratingConser;
    short bloco;
    //gets
    short getCodigo();
    short getConserva();
    short getBloco();
    //sets
    void setCodigo(short codigo);
    void setConserva(short ratingConser);
    void setBloco(short bloco);
};

#endif /* Exemplar_hpp */
