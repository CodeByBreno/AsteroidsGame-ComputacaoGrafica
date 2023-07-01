#define CIRCLE_PRECISION 1000

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

