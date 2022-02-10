#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

class No{
private:
    const char* valor;
    No* proximo;
   
public:
    No(const char* valor){
        this->valor = valor;
        proximo = NULL;
    }
    const char* getValor(){
        return valor;
    }
    No* getProx(){
        return proximo;
    }
   
    void setProx(No* novo){
        proximo = novo;
    }

};
//iniciando a fila
No* ini;
int filaCont;
FILE* fout;

int iniTam(){
    return filaCont;
}
bool isEmpty(){
    return (ini == NULL);
}
//criar fila;
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
//pegar os bytes e somar
int soma{0};
const int tam=8;
void separarEsomar(const char* valor){
    //cout << soma << endl;
    int i=0;
    for(int i=0;i<tam; i++){
        if(valor[i] == '1'){
            switch (i){
            case 0: 
                soma += (pow(2,7)); 
            case 1:
                soma += (pow(2,6));
            case 2:
                soma += (pow(2,5)); break;
            case 3:
                soma += (pow(2,4)); break;
            case 4:
                soma += (pow(2,3)); break;
            case 5: 
                soma += (pow(2,2)); break;
            case 6:
                soma += (pow(2,1)); break;
            case 7:
                soma += (pow(2,0)); break;
                          
            }
        }
    }    

    //cout << "\t" << soma+'0' << endl;
    fout = fopen("mamaco.txt","w");
    if(fout == NULL)
        cout << "NUU\n";
    else{
      
        cout << "Valor: " << (soma) << " corresponde ao caractere: " << (char)(soma) << " adicionado ao mamaco.txt!" << endl;
        //cout << "Valor: " << (soma+'0') << " corresponde ao caractere: " << (char)(soma+'0') << " adicionado ao mamaco.txt!" << endl;    
        fputc((soma),fout);
        fclose(fout);
    }
    

    soma=0;
}
  


//add na fila
void enfileirar(const char* valor){
    No* novo ;
    if(novo = NULL)
        cout << "Erro de alocação\n" << endl;
    else if(ini == NULL){
        separarEsomar(valor);
        novo = new No(valor);
        novo->setProx(NULL);
        ini = novo;
        filaCont++;
       //cout << "adicionou se a fila tiver vazia"<<endl;
    }
    else{
        if(ini->getProx() == NULL){
            separarEsomar(valor);    
            novo = new No(valor);
            novo->setProx(NULL);
            ini->setProx(novo);
            filaCont++;
            //cout << "adicionou se o segundo estiver vazio\n";
        }else{
            No* temp = ini;
            separarEsomar(valor);
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
//tirar da fila
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
//imprimira fila
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



int main(){
    filaConstrutor();
    cout<<endl;

    enfileirar("01001011");
    enfileirar("01011111");
    enfileirar("01101011");
    enfileirar("01001011");
    enfileirar("01001111");
    enfileirar("01001011");
    enfileirar("01111111");
    enfileirar("00000001");
    enfileirar("01111011");
    enfileirar("01111111");
    enfileirar("01001001");
    enfileirar("01111000");
    enfileirar("00001110");
    enfileirar("00000111");
    enfileirar("00001101");
    enfileirar("00001011");

    cout<<endl;
    cout << iniTam();
    printFila();

    desenfileirar();
    desenfileirar();

    cout<<endl;
    cout << iniTam();
    printFila();

    
 
    filaDestrutor();
    cout << "\nbilu   teteia ate entao" << endl;
    return 0;
}
