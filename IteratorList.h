#ifndef __ITERATORLIST__H__
#define __ITERATORLIST__H__

#include "linkedList.h"
template<typename T>
class IteratorList;

template<typename T>
class IteratorList{
    private:
        LinkedList<T> stack;
        Node<T>* iterador;
    public:
        IteratorList(LinkedList<T>);
        bool HaveNext();
        void First();
        void Next();
        Node<T>* Current();
};

template<typename T>
IteratorList<T>::IteratorList(LinkedList<T> list){
    this->stack = list;
    this->iterador = stack.Begin();
}

template<typename T>
bool IteratorList<T>::HaveNext(){
    return (iterador != stack.End());
}

template<typename T>
void IteratorList<T>::First(){
    iterador=stack.Begin();
}

template<typename T>
void IteratorList<T>::Next(){
    iterador=iterador->getNext();
}

template<typename T>
Node<T>* IteratorList<T>::Current(){
    return iterador;
}
#endif