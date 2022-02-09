#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;
#define TAM 256

typedef unsigned long long int myint;
typedef unsigned char mychar;

vector<pair<mychar,myint>> tab;
char caract;
vector<char> caracter;

void bubbleSort(){
    pair<myint,mychar> aux;
    for(int i=0; i<(int)tab.size(); i++){
        for(int j=i; j<(int)tab.size();j++){
            if(tab[i].second < tab[j].second){
                aux = tab[i];
                tab[i] = tab[j];
                tab[j] = aux;
            }
        }
    }
}

int getFreq(vector<char>& vet, char letra){
    int cont{0};
    for(int i=0; i<(int)vet.size(); i++){
        if(vet[i] == letra){
            cont++;
        }
    }
    return cont;
}

void ftabConstructor(const char* filename){
    //criando a tabela
    FILE* aqv; 
    aqv = fopen(filename,"r");

    if(aqv == NULL)
        cout<<"\n[ERRO:NULO]\n";
    else{
        //cout << "ENTROU AQUI EIN, OIA QUE PASSO\n";
        while( (caract = fgetc(aqv)) != EOF )
            caracter.push_back(caract);
        fclose(aqv);
    }
    
    //calcular a frequencia

    int freq{0};
    for(int i=0; i<(int)caracter.size(); i++){
        freq = getFreq(caracter,caracter[i]);
        tab.push_back(make_pair(caracter[i],freq));
    }//cout << freq;
    
    //remover caracteres repetidos
    bool flag = true;
    while(flag){
        int cont_=0;
        for(int k=0; k<(int)tab.size(); k++){
            for(int l = k+1; l<(int)tab.size(); l++){
                if(tab[k] == tab[l]){
                    tab.erase(tab.begin()+k);
                }
            }
        }
        for(int i=0; i<(int)tab.size(); i++){
            for(int j=i+1; j<(int)tab.size(); j++){
                if(tab[i] == tab[j])
                     cont_++;
            }
        }
        if(cont_ < 1)
            flag = false;
    } 
    bubbleSort();
}

void ftabPrint(){
    for(int i=0; i<(int)tab.size(); i++){
        if(tab[i].first == ' '){
            cout << "space" << '\t' << tab[i].second << endl;
        }else if( tab[i].first == '\n'){
            cout << "\n" << '\t' << tab[i].second << endl;
        }else
            cout << tab[i].first << '\t' << tab[i].second << endl;
    }
        
    cout<<endl;
}

int main(int argc, char** argv){
   
    char filename[] = "mamaco.txt";
    ftabConstructor(filename);
    ftabPrint();
    cout<<endl;
    return 0;
}
