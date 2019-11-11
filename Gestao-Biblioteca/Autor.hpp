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
    Autor(string cod_Autor, string nome);
    //Segundo construtor
    Autor();
    //Destrutor
    ~Autor();
//    static int qtdAutor;
    //gets
    string getCodigo();
    string getNome();
    //sets
    void setCodigo(string);
    void setNome(string);
    //toString
    void toString();
private:
    //MARK: Properties
    string cod_Autor;
    string nome;
    
};

#endif /* Autor_hpp */
