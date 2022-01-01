#include <iostream>
using namespace std;
template <class T>
void insertion(T array[],int tam){
	for(int i=0;i<tam-1;i++){
		for(int j=i+1;j>0;j--){
			if(array[j] < array[j-1]){
				T aux = array[j];
				array[j] = array[j-1];
				array[j-1] = aux;
			
			}else break; //caso a posição for menor ou maior q anterior, nao precisa verificar os anteriores
		}
		
	}


}
/*
for(int i = 1; i <n; i++){
        int x = array[i];
        int j=i-1;
        while(j >= 0 && array[j] > x){
            array[j+1] = array[j];
            j--;    
        }
        array[j+1] = x;
    }
*/






int main(){
	int array[] = {9,4,5,0,10,3,2,7,6,8,11,13,14,12,1};
	int tam = sizeof(array)/sizeof(int);
	insertion<int>(array,tam);
	
	for(int i=0;i<15;i++)
		cout << array[i] << std::endl;
	
	//cout << tam;
	return 0;
}

