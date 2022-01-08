NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
initializing/assign_indexing.c \
initializing/check_input.c \
initializing/check_number.c \
initializing/create_number_array.c \
initializing/fill_array.c \
initializing/get_stack_size.c \
initializing/initialize_stacks.c \
initializing/free_memory.c \
operations/push.c \
operations/rotate.c \
operations/reverse_rotate.c \
operations/swap.c \
sort/sort_numbers.c \
sort/sort_three.c \
sort/sort_five.c \
sort/sort_radix.c \

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = libft/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)libft.a -o $(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f *.o
	rm -f */*.o

fclean:
	make fclean -C $(LIBFT_PATH)
	rm -f *.o
	rm -f */*.o
	rm -f $(NAME)

re:	fclean all