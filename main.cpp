#include <iostream>
#include "ListaSDC.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

ListaSDC* elementos();
ListaSDC* crearLista(int cantidad);


ListaSDC* crearLista(int cantidad)
{
ListaSDC * simpleL = new ListaSDC(true, true);
srand(time(NULL));


    int n = 0;

     for(int i=0;i<cantidad;i++)
     {
         n = rand()%10000+1;
         simpleL->append(n);
     }
     //cout<<simpleL->show();
     return simpleL;
}
void insertion()
{   cout<<"0";
    ListaSDC* simpleL = elementos();
    cout<<"1";
    simpleL->InsertSort();
    cout<<"2";
    cout << simpleL->show();
}

void bubble()
{
    ListaSDC* simpleL = elementos();

    simpleL->BubbleSort();
    cout<<" "<<endl;
    cout << simpleL->show() << endl;
}
void selection()
{
    ListaSDC* simpleL = elementos();

    simpleL->SelectionSort();
    cout<<" "<<endl;
    cout << simpleL->show() << endl;
}



ListaSDC* elementos()
{
    int cantidad=0;
    cout << " " << endl;
    cout << " " << endl;
    cout<<"Los grupos de elementos pueden ser 50, 100, 200, 500, y 1000. "<<endl;
    cout << " " << endl;
    cout<<"Digite la cantidad de elementos que desea ordenar"<<endl;
    cin>>cantidad;
    cout<<" "<<endl;
    if(cantidad==50||cantidad==100||cantidad==200||cantidad==500||cantidad==1000)
    {
        ListaSDC* simpleL = crearLista(cantidad);
        cout<<simpleL->show();
        return simpleL;
    }
    else{
        cout<<"Los numeros deben ser: 50, 100, 200, 500, o 1000."<<endl;
        elementos();
    }
}




int menu ()
{
    int opcion=0;
    do{
        cout << "* * * * * * * Primer Proyecto Programado * * * * * * *" << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout<<"Ingrese el numero del metodo que desea emplear : "<<endl;
        cout << " " << endl;
        cout<<"1.BubbleSort"<<endl;
        cout<<"2.Insert Sort"<<endl;
        cout<<"3.Selection Sort"<<endl;
        cout <<"4.Shell Sort" << endl;
        cout << "5.Radix Sort" << endl;
        cout << "0. Salir" << endl;//problemas al salir no sale xD

        cout << " " << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << "Ingresar opcion: " << endl;

        cout << " " << endl;
        cin >> opcion;
        cout << " " << endl;
    }
    while (opcion>5);
    {
        return opcion;
    }
}


int main()
{
 int opcionUsr = 0;
    do{
        opcionUsr = menu();
        switch ( opcionUsr )
        {
            case 1 : bubble(); break;
            case 2 :insertion();break;
            case 3 : selection(); break;
            //case 4: shellSort(); break;
            //case 4: radixsort(); break;
        }
    }
    while (opcionUsr != 0 );
    return 0;






  // cout << "Demo Listas Simples, Dobles y Circulares!" << endl;

//    Creando una  lista simple lineal
//    ListaSDC * simpleL = new ListaSDC(false, false);



 /*   simpleL->append(12);
    simpleL->append(13);
    simpleL->append(60);
    simpleL->append(64);
    simpleL->append(70);
    simpleL->append(80);
    simpleL->append(87);
    simpleL->append(100);

    cout << simpleL->show() << endl;

    int numero = 30;
    cout << "El "<< numero << " esta en posicion " << simpleL->find(numero) << endl;
    cout<< " "<<endl;

    simpleL->setActual(4); // 40 poscion actual
    if (simpleL->getActual() != NULL){
        cout << simpleL->getActual()->element << endl;
    }
    else
        cout << "Posicion incorrecta." << endl;


    simpleL->insert(5,57);
    simpleL->insert(2,18);
    simpleL->insert(2,18);
    simpleL->insert(1,57);

    cout << simpleL->show() << endl;

    EJERCICIOS TAREA 3 Y 4

    brinda numero mayor y menor de la lista

    cout << "El mayor elemento de la lista es el numero: " <<endl;

    cout << simpleL->mayor() << endl;
    cout<<" "<<endl;

    cout << "El elemento menor de la lista es el : " <<endl;

    cout << simpleL->menor() << endl;
    cout<<" "<<endl;



    //saber si  esta ordenada asc

    if (simpleL->isOrderedAsc() == true){
        cout<< " "<<endl;
        cout << "La lista se encuentra ordenada ascendiente." << endl;
        cout<< " "<<endl;
    }
    else
    {


        cout<< " "<<endl;
        cout << "La lista no se encuentra ordenada ascendiente" << endl;
        cout<< " "<<endl;

    }



cuantas repeticiones hay de un num definido

    cout << "El elemento 60 tiene " <<endl;
    cout << simpleL->apariciones(60) << " apariciones." << endl;
    cout<< " "<<endl;


    ejemplo de la profe para eliminar

    Incorporar este codigo para probar la eliminación en el programa principa/

    Probando remover el elemento actual de la lista,

    coloca el actual al inicio de la lista
    simpleL->setActual(1);
    simpleL->remove();
    cout<< " "<<endl;
    cout << "Luego de borrar el inicio, " << simpleL->show() << endl;
    cout<< " "<<endl;

    coloca el actual al final de la lista
    simpleL->setActual(simpleL->getSize());
    simpleL->remove();
    cout<< " "<<endl;
    cout << "Luego de borrar el ultimo, " << simpleL->show() << endl;

     coloca al segundo elemento como actual
    simpleL->setActual(2);   // haciendo del 40 el actual
    if (simpleL->getActual() != NULL){
            cout << simpleL->getActual()->element << endl;
            simpleL->remove();
            cout<< " "<<endl;
            cout << "Luego de borrar el segundo de la lista, " << simpleL->show() << endl;
        }
    else
        cout << "Posicion incorrecta" << endl;
        cout<< " "<<endl;

    cout<<"Se elimino el elemento 20, cantidad "<<
    simpleL->removeAll(20)<<" VECES"<<endl;
    cout<< " "<<endl;

    simpleL->reverse();
    cout<<"La lista en reversa es : "<<
    simpleL->show()<<endl;

    simpleL->joinRepeteadElem();
    cout<<"La lista acomodada seria con elementos repetidos: "<<
    simpleL->show()<<endl;

    simpleL->removeRepeteadElem();
    cout<<"La lista sin repeticiones es: "<<
    simpleL->show()<<endl;



    simpleL->insertAsc(58);
    cout<<"La nueva lista agregando el elemento es: "<<
    simpleL->show();





    simpleL->getDesc();
    cout<<"La lista ordenada descendentemente es: "<<
    simpleL->show()<<endl;

    */
    //Fin primera parte

}




