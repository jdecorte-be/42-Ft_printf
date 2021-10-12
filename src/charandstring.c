#include "../includes/ft_printf.h"

int	ischar(t_print *tab)
{
	int		len;
	char	res;

	len = 0;
	res = va_arg(tab->args, unsigned int);
	tab->len += 1;
	ft_putchar(res);
	return (len);
}

char	isstring(t_print *tab)
{
	char	*res;
	int		i;

	res = va_arg(tab->args, char *);
	if (res == NULL)
	{
		ft_putstr("(null)");
		tab->len += 6;
		return (0);
	}
	i = 0;
	while (res[i])
	{
		ft_putchar(res[i]);
		tab->len++;
		i++;
	}
	return (0);
}
