#include "../includes/bsq.h"

/*
	desc:
			- frees the Map if it exists
			- frees the matrix if it exists
			it actually cleans up resources and returns true or false
*/
bool	ft_clear(t_data *d, unsigned short **matrix, bool ret)
{
	if (d->map)
		free(d->map);
	if (matrix)
		free_matrix(matrix, d);
	return (ret);
}
/*
	desc:
		- the main logic for solving the BSQ problem
*/
bool	solve(t_data *d, char *file)
{
	unsigned short	**matrix;

	init_data(d);
	if (!file)
	{
		if (!read_stdin(d))
			return (ft_clear(d, NULL, false));
	}
	else
	{
		if (!read_file(d, file))
			return (ft_clear(d, NULL, false));
	}
	matrix = init_matrix(d);
	if (!matrix)
		return (ft_clear(d, NULL, false));
	if (!process(d, matrix))
		return (ft_clear(d, matrix, false));
	if (PRINT == 0)
		display_bsq(d, matrix);
	return (ft_clear(d, matrix, true));
}

int	main(int ac, char **av)
{
	t_data	d;
	int		i;

	if (ac > 1)
	{
		i = 1;
		while (i < ac && solve(&d, av[i]))
		{

			i++;
			write(1,"\n",1);
		}
		if (i < ac)
			return (1);
	}
	else
		return (solve(&d, NULL));
	
	return (0);
		
}
