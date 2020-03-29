/*
* Name: Daniel Isaias Canales.
* Account: 31211013
* This project is in c ++ using data structures, implemented with
* binary trees and their respective methods of managing binary trees.
*/
#include <iostream> 
#include <string> 
#include <conio.h> 
#include <fstream>
#include <stdlib.h>
#include <string.h>

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};  

using namespace std;
void leer();
Nodo *crearNodo(int, Nodo *);
void insertarNodo(Nodo *&,int, Nodo *);
string token(string,string,int);
void mostrarArbol(Nodo *,int);
bool busqueda(Nodo *,int);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destruirNodo(Nodo *);
bool busquedaSimple(Nodo *,int);

Nodo *arbol = NULL;
int controles= 0;
int dateFather = 0;

int main(){
	int control = 0,dato,contador=0;
	do{
		system("cls");
		cout<<"1.Generar desde archivo y mostrar.\n"
			<<"2.Insertar Datos.\n"
			<<"3.Mostrar Arbol.\n"
			<<"4.Eliminar Nodo.\n"
			<<"5.Buscar Nodo.\n"
			<<"6.Salir.\n";	
		cin>>control;
		switch(control){
			case 1:{
				system("cls");
			
				
				if(*&arbol !=  NULL){
					*&arbol = NULL;
					leer();
					mostrarArbol(arbol,contador);
					
				}else {
					leer();
					mostrarArbol(arbol,contador);	
				}
				system("pause");
				break;
			}
			case 2:{
				system("cls");
				 cout<<"\nDigite un numero: ";
					cin>>dato;
					insertarNodo(arbol,dato,NULL);
				break;
			}
			case 3:{
				system("cls");
				mostrarArbol(arbol,contador);
				system("pause");
				break;
			}
			
			case 4:{
				system("cls");
			 cout<<"\nDigite el numero a eliminar: ";
				cin>>dato;
				if(busquedaSimple(arbol,dato)==true){
				eliminar(arbol,dato);
				cout<<"Dato eliminado.."<<endl;
				}else{
					system("cls");
					cout<<"No existe el dato ingresado."<<endl;
				
				}
				
				cout<<"\n";
				system("pause");
				break;
			}
			case 5:{
				system("cls");
				controles = 0;
				dateFather = 0;
				cout<<"\nDigite el elemento a buscar: ";
				cin>>dato;
				
				if(busqueda(arbol,dato) == true){
			//	cout<<"\nElemento "<<dato<<" a sido encontrado en el arbol\n";
				cout<<"Dato encontrado exitosamente..."<<endl;
				}
				else{
				cout<<"\nDato no encotrado\n";
				}
				system("pause");
				break;
			}
			
			case 6:{
				system("cls");
				cout << "Saliendo del Programa...." <<endl;
				system("pause");
				break;
			}
			
			default:{
				system("cls");
				cout<<"Opcion equivocada...";
				system("Pause");
				break;
			}
							
		}	
	}while(control!=6);
}


string token(string cadena, string divisor, int pos){
               if(cadena.size()>0){
                 char oracion[cadena.size()]; 
                 for (int i=0;i<=cadena.size();i++)
                 {oracion[i]=cadena[i];}                    
                 char *ptrtoken; 
                 int num=1;
                 const char* d=divisor.c_str();
                 ptrtoken = strtok(oracion , d);             
                 while(ptrtoken){
                     if(num==pos){ 
                        return ptrtoken;}                 
                     ptrtoken = strtok(NULL, d);
                     num++;}
                 return "";
               }else{return "";}
            }
            
            
            void leer(){
                 fstream Leer;
                 string linea;
                
                 
                 Leer.open("Proyecto1.txt"); 
                 while(! Leer.eof()){
                         getline(Leer,linea); 
                         if(linea.size()>0){     
							insertarNodo(arbol,atoi(token(linea,";", 1).c_str()),NULL);	                      
                           }
                  }     
                 Leer.close();}
                 
                 
     //Method that is responsible for creating the 
	 //node to add in the search binary tree.            
     //(funcion para crear un nuevo nodo)
     //version 1.0
    Nodo *crearNodo(int n,Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;
	
	return nuevo_nodo;
}

// funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol,int n,Nodo *padre){
	if(arbol == NULL){ // si esta vacio
		Nodo *nuevo_nodo = crearNodo(n,padre);
		arbol = nuevo_nodo;
	}
	else{ // si tiene uno o mas nodos el arbol
		int ValorRaiz = arbol->dato; // obtiene valor raiz
		if(n < ValorRaiz){ // si el elemento es menor a la raiz insertar izq
			insertarNodo(arbol->izq,n,arbol);
		}
		else{ //si el elemento es mayor a la raiz insertar derech
			insertarNodo(arbol->der,n,arbol);
		}
	}
}
            

// funcion para mostrar el arbol
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol == NULL){// si esta vacio arbol
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}                
                 
 // funcion para buscar en el arbol
bool busqueda(Nodo *arbol,int n){
	
	if(arbol == NULL){ // si esta vacio
		return false;
	}
	else if(arbol->dato == n){// si el nodo es igual al elemento
	controles++;
		cout<<"El nivel del nodo es : "<<controles<<endl;
	
		if(dateFather == 0){
			cout<<"El nodo del arbol no tiene padre."<<endl;
		}else{
			cout<<"El nodo padre es: "<<dateFather<<endl;
		}
		
		if(arbol->izq == NULL){
			cout<<"No tiene Hijo Izquierdo"<<endl;
		}else{
		cout<<"Hijo Izquierdo es: "<<arbol->izq->dato<<endl;	
		}
		
		if(arbol->der == NULL){
			cout<<"No tiene Hijo Derecho."<<endl;
		}else{
		cout<<"Hijo Derecho es: "<<arbol->der->dato<<endl;	
		} 
		
		
		return true;
	}
	else if(n < arbol->dato){
		controles++;
		dateFather = arbol->dato;
		return busqueda(arbol->izq,n);// busca los hijos izquierdos
	}
	else{
		controles++;
		dateFather = arbol->dato;
		return busqueda(arbol->der,n); // busca los hijos derechos
	}

}

//eliminar nodo en el arbol
void eliminar(Nodo *arbol,int n){
	if(arbol == NULL){ // si esta vacio arboñ
		return; // no hace nada 
	}
	else if(n < arbol->dato){// si el valor es menor
		eliminar(arbol->izq,n);// busca por la izq
	}
	else if(n > arbol->dato){// si el valor es mayor
		eliminar(arbol->der,n);// busca por la der
	}
	else{// si ya encontro el valor
		eliminarNodo(arbol);
	}
}  


// funcion para eliminar nodo encontrado
void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){//si el nodo tiene hijo izq y der
		Nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoEliminar->izq){// si tiene hijo der
		reemplazar(nodoEliminar,nodoEliminar->izq);
		destruirNodo(nodoEliminar);
	}
	else if(nodoEliminar->der){
		reemplazar(nodoEliminar,nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}
	else{// no tiene hijos
		reemplazar(nodoEliminar,NULL);
		destruirNodo(nodoEliminar);
	}
}

// funcion determinar el nodo mas izq posible
Nodo *minimo(Nodo *arbol){
	if(arbol == NULL){// si esta vacio arlbol
		return NULL;
	}
	if(arbol->izq){// si hay hijo izq
		return minimo(arbol->izq);// busca la parte minima izq
	}
	else{// si no tiene hijo izq
		return arbol;// retorna mismo nodo
	}
}

void reemplazar(Nodo *arbol,Nodo *nuevoNodo){
	if(arbol->padre){
		//arbol->padre hay que asignar su nuevo hijo
		if(arbol->dato == arbol->padre->izq->dato){
			arbol->padre->izq = nuevoNodo;
		}
		else if(arbol->dato == arbol->padre->der->dato){
			arbol->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		//prosede a signar su nuevo padre
		nuevoNodo->padre = arbol->padre;
	}
}

void destruirNodo(Nodo *nodo){
	nodo->izq = NULL;
	nodo->der = NULL;
	
	delete nodo;
}

bool busquedaSimple(Nodo *arbol,int n){
	
	if(arbol == NULL){ // si esta vacio
		return false;
	}
	else if(arbol->dato == n){// si el nodo es igual al elemento
		return true;
	}
	else if(n < arbol->dato){
		return busquedaSimple(arbol->izq,n);// busca los hijos izquierdos 
	}
	else{
		return busquedaSimple(arbol->der,n); // busca los hijos derechos
	}

}
