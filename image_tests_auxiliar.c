//Test file for image8bit.c file, to see if ImageStats, ImageGetPixel and ImageSetPixel are working properly
//gcc -o image_tests image_tests.c image8bit.c instrumentation.c -I ------ and then ./image_tests

#include "image8bit.h" 
#include <stdio.h>
#include <assert.h>

void testImageGetSetPixel() {
    Image img = ImageCreate(10, 10, 255);
    assert(img != NULL);

    // Test 1: set pixel and get pixel
    ImageSetPixel(img, 5, 5, 123);
    uint8 pixelValue = ImageGetPixel(img, 5, 5);
    assert(pixelValue == 123);

    ImageDestroy(&img);
}

int main() {
    printf("Iniciando testes...\n");
    
    testImageGetSetPixel();
    
    printf("Todos os testes passaram.\n");
    return 0;
}

