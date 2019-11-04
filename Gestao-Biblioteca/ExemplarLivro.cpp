//
//  ExemplarLivro.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/21/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "ExemplarLivro.hpp"
#include <sstream>

ExemplarLivro::ExemplarLivro(short codigo, short ratingConser, short bloco, Leitor *lastReader, bool emprestado):Exemplar(codigo, ratingConser, bloco) {
    this->lastReader = lastReader;
    this->emprestado = emprestado;
}

ExemplarLivro::ExemplarLivro()  {ExemplarLivro(0,0,0,NULL,false);}

ExemplarLivro::~ExemplarLivro() {}

bool ExemplarLivro::getSituacao(){ return emprestado;}

void ExemplarLivro::setSituacao(bool emprestado) { this->emprestado = emprestado;}

string ExemplarLivro::toString() {
    stringstream str;
    //Operação ternária
    str<<Exemplar::toString()<< (getSituacao()? "\nSituação: Emprestado" : "\nSituação: Livre");
    return str.str();
}
