//
//  Leitor.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/28/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef Leitor_hpp
#define Leitor_hpp

#include <iostream>

using namespace std;

class Leitor {
public:
    //Construtor
    Leitor(string cod_leitor, string nome, char categoria, short prioridade, string data_inscr, string validade);
    Leitor();
    //Destrutor
    ~Leitor();
//    static int qtdLeitor;
    //MARK: gets
    string getCodigo();
    string getNome();
    char getCategoria();
    short getPrioridade();
    string getData_inscr();
    string getValidade();
    //MARK: sets
    void setCodigo(string cod_leitor);
    void setNome(string nome);
    void setCategoria(char categoria);
    void setPrioridade(char categoira);
    void setData_inscr(string data_inscr);
    void setValidade(string validade);
    //toString
    void toString();
    
private:
    //MARK: Properties
    string cod_leitor;
    string nome;
    char categoria;
    short prioridade;
    string data_inscr;
    string validade;
    //apontador
//    Livro nodeLivroEmprestado;
    
};

#endif /* Leitor_hpp */
