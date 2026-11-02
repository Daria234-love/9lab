#define ROW 5
#define COL 5

#include <stdio.h>

int main() 
{
	int row, col;
	printf("\n");
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL - row; col++)
			printf("%5d", 20 - row + col);
		printf("\n");
	}
	getchar();
	return 0;
}