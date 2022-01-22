#include <iostream>
#include "pilha.h"

using namespace std;

int main(){
	Pilha p ;
	
	cout <<"pilha vazia: "<<  p.isEmpty()  <<  std::endl;
	cout <<  p.getTopo() << std::endl;
	
	p.empilhar(10);
	p.empilhar(12);
	p.empilhar(14);
	cout <<  p.getTopo() << std::endl;
	p.desempilhar();
	cout <<  p.getTopo() << std::endl;
	p.desempilhar();
	cout << p.getTopo()  << std::endl;
	
	return 0;
}
