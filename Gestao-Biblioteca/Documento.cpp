//
//  Documento.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/6/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "Documento.hpp"

Documento::Documento(string titulo, string assunto, int cota, string editora) {
    this->titulo    = titulo;
    this->assunto   = assunto;
    this->cota      = cota;
    this->editora   = editora;
}

Documento::Documento()  { Documento("","",0,"");}

Documento::~Documento() {}

string Documento::getTitulo()   { return titulo; }

string Documento::getAssunto()  { return assunto;}

int Documento::getCota()        { return cota;   }

string Documento::getEditora()  { return editora;}

void Documento::setTitulo(string titulo)    {
    if (!titulo.empty())
        this->titulo = titulo;
}

void Documento::setAssunto(string assunto)  {
    if (!assunto.empty())
        this->assunto = assunto;
}

void Documento::setCota(int cota)           {
    if (cota != 0 && cota < 11)
        this->cota = cota;
}
void Documento::setEditora(string editora)  {
    if (!editora.empty())
        this->editora = editora;
}

void Documento::toString() {
    cout<<"\nTitulo: "<<titulo+""<<"\nAssunto: "<<assunto<<"\nCota: "<<cota<<"\nEditora: "<<editora;;
}
