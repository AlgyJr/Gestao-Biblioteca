//
//  Leitor.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/28/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "Leitor.hpp"
#include <stdio.h>
#include <iostream>
#include <string.h>

Leitor::Leitor(string cod_leitor, string nome, char categoria, short prioridade, string data_inscr, string validade) {
    this->cod_leitor = cod_leitor;
    this->nome       = nome;
    this->categoria  = categoria;
    this->prioridade = prioridade;
    this->data_inscr = data_inscr;
    this->validade   = validade;
//    qtdLeitor++;
}

Leitor::Leitor() { Leitor("","",' ',0,"","");}

Leitor::~Leitor() { /*qtdLeitor--;*/}

string Leitor::getCodigo()      { return cod_leitor;}

string Leitor::getNome()        { return nome;      }

char Leitor::getCategoria()     { return categoria; }

short Leitor::getPrioridade()   { return prioridade;}

string Leitor::getData_inscr()  { return data_inscr;}

string Leitor::getValidade()    { return validade;  }

void Leitor::setCodigo(string cod_leitor) {
    if (!cod_leitor.empty())
        this->cod_leitor = cod_leitor;
}

void Leitor::setNome(string nome) {
    if (!nome.empty())
        this->nome = nome;
}

void Leitor::setCategoria(char categoria) {
    if (categoria == 'P' || categoria == 'E' || categoria == 'F' || categoria == 'O')
        this->categoria = categoria;
}

void Leitor::setPrioridade(char categoria) {
    switch (categoria) {
        case 'P': this->prioridade = 1; break;
        case 'E': this->prioridade = 2; break;
        case 'F': this->prioridade = 3; break;
        case 'O': this->prioridade = 4; break;
        default: cout<<"Categoria não existente"<<endl; break;
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

void Leitor::toString() {
    cout<<"\nCódigo Leitor: "<<cod_leitor<<"\nNome: "<<nome<<"\nCategoria: "<<categoria<<"\nPrioridade: "<<prioridade<<"\nData de Inscrição: "<<data_inscr<<"\nValidade: "<<validade<<endl;
}
