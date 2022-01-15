/*#include "lista.h"
#include <iostream>
using namespace std;
template <class T>

Node::Node(T value){
    this->valor = value;
    this->proximo = NULL;
}

T Node::getValor(){
    return this->valor;
}
Node* Node::getProximo(){
    return this->proximo;
}

void Node::setProximo(Node* prox){
    this->proximo = prox;
}


Lista::Lista(){
    this->cabeca = NULL;
    this->cauda = NULL;
}
template <class T>
Lista::Lista(T value){
    this->cabeca = new Node<T>(value);
    this->cauda = this->cabeca;
}
Lista::~Lista(){
    delete this->cabeca;
}
bool Lista::isEmpty(){
    return (this->cabeca == NULL);
}

void Lista::printLista(){
    Node<T>* aux = this->cabeca;
    if(isEmpty())
        cout << "Vazio\n";
    else{
        cout << aux->getValor() << std::endl;
        aux = aux->getProximo();
    } 
}
void Lista::addFirst(T value){
    Node<T>* novo = new Node<T>(value);
    novo->setProximo(this->cabeca);
    this->cabeca = novo;
}
void Lista::addLast(T value){
    Node<T>* novo = new Node<T>(value);
    if(isEmpty())
        cout << "Vazio\n";  
    else{
        this->cauda->setProximo(novo);
        this->cauda = novo;
    }
}
s
int Lista::sizeLista(){
    int tam=0;
    Node<T>* aux = this->cabeca;
    do{
        aux = aux->getProximo();
        tam++;
    }while(aux)

    return tam;
}

bool Lista::buscarLista(T value){
    Node<T>* aux = this->cabeca;
    while(aux){
        if(aux->getValor() == value)
            return true;
        aux = aux->getProximo();    
    }
    return false;
}
template <class T>
void Lista::removeLast(){
    if(isEmpty())
        cout << "Vazio\n";
    if(this->cabeca->getProximo() == NULL)
        this->cabeca == NULL;
    else if(this->cabeca->getProximo()->getProximo() == NULL)
        this->cabeca->setProximo(NULL);
    else{
        Node<T>* ant_ant = this->cabeca;
        Node<T>* ant = this->cabeca->getProximo();
        Node<T>* corrente = this->cabeca->getProximo()->getProximo();

        while(corrente){
            Node<T>* aux = ant;
            ant = corrente;
            ant_ant = aux;

            corrente = corrente->getProximo();
        }
        delete ant_ant->getProximo();
        ant_ant->setProximo(NULL);
        this->cauda = ant_ant;
    }


}*/