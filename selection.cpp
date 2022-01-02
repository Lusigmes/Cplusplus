#include <iostream>
using namespace std;

template <class T>
void selection(T array[],int tam){
	double less;
	int position;
	bool trade;
	for(int i=0; i<tam-1;i++){
		less = array[i];
		position = i;
		trade = false;
		for(int j=i+1; j<tam;j++){
			if(array[j] < less){
			less = array[j];
			position = j;
			trade = true;
			}
		
		}
		if(trade){
			T aux = array[i];
			array[i] = less;
			array[position] = aux;
		
		}
	}



}


int main(){
	int array[] = {9,4,5,0,10,3,2,7,6,8,11,13,14,12,1};
	int tam = sizeof(array)/sizeof(int);
	selection<int>(array,tam);
	
	for(int i=0;i<15;i++)
		cout << array[i] << std::endl;
	
	cout << tam;
	return 0;
}
