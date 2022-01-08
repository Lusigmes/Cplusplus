#include <iostream>
#include <stack>
using namespace std;
int main(){
	int tam,value;
	cin >> tam;
	stack<int>array1,array2;
	for(int i=0;i<tam;i++){
		cin >> value;
		array1.push(value);
	}

	while(!array1.empty()){
		int temp = array1.top();
		array1.pop();
		while(!array2.empty() && array2.top() < temp){
			array1.push(array2.top());
			array2.pop();
		}
		array2.push(temp);
	}
	while(!array2.empty()){
		cout << array2.top() << " " ;
		array2.pop();
	}	
	cout << std::endl;

	return 0;
}
