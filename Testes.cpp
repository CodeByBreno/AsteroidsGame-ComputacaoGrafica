#include <stdio.h>
#include <math.h>

float reverseAngle(float angulo){
	int aux = (int) angulo;
	return ((aux + 180) % 360);
}

int whosUpper(float x1, float y1, float x2, float y2){
	if (y2 > y1){
		return 2;
	} else{
		return 1;
	}
}

float Degree(float angle){
	return (180/3.14156295)*angle;
}

float angleAfterColision(float x1, float y1, float x2, float y2){
	float anguloColisao;
	float dx = x2 - x1, dy = y2 - y1; 

	if ((dx > 0) && (dy > 0)){
		anguloColisao = Degree(atan(dy/dx));
		return anguloColisao + 180;
	} 
	if ((dx < 0) && (dy > 0)){
		anguloColisao = Degree(atan(dy/-dx));
		return 360 - anguloColisao;
	}
	if ((dx > 0) && (dy < 0)){
		anguloColisao = Degree(atan(-dx/dx));
		return 180 - anguloColisao;
	}
	if ((dy < 0) && (dx < 0)){
		anguloColisao = Degree(atan(dy/dx));
		return anguloColisao;
	}
}

int main(void){
	float x1 = 5.0f, y1 = 10.0f;
	float x2 = -2.0f, y2 = -25.0f;
	printf("%.2f\n", reverseAngle(20.0));
	printf("%.2f\n", reverseAngle(210.0));
	printf("%d\n", whosUpper(x1, y1, x2, y2));


	float collision_angle = angleAfterColision(x1, y1, x2, y2);
	printf("Angulo de Colisão : %.2f", collision_angle);

	return 0;
}
