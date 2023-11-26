#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "instrumentation.h"
#include "image8bit.h"

// Esta função será usada para contar as comparações durante a localização da subimagem
int countComparisons(Image img1, Image img2) {
    int count = 0;
    for (int y = 0; y <= ImageHeight(img1) - ImageHeight(img2); y++) {
        for (int x = 0; x <= ImageWidth(img1) - ImageWidth(img2); x++) {
            count++; // Aumenta a contagem para cada tentativa de correspondência
        }
    }
    return count;
}

int main(void) {
    printf("Testando ImageLocateSubImage\n");

    // Carrega a imagem principal e a subimagem
    Image mainImage = ImageLoad("pgm/other/tools_2_765x460.pgm");
    Image subImage = ImageLoad("pgm/small/bird_256x256.pgm");

    if (!mainImage || !subImage) {
        fprintf(stderr, "Erro ao carregar imagens.\n");
        return 1; // Retorna erro, cado as imagens não puderem ser carregadas
    }

    // Aqui estão as variáveis para armazenar a posição da subimagem encontrada
    int pos_x, pos_y;

    // Conta o número de comparações
    int num_comparisons = countComparisons(mainImage, subImage);

    // Mede o tempo de execução
    double start_time = cpu_time();
    int found = ImageLocateSubImage(mainImage, &pos_x, &pos_y, subImage);
    double finish_time = cpu_time();

    // Calcula o tempo de execução
    double exec_time = finish_time - start_time;

    // Mostra os resultados
    if (found) {
        printf("Subimagem encontrada na posição (%d, %d)\n", pos_x, pos_y);
    } else {
        printf("Subimagem não encontrada.\n");
    }
    printf("Número de comparações: %d\n", num_comparisons);
    printf("Tempo de execução: %f segundos\n", exec_time);

    // Limpa as imagens da memória
    ImageDestroy(&mainImage);
    ImageDestroy(&subImage);

    return 0;
}
