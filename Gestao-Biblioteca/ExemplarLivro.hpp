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

class ExemplarLivro:public Exemplar {
public:
    ExemplarLivro(short codigo, short ratingConser, short bloco, Leitor *lastReader, bool emprestado);
    ExemplarLivro();
    ~ExemplarLivro();
    ExemplarLivro *next;
    //get
    Leitor* getLastReader();
    bool getSituacao();
    //set
    void setLastReader(Leitor*);
    void setSituacao(bool situacao);
    //toString
    void toString();
private:
    Leitor *lastReader;
    bool emprestado;
};

#endif /* ExemplarLivro_hpp */
