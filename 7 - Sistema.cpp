
void Inicializar(void){
	//Setando a cor de limpeza do buffer de cores
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//Setando a janela de trabalho
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(CANVA_X0, CANVA_X0 + CANVA_WIDTH, CANVA_Y0, CANVA_Y0 + CANVA_HEIGHT); //Mapeamento das dimensï¿½es da janela
}

void Desenha(void){
	DesenhaTela(0);
}

// Função callback chamada quando o tamanho da janela é alterado 
void Reshape(GLsizei w, GLsizei h)
{
    // Evita a divisao por zero
    if(h == 0) h = 1;

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

	//Modificando o tamanho da janela
	ALTURA_JANELA = h;
	LARGURA_JANELA = w;

    // Estabelece a janela de seleção (left, right, bottom, top)     
    if (w <= h){
		CANVA_HEIGHT = CANVA_WIDTH*h/(w - LOG_LARGURA);
	}else{
		CANVA_WIDTH = CANVA_HEIGHT*(w - LOG_LARGURA)/h;
	}
	
	printf("Configurações da nova ortho: (%.2f, %.2f) (%.2f, %.2f)\n", CANVA_X0, CANVA_X0 + CANVA_WIDTH, CANVA_Y0, CANVA_Y0 + CANVA_HEIGHT);
	printf("LOG_LARGURA = %.2f\n", LOG_LARGURA);
	printf("CANVA_WIDTH = %.2f\n", CANVA_WIDTH);
	printf("CANVA_HEIGHT = %.2f\n\n", CANVA_HEIGHT);
    gluOrtho2D(CANVA_X0, CANVA_X0 + CANVA_WIDTH, CANVA_Y0, CANVA_Y0 + CANVA_HEIGHT);
}

void EndGame(){
	game_running = 0;
}

void AtualizaTela(int value){
	//Chamada recursiva da função para garantir que seja executada múltiplas vezes
	if (game_running == 1){
		//Redesenho da Tela
		AtualizaEstado(0);
		CollisionDetector();
		DesenhaTela(0);

		glutTimerFunc(TEMPO_ATUALIZACAO_TELA, AtualizaTela, 1);
	} 
}


