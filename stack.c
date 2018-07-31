#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
}nodo;

nodo* primero = NULL;

void insertarNodo(){
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf("Ingresa el dato del nuevo Nodo: ");
	scanf("%d",&nuevo->dato);

	nuevo->siguiente = primero;
	primero = nuevo;

}

void mostrarPila(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	printf("\n\tDatos en la pila\n");
	if(primero!=NULL){ //pila existe (tiene datos)
		while(actual!=NULL){ //recorremos pila
			printf("\n %d", actual->dato);
			actual = actual -> siguiente;
		}
	}else{
		printf("La pila esta vacia\n");
	}

}

void modificarNodo(){
	nodo *actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscadoM=0, encontrado=0;
	printf("Ingresa el nodo a modificar: ");
	scanf("%d",&nodoBuscadoM);
	if(primero!=NULL){
		while(actual!=NULL){ 
			if(actual->dato == nodoBuscadoM){
				printf("\n\tNodo a modificar encontrado\n");
				printf("Ingresa el nuevo valor: ");
				scanf("%d",&actual->dato);
				printf("\nNodo modificado\n");
				encontrado=1;
			}
			actual = actual -> siguiente;
		}
		if(!encontrado){
			printf("\t\nNodo no encontrado\n");
		}
	}else{
		printf("\n\tLa pila esta vacia\n");
	}
}

void eliminarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	nodo *anterior = (nodo*) malloc(sizeof(nodo));
	int nodoBuscado=0, encontrado=0,i=0;;
	printf("Ingresa el nodo a buscar para borrar: ");
	scanf("%d",&nodoBuscado);
	if(primero!=NULL){ 
		while(actual!=NULL){ 
			i++;
			if(actual->dato == nodoBuscado){
				printf("\t\nNodo con el dato (%d) fue encontrado en la posicion (%d) de la pila\n", nodoBuscado,i);
				if(actual == primero){
					primero = primero -> siguiente;
				}
				else{
					anterior -> siguiente = actual -> siguiente;
				}
				printf("El nodo ha sido eliminado\n");
				encontrado=1;
			}
			anterior = actual;
			actual = anterior -> siguiente;
		}
		if(!encontrado){
			printf("\t\nNodo no encontrado\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n\tLa pila esta vacia\n");
	}
}


//testing
void promedioPila(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int i=0,datos=0;
	printf("\n\tDatos en la pila\n");
	if(primero!=NULL){ 
		while(actual!=NULL){
			i++;
			datos += (int) actual->dato ;
			actual = actual -> siguiente;
		}
		printf("La media(promedio) de la pila es: %.2f\n",(float)datos/i);
	}else{
		printf("La pila esta vacia\n");
	}

}
// END TESTING



void buscarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado=0, encontrado=0,i=0;;
	printf("Ingresa el nodo a buscar: ");
	scanf("%d",&nodoBuscado);
	if(primero!=NULL){ 
		while(actual!=NULL){ 
			i++;
			if(actual->dato == nodoBuscado){
				printf("\t\nNodo con el dato (%d) fue encontrado en la posicion (%d) de la pila\n", nodoBuscado,i);
				encontrado=1;
			}
			actual = actual -> siguiente;
		}
		if(!encontrado){
			printf("\t\nNodo no encontrado\n");
		}
	}else{
		printf("\n\tLa pila esta vacia\n");
	}
}

void menu(){
	int opc;
	do{
	printf("\n\t1. Mostrar Pila\n");
	printf("\t2. Insertar nodo\n");
	printf("\t3. Buscar nodo\n");
	printf("\t4. Modificar nodo\n");
	printf("\t5. Borrar nodo\n");
	printf("\t6. Salir\n");
	printf("\nIngresa una opcion: ");
	scanf("%d",&opc);

		switch(opc){
			case 1:
					mostrarPila();
					break;
			case 2: 
					insertarNodo();
					break;
			case 3:
					buscarNodo();
					break;
			case 4:
					modificarNodo();
					break;
			case 5:
					eliminarNodo();
					break;
			case 7:
					promedioPila();
					break;
			case 6:
					printf("\t\nSaliendo...\n");
					break;

			default:
					printf("Opcion no valida :(\n");
		}	
	
	}while(opc!=6);

}

int main(){
	int i,nNodos=0;

	printf("Ingresa el tamaño de la pila(nodos a ingresar tamaño inicial): ");
	scanf("%d",&nNodos);

	for(i=0;i<nNodos;i++){
	insertarNodo();
	}

	mostrarPila();
	menu();

	return 0;
}
