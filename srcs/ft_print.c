#include "../includes/bsq.h"
/*
	This function prints the final map to the standard output 
	after the largest square has been marked.
	using (write system call), skips the 1st line(head of map)
*/
static void	print_bsq(t_data *d)
{
	(void)!write(1, &d->map[d->n], d->nbr_lines * (d->len_lines + 1));
}

/*
	This function is for debugging purposes. It prints the matrix 
	that was used to determine the size of the largest square
*/
static void	print_debug(t_data *d, unsigned short **matrix)
{
	unsigned int	x;
	unsigned int	y;

	printf("\n");
	y = 0;
	while (y < d->nbr_lines)
	{
		x = 0;
		while (x < d->len_lines)
		{
			printf("%d", matrix[y][x]);
			x++;
		}
		y++;
		printf("\n");
	}
}

/*
	This function modifies the map by marking the largest square found with the filler character.
*/
static void	paint_bsq(t_data *d, unsigned short **matrix)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	top_left_x;
	unsigned int	top_left_y;

	top_left_x = d->bsq_x - matrix[d->bsq_y][d->bsq_x] + 1;
	top_left_y = d->bsq_y - matrix[d->bsq_y][d->bsq_x] + 1;
	y = 0;
	while (y <= d->nbr_lines)
	{
		x = 0;
		while (x <= d->len_lines)
		{
			if ((y >= top_left_y && y <= d->bsq_y)
				&& (x >= top_left_x && x <= d->bsq_x))
				d->map[(y * (d->len_lines + 1)) + x + d->n] = d->filler;
			x++;
		}
		y++;
	}
}

void	display_bsq(t_data *d, unsigned short **matrix)
{
	paint_bsq(d, matrix);
	print_bsq(d);
	if (DEBUG != 0)
		print_debug(d, matrix);
}
