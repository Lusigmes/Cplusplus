#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Compressorkk{
    char letra;
    int contador;
};
int comprime(char* original, Compressorkk comp[]){
    int i , i_orig=0, j;
    for(i=0; i<1000; i++){
        for(j=i_orig; j<strlen(original); j++){
            if(original[j] != original[j+1])
                break;
        }
        cout << (comp[i].contador = j-i_orig+1)<< endl;
        cout << (comp[i].letra = original[i_orig]) << endl;
    
        if(i_orig < strlen(original))
            cout << (i_orig = j+1);
         else
            break;
    }

    return i;
}
int descomprime(Compressorkk comp[], char descomp[], int tam){
    int i, i_descomp=0;
    for(i=0; i<tam;i++){
        for(int j=0; j<comp[i].contador; j++){
            descomp[i_descomp] = comp[i].letra;
            i_descomp++;
        }
    }



    return 0;
}
int main(){
    char original[] = "ORIGINALGIROFLEX";
    int originalsize = sizeof(original)/sizeof(char);
    int contador;
    Compressorkk comp[1000];
    char descomp[1000];

    contador = comprime(original,comp);
    cout << original << endl;
    for(int i=0; i<contador; i++)
        cout << comp[i].letra << comp[i].contador;
    cout << endl;
    
    descomprime(comp, descomp, contador);
    cout << descomp << endl;
    cout << originalsize << endl;
    return 0;
}
