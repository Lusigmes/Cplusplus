#include <iostream>
#include <stdlib.h>
using namespace std;

void merge(int *array,int ini,int meio,int fim){
	int *aux,tam,i,j,k,pE,pD;
	int fim1=0,fim2=0;
	tam = fim-ini+1;
	pE = ini;
	pD = meio+1;
	aux = (int *) malloc(tam*sizeof(int));
	if(aux != NULL){
		for(i=0;i<tam;i++){
			if(!fim1 && !fim2){
				if(array[pE] > array[pD])
					aux[i] = array[pE++];
				else
					aux[i] = array[pD++];
			if(pE>meio) 
				fim1=1;
			if(pD>fim)
				fim2=1;	
			}else{
				if(!fim1)
					aux[i] = array[pE++];
				else
					aux[i] = array[pD++];
			}
		}
		for(j=0,k=ini;j<tam;j++,k++)
			array[k] = aux[j];
	}
	free(aux);
}



void mergeS(int *array,int ini,int fim){
	int meio;
	if(ini < fim){
		meio = (ini+fim)/2;
		mergeS(array,ini,meio);
		mergeS(array,meio+1,fim);
		merge(array,ini,meio,fim);
	}

}

int main(){
	int array[] = {9,4,5,0,10,3,2,7,6,8,11,13,14,12,1,18};
	int tam = sizeof(array)/sizeof(int);
	mergeS(array,0,tam-1);
	
	for(int i=0;i<tam;i++)
		cout << array[i] << std::endl;
	
	//cout << tam;
	return 0;
}
