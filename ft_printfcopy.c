/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/08 00:57:37 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/05/08 00:57:37 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	count_len(int n)
{	
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	count_base(unsigned long long int n)
{	
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	print_c(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar(c);
	return (1);
}

int	print_d_i(va_list args)
{
	int	n;

	n = va_arg(args, int);
	ft_putnbr(n);
	return (count_len(n));
}

int	print_pourcent(void)
{
	ft_putchar('%');
	return (1);
}

int	print_s(va_list args)
{
	const char	*s;

	s = va_arg(args, const char *);
	return (ft_putstr(s));
}

int	print_u(va_list args)
{
	unsigned long long int	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_positive(n);
	return (count_len(n));
}

int	print_x(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_base(n, "0123456789abcdef");
	return (count_base(n));
}

int	print_X(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_base(n, "0123456789ABCDEF");
	return (count_base(n));
}

int	print_p(va_list args)
{
	unsigned long	n;

	n = (unsigned long)va_arg(args, void *);
	if (n == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	ft_putnbr_base(n, "0123456789abcdef");
	return (count_base(n));
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

void	ft_putnbr(int n)
{
	long long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if (nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_putnbr_positive(unsigned int n)
{
	unsigned long long int	nb;

	nb = n;
	if (nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_putnbr_base(unsigned long long int nb, char *base)
{
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, base);
		write(1, &base[nb % 16], 1);
	}
	else
		write(1, &base[nb], 1);
}



int	check(char c, va_list args)
{
	if (c == '%')
		return (print_pourcent());
	if (c == 'c')
		return (print_c(args));
	if (c == 'p')
		return (print_p(args));
	if (c == 's')
		return (print_s(args));
	if (c == 'd' || c == 'i')
		return (print_d_i(args));
	if (c == 'u')
		return (print_u(args));
	if (c == 'x')
		return (print_x(args));
	if (c == 'X')
		return (print_X(args));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int i;
	int	count;
	va_list args;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = count + check(str[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}



int main(void)
{
	printf("longueur de mon printf %d\n", ft_printf("bonjour %d", 1000));
	printf("longueur de printf %d\n", printf("bonjour %d", 1000));

	printf("longueur de mon printf %d\n", ft_printf("bonjour %c", 'a'));
	printf("longueur de printf %d\n", printf("bonjour %c", 'a'));
}