#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"
#include "stb_image_resize.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Specify the input and output file names
    char *input_filename = "ENTER HERE ABSOLUTE PATH TO THE PICTURE";  // Filename of the picture we want to resize
    char *output_filename = "result.jpg";  // (Future) name of the resized image

    int width, height, channels;

    unsigned char *image = stbi_load(input_filename, &width, &height, &channels, 0);
    if (image == NULL) {
        fprintf(stderr, "Error loading image: %s\n", input_filename);
        return 1;
    }

    // Calculate the new dimensions (half the size in this example)
    int new_width = width / 2;
    int new_height = height / 2;

    unsigned char *resized_image = (unsigned char *)malloc(new_width * new_height * channels);
    if (resized_image == NULL) {
        fprintf(stderr, "Error allocating memory for resized image\n");
        stbi_image_free(image);
        return 1;
    }

    if (!stbir_resize_uint8(image, width, height, 0, resized_image, new_width, new_height, 0, channels)) {
        fprintf(stderr, "Error resizing image\n");
        free(resized_image);
        stbi_image_free(image);
        return 1;
    }

    if (!stbi_write_png(output_filename, new_width, new_height, channels, resized_image, new_width * channels)) {
        fprintf(stderr, "Error saving resized image: %s\n", output_filename);
        free(resized_image);
        stbi_image_free(image);
        return 1;
    }

    printf("Image resized successfully: %s\n", output_filename);

    free(resized_image);
    stbi_image_free(image);

    return 0;
}