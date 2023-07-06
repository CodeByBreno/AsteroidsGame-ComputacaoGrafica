//Monitoramento de Condições
int NaveForaTela(float dx, float dy){
	if ((x_nave + dx < CANVA_X0) | (x_nave + dx > CANVA_X0 + CANVA_WIDTH)){
		return 1;
	}
	if ((y_nave + dy < CANVA_Y0) | (y_nave + dy > CANVA_Y0 + CANVA_HEIGHT)){
		return 1;
	}
	return 0;
}

void GarbageCollector(int value){
	for (int i = 0; i < tamanho_LE(&Tiros); i++){
		element aux = getElement_LE(&Tiros, i);

		//Tiro saiu da tela, deve ser removido da lista de TIROS
		if ((aux.x >= CANVA_X0 + CANVA_WIDTH + 100) || (aux.x <= CANVA_X0 - 100) 
			|| (aux.y >= CANVA_Y0 + CANVA_HEIGHT + 100) || (aux.y <= CANVA_Y0 - 100)){
			popElementP_LE(&Tiros, i);
		}
	}

	for (int i = 0; i < tamanho_LE(&Asteroides); i++){
		element aux = getElement_LE(&Asteroides, i);

		//Tiro saiu da tela, deve ser removido da lista de ASTEROIDES
		if ((aux.x >= CANVA_X0 + CANVA_WIDTH + 100) || (aux.x <= CANVA_X0 - 100) 
			|| (aux.y >= CANVA_Y0 + CANVA_HEIGHT + 100) || (aux.y <= CANVA_Y0 - 100)){
			popElementP_LE(&Asteroides, i);
		}
	}

	glutTimerFunc(GARBAGE_TIME, GarbageCollector, 0);
}

void CollisionDetector(){
	for (int i = 0; i < Tiros.size; i++){
		element disparo = Tiros.elements[i];
		for (int j = 0; j < Asteroides.size; j++){
			element asteroid = Asteroides.elements[j];
			if (distance(disparo.x, disparo.y, asteroid.x, asteroid.y) <= asteroid.radius){
				popElement_LE(&Asteroides, asteroid.x, asteroid.y);
				popElement_LE(&Tiros, disparo.x, disparo.y);
			}
		}
	}
}
