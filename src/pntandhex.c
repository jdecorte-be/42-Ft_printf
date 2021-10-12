#include "../includes/ft_printf.h"

void	ft_base(unsigned long int i, t_print *tab)
{
	char	z;

	if (i >= 16)
	{
		ft_base(i / 16, tab);
		ft_base(i % 16, tab);
	}
	else if (i < 10)
	{
		tab->len ++;
		z = i + '0';
		write(1, &z, 1);
	}
	else
	{
		tab->len ++;
		z = i - 10 + '0' + 17 + 16;
		write(1, &z, 1);
	}
}

int	ispointer(t_print *tab)
{
	unsigned long	res;

	res = va_arg(tab->args, unsigned long);
	if (res == 0)
	{
		ft_putstr("(nil)");
		tab->len += 5;
		return (0);
	}
	ft_putstr("0x");
	tab->len += 2;
	ft_base(res, tab);
	return (0);
}

int	ishex(t_print *tab)
{
	int	res;

	res = va_arg(tab->args, unsigned int);
	if (res == 0)
	{
		ft_putstr("(nil)");
		tab->len += 5;
		return (0);
	}
	ft_base(res, tab);
	return (0);
}
