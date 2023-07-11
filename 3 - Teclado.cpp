
void Keyboard(unsigned char key, int x, int y){
	if ((key == 'q') || (key == 'Q')){
		exit(1);
	}

	if ((key == 'f') || (key == 'F')){
		if (fullScreen == 0){
			glutFullScreen();
			fullScreen = 1;
		} else {
			glutPositionWindow((int)(LARGURA_TELA/2 - LARGURA_JANELA/2), (int)(ALTURA_TELA/2 - ALTURA_JANELA/2));
			glutReshapeWindow(LARGURA_JANELA, ALTURA_JANELA);
			fullScreen = 0;
		}
	}

	if (key == ' '){
		game_start = 0;
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

