//
//  Monografia.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/25/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "Monografia.hpp"
#include "Documento.hpp"

Monografia::Monografia(string titulo, string assunto, int cota, string editora, string curso, Exemplar *exemplares[]):Documento(titulo, assunto, cota, editora){
    this->curso = curso;
//    for (short i = 0; i < sizeof(exemplares); i++)
//        this->exemplares[i] = exemplares[i];
//    qtdMono++;
}

Monografia::Monografia():Documento("","",0,""){ Monografia("","",0,"","",NULL);}

Monografia::~Monografia() { /*qtdMono--;*/}

string Monografia::getCurso()        { return curso;     }

Exemplar** Monografia::getExemplar() { return exemplares;}

void Monografia::setCurso(string curso) {
    if (!curso.empty())
        this->curso = curso;
}

void Monografia::setExemplares(Exemplar* exemplares[]) {
    for (short i = 0; i < sizeof(exemplares); i++) {
        this->exemplares[i] = exemplares[i];
    }
}

void Monografia::toString() {
    Documento::toString();
    cout<<"\nCurso: "<<curso<<endl;
}
