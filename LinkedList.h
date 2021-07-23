#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__

#include <iostream>
#include "Node.h"

template<typename T>
class LinkedList;

template<typename T>
class LinkedList{
    private:
        Node<T>* head;
        int size;
    public:
        LinkedList();
        LinkedList(T);
        LinkedList(const LinkedList<T>&);
        LinkedList(LinkedList<T> &&);
        LinkedList<T>& operator=(const LinkedList<T> &);
        LinkedList<T>& operator=(LinkedList<T>&&);
        ~LinkedList();
        
        //funciones
        void PushBack(T);
        void PushFront(T);
        void InsertPos(T,int);
        void RemoveBack();
        void RemoveFront();
        void RemovePos(int);
        Node<T>* End();
        Node<T>* Begin();

        //getter
        Node<T>* getHead();
        int getSize();
        //overload <<
        friend std::ostream &operator << (std::ostream &out, LinkedList &o){
            Node<T>* aux=o.getHead();
            while(aux!=nullptr){
                out<<*aux<<" -> ";
                aux=aux->getNext();
            }
            return out;
        }
};

//constructores
template<typename T>
LinkedList<T>::LinkedList(){
    this->head=nullptr;
    this->size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(T value){
    this->head=new Node<T>(value);
    this->size=1;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &o){
    this->head=nullptr;
    this->size=0;
    Node<T>* aux = o.head;
    while(aux!=nullptr){
        this->PushBack(aux->getData());
        aux=aux->getNext();
        this->size+=1;
    }
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&o){
    this->head=nullptr;
    this->size=0;
    Node<T>* aux = o.head;
    while(aux!=nullptr){
        this->PushBack(aux->getData());
        aux=aux->getNext();
        this->size+=1;
    }
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &o){
    this->head=nullptr;
    this->size=0;
    Node<T>* aux = o.head;
    while(aux!=nullptr){
        this->PushBack(aux->getData());
        aux=aux->getNext();
        this->size+=1;
    }
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &&o){
    this->head=nullptr;
    this->size=0;
    Node<T>* aux = o.head;
    while(aux!=nullptr){
        this->PushBack(aux->getData());
        aux=aux->getNext();
        this->size+=1;
    }
}

template<typename T>
LinkedList<T>::~LinkedList(){
    Node <T>*aux=nullptr;
    while (head!=nullptr){
        aux=head;
        head=head->getNext();
        delete aux;
    }
}

//funciones
template<typename T>
void LinkedList<T>::PushBack(T elem){
    Node<T>* new_node = new Node<T>(elem);
    Node<T>* aux=head;
    if(head==nullptr){
        head=new_node;
    }else{
        while(aux->getNext()!=nullptr){
            aux=aux->getNext();
        }
        aux->setNext(new_node);
    }
    size++;
}

template<typename T>
void LinkedList<T>::PushFront(T elem){
    Node<T>* new_node = new Node<T>(elem);
    new_node->setNext(head);
    head=new_node;
    size++;
}

template<typename T>
void LinkedList<T>::InsertPos(T elem,int pos){
    Node<T>* new_node = new Node<T>(elem);
    Node<T>* aux=head;
    Node<T>* aux2=head->getNext();
    int contador=1;
    if(pos >=0){
        if(head==nullptr){
            head=new_node;
            size++;
        }else{
            if(pos==0){
                PushFront(elem);
            }else{
                if(pos<=this->size+1){
                    while(contador < pos-1){
                        aux=aux->getNext();
                        aux2=aux2->getNext();
                        contador++;
                    }
                new_node->setNext(aux2);
                aux->setNext(new_node);
                size++;
                }else{
                    std::cout<<"Esa posicion es invalida, lista no fue modificada\n";
                }
            }
        }
    }else{
        std::cout<<"No es valido usar numeros negativos, lista no fue modificada\n";
    }
}

template <typename T>
void LinkedList<T>::RemoveBack(){
    Node<T>* aux = head;
    Node<T>* copy = nullptr;
    while(aux->getNext() !=nullptr){
        copy=aux;
        aux=aux->getNext();
    }
    delete aux;
    copy->setNext(nullptr);
    size--;
}

template <typename T>
void LinkedList<T>::RemoveFront(){
    Node<T>* aux=head->getNext();
    delete head;
    head = aux;
    size--;
}

template <typename T>
void LinkedList<T>::RemovePos(int pos){
    
    Node<T>* aux = head;
    Node<T>* copy = nullptr;
    int contador=1;
    if(pos>=0 && pos<=size){
        if(pos==0){
            RemoveFront();
        }
        if(pos==size){
            RemoveBack();
        }
        while(contador<pos){
            copy=aux;
            aux=aux->getNext();
            contador++;
        }
        copy->setNext(aux->getNext());
        delete aux;
        size--;
    }else{
        std::cout<<"Posicion no valida, lista no fue modificada\n";
    }
}

template<typename T>
Node<T>* LinkedList<T>::Begin(){
    return head;
}

template<typename T>
Node<T>* LinkedList<T>::End(){
    Node<T>* aux = head;
    if(aux==nullptr){
        return aux;
    }else{
        while(aux->getNext()!=nullptr){
            aux=aux->getNext();
        }
        return aux;
    }
}

//getter
template<typename T>
Node<T>* LinkedList<T>::getHead(){
    return head;
}

template<typename T>
int LinkedList<T>::getSize(){
    return size;
}



#endif