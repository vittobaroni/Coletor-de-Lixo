#include "gc.h"
#include <stdio.h>
#include <locale.h>

void imprimir_status_memoria() {

    printf("--------------------------------------------\n");

    printf("Tamanho Total do Heap  : %lu bytes\n", (unsigned long)GC_get_heap_size());  // pegar tamanho do heap
   
    printf("Bytes Livres no Heap   : %lu bytes\n", (unsigned long)GC_get_free_bytes()); //quantos bytes tem livre
    
    printf("Bytes em Uso no Heap   : %lu bytes\n", (unsigned long)GC_get_heap_size() - (unsigned long)GC_get_free_bytes()); //quantidade total de bytes usados
    printf("-------------------------------------------\n");
}

int main() {
    setlocale(LC_ALL,"pt_BR.UTF-8");

    int i;
    
    // inicialização
    GC_INIT();
    printf(" Demonstrando o Processo Completo do Mark and Sweep \n\n");
    printf("Estado Inicial: \n");
    imprimir_status_memoria();

    printf("\n Alocando um objeto que permanecera vivo durante todo o programa.\n");

    // Este ponteiro nunca será perdido, então a memória que ele aponta nunca será lixo.
    void* ponteiro_vivo = GC_MALLOC(1024); //

    printf("No codigo, alocamos um ponteiro com 1kb que nunca será perdido\n");

    imprimir_status_memoria();

    // crindo lixo proposital para demonstração

    printf("\n criando lixo de propósito.\n");
    printf("alocando 500 blocos de memoria, com cada um tendo 1kb de tamanho , mas perdendo a referencia a cada um deles.\n");

    for (i = 0; i < 500; i++) {
        // O ponteiro retornado aqui é perdido na proxima iteração do loop,
        // tornando o bloco de memória alocado inacessível (lixo).
        GC_MALLOC_ATOMIC(1024 * 10); // Aloca 10KB de lixo
    }
    printf("Lixo criado .\n\n");
    
    // Neste ponto, o heap cresceu muito, e a maior parte dos "Bytes em Uso" é, na verdade, lixo.
    printf("Antes da coleta: \n");
    imprimir_status_memoria();

    // --- processo de mark and sweep

    printf("Iniciando a coleta do lixo:\n\n");

    // Forçando o ciclo de coleta de lixo
    printf("Concluído ! Estado do heap agora : ");
    GC_gcollect();

    // finalizando 

    printf("Depois da coleta : ");
    imprimir_status_memoria();
    printf("O ponteiro vivo ainda está alocado . Para tirá-lo, basta fazê-lo apontar para nasda e dar um gc_gcollect nele\n\n");
    ponteiro_vivo = NULL;
    GC_gcollect();
    imprimir_status_memoria();
    printf("\nPonteiro vivo desalocado e memória original voltada ao início!\n");
    printf("Finalização da apresentação .");


    return 0;
}
