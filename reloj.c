#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>

int horab0(int hora){
	if(hora %2){
		digitalWrite (4, 1);
		return 1;
	}
	digitalWrite (4, 0);
	return 0;
}
int horab1(int hora){
	if((hora>>1)%2 ){
		digitalWrite (1, 1);
		return 1;
	}
	
	digitalWrite (1, 0);
	return 0;

}
int horab2(int hora){
	if((hora>>2)%2 ){
		digitalWrite (16, 1);
		return 1;
	}
	digitalWrite (16, 0);
	return 0;
}
int horab3(int hora){
	if(hora >=8){
		digitalWrite (15, 1);
		return 1;
	}
	digitalWrite (15, 0);
	return 0;
}



int minutosb0(int minutos){
	if(minutos%2 ){
		digitalWrite (28, 1);
		return 1;
	}
	digitalWrite (28, 0);
	return 0;
}
int minutosb1(int minutos){
	if((minutos>>1)%2 ){
		digitalWrite (27, 1);
		return 1;
	}
	digitalWrite (27, 0);
	return 0;
}
int minutosb2(int minutos){
	if((minutos>>2)%2 ){
		digitalWrite (26, 1);
		return 1;
	}
	digitalWrite (26, 0);
	return 0;
}
int minutosb3(int minutos){
	if((minutos>>3)%2 ){
		digitalWrite (11, 1);
		return 1;
	}
	digitalWrite (11, 0);
	return 0;
}
int minutosb4(int minutos){
	if((minutos>>4)%2 ){
		digitalWrite (10, 1);
		return 1;
	}
	digitalWrite (10, 0);
	return 0;
}

int minutosb5(int minutos){
	if(minutos>=32){
	digitalWrite (6, 1);
		return 1;
	}
	digitalWrite (6, 0);
	return 0;
}


char* hora(struct tm* tiempo){
	char* horac= NULL;
	int hour = tiempo->tm_hour + 1;
	horac = malloc(5);
	if (hour > 12)
		hour -= 12;
	sprintf(horac, "%d%d%d%d", horab3(hour), horab2(hour), horab1(hour), horab0(hour));
	return horac;
}

char* minutos(struct tm* tiempo){
	char* minc= NULL;
	int min = tiempo->tm_min;
	minc = malloc(7);
	sprintf(minc, "%d%d%d%d%d%d", minutosb5(min), minutosb4(min), minutosb3(min), minutosb2(min), minutosb1(min), minutosb0(min));
	return minc;
}

int main (){

	struct tm* tiempo=NULL;
	time_t t= time(NULL);
	
	if (wiringPiSetup () == -1)
		return 1;
	pinMode (15, OUTPUT);
	pinMode (16, OUTPUT);
	pinMode (1, OUTPUT);
	pinMode (4, OUTPUT);

		
	pinMode (6, OUTPUT);
	pinMode (10, OUTPUT);
	pinMode (11, OUTPUT);
	pinMode (26, OUTPUT);
	pinMode (27, OUTPUT);
	pinMode (28, OUTPUT);
	while(1){
		t = time(NULL);
		tiempo = localtime(&t);
		//printf("%d\n", (cosa>>1)%2);
		//printf("%d:%d\n", hour, min);
		hora(tiempo), minutos(tiempo);
		sleep(1);
		
	}
	return 0;
}
