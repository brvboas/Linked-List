/* 
 * File:   LinkedList.h
 * Author: Bruno
 *
 * Created on 24 de Outubro de 2009, 09:49
 */

#ifndef _LINKEDLIST_H
#define	_LINKEDLIST_H
using namespace std;
#include <iostream>

typedef int Node_entry;
struct Node {
// data members
	Node_entry entry;
	Node *next;
	// constructors
	Node();
	Node(Node_entry, Node *link = NULL);
};


class LinkedList{
  private:
	Node *front;
        int qtdEl();
  public:
	LinkedList();
	~LinkedList();
	bool isEmpty();
   	bool insert(Node_entry);//insert ordenado
   	bool insertpos(int,Node_entry);//insert em determinada posicao
	bool remove(Node_entry); //remove o elemento passado por parâmetro
        void print();
        void media();
        bool ordena();
	bool isinList(Node_entry); //verifica se um determinado elemento (passado por parâmetro) está na lista
};



#endif	/* _LINKEDLIST_H */

