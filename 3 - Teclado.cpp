
void Keyboard(unsigned char key, int x, int y){
	if (key == 'q'){
		exit(1);
	}
	if (key == ' '){
		if (counter_shoot == SHOOT_COUNTER){
			addElement_LE(&Tiros, x_nave, y_nave, tipo_tiro, angulo_nave, 0);
			counter_shoot = 0;
		}
	}
}

void TeclasEspeciais(int key, int x, int y){
	if (key == GLUT_KEY_LEFT){
		angulo_nave += DELTA_ROTATION;
	}
	if (key == GLUT_KEY_RIGHT){
		angulo_nave -= DELTA_ROTATION;
	}
	if (key == GLUT_KEY_DOWN){
		r_nave = -DELTA_POSITION;
		counter_smooth = 0;
	}
	if (key == GLUT_KEY_UP){
		r_nave = DELTA_POSITION;
		counter_smooth = 0;
	}
}

