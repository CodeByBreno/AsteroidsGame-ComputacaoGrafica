
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

