#ifndef __NODE__H__
#define __NODE__H__


#include <iostream>

template <typename T>
class Node;

template <typename T>
class Node{
    private:
        T data;
        Node<T>* next;
    public:
        //constructores
        Node();
        Node(T);
        Node (const Node<T> &);
        Node(Node<T> &&);
        Node<T>& operator=(const Node<T> &);
        Node<T>& operator=(Node<T> &&);

        T getData()const;
        void setNext(Node<T>* next);
        Node<T>* getNext()const;
        ~Node();

        friend std::ostream &operator << (std::ostream &out, const Node<T> &o){
            out<<o.data;
            return out;
        }
};

//C. por defecto
template <typename T>
Node<T>::Node(){
    this-> T = 0;
    this->next = nullptr;
}

//C. por valor
template <typename T>
Node<T>::Node(T data){
    this->data=data;
    this->next=nullptr;
}

//C. copia
template <typename T>
Node<T>::Node(const Node<T> &o){
    this->next=o.next;
    this->data=o.data;
}

//C. mover
template <typename T>
Node<T>::Node(Node<T> &&o){
    this->next=o.next;
    this->data=o.data;
}

//sobrecarga de asignacion copia
template <typename T>
Node<T> &Node<T>::operator=(const Node<T> &o){
    this->next=o.next;
    this->data=o.data;
}

//sobrecarga de asignacion mover
template <typename T>
Node<T> &Node<T>::operator=(Node<T> &&o){
    this->next=o.next;
    this->data=o.data;
}

//getter and setter
template <typename T>
T Node<T>::getData()const{
    return data;
}

template <typename T>
void Node<T>::setNext(Node<T>* next){
    this->next=next;
}

template <typename T>
Node<T>* Node<T>::getNext()const{
    return this->next;
}

//desctructor
template <typename T>
Node<T>::~Node(){}

#endif