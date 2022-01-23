#include <iostream>
#include <stdlib.h>
using namespace std;

struct No{
    int valor;
    No *antes;
    No *prox;
};
struct ListaD{
    No* ini = NULL;
    No* fim = NULL;
};


bool isEmpty(ListaD *lista){
    if(lista->ini == NULL)
        return true;
    return false;
}

int listaCont;
int sizeLista(){
    return listaCont;
}

//construtor e destrutor
void listaConstrutor(ListaD *lista){
    lista->ini = NULL;
    lista->fim = NULL;
    listaCont = 0;
    cout << "Lista criada\n";
}
void listaDestrutor(ListaD *lista){
    No* temp;
    if(isEmpty(lista))
        cout << "Lista Vazia\n";
    else{
        do{
            No* aux = lista->ini;
            lista->ini = lista->ini->prox;
            aux->prox = NULL;
            free(aux);
        }while(lista->ini != NULL);
        listaCont = 0;
    }
    cout << "Lista destruída\n";
}


//add começo
void inserirInicio(ListaD *lista){
    No* novo;
    novo = new No;
    //No* novo = (No*)malloc(sizeof(No));
    cout << "Digite o valor inicio: ";
    cin >> novo->valor;
    
    if(lista->ini == NULL){
        lista->ini = novo;
        lista->fim = novo;
        listaCont++;
    }else{
        lista->ini->antes = novo;
        novo->prox = lista->ini;
        lista->ini = novo;
        listaCont++;
        }
}
//add fim
void inserirFim(ListaD* lista){
    No* novo = new No;
    cout << "Digite o valor no fim: ";
    cin >> novo->valor;
    if(lista->ini == NULL){
        lista->ini = novo;
        lista->fim = novo;
        listaCont++;
    }else if(lista->fim->prox == NULL){
        lista->fim->prox = novo;
        novo->antes = lista->fim;
        lista->fim = novo;
        //lista->fim->prox = NULL;
        listaCont++;
    }
        
    
    
}
//remover do começo com um metodo
void removerIni(ListaD *lista){
    No* aux;
    if(isEmpty(lista))
        cout << "Lista vazia\n";
    else{//pode usar mesma logica pro fim
        aux  = lista->ini;
        //aux->prox = lista->ini->prox;
        lista->ini = aux->prox;
        cout << "Removido do começo: " << aux->valor << endl;
        lista->ini->antes = NULL;//lista->ini->antes == aux == null;
        listaCont--;
        free(aux);
        //cout<< "Removido do começo:"
    }
}
//remover do fim com outro metodo
void removerFim(ListaD *lista){
     //No* aux;
    if(isEmpty(lista))
        cout << "Lista vazia\n";
    else{//pode usar mesa logica pro ini
        //aux  = lista->fim;
        //aux->prox = lista->ini->prox;
        //->fim = aux->antes;
        lista->fim = lista->fim->antes;
        cout << "Removido do fim: " << lista->fim->prox->valor << endl;
        lista->fim->prox = NULL;
        
        listaCont--;
        free(lista->fim->prox);
    }
}
//mostrar lista e buscar valor
void printLista(ListaD *lista){
    No* novo = new No;
    novo = lista->ini;
    if(isEmpty(lista))
        cout << "\nLista Vazia\n";
    else{
        cout<<endl;
        while(novo != NULL){
            cout << novo->valor << " ";
            novo = novo->prox;
        }
        cout<<endl;
    }
    
}
void buscarNaLista(ListaD *lista, int n){
    No* temp = lista->ini;
    int contAux = 0 ; 
    bool flag = true;
    if(isEmpty(lista)){
        cout << "Lista Vazia\n";
    }else{
        while(temp != NULL){
            contAux++;
            if(temp->valor == n){
                flag=false;
                cout << "Valor " << temp->valor << " na posição: "<< contAux << endl;
            }
            temp = temp->prox;
        }
    }
    if(flag)
        cout << "Valor não encontrado\n";
}


int main(){
    ListaD l ;
    listaConstrutor(&l);

    cout << isEmpty(&l) << endl;

    printLista(&l);
    inserirFim(&l);
    inserirInicio(&l);
    inserirFim(&l);
    inserirInicio(&l);
    inserirInicio(&l);
    inserirFim(&l);
    inserirInicio(&l);
    inserirInicio(&l);
    printLista(&l);
    removerIni(&l);
    removerFim(&l);
    removerIni(&l);
    removerFim(&l);

    printLista(&l);
    buscarNaLista(&l, 8);

    cout << isEmpty(&l) << endl;

    printLista(&l);
    
    inserirFim(&l);
    inserirFim(&l);
    inserirFim(&l);
    inserirInicio(&l);
    inserirFim(&l);
    inserirFim(&l);
    inserirFim(&l);
    inserirInicio(&l);
    inserirInicio(&l);
    removerIni(&l);
    removerFim(&l);
    buscarNaLista(&l, 23);

    cout << sizeLista()<<endl;
    printLista(&l); cout << endl;
    listaDestrutor(&l);
    printLista(&l);
    cout << sizeLista()<<endl;
    
    cout << "\nSHOW DE BOLA\n";

    return 0; 
}