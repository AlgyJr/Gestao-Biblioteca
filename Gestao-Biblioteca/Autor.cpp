//
//  Autor.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/21/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "Autor.hpp"

Autor::Autor(int cod_Autor, string nome){
    this->cod_Autor = cod_Autor;
    this->nome      = nome;
//    qtdAutor++;
}

Autor::Autor() {
    Autor(0,"");
}

Autor::~Autor() { /*qtdAutor--;*/}

int Autor::getCodigo() { return cod_Autor;}

string Autor::getNome()   { return nome;     }

void Autor::setCodigo(int cod_Autor) {
    if (cod_Autor > 0)
        this->cod_Autor = cod_Autor;
}

void Autor::setNome(string nome) {
    if (!nome.empty())
        this->nome = nome;
}

void Autor::toString() {
    cout<<"\nCódigo Autor: "<<cod_Autor<<"\nNome: "<<nome;
}
