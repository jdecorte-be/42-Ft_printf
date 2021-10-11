#include "includes/ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_base(unsigned int i, unsigned int base_length, char *base)
{
	if (i > base_length)
	{
		ft_base(i / base_length, base_length, base);
		ft_base(i % base_length, base_length, base);
	}
	else
	{
		ft_putchar(base[i]);
	}
}

t_print *ft_initialise_tab(t_print *tab)                       
{                       
      tab->len = 0;     
      tab->prc = 0;                        
      tab->zero = 0;                        
      tab->pnt = 0;                        
      tab->sign = 0;                        
      tab->tl = 0;                        
      tab->is_zero = 0;                        
      tab->dash = 0;                        
      tab->perc = 0;                        
      tab->sp = 0;                        
      return (tab);                       
}

//----------------------------------------------------------------

int	ischar(t_print *tab)
{
	int len = 0;
	char res;
	res = va_arg(tab->args, unsigned int);
	tab->len += 1;
	ft_putchar(res);
	return len;
}
char	isstring(t_print *tab)
{
	char *res;

	res = va_arg(tab->args, char *);
	if(res == NULL)
	{
		ft_putstr("(null)");
		tab->len += 6;
		return 0;
	}
	int i = 0;
	while(res[i])
	{
		ft_putchar(res[i]);
		tab->len++;
		i++;
	}
	return 0;
}
int	ispointer(t_print *tab)
{
	int len = 0;
	unsigned long res;
	res = va_arg(tab->args, unsigned long);
	write(1, &"0x", 2);
	ft_base(res, 16, "0123456789abcdef");
	tab->len += 2;
	return len;
}
int	isint(t_print *tab)
{
	int len = 0;
	int res;
	char intmin[] = "-2147483648";
	res = va_arg(tab->args, unsigned int);
	if (-2147483647 >= res)
	{
		ft_putstr(intmin);
		tab->len += ft_strlen(intmin);
		return 0;
	}
	ft_putnbr(res);
	if (res < 0)
	{
		res = res * -1;
		len++;
	}
	if (res == 0)
		len = 1;
	while(res > 0)
	{
		res = res / 10;
		len++;
	}
	tab->len += len;
	return 0;
}
int	isdecint(t_print *tab)
{
	int len = 0;
	unsigned int res;

	res = va_arg(tab->args, unsigned int);
	
	ft_putnbr(res);
	if (res < 0)
	{
		res = res * -1;
		len++;
	}
	if (res == 0)
		len = 1;
	while(res > 0)
	{
		res = res / 10;
		len++;
	}
	tab->len += len;
	return len;
}
int	ishex(t_print *tab)
{
	int len2 = 0;
	int res;

	res = va_arg(tab->args, unsigned int);
	write(1,"0x",2);
	ft_base(res, 16, "0123456789abcdef");
	tab->len+=len2;
}
void	isperc(t_print *tab)
{
	ft_putchar('%');
	tab->len++;
}

void ft_conv(char c, t_print *tab)
{
	if (c == 'c')
		ischar(tab);
	else if (c == 's')
		isstring(tab);
	else if (c == 'p')
		ispointer(tab);
	else if (c == 'd' || c == 'i')
		isint(tab);
	if (c == 'u')
		isdecint(tab);
	if (c == 'x' || c == 'X')
		ishex(tab);
	if (c == '%')
		isperc(tab);
}

// ----------------------------------------------------------------

int ft_printf(const char *input, ...)
{
	t_print *tab;
	tab = malloc(sizeof(t_print));
	if(!tab)
		return -1;
	tab = ft_initialise_tab(tab);
	int i = 0;

	va_start(tab->args, input);
	while(input[i])
	{
		if(input[i] == '%')
		{
			if(ft_strchr("cspdiuxX%", input[i + 1]))
			{
				ft_conv(input[i + 1], tab);
				i++;
			}
		}
		else
		{
			ft_putchar(input[i]);
			tab->len ++;
		}
		i++;
	}
	va_end(tab->args);
	free(tab);
	return tab->len;
}

int main()
{
	ft_printf("Hello %x ", 400);
}