//
//  Disco.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/12/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef Disco_hpp
#define Disco_hpp

#include "Documento.hpp"
#include "Exemplar.hpp"
#include <stdio.h>

using namespace std;

class Disco:public Documento {
public:
    Disco(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar exemplares):Documento(titulo, assunto, cota, editora){
        this->duracao    = duracao;
        this->idioma     = idioma;
        this->exemplares = exemplares;
    };
//    Disco():Documento("","",0,""){
//        Disco("","",0,"",0,"",NULL);
//    };
    ~Disco();
protected:
    int duracao;
    string idioma;
    Exemplar exemplares;
    //métodos
    //gets
    int getDuracao();
    string getIdioma();
    Exemplar getExemplares();
    //sets
    void setDuracao(int);
    void setIdioma(string);
    void setExemplares(Exemplar);
    //toString
    string toString();
    };

#endif /* Disco_hpp */
