//
//  CD.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/21/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef CD_hpp
#define CD_hpp

#include "Disco.hpp"
#include <stdio.h>

class CD:public Disco {
public:
    //Construtor
    CD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar exemplares):Disco(titulo, assunto, cota, editora, duracao, idioma, exemplares){
        qtdCD++;
    };
//    CD():Disco("","",0,"",0,"",NULL){
//        this("","",0,"",0,"",NULL);
//    };
    //Destrutor
    ~CD();
    static int qtdCD;
private:
    //toString
    string toString();
};

#endif /* CD_hpp */
