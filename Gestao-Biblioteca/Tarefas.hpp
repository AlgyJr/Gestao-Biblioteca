//
//  Tarefas.hpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 11/4/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#ifndef Tarefas_hpp
#define Tarefas_hpp
#define maxDocs 5

#include <stdio.h>
#include "Documento.hpp"
#include "Livro.hpp"
#include "DVD.hpp"
#include "CD.hpp"
#include "Monografia.hpp"
#include "Revista.hpp"

class Tarefas {
public:
    Tarefas();
    ~Tarefas();
    void lerDoFicheiro();
    void inserirTable();
    Autor* criarObjectAutor(int cod_Autor, string nomeA);
    Livro* criarObjectLivro(string titulo, string assunto, int cota, string editora, Autor *autor, string isbn,ExemplarLivro *exemplares[]);
    Monografia* criarObjectMonografia(string titulo, string assunto, int cota, string editora, string curso, Exemplar *exemplares[]);
    Revista* criarObjectRevista(string titulo, string assunto, int cota, string editora, string issn, string url, Exemplar* exemplares[]);
    DVD* criarObjectDVD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[], int qualidade);
    CD* criarObjectCD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[]);
    void inserirDoc(char);
    void removerDoc(int);
    bool equalRev(Revista*,string);
    bool equalDisc(Disco*,string);
    int search(int);
    bool equalMonografia(Monografia*,string);
    bool equalBook(Livro*,string);
    bool equalDoc(int,Documento*,string);
    short posDoc(char);
    void printDocTable();
//    void printObject();
    //MARK: Operação 2:
    void bubbleUp(int idx);
    
    //chamado pelo delete()
    //se o valor for maior que a do filhos
    //o valor e borbulhado ate nao ter mais filhos
    
    void bubbleDown(int idx);
    //usado pelo bubbleDown()
    //pega o indice do menor valor
    //entre 3 indices dados para o array da heap
    
    int getMinIdx(int aIdx,int bIdx, int cIdx);
    
public:
    bool isFull();//retorna true se a fila por prioridade nao pode receber nenhuma outra entrada
    bool isEmpty()const;//retorna true se a fila por prioridade estiver vazia
    int size()const;//retorna o numero de elementos na fila por prioridade
    int parent(unsigned int idx)const;
    int child(unsigned int idx)const;
    void insert(Leitor *obj);//metodo para inserira na fila por prioridade
    Leitor* extractMin();//removes and returns min value
    void printHeap() const;
    Leitor *criarLeitor(string cod_leitor, string nome, char categoria, string data_inscr, string validade);
    void swapObj(int, int);
    void printReserva(Leitor *obj);
    
    //Falta adicionar métodos para imprimir Livros só, Revista, Discos, 
private:
    //Estrutura para tabela de Dispersão Documentos
    Documento *table[maxDocs];
    Leitor *heapReserva[199];
    int size_;
};

#endif /* Tarefas_hpp */
