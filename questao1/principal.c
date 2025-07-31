#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

#define TAMANHO_BUFFER 5

int buffer[TAMANHO_BUFFER] = {0};
int contador = 0;
int produtores_ativos = 3; // Item A
int produtores_ativos_g = 6; // Item G

pthread_mutex_t mutex;
pthread_cond_t cond_producer;
pthread_cond_t cond_consumer;

typedef struct produtorArgs {
    int n;
} produtorArgs;

void *produtor(void *args) {
    produtorArgs *pargs = (produtorArgs *)args;
    int n = pargs->n;
    int interacoes = 0;
    while (n-- > 0) {
        pthread_mutex_lock(&mutex);
        int valor = rand() % 1000 + 1;
        // pthread_mutex_unlock(&mutex);

        // pthread_mutex_lock(&mutex);
        while (contador == TAMANHO_BUFFER) {
            pthread_cond_wait(&cond_producer, &mutex);
        }
        for (int i = 0; i < TAMANHO_BUFFER; i++) {
            if (buffer[i] == 0) {
                buffer[i] = valor;
                break;
            }
        }
        contador++;
        printf("(P) TID: %lu | VALOR: R$ %d | ITERACAO: %d\n",
               pthread_self(), valor, ++interacoes);
        if (contador == TAMANHO_BUFFER) {
            pthread_cond_signal(&cond_consumer);
        }
        pthread_mutex_unlock(&mutex);

        sleep(rand() % 5 + 1);
    }
    pthread_mutex_lock(&mutex);
    if (produtores_ativos > 0) { // Item A
        produtores_ativos--;
    } else if (produtores_ativos_g > 0) { // Item G
        produtores_ativos_g--;
    }
    printf("(P) TID: %lu finalizou\n", pthread_self());
    pthread_cond_signal(&cond_consumer);
    pthread_mutex_unlock(&mutex);
    free(args);
    pthread_exit(NULL);
    return NULL;
}

void *consumidor_a(void *args) {
    int interacoes = 0;

    while (1) {
        pthread_mutex_lock(&mutex);

        while (contador < TAMANHO_BUFFER && produtores_ativos > 0 && contador > 0) {
            pthread_cond_wait(&cond_consumer, &mutex);
        }

        if (produtores_ativos == 0 && contador == 0) {
            pthread_mutex_unlock(&mutex);
            break;
        }

        if (contador > 0) {
            int soma = 0;
            int itens_processados = 0;

            for (int i = 0; i < TAMANHO_BUFFER && itens_processados < contador; i++) {
                if (buffer[i] != 0) {
                    soma += buffer[i];
                    buffer[i] = 0;
                    itens_processados++;
                }
            }

            double media = (double)soma / itens_processados;
            contador = 0;

            printf("(C) TID: %lu | MEDIA: R$ %.2f | ITERACAO: %d\n",
                  pthread_self(), media, ++interacoes);

            pthread_cond_broadcast(&cond_producer);
        }

        pthread_mutex_unlock(&mutex);
    }

    printf("(C) TID: %lu finalizou\n", pthread_self());
    pthread_exit(NULL);
    return NULL;
}

void *consumidor_g(void *args) {
    int interacoes = 0;

    while (1) {
        pthread_mutex_lock(&mutex);

        while (contador < TAMANHO_BUFFER/2 && produtores_ativos_g > 0 && contador > 0) {
            pthread_cond_wait(&cond_consumer, &mutex);
        }

        if (contador == 0 && produtores_ativos_g == 0) {
            pthread_mutex_unlock(&mutex);
            break;
        }

        if (contador > 0) {
            int itens_a_processar = (contador > TAMANHO_BUFFER/2) ? TAMANHO_BUFFER/2 : contador;
            int soma = 0;
            int processado = 0;

            for (int i = 0; i < TAMANHO_BUFFER && processado < itens_a_processar; i++) {
                if (buffer[i] != 0) {
                    soma += buffer[i];
                    buffer[i] = 0;
                    processado++;
                    contador--;
                }
            }
            double media = (double)soma / itens_a_processar;

            printf("(C) TID: %lu | MEDIA: R$ %.2f | ITERACAO: %d\n",
                   pthread_self(), media, ++interacoes);

            if (processado > 0) {
                pthread_cond_broadcast(&cond_producer);
            }
        }
        pthread_mutex_unlock(&mutex);
    }
    printf("(C) TID: %lu finalizou\n", pthread_self());
    return NULL;
}

int escolha_executar_item_a_g() {
    int escolha = 0;
    printf("Questão 1 - Itens: A e G:\n");
    printf("1 - 3 produtores e 1 consumidor\n");
    printf("2 - 6 produtores e 2 consumidores\n");
    printf("Digite sua escolha (1 ou 2): ");
    scanf("%d", &escolha);
    while (escolha != 1 && escolha != 2) {
        printf("Escolha invalida. Digite 1 ou 2: ");
        scanf("%d", &escolha);
    }
    return escolha;
}

int main() {
    srand(time(NULL));

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_consumer, NULL);
    pthread_cond_init(&cond_producer, NULL);

    int escolha = escolha_executar_item_a_g();

    if (escolha == 1) {
        // Item A: 3 produtores e 1 consumidor
        produtores_ativos = 3;
        produtores_ativos_g = 0;

        pthread_t produtores[3];
        pthread_t consumidor;

        struct timeval ini, fim;
        gettimeofday(&ini, NULL);

        for (int i = 0; i < 3; i++) {
            produtorArgs *args = malloc(sizeof(produtorArgs));
            pthread_mutex_lock(&mutex);
            args->n = rand() % 11 + 20;
            pthread_mutex_unlock(&mutex);
            pthread_create(&produtores[i], NULL, produtor, args);
        }

        pthread_create(&consumidor, NULL, consumidor_a, NULL);

        for (int i = 0; i < 3; i++) {
            pthread_join(produtores[i], NULL);
        }
        pthread_join(consumidor, NULL);

        gettimeofday(&fim, NULL);
        double tempo_total = (fim.tv_sec - ini.tv_sec) + (fim.tv_usec - ini.tv_usec)/1000000.0;
        printf("Tempo total: %.2f s\n", tempo_total);
    }
    else if (escolha == 2) {
        // Item G: 6 produtores e 2 consumidores
        produtores_ativos = 0;
        produtores_ativos_g = 6;

        pthread_t produtores[6];
        pthread_t consumidores[2];

        struct timeval ini, fim;
        gettimeofday(&ini, NULL);

        for (int i = 0; i < 6; i++) {
            produtorArgs *args = malloc(sizeof(produtorArgs));
            pthread_mutex_lock(&mutex);
            args->n = rand() % 11 + 20;
            pthread_mutex_unlock(&mutex);
            pthread_create(&produtores[i], NULL, produtor, args);
        }

        for (int i = 0; i < 2; i++) {
            pthread_create(&consumidores[i], NULL, consumidor_g, NULL);
        }

        for (int i = 0; i < 6; i++) {
            pthread_join(produtores[i], NULL);
        }

        pthread_mutex_lock(&mutex);
        pthread_cond_broadcast(&cond_consumer);
        pthread_mutex_unlock(&mutex);

        for (int i = 0; i < 2; i++) {
            pthread_join(consumidores[i], NULL);
        }

        gettimeofday(&fim, NULL);
        double tempo_total = (fim.tv_sec - ini.tv_sec) + (fim.tv_usec - ini.tv_usec)/1000000.0;
        printf("Tempo total: %.2f s\n", tempo_total);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_consumer);
    pthread_cond_destroy(&cond_producer);
    return 0;
}