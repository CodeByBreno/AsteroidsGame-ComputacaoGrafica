
void DesenhaTiro(){
	glColor3f(0.0f, 1.0f, 0.5f);
	DrawRectangle(6.0f, 44.0f, 1.0f, 30.0f);
	DrawRectangle(-8.0f, 44.0f, 1.0f, 30.0f);
	DrawRectangle(15.0f, 42.0f, 1.0f, 36.0f);
	DrawRectangle(-17.0f, 42.0f, 1.0f, 36.0f);

	glColor3f(0.5f, 1.0f, 0.8f);
	DrawRectangle(7.0f, 44.0f, 1.0f, 30.0f);
	DrawRectangle(-7.0f, 44.0f, 1.0f, 30.0f);
	DrawRectangle(16.0f, 42.0f, 1.0f, 36.0f);
	DrawRectangle(-16.0f, 42.0f, 1.0f, 36.0f);
}

void DesenhaNaveTela(){
	glPushMatrix();
		glTranslatef(x_nave, y_nave, 0.0f);
		glRotatef(angulo_nave, 0.0f, 0.0f, 1.0f);
		DesenhaNave();
		DesenhaNaveHitbox();
	glPopMatrix();
}

void DesenhaTela(int value){
	glClear(GL_COLOR_BUFFER_BIT);

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

	//Desenhando a parte do Jogo
	glViewport(LOG_LARGURA, 0, LARGURA_JANELA - LOG_LARGURA, ALTURA_JANELA);
	DesenhaNaveTela();
	DrawRectangle(x_test, y_test, 30.0f, 30.0f);

	//Desenhando os Tiros
	for (int i = 0; i < Tiros.size; i++){
		element aux = getElement_LE(&Tiros, i);
		
		glPushMatrix();
			glTranslatef(aux.x, aux.y, 0.0f);
			glRotatef(aux.angle, 0.0f, 0.0f, 1.0f);
			DesenhaTiro();
		glPopMatrix();
	}

	glFlush();
}

void AtualizaTela(int value){
	x_test += 1.0f;
	y_test += 1.0f;
	//printf("teste\n");

	//Redesenho da Tela
	AtualizaEstado(0);
	DesenhaTela(0);

	//Chamada recursiva da função para garantir que seja executada múltiplas vezes
	glutTimerFunc(TEMPO_ATUALIZACAO_TELA, AtualizaTela, 1);
}

