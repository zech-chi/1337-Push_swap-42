NAME = push_swap.a
MANSRCS = ft_split.c push_swap.c push_swap_utils1.c stack.c
MANOBJS = $(MANSRCS:.c = .o)

$(NAME) : $(MANOBJS)
	ar -rcs $@ $^

all: $(NAME)

%.o : %.c push_swap.h
	cc -Wall -Wextra -Werror -c $^ -o $@

clean:
	rm -f $(MANOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean
