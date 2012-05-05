#include "LinkedList.h"

Node::Node() {
    next = NULL;
}

Node::Node(Node_entry item, Node *add_on) {
    entry = item;
    next = add_on;
}

LinkedList::LinkedList(){
    front=NULL;
}

LinkedList::~LinkedList(){
    Node *prevNode,*currentNode;
    currentNode=front;
    prevNode=NULL;
    while(currentNode!=NULL){
        prevNode=currentNode;
        currentNode=currentNode->next;
        delete prevNode;
    }
    
}

bool LinkedList::isEmpty(){
    if (front == NULL) return true;
    return false;
}

bool LinkedList::insert(Node_entry el){
  Node *newNode, *prevNode, *currentNode;
  newNode = new Node(el);
  if(newNode == NULL) return false;
  prevNode = NULL;
  currentNode = front;
  while(currentNode!=NULL && el>currentNode->entry){
     prevNode = currentNode;
     currentNode = currentNode->next;
  }
  if(prevNode == NULL){
    newNode->next = front;
    front = newNode;
  }
  else{
    prevNode->next=newNode;
    newNode->next = currentNode;
  }
  return true;
}

bool LinkedList::insertpos(int pos,Node_entry el){
    int posCurrent=0;
    Node *newNode, *prevNode, *currentNode;
    newNode = new Node(el);
    if(newNode == NULL) return false;
    prevNode = NULL;
    currentNode = front;
    while (posCurrent!=pos){
        posCurrent++;
        prevNode = currentNode;
        currentNode=currentNode->next;
    }
    if(prevNode == NULL){
        newNode->next = front;
        front = newNode;
    }
    else{
        prevNode->next=newNode;
        newNode->next = currentNode;
    }
    return true;
}

void LinkedList::media(){
    int media=0,cont=0;
    Node *currentNode;
    currentNode=front;
    while( currentNode!= NULL){
        media=media+currentNode->entry;
        currentNode=currentNode->next;
        cont++;
    }
    media=media/cont;
    cout << "A media dos elementos da lista eh: " << media << endl;
}

int LinkedList::qtdEl(){
    Node *currentNode;
    int cont=0;
    currentNode=front;
    while(currentNode!=NULL){
        cont++;
        currentNode=currentNode->next;
    }
    return cont;
}

bool LinkedList::ordena(){
    int cont=0;
    Node *currentNode, *prevNode;
    Node_entry auxNode;
    if (qtdEl() == 1) return true;
    currentNode=front->next;
    prevNode=front;
    while (cont!=qtdEl()){
        while(currentNode!= NULL){
            if (currentNode->entry < prevNode->entry){
                auxNode=currentNode->entry;
                currentNode->entry=prevNode->entry;
                prevNode->entry=auxNode;
            }
            prevNode=currentNode;
            currentNode=currentNode->next;
        }
        cont++;
    }
    cout << "ordenou!!" << endl;
    return true;
}

bool LinkedList::isinList(Node_entry el){
    int pos=0;
    Node *newNode, *currentNode;
    newNode = new Node(el);
    if(newNode == NULL) return false;
    currentNode = front;
    while(currentNode!=NULL && el!=currentNode->entry){
        pos++;
        currentNode=currentNode->next;
    }
    if(currentNode == NULL){
        cout << "Nao foi encontrado o elemento desejado" << endl;
        return false;
    }
    cout << "encontramos o seu elemento e esta na posicao " << pos << endl;
    return true;


}

bool LinkedList::remove(Node_entry el){
  if(isEmpty()) return false;
  Node *prevNode=NULL, *currentNode=front;
  while(currentNode!=NULL && currentNode->entry!=el){
    prevNode = currentNode;
    currentNode = currentNode->next;
  }
  if(prevNode == NULL){//remove o front
        front = front->next;
		delete currentNode;
  }
  else if(currentNode==NULL) return false;//elemento não encontrado
  else{
     prevNode->next = currentNode->next;
     delete currentNode;
  }
  return true;
}

void LinkedList::print(){
    Node *currentNode;
    currentNode=front;
    while(currentNode!=NULL){
        cout << " " << currentNode->entry;
        currentNode=currentNode->next;
    }
    cout << endl;
}

