#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "instrumentation.h"
#include "image8bit.h"

int main() {
    // Inicializa a biblioteca de imagens
    ImageInit();

    // Carrega a imagem original
    Image originalImage = ImageLoad("pgm/small/bird_256x256.pgm");
    if (originalImage == NULL) {
        fprintf(stderr, "Erro ao carregar a imagem original.\n");
        return 1;
    }

    // Define as dimensões da região a ser recortada para criar a subimagem
    int cropX = 100; // Coordenada X do canto superior esquerdo da região de corte
    int cropY = 100; // Coordenada Y do canto superior esquerdo da região de corte
    int cropWidth = 200; // Largura da região de corte
    int cropHeight = 200; // Altura da região de corte

    // Cria a subimagem a partir da imagem original
    Image subImage = ImageCrop(originalImage, cropX, cropY, cropWidth, cropHeight);
    if (subImage == NULL) {
        fprintf(stderr, "Erro ao criar a subimagem.\n");
        ImageDestroy(&originalImage);
        return 1;
    }

    // Salva a subimagem em um arquivo
    if (ImageSave(subImage, "pgm/other") == 0) {
        fprintf(stderr, "Erro ao salvar a subimagem.\n");
    }

    // Liberta a memória das imagens
    ImageDestroy(&originalImage);
    ImageDestroy(&subImage);

    return 0;
}
