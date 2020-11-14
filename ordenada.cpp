#include <iostream>
using namespace std;

struct node{
    int element;
    struct node *next;
};

void menu();
void InsertarLista(node *&, int);
void mostrarLista(node *);

node *lista = NULL;

int main(){
    
    menu();
    InsertarLista();
    mostrarLista(lista);


}

void menu(){
    int option, element;
    do{
        cout<<"---MENU---"<<endl;
        cout<<"1. Insertar elemento"<<endl;
		cout<<"2. Mostrar elementos"<<endl;
		cout<<"3. Salir"<<endl;
        cout<<"Ingrese una opcion:";
        cin>>option;
    }
    while(option != 3);

    switch(option){

        case 1: 
        cout<<"Digite un entero: ";
        cin>>element;
        InsertarLista(lista, element);
        break;
        case 2: mostrarLista(lista); break;

    }

}
void InsertarLista(node *&lista, int n){
    node *nuevo_nodo = new node();
    nuevo_nodo-> element = n;
    node *aux1 = lista;
    node *aux2;

    while((aux1 != NULL) && (aux1->element < n)){
        aux2 = aux1;
        aux1 = aux1->next;
    }
    if (lista == aux1)
    {
        lista = nuevo_nodo;
    }
    else
    {
        aux2->next= nuevo_nodo;
    }
    nuevo_nodo->next = aux1;



}

void mostrarLista(node *lista){
    node *nuevo = new node();
    nuevo = lista;

    while(nuevo != NULL){
        cout<<nuevo->element<<"--";
        nuevo = nuevo->next;
    }

}