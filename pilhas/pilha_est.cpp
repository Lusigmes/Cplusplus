#include <iostream>
#include <stdlib.h>
#define MAXTAM 1000
using namespace std;
//pilha estática
int  arrayPilha[MAXTAM];
int top = 1000;

void pilhaContructor(){
    top = -1;
}
int getTop(){ //tamanho do array
    return top+1;
}
bool pilhaEmpty(){
    return  (top == -1);
}
bool pilhaFull(){
    return (top == MAXTAM-1);
}

void pilhaPush(int valor){//adiciona elemento no topo
    if(pilhaFull()){
        cout << "Pilha cheia\n";
    }else{
        top++;
        arrayPilha[top] = valor;
        cout << "Empilhado\n";
    } 
}
void pilhaPop(){ //remove o elemento do topo
    if(pilhaEmpty()){
        cout << "Pilha vazia\n";
    }else{
        int temp = arrayPilha[top];
        top--;
        cout << temp << " Desempilhado\n";
        temp = -1;
        
    }
}
void pilhaBuscar( int valor){
    bool flag = true;
    if(pilhaEmpty()){
        cout << "Pilha vazia\n";
        //return false;
    }else{
        int aux = top;
        //retorna o elemento e a posição(tamanho) em que está alocado
        while(aux > -1){
            if(arrayPilha[aux] == valor){
                if(arrayPilha[aux] == arrayPilha[top])
                    cout << "Este valor está no topo\n";
                cout <<  arrayPilha[aux] << " na posição " << aux+1 << endl;
                flag =false;
                break;
                
                //return true;
            }
            aux --;
        }
        aux = -1;
    }
    if(flag){
        cout << "Valor não encontrado\n";}
    //return false;
}

void printPilha(){
    if(pilhaEmpty())
        cout << "Vazio\n";
    else{
        int aux = top;
        while(aux > -1){
            cout << arrayPilha[aux] << " ";
            cout << aux << endl;
            aux--;
        }
        aux = -1;
    }
}


int main(){
    int valor;
    pilhaContructor();
    cout << pilhaEmpty();
    pilhaPush(1);
    pilhaPush(3);
    pilhaPush(5);
    pilhaPush(7);
    pilhaPush(4);

    //pilhaPop();
    //pilhaPop();
    //pilhaPop();

    pilhaBuscar(5);
    printPilha();

    cout << endl;
    cout << getTop();
    cout << endl;
    
    pilhaPop();
    printPilha();

    cout << endl;
    cout << getTop();
    cout << endl;
   
    pilhaBuscar(7);


   


    //system("pause");
    return 0;
}
