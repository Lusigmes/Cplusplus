#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_TERMS 2000000000
#define NUM_THREADS 16
#define SIZE_PARCIAL ((NUM_TERMS) / (NUM_THREADS))

pthread_mutex_t mutex ;
double soma_global = 0.0;

typedef struct {
    int primeiro_termo;
    int tid;
    double tempo;
} threadss;

double formulaParcial(int primeiro_termo) {
    double soma_parcial = 0.0;
    double sinal = (primeiro_termo % 2 == 0) ? 1.0 : -1.0;
    // leibnz  com o tamanho dos termos pelo numero de threads
    for (int k = primeiro_termo; k < primeiro_termo + SIZE_PARCIAL; k++) {
        soma_parcial += sinal / (2*k+1);
        sinal *= -1.0;
    }

    return soma_parcial;
}

void *processamentoParcial(void *args) {
    threadss *dados = (threadss *)args;

    struct timeval ini, fim;
    gettimeofday(&ini, NULL);

    double somad_parcial = formulaParcial(dados->primeiro_termo);

    gettimeofday(&fim, NULL);
    // mutex para proteger variavel global
    pthread_mutex_lock(&mutex);
    soma_global += somad_parcial;
    pthread_mutex_unlock(&mutex);

    dados->tempo = (fim.tv_sec - ini.tv_sec) +
        (fim.tv_usec - ini.tv_usec)/1000000.0;

    printf("TID: %d: %.2f s\n", dados->tid, dados->tempo);

    pthread_exit(NULL);
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_t threads[NUM_THREADS];
    threadss dados_threads[NUM_THREADS];

    struct timeval ini, fim;
    gettimeofday(&ini, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        dados_threads[i].primeiro_termo = i*SIZE_PARCIAL;
        dados_threads[i].tid = i;
        pthread_create(&threads[i], NULL, processamentoParcial, &dados_threads[i]);
    }

    for ( int i=0; i< NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    double pi = 4.0 * soma_global;

    gettimeofday(&fim, NULL);

    double tempo_total = (fim.tv_sec - ini.tv_sec) +
        (fim.tv_usec - ini.tv_usec)/1000000.0;

    double soma_tempo_thread = 0.0;
    for (int i = 0; i < NUM_THREADS; i++) {
        soma_tempo_thread += dados_threads[i].tempo;
    }

    // imprimir tempo thread,proce
    printf("Pi aproximado: %.9f\n", pi);
    printf("processo paralelo total: %.2f s\n", tempo_total);
    printf("total threads: %.2f s\n", soma_tempo_thread);

    pthread_mutex_destroy((&mutex));
    return 0;
}
