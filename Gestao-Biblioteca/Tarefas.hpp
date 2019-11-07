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
    Autor* criarObjectAutor(int cod_Autor, string nomeA);
    Livro* criarObjectLivro(string titulo, string assunto, int cota, string editora, Autor *autor, string isbn,ExemplarLivro *exemplares[]);
    Monografia* criarObjectMonografia(string titulo, string assunto, int cota, string editora, string curso, Exemplar *exemplares[]);
    Revista* criarObjectRevista(string titulo, string assunto, int cota, string editora, string issn, string url, Exemplar* exemplares[]);
    DVD* criarObjectDVD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[], int qualidade);
    CD* criarObjectCD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[]);
    void inserirDoc(char);
    void removerDoc();
    bool equalDoc();
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
//    int fila[max];
    void clear();
    bool isFull();//retorna true se a fila por prioridade nao pode receber nenhuma outra entrada
    bool isEmpty()const;//retorna true se a fila por prioridade estiver vazia
    int size()const;//retorna o numero de elementos na fila por prioridade
    int getItem(unsigned int idx) const;
    int parent(unsigned int idx)const;
    int child(unsigned int idx)const;
    int find(unsigned int idx,int val)const;
    void insert(int val);//metodo para inserira na fila por prioridade
    void remove(int val);//metodo para Remover a entrada com a menor prioridade
    void makeHeap(int array[],int size);
    void makeHeap(std::vector<int>&input);
    int extractMin();//removes and returns min value
    std::vector<int> heapSort();//o(n log n)
    std::string toString() const;
    
    //Falta adicionar métodos para imprimir Livros só, Revista, Discos, 
private:
    //Estrutura para tabela de Dispersão Documentos
    Documento *table[maxDocs];
    int size_;
};

#endif /* Tarefas_hpp */
