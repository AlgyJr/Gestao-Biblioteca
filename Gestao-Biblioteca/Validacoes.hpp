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
    string validarString(string msg, short min, short m, string erro);
    short validarShort(string msg, short min, short m, string erro);
    int validarInt(string msg, int min, int m, string erro);
    float validarFloat(string msg, float min, float m, string erro);
    string validarRegex(string, string, string);
    //este abaixo farei By: Algy
    string validarStringOptions(string, string, string, string, string, string);
    char validarCharOption(string msg, char, char, char, char, string);
};

#endif /* Validacoes_hpp */
