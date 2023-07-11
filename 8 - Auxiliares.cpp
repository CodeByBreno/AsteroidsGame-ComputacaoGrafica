//
//Auxiliares
//

float Radian(float angle){
	while(angle > 360){
		angle -= 360;
	}
	while(angle < 0)
	{
		angle += 360;
	}

	return (3.14159/180)*angle;
}

float Degree(float angle){
	return (180/3.14156295)*angle;
}

unsigned long long currentTimestampMillis() {
    struct timespec ts;
    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
        // Lida com erro
        return 0;
    }

    return (unsigned long long)(ts.tv_nsec * 1000000);
}

void borderDebugger(){
	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(CANVA_X0 + CANVA_WIDTH + 50, CANVA_Y0);
		glVertex2f(CANVA_X0 + CANVA_WIDTH + 50, 1300 + CANVA_Y0);
		
		glVertex2f(CANVA_X0 - 50, CANVA_Y0);
		glVertex2f(CANVA_X0 - 50, 1300 + CANVA_Y0);

		glVertex2f(1100 + CANVA_X0, CANVA_Y0 - 50);	
		glVertex2f(CANVA_X0, CANVA_Y0 - 50);	

		glVertex2f(1100 + CANVA_X0, -1*CANVA_Y0 + 50);
		glVertex2f(CANVA_X0, CANVA_Y0 + CANVA_HEIGHT + 50);				
	glEnd();
}

float distance(float x0, float y0, float x1, float y1){
	float sqdx = pow(x0 - x1, 2);
	float sqdy = pow(y0 - y1, 2);

	return sqrt(sqdx + sqdy);
}

void DesenhaTexto(char *string, float x, float y){
	glRasterPos2f(x, y);
	while (*string){	
		glutBitmapCharacter(FONTE_PADRAO, *string++);
	}
}

void DesenhaTextoPequeno(char *string, float x, float y){
	glRasterPos2f(x, y);
	while (*string){	
		glutBitmapCharacter(FONTE_PEQUENA, *string++);
	}
}

float hitboxRadius(int value){
	switch(value){
		case 0:
			return HITBOX_AST0;
		case 1:
			return HITBOX_AST1;
		case 2:
			return HITBOX_AST2;
		case 3:
			return HITBOX_AST3;
		case 4:
			return HITBOX_AST4;
		default:	
			printf("ERRO: Variedade de Asteroide com Hitbox não definida\n");
			exit(504);
	}
}

