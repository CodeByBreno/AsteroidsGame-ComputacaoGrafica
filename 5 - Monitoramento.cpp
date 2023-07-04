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

		//Tiro saiu da tela, deve ser removido da lista de tiros
		if ((aux.x >= 650) || (aux.x <= -650) || (aux.y >= 550) || (aux.y <= -550)){
			popElementP_LE(&Tiros, i);
		}
	}

	for (int i = 0; i < tamanho_LE(&Asteroides); i++){
		element aux = getElement_LE(&Asteroides, i);

		//Tiro saiu da tela, deve ser removido da lista de tiros
		if ((aux.x >= 660) || (aux.x <= -660) || (aux.y >= 560) || (aux.y <= -560)){
			popElementP_LE(&Asteroides, i);
		}
	}

	glutTimerFunc(GARBAGE_TIME, GarbageCollector, 0);
}
