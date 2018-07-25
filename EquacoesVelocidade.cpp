#include <stdio.h>
#include <stdlib.h>

int main () {

    FILE *output;
	double a0, a1, v0= 0.0, v1= 0.0, p0= 0.0, p1= 0.0;


	if (NULL == (output = fopen ("data2", "w"))) { 
		puts ("erro com arquivo"); 
		return 0;
	}

    //---------------------------------------------------------
    // Gerar e gravar dados.
	//---------------------------------------------------------
	for (int k = 0; k < 200; k++) {
	
	   a0 = k / 200.;
	   
	   v1 = v0 + (k * a0);

	   p1 = p0 + (k * v0);
		
	   v0 = v1;
	   p0 = p1;


       fprintf(output, "%d %f %f %f\n", k, a0, v0, p0);
	}
	//---------------------------------------------------------

	fclose(output);
	/*
    system ("gnuplot -p -e \" "
            "set multiplot layout 1,2 ; "	
            "set xlabel \'tempo' ;"
            "plot \'data2\' using 1:2 with lines ti \'eq1\' lw 1 dt 1 lc rgb '#000000' ; "
            "plot \'data2\' using 1:3 with lines ti \'eq2\' lw 3 dt 3 lc rgb '#ff4000'\" ");
	*/
    system ("gnuplot -p -e \" "
            "set xlabel \'tempo' ; "
            "set ylabel \'Posição' ; "
            "plot \'data2\' using 1:4 with lines ti \'resultados\' lw 2 dt 2 lc rgb '#0000ff' \" ");

	return 0;
}