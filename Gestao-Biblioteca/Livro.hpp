//
//  Livro.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/12/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef Livro_hpp
#define Livro_hpp

#include "Documento.hpp"
#include "Autor.hpp"
#include "ExemplarLivro.hpp"
#include <stdio.h>
using namespace std;

class Livro:public Documento {
public:
    //Construtor
    Livro(string titulo, string assunto, int cota, string editora, Autor autor, string isbn, ExemplarLivro exemplares):Documento(titulo, assunto, cota, editora) {
        this->autor = autor;
        this->isbn  = isbn;
        qtdLivro++;
    };
//    Livro():Documento("","",0,""){
//        this("","",0,"",NULL,"",NULL);
//    };
    ~Livro();
    static int qtdLivro;
private:
    Autor autor;
    string isbn;
    ExemplarLivro exemplares;
    //métodos
    //gets
    Autor getAutor();
    string getISBN();
    ExemplarLivro getExemplaresLivro();
    //sets
    void setAutor(Autor);
    void setISBN(string);
    void setExemplares(ExemplarLivro);
    //toString
    string toString();
};

#endif /* Livro_hpp */
