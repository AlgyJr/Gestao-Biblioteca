//
//  Validacoes.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 11/4/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "Validacoes.hpp"

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

string Validacoes::validarString(string msg, short min, short m, string erro) {
    string val;
    int i = 0;
    cout<<msg;
    do {
        getline(cin,val);
        i++;
        cout<<endl;
        if (val.length() < min || val.length() > m)
            cout<<erro<<endl;
    } while (val.length() < min || val.length() > m);
    return val;
}

short Validacoes::validarShort(string msg, short min, short m, string erro) {
    short v;
    do {
        cout<<msg;
        cin>>v;
        cout<<endl;
        if (v < min || v > m)
            cout<<erro<<endl;
    } while (v < min || v > m);
    return v;
}

int Validacoes::validarInt(string msg, int min, int m, string erro) {
    int a;
    do {
        cout<<msg;
        cin>>a;
        cout<<endl;
        if(a < min || a > m)
            cout<<erro<<endl;
    } while (a < min || a > m);
    return a;
}

float Validacoes::validarFloat(string msg, float min, float m, string erro) {
    float v;
    
    do {
        cout<<msg;
        cin>>v;
        cout<<endl;
        if(v < min || v > m)
            cout<<erro<<endl;
    } while (v < min || v > m);
    return v;
}

string Validacoes::validarRegex(string msg, string expres, string erro) {
    //Este copiei na internet nao sei o que significaa nada do que esta escrito kkk, desculpa teras que testar
    string val;
    
    do {
//        regex url_regex(val);
        cout<<msg<<endl;
        cin>>val;
        cout<<endl;
        if(/*regex_match(url,url_regex) == */false)
            cout<<"Erro! URL inválido, tente novamente."<<endl;
    } while (/*regex_match(url,url_regex) ==*/ false);
    return val;
}

string Validacoes::validarStringOptions(string msg, string opt1, string opt2, string opt3, string opt4, string erro) {
    string v;
    do {
        cout<<msg<<endl;
        cin>>v;
        cout<<endl;
        if (v != opt1 && v != opt2 && v != opt2 && v != opt3 && v != opt4)
            cout<<erro<<endl;
    } while (v != opt1 && v != opt2 && v != opt2 && v != opt3 && v != opt4);
    return v;
}

char Validacoes::validarCharOption(string msg, char opt1, char opt2, char opt3, char opt4, string erro){
    char v;
    do {
        cout<<msg<<endl;
        cin>>v;
        cout<<endl;
        if (v != opt1 && v != opt2 && v != opt2 && v != opt3 && v != opt4)
            cout<<erro<<endl;
    } while (v != opt1 && v != opt2 && v != opt2 && v != opt3 && v != opt4);
    return v;
}
