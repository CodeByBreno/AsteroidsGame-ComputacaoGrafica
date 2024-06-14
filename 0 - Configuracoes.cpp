//
// Vari�veis da Aplica��o
// e Tipos Abstratos de Dados
//

typedef struct{
	float x;
	float y;
	int type;
	float angle;
	float radius;
} element;

typedef struct{
	element * elements;
	int size;
} listElements;

typedef struct{
	float x;
	float y;
} point;

#define SHOOT_COUNTER 5
#define SMOOTH_COUNTER 30

float x_nave = 0.0f, y_nave = 0.0f, angulo_nave = 0.0f, r_nave = 0.0f;
float hitbox_nave = 20.0f;
int tipo_tiro = 0;
float x_test = 0.0f, y_test = 0.0f;
int counter_shoot = SHOOT_COUNTER;
int counter_smooth = 0;
int game_running = 1, game_start = 1;
int player_score = 0;
int fullScreen = 0;

listElements Tiros;
listElements Asteroides;

#define LARGURA_TELA 1280
#define ALTURA_TELA 720
int LARGURA_JANELA = 800;
int ALTURA_JANELA = 500;
int LOG_LARGURA = 300;

int CANVA_X0 = -600.0f;
int CANVA_Y0 = -500.0f;
int CANVA_WIDTH = 1200.0f;
int CANVA_HEIGHT = 1000.0f;

#define DELTA_ROTATION 20.0f
#define DELTA_POSITION 5.0f
#define VELOCIDADE_TIRO 30.0f
#define VELOCIDADE_ASTEROIDE 4.0f

#define TEMPO_CRIACAO_ASTEROIDE 200
#define TEMPO_ATUALIZACAO_TELA 10
#define GARBAGE_TIME 10

#define HITBOX_AST0 45
#define HITBOX_AST1 40
#define HITBOX_AST2 40
#define HITBOX_AST3 18
#define HITBOX_AST4 50

#define LOG_LEFT_PADDING 50.0f
#define LOG_RIGHT_PADDING 50.0f
#define LOG_TOP_PADDING 15.0f
#define LOG_DOWN_PADDING 15.0f

#define LPAD_SCORE 80.0f
#define TPAD_SCORE 50.0f

#define LPAD_BOX_SCORE 60.0f
#define TPAD_BOX_SCORE 100.0f
#define HEIGHT_BOX_SCORE 60.0f

#define FONTE_PADRAO GLUT_BITMAP_TIMES_ROMAN_24
#define FONTE_PEQUENA GLUT_BITMAP_HELVETICA_18

#define CAN_DIE 1
