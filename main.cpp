/* 
 * File:   main.cpp
 * Author: Bruno
 *
 * Created on 24 de Outubro de 2009, 09:47
 */

#include "LinkedList.h"

/*
 * 
 */
int main(){
    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.insert(7);
    
    cout << "insere um elemento para ordenar" << endl;
    l1.insert(3);

    cout << "remove elemento" << endl;
    l1.remove(7);

    //procura el na lista
    cout << "procura na lista e nao encotra " << endl;
    l1.isinList(7);
    cout << "procura na lista e encotra " << endl;
    l1.isinList(5);
    cout << "l1 = "; l1.print();

    //insere em uma determinada posicao
    cout << "insere em uma determinada posicao" << endl;
    l1.insertpos(6,7);
    cout << "l1 = "; l1.print();
    l1.media();
    cout << "insere um elemento nao ordenado" << endl;
    l1.insertpos(3,10);
    cout << "ordena..." << endl;
    l1.ordena();
    l1.print();

    return 0;
}

