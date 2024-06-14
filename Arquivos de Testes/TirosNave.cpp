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
#define MOSTRAR_MALHA_MINIMA 1

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
	glPointSize(3.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	frame = 0;

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
	glLineWidth(2.0f);

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

void DesenhaNaveHitbox(){
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-20.0f, 24.0f);
		glVertex2f(20.0f, 24.0f);
		glVertex2f(20.0f, -22.0f);
		glVertex2f(-20.0f, -22.0f);
	glEnd();
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

void Desenha(void){
	//Limpando o buffer com a cor definida por glClearColor
	glClear(GL_COLOR_BUFFER_BIT);
	DesenhaMalhas();
	DesenhaNave();
	DesenhaNaveHitbox();

	//Desenhando um tiro
	DesenhaTiro();
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
