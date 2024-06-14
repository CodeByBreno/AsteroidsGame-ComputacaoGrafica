#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float x;
	float y;
	int type;
	float angle;
	float radius;
} element;

typedef struct{
	element * elements;
	int size;
} listElements;

#include "Asteroids/9 - EstruturasDeDados.cpp"

int main(){
	listElements teste;
	inicializar_LE(&teste);
	addElement_LE(&teste, 1.0f, -5.0f, 0, 0, 5);
	addElement_LE(&teste, -12.0f, 0.0f, 0, 0, 5);
	printf("\nLista 1:\n");	
	apresentar_LE(&teste);

	listElements outro_teste;
	inicializar_LE(&outro_teste);
	addElement_LE(&outro_teste, -10.0f, 8.0f, 0, 0, 5);
	printf("\nLista 2:\n");
	apresentar_LE(&outro_teste);

	copyElement_LE(&teste, &outro_teste);
	printf("\nLista 1(COPIA DA 2):\n");
	apresentar_LE(&teste);

	addElement_LE(&outro_teste, 15.0f, -5.0f, 0, 0, 5);
	printf("\nApos modificar Lista 2:\n");
	printf("Lista 1:\n");
	apresentar_LE(&teste);
	printf("\nLista 2:\n");
	apresentar_LE(&outro_teste);

	printf("\nTeste de Remocao do ponto (0.0f, -20.0f):\n");
	popElement_LE(&outro_teste, 0.0f, -20.0f);
	printf("\nNova Lista 2:\n");
	apresentar_LE(&outro_teste);

	printf("\nTentando remover um ponto que nao existe (-1.0f, 4.0f):\n");
	popElement_LE(&outro_teste, -1.0f, 4.0f);
	printf("\nLista 2:\n");
	apresentar_LE(&outro_teste);

	printf("\nAcessando todos os pontos da lista:\n");
	for (int i = 0; i < tamanho_LE(&outro_teste); i++){
		printf("(%.2f, %.2f)\n", getElement_LE(&outro_teste, i).x, getElement_LE(&outro_teste, i).y);
	}

	printf("\n");
	listElements teste3;
	inicializar_LE(&teste3);
	addElement_LE(&teste3, 10.0f, -1.0f, 0, 0, 5);
	addElement_LE(&teste3, -15.0f, 7.0f, 0, 0, 5);
	addElement_LE(&teste3, 7.0f, 8.0f, 0, 0, 5);
	addElement_LE(&teste3, -5.0f, -8.0f, 0, 0, 5);
	addElement_LE(&teste3, 12.0f, -40.0f, 0, 0, 5);
	apresentar_LE(&teste3);
	popElementP_LE(&teste3, 2);
	apresentar_LE(&teste3);
}


