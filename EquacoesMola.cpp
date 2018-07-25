#include <stdio.h>
#include <stdlib.h>

int main () {

    FILE *output;
	float ph = 1, vh = 0 , ah = 1, pa, va, aa;
	int t;

	if (NULL == (output = fopen ("data3", "w"))) { 
		puts ("erro com arquivo"); 
		return 0;
	}

    //---------------------------------------------------------
    // Gerar e gravar dados.
	//---------------------------------------------------------

	for (t = 0; t < 50000; t++) {
			
		
		va = vh + 0.1 * ah;
		pa = ph + 0.01 * vh;
		aa = -ph;

		ah = aa;
		vh = va;
		ph = pa;


       fprintf(output, "%d	%.2f		%.2f		%.2f \n", t, vh, ah, ph);
	}
	//---------------------------------------------------------

	fclose(output);
	/*
    system ("gnuplot -p -e \" "
            "set multiplot layout 1,2 ; "	
            "set xlabel \'tempo' ;"
            "plot \'data3\' using 1:2 with lines ti \'eq1\' lw 1 dt 1 lc rgb '#000000' ; "
            "plot \'data3\' using 1:3 with lines ti \'eq2\' lw 3 dt 3 lc rgb '#ff4000' ; "
            "plot \'data3\' using 1:4 with lines ti \'eq1\' lw 1 dt 1 lc rgb '#000000' ; " );
	*/
    system ("gnuplot -p -e \" "
            "set xlabel \'Tempo' ; "
            "set ylabel \'Posicao' ; "
            "plot \'data3\' using 1:4 with lines ti \'resultados\' lw 2 dt 2 lc rgb '#0000ff' \" ");

	system ("gnuplot -p -e \" "
            "set xlabel \'Velocidade' ; "
            "set ylabel \'Posicao' ; "
            "plot \'data3\' using 2:4 with lines ti \'resultados\' lw 2 dt 2 lc rgb '#0000ff' \" ");


	
	return 0;
}