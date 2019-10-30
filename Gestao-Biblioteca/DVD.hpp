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
#include <stdio.h>

//Subclass DVD
class DVD:public Disco {
public:
    //Construtor
    DVD(string titulo, string assunto, int cota, string editora, int duracao,string idioma, Exemplar exemplares, int qualidade):Disco(titulo, assunto, cota, editora, duracao, idioma, exemplares){
        this->qualidade = qualidade;
        qtdDVD++;
    };
//    DVD():Disco("","",0,"",0,"",NULL){
//        this("","",0,"",0,"",NULL,0);
//    };
    ~DVD();
    static int qtdDVD;
private:
    int qualidade;
    //Gets
    int getQualidade();
    //Sets
    void setQualidade(int);
    //toString
    string toString();
};

#endif /* DVD_hpp */
