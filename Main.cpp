//
// Vers�o Estilizada do jogo cl�ssico Asteroids
// Projeto Desenvolvido para Disciplina de Computa��o Gr�fica
// Ministrada pelo professor Jorge Cavalcanti
//
// Por Breno Gabriel e Hellian Sampaio
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gl/glut.h>
#include <Windows.h>

#include "0 - Configuracoes.cpp"
#include "Header.h"
#include "1 - Formas.cpp"
#include "2 - Nave.cpp"
#include "3 - Teclado.cpp"
#include "4 - DesenharElementos.cpp"
#include "5 - Monitoramento.cpp"
#include "6 - AtualizacaoEstado.cpp"
#include "7 - Sistema.cpp"
#include "8 - Auxiliares.cpp"
#include "9 - EstruturasDeDados.cpp"

int main(){
	//Inicializando as estruturas de dados
	inicializar_LE(&Tiros);

	//Setando o modo do OpenGL com apenas um buffer de cores e cor em RGB
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );

	//Criando uma janela no SO
	glutInitWindowPosition((int)(LARGURA_TELA/2 - LARGURA_JANELA/2), (int)(ALTURA_TELA/2 - ALTURA_JANELA/2));
	glutInitWindowSize(LARGURA_JANELA, ALTURA_JANELA);
	glutCreateWindow("Asteroids");

	//Setando a fun��o padr�o de desenho
	glutDisplayFunc(Desenha);

	//Setando a fun��o de callback para eventos do teclado
	glutKeyboardFunc(Keyboard);

	//Monitor de Eventos Especiais
	glutSpecialFunc(TeclasEspeciais);
	
	//Fun��o de Redimensionamento
	glutReshapeFunc(Reshape);

	//Fun��o de desenho da tela
	glutTimerFunc(TEMPO_ATUALIZACAO_TELA, AtualizaTela, 0);

	//Fun��o respons�vel por eliminar elementos fora da tela
	glutTimerFunc(GARBAGE_TIME, GarbageCollector, 0);

	Inicializar();

	//Loop de callback e captura de eventos
	glutMainLoop();
}
