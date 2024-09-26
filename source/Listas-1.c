#include <stdio.h>
#include <string.h>
#include <stdlib.h>/*Para uso de malloc*/
struct nodo { /*Definimos nuestra estructura nodo (Puede tener cualquier nombre)*/
	int CoordX;
	int CoordY;
	struct nodo *next;/*importante que uno de los miembros sea un puntero al mismo tipo de estructura (para poder apuntar a la siguiente)*/
}INICIO;
/*INICIO1 va a ser nuestro nodo inicial ya que le insertaremos a la derecha
FIN2 va a ser el nodo final de la segunda FIN ya que le insertaremos a la izquierda*/
	
struct nodo *insertarDespuesDe (struct nodo *actual);
void grabarPunto (struct nodo *actual, int x, int y);

int main() {
	int i;
	struct nodo  *FIN, *temp;
	FIN = &INICIO; FIN->next = NULL;	
	
	/*Crea e inserta 10 nodos*/
	for (i=0; i<10; i++) {	
		/*Se van insertando nodos a la derecha de la primer FIN*/
		FIN=insertarDespuesDe (FIN);
			
		/*Se le asigna un valor a los miembros del nuevo nodo*/
		grabarPunto (FIN, i, i);
			
	}
	
	printf("FIN creada con despu�s de:\n");
	temp=&INICIO;
	while(temp!=NULL){
		printf("DD:\tX:%d Y:%d\n\n", temp->CoordX, temp->CoordY);
		temp=temp->next; /*notar como recorremos la FIN aqui*/
	}
	getch();
}

struct nodo *insertarDespuesDe (struct nodo *actual) { 
	struct nodo *nuevo = (struct nodo *) malloc (sizeof (struct nodo));
	actual->next=nuevo;/*Definimos el siguiente como nuestro nuevo nodo*/
	nuevo->next=NULL;
	return nuevo;/*Retorno de la nueva �ltima posici�n*/
}

void grabarPunto (struct nodo *actual, int x, int y){ 
	/*Esta funci�n hace lo mismo que har�a acceder a los miembros directamente,
	pero debemos pensar que por ejemplo, podr�a leer datos de alg�n otro lado como
	un puerto serie en lugar de cargarlos por par�metro
	*/
	actual ->CoordX = x;
	actual ->CoordY = y;
}
