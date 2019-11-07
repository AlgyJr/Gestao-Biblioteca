//
//  Livro.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 10/12/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef Livro_hpp
#define Livro_hpp

#include "Documento.hpp"
#include "Autor.hpp"
#include "ExemplarLivro.hpp"


using namespace std;

class Livro:public Documento {
public:
    //Construtor
    Livro(string titulo, string assunto, int cota, string editora, Autor *autor, string isbn, ExemplarLivro *exemplares[]);
    Livro();
    ~Livro();
    Livro *next;
//    static int qtdLivro;
    //métodos
    //gets
    Autor* getAutor();
    string getISBN();
    ExemplarLivro** getExemplaresLivro();
    //sets
    void setAutor(Autor*);
    void setISBN(string);
    void setExemplares(ExemplarLivro*[]);
    //toString
    string toString();
private:
    Autor *autor;
    string isbn;
    ExemplarLivro *exemplares[max];
};

#endif /* Livro_hpp */
