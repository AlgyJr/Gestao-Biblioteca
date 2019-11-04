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
    Autor(short cod_Autor, string nome);
    //Segundo construtor
    Autor();
    //Destrutor
    ~Autor();
    static int qtdAutor;
    //toString
    string toString();
private:
    short cod_Autor;
    string nome;
    
    //gets
    short getCodigo();
    string getNome();
    //sets
    void setCodigo(short);
    void setNome(string);
};

#endif /* Autor_hpp */
