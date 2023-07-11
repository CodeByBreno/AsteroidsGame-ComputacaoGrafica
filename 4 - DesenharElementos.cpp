
void DesenhaGameStart(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	DesenhaTexto("ASTEROIDS", 0.0f, 0.0f);
	DesenhaTextoPequeno("Aperte Espaco para comecar", -50.0f, -30.0f);
	glFlush();
}

void DesenhaGameOver(){
	char scoreText[30];
	sprintf(scoreText, "Score : %d", player_score);
	glColor4f(0.3f, 0.3f, 0.3f, 1.0f);
	DrawRectangle(CANVA_X0, CANVA_Y0, CANVA_WIDTH, CANVA_HEIGHT);
	glColor3f(0.0f, 1.0f, 0.0f);
	printf("DIMENSOES DA JANELA = %d %d", LARGURA_JANELA, ALTURA_JANELA);
	DrawRectangleBorder(-0.02*LARGURA_JANELA, 0.1*ALTURA_JANELA, 0.2*LARGURA_JANELA, 0.18*ALTURA_JANELA);
	DesenhaTexto("GAME OVER!\n", 0.015*LARGURA_JANELA, 0.02*ALTURA_JANELA);
	DesenhaTexto(scoreText, 0.035*LARGURA_JANELA, -0.03*ALTURA_JANELA);
}

void DesenhaNaveTela(){
	glPushMatrix();
		glTranslatef(x_nave, y_nave, 0.0f);
		glRotatef(angulo_nave, 0.0f, 0.0f, 1.0f);
		DesenhaNave();
	glPopMatrix();
}

void DesenhaTiroTela(){
	for (int i = 0; i < Tiros.size; i++){
		element aux = getElement_LE(&Tiros, i);
		
		glPushMatrix();
			glTranslatef(aux.x, aux.y, 0.0f);
			glRotatef(aux.angle, 0.0f, 0.0f, 1.0f);
			DesenhaTiro();
		glPopMatrix();
	}
}

void DesenhaAsteroideTela(){	
	for (int i = 0; i < Asteroides.size; i++){
		element aux = getElement_LE(&Asteroides, i);
		
		glPushMatrix();
			glTranslatef(aux.x, aux.y, 0.0f);
			glRotatef(aux.angle, 0.0f, 0.0f, 1.0f);
			DesenhaAsteroide(aux.type);
		glPopMatrix();
	}
}

void DesenhaLog(){
	//Desenhando o log do jogo
	float x0 = CANVA_X0 + LOG_LEFT_PADDING, y0 = -1*CANVA_Y0 - LOG_TOP_PADDING; 
	float w = CANVA_WIDTH - LOG_LEFT_PADDING - LOG_RIGHT_PADDING;
	float h = CANVA_HEIGHT - LOG_TOP_PADDING - LOG_DOWN_PADDING;

	glViewport(0, 0, LOG_LARGURA, ALTURA_JANELA);

	glColor3f(0.0f, 1.0f, 0.0f);
	DrawRectangleBorder(x0, y0, w, h);

	glColor3f(1.0f, 1.0f, 1.0f);
	DesenhaTexto("Score", x0 + LPAD_SCORE, y0 - TPAD_SCORE);

	glColor3f(0.0f, 1.0f, 0.0f);
	DrawRectangleBorder(x0 + LPAD_BOX_SCORE, y0 - TPAD_BOX_SCORE, w - 2*LPAD_BOX_SCORE, HEIGHT_BOX_SCORE);

}

void DesenhaScoreTela(){
	char textoScore[30];
	glColor3f(0.0f, 1.0f, 0.0f);
	sprintf(textoScore, "Score : %d", player_score);
	DesenhaTexto(textoScore, CANVA_X0 + 50.0, CANVA_Y0 + CANVA_HEIGHT - 100.0f);
}

void DesenhaTela(int value){
	glClear(GL_COLOR_BUFFER_BIT);

	//Desenhando o log do Jogo
	//DesenhaLog();

	//Desenhando a parte do Jogo
	//glViewport(LOG_LARGURA, 0, LARGURA_JANELA - LOG_LARGURA, ALTURA_JANELA);
	glViewport(0, 0, LARGURA_JANELA, ALTURA_JANELA);

	//A Nave
	DesenhaNaveTela();

	//Desenhando os Tiros
	DesenhaTiroTela();

	//Desenha os Asteroides
	DesenhaAsteroideTela();

	//Debugger das bordas
	borderDebugger();

	//Desenha o Score
	DesenhaScoreTela();

	//Tela de Game Over
	if (game_running == 0) DesenhaGameOver();
	
	//Desenha Tela inicial
	if (game_start == 1) DesenhaGameStart();

	glutSwapBuffers();
}
