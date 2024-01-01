NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SMAN = push_swap.c

OMAN = $(SMAN:.c=.o)

SBON = checker.c

OBON = $(SBON:.c=.o)

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

$(NAME): $(OBJS) $(OMAN)
	$(CC) $(CFLAGS) $^ -o $@

$(BONNAME): $(OBJS) $(OBON)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c push_swap.h 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OMAN) $(OBON)

fclean: clean
	$(RM) $(NAME) $(BONNAME)

re: fclean all

bonus: $(BONNAME)

.PHONY: all clean fclean re