#ifndef __ITERATORLIST__H__
#define __ITERATORLIST__H__

#include "linkedList.h"
template<typename T>
class IteratorList;

template<typename T>
class IteratorList{
    private:
        Node<T>* iterator;
    public:
        IteratorList();
        IteratorList(Node<T>*);
        IteratorList(const IteratorList<T> &);
        IteratorList(IteratorList<T>&&);
        ~IteratorList();

        IteratorList<T> operator =(Node<T>*);
        IteratorList<T> operator =(const IteratorList<T>&);
        IteratorList<T> operator =(const IteratorList<T>&&);

        IteratorList<T> operator++(int);
        IteratorList<T> &operator++();
        IteratorList<T> operator+(int);
        IteratorList<T> operator+=(int);
        bool operator!=(Node<T>*);
        friend std::ostream& operator <<(std::ostream &out,IteratorList<T>& i){
            out<<*i;
            return out;
        }  

        T operator*();
};

//constructores____________________________________________________________________________

template<typename T>
IteratorList<T>::IteratorList(){
    this->iterator = nullptr;
}

template<typename T>
IteratorList<T>::IteratorList(Node<T>* node){
    this->iterator=node;
}

template<typename T>
IteratorList<T>::IteratorList(const IteratorList<T> &o){
    this->iterator = o.iterator;
}

template<typename T>
IteratorList<T>::IteratorList(IteratorList<T> &&o){
    this->iterator = o.iterator;
}

template<typename T>
IteratorList<T>::~IteratorList(){}

//sobrecargas__________________________________________________________________________________
template<typename T>
IteratorList<T> IteratorList<T>::operator =(Node<T>* o){
    this->iterator = o;
    return *this;
}

template<typename T>
IteratorList<T> IteratorList<T>::operator =(const IteratorList<T> &o){
    this->iterator = o.iterator;
    return *this;
}

template<typename T>
IteratorList<T> IteratorList<T>::operator =(const IteratorList<T> &&o){
    this->iterator = o.iterator;
    return *this;
}

template<typename T>
IteratorList<T> IteratorList<T>::operator ++(int){
    this->iterator = iterator->getNext();
    IteratorList<T> aux(this->iterator);
    return aux; 
}

template<typename T>
IteratorList<T> &IteratorList<T>::operator ++(){
    this->iterator = iterator->getNext();
    IteratorList<T> aux(this->iterator);
    return aux; 
}

template<typename T>
IteratorList<T> IteratorList<T>::operator +(int des){
    for(int i=0;i<des;i++){
        this->iterator=iterator->getNext();
    }
    IteratorList<T> aux(iterator);
    return aux;  
}

template<typename T>
IteratorList<T> IteratorList<T>::operator +=(int des){
    for(int i=0;i<des;i++){
        this->iterator=iterator->getNext();
    }
    IteratorList<T> aux(iterator);
    return aux;  
}

template<typename T>
bool IteratorList<T>::operator!=(Node<T>* node){
    return iterator!=node;
}

template<typename T>
T IteratorList<T>::operator*(){
    return iterator->getData();
}


#endif
