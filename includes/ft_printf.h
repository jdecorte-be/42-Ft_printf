#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_print
{
	va_list	args;
	int		len;
}		t_print;

int		ft_printf(const char *input, ...);
size_t	ft_strlen(const char *theString);
int		isint(t_print *tab);
int		ischar(t_print *tab);
int		ispointer(t_print *tab);
int		ishex(t_print *tab);
int		isint(t_print *tab);
int		isdecint(t_print *tab);

char	isstring(t_print *tab);

void	isperc(t_print *tab);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

char	*ft_strchr(const char *string, int searchedChar);
char	*ft_itoa(int nb);

#endif
