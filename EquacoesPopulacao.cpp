#include <stdio.h>
#include <stdlib.h>

int main () {

    FILE *output;
	
	  int t;

	if (NULL == (output = fopen ("dataPop", "w"))) { 
		puts ("erro com arquivo"); 
		return 0;
	}

//---------------------------------------------------------
// Gerar e gravar dados.
//---------------------------------------------------------
  float a = 0.8052, b = 0.0253, c = 6.4769 , d = 0.1288, xa, ya, xh = 53.0, yh = 30.0, dlt = 1./2048., varx = 0.0, vary = 0.0;
	
  for (t = 0; t < 15000; t++) {
			
		varx = (a * xh) - (b * xh * yh);
		vary = (-c * yh) + (d * xh * yh);
    
    xa = xh + dlt * varx;
		ya = yh + dlt * vary;
    
		xh = xa;
		yh = ya;

    fprintf(output, "%d	%.6f		%.6f\n", t, xh, yh);
	}
//---------------------------------------------------------

	fclose(output);


    system ("gnuplot -p -e \" "
            "set xlabel \'Presa' ; "
            "set ylabel \'Predador' ; "
            "plot \'dataPop\' using 2:3 with lines ti \'resultados\' lw 2 dt 2 lc rgb '#0000ff' \" ");

	
	
	return 0;
}

//Ver se é assim msm, duvida entre as 2 formas de fazer o calculo!!


	/*
    system ("gnuplot -p -e \" "
            "set multiplot layout 1,2 ; "	
            "set xlabel \'tempo' ;"
            "plot \'data3\' using 1:2 with lines ti \'eq1\' lw 1 dt 1 lc rgb '#000000' ; "
            "plot \'data3\' using 1:3 with lines ti \'eq2\' lw 3 dt 3 lc rgb '#ff4000' ; "
            "plot \'data3\' using 1:4 with lines ti \'eq1\' lw 1 dt 1 lc rgb '#000000' ; " );
	
	system ("gnuplot -p -e \" "
            "set xlabel \'Velocidade' ; "
            "set ylabel \'Posicao' ; "
            "plot \'data3\' using 2:4 with lines ti \'resultados\' lw 2 dt 2 lc rgb '#0000ff' \" ");

	*/
