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
    lerDoFicheiro();
    printDocTable();
    cout<<"\nAcaba tudo";
//    removerDoc(1); //Escolhido remover um Revista
    printDocTable();
    insert(criarLeitor("20150471", "Claida", 'P', "02/10/2019", "20/01/2021"));
    insert(criarLeitor("2016049", "Fernando", 'F', "09/11/2016", "02/01/2021"));
    insert(criarLeitor("2017220", "Tonito", 'E', "10/09/2018", "11/10/2021"));
    insert(criarLeitor("20190471", "Kelvio", 'F', "20/10/2017", "05/04/2022"));
    insert(criarLeitor("2019034", "Alfredo", 'P', "18/02/2019", "28/12/2020"));
    
    cout<<"----------Reservas----------";
    printHeap();
    
    cout<<"----------Removido----------";
    extractMin()->toString();
    
    cout<<"\nNova heap";
    printHeap();
    
    cout<<endl<<endl;
    
    Livro *listB[999];
    int sizeListB = initArrayBooks(listB, sizeListB); //Atribuição da lista ligada dos livros da posção dos livros
    
    cout<<"-------Ordenado Por Assunto------";
    
    orderByTitle(listB, sizeListB);
    cout<<sizeListB<<endl;
    printOrderArray(listB, sizeListB);
    
    cout<<"-------Ordenado Por Assunto------";
    orderByAssunto(listB, sizeListB);
    printOrderArray(listB, sizeListB);
}

Tarefas::~Tarefas() {}

//MARK: Ler Ficheiro
void Tarefas::lerDoFicheiro(){
    ifstream file ("documento.txt");
    string linha,titulo,assunto,editora,issn,url,curso,idioma,nomeA,isbn,criterio;
    float duracao;
    int qualidade;
    short cod_Autor, cota;
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
//            cout<<titulo<<assunto<<cota<<editora<<endl;
            criterio = strtok(NULL,";");
            if(criterio=="R"){//Revista
                issn=strtok(NULL,";");
                url=strtok(NULL,";");
//                r = dynamic_cast<Revista*>(aux);
                r = criarObjectRevista(titulo,assunto,cota,editora,issn,url, exemplares);
                index = 1;
//                cout<<issn<<url;
                cout<<"R";
            } else if(criterio=="M") {//monografia
                curso=strtok(NULL,";");
//                mon = dynamic_cast<Monografia*>(aux);
                mon = criarObjectMonografia(titulo,assunto,cota,editora,curso, exemplares);
                index = 2;
                cout<<curso<<endl;
            } else if(criterio=="I") {//Disco
                idioma=strtok(NULL,";");
                duracao=atoi(strtok(NULL,";"));
                cout<<idioma<<duracao;
                criterio = strtok(NULL,";");
//                dis = dynamic_cast<Disco*>(aux);
                if(criterio=="D") {//DVD
                    qualidade=atoi(strtok(NULL,";"));
//                    d = dynamic_cast<DVD*>(dis);
                    d = criarObjectDVD(titulo, assunto, cota, editora, duracao, idioma,
                        exemplares, qualidade);
                    index = 3;
                    cout<<qualidade;
                } else { //cd
//                    c = dynamic_cast<CD*>(dis);
                    c = criarObjectCD(titulo, assunto, cota, editora, duracao, idioma, exemplares);
                    cout<<"\nCriado objecto CD"<<endl;
                    index = 4;
                }
            } else { //Livro
                cod_Autor=atoi(strtok(NULL, ";"));
                nomeA=strtok(NULL,";");
                isbn=strtok(NULL,";");
//                l = dynamic_cast<Livro*>(aux);
                autor = criarObjectAutor(cod_Autor, nomeA);
                l = criarObjectLivro(titulo, assunto, cota, editora, autor, isbn, exemplaresLivro);
                index = 0;
//                cout<<cod_Autor<<nomeA<<isbn;
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
                    cout<<"Revista: "<<titulo;
                    aux = r;
                } else if (index == 2) {
                    cout<<"Monografia";
                    aux = mon;
                } else if (index == 3) {
                    cout<<"DVD";
                    aux = d;
                } else if (index == 4) {
                    cout<<"\nCD"<<titulo;
                    aux = c;
                } else {
                    cout<<"Livro: "<<titulo;
                    aux = l;
                }
                cout<<"\nIndex: "<<index;
                aux->next = table[index];
                table[index] = aux;
            } else {
                cout<<"Já existe";
            }
        }
        file.close();
        cout<<"Leitura efectuada com sucesso"<<endl;
    } else {
        cout<<"O ficheiro nao foi encontrado"<<endl;
    }
}

Autor* Tarefas::criarObjectAutor(int cod_Autor, string nomeA) {
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

DVD* Tarefas::criarObjectDVD(string titulo, string assunto, int cota, string editora, float duracao,string idioma, Exemplar *exemplares[], int qualidade){
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
}

//MARK: Operação 1: Inserir Documento

short Tarefas::posDoc(char criterio) {
    if (criterio == 'L') {
        return 0;
    } else if (criterio == 'R') {
        return 1;
    } else if (criterio == 'M') {
        return 2;
    } else if (criterio == 'D') {
        return 3;
    } else {
        return 4;
    }
}

bool Tarefas::equalDisc(Disco *aux, string titulo) {
    return aux->getTitulo() == titulo;
}

bool Tarefas::equalRev(Revista *aux, string issn) {
    cout<<"\nO ISSN: "<<aux->getISSN()<<"== "<<issn<<endl;
    return aux->getISSN() == issn;
}

bool Tarefas::equalBook(Livro *aux, string isbn) {
    return aux->getISBN() == isbn;
}

bool Tarefas::equalMonografia(Monografia *aux, string titulo) {
    return aux->getTitulo() == titulo;
}

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

void Tarefas::inserirDoc(char criterio) {
    Documento *aux = NULL;
    Exemplar* exemplares[max];
    ExemplarLivro *exemplaresLivro[max];
    Autor *autor;
    short index = posDoc(criterio);
    string linha,titulo,assunto,editora,issn,url,curso,idioma,nomeA,isbn;
    float duracao;
    int qualidade;
    short cod_Autor, cota;
    bool equal = false;
    
    aux = table[index];
    while ((aux != NULL) && !equal) {
        
        aux = aux->next;
    }
    
    if (aux == NULL) {
        aux = new Documento;
        
        cout<<"Introduza o titulo: ";
        cin >> titulo;
        cout<<"\nIntroduza o assunto: ";
        cin >> assunto;
        cout<<"\nIntroduza a cota: ";
        cin >> cota;
        cout<<"\nIntroduza a editora: ";
        cin >> editora;
        cout<<titulo<<assunto<<cota<<editora<<endl;
        if(criterio=='R'){//Revista
            cout<<"\nIntroduza o ISSN: ";
            cin >> issn;
            cout<<"\nIntroduza o url: ";
            cin >> url;
            criarObjectRevista(titulo,assunto,cota,editora,issn,url, exemplares);
            cout<<issn<<url;
        } else if(criterio=='M') {//monografia
            cout<<"Introduza o curso: ";
            cin >> curso;
            criarObjectMonografia(titulo,assunto,cota,editora,curso, exemplares);
            cout<<curso<<endl;
        } else if(criterio=='I') {//Disco
            cout<<"Introduza o idioma: ";
            cin >> idioma;
            cout<<"Introduza a duração em minutos: ";
            cin >> duracao;
            cout<<idioma<<duracao;
            if(criterio=='D') {//DVD
                cout<<"Introduza a qualidade do video(p): ";
                cin >> qualidade;
                criarObjectDVD(titulo, assunto, cota, editora, duracao, idioma,
                    exemplares, qualidade);
                cout<<qualidade;
            } else//CD
                if(criterio=='C')
                    criarObjectCD(titulo, assunto, cota, editora, duracao, idioma, exemplares);
        } else //livro
            if(criterio=='L'){
                cout<<"Introduza o código do autor: ";
                cin >> cod_Autor;
                cout<<"Introduza o nome do autor: ";
                cin >> nomeA;
                cout<<"Introduza o ISBN: ";
                cin >> isbn;
                autor = criarObjectAutor(cod_Autor, nomeA);
                criarObjectLivro(titulo, assunto, cota, editora, autor, isbn, exemplaresLivro);
                cout<<cod_Autor<<nomeA<<isbn;
            }


        aux->next = table[index];
        table[index] = aux;
        
        printf("Documento inserido com sucesso");
    } else
        printf("Erro! O documento já existe na Base de Dados");
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
        cout<<heapReserva[parentIdx]->getNome()<<"Troca com"<<heapReserva[idx]->getNome()<<endl;
        swapObj(parentIdx,idx);//Metodo para trocar os valores
        bubbleUp(parentIdx);
    }
}

void Tarefas::insert(Leitor *obj){//Metodo para inserir um novo obj
    heapReserva[size_] = obj;
    bubbleUp(size_);
    size_++;
}
//
////Precondition : index aIdx and bIdx exist in the array
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
    cout<<"Index do filho: "<<childIdx<<endl;
    if(childIdx == -1)
        return ; //Se nao tiver filho esquerdo
    int minIdx = getMinIdx(idx , childIdx , childIdx + 1);
    
    if(minIdx != idx){
        cout<<"Posição do index minimo: "<<idx<<endl;
        swapObj(idx, minIdx);
        bubbleDown(minIdx);
    }
}


Leitor *Tarefas::extractMin(){
    Leitor *min = heapReserva[0];
    size_--;
    heapReserva[0] = heapReserva[size_];
    heapReserva[size_] = NULL;//Decrementa -mos a quantidade de Obj
    cout<<endl<<size_<<endl;
    if (size_ > 1) {
        bubbleDown(0);
    }
    
    return min;
}

void Tarefas::printHeap() {
    if(isEmpty())
        cout<<"Sem Reservas"<<endl;
    else{
        for(int i=0;i<size_;i++){
            heapReserva[i]->toString();
        }
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
        cout<<endl<<"Index da procura: "<<i<<endl;
        if (i == -1) {
            cout<<"Documento não encontrado";
        } else {
            
            if (i == 0) {
                table[index] = table[index]->next;
            } else {
                aux1 = table[index]->next;
                aux2 = table[index];
                cout<<"Entrou no else";
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
    if (index == 0) { //Pedir para introduzir
        cout<<"ISBN: ";
        //chamada do método validar
    } else if (index == 1) {
        cout<<"ISSN: ";
    } else {
        cout<<"Título: ";
    }
    cin>>crit;
    
    aux1 = table[index];
    
    cout<<"Entrou no else";
//    aux1 = aux1->next;
    while (aux1 != NULL) {
        cout<<"Título: "<<aux1->getTitulo()<<endl;
        if (equalDoc(index, aux1, crit)) {
            cout<<"Apanhou";
            return i;
        } else {
            cout<<"Ainda!"<<endl;
            aux1 = aux1->next;
            i++;
        }
    }
    
    return -1;
}

//MARK: Operação 5: Pesquisar Autor (Return livro do autor)

//MARK: Operação 6: Listar Livros por Ordem

int Tarefas::initArrayBooks(Livro *liv[], int sizList) {
    Documento *aux = table[0];
    int i = 0;
    
    while (aux != NULL) {
        cout<<"Entra no while";
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

    cout<<strcmp(str1, str2)<<endl;
    
    short result = strcmp(str1, str2);
    
    if (result < 0) {
        cout<<"Primeiro Título: "<<str1<<"Segundo Título: "<<str2<<endl;
        return -1;
    } else if (result > 0) {
        cout<<"Primeiro Título: "<<str2<<"Segundo Título: "<<str1<<endl;
        return 1;
    } else
        return 0;
}

void Tarefas::printOrderArray(Livro *liv[], int siz) {
    for (int x = 0; x < siz-1; x++) {
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

//MARK: Operação 8: Menu
