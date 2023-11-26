#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "instrumentation.h"
#include "image8bit.h"

// Função para testar a função ImageBlur com uma imagem específica e um tamanho de filtro.
void testImageBlur(const char* imagePath, int dx, int dy) {
    printf("Testando ImageBlur com a imagem: %s e filtro de tamanho (%d, %d)\n", imagePath, dx, dy);

    // Carrega a imagem do caminho especificado.
    Image img = ImageLoad(imagePath);
    if (img == NULL) {
        fprintf(stderr, "Falha ao carregar a imagem: %s\n", imagePath);
        return;
    }

    // Regista o tempo de início.
    double start_time = cpu_time();

    // Executa a função ImageBlur.
    ImageBlur(img, dx, dy);

    // Regista o tempo final e calcula o tempo de execução.
    double finish_time = cpu_time();
    double exec_time = finish_time - start_time;

    printf("Tempo de execução (filtro %dx%d): %f segundos\n", (2*dx+1), (2*dy+1), exec_time);

    // Liberta a imagem da memória.
    ImageDestroy(&img);
}

int main(void) {
    // Testa a função ImageBlur com diferentes tamanhos de imagem e de filtro.
    testImageBlur("pgm/small/art4_300x300.pgm", 7, 7);
    testImageBlur("pgm/medium/ireland-03_640x480.pgm", 7, 7);
    testImageBlur("pgm/large/ireland-06-1200x1600.pgm", 7, 7);

    return 0;
}
