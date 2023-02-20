#include <stdint.h>

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
				
} BMP_rgb_t;

void BMP_create(char *filename, char *rgb_arr, int width, int height);
