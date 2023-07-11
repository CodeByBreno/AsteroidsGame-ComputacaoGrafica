//
//Atualiza��o de Estado
//

void AtualizaEstado(int value){
	if (counter_shoot < SHOOT_COUNTER) { counter_shoot++; }    //Um novo tiro s� poder� ser disparado quando o contador atingir o valor m�ximo (SHOOT_COUNTER)
	if (counter_smooth < SMOOTH_COUNTER) { counter_smooth++; } //A nave n�o para de imediato. Ap�s parar de move-l�, somente quando o contador chegar ao valor
                                                               //m�ximo, ela ir� parar totalmente

	AtualizaNave();
	AtualizaTiro();
	AtualizaAsteroide();
}

void AtualizaNave(){
	int signal;
	if (r_nave < 0){
		signal = -1;
	} else{
		signal = 1;
	}

	float dx = -r_nave*sin(Radian(angulo_nave));
	float dy = r_nave*cos(Radian(angulo_nave));
	//printf("dx=%.2f dy=%.2f\n", dx, dy);

	if (angulo_nave >= 360) angulo_nave -= 360;
	if (!NaveForaTela(dx, dy)){
		x_nave += dx;
		y_nave += dy;
	} 
	
	r_nave = signal*DELTA_POSITION*(1 - counter_smooth/SMOOTH_COUNTER);
}

void AtualizaTiro(){
	float dx, dy;
	printf("\nTiros:\n");
	apresentar_LE(&Tiros);

	for (int i = 0; i < Tiros.size; i++){
		dx = -VELOCIDADE_TIRO*sin(Radian(Tiros.elements[i].angle));
		dy = VELOCIDADE_TIRO*cos(Radian(Tiros.elements[i].angle));
		Tiros.elements[i].x += dx;
		Tiros.elements[i].y += dy;
	}
}

void AtualizaAsteroide(){
	float dx, dy;
	printf("\nAsteroides: \n");
	apresentar_LE(&Asteroides);

	for (int i = 0; i < Asteroides.size; i++){
		dx = -VELOCIDADE_ASTEROIDE*sin(Radian(Asteroides.elements[i].angle));
		dy = VELOCIDADE_ASTEROIDE*cos(Radian(Asteroides.elements[i].angle));
		Asteroides.elements[i].x += dx;
		Asteroides.elements[i].y += dy;
	}	
}

void CreateAsteroid(int value){

    unsigned long long seed = currentTimestampMillis();
    srand((unsigned)seed);

	int angle, randomNum, geracaoAsteroide = rand()%4;
	int tipoAsteroide = rand()%5;
	float x_asteroide, y_asteroide;

	float radius = hitboxRadius(tipoAsteroide);

	switch(geracaoAsteroide%4){
		case 0:
			randomNum = rand()%(CANVA_HEIGHT + 100);
			x_asteroide = CANVA_X0 + CANVA_WIDTH + 50;
			y_asteroide = (float)randomNum + CANVA_Y0;
			break;
		case 1:
			randomNum = rand()%(CANVA_HEIGHT + 100);
			x_asteroide = CANVA_X0 - 50;
			y_asteroide = (float)randomNum + CANVA_Y0;
			break;
		case 2:
			randomNum = rand()%(CANVA_WIDTH + 100);
			x_asteroide = (float)randomNum + CANVA_X0;
			y_asteroide = CANVA_Y0 - 50;
			break;
		case 3:
			randomNum = rand()%(CANVA_WIDTH + 100);
			x_asteroide = (float)randomNum + CANVA_X0;
			y_asteroide = CANVA_Y0 + CANVA_HEIGHT + 50;		
			break;
		default:
			printf("ERRO: Problema ao gerar um asteroide novo\n");
	}

	printf("NOVO ASTEROIDE CRIADO\n");
	angle = 180.0 - Degree(y_asteroide/x_asteroide);
	if (!game_start)
		addElement_LE(&Asteroides, x_asteroide, y_asteroide, tipoAsteroide, angle, radius);

	if (game_running == 1){
		glutTimerFunc(TEMPO_CRIACAO_ASTEROIDE, CreateAsteroid, 0);
	}
}
