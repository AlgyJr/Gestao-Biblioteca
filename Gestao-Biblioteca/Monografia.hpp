//
//  Monografia.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/25/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef Monografia_hpp
#define Monografia_hpp

#include "Documento.hpp"
#include "Exemplar.hpp"
#include <stdio.h>

class Monografia:public Documento {
public:
    Monografia(string titulo, string assunto, int cota, string editora, string curso, Exemplar *exemplares[]);
    Monografia();
    ~Monografia();
//    static int qtdMono;
    Monografia *next;
    //MARK: Métodos
    //gets
    string getCurso();
    Exemplar** getExemplar();
    //sets
    void setCurso(string);
    void setExemplares(Exemplar*[]);
    //toString
    string toString();
    
private:
    string curso;
    Exemplar *exemplares[max];
    
};

#endif /* Monografia_hpp */
