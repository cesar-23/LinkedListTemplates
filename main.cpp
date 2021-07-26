#include <iostream>
#include "IteratorList.h"
using namespace std;

int main(){
    LinkedList<int> MyList;
    cout<<"El tamanho de la lista es: "<<MyList.getSize()<<"\n";
    MyList.PushBack(2);
    MyList.PushBack(4);
    MyList.PushFront(1);
    MyList.PushBack(5);
    MyList.InsertPos(3,3);
    for(int i=6;i<11;i++){
        MyList.PushBack(i);
    }
    cout<<"Lista impresa despues de inserciones: \n"<<MyList<<"\n";
    cout<<"El nuevo tamanho de la lista es: "<<MyList.getSize()<<"\n";
    MyList.RemoveBack();
    MyList.RemoveFront();
    MyList.RemovePos(5);
    cout<<"Lista impresa despues de modificaciones: \n"<<MyList<<"\n";
    cout<<"El nuevo tamanho de la lista es: "<<MyList.getSize()<<"\n";
    cout<<"Imprimiendo el primer y ultimo elemento\n";
    cout<<"Primer elemento: "<<*MyList.Begin()<<"\n";
    cout<<"Ultimo elemento: "<<*MyList.End()<<"\n";
    cout<<"//////////////////////////////////////////////////////////////////////\n";
    IteratorList<int> iterator;
    cout<<"imprimir mediante iterator: \n";
    for(iterator=MyList.Begin();iterator!=nullptr;iterator++){
        cout<<iterator<<" -> ";
    }
    return 0;

}
