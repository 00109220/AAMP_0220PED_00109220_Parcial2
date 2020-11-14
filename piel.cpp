#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct nombreEstrato
{
  string estrato;
  float grosor;
};
typedef struct nombreEstrato nameEstrato;

stack<nameEstrato> capa;

void menu(stack<nameEstrato>& );
void Agregar(stack<nameEstrato>&);
void Eliminar(stack<nameEstrato>&);
void eliminarTodo(stack<nameEstrato>&);
float calcularGrosor(stack<nameEstrato>);

int main()
{
	stack<nameEstrato> piel;
  menu(piel);
	return 0;
}

void menu(stack<nameEstrato> &capa)
{
	int option;
	bool continuar = true;

	cout<<"-----MENU-----"<<endl;
	cout<<"Ingresa una opcion"<<endl;

	do{
		cout<<"1. Agregar una capa"<<endl;
		cout<<"2. Eliminar capa"<<endl;
		cout<<"3. Eliminar todas las capas"<<endl;
		cout<<"4. Calcular grosor de la capa"<<endl;
		cout<<"5. Salir"<<endl;
		cin>>option;cin.ignore();

		switch (option){
		case 1: Agregar(capa); break;
		case 2: Eliminar(capa); break;
		case 3: eliminarTodo(capa); break;
		case 4: cout << "El grosor total es " << calcularGrosor(capa) << endl; break;
		case 5: continuar = false; cout<<"Fin del programa"<<endl;
		default: break;
		}
	}while(continuar);
}

void Agregar(stack<nameEstrato> &capa){

  nameEstrato piel;
  cout<<"Ingrese el nombre de la piel: ";
  getline(cin, piel.estrato);
	do{
		cout<<"Ingrese el grosor de la piel. Debe de ser mayor a 0: ";
		cin >> piel.grosor;
	}while(piel.grosor <= 0);
	
  cin.ignore();
    
  capa.push(piel);
}

void Eliminar(stack<nameEstrato> &capa){
  cout<<"Eliminando la capa"<<endl;
  capa.pop();
}

void eliminarTodo(stack<nameEstrato> &capa){
	while(!capa.empty()){
		capa.pop();
  }
}

float calcularGrosor(stack<nameEstrato> capa){
  float total = 0;
  while(!capa.empty()){
    total += capa.top().grosor;
		capa.pop();
  }
	return total;
}