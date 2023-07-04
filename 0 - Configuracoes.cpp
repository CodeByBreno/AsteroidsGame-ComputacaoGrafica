//
// Variáveis da Aplicação
// e Tipos Abstratos de Dados
//

typedef struct{
	float x;
	float y;
	int type;
	float angle;
} element;

typedef struct{
	element * elements;
	int size;
} listElements;

#define SHOOT_COUNTER 1
#define SMOOTH_COUNTER 30

float x_nave = 0.0f, y_nave = 0.0f, angulo_nave = 0.0f, r_nave = 0.0f;
int tipo_tiro = 0;
float x_test = 0.0f, y_test = 0.0f;
int counter_shoot = SHOOT_COUNTER;
int counter_smooth = 0;

listElements Tiros;
listElements Asteroides;

#define LARGURA_TELA 1920
#define ALTURA_TELA 1080 
int LARGURA_JANELA = 1000;
int ALTURA_JANELA = 600;
int LOG_LARGURA = 300;

int CANVA_X0 = -600.0f;
int CANVA_Y0 = -500.0f;
int CANVA_WIDTH = 1200.0f;
int CANVA_HEIGHT = 1000.0f;

#define DELTA_ROTATION 15.0f
#define DELTA_POSITION 4.0f
#define VELOCIDADE_TIRO 30.0f
#define VELOCIDADE_ASTEROIDE 4.0f

#define TEMPO_CRIACAO_ASTEROIDE 500
#define TEMPO_ATUALIZACAO_TELA 10
#define GARBAGE_TIME 10


