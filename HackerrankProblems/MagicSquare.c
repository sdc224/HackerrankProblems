#include <math.h>

int formingMagicSquare(int s_rows, int s_columns, int** s) 
{
	int magic_squares_matrix[8][3][3] = 
	{
		{ { 8, 1, 6 },{ 3, 5, 7 },{ 4, 9, 2 } },
		{ { 6, 1, 8 },{ 7, 5, 3 },{ 2, 9, 4 } },
		{ { 4, 9, 2 },{ 3, 5, 7 },{ 8, 1, 6 } },
		{ { 2, 9, 4 },{ 7, 5, 3 },{ 6, 1, 8 } },
		{ { 8, 3, 4 },{ 1, 5, 9 },{ 6, 7, 2 } },
		{ { 4, 3, 8 },{ 9, 5, 1 },{ 2, 7, 6 } },
		{ { 6, 7, 2 },{ 1, 5, 9 },{ 8, 3, 4 } },
		{ { 2, 7, 6 },{ 9, 5, 1 },{ 4, 3, 8 } },
	};

	int min_cost = 81;

	for (int k = 0; k < 8; k++) 
	{
		int create_cost = 0;
		for (int i = 0; i < s_rows; i++) 
		{
			for (int j = 0; j < s_columns; j++)
				create_cost += abs(s[i][j] - magic_squares_matrix[k][i][j]);
		}

		if (create_cost < min_cost)
			min_cost = create_cost;
	}

	return min_cost;
}
