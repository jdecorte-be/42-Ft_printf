NAME = libft.a

SRC = ft_printf.c	\

FILEO = $(SRC:.c=.o)

HEADER = libft.h

WWW = -Wall -Werror -Wextra

$(NAME):
	gcc $(WWW) -c $(SRC) -I ./includes
	ar rc $(NAME) $(FILEO)
	ranlib $(NAME)

all: $(NAME)

clean:
	/bin/rm -f $(FILEO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all 

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)