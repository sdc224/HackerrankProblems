#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int arr[6][6], i, j;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
			scanf_s("%d", &arr[i][j]);
	
	int max = INT_MIN, column_limiter = 0, sum, row_count = 0;

	// We don't need to continue the loop till arr_rows, as for 6 X 6, max row for this operation is 4(0+3)
	for (i = 0; i < 6 - 2; i++)
	{
		sum = 0;
		
		for (j = 0; j < column_limiter + 3; j++)
		{
			if (row_count == 1)
			{
				sum += arr[i][j + 1];
				break;
			}

			else
				sum += arr[i][j];
			/*if (j == column_limiter)
				sum += arr[i + 1][column_limiter + 1];*/

		}

		if (row_count < 3)
			row_count++;
		else
			row_count = 0;
			
		// To increase the no of columns
		if(column_limiter < 3)
			column_limiter++;
		else
			column_limiter = 0;

		// To compare the sum with max value and store it in sum to return
		if(sum > max)
			max = sum;

		/*if(column_limiter != 0)
			i--;*/
	}
	
	printf("%d", sum);
	return 0;
}