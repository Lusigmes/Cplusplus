#ifndef _LISTA_H_
#define _LISTA_H_
#include <iostream>
using namespace std;

template <class T>
class Node{
private:
    T valor;
    Node* proximo;
public:
    Node(T value){
        this->valor = value;
        this->proximo = NULL;
    }
    T getValor(){
        return this->valor;
    }
    void setProximo(Node* prox){
        this->proximo = prox;
    }
    Node* getProximo(){
        return this->proximo;
    }
};

template <class T>
class Lista{
private:
    Node<T> *cabeca;
    Node<T> *cauda;
public:
    Lista(T value){
        cabeca = new Node<T>(value);
        cauda = cabeca;
    }
    Lista(){
        cabeca = NULL;
        cauda = NULL;
    };
    ~Lista(){
        delete cabeca;
    }
    bool isEmpty(){
        return (cabeca == NULL);
    }
    void printLista(){
        Node<T>* aux = cabeca;
        if(isEmpty())
            cout << "Vazio\n";
        while(aux){
            cout << aux->getValor() << std::endl;
            aux = aux->getProximo();
        }
    }
    void addFirst(T value){
        Node<T>* novo = new Node<T>(value);
        novo->setProximo(cabeca);
        cabeca = novo;
    }
    void addLast(T value){
        Node<T>* novo = new Node<T>(value);
        if(isEmpty()){
            cabeca = novo;
            cauda = novo;
        }else{
            cauda->setProximo(novo);
            cauda = novo;
        }
    }
    int sizeLista(){
        int tam=0;
        if(isEmpty())
            return 0;
        Node<T>* aux = cabeca;
        do{
            aux = aux->getProximo();
            tam++;
        }while(aux);

        return tam;
    }   
    bool buscarLista(T value){
       Node<T>* aux = cabeca;
       while(aux){
           if(aux->getValor() == value){
               return true;
           }
           aux = aux->getProximo();
       }
       return false;
    }
    void removeLast(){
        if(cabeca->getProximo() == NULL)
            cabeca = NULL;
        else if(cabeca->getProximo()->getProximo() == NULL)
            cabeca->setProximo(NULL);
        else{
            Node<T>* ant_ant = cabeca;
            Node<T>* ant = cabeca->getProximo();
            Node<T>* corrente = cabeca->getProximo()->getProximo();

            while(corrente){
                Node<T>* aux = ant;
                ant = corrente;
                ant_ant = aux;
                corrente = corrente->getProximo();
            }
            delete ant_ant->getProximo();
            ant_ant->setProximo(NULL);
            cauda = ant_ant;
        }
    }

};


#endif