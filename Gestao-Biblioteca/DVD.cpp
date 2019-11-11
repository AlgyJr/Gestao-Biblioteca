//
//  DVD.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/21/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "DVD.hpp"

DVD::DVD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[], string qualidade):Disco(titulo, assunto, cota, editora, duracao, idioma, exemplares){
    this->qualidade = qualidade;
//    qtdDVD++;
}

DVD::DVD():Disco("","",0,"",0,"",NULL){
    DVD("","",0,"",0,"",NULL,"");
}

DVD::~DVD() { /*qtdDVD--;*/}

string DVD::getQualidade() { return qualidade;}

void DVD::setQualidade(string qualidade) {
    this->qualidade = qualidade;
}

void DVD::toString() {
    Disco::toString();
    cout<<"\nQualidade: "<<qualidade<<endl;
}
