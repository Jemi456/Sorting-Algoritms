#ifndef LISTASDC_H
#define LISTASDC_H
#include <string>
#include "Nodo.h"

using namespace std;

class ListaSDC
{
    public:
        ListaSDC(bool, bool );
        virtual ~ListaSDC();
        int getSize();
        Nodo* getHead();
        Nodo* getTail();
        Nodo* getActual();
        void append(int elem);
        string show();
        int find(int);
        // find devuelve la posicion donde el elemento de la primera aparicion
        void setActual (int);
        //setActual coloca el puntero actual de la lista en la posicion indicada
        void insert (int , int);
        // insert incorpora el elemento en la posicion indicada
        int mayor ();
        //regresa el elemento mayor
        int menor ();
        //regresa el menor
        bool isOrderedAsc();
        //funcion bool regresa si es  o no asc ordenado
        int apariciones(int);
        //regresa el numero de aparciones de un elemento en especifico
        void remove();

        //Para quitar elemento... agregago por la porfe******
        int removeAll(int);

        void reverse();
        void removeRepeteadElem();
        void joinRepeteadElem();
        bool insertAsc(int);
        //void getDesc();

        //Proyecto
        int menu();
        ListaSDC* crearLista(int);
        Nodo* soltar(int pos);
        void amarrar(Nodo*,int);
        void BubbleSort();
        void InsertSort();
        void SelectionSort();



    protected:
    private:
        int largo;
        Nodo* head;
        Nodo* tail;
        Nodo* actual;
        bool esDoble;
        bool esCircular;

        string numberToString(int);
};

#endif // LISTASDC_H
