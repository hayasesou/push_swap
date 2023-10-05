NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
M_FILES =	new_doubly.c add_back_doubly.c make_circular_doubly.c\
			swap.c push.c shift_up.c shift_down.c push_swap_main.c\
			argument_check.c display_Error.c insertion_in_stack_a.c\
			coordinate_compression.c check_list_order.c\
			quick_sort.c insertion_in_stack_b.c stack_b_3number.c\
			small_large_quick.c push_utils.c debug.c list_utils.c\

LIBFT_DIR = ./libft
LIBFT = ft
PRINTF_DIR = ./printf
PRINTF = ftprintf
SRC_DIR = ./srcs
INCLUDE_DIR = ./include
INCLUDE = -I $(INCLUDE_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)
LDFLAGS = -L$(LIBFT_DIR) -l$(LIBFT) -L$(PRINTF_DIR) -l$(PRINTF)

SOURCES = $(addprefix $(SRC_DIR)/,$(M_FILES))
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		make -C $(LIBFT_DIR)
		make -C $(PRINTF_DIR)
		$(CC) $(CFLAGS) $(INCLUDE) $(LDFLAGS) $(OBJECTS) -o $@

.c.o: $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	$(RM) $(OBJECTS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)


re:	fclean all
