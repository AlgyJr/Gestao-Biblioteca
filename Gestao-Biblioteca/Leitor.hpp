//
//  Leitor.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/28/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef Leitor_hpp
#define Leitor_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Leitor {
public:
    //Construtor
    Leitor(string nome, string cod_leitor, short categoria, short prioridade, string data_inscr, string validade) {
        this->nome       = nome;
        this->cod_leitor = cod_leitor;
        this->categoria  = categoria;
        this->prioridade = prioridade;
        this->data_inscr = data_inscr;
        this->validade   = validade;
    };
    //Destrutor
    ~Leitor();
private:
    string nome;
    string cod_leitor;
    short categoria;
    short prioridade;
    string data_inscr;
    string validade;
    //gets
    string getNome();
    string getCodigo();
    short getCategoria();
    short getPrioridade();
    string getData_inscr();
    string getValidade();
    //sets
    void setNome(string nome);
    void setCodigo(string cod_leitor);
    void setCategoria(short categoria);
    void setPrioridade(short prioridade);
    void setData_inscr(string data_inscr);
    void setValidade(string validade);
    //toString
    string toString();
};

#endif /* Leitor_hpp */
