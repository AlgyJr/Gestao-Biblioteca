//
//  Revista.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/12/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef Revista_hpp
#define Revista_hpp

#include "Documento.hpp"
#include "Exemplar.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
class Revista:public Documento {
public:
    Revista(string titulo, string assunto, int cota, string editora, string issn, string url, Exemplar* exemplares[]);
    Revista();
    ~Revista();
//    static int qtdRev;
    Revista *next;
    //MARK: Métodos
    //gets
    string getISSN();
    string getURL();
    Exemplar** getExemplares();
    //sets
    void setISSN(string);
    void setURL(string);
    void setExemplares(Exemplar*[]);
    //toString()
    void toString();
    
private:
    string issn;
    string url;
    Exemplar* exemplares[max];
    
};

#endif /* Revista_hpp */
