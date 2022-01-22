#ifndef _PILHA_H_
#define _PILHA_H_
#include <iostream>
using namespace std;
class Pilha{
private:
	int *array;
	int max_tam;
	int topo;
public:
	Pilha(){
		array = new int[100];
		max_tam = 99;
		topo = -1;
	}
	~Pilha(){
		delete[] array;
	}
	void empilhar(int temp){//push
		if(topo == max_tam){
			cout << "Pilha cheia\n";
		}else{
			array[++topo] = temp;
		}
	}
	void desempilhar(){//pop
	if(topo == -1)
			 cout << "Pilha vazia\n";
		else
			topo--;
	}
	int getTopo(){
		if(!isEmpty())
			return array[topo];
		return  -1;
	}
	bool isEmpty(){
		return (topo == -1);
	}
	

};

#endif
