void createElement(element * newElement, float x, float y, int type, float angle){
	newElement->x = x;
	newElement->y = y;
	newElement->type = type;
	newElement->angle = angle;
}

void inicializar_LE(listElements * entrada){
	entrada->elements = (element *) malloc(sizeof(element));
	entrada->size = 0;
}

void apresentar_LE(listElements * entrada){
	printf("Tamanho: %d\n", entrada->size);
	for (int i = 0; i < entrada->size; i++){
		printf("Tipo: %d | Ponto %d: (%.2f, %.2f) | Angulo: %.2f\n", 
				entrada->elements[i].type, i+1, entrada->elements[i].x, entrada->elements[i].y, entrada->elements[i].angle);
	}
}

void addElement_LE(listElements * entrada, float x, float y, int type, float angle){
	element aux;
	createElement(&aux, x, y, type, angle);

	entrada->elements = (element *) realloc(entrada->elements, (entrada->size + 1)*sizeof(element));
	entrada->size = entrada->size + 1;
	entrada->elements[entrada->size - 1] = aux;
}

void copyElement_LE(listElements * destino, listElements * origem){
	destino->elements = (element *) realloc(destino->elements, origem->size*sizeof(element));

	for (int i = 0; i < origem->size; i++){
		destino->elements[i] = origem->elements[i];
	}

	destino->size = origem->size;
}

void popElement_LE(listElements * entrada, float x, float y){
	listElements aux;
	inicializar_LE(&aux);

	for (int i = 0; i < entrada->size; i++){
		if ((entrada->elements[i].x != x) && (entrada->elements[i].y != y)){
			addElement_LE(&aux, entrada->elements[i].x, entrada->elements[i].y, entrada->elements[i].type, entrada->elements[i].angle);
		}	
	}

	copyElement_LE(entrada, &aux);
}

void popElementP_LE(listElements * entrada, int p){
	listElements aux;
	inicializar_LE(&aux);

	for (int i = 0; i < entrada->size; i++){
		if (i != p){
			addElement_LE(&aux, entrada->elements[i].x, entrada->elements[i].y, entrada->elements[i].type, entrada->elements[i].angle);
		}	
	}

	copyElement_LE(entrada, &aux);
}

int tamanho_LE(listElements * entrada){
	return entrada->size;
}

element getElement_LE(listElements * entrada, int i){
	return entrada->elements[i];
}

