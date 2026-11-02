#define ROW 5
#define COL 5

#include <stdio.h>

int main() 
{
	int row, col;
	printf("\n");
	for (row = 1; row <= ROW; row++)
	{
		for (col = 1; col <= row; col++)
			printf("%5d", 5);
		printf("\n");
	}
	getchar();
	return 0;
}