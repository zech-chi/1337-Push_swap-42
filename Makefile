NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

MAN = push_swap.c

BON = checker.c

BONNAME = checker

SRCS = stack.c \
	from_a_to_b.c\
	from_b_to_a.c\
	ft_split.c \
	push_swap_utils1.c\
	push_swap_utils2.c\
	push_swap_utils3.c\
	get_next_line.c\
	get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(MAN)
	$(CC) $(CFLAGS) $^ $(MAN) -o $@

$(BONNAME): $(OBJS) $(BON)
	$(CC) $(CFLAGS) $^ $(BON) -o $@

%.o: %.c push_swap.h 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(MAN:.c=.o) $(BON:.c=.o)

fclean: clean
	$(RM) $(NAME) $(BONNAME)

re: fclean all

bonus: $(BONNAME)

.PHONY: all clean fclean re