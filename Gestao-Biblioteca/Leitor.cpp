//
//  Leitor.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/28/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "Leitor.hpp"
#include <sstream>

Leitor::Leitor(short cod_leitor, string nome, char categoria, short prioridade, string data_inscr, string validade) {
    this->cod_leitor = cod_leitor;
    this->nome       = nome;
    this->categoria  = categoria;
    this->prioridade = prioridade;
    this->data_inscr = data_inscr;
    this->validade   = validade;
}

Leitor::Leitor() { Leitor(0,"",0,0,"","");}

Leitor::~Leitor() { qtdLeitor--;}

short Leitor::getCodigo()       { return cod_leitor;}

string Leitor::getNome()        { return nome;      }

char Leitor::getCategoria()     { return categoria; }

short Leitor::getPrioridade()   { return prioridade;}

string Leitor::getData_inscr()  { return data_inscr;}

string Leitor::getValidade()    { return validade;  }

void Leitor::setCodigo(short codigo) {
    if (cod_leitor > 0)
        this->cod_leitor = cod_leitor;
}

void Leitor::setNome(string nome) {
    if (!nome.empty())
        this->nome = nome;
}

void Leitor::setCategoria(char categoria) {
    if (categoria == 'P' && categoria == 'E' && categoria == 'F' && categoria == 'O')
        this->categoria = categoria;
}

void Leitor::setPrioridade(short prioridade) {
    switch (categoria) {
        case 'P': this->prioridade = 1; break;
        case 'E': this->prioridade = 2; break;
        case 'F': this->prioridade = 3; break;
        case 'O': this->prioridade = 4; break;
        default: break;
    }
}

void Leitor::setData_inscr(string data_inscr) {
    if (!data_inscr.empty())
        this->data_inscr = data_inscr;
}

void Leitor::setValidade(string validade) {
    if (!validade.empty())
        this->validade = validade;
}

string Leitor::toString() {
    stringstream str;
    str<<"\nCódigo Leitor: "<<cod_leitor<<"\nNome: "<<nome<<"\nCategoria: "<<categoria<<"\nPrioridade: "<<prioridade<<"\nData de Inscrição: "<<data_inscr<<"\nValidade: "<<validade;
    return str.str();
}
