//
//  Documento.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/6/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef Documento_hpp
#define Documento_hpp

#include <stdio.h>
#include <iostream>

using namespace std;
//Superclass Documento
class Documento {
public:
    //Inicialização do construtor
    Documento(string titulo, string assunto, int cota, string editora) {
        this->titulo    = titulo;
        this->assunto   = assunto;
        this->cota      = cota;
        this->editora   = editora;
    }
//    Documento() {
//        this("","",0,"");
//    };
    //Destrutor
    ~Documento();
private:
    //gets
protected:
    string titulo;
    string assunto;
    int cota;
    string editora;
    //métodos
    //gets
    string getTitulo();
    string getAssunto();
    int getCota();
    string getEditora();
    //sets
    void setTitulo(string);
    void setAssunto(string);
    void setCota(int);
    void setEditora(string);
    //toString
    string toString();
};

#endif /* Documento_hpp */
