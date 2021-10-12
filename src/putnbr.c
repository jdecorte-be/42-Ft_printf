#include "../includes/ft_printf.h"

int	isint(t_print *tab)
{
	int		res;
	char	*intmin;

	intmin = "-2147483648";
	res = va_arg(tab->args, unsigned int);
	if (-2147483647 >= res)
	{
		ft_putstr(intmin);
		tab->len += ft_strlen(intmin);
		return (0);
	}
	ft_putnbr(res);
	if (res < 0)
	{
		res = res * -1;
		tab->len ++;
	}
	if (res == 0)
		tab->len ++;
	while (res > 0)
	{
		res = res / 10;
		tab->len ++;
	}
	return (0);
}

int	isdecint(t_print *tab)
{
	int				len;
	unsigned int	res;

	len = 0;
	res = va_arg(tab->args, unsigned int);
	ft_putnbr(res);
	if ((int)res < 0)
	{
		res = res * -1;
		len++;
	}
	if (res == 0)
		len = 1;
	while (res > 0)
	{
		res = res / 10;
		len++;
	}
	tab->len += len;
	return (len);
}

void	isperc(t_print *tab)
{
	ft_putchar('%');
	tab->len++;
}
