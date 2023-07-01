
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
	glPointSize(4.0*(10000/(CANVA_WIDTH*CANVA_HEIGHT)));
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

void DesenhaNaveHitbox(){
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-20.0f, 24.0f);
		glVertex2f(20.0f, 24.0f);
		glVertex2f(20.0f, -22.0f);
		glVertex2f(-20.0f, -22.0f);
	glEnd();
}

void DesenhaNave(){
	static int frame = 0;
	glLineWidth(2.0*(10000/(CANVA_WIDTH*CANVA_HEIGHT)));

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

