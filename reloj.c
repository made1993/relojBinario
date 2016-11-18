#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int horab0(int hora){
	if(hora %2)
		return 1;
	return 0;
}
int horab1(int hora){
	if((hora>>1)%2 )
		return 1;
	return 0;

}
int horab2(int hora){
	if((hora>>2)%2 )
		return 1;
	return 0;
}
int horab3(int hora){
	if(hora >=8)
		return 1;
	return 0;
}



int minutosb0(int minutos){
	if(minutos%2 )
		return 1;
	return 0;
}
int minutosb1(int minutos){
	if((minutos>>1)%2 )
		return 1;
	return 0;
}
int minutosb2(int minutos){
	if((minutos>>2)%2 )
		return 1;
	return 0;
}
int minutosb3(int minutos){
	if((minutos>>3)%2 )
		return 1;
	return 0;
}
int minutosb4(int minutos){
	if((minutos>>4)%2 )
		return 1;
	return 0;
}

int minutosb5(int minutos){
	if(minutos>=32)
		return 1;
	return 0;
}


char* hora(struct tm* tiempo){
	char* horac= NULL;
	int hour = tiempo->tm_hour;
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
	const time_t t= time(NULL);
	tiempo = localtime(&t);

	int hour = tiempo->tm_hour;
	int min = tiempo->tm_min;
	int cosa =35;
	printf("%d\n", (cosa>>1)%2);
	printf("%d:%d\n", hour, min);
	printf("%s\n%s\n", hora(tiempo), minutos(tiempo));
	return 0;
}