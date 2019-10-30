//
//  Autor.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/21/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef Autor_hpp
#define Autor_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Autor {
public:
    //Construtor
    Autor(string nome, string cod_Autor){
        this->nome = nome;
        this->cod_Autor = cod_Autor;
        qtdAutor++;
    };
    //Destrutor
    static int qtdAutor;
private:
    string nome;
    string cod_Autor;
    //gets
    string getNome();
    string getCodigo();
    //sets
    void setNome(string);
    void setCodigo(string);
    //toString
    string toString();
};

#endif /* Autor_hpp */
