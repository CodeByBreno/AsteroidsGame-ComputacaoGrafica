
//Atualização de Estado
void AtualizaNave(){
	int signal;
	if (r_nave < 0){
		signal = -1;
	} else{
		signal = 1;
	}

	float dx = -r_nave*sin(Radian(angulo_nave));
	float dy = r_nave*cos(Radian(angulo_nave));
	//printf("dx=%.2f dy=%.2f\n", dx, dy);

	if (angulo_nave >= 360) angulo_nave -= 360;
	if (!NaveForaTela(dx, dy)){
		x_nave += dx;
		y_nave += dy;
	} 
	
	r_nave = signal*DELTA_POSITION*(1 - counter_smooth/SMOOTH_COUNTER);
}

void AtualizaTiro(){
	float dx, dy;
	apresentar_LE(&Tiros);

	for (int i = 0; i < Tiros.size; i++){
		dx = -VELOCIDADE_TIRO*sin(Radian(Tiros.elements[i].angle));
		dy = VELOCIDADE_TIRO*cos(Radian(Tiros.elements[i].angle));
		Tiros.elements[i].x += dx;
		Tiros.elements[i].y += dy;
	}
}

void AtualizaEstado(int value){
	if (counter_shoot < SHOOT_COUNTER) { counter_shoot++; }    //Um novo tiro só poderá ser disparado quando o contador atingir o valor máximo (SHOOT_COUNTER)
	if (counter_smooth < SMOOTH_COUNTER) { counter_smooth++; } //A nave não para de imediato. Após parar de move-lá, somente quando o contador chegar ao valor
                                                               //máximo, ela irá parar totalmente

	AtualizaNave();
	AtualizaTiro();
}

