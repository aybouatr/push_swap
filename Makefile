PROG = push_swap
PROG_B = push_swap_bonus

SRC = srcs/push_swap.c srcs/check_error.c srcs/ft_split.c srcs/link_list.c srcs/push_a.c srcs/push_b.c \
      srcs/rank.c srcs/rev_rotate_rra.c srcs/rev_rotate_rrb.c srcs/rev_rotate_rrr.c srcs/rotate_ra.c \
      srcs/rotate_rb.c srcs/rotate_rr.c srcs/swap_a.c srcs/swap_b.c srcs/swap_ss.c srcs/swap_first_last.c

SRC_B = srcs/push_swap_bonus.c srcs/check_error.c srcs/ft_split.c srcs/link_list.c srcs/push_a.c srcs/push_b.c \
        srcs/rank.c srcs/rev_rotate_rra.c srcs/rev_rotate_rrb.c srcs/rev_rotate_rrr.c srcs/rotate_ra.c \
        srcs/rotate_rb.c srcs/rotate_rr.c srcs/swap_a.c srcs/swap_b.c srcs/swap_ss.c srcs/swap_first_last.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADER = -I./includes

%.o : srcs/%.c
	@$(CC) $(HEADER) $(CFLAGS) -c $< -o $@

all : $(PROG)

$(PROG) : $(OBJ)
	@$(CC) $(OBJ) -o $(PROG)

bonus : $(OBJ_B)
	@$(CC) $(OBJ_B) -o $(PROG_B)

clean :
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_B)
fclean : clean
	@rm -rf $(PROG)
	@rm -rf $(PROG_B)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus bonus clean
