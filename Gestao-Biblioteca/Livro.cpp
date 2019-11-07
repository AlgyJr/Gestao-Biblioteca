//
//  Livro.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/12/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "Livro.hpp"
#include <sstream>

Livro::Livro(string titulo, string assunto, int cota, string editora, Autor *autor, string isbn, ExemplarLivro *exemplares[]):Documento(titulo, assunto, cota, editora) {
    this->autor = autor;
    this->isbn  = isbn;
//    for (short i = 0; i < sizeof(exemplares); i++)
//        this->exemplares[i] = exemplares[i];
//    qtdLivro++;
}

Livro::Livro():Documento("","",0,""){
    Livro("","",0,"",NULL,"",NULL);
}

Livro::~Livro() { /*qtdLivro--;*/}

Autor* Livro::getAutor()                    { return autor;     }

string Livro::getISBN()                     { return isbn;      }

ExemplarLivro** Livro::getExemplaresLivro() { return exemplares;}

void Livro::setAutor(Autor* autor) {
    if (autor != NULL)
        this->autor = autor;
}

void Livro::setISBN(string isbn) {
    if (!isbn.empty())
        this->isbn = isbn;
}

void Livro::setExemplares(ExemplarLivro* exemplares[]) {
    for (short i = 0; i < sizeof(exemplares); i++)
        this->exemplares[i] = exemplares[i];
}

string Livro::toString() {
    stringstream str;
    str<<Documento::toString()<<autor->toString()<<"\nISBN: "<<isbn;
    return str.str();
}
