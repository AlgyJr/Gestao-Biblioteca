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
    CD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[]);
    CD();
    //Destrutor
    ~CD();
//    static int qtdCD;
    CD *next;
    //toString
    void toString();
};

#endif /* CD_hpp */
