#include <iostream>
#include <stdlib.h>
using namespace std;
class No{
private:
    int valor;
    No* proximo;
   
public:
    No(int valor){
        this->valor = valor;
        proximo = NULL;
    }
    int getValor(){
        return valor;
    }
    No* getProx(){
        return proximo;
    }
   
    void setProx(No* novo){
        proximo = novo;
    }

};

No* ini;

int filaCont;

bool isEmpty(){
    return (ini == NULL);
}

void filaConstrutor(){
    ini = NULL;
    filaCont = 0;
    cout<<"Fila criada\n";
}
void filaDestrutor(){
    No* temp;
    if(isEmpty())   
        cout << "Fila vazia\n";
    else{
        while(ini != NULL){
            temp = ini;
            temp->setProx(NULL);
            ini = ini->getProx();
            free(temp);
        }
        filaCont = 0;
    }
    free(ini);
    cout<<endl;
    cout << "Fila destruida";
    cout<<endl;
}
//entrar na fila
void enfileirar(int valor){
    No* novo ;
    if(novo = NULL)
        cout << "Erro de alocação\n" << endl;
    else if(ini == NULL){
       novo = new No(valor);
       novo->setProx(NULL);
       ini = novo;
       filaCont++;
       //cout << "adicionou se a fila tiver vazia"<<endl;
    }
    else{
        if(ini->getProx() == NULL){
            novo = new No(valor);
            novo->setProx(NULL);
            ini->setProx(novo);
            filaCont++;
            //cout << "adicionou se o segundo estiver vazio\n";
        }else{
            No* temp = ini;
            novo = new No(valor);
            novo->setProx(NULL);
            while(temp != NULL){
                //cout <<" verifica valor: " << temp->getValor() << endl;
                //cout << " verifica posição prox: " << temp->getProx()<< endl;
                if(temp->getProx() == NULL){
                    temp->setProx(novo);
                    filaCont++;
                    //cout << "adicionou se o terceiro ou seguinte estver vazio\n";
                    break;
                }
                temp = temp->getProx();
            }
        }
    }  
}
//sair da fila
void desenfileirar(){
    No* aux = ini;
    if(isEmpty()){
        cout << "Fila Vazia\n";
    }else{
        //cout << "valor: " << ini->getValor() << " desinfileirado" << endl;
        ini = aux->getProx();
        filaCont--;
        free(aux);        
    }
}

void printFila(){
    No* aux = ini;
    if(isEmpty())
        cout << "Fila Vazia\n";
    else{
        cout<<endl;
        while(aux != NULL){
        cout << aux->getValor() << " " ;
        aux = aux->getProx();
        }
    }
    cout << endl;
    
}

int iniTam(){
    return filaCont;
}


int main(){
    filaConstrutor();
    cout << isEmpty() << endl;
    printFila();
    cout << "Valor do primeiro da fila: " << ini << endl;
    
    enfileirar(1);
    enfileirar(2);
    enfileirar(3);
    enfileirar(4);
    enfileirar(5);
    enfileirar(6);
    enfileirar(4);
    enfileirar(5);
    enfileirar(6);
    enfileirar(7);
    enfileirar(14);
    enfileirar(1);
    enfileirar(145);
    enfileirar(124);
    cout<<endl;
    cout << iniTam();
    printFila();
    desenfileirar();
    desenfileirar();
    desenfileirar();
    desenfileirar();
    desenfileirar();
    desenfileirar();
    desenfileirar();
    desenfileirar();
    desenfileirar();
    desenfileirar();
    cout<<endl;
    cout << iniTam();
    printFila();
    
    cout << "\nValor do primeiro da fila: " << ini->getValor() << endl;
    //cout << ini->getAntes()->getValor() << endl;
    //cout << "Valor do ultimo: " << ultimo->getValor() << endl;
    cout << isEmpty() << endl;
    filaDestrutor();
    cout << iniTam() << endl;
    printFila();
    cout << "\nbilu   teteia ate entao" << endl;
    return 0;
}