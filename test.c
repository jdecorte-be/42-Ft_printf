#include <stdio.h>
#include <unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nb, int i)
{
	unsigned int	nbr;
	char			*base;

	base = "0123456789abcdef";
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, ++i);
	if (i == 1)
		ft_putchar('0');
	ft_putchar(base[nbr % 16]);
}

int main()
{
	printf(" %p ", 1);
}