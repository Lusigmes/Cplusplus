#include "lista.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[]){
    Lista<string> l ;
    l.addLast("agua");
    l.addLast("refri");
    l.addLast("suco");
    l.addFirst("querosene");
    l.addFirst("chumbinho");
    l.addLast("Quiboa");
    l.addLast("Radiação");

    if(l.buscarLista("dragao")) cout << "Encontrado\n";
    else cout << "Não encontrado\n"; 

    l.printLista();
    cout << l.sizeLista() << "\n";

    l.removeLast();
    l.removeLast();
    l.removeLast();
    l.removeLast();

    if(l.buscarLista("agua")) cout << "Encontrado\n";
    else cout << "Não encontrado\n"; 
    
    l.printLista();
    cout << l.sizeLista() << "\n";
    l.~Lista();
    return 0;
}