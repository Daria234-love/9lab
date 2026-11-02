#define ROW 9
#define COL 9

#include <stdio.h>

int main() 
{
	int row, col;
	printf("\n");
	for (row = 1; row <= ROW; row++)
	{
		for (col = 1; col <= COL; col++)
			printf("%5d", col * row);
		printf("\n");
	}
	getchar();
	return 0;
}