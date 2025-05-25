#include <stdlib.h>
#include <stdio.h>

/**
 * grid_addition - Adds two 3x3 grids element-wise.
 * @grid1: First 3x3 grid.
 * @grid2: Second 3x3 grid.
 */
void grid_addition(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
}

/**
 * grid_print - Prints a 3x3 grid.
 * @grid: 3x3 grid to print.
 */
void grid_print(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * grid_is_ok - Checks if all values in a 3x3 grid are less than or equal to 3.
 * @grid: 3x3 grid to check.
 *
 * Return: 1 if all values are ≤ 3, 0 otherwise.
 */
int grid_is_ok(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * grid_change - Performs one iteration of sandpile toppling.
 * @grid1: 3x3 grid to modify.
 */
void grid_change(int grid1[3][3])
{
	int i, j;
	int gridx[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			gridx[i][j] = 0;
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i - 1 >= 0)
					gridx[i - 1][j] += 1;
				if (j - 1 >= 0)
					gridx[i][j - 1] += 1;
				if (i + 1 < 3)
					gridx[i + 1][j] += 1;
				if (j + 1 < 3)
					gridx[i][j + 1] += 1;
			}
		}
	}
	grid_addition(grid1, gridx);
}

/**
 * sandpiles_sum - Adds two sandpiles and stabilizes the result.
 * @grid1: First 3x3 grid.
 * @grid2: Second 3x3 grid.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid_addition(grid1, grid2);
	while (!grid_is_ok(grid1))
	{
		grid_print(grid1);
		grid_change(grid1);
	}
}
