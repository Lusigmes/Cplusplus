#include <stdio.h>
#include <sys/time.h>

#define SIZE 2000000000

double calcularPIsequencial() {
    double piAproximado = 0.0;
    double sinal = 1.0;

    // leibniz
    for (int k= 0; k< SIZE; k++) {
        piAproximado += sinal / (2 * k+1);        // printf( "%f\n",piAproximado);
        sinal *= -1.0;        // printf("%f\n",sinal);
    }

    return 4.0 * piAproximado;
}

int main() {
    struct timeval ini, fim;
    gettimeofday(&ini, NULL);

    double pi = calcularPIsequencial();

    gettimeofday(&fim, NULL);

    double tempo = (fim.tv_sec - ini.tv_sec) +
        (fim.tv_usec - ini.tv_usec)/1000000.0;

    printf("Pi aproximado: %.9f\n", pi);
    printf("tempo de processmento sequencial: %.2f s\n", tempo);
    return 0;
}
