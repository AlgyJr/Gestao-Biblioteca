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
    ExemplarLivro(string codigo, short ratingConser, short bloco, Leitor lastReader):Exemplar(codigo, ratingConser, bloco) {
        this->lastReader = lastReader;
    }
    ~ExemplarLivro();
private:
    Leitor lastReader;
    //get
    Leitor getLastReader();
    //set
    void setLastReader(Leitor lastReader);
    //toString
    string toString();
};

#endif /* ExemplarLivro_hpp */
