#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
/*
	explanations:
		1.BUFFER_SIZE:This large buffer is used for reading input (likely entire map data).
		2.BUFFER_INIT: Initial buffer size set to 4096.
		3.BUFFER_STDIN: Buffer size for standard input set to 280000.
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	100000000 
# endif

# define BUFFER_INIT	4096
# define BUFFER_STDIN	280000

# ifndef DEBUG
#  define DEBUG			0
# endif

# ifndef PRINT
#  define PRINT			0
# endif

/*
	explanations:
		This structure holds all relevant information needed for BSQ problm:
	1.map: A pointer to the map data.
	2.(empty, obstacle, filler): 
		Characters representing empty spaces, obstacles, and the square filler.
	3.(nbr_lines, len_lines): 
		Number of lines in the map and the length of each line.
	4.(bsq_x, bsq_y): Coordinates for the top-left corner of the largest square.
	5.n: A large number likely representing the number of elements or the area.
	6.fd: File descriptor.
*/

typedef struct s_data
{
	char			*map;
	char			empty;
	char			obstacle;
	char			filler;
	unsigned int	nbr_lines;
	unsigned int	len_lines;
	unsigned int	bsq_x;
	unsigned int	bsq_y;
	unsigned long	n;
	int				fd;
}					t_data;

bool			read_file(t_data *d, char *file);
bool			read_stdin(t_data *d);
bool			map_arg(t_data *d);
bool			read_len_lines(t_data *d);

bool			process(t_data *d, unsigned short **matrix);

void			display_bsq(t_data *d, unsigned short **matrix);

void			init_data(t_data *data);
unsigned short	**init_matrix(t_data *d);
void			free_matrix(unsigned short **matrix, t_data *data);
unsigned short	**free_matrix_i(unsigned short **matrix, int i);

char			*ft_strjoin_bsq(char *s1, const size_t size1,
					char *s2, const size_t size2);
bool			print_error(char *str);

#endif
