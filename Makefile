NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

MAN = push_swap.c

SRCS = stack.c \
	from_b_to_a.c\
	from_a_to_b.c\
	ft_split.c \
	push_swap_utils1.c\
	push_swap_utils2.c\
	push_swap_utils3.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(MAN) -o $@

%.o: %.c push_swap.h $(MAN)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(MAN:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re