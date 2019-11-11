//
//  Disco.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/12/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "Disco.hpp"

Disco::Disco(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[]):Documento(titulo, assunto, cota, editora){
    this->duracao    = duracao;
    this->idioma     = idioma;
//    for (short i = 0; i < sizeof(exemplares); i++)
//        this->exemplares[i] = exemplares[i];
}

Disco::Disco():Documento("","",0,""){ Disco("","",0,"",0,"",NULL);}

Disco::~Disco(){}

float Disco::getDuracao()         { return duracao;   }

string Disco::getIdioma()         { return idioma;    }

//Exemplar** Disco::getExemplares() { return exemplares;}

void Disco::setDuracao(float duracao) {
    if (duracao != 0.0)
        this->duracao = duracao;
}

void Disco::setIdioma(string idioma) {
    if (!idioma.empty())
        this->idioma = idioma;
}

//void Disco::setExemplares(Exemplar* exemplares[]) {
//    for (short i = 0; i < sizeof(exemplares); i++) {
//        this->exemplares[i] = exemplares[i];
//    }
//}

void Disco::toString() {
    Documento::toString();
    cout<<"\nDuração: "<<duracao<<" min"<<"\nIdioma: "<<idioma;
}
