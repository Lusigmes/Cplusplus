#include <iostream>

using  namespace std;
template <class T>
/*void bubble(T array[],int tam){
	for(int i=tam-1; i> 0;i--){
		for(int j=0;j< i;j++){
			if(array[j] < array[j+1]){
				T aux = array[j];
				array[j] = array[j+1];	
				array[j+1] = aux;	
			}
		}
	}



}*/
void bubble(T array[],int tam){
	for(int i=0; i<tam;i++){
		for(int j=0;j<tam-1;j++){
			if(array[j] > array[j+1]){
				T aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
			}
		}	
	}





}

int main(){
	int array[] = {9,4,5,0,10,3,2,7,6,8,11,13,14,12,1};
	int tam = sizeof(array)/sizeof(int);
	bubble<int>(array,tam);
	
	for(int i=0;i<15;i++)
		cout << array[i] << std::endl;
	
	//cout << tam;
	return 0;
}

