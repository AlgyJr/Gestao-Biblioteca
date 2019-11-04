//
//  Validacoes.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 11/4/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef Validacoes_hpp
#define Validacoes_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Validacoes {
public:
    //msg é a string recebida para visualizar de inicio Ex: Introduza...
    int validarInt(string msg, int min, int max);
    float validarFloat(string msg, float min, float max);
    string validarURL(string msg, string url);
    //este abaixo farei By: Algy
    string validarStringOptions(string, string, string, string, string, string);
};

#endif /* Validacoes_hpp */
