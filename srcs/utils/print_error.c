#include "../../includes/bsq.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	print_error(char *str)
{
	(void)!write(2, str, ft_strlen(str));
	return (false);
}
