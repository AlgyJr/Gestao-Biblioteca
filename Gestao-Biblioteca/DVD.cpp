//
//  DVD.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/21/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "DVD.hpp"

DVD::DVD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[], int qualidade):Disco(titulo, assunto, cota, editora, duracao, idioma, exemplares){
    this->qualidade = qualidade;
//    qtdDVD++;
}

DVD::DVD():Disco("","",0,"",0,"",NULL){
    DVD("","",0,"",0,"",NULL,0);
}

DVD::~DVD() { /*qtdDVD--;*/}

int DVD::getQualidade() { return qualidade;}

void DVD::setQualidade(int qualidade) {
    if (qualidade == 144 && qualidade == 240 && qualidade == 360 && qualidade == 480 && qualidade == 720 && qualidade == 1080) {
        this->qualidade = qualidade;
    }
}

void DVD::toString() {
    Disco::toString();
    cout<<"\nQualidade: "<<qualidade<<"p"<<endl;
}
