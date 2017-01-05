#include "ListaSDC.h"
#include <string>
#include <sstream>
#include <iostream>

ListaSDC::ListaSDC(bool esDoble, bool esCircular)
{
    //ctor
    largo = 0;
    head = NULL;
    tail = NULL;
    actual = NULL;
    this->esDoble = esDoble;
    this->esCircular = esCircular;
}

ListaSDC::~ListaSDC()
{
    //dtor
    head = NULL;
    tail = NULL;
    actual = NULL;
    largo = 0;
}

int ListaSDC::getSize(){
    return largo;
}

Nodo* ListaSDC::getHead(){
    return head;
}

Nodo* ListaSDC::getTail(){
    return tail;
}

Nodo* ListaSDC::getActual(){
    return actual;
}

void ListaSDC::append(int elem){
    Nodo* nuevo = new Nodo(elem);   // incorporar el elemento en un nodo
    if (head ==NULL){               // lista esta vacia
        head = nuevo;
    }
    else{
            tail->sig = nuevo;      // se agrega al final de la lista
    }
    actual = nuevo;
    tail = nuevo;
    largo++;
}

string ListaSDC::numberToString(int n){
    stringstream convert;       // stringstream used for the conversion
    convert << n;               //add the value of Number to the characters in the stream
    return convert.str();       //set Result to the content of the stream
}

string ListaSDC::show(){
    //Nodo* tmp = head;
    actual = head;
    string res = "";

    for ( int i = 1; i <= largo; i++){
        res = res + numberToString(actual->element)+ " ";
        actual = actual->sig;
    }
    return "Contenido de la Lista\n" + res + "\n";

}

/*find: retorna la posicion donde se localiza la primera aparicion del elem*/
int ListaSDC::find(int elem){
    if (head == NULL)
        return -1;  // lista vacia
    else{
        Nodo* tmp= head;
        //actual = head
        int c=1;
        while(tmp != NULL && tmp->element != elem){
            tmp=tmp->sig;
            c++;
        }
        if (tmp!=NULL)
            return c;
        else
            return -1;   // no lo encontró en la lista
    }

}

void ListaSDC::setActual (int posicion)
{
        if (posicion >=1 && posicion <= largo){
            actual = head;
            for (int c = 1; c < posicion; c++){
                actual = actual->sig;
            }
        }

}


void ListaSDC::insert (int posicion, int elemento){
    if (posicion == 1){
        Nodo* nuevo = new Nodo(elemento);
        nuevo->sig = head;
        if(esDoble)
            head->ant=nuevo;
        head = nuevo;
        actual = nuevo;
        largo++;
    }
    else
    if (posicion == largo + 1 ){
        append(elemento);
    }
    else{
        setActual(posicion - 1);
        Nodo* nuevo = new Nodo(elemento);
        nuevo->sig = actual->sig;
        actual->sig = nuevo;
        if(esDoble)
        {
            nuevo->sig->ant=nuevo;
            nuevo->ant=actual;
        }
        actual = nuevo;
        largo++;
    }
}

int ListaSDC::mayor()
{
    Nodo* tmp = head;
    int mayor = 0;
    while (tmp->sig != NULL){
    if (tmp->element > mayor )
        mayor = tmp->element;
    else
        tmp = tmp->sig;
    }
    return mayor;
}


int ListaSDC::menor()
{
    Nodo* tmp = head;
    int menor = tmp->element;
    while (tmp->sig != NULL){
    if (tmp->element < menor )
        menor = tmp->element;
    else
        tmp = tmp->sig;
    }
    return menor;
}

//retonra si esta o no asc ordenado
bool ListaSDC::isOrderedAsc(){
            actual = head;
            int cuenta=0;
            int current=1;
            int elemento = getActual()->element;

        if(largo == 0 ){ ///si la lista esta vacia

            return false;
        }

        else if(largo > 0) {                   ///Si la lista tiene muchos archivos, recorre la misma buscando el numero mayor
            setActual(current);
            elemento = getActual()->element;

            while(current<(largo+1)){
                setActual(current);
                if( elemento <= (getActual()->element) ){cuenta++;}
                current++;
                elemento = getActual()->element;
            }
            if(cuenta==largo){return true;}
            if(cuenta!=largo){return false;}
        }
}//fin del metodo ascendente
//retorna la cantidad de apariciones de determinado elemnto

int ListaSDC::apariciones(int num)
{
    Nodo* tmp = head;
    int i = 0;
    while (tmp != NULL)
        {
        if (tmp->element == num)
        {
           i++;
           tmp = tmp->sig;
        }
        else
         tmp = tmp->sig;

    }
    return i;
}


//para eleminar elementos de las listas
// hecho por la profe
void ListaSDC::remove()
{
    if (head!=NULL)
    {
        if (largo==1)
        {
        delete actual;
        head = NULL;
        actual = NULL;
        tail= NULL;
        largo=0;
        }
        else{
            if (actual == head){
                head = head->sig;
                delete actual;
                actual = head;
                largo--;
            }
            else{
                // toma al actual como el que va a borrar
                Nodo* borrar = actual;
                // debe ubicar al actual uno antes del que va a borrar


          actual = head;
                while (actual->sig != borrar){
                    actual= actual->sig;

                    if(esDoble&& borrar!=tail)
                    {
                        borrar->sig->ant=actual;
                    }
                }
                // desenlaza el nodo a borrar, asegurando que la lista queda continua
                actual->sig = borrar->sig;
                // actualiza la cola de la lista si va a borrar el ultimo
                if (borrar == tail)
                    tail = actual;

                // elimina el nodo a borrar
                delete borrar;
                largo--;
            }
        }
    }
}

//retorna las veces que se elimina un valor determinado
int ListaSDC::removeAll(int num)
{
    actual = head;
    int i=0;

    while(actual != NULL)
    {
        if(actual->element == num)
        {
            remove();
            i++;
        }
        else
            actual=actual->sig;
    }
    return i;
}

//Da la lista en reversa pero viendolo de atras hacia adeltante
void ListaSDC::reverse()
{
   Nodo * temporal = tail;

   while(temporal != head)
   {
       actual=head;
       while(actual->sig != temporal)
       {
           actual=actual->sig;
       }
       temporal->sig=actual;
       temporal=actual;
   }
   temporal->sig=NULL;
   head=tail;
   tail=temporal;
}

//acomoda repetidos

void ListaSDC::joinRepeteadElem()
{
    Nodo* current;
    Nodo* rec;
    actual=head;
    int n,m;

    while(actual!=NULL){
        m=actual->element;
        rec=actual->sig;
        current=actual;

        while(rec!=NULL){
            n=rec->element;

            if(n==m){
                while(current->sig != rec){
                    current =current->sig;
                }
                current->sig=rec->sig;
                rec->sig=actual->sig;
                actual->sig=rec;
                if(rec==tail){tail=current;}
                rec=current;

                break;
            }
            rec=rec->sig;

        }

        actual=actual->sig;
    }

}


//ELIMINA REPETIDOS
void ListaSDC::removeRepeteadElem()
{

    Nodo* tmp = head;
    while (tmp != NULL){

            Nodo* tmp2 = tmp->sig;

            while (tmp2 != NULL){

                if (tmp->element == tmp2->element){
                        actual = tmp2;
                        tmp2 = tmp2->sig;
                        remove();
                        }
                else
                    tmp2 = tmp2->sig;
                    }
            tmp = tmp->sig;
            }

}


bool ListaSDC::insertAsc(int num)
{
    if(isOrderedAsc()==false)
    {
        cout<<"No se puede agregar a la lista dado que no se encuentra ordenada"<<endl;
        return false;
    }
    else
    {
        actual=head;
        int i=0;

        while(actual!=NULL)
        {
            if(actual->element<= num && actual->sig->element>=num)
            {
                   insert(i-1,num);

                   return true;
            }

            else
            {
                actual=actual->sig;
                i+1;
            }
        }


    }
}


//Ordesimnar asctime
//void ListaSDC::getDesc()
//{
//       Nodo * tmp = head;
//       Nodo * tmp2 ;
//
//
//   while(head != NULL)
//   {
//       actual=head;
//       tmp2=actual->sig;
//
//
//            if(tmp > tmp2->element)

//            {
//
//                int tmp3=tmp2->element;
//                tmp2->element=tmp->element;
//                tmp->element=tmp3;
//            }
//            else
//            {
//              tmp2=tmp2->sig;
//            }
//
//
//
//
//    }
//}




//proyectp


//imetodo 2
Nodo* ListaSDC::soltar(int pos){
        Nodo* current;
        setActual(pos);
        current=head;

     if(largo==1){
        actual=NULL;
        tail=NULL;
        head=NULL;
        return current;
        largo--;
     }
      else {
            if(actual==head){
            head = head->sig;
            actual=head;
            current->sig=NULL;
            if(esDoble){actual->ant=NULL;}
            largo--;
            return current;
        }
      else if(actual==tail){
        current=tail;
        actual=head;
        while(actual->sig!=tail){actual=actual->sig;}
        tail=actual;
        tail->sig=NULL;
        if(esDoble){current->ant=NULL;}
        largo--;
        return current;
      }
      else  {
        current=actual;
        actual=head;
        while(actual->sig!=current){actual=actual->sig;}
        actual->sig=current->sig;
        if(esDoble){current->sig->ant = actual;current->ant=NULL;}
        current->sig=NULL;
        largo--;
        return current;
      }
      }

}//fin del metod.

void  ListaSDC::amarrar(Nodo* nuevo,int posicion){
        if (posicion == 1){
        nuevo->sig = head;
        if(esDoble){ head->ant=nuevo;nuevo->ant=NULL;}//para listas dobles
        head = nuevo;
        actual = nuevo;
        largo++;
    }
    else
    if (posicion == (largo + 1)){
            tail->sig=nuevo;
            if(esDoble){nuevo->ant=tail;}
            tail=nuevo;
            tail->sig=NULL;
            actual=tail;
            largo++;
    }
    else{  // posicion intermedia
        setActual(posicion-1);
        nuevo->sig = actual->sig;
        actual->sig = nuevo;
         if(esDoble){//este if es para listas dobles
                nuevo->sig->ant=nuevo;
                nuevo->ant =actual;
         }
        actual = nuevo;
        largo++;
    }
}

void ListaSDC::BubbleSort(){
    Nodo* next;
    Nodo* cosa;
    actual=head;
    next=actual->sig;
    long m;
    m=1;

    while(actual!= tail){

        if((next->element)<(actual->element)){
           cosa=soltar(m+1);
           amarrar(cosa,(m));
           setActual(m);
           next=actual->sig;
        }
        next=next->sig;
        actual=actual->sig;
        m++;
    }
if(isOrderedAsc()!=true){;BubbleSort();}
}//fin del metodo
///n/////////////////////////////////////////////////////////////////////
void ListaSDC::InsertSort( ){
      Nodo* current;
      Nodo* cosa;
      current=head;
      actual=head;
      int m=1;int n;
      while(current!= NULL){
        cout<<" 1.1";
        n=m;
        if(current==head) // Si current == head entonces la lista esta vacia
        {
            current=current->sig;
            m++;
            cout<<" 2.1";
        }
        else if(current!=head)
            {cout<<" 3.1";
           actual=current;
           cout<<" 3.3.1";
           while((actual->element)<(actual->ant->element)  )
           {cout<<" 4.1";

                    cosa=soltar(n);
                    n--;
                    amarrar(cosa,n);
                    setActual(n);

           }
           setActual(m);
           current=actual;
           current=current->sig;

           m++;
           cout<<" 5.1";
        }
      }
}///fin del metodo InsertSort
void ListaSDC::SelectionSort(){
    int m=1;int pos=1;actual=head;Nodo* lugar;Nodo*current;Nodo* cosa;int menor;

    while(actual!=NULL){
            menor=actual->element;
            //cout<<actual->element<<endl;
            //cout<<m<<endl;
            for(setActual(m);actual!=NULL;actual=actual->sig){
                if((menor)>(actual->element)){lugar=getActual();
                    menor=actual->element;
                   // cout<<actual->element<<"comparando"<<endl;
                    }
                else if((menor)==(actual->element)){
                        lugar=getActual();
                        menor=actual->element;
                        //cout<<actual->element<<"comparando"<<endl;
                }
                //cout<<actual->element<<"    en ciclo   "<<m<<endl;
            }
            //cout<<"el menor:  "<<menor<<endl;
            for(current=head;current!=lugar;current=current->sig){
                 //   cout<<"y"<<"";
                pos++;
            }
            //cout<<"posicion     "<<pos<<endl;
            cosa=soltar(pos);
            //cout<<"suelo   cosa     "<<cosa->element<<endl;
            amarrar(cosa,m);
            m++;
            setActual(m);
            pos=1;
                //cout<<show()<<endl;
    }

}//fin del metodo
