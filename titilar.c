 
#include <stdio.h>
#include <wiringPi.h>
 
int main (void)
{
printf ("Titilando LED\n");
if (wiringPiSetup () == -1)
return 1;
pinMode (15, OUTPUT); //0 es el correspondiente del chip al pin 17
for (;;)
{
printf("titilar\n");
digitalWrite (15, 1); //Poner en ON o encenderlo
delay (1300); //Retraso de 1.3 segundos
digitalWrite (15, 0); //Poner en Off o apagar
delay (1300); //Retraso para volver a encender...
}
return 0;
}
