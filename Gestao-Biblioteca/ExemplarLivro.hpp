//
//  ExemplarLivro.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/21/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef ExemplarLivro_hpp
#define ExemplarLivro_hpp

#include "Exemplar.hpp"
#include "Leitor.hpp"
#include <stdio.h>

struct ExemplarLivro:public Exemplar {
public:
    ExemplarLivro(short codigo, short ratingConser, short bloco, Leitor *lastReader, bool emprestado);
    ExemplarLivro();
    ~ExemplarLivro();
private:
    Leitor *lastReader;
    bool emprestado;
    //get
    Leitor* getLastReader();
    bool getSituacao();
    //set
    void setLastReader(Leitor*);
    void setSituacao(bool situacao);
    //toString
    string toString();
};

#endif /* ExemplarLivro_hpp */
