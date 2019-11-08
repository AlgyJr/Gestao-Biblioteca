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
    lerDoFicheiro();
    printDocTable();
    cout<<"\nAcaba tudo";
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
    Disco *dis;
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
            
            while ((aux != NULL) && (!equalDoc())) {
                aux = aux->next;
                cout<<"\n1";
            }
            
            
            if (aux == NULL) {
                aux = new Documento;
                
                if (criterio=="R") {
                    cout<<"Revista: "<<titulo;
                    aux = r;
                } else if (criterio == "M") {
                    cout<<"Monografia";
                    aux = mon;
                } else if (criterio == "D") {
                    cout<<"DVD";
                    aux = d;
                } else if (criterio == "C") {
                    cout<<"CD";
                    aux = c;
                } else {
                    cout<<"Livro: "<<titulo;
                    aux = l;
                }
                
                aux->next = table[index];
                table[index] = aux;
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
            cout<<"Start While\n";
            string st = typeid(*aux).name();
            if (i == 0) { //Se é do tipo Livro
                cout<<"Livro ";
                l = static_cast<Livro*>(aux);
                l->toString();
                cout<<endl;
            } else if (i == 2) {//Se é Monografia
                cout<<"Monografia ";
                m = static_cast<Monografia*>(aux);
                m->toString();
                cout<<endl;
            } else if (i == 3 || i == 4) {//Se é Disco
                cout<<"Disco ";
                dis = static_cast<Disco*>(aux);
                if (i == 3){//Se é DVD
                    cout<<" DVD";
                    d = static_cast<DVD*>(dis);
                    d->toString();
                    cout<<endl;
                }else {
                    cout<<"CD";
                    c = static_cast<CD*>(dis);
                    c->toString();
                    cout<<endl;
                }
            } else {//Se for Revista
                cout<<"Revista";
                r = static_cast<Revista*>(aux);
                r->toString();
                cout<<endl;
            }
            
            aux = aux->next;
        }
        cout<<i;
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
    
//    if (Livro *l = dynamic_cast<Livro*>(ob))//Se é Livro
//        return 0;
//    else if (Monografia *l = dynamic_cast<Monografia*>(ob))//Se é Monografia
//        return 1;
//    else if (Disco *dis = dynamic_cast<Disco*>(ob))//Se é Disco
//        if (DVD *d = dynamic_cast<DVD*>(ob))//Se é DVD
//            return 3;
//        else
//            return 4;
//    else//Se for Revista
//        return 2;
}

bool Tarefas::equalDoc() {
    //Falta saber que criterios de chave unica iremos usar para comparar se é igual(se ja existe)
    return false;
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
    
    aux = table[index];
    while ((aux != NULL) && (!equalDoc()))
        aux = aux->next;
    
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

//add a dud first elem
//heap::heap() : queue_(1,0),size_(0)

bool Tarefas::isEmpty() const{ return size_ == 0; }

int Tarefas::size() const{ return size_; }

//void Tarefas::clear(){
//    queue_.clear();
//    queue_.push_back(0); //first item is a dud
//}

//int Tarefas::getItem(unsigned int idx)const{ return queue_[idx]; }
//
//int Tarefas::parent(unsigned int idx)const{
//    if(size_<=1) //empty or root has no parent
//        return -1;
//    return ((int)idx/2);//floor(idx/2)
//}
//
//int Tarefas::child(unsigned int idx)const{
//    if(size_ <= 1|| 2 * idx>size_)
//        return -1; //empty or root has no child
//
//    return (2*idx);
//}
//
//int Tarefas::find(unsigned int idx,int val)const{
//    if(idx > size_)
//        return -1;//base case :: idx out of bounds
//    if(val <queue_[idx])
//        return -1;//base case : val not in min-heap
//    if(queue_[idx] == val)
//        return idx;//found the val, return its index
//
//    int childIdx = child(idx), i =-1;
//
//    if(childIdx != -1){
//        i = max(find(childIdx,val), find(childIdx + 1,val));
//    }
//
//    return i;
//}
//
//void Tarefas::bubbleUp(int idx){
//    int parentIdx = parent(idx);
//    if(parentIdx == -1)
//        return;//base case root of heap
//    if(queue_[parentIdx]>queue_[idx]){
//        swap(queue_[parentIdx],queue_[idx]);
//        bubbleUp(parentIdx);
//    }
//}
//void Tarefas::insert(int val){
//    queue_.push_back(val);
//    size_++;
//    bubbleUp(size_);
//}
//
////Precondition : index aIdx and bIdx exist in the array
//int Tarefas::getMinIdx(int aIdx,int bIdx,int cIdx){
//    bool isLeftSmaller = (queue_[aIdx]<queue_[bIdx]);
//
//    if(cIdx >(int) size_){
//        return isLeftSmaller ? aIdx : bIdx;
//    }else if(isLeftSmaller){
//        return (queue_[aIdx]<queue_[cIdx]) ? aIdx : cIdx;
//    }else{
//        return (queue_[bIdx]<queue_[cIdx]) ? bIdx : cIdx;
//    }
//}
//
//void Tarefas::bubbleDown(int idx){
//    int childIdx = child(idx);
//    if(childIdx == -1)
//        return ; //bas case no childres left
//    int minIdx = getMinIdx(idx , childIdx , childIdx + 1);
//
//    if(minIdx != idx){
//        swap(queue_[minIdx], queue_[idx]);
//        bubbleDown(minIdx);
//    }
//}
//
//void Tarefas::remove(int val){
//    int idx = find(1,val);
//    if(idx == -1)
//        return;
//
//    queue_[idx] = queue_[size_--]; //swap current with last item
//    queue_.resize(size_ + 1);//idx 0 is a dud item
//    bubbleDown(idx);
//    bubbleUp(idx);
//}
//
//int Tarefas::extractMin(){
//    //Special case of remove
//
//    int min = queue_[1];
//    remove(min);
//    return min;
//}
//
//vector<int> Tarefas::heapSort(){
//    vector<int>sortedItems;
//    sortedItems.reserve(size_);
//    while(!isEmpty()){
//        sortedItems.push_back(extractMin());
//    }
//
//    return sortedItems;
//}
//
////create the heap given an unsorted array
//void Tarefas::makeHeap(int array[],int n){
//    size_ = n;
//    int i=0;
//    for(;i<n;i++){
//        queue_.push_back(array[i]);
//    }
//    for(int i = n;i>0;i--){
//        bubbleDown(i);
//    }
//}
//
////create heap given an unsorted vector
//void Tarefas::makeHeap(std::vector<int>&input){
//    size_ = input.size();
//    vecCiter citer = input.begin();
//
//    for(;citer != input.end();citer++){
//        queue_.push_back(*citer);
//    }
//    for(int i = size_;i>0;i--){
//        bubbleDown(i);
//    }
//}
//
//string Tarefas::toString()const{
//    if(isEmpty())
//        return "";
//
//    ostringstream sstream;
//    copy(queue_.begin()+1,queue_.end()-1,ostream_iterator<int>(sstream," "));
//    sstream << *(queue_.end()-1);
//
//    return sstream.str();
//}

//MARK: Operação 3: Remover Documento

void Tarefas::removerDoc() {
    
}

//MARK: Operação 4: Pesquisar Documento

//MARK: Operação 5: Pesquisar Autor (Return livro do autor)

//MARK: Operação 6: Listar Livros por Ordem

//MARK: Operação 7: Devolver Livro

//MARK: Operação 8: Menu

//int main() {
//    Tarefas tar;
//    tar.lerDoFicheiro();
//
//    return 0;
//}
