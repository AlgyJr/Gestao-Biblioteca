//
//  Documento.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/6/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef Documento_hpp
#define Documento_hpp
#define max 10

#include <stdio.h>
#include <iostream>

using namespace std;
//Superclass Documento
class Documento {
public:
    //Inicialização do construtor
    Documento(string titulo, string assunto, int cota, string editora);
    Documento();
    //Destrutor
    //virtual para permitir Documento ser polimórfico
    virtual ~Documento();
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
    Documento *next;
    
protected:
    string titulo;
    string assunto;
    int cota;
    string editora;
};

#endif /* Documento_hpp */
