//gcc 5.4.0
#include  <stdio.h>
#include <stdlib.h>
#include <time.h>

//FILA------------------------------------------
int fila[100], espera[100], frente, tras, quantos;

void criafila(){
	int g;
     for (g=0; g<100; g++)
         fila[g]=0;
     frente = quantos = 0;
     tras = (-1);
     }

int enfileira(int elemento){
    if (quantos > 99)
                return 0;
    quantos++;
    tras++;
    if (tras > 99)
             tras = 0;
    fila[tras] = elemento;
    return 1;
}

int desenfileira(){
    int aux;
    if (quantos <= 0)
                return (-2);
    aux = fila[frente];
    frente++;
    quantos--;
    if (frente > 99)
               frente = 0;
    return aux;
}

int filavazia(){
    return quantos == 0;
}

//SORTEAR-----------------------------------------------
float TE(){ //taxa entrada
	srand ( (unsigned)time(NULL) );
	float x = rand () % 2;
	srand ( (unsigned)time(NULL) );
	float y = rand () % 60;
	return 8+x+(y/100);
}

float TS(){ //taxa saida
	srand ( (unsigned)time(NULL) );
	float x = rand () % 2;
	srand ( (unsigned)time(NULL) );
	float y = rand () % 60;
	return 10+x+(y/100);
}

//MAIN---------------------------------------------------
int main () {
  FILE *output;
	
  if (NULL == (output = fopen ("data", "w"))) { 
    puts ("erro com arquivo"); 
    return 0;
  }



	float e = 1., s = 1., taxE1, taxS1, tempo1 = 0, tempo2 = 0, tempo3 = 0, soma = 0;
    int cont = 0, i = 0, j=0;
    
    criafila();
  	
    while ( tempo3 < 60. ){
        taxE1 = TE();
        taxS1 = TS();
        
        if ( i == 0 ){
            if ( tempo1 >= taxS1 ){
            	tempo1 = 0.0;
                desenfileira();
                i = 1;
                soma = taxS1+soma;
                j++;
            }
        }else{
            if ( tempo2 >= taxE1 ){
            	tempo2 = 0.0;
                cont++;
                enfileira(cont);
                i = 0;
                soma = soma+taxE1;
            }
        }
        
        if (tempo3 == .59 ){
            tempo3 = tempo3 + .41;
            tempo2 = tempo2 + .41;
            tempo1 = tempo1 + .41;
        }
        
        tempo1 = tempo1 + .01;
        tempo2 = tempo2 + .01;
        tempo3 = tempo3 + .01;
    }
    
    int h;
    //for (h=0; h<100; h++)
    //    printf("%d - %d\n", h+1, fila[h]);
    
    printf("tamanho fila: %d\ntempo espera: %.2f", tras+1, soma);
	return 0;
}
