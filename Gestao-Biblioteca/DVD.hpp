//
//  DVD.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/21/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef DVD_hpp
#define DVD_hpp

#include "Disco.hpp"
#include "DVD.hpp"
#include <stdio.h>

//Subclass DVD
class DVD:public Disco {
public:
    //Construtor
    DVD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[], string qualidade);
    DVD();
    ~DVD();
//    static int qtdDVD;
    //Gets
    string getQualidade();
    //Sets
    void setQualidade(string);
    //toString
    void toString();
    
private:
    string qualidade;
    
};

#endif /* DVD_hpp */
