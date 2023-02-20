#include <stdio.h>
#include <stdlib.h>
#include <bmp.h>

#define BLACK {0, 0, 0}
#define WHITE {255, 255, 255}
#define RED   {255 , 0, 0}
#define BROWN {150, 75, 0}
#define BLUE  {0, 0, 255}
#define PINK  {255, 192, 203}

#define SQUARE_SIZE 100
#define BOARD_SIZE 8

void create_bmp(BMP_rgb_t c1, BMP_rgb_t c2);

BMP_rgb_t gptr[BOARD_SIZE*SQUARE_SIZE][BOARD_SIZE*SQUARE_SIZE];

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("No arguments given, resorting to black and white\n");
        create_bmp((BMP_rgb_t)PINK, (BMP_rgb_t)BROWN);
    }
    return 0;
}

void fill_square(BMP_rgb_t ptr[BOARD_SIZE*SQUARE_SIZE][BOARD_SIZE*SQUARE_SIZE], int ro, int co, BMP_rgb_t c)
{
    for(int row=ro; row<ro+SQUARE_SIZE; row++)
    {
        for(int col=co; col<co+SQUARE_SIZE; col++)
        {
            ptr[row][col] = c;
        }
    }
}

void create_bmp(BMP_rgb_t c1, BMP_rgb_t c2)
{
    BMP_rgb_t colors[] = {c1, c2};

    int row_offset = 0;
    int col_offset = 0;
    BMP_rgb_t color = c1;
    int auxCount = 0;
    int test_n = 8;

    for(int i = 0; i < test_n; i++)
    {
        col_offset = 0;
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            color = colors[(int)((i + j)%2 == 0)];
            fill_square(gptr, row_offset, col_offset, color);
            col_offset +=SQUARE_SIZE;
            auxCount++;
        }
        row_offset += SQUARE_SIZE;
        auxCount += 1;
    }

    BMP_create("test.bmp", (char *)gptr, BOARD_SIZE*SQUARE_SIZE, BOARD_SIZE*SQUARE_SIZE);
}