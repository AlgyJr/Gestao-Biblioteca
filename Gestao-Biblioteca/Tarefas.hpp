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
#include "Validacoes.hpp"

class Tarefas {
    
public:
    Tarefas();
    ~Tarefas();
    void lerDoFicheiro(string);
    void inserirTable();
    Autor* criarObjectAutor(string cod_Autor, string nomeA);
    Livro* criarObjectLivro(string titulo, string assunto, int cota, string editora, Autor *autor, string isbn,ExemplarLivro *exemplares[]);
    Monografia* criarObjectMonografia(string titulo, string assunto, int cota, string editora, string curso, Exemplar *exemplares[]);
    Revista* criarObjectRevista(string titulo, string assunto, int cota, string editora, string issn, string url, Exemplar* exemplares[]);
    DVD* criarObjectDVD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[], string qualidade);
    CD* criarObjectCD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[]);
    void inserirDoc(int);
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
    bool isFull();//retorna true se a fila por prioridade nao pode receber nenhuma outra entrada
    bool isEmpty();//retorna true se a fila por prioridade estiver vazia
    int size();//retorna o numero de elementos na fila por prioridade
    int parent(int idx);
    int child(int idx);
    void insertReserva();//metodo para inserira na fila por prioridade
    Leitor* extractMin();//removes and returns min value
    void printHeap(); //Imprime reservas todas
    Leitor *criarLeitor(string cod_leitor, string nome, char categoria, string data_inscr, string validade);
    void swapObj(int, int);
    void printReserva(Leitor *obj); //Imprimir uma reserva
    
    
    //MARK: Operação 3:
    void removerDoc(int);
    bool equalRev(Revista*,string);
    bool equalDisc(Disco*,string);
    bool equalMonografia(Monografia*,string);
    bool equalBook(Livro*,string);
    bool equalDoc(int,Documento*,string);
    
    //MARK: Operação 4:
    int search(int);
    
    //MARK: Operação 5:
    bool equalAutorBook(Livro*,string);
    int catchAutorBook(Livro *book[]);
    
    //MARK: Operação 6:
    int initArrayBooks(Livro* liv[]);
    void orderByTitle(Livro* liv[], int); //usando BubbleSort
    void orderByAssunto(Livro* liv[], int); //usando BubbleSort
    int compareCrit(string, string);
    void swapElements(Livro* array[], int, int);
    void printOrderArray(Livro *liv[], int);
    
    //MARK: Operação 7:
    
    
    //MARK: Operação 8:
    void menu();
    void subMenuInsercao();
    void subMenuRemove();
    void subMenuOrdenacao();
    void subMenuPesquisa();
    void subMenu(string cab);
    
    //Falta adicionar métodos para imprimir Livros só, Revista, Discos, 
private:
    //Estrutura para tabela de Dispersão Documentos
    Documento *table[maxDocs];
    Leitor *heapReserva[199];
    Validacoes val;
    int size_;
};

#endif /* Tarefas_hpp */
