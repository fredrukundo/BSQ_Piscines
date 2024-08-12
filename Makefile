NAME := bsq

SRCS = srcs/ft_print.c srcs/main.c srcs/ft_process.c srcs/ft_read.c srcs/utils/free_matrix.c srcs/utils/print_error.c srcs/utils/ft_strjoin.c srcs/utils/ft_init.c srcs/utils/ft_map_args.c

OBJS := $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

HEADER = includes/bsq.h

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $^ -o $@


%.o: %.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@



clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all
