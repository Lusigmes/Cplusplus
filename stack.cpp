#include <iostream>
#include <stack>
using namespace std;

template <class T>
void stackS(T array[],int tam){
	stack<T> a;
	stack<T> b;
	
	if(tam<=1)
		return;
	T aux = array[0];
	a.push(aux);
	
	for(int i=1; i<tam; i++){
		aux = array[i];
		while(!a.empty() && a.top() > aux){
			T temp = a.top();
			a.pop();
			b.push(temp);
		}
		a.push(aux);
		while(!b.empty()){
			T temp = b.top();
			b.pop();
			a.push(temp);
		}
	}
	for(int i=0; i<tam;i++){
		array[i] = a.top();
		a.pop();
	}

}

int main(){
	int array[] = {9,4,5,0,10,3,2,7,6,8,11,13,14,12,1};
	int tam = sizeof(array)/sizeof(int);
	stackS(array,tam);
	
	for(int i=0;i<tam;i++)
		cout << array[i] << std::endl;
	
	//cout << tam;
	return 0;
}
