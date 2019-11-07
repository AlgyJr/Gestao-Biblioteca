//
//  CD.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/21/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "CD.hpp"
//#include <sstream>

CD::CD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[]):Disco(titulo, assunto, cota, editora, duracao, idioma, exemplares){
//    qtdCD++;
}

CD::CD():Disco("","",0,"",0,"",NULL){
    CD("","",0,"",0,"",NULL);
}

CD::~CD() { /*qtdCD--;*/}

string CD::toString() {
//    stringstream str;
//    str<<Disco::toString();
    return Disco::toString();
}
