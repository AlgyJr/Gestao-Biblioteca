//
//  Autor.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/21/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "Autor.hpp"
#include <sstream>

Autor::Autor(short cod_Autor, string nome){
    this->cod_Autor = cod_Autor;
    this->nome      = nome;
    qtdAutor++;
}

Autor::Autor() {
    Autor(0,"");
}

Autor::~Autor() { qtdAutor--;}

short Autor::getCodigo() { return cod_Autor;}

string Autor::getNome()   { return nome;     }

void Autor::setCodigo(short cod_Autor) {
    if (cod_Autor > 0)
        this->cod_Autor = cod_Autor;
}

void Autor::setNome(string nome) {
    if (!nome.empty())
        this->nome = nome;
}

string Autor::toString() {
    stringstream str;
    str<<"\nCódigo Autor: "<<cod_Autor<<"\nNome: "<<nome;
    return str.str();
}
