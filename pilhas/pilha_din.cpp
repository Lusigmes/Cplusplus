#include <iostream>
#include <stdlib.h>
using namespace std;
//pilha dinamica

struct Node{
    int valor;
    Node* proximo;
};

int pilhaCont;
Node* top;


Node* getTopo(){
    return top;
}
int getTop(){
    return getTopo()->valor;
}
Node* getProx(){
    return top->proximo;
}
bool pilhaEmpty(){
    return (top == NULL);
}

void pilhaConstrutor(){
    top  = NULL;
    pilhaCont = 0;
    cout << "\nPilha Criada\n";
}
void pilhaDestrutor(){
    int aux;
    Node* temp;
    if(pilhaEmpty())
        cout << "Pilha vazia\n";
    else{
            while(top != NULL){
                temp = top;
                top = top->proximo;
                temp->proximo = NULL;
                free(temp);
            }
            pilhaCont = 0;
            cout << "\nPilha Desruida\n";
        }
}


int pilhaSize(){
    return pilhaCont;
}


void pilhaPush(int valor){
    Node* novo =(Node*)malloc(sizeof(Node));
    if(novo == NULL)
        cout  << "ERRO\n";
    else{
        novo->valor = valor;
        novo->proximo = top;
        top = novo;
        pilhaCont++;
        cout << "OK\n";
    }
}
void pilhaPop(){
    Node* temp;
    if(pilhaEmpty())
        cout << "ERRO\n";
    else{
        int aux = top->valor;

        temp = top;
        top = top->proximo;
        temp->proximo = NULL;

        pilhaCont--;
        cout << aux << " Desempilhado\n";
        aux = -1;
        free(temp);
    }
   
}

void printPilha(){
    Node* aux = top;
    if(pilhaEmpty())
        cout << "Pilha vazia\n";
    while(aux != NULL){
        cout << aux->valor << " ";
        aux = aux->proximo;
    }
    free(aux);
}


int main(){
    pilhaConstrutor();
    printPilha();
    cout << pilhaEmpty() << endl;
    cout << pilhaSize() << endl;
    pilhaPush(1);
    pilhaPush(3);
    pilhaPush(5);
    pilhaPush(7);
    pilhaPush(2);
    pilhaPop();
    cout << pilhaEmpty() << endl;
    cout << pilhaSize() << endl;
    printPilha();
    cout << endl;
    pilhaPop(); 
    printPilha(); 
    cout << endl;
    cout << pilhaSize() << endl;  
    cout << getTopo()->valor << endl;
    cout << getProx()->valor << endl;
    pilhaPush(9);
    pilhaPush(11);
    pilhaPush(13);
    pilhaPush(15); 
    printPilha();  cout<< endl;
    cout << pilhaSize() << endl;  
    cout << getTopo()->valor << endl;
    cout << getProx()->valor << endl;
    pilhaPop();
    cout << pilhaSize() << endl;  
    cout << getTopo()->valor << endl;
    cout << getProx()->valor << endl;
    printPilha();
    pilhaDestrutor();
    printPilha();
    cout << pilhaSize() << endl;  
     //cout << getProx()->valor << endl;
    /*
    int *p;
    p = (int*)malloc(sizeof(int));
    free(p);
    */
    return 0;
}
