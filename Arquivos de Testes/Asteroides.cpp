#include <stdio.h>
#include <math.h>
#include <gl/glut.h>

#define LARGURA_TELA 1280
#define ALTURA_TELA 720 
#define LARGURA_JANELA 600
#define ALTURA_JANELA 600
#define CIRCLE_PRECISION 1000

#define MOSTRAR_MALHA_PRINCIPAL 1
#define MOSTRAR_MALHA_MEDIA 1
#define MOSTRAR_MALHA_MINIMA 0

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

void DesenhaAsteroide1(){
	glBegin(GL_POLYGON);
		glColor3f(0.45f, 0.45f, 0.45f);
		glVertex2f(-50.0f, 20.0f);
		glVertex2f(-30.0f, 50.0f);
		glVertex2f(30.0f, 40.0f);
		glVertex2f(50.0f, 10.0f);
		glVertex2f(50.0f, -20.f);
		glVertex2f(30.0f, -40.0f);
		glVertex2f(-30.0f, -40.0f);
		glVertex2f(-50.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.7f, 0.7f, 0.7f);
		glVertex2f(-50.0f, 20.0f);
		glVertex2f(-30.0f, 50.0f);
		glVertex2f(30.0f, 40.0f);
		glVertex2f(50.0f, 10.0f);
		glVertex2f(50.0f, -20.f);
		glVertex2f(30.0f, -30.0f);
		glVertex2f(-25.0f, -20.0f);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.85f, 0.85f, 0.85f);
		glVertex2f(-30.0f, 50.0f);
		glVertex2f(30.0f, 40.0f);
		glVertex2f(50.0f, 10.0f);
		glVertex2f(50.0f, -20.f);
		glVertex2f(30.0f, -20.0f);
		glVertex2f(-15.0f, -10.0f);	
	glEnd();
}

void DesenhaAsteroide2(){
	glBegin(GL_POLYGON);
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex2f(4.0f, -40.0f);
		glVertex2f(30.0f, -30.0f);
		glVertex2f(35.0f, -15.0f);
		glVertex2f(20.0f, 35.0f);
		glVertex2f(25.0f, -15.0f);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex2f(20.0f, 35.0f);
		glVertex2f(25.0f, -15.0f);
		glVertex2f(4.0f, -40.0f);
		glVertex2f(-6.0f, -40.0f);
		glVertex2f(15.0f, -10.0f);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.66f, 0.66f, 0.66f);
		glVertex2f(-10.0f, 40.0f);
		glVertex2f(-30.0f, 30.0f);
		glVertex2f(-35.0f, -5.0f);
		glVertex2f(-6.0f, -40.0f);
		glVertex2f(15.0f, -10.0f);
		glVertex2f(20.0f, 35.0f);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.85f, 0.85f, 0.85f);
		glVertex2f(-10.0f, 40.0f);
		glVertex2f(-30.0f, 30.0f);
		glVertex2f(-35.0f, -5.0f);
		glVertex2f(-12.0f, 0.0f);
		glVertex2f(0.0f, 20.0f);
	glEnd();

	glBegin(GL_POINTS);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(-12.0f, 20.0f);
	glEnd();
}

void DesenhaAsteroide3(){
	glBegin(GL_POLYGON);
		glColor3f(0.45f, 0.45f, 0.45f);
		glVertex2f(40.0f, 10.0f);
		glVertex2f(40.0f, -20.0f);
		glVertex2f(20.0f, -30.0f);
		glVertex2f(-20.0f, -30.0f);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.66f, 0.66f, 0.66f);
		glVertex2f(-40.0f, 0.0f);
		glVertex2f(-20.0f, -30.0f);
		glVertex2f(20.0f, -20.0f);
		glVertex2f(40.0f, 10.0f);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.85f, 0.85f, 0.85f);
		glVertex2f(0.0f, 30.0f);
		glVertex2f(40.0f, 10.0f);
		glVertex2f(-10.0f, -20.0f);
		glVertex2f(-40.0f, 0.0f);
		glVertex2f(-30.0f, 20.0f);
	glEnd();
}

void DesenhaAsteroide4(){
	glBegin(GL_POLYGON);
		glColor3f(0.5f, 0.7f, 0.8f);
		glVertex2f(-10.0f, 10.0f);
		glVertex2f(0.0f, -10.0f);
		glVertex2f(20.0f, -10.0f);
		glVertex2f(0.0f, -20.0f);
		glVertex2f(-10.0f, -10.0f);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.7f, 0.9f, 1.0f);
		glVertex2f(0.0f, 20.0f);
		glVertex2f(20.0f, 0.0f);
		glVertex2f(20.0f, -10.0f);
		glVertex2f(0.0f, -10.0f);
		glVertex2f(-10.0f, 10.0f);
	glEnd();
}

void DesenhaAsteroide5(){
	glBegin(GL_POLYGON);
		glColor3f(0.35f, 0.35f, 0.35f);
		glVertex2f(-30.0f, 50.0f);
		glVertex2f(0.0f, 50.0f);
		glVertex2f(30.0f, 30.0f);
		glVertex2f(50.0f, 0.0f);
		glVertex2f(40.0f, -40.0f);
		glVertex2f(20.0f, -50.0f);
		glVertex2f(-30.0f, -50.0f);
		glVertex2f(-50.0f, -30.0f);
		glVertex2f(-50.0f, 30.0f);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex2f(-30.0f, 50.0f);
		glVertex2f(0.0f, 50.0f);
		glVertex2f(30.0f, 30.0f);
		glVertex2f(50.0f, 0.0f);
		glVertex2f(40.0f, -20.0f);
		glVertex2f(20.0f, -35.0f);
		glVertex2f(0.0f, -40.0f);
		glVertex2f(-40.0f, -30.0f);
		glVertex2f(-50.0f, -10.0f);
		glVertex2f(-50.0f, 30.0f);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.66f, 0.66f, 0.66f);
		glVertex2f(-50.0f, 30.0f);
		glVertex2f(-30.0f, 50.0f);
		glVertex2f(0.0f, 50.0f);
		glVertex2f(30.0f, 30.0f);
		glVertex2f(30.0f, -10.0f);
		glVertex2f(20.0f, -20.0f);
		glVertex2f(0.0f, -30.0f);
		glVertex2f(-30.0f, -20.0f);
		glVertex2f(-50.0f, -5.0f);
	glEnd();

	//Ouro
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(-20.0f, 45.0f);
		glVertex2f(-10.0f, 45.0f);
		glVertex2f(0.0f, 35.0f);
		glVertex2f(0.0f, 25.0f);
		glVertex2f(-10.0f, 25.0f);
		glVertex2f(-20.0f, 35.0f);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(0.0f, 15.0f);
		glVertex2f(10.0f, 15.0f);
		glVertex2f(20.0f, 5.0f);
		glVertex2f(20.0f, -5.0f);
		glVertex2f(10.0f, -5.0f);
		glVertex2f(0.0f, 5.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);
		
		glVertex2f(15.0f, 35.0f);
		glVertex2f(25.0f, 25.0f);
		glVertex2f(15.0f, 15.0f);
		glVertex2f(5.0f, 25.0f);

		glVertex2f(-10.0f, 0.0f);
		glVertex2f(0.0f, -10.0f);
		glVertex2f(-10.0f, -20.0f);
		glVertex2f(-20.0f, -10.0f);

		glVertex2f(-30.0f, 30.0f);
		glVertex2f(-20.0f, 20.0f);
		glVertex2f(-30.0f, 10.0f);
		glVertex2f(-40.0f, 20.0f);

		glVertex2f(-25.0f, 10.0f);
		glVertex2f(-20.0f, 5.0f);
		glVertex2f(-25.0f, 0.0f);
		glVertex2f(-30.0f, 5.0f);

		glVertex2f(5.0f, -10.0f);
		glVertex2f(10.0f, -15.0f);
		glVertex2f(5.0f, -20.0f);
		glVertex2f(0.0f, -15.0f);

		glVertex2f(-45.0f, 10.0f);
		glVertex2f(-40.0f, 5.0f);
		glVertex2f(-45.0f, 0.0f);
		glVertex2f(-50.0f, 5.0f);

	glEnd();
}

void DesenhaAsteroide(){
	glColor3f(0.8f, 0.4f, 0.4f);
	DrawCircle(20, 0, 0);
	glColor3f(0.4, 0.1, 0.1);
	DrawRectangle(20, 21, 2, 2);
	DrawRectangle(22, 24, 2, 2);
	DrawRectangle(25, 24, 2, 2);	
	DrawRectangle(-15, 22, 2, 2);
	DrawRectangle(-21, 23, 2, 2);
	DrawRectangle(-23, 25, 2, 2);
	DrawRectangle(20, -26, 2, 2);
	DrawRectangle(16, -24, 2, 2);
	DrawRectangle(24, -23, 2, 2);
	DrawRectangle(26, -21, 2, 2);
	DrawRectangle(-21, -26, 2, 2);
	DrawRectangle(-23, -24, 2, 2);
}

void Inicializar(void){
	//Setando a cor de limpeza do buffer de cores
	glClearColor(0.4f, 0.4f, 0.4f, 1.0f);

	//Setando a janela de trabalho
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-50.0, 50.0, -50.0, 50.0); //Mapeamento das dimensões da janela
}

void DesenhaMalhas(){
	glLineWidth(2.0);

	if (MOSTRAR_MALHA_MINIMA){
		glLineWidth(0.02f);
		glBegin(GL_LINES);
			glColor3f(0.50f, 0.50f, 0.50f);
			for (int i = -50.0; i < 50.0; i++){
				glVertex2f(-50.0f, i);
				glVertex2f(50.0f, i);
				glVertex2f(i, 50.0f);
				glVertex2f(i, -50.0f);
			}
		glEnd();
	}

	if (MOSTRAR_MALHA_MEDIA){
		glBegin(GL_LINES);
			glColor3f(0.60f, 0.60f, 0.60f);
			for (int i = -50.0; i < 50.0; i+=5){
				glVertex2f(-50.0f, i);
				glVertex2f(50.0f, i);
				glVertex2f(i, 50.0f);
				glVertex2f(i, -50.0f);
			}
		glEnd();
	}

	if (MOSTRAR_MALHA_PRINCIPAL){
		glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex2f(-50.0f, 0.0f);
			glVertex2f(50.0f, 0.0f);
	
			glVertex2f(0.0f, 50.0f);
			glVertex2f(0.0f, -50.0f);
		glEnd();
	}
}

void Desenha(void){
	//Limpando o buffer com a cor definida por glClearColor
	glClear(GL_COLOR_BUFFER_BIT);
	DesenhaMalhas();
	DesenhaAsteroide();
	glFlush();
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

	
	
	Inicializar();
	//Loop de callback e captura de eventos
	glutMainLoop();
}
