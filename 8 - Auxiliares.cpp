
//Auxiliares
float Radian(float angle){
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
