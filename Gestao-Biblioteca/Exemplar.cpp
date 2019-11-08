//
//  Exemplar.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/21/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "Exemplar.hpp"

Exemplar::Exemplar(short codigo, short ratingConser, short bloco) {
    this->codigo       = codigo;
    this->ratingConser = ratingConser;
    this->bloco        = bloco;
}

Exemplar::Exemplar() { Exemplar(0,0,0);}

Exemplar::~Exemplar() {}

short Exemplar::getCodigo()  { return codigo;      }

short Exemplar::getConserva() { return ratingConser;}

short Exemplar::getBloco()    { return bloco;       }

void Exemplar::setCodigo(short codigo) {
    if (codigo > 0 && codigo < 10)
        this->codigo = codigo;
}

void Exemplar::setConserva(short ratingConser) {
    if (ratingConser > 0 && ratingConser < 6)
        this->ratingConser = ratingConser;
}

void Exemplar::setBloco(short bloco) {
    if (bloco > 0 && bloco < 20)
        this->bloco = bloco;
}

void Exemplar::toString() {
    cout<<"\nCódigo: "<<codigo<<"\nRating Conservação: "<<ratingConser<<"\nBloco: "<<bloco;
}
