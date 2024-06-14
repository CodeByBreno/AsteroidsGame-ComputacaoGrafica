#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gl/glut.h>

#define LARGURA_TELA 1280
#define ALTURA_TELA 720 
#define LARGURA_JANELA 600
#define ALTURA_JANELA 600
#define CIRCLE_PRECISION 1000

#define WINDOW_X -300.0f
#define WINDOW_Y -300.0f
#define WINDOW_WIDTH 600.0f
#define WINDOW_HEIGHT 600.0f

#define DELTA_ROTATION 10.0f
#define DELTA_POSITION 10.0f

float x_nave = 0.0f, y_nave =  0.0f;

void DrawHorizontalTracing(float x0, float y0, float width, float height, float increment){
	glBegin(GL_LINES);
	for (int i = 0; increment*i < height; i++){
		glVertex2f(x0 , y0 - i*increment);
		glVertex2f(x0 + width, y0 - i*increment);	
	}
	glEnd();
}

void DrawVerticalTracing(float x0, float y0, float width, float height, float increment){
	glBegin(GL_LINES);
	for (int i = 0; increment*i < height; i++){
		glVertex2f(x0 - i*increment, y0 );
		glVertex2f(x0 - i*increment, y0 + width);	
	}
	glEnd();
}

void DrawRectangleBorder(float x0, float  y0, float width, float height){
	glBegin(GL_LINE_LOOP);
		glVertex2f(x0, y0);
		glVertex2f(x0 + width, y0);
		glVertex2f(x0 + width, y0 - height);
		glVertex2f(x0, y0 - height);
	glEnd();
}

void DrawRectangle(float x0, float  y0, float width, float height){
	glBegin(GL_QUADS);
		glVertex2f(x0, y0);
		glVertex2f(x0 + width, y0);
		glVertex2f(x0 + width, y0 - height);
		glVertex2f(x0, y0 - height);
	glEnd();
}

void DrawTrapezoid(float x0, float y0, float big_w, float small_w, float height){
	glBegin(GL_QUADS);
		glVertex2f(x0, y0);
		glVertex2f(x0 + big_w, y0);
		glVertex2f(x0 + small_w, y0 - height);
		glVertex2f(x0, y0 - height);		
	glEnd();
}

void DrawCircle(float r, float x0, float y0){
    int precision = CIRCLE_PRECISION;
	float a = (float) 360/precision; //Taxa de variacao do angulo
	glBegin(GL_POLYGON);
		for(int x = 0; x < precision; x++){
			glVertex2f(r*cos(a*x) + x0, r*sin(a*x) + y0);
		}
	glEnd();
}


void Inicializar(void){
	//Setando a cor de limpeza do buffer de cores
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//Setando a janela de trabalho
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(WINDOW_X, WINDOW_X + WINDOW_WIDTH, WINDOW_Y, WINDOW_Y + WINDOW_HEIGHT); //Mapeamento das dimensões da janela
}

void DesenhaBordaNave(){
	glBegin(GL_LINES);
		glVertex2f(-6.0f, -18.0f);
		glVertex2f(-6.0f, -10.66f);

		glVertex2f(-6.0f, -10.66f);	
		glVertex2f(-10.0f, -16.0f);

		glVertex2f(-10.0f, -16.0f);
		glVertex2f(-18.0f, -16.0f);

		glVertex2f(-18.0f, -16.0f);
		glVertex2f(-18.0f, -8.0f);

		glVertex2f(-18.0f, -8.0f);
		glVertex2f(-20.0f, -8.0f);

		glVertex2f(-20.0f, -8.0f);
		glVertex2f(-20.0f, -4.0f);

		glVertex2f(-20.0f, -4.0f);
		glVertex2f(-10.0f, -4.0f);

		glVertex2f(-10.0f, -4.0f);
		glVertex2f(-10.0f, 4.0f);

		glVertex2f(-10.0f, 4.0f);
		glVertex2f(-4.0f, 4.0f);

		glVertex2f(-4.0f, 4.0f);
		glVertex2f(-4.0f, 16.0f);

		glVertex2f(-4.0f, 16.0f);
		glVertex2f(-2.0f, 16.0f);

		glVertex2f(-2.0f, 16.0f);
		glVertex2f(-2.0f, 24.0f);

		glVertex2f(-2.0f, 24.0f);
		glVertex2f(2.0f, 24.0f);

		glVertex2f(2.0f, 24.0f);
		glVertex2f(2.0f, 16.0f);

		glVertex2f(2.0f, 16.0f);
		glVertex2f(4.0f, 16.0f);

		glVertex2f(4.0f, 16.0f);
		glVertex2f(4.0f, 4.0f);

		glVertex2f(4.0f, 4.0f);
		glVertex2f(10.0f, 4.0f);

		glVertex2f(10.0f, 4.0f);
		glVertex2f(10.0f, -4.0f);

		glVertex2f(10.0f, -4.0f);
		glVertex2f(20.0f, -4.0f);

		glVertex2f(20.0f, -4.0f);
		glVertex2f(20.0f, -8.0f);

		glVertex2f(20.0f, -8.0f);
		glVertex2f(18.0f, -8.0f);

		glVertex2f(18.0f, -8.0f);
		glVertex2f(18.0f, -16.0f);

		glVertex2f(18.0f, -16.0f);
		glVertex2f(10.0f, -16.0f);

		glVertex2f(10.0f, -16.0f);
		glVertex2f(6.0f, -10.66f);	

		glVertex2f(6.0f, -10.66f);
		glVertex2f(6.0f, -18.0f);

		glVertex2f(6.0f, -18.0f);
		glVertex2f(-6.0f, -18.0f);
	glEnd();
}


void DesenhaFumaca(int frame){
	glPointSize(4.0*(10000/(WINDOW_WIDTH*WINDOW_HEIGHT)));
	glColor3f(1.0f, 1.0f, 1.0f);

	switch(frame){

		case 0:
			glBegin(GL_POINTS);	
				//Tanque 1
				glVertex2f(-18.0f, -19.0f);
				glVertex2f(-17.0f, -22.0f);
				glVertex2f(-16.0f, -22.0f);
				glVertex2f(-18.0f, -20.0f);
				glVertex2f(-17.0f, -21.0f);
				glVertex2f(-16.0f, -23.0f);
				glVertex2f(-16.0f, -25.0f);
				glVertex2f(-17.0f, -25.0f);

				//Tanque 2
				glVertex2f(-12.0f, -22.0f);
				glVertex2f(-11.0f, -23.0f);
				glVertex2f(-10.0f, -22.0f);
				glVertex2f(-12.0f, -20.0f);
				glVertex2f(-12.0f, -25.0f);
				glVertex2f(-10.0f, -19.0f);
				glVertex2f(-10.0f, -23.0f);
				glVertex2f(-11.0f, -21.0f);

				//Tanque 3
				glVertex2f(12.0f, -21.0f);
				glVertex2f(11.0f, -22.0f);
				glVertex2f(10.0f, -19.0f);
				glVertex2f(12.0f, -24.0f);
				glVertex2f(12.0f, -23.0f);
				glVertex2f(10.0f, -26.0f);
				glVertex2f(10.0f, -25.0f);
				glVertex2f(11.0f, -19.0f);	

				//Tanque 4
				glVertex2f(18.0f, -19.0f);
				glVertex2f(17.0f, -22.0f);
				glVertex2f(16.0f, -19.0f);
				glVertex2f(18.0f, -23.0f);
				glVertex2f(17.0f, -22.0f);
				glVertex2f(16.0f, -26.0f);
				glVertex2f(16.0f, -25.0f);
				glVertex2f(17.0f, -22.0f);

				//Tanque Central 1
				glVertex2f(-2.0f, -24.0f);
				glVertex2f(-3.0f, -26.0f);
				glVertex2f(-2.0f, -26.0f);
				glVertex2f(-4.0f, -27.0f);
				glVertex2f(-4.0f, -23.0f);
				glVertex2f(-2.0f, -25.0f);
				glVertex2f(-2.0f, -27.0f);
				glVertex2f(-3.0f, -28.0f);

				//Tanque Central 2
				glVertex2f(2.0f, -24.0f);
				glVertex2f(3.0f, -25.0f);
				glVertex2f(2.0f, -27.0f);
				glVertex2f(4.0f, -28.0f);
				glVertex2f(4.0f, -23.0f);
				glVertex2f(2.0f, -23.0f);
				glVertex2f(2.0f, -26.0f);
				glVertex2f(3.0f, -25.0f);
	
			glEnd();
			break;
		case 1:
			glBegin(GL_POINTS);	
				//Tanque 1
				glVertex2f(-18.0f, -25.0f);
				glVertex2f(-17.0f, -24.0f);
				glVertex2f(-16.0f, -22.0f);
				glVertex2f(-18.0f, -20.0f);
				glVertex2f(-17.0f, -26.0f);
				glVertex2f(-16.0f, -25.0f);
				glVertex2f(-16.0f, -23.0f);
				glVertex2f(-17.0f, -24.0f);

				//Tanque 2
				glVertex2f(-12.0f, -22.0f);
				glVertex2f(-11.0f, -23.0f);
				glVertex2f(-10.0f, -20.0f);
				glVertex2f(-12.0f, -24.0f);
				glVertex2f(-12.0f, -25.0f);
				glVertex2f(-10.0f, -22.0f);
				glVertex2f(-10.0f, -24.0f);
				glVertex2f(-11.0f, -26.0f);

				//Tanque 3
				glVertex2f(12.0f, -22.0f);
				glVertex2f(11.0f, -23.0f);
				glVertex2f(10.0f, -20.0f);
				glVertex2f(12.0f, -25.0f);
				glVertex2f(12.0f, -26.0f);
				glVertex2f(10.0f, -23.0f);
				glVertex2f(10.0f, -22.0f);
				glVertex2f(11.0f, -23.0f);	

				//Tanque 4
				glVertex2f(18.0f, -24.0f);
				glVertex2f(17.0f, -23.0f);
				glVertex2f(16.0f, -25.0f);
				glVertex2f(18.0f, -20.0f);
				glVertex2f(17.0f, -22.0f);
				glVertex2f(16.0f, -26.0f);
				glVertex2f(16.0f, -27.0f);
				glVertex2f(17.0f, -23.0f);

				//Tanque Central 1
				glVertex2f(-2.0f, -27.0f);
				glVertex2f(-3.0f, -28.0f);
				glVertex2f(-2.0f, -29.0f);
				glVertex2f(-4.0f, -30.0f);
				glVertex2f(-4.0f, -26.0f);
				glVertex2f(-2.0f, -24.0f);
				glVertex2f(-2.0f, -23.0f);
				glVertex2f(-3.0f, -25.0f);

				//Tanque Central 2
				glVertex2f(2.0f, -25.0f);
				glVertex2f(3.0f, -26.0f);
				glVertex2f(2.0f, -24.0f);
				glVertex2f(4.0f, -25.0f);
				glVertex2f(4.0f, -24.0f);
				glVertex2f(2.0f, -30.0f);
				glVertex2f(2.0f, -27.0f);
				glVertex2f(3.0f, -26.0f);
	
			glEnd();
			break;
		case 2:
			glBegin(GL_POINTS);	
				//Tanque 1
				glVertex2f(-18.0f, -19.0f);
				glVertex2f(-17.0f, -21.0f);
				glVertex2f(-16.0f, -20.0f);
				glVertex2f(-18.0f, -19.0f);
				glVertex2f(-17.0f, -32.0f);
				glVertex2f(-16.0f, -30.0f);
				glVertex2f(-16.0f, -31.0f);
				glVertex2f(-17.0f, -32.0f);

				//Tanque 2
				glVertex2f(-12.0f, -21.0f);
				glVertex2f(-11.0f, -20.0f);
				glVertex2f(-10.0f, -31.0f);
				glVertex2f(-12.0f, -19.0f);
				glVertex2f(-12.0f, -24.0f);
				glVertex2f(-10.0f, -19.0f);
				glVertex2f(-10.0f, -32.0f);
				glVertex2f(-11.0f, -28.0f);

				//Tanque 3
				glVertex2f(12.0f, -32.0f);
				glVertex2f(11.0f, -20.0f);
				glVertex2f(10.0f, -19.0f);
				glVertex2f(12.0f, -30.0f);
				glVertex2f(12.0f, -26.0f);
				glVertex2f(10.0f, -27.0f);
				glVertex2f(10.0f, -30.0f);
				glVertex2f(11.0f, -19.0f);	

				//Tanque 4
				glVertex2f(18.0f, -19.0f);
				glVertex2f(17.0f, -21.0f);
				glVertex2f(16.0f, -19.0f);
				glVertex2f(18.0f, -32.0f);
				glVertex2f(17.0f, -28.0f);
				glVertex2f(16.0f, -26.0f);
				glVertex2f(16.0f, -28.0f);
				glVertex2f(17.0f, -27.0f);

				//Tanque Central 1
				glVertex2f(-2.0f, -23.0f);
				glVertex2f(-3.0f, -30.0f);
				glVertex2f(-2.0f, -31.0f);
				glVertex2f(-4.0f, -28.0f);
				glVertex2f(-4.0f, -23.0f);
				glVertex2f(-2.0f, -28.0f);
				glVertex2f(-2.0f, -29.0f);
				glVertex2f(-3.0f, -32.0f);

				//Tanque Central 2
				glVertex2f(2.0f, -26.0f);
				glVertex2f(3.0f, -28.0f);
				glVertex2f(2.0f, -27.0f);
				glVertex2f(4.0f, -33.0f);
				glVertex2f(4.0f, -23.0f);
				glVertex2f(2.0f, -25.0f);
				glVertex2f(2.0f, -34.0f);
				glVertex2f(3.0f, -26.0f);
	
			glEnd();
			break;
	}
}

void DesenhaNave(){
	static int frame = 0;
	glLineWidth(2.0*(10000/(WINDOW_WIDTH*WINDOW_HEIGHT)));

	glColor3f(0.98f, 0.39f, 0.39f);

	//Cano Frontal Maior
	DrawRectangle(-4.0f, 16.0f, 8.0f, 12.0f);
	//Cano Frontal Menor
	DrawRectangle(-2.0f, 24.0f, 4.0f, 8.0f);
	//Suporte do Cano Frontal
	DrawRectangle(-10.0f, 4.0f, 20.f, 8.0f);
	//Corpo Principal da Nave
	DrawRectangle(-20.0f, -4.0f, 40.0f, 4.0f);

	//Suporte propulsor esquerdo
	DrawTrapezoid(-18.0f, -8.0f, 14.0f, 8.0f, 8.0f);
	//Suporte propulsor direito
	DrawTrapezoid(18.0f, -8.0f, -14.0f, -8.0f, 8.0f);

	//Suporte propulsores centrais
	DrawRectangle(-6.0f, -8.0f, 12.0f, 10.0f);	

	//Propulsores esquerdos
	glColor3f(0.8f, 0.8f, 0.8f);
	DrawRectangle(-18.0f, -16.0f, 2.0f, 2.0f);
	DrawRectangle(-12.0f, -16.0f, 2.0f, 2.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	DrawRectangleBorder(-18.0f, -16.0f, 2.0f, 2.0f);
	DrawRectangleBorder(-12.0f, -16.0f, 2.0f, 2.0f);

	//Propulsores centrais
	glColor3f(0.8f, 0.8f, 0.8f);
	DrawRectangle(-4.0f, -18.0f, 2.0f, 4.0f);
	DrawRectangle(4.0f, -18.0f, -2.0f, 4.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	DrawRectangleBorder(-4.0f, -18.0f, 2.0f, 4.0f);
	DrawRectangleBorder(4.0f, -18.0f, -2.0f, 4.0f);

	//Propulsores esquerdos
	glColor3f(0.8f, 0.8f, 0.8f);
	DrawRectangle(18.0f, -16.0f, -2.0f, 2.0f);
	DrawRectangle(12.0f, -16.0f, -2.0f, 2.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	DrawRectangleBorder(18.0f, -16.0f, -2.0f, 2.0f);
	DrawRectangleBorder(12.0f, -16.0f, -2.0f, 2.0f);

	//Tanques Frontais
	glColor3f(0.8f, 0.8f, 0.8f);
	DrawRectangle(-18.0f, 2.0f, 4.0f, 6.0f);
	DrawRectangle(18.0f, 2.0f, -4.0f, 6.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	DrawRectangleBorder(-18.0f, 2.0f, 4.0f, 6.0f);
	DrawRectangleBorder(18.0f, 2.0f, -4.0f, 6.0f);
	DrawRectangleBorder(-18.0f, 2.0f, 4.0f, 1.0f);
	DrawRectangleBorder(18.0f, 2.0f, -4.0f, 1.0f);

	//Armas principais
	glColor3f(0.8f, 0.8f, 0.8f);
	DrawRectangle(-8.0f, 12.0f, 2.0f, 8.0f);
	DrawRectangle(8.0f, 12.0f, -2.0f, 8.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	DrawRectangleBorder(-8.0f, 12.0f, 2.0f, 8.0f);
	DrawRectangleBorder(8.0f, 12.0f, -2.0f, 8.0f);
	DrawRectangleBorder(-8.0f, 12.0f, 2.0f, 1.0f);
	DrawRectangleBorder(8.0f, 12.0f, -2.0f, 1.0f);

	//Detalhe na nave
	glColor3f(0.94f, 0.94f, 0.94f);
	DrawRectangle(-6.0f, 3.0f, 12.0f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	DrawRectangleBorder(-6.0f, 3.0f, 12.0f, 10.0f);
	glColor3f(0.94f, 0.94f, 0.94f);
	DrawRectangle(-8.0f, -4.0f, 16.0f, 6.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	DrawRectangleBorder(-8.0f, -4.0f, 16.0f, 6.0f);
	glColor3f(0.94f, 0.94f, 0.94f);
	DrawRectangle(-2.0f, 10.0f, 4.0f, 10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	DrawRectangleBorder(-2.0f, 10.0f, 4.0f, 10.0f);

	//Cabine
	glColor3f(0.4f, 0.84f, 0.95f);
	DrawRectangle(-3.0f, 0.0f, 6.0f, 8.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	DrawRectangleBorder(-3.0f, 0.0f, 6.0f, 8.0f);

	//Vidro da Cabine
	DrawRectangleBorder(-2.0f, -1.0f, 4.0f, 6.0f);
	glBegin(GL_LINES);
		glVertex2f(-3.0f, 0.0f);
		glVertex2f(-2.0f, -1.0f);

		glVertex2f(3.0f, 0.0f);
		glVertex2f(2.0f, -1.0f);

		glVertex2f(3.0f, -8.0f);
		glVertex2f(2.0f, -7.0f);

		glVertex2f(-3.0f, -8.0f);
		glVertex2f(-2.0f, -7.0f);
	glEnd();	

	//Baterias
	glColor3f(0.94f, 0.94f, 0.94f);
	DrawRectangle(-16.0f, -6.0f, 6.0f, 8.0f);
	DrawRectangle(16.0f, -6.0f, -6.0f, 8.0f);
	DrawRectangle(-4.0, -10.0, 8.0f, 6.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	DrawRectangleBorder(-16.0f, -6.0f, 6.0f, 8.0f);
	DrawRectangleBorder(16.0f, -6.0f, -6.0f, 8.0f);
	DrawRectangleBorder(-4.0, -10.0, 8.0f, 6.0f);
	DrawHorizontalTracing(-16.0f, -6.0f, 6.0f, 8.0f, 2.0f);
	DrawHorizontalTracing(16.0f, -6.0f, -6.0f, 8.0f, 2.0f);
	DrawHorizontalTracing(-4.0, -10.0, 8.0f, 6.0f, 2.0f);

	//Bordas
	glColor3f(0.0f, 0.0f, 0.0f);
	DesenhaBordaNave();
	
	if (frame > 2) frame = 0;
	DesenhaFumaca(frame++);
}

void DesenhaNucleo(float d_angle, float d_position , int * flags){
	static float angle, position = 0.0;
	static float last_angle_change = 90.0f;

	if (flags[0] == 1) angle += d_angle; 
	if (flags[1] == 1) position += d_position;

	glClear(GL_COLOR_BUFFER_BIT);

	glRotatef(d_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, d_position, 0.0f);
	DesenhaNave();

	glFlush();
}

void Desenha(void){
	int flags[2] = {0, 0}, angle = 0.0f;

	DesenhaNucleo(0.0f, 0.0f, flags);
}

void Keyboard(unsigned char key, int x, int y){
	if (key == 'q'){
		exit(1);
	}
}

void TeclasEspeciais(int key, int x, int y){
	int flags[2] = {0, 0};

	if (key == GLUT_KEY_LEFT){
		flags[0] = 1;
		DesenhaNucleo(DELTA_ROTATION, 0.0f, flags);
	}
	if (key == GLUT_KEY_RIGHT){
		flags[0] = 1;
		DesenhaNucleo(-DELTA_ROTATION, 0.0f, flags);
	}
	if (key == GLUT_KEY_DOWN){
		flags[1] = 1;
		DesenhaNucleo(0.0f, -DELTA_POSITION, flags);
	}
	if (key == GLUT_KEY_UP){
		flags[1] = 1;
		DesenhaNucleo(0.0f, DELTA_POSITION, flags);
	}

}

int main(){
	//Setando o modo do OpenGL com apenas um buffer de cores e cor em RGB
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );

	//Criando uma janela no SO
	glutInitWindowPosition((int)(LARGURA_TELA/2 - LARGURA_JANELA/2), (int)(ALTURA_TELA/2 - ALTURA_JANELA/2));
	glutInitWindowSize(LARGURA_JANELA, ALTURA_JANELA);
	glutCreateWindow("Primitivas Gráficas");

	//Setando a função padrão de desenho
	glutDisplayFunc(Desenha);

	//Monitor de Eventos Especiais
	glutSpecialFunc(TeclasEspeciais);
	
	Inicializar();
	//Loop de callback e captura de eventos
	glutMainLoop();
}
