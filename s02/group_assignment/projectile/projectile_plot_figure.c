#include <stdio.h>
//画像を保存

int main() {
    FILE *gnuplotPipe = popen ("gnuplot -persistent", "w");

    if (gnuplotPipe == NULL) {
        printf("Error opening pipe to GNU plot.\n");
        return 1;
    }
 
    fprintf(gnuplotPipe, "set title 'projectile plot'\n");
    fprintf(gnuplotPipe, "set xrange [0:18]\n");
    fprintf(gnuplotPipe, "set yrange [0:18]\n");


    for (int i = 1; i <= 10; i++) {
        if (i == 1) {
            fprintf(gnuplotPipe, "plot 'data1_%d.dat' with lines\n", i);
        } else {
            fprintf(gnuplotPipe, "replot 'data1_%d.dat' with lines\n", i);
        }
    }
    fprintf(gnuplotPipe, "replot\n");
    

    fflush(gnuplotPipe);
    fclose(gnuplotPipe);
    return 0;
}