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
    Exemplar(string codigo, short ratingConser, short bloco) {
        this->codigo       = codigo;
        this->ratingConser = ratingConser;
        this->bloco        = bloco;
    }
    ~Exemplar();
private:
    string codigo;
    short ratingConser;
    short bloco;
    //gets
    string getCodigo();
    short getConserva();
    short getBloco();
    //sets
    void setCodigo(string codigo);
    void setConserva(short ratingConser);
    void setBloco(short bloco);
    //toString
    string toString();
};

#endif /* Exemplar_hpp */
