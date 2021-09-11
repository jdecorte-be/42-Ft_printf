#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

void ft_putchar(char c);

int ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int		isvalid(char c, int base)
{
	char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";

	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int		value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int result;
	int sign;

	result = 0;
	while (ft_isblank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (isvalid(*str, str_base))
		result = result * str_base + value_of(*str++);
	return (result * sign);
}

void ft_putchar(char c)
{
    write(1,&c,1);
}

void	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

// print char
void ft_printc(int c)
{
    write(1, &c, 1);
}

// print nbr
char ft_printd(int n)
{
    if (n < 0)
    {
    ft_putchar('-');
    n = -n;
    }
    if (n >= 10)
    {
    ft_printd(n / 10);
    ft_putchar(n % 10 + '0');
    }
    if (n < 10)
    {
    ft_putchar(n % 10 + '0');
    }
    return (n);  
}

int ft_printi(int n)
{
    if (n < 0)
    {
    ft_putchar('-');
    n = -n;
    }
    if (n >= 10)
    {
    ft_printd(n / 10);
    ft_putchar(n % 10 + '0');
    }
    if (n < 10)
    {
    ft_putchar(n % 10 + '0');
    }
    return (n); 
}

int ft_printo(char *str)
{
    int i = ft_atoi_base(str , 2);
    ft_printi(i);
}

int ft_printf(const char *input, ...)
{
    int i = 0;

    va_list parametersInfos;
    va_start( parametersInfos, input );
    while(input[i])
    {
        if(input[i] == '%')
        {
            if(input[i+1] == 'c')
            {
                char charvalue = (char) va_arg(parametersInfos, int);
                ft_printc(charvalue);
            }
            if(input[i+1] == 'd')
            {
                int integerValue = (int) va_arg( parametersInfos, int );
                ft_printd(integerValue);
            }
            if(input[i+1] == 'i')
            {
                int integerValue = (int) va_arg( parametersInfos, int );
                ft_printd(integerValue);
            }
            // if(input[i+1] == 'o')
            // {
            //     unsigned char *integerValue = (unsigned char *) va_arg( parametersInfos, int );
            //     ft_printo(integerValue);
            // }

            i++;
        }
        else
        {
            write(1,&input[i], 1);
        }
        i++;
    }
    va_end( parametersInfos );
}

int main()
{
    int nbr = 10;
    int nbr2 = 42;
    ft_printf("Nbr : %d %d\n", nbr, nbr2);
    printf("Nbr : %d", nbr);

}