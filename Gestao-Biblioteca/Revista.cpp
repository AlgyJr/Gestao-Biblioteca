//
//  Revista.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/12/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "Revista.hpp"

Revista::Revista(string titulo, string assunto, int cota, string editora, string issn, string url, Exemplar* exemplares[]):Documento(titulo, assunto, cota, editora){
    this->issn       = issn;
    this->url        = url;
//    for (short i = 0; i < sizeof(exemplares); i++)
//        this->exemplares[i] = exemplares[i];
//    qtdRev++;
}

Revista::Revista():Documento("","",0,""){
    Revista("","",0,"","","",NULL);
}

Revista::~Revista() { /*qtdRev--;*/}

string Revista::getISSN()           { return issn;     }

string Revista::getURL()            { return url;      }

Exemplar** Revista::getExemplares() {return exemplares;}

void Revista::setISSN(string issn) {
    if (!issn.empty())
        this->issn = issn;
}

void Revista::setURL(string url) {
    if (!url.empty())
        this->url = url;
}

void Revista::setExemplares(Exemplar* exemplares[]) {
    for (short i = 0; i < sizeof(exemplares); i++)
        this->exemplares[i] = exemplares[i];
}

void Revista::toString() {
    Documento::toString();
    cout<<"\nISSN: "+issn+"\nURL: "+url<<endl;
}
