//
//  Tarefas.cpp
//  Gestao-Biblioteca
//
//  Created by ALgy Aly, Juicy dos Santos, Regina Massiua, Celeste Ngonhamo on 11/4/19.
//  Copyright © 2019 ALgy Aly. All rights reserved.
//

#include "Tarefas.hpp"
#include "Revista.hpp"
#include "Livro.hpp"
#include "CD.hpp"
#include "DVD.hpp"
#include "Monografia.hpp"
#include "Documento.hpp"
#include "Disco.hpp"

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

Tarefas::Tarefas() {
    //Inicializar aqui logo que ler do ficheiro
    size_ = 0;
    size_Exemp = 0;
    table[0] = NULL;
    table[1] = NULL;
    table[2] = NULL;
    table[3] = NULL;
    table[4] = NULL;
    
    lerDoFicheiro("documento.txt");
    
    menu();
}

Tarefas::~Tarefas() {}

//MARK: Ler Ficheiro
void Tarefas::lerDoFicheiro(string fich){
    ifstream file (fich);
    string linha,titulo,assunto,editora,issn,url,curso,idioma,nomeA,isbn,criterio, qualidade ,cod_Autor;
    float duracao;
    short cota;
    Exemplar* exemplares[max];
    ExemplarLivro *exemplaresLivro[max];
    Autor *autor;
    short index;
    Documento *aux;
    Livro *l;
    Revista *r;
    CD *c;
    DVD *d;
    Monografia *mon;
    
    /*Regina - Adicionar no ficheiro .txt: código autor(apenas para Livro), nome autor(apenas para Livro), qtd de exemplares(no fim da linha)*/
    
    if(file.is_open())// se o ficheiro estiver aberto
    {
        while(getline(file,linha))// verificar se o ficheiro nao tiver chegado no fim
        {
         // para que possa ler o ficheiro linha por linha
            char* str=new char[linha.length()+1];
            strcpy(str,linha.c_str());
            titulo = strtok(str,";");
            assunto= strtok(NULL,";");
            cota = atoi(strtok(NULL,";"));
            editora= strtok(NULL,";");
            criterio = strtok(NULL,";");
            if(criterio=="R"){//Revista
                issn=strtok(NULL,";");
                url=strtok(NULL,";");
                r = criarObjectRevista(titulo,assunto,cota,editora,issn,url, exemplares);
                index = 1;
            } else if(criterio=="M") {//monografia
                curso=strtok(NULL,";");
                mon = criarObjectMonografia(titulo,assunto,cota,editora,curso, exemplares);
                index = 2;
            } else if(criterio=="I") {//Disco
                idioma=strtok(NULL,";");
                duracao=atoi(strtok(NULL,";"));
                criterio = strtok(NULL,";");
                if(criterio=="D") {//DVD
                    qualidade = strtok(NULL,";");
                    d = criarObjectDVD(titulo, assunto, cota, editora, duracao, idioma,
                        exemplares, qualidade);
                    index = 3;
                } else { //cd
                    c = criarObjectCD(titulo, assunto, cota, editora, duracao, idioma, exemplares);
                    index = 4;
                }
            } else { //Livro
                cod_Autor = strtok(NULL, ";");
                nomeA=strtok(NULL,";");
                isbn=strtok(NULL,";");
                autor = criarObjectAutor(cod_Autor, nomeA);
                l = criarObjectLivro(titulo, assunto, cota, editora, autor, isbn, exemplaresLivro);
                index = 0;
            }
            
            aux = NULL;
            aux = table[index];
            
            string crit;
            if (index == 0) {
                crit = isbn;
            } else if (index == 1) {
                crit = issn;
            } else {
                crit = titulo;
            }
            
            
            while ((aux != NULL) && !equalDoc(index, aux, crit))
                aux = aux->next;
            
            
            if (aux == NULL) {
                aux = new Documento;
                
                if (index == 1) {
                    aux = r;
                } else if (index == 2) {
                    aux = mon;
                } else if (index == 3) {
                    aux = d;
                } else if (index == 4) {
                    aux = c;
                } else {
                    aux = l;
                }
                aux->next = table[index];
                table[index] = aux;
            } else {
                cout<<"Erro! Documento já existente"<<endl;
            }
        }
        file.close();
        cout<<"Leitura efectuada com sucesso"<<endl;
    } else {
        cout<<"O ficheiro nao foi encontrado"<<endl;
    }
}

Autor* Tarefas::criarObjectAutor(string cod_Autor, string nomeA) {
    Autor *a = new Autor();
    a->setCodigo(cod_Autor);
    a->setNome(nomeA);
    return a;
}

Revista* Tarefas::criarObjectRevista(string titulo, string assunto, int cota, string editora, string issn, string url, Exemplar* exemplares[]){
    Revista *rev = new Revista();
    rev->setTitulo(titulo);
    rev->setAssunto(assunto);
    rev->setCota(cota);
    rev->setEditora(editora);
    rev->setISSN(issn);
    rev->setURL(url);
//    rev->setExemplares(exemplares);
    
    return rev;
}

Monografia* Tarefas:: criarObjectMonografia(string titulo, string assunto, int cota, string editora, string curso, Exemplar *exemplares[]){
    Monografia *mono = new Monografia();
    mono->setTitulo(titulo);
    mono->setAssunto(assunto);
    mono->setCota(cota);
    mono->setEditora(editora);
    mono->setCurso(curso);
//    mono->setExemplares(exemplares);
    
    return mono;
}

DVD* Tarefas::criarObjectDVD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[], string qualidade){
    DVD *dvd=new DVD();
    dvd->setTitulo(titulo);
    dvd->setAssunto(assunto);
    dvd->setCota(cota);
    dvd->setEditora(editora);
    dvd->setIdioma(idioma);
    dvd->setDuracao(duracao);
    dvd->setQualidade(qualidade);
//    dvd->setExemplares(exemplares);
    
    return dvd;
}
CD* Tarefas::criarObjectCD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[]){
    CD *cd=new CD();
    cd->setTitulo(titulo);
    cd->setAssunto(assunto);
    cd->setCota(cota);
    cd->setEditora(editora);
    cd->setIdioma(idioma);
    cd->setDuracao(duracao);
//    cd->setExemplares(exemplares);
    
    return cd;
}
    
Livro* Tarefas::criarObjectLivro(string titulo,string assunto,int cota,string editora,Autor *autor,string isbn, ExemplarLivro* exemplaresLivro[]){
    Livro *livro = new Livro();
    livro->setTitulo(titulo);
    livro->setAssunto(assunto);
    livro->setCota(cota);
    livro->setEditora(editora);
    livro->setAutor(autor);
    livro->setISBN(isbn);
//    livro->setExemplares(exemplaresLivro);
    
    return livro;
}

void Tarefas::printDocTable() {
    Documento *aux = NULL;
    Livro *l;
    Monografia *m;
    Disco *dis;
    DVD *d;
    CD *c;
    Revista *r;
    
    if (table != NULL) {
        for (int i = 0; i < maxDocs; i++) {
            aux = table[i];
            while (aux != NULL) {
                if (i == 0) { //Posição dos Livros
                    l = static_cast<Livro*>(aux);
                    l->toString();
                    cout<<endl;
                } else if (i == 2) {//Posição das Monografias
                    m = static_cast<Monografia*>(aux);
                    m->toString();
                    cout<<endl;
                } else if (i == 3 || i == 4) {//Posições dos Discos
                    dis = static_cast<Disco*>(aux);
                    if (i == 3){//Posição dos DVDs
                        d = static_cast<DVD*>(dis);
                        d->toString();
                        cout<<endl;
                    }else { //Posição dos CDs
                        c = static_cast<CD*>(dis);
                        c->toString();
                        cout<<endl;
                    }
                } else {//Posição das Revistas
                    r = static_cast<Revista*>(aux);
                    r->toString();
                    cout<<endl;
                }
                
                aux = aux->next;
            }
        }
    } else {
        cout<<"Sem documentos"<<endl;
    }
}

//MARK: Operação 1: Inserir Documento

bool Tarefas::equalDisc(Disco *aux, string titulo)            { return aux->getTitulo() == titulo; }

bool Tarefas::equalRev(Revista *aux, string issn)             { return aux->getISSN() == issn;     }

bool Tarefas::equalBook(Livro *aux, string isbn)              { return aux->getISBN() == isbn;     }

bool Tarefas::equalMonografia(Monografia *aux, string titulo) { return aux->getTitulo() == titulo; }

bool Tarefas::equalDoc(int index, Documento *aux, string crit) { //com posição do tipo do objecto
    if (index == 1) { //Se for revista
        return equalRev(static_cast<Revista*>(aux), crit);
    } else if (index == 2) { //Se for Monografia
        return equalMonografia(static_cast<Monografia*>(aux), crit);
    } else if (index == 3 || index == 4) { //Se for posição dos Discos
        return equalDisc(static_cast<Disco*>(aux), crit);
    } else {//Se for posição dos Livros
        return equalBook(static_cast<Livro*>(aux), crit);
    }
}

void Tarefas::inserirDoc(int index) {
    Documento *aux = NULL;
    Exemplar* exemplares[max];
    ExemplarLivro *exemplaresLivro[max];
    Autor *autor;
    Livro *l;
    Revista *r;
    CD *c;
    DVD *d;
    Monografia *mon;
    string linha,titulo,assunto,editora,issn,url,curso,idioma,nomeA,isbn, cod_Autor, qualidade;
    float duracao;
    short cota;
    bool equal = false;
    
    aux = table[index];
    while ((aux != NULL) && !equal) {
        
        aux = aux->next;
    }
    
    if (aux == NULL) {
        aux = new Documento;
        
        titulo = val.validarString("Introduza o título: ", 1, 24, "Erro! Título inválido, tente novamente!");
        assunto = val.validarString("Introduza o assunto: ", 1, 99, "Erro! Assunto inválido, tente novamente!");
        cota = val.validarInt("Introduza a cota(quantidade de exemplares): ", 1, 10, "Erro! Cota inválida, tente novamente!");
        editora = val.validarString("Introduza a editora: ", 1, 18, "Erro! Editora inválida, tente novamente!");
        if(index == 1){//Revista
            issn = val.validarString("Introduza o título: ", 8, 8, "Erro! ISSN inválido, tente novamente!");
            url = val.validarRegex("Introduza o URL: ", "/(http(s)?:\/\/.)?(www\.)?[-a-zA-Z0-9@:%._\+~#=]{2,256}\.[a-z]{2,4}\b([-a-zA-Z0-9@:%_\+.~#?&//=]*)/g", "Erro! URL inválido, tente novamente!");
            r = criarObjectRevista(titulo,assunto,cota,editora,issn,url, exemplares);
        } else if(index == 2) {//monografia
            curso = val.validarString("Introduza o curso: ", 4, 30, "Erro! Curso inválido, tente novamente!");
            mon = criarObjectMonografia(titulo,assunto,cota,editora,curso, exemplares);
        } else if(index == 3 || index == 4) {//Disco
            cout<<"Introduza o idioma: ";
            cin >> idioma;
            cout<<"Introduza a duração em minutos: ";
            cin >> duracao;
            cout<<idioma<<duracao;
            if(index == 3) {//DVD
                cout<<"Introduza a qualidade do video(p): ";
                qualidade = val.validarStringOptions("Introduza a qualidade(260, 340p, 720p, 1080p): ", "240p", "360p", "720p", "1080p", "Erro! Qualidade inválida, tente d");
                d = criarObjectDVD(titulo, assunto, cota, editora, duracao, idioma,
                    exemplares, qualidade);
            } else//CD
                if(index == 4)
                    c = criarObjectCD(titulo, assunto, cota, editora, duracao, idioma, exemplares);
        } else {//livro
            cod_Autor = val.validarString("Introduza o código do autor(4 dígitos): ", 4, 4, "Erro! Código inválido, tente novamente!");
            nomeA = val.validarString("Introduza o nome do autor: ", 1, 70, "Erro! Nome inválido, tente novamente!");
            isbn = val.validarString("Introduza o ISBN do livro(deve conter 13 dígitos e 4(-) = 17 digitos): ", 17, 17, "Erro! ISBN inválido!");
            autor = criarObjectAutor(cod_Autor, nomeA);
            l = criarObjectLivro(titulo, assunto, cota, editora, autor, isbn, exemplaresLivro);
        }
        
        aux = NULL;
        aux = table[index];
        
        string crit;
        if (index == 0) {
            crit = isbn;
        } else if (index == 1) {
            crit = issn;
        } else {
            crit = titulo;
        }
        
        while ((aux != NULL) && !equalDoc(index, aux, crit)) {
            aux = aux->next;
        }
        
        if (aux == NULL) {
            aux = new Documento;
            
            if (index == 1) {
                aux = r;
            } else if (index == 2) {
                aux = mon;
            } else if (index == 3) {
                aux = d;
            } else if (index == 4) {
                aux = c;
            } else {
                aux = l;
            }
            
            aux->next = table[index];
            table[index] = aux;
        } else {
            cout<<"Erro! Documento já existente"<<endl;
        }
        
        cout<<"Documento inserido com sucesso"<<endl;
    } else
        cout<<"Erro! O documento já existe na Base de Dados"<<endl;
}

//MARK: Operação 2: Reservar Livro

bool Tarefas::isEmpty() { return size_ == 0; }

int Tarefas::size() { return size_; }

int Tarefas::parent(int idx) {
    if(size_<=1) //empty or root has no parent
        return -1;
    return ((int)(idx/2)-1);//floor(idx/2)
}

int Tarefas::child(int idx) {
    if(size_ <= 1|| (2 * idx) > size_)
        return -1; //empty or root has no child

    return (2*idx)+1;
}
void Tarefas::bubbleUp(int idx){
    int parentIdx = parent(idx);
    if(parentIdx == -1)
        return;//base case root of heap
        //Se o Valor da prioridade do pai e maior que do burraco
    if(heapReserva[parentIdx]->getPrioridade() > heapReserva[idx]->getPrioridade()){
        swapObj(parentIdx,idx);//Metodo para trocar os valores
        bubbleUp(parentIdx);
    }
}

void Tarefas::insertReserva(){//Metodo para inserir um novo obj
    string cod_leitor = val.validarString("Introduza o código leitor(4 digitos): ", 4, 4, "Erro! Código leitor inválido, tente novamente(4 digitos)!");
    string nome = val.validarString("Introduza o nome do leitor: ", 1, 99, "Erro! Nome inválido, tente novamente!");
    char categoria = val.validarCharOption("Introduza a categoria do leitor(P - Professor,E- Estudante, F- Funcionario, O- Outros): ", 'P', 'E', 'F', 'O', "Erro! Categoria inválida, tente novamente!");
    string data_inscr = val.validarString("Introduza a data de inscrição: ", 8, 10, "Erro! Data de inscrição inválida!");
    string validade = val.validarString("Introduza a validade: ", 8, 10, "Erro! Validade inválida, tente novamente!");
    heapReserva[size_] = criarLeitor(cod_leitor, nome, categoria, data_inscr, validade);
    bubbleUp(size_);
    size_++;
    //sets no exemplar
}


int Tarefas::getMinIdx(int aIdx,int bIdx,int cIdx){
    bool isLeftSmaller = (heapReserva[aIdx]->getPrioridade() <= heapReserva[bIdx]->getPrioridade());
    
    if(cIdx >=(int) size_){
        return isLeftSmaller ? aIdx : bIdx;//operacao ternaria,?-if :-else
    }else if(isLeftSmaller){
        return (heapReserva[aIdx]->getPrioridade() <= heapReserva[cIdx]->getPrioridade()) ? aIdx : cIdx;
    }else{
        return (heapReserva[bIdx]->getPrioridade() <= heapReserva[cIdx]->getPrioridade()) ? bIdx : cIdx;
    }
}

void Tarefas::bubbleDown(int idx){
    int childIdx = child(idx);
    if(childIdx == -1)
        return ; //Se nao tiver filho esquerdo
    int minIdx = getMinIdx(idx , childIdx , childIdx + 1);
    
    if(minIdx != idx){
        swapObj(idx, minIdx);
        bubbleDown(minIdx);
    }
}


Leitor *Tarefas::extractMin(){
    Leitor *min = heapReserva[0];
    size_--;//Decrementa -mos a quantidade de Obj
    heapReserva[0] = heapReserva[size_];
    heapReserva[size_] = NULL;
    if (size_ > 1) {
        bubbleDown(0);
    }
    return min;
}

void Tarefas::printHeap() {
    if(isEmpty())
        cout<<"Sem Reservas"<<endl;
    else{
        for(int i=0;i<size_;i++)
            heapReserva[i]->toString();
    }
}

void Tarefas::printReserva(Leitor *obj) {
    obj->toString();
}

Leitor *Tarefas::criarLeitor(string cod_leitor, string nome, char categoria, string data_inscr, string validade){//Criar leitor
    Leitor *novo = new Leitor();
    novo->setCodigo(cod_leitor);
    novo->setNome(nome);
    novo->setCategoria(categoria);
    novo->setPrioridade(categoria);
    novo->setData_inscr(data_inscr);
    novo->setValidade(validade);
    
    return novo;
}

void Tarefas::swapObj(int parentIdx, int idx) {
    Leitor *aux;
    aux = heapReserva[parentIdx];
    heapReserva[parentIdx] = heapReserva[idx];
    heapReserva[idx] = aux;
}

//MARK: Operação 3: Remover Documento

void Tarefas::removerDoc(int index) { //Para referenciar que documento o utilizador quer inserir
    Documento *aux1, *aux2;
    
    if (table[index] != NULL) {
        int i = search(index);
        if (i == -1) {
            cout<<"Documento não encontrado";
        } else {
            
            if (i == 0) {
                table[index] = table[index]->next;
            } else {
                aux1 = table[index]->next;
                aux2 = table[index];
                for (int c = 1; c < i; c++) {
                    aux2 = aux1;
                    aux1 = aux1->next;
                }
                aux2->next = aux1->next;
            }
        }
    } else {
        if (index == 0) {
            cout<<"Sem Livro na biblioteca";
        } else if (index == 1) {
            cout<<"Sem Revistas na Biblioteca";
        } else if (index == 2) {
            cout<<"Sem Monografias na Biblioteca";
        } else if (index == 3) {
            cout<<"Sem Discos DVD na Biblioteca";
        } else {
            cout<<"Sem Discos DVD na Biblioteca";
        }
    }
}

//MARK: Operação 4: Pesquisar Documento

int Tarefas::search(int index) {
    Documento *aux1;
    int i = 0;
    
    string crit;
    cout<<"Introduza o";
    if (index == 0) { //Pedir para introduzir
        cout<<"ISBN: ";
        //chamada do método validar
    } else if (index == 1) {
        cout<<"ISSN: ";
    } else {
        cout<<"Título: ";
    }
    cin>>crit;
    cout<<endl;
    
    aux1 = table[index];
    
    while (aux1 != NULL) {
        cout<<"Título: "<<aux1->getTitulo()<<endl;
        if (equalDoc(index, aux1, crit)) { //Se for o documento a ser procurado
            return i;
        } else { //Se não for o documento a ser procurado
            aux1 = aux1->next;
            i++;
        }
    }
    
    return -1;
}

//MARK: Operação 5: Pesquisar Autor (Return livro do autor)
bool Tarefas::equalAutorBook(Livro *obj, string name) {
    return obj->getAutor()->getNome() == name;
}

int Tarefas::catchAutorBook(Livro *book[]) {
    if (table[0] == NULL) {
        return -1;
    }
    Documento *aux = table[0];
    int i = 0;
    string name = val.validarString("Introduza o nome do autor: ", 1, 99, "Erro! Nome inválido, tente novamente!");
    
    while (aux != NULL) {
        if (equalAutorBook(static_cast<Livro*>(aux), name)) {
            book[i] = static_cast<Livro*>(aux);
            i++;
        }
        aux = aux->next;
        
    }
    return i;
}

//MARK: Operação 6: Listar Livros por Ordem

int Tarefas::initArrayBooks(Livro *liv[]) {
    Documento *aux = table[0];
    int i = 0;
    
    while (aux != NULL) {
        liv[i] = static_cast<Livro*>(aux);
        aux = aux->next;
        i++;
    }
    return i;
}

void Tarefas::orderByTitle(Livro *liv[], int sizeList) {
    for (int i = sizeList-1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (compareCrit(liv[j]->getTitulo(), liv[j+1]->getTitulo()) > 0)
                swapElements(liv, j, j+1);
}

void Tarefas::orderByAssunto(Livro *liv[], int sizeList) {
    for (int i = sizeList-1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (compareCrit(liv[j]->getAssunto(), liv[j+1]->getAssunto()) > 0)
                swapElements(liv, j, j+1);
}

int Tarefas::compareCrit(string critObj1, string critObj2) {
    char* str1 = new char[critObj1.length()+1];
    char* str2 = new char[critObj2.length()+1];
    
    strcpy(str1, critObj1.c_str());
    strcpy(str2, critObj2.c_str());
    
    short result = strcmp(str1, str2);
    
    if (result < 0) {
        return -1;
    } else if (result > 0) {
        return 1;
    } else
        return 0;
}

void Tarefas::printOrderArray(Livro *liv[], int siz) {
    for (int x = 0; x < siz; x++) {
        liv[x]->toString();
        cout<<endl;
    }
}

void Tarefas::swapElements(Livro *array[], int i, int j) {
    Livro *aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}

//MARK: Operação 7: Devolver Livro
bool Tarefas::isVazio() { return size_Exemp == 0; }

void Tarefas::receber() {
    short codigo = val.validarShort("Introduza o código do exemplar(1-10): ", 1, 10, "Erro! Código inválido, tente novamente!");
    short ratingConser = val.validarShort("Introduza o rating de conservação(1-5): ", 1, 5, "Erro! Rating inválido, tente novamente!");
    short bloco = val.validarShort("Introduza o bloco(1-20) em que se localiza: ", 1, 20, "Erro! Bloco inválido, tente novamente!");
    bool emprestado = false;
    
    string cod_leitor = val.validarString("Introduza o código leitor(4 digitos): ", 4, 4, "Erro! Código leitor inválido, tente novamente(4 digitos)!");
    string nome = val.validarString("Introduza o nome do leitor: ", 1, 99, "Erro! Nome inválido, tente novamente!");
    char categoria = val.validarCharOption("Introduza a categoria do leitor(P - Professor,E- Estudante, F- Funcionario, O- Outros): ", 'P', 'E', 'F', 'O', "Erro! Categoria inválida, tente novamente!");
    string data_inscr = val.validarString("Introduza a data de inscrição: ", 8, 10, "Erro! Data de inscrição inválida!");
    string validade = val.validarString("Introduza a validade: ", 8, 10, "Erro! Validade inválida, tente novamente!");
    
    Leitor *lastReader = criarLeitor(cod_leitor, nome, categoria, data_inscr, validade);
    
    ExemplarLivro *obj = criarObjectoExemplarL(codigo, ratingConser, bloco, lastReader, emprestado);
    exemplaresTo[size_Exemp++] = obj;
}

ExemplarLivro* Tarefas::repor() {
    if (isVazio()) {
        return NULL;
    }
    string cod_leitor = val.validarString("Introduza o código leitor(4 digitos): ", 4, 4, "Erro! Código leitor inválido, tente novamente(4 digitos)!");
    string nome = val.validarString("Introduza o nome do leitor: ", 1, 99, "Erro! Nome inválido, tente novamente!");
    char categoria = val.validarCharOption("Introduza a categoria do leitor(P - Professor,E- Estudante, F- Funcionario, O- Outros): ", 'P', 'E', 'F', 'O', "Erro! Categoria inválida, tente novamente!");
    string data_inscr = val.validarString("Introduza a data de inscrição: ", 8, 10, "Erro! Data de inscrição inválida!");
    string validade = val.validarString("Introduza a validade: ", 8, 10, "Erro! Validade inválida, tente novamente!");
    
    short ratingConser = val.validarShort("Introduza o rating de conservação(1-5): ", 1, 5, "Erro! Rating inválido, tente novamente!");
    
    Leitor *lastReader = criarLeitor(cod_leitor, nome, categoria, data_inscr, validade);
    
    exemplaresTo[size_Exemp-1]->setSituacao(false); //passa para disponivel para emprestimo
    exemplaresTo[size_Exemp-1]->setConserva(ratingConser);
    exemplaresTo[size_Exemp-1]->setLastReader(lastReader);
    return exemplaresTo[--size_Exemp];
}

ExemplarLivro* Tarefas::criarObjectoExemplarL(short codigo, short ratingConser, short bloco, Leitor *lastReader, bool emprestado) {
    ExemplarLivro *obj = new ExemplarLivro();
    obj->setCodigo(codigo);
    obj->setConserva(ratingConser);
    obj->setBloco(bloco);
    obj->setLastReader(lastReader);
    
    return obj;
}

//MARK: Operação 8: Menu
void Tarefas::menu() {
    short opcao;
    
    do {
        cout<<"|*****************BIBLIOTECA****************|"<<endl;
        cout<<"|1   Inserir documento                      |"<<endl;
        cout<<"|2   Visualizar documentos                  |"<<endl;
        cout<<"|3   Reservar Livro                         |"<<endl;
        cout<<"|4   Visualizar reservas de livros          |"<<endl;
        cout<<"|5   Remover documento                      |"<<endl;
        cout<<"|6   Pesquisar por documento                |"<<endl;
        cout<<"|7   Visualizar Livros de Autor             |"<<endl;
        cout<<"|8   Visualizar Livros Ordenados            |"<<endl;
        cout<<"|9   Receber Livro                          |"<<endl;
        cout<<"|10  Repor Livro na biblioteca              |"<<endl;
        cout<<"|11  Sair                                   |"<<endl;
        cout<<"|*******************************************|"<<endl;
        
        opcao = val.validarShort("Introduza a opção (1-11): ", 1, 11, "Erro! Opção inválida, tente novamente!");
        
//        extractMin()->toString();
        int sizeListB = 0;
        
        switch(opcao){
            case 1: subMenuInsercao(); break;
            case 2: printDocTable(); break;
            case 3: insertReserva(); break;
            case 4: printHeap();; break;
            case 5: subMenuRemove(); break;
            case 6: subMenuPesquisa(); break;
            case 7: Livro *listB[999];
                    sizeListB = catchAutorBook(listB);
                    if (sizeListB != -1) {
                        orderByTitle(listB, sizeListB);
                        printOrderArray(listB, sizeListB);
                    }break;
            case 8: subMenuOrdenacao(); break;
            case 9: receber(); break;
            case 10: repor(); break;
            case 11: cout<<"Continuação de um bom dia"<<endl;
        }
    } while (opcao != 11);
}

void Tarefas::subMenuInsercao(){
    int opcao;
    
    subMenu("Inserção");
    opcao = val.validarShort("Introduza a opção (1-6): ", 1, 6, "Erro! Opção inválida, tente novamente!");
    
    switch(opcao){
        case 1: inserirDoc(2); break;
        case 2: inserirDoc(3); break;
        case 3: inserirDoc(4); break;
        case 4: inserirDoc(0); break;
        case 5: inserirDoc(1); break;
        case 6: return;
    }
}

void Tarefas::subMenuRemove() {
    int opcao;
    
    subMenu("Remoção");
    opcao = val.validarShort("Introduza a opção (1-6): ", 1, 6, "Erro! Opção inválida, tente novamente!");
    
    switch(opcao){
        case 1: removerDoc(2); break;
        case 2: removerDoc(3); break;
        case 3: removerDoc(4); break;
        case 4: removerDoc(0); break;
        case 5: removerDoc(1); break;
        case 6: return;
    }
}

void Tarefas::subMenuOrdenacao(){
    int opcao;
    
    Livro *listB[999];
    int sizeListB = initArrayBooks(listB); //Atribuição da lista ligada dos livros da posção dos livros
    cout<<"|****************ORDENACAO****************|"<<endl;
    cout<<"|1 Ordenado por Titulo                    |"<<endl;
    cout<<"|2 Ordenado por Tema                      |"<<endl;
    cout<<"|3 Voltar ao Menu Principal               |"<<endl;
    cout<<"|*****************************************|"<<endl;
    
    opcao = val.validarShort("Introduza a opção (1-3): ", 1, 3, "Erro! Opção inválida, tente novamente!");
    
    switch(opcao){
        case 1: orderByTitle(listB, sizeListB);
                cout<<"-------Ordenado Por Titulo------";
                printOrderArray(listB, sizeListB); break;
        case 2: orderByAssunto(listB, sizeListB);
                cout<<"-------Ordenado Por Assunto------";
                printOrderArray(listB, sizeListB); break;
        case 3: return;
    }
}

void Tarefas::subMenuPesquisa() {
    int opcao;
    
    subMenu("Pesquisa");
    opcao = val.validarShort("Introduza a opção (1-6): ", 1, 6, "Erro! Opção inválida, tente novamente!");
    
    switch(opcao){
        case 1: search(2); break;
        case 2: search(3); break;
        case 3: search(4); break;
        case 4: search(0); break;
        case 5: search(1); break;
        case 6: return;
    }
}

void Tarefas::subMenu(string cab) {
    cout<<"|****************"<<cab<<"****************|"<<endl;
    cout<<"|1  Monografia                           |"<<endl;
    cout<<"|2  DVD                                  |"<<endl;
    cout<<"|3  CD                                   |"<<endl;
    cout<<"|4  Livro                                |"<<endl;
    cout<<"|5  Revista                              |"<<endl;
    cout<<"|6  Voltar ao Menu Principal             |"<<endl;
    cout<<"|****************************************|"<<endl;
}
