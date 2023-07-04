
void DesenhaNaveTela(){
	glPushMatrix();
		glTranslatef(x_nave, y_nave, 0.0f);
		glRotatef(angulo_nave, 0.0f, 0.0f, 1.0f);
		DesenhaNave();
		DesenhaNaveHitbox();
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
			DesenhaAsteroide();
		glPopMatrix();
	}
}

void DesenhaLog(){
	//Desenhando o log do jogo
	glViewport(0, 0, LOG_LARGURA, ALTURA_JANELA);
	glBegin(GL_QUADS);
		glColor3f(0.95, 0.0, 0.55);
		glVertex2f(CANVA_X0, CANVA_Y0 + CANVA_HEIGHT);
		glVertex2f(CANVA_X0 + CANVA_WIDTH, CANVA_Y0 + CANVA_HEIGHT);
		glColor3f(0.09, 0.0, 0.62);
		glVertex2f(CANVA_X0 + CANVA_WIDTH, CANVA_Y0);
		glVertex2f(CANVA_X0, CANVA_Y0);	
	glEnd();
}

void DesenhaTela(int value){
	glClear(GL_COLOR_BUFFER_BIT);

	//Desenhando o log do Jogo
	DesenhaLog();

	//Desenhando a parte do Jogo
	glViewport(LOG_LARGURA, 0, LARGURA_JANELA - LOG_LARGURA, ALTURA_JANELA);

	//A Nave
	DesenhaNaveTela();

	//Desenhando os Tiros
	DesenhaTiroTela();

	//Desenha os Asteroides
	DesenhaAsteroideTela();

	glFlush();
}

void AtualizaTela(int value){

	//Redesenho da Tela
	AtualizaEstado(0);
	DesenhaTela(0);

	//Chamada recursiva da função para garantir que seja executada múltiplas vezes
	glutTimerFunc(TEMPO_ATUALIZACAO_TELA, AtualizaTela, 1);
}

