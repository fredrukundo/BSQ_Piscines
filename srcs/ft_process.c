#include "../includes/bsq.h"

/*
	desc:
	This function updates the matrix when an empty cell is encountered.
	 It calculates the size of the square that can be formed at
	  the current position (x, y) based on the surrounding cells.
*/
static void	process_empty(t_data *d, unsigned short **matrix,
	unsigned int x, unsigned int y)
{
	unsigned short	tmp;

	if (x == 0 || y == 0)
		matrix[y][x] = 1;
	else
	{
		if (matrix[y - 1][x] > matrix[y][x - 1])
			tmp = matrix[y][x - 1];
		else
			tmp = matrix[y - 1][x];
		if (tmp > matrix[y - 1][x - 1])
			matrix[y][x] = matrix[y - 1][x - 1] + 1;
		else
			matrix[y][x] = tmp + 1;
		if (matrix[y][x] > matrix[d->bsq_y][d->bsq_x])
		{
			d->bsq_y = y;
			d->bsq_x = x;
		}
	}
}
/*
	desc:
		This function checks if the current line 
		ends correctly and that all lines in the map have the same length
*/

static bool	process_end_check(t_data *d,
	unsigned int *x, unsigned int *y, unsigned int i)
{
	if (d->map[i] == '\n')
	{
		if (x[0] != d->len_lines)
			return (print_error(
					"Error: map error\t(all lines should be the same length)\n"));
		x[0] = -1;
		y[0] += 1;
	}
	else
		return (print_error(
				"Error: map error\t(all lines should be the same length)\n"));
	return (true);
}

/*
	desc:
		This function is the main processing loop that iterates over each character in the map, 
		updating the matrix and finding the largest square.
*/
bool	process(t_data *d, unsigned short **matrix)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;

	i = d->n;
	x = 0;
	y = 0;
	while (i < (d->len_lines + 1) * d->nbr_lines)
	{
		if (y >= d->nbr_lines)
			return (print_error(
					"Error: map error\t(lines over number of lines in arg)\n"));
		else if (d->map[i] == d->empty)
			process_empty(d, matrix, x, y);
		else if (d->map[i] == d->obstacle)
			matrix[y][x] = 0;
		else if (!process_end_check(d, &x, &y, i))
			return (false);
		i++;
		x++;
	}
	return (true);
}
