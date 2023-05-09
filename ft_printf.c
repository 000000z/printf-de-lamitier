/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:57:37 by lboudjel          #+#    #+#             */
/*   Updated: 2023/05/08 00:57:37 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include "includes/ft_printf.h"

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
	int	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_base(n, "0123456789abcdef");
	return (count_base(n));
}

int	print_X(va_list args)
{
	int	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_base(n, "0123456789ABCDEF");
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


int		ft_printf(const char *str, ...)
{
    int i;
    va_list args;

    va_start(args, str);

    i = 0;
    while(str[i])
    {
        if (str[i] == '%' && str[i + 1] == '%')
        {
            i++;
            print_pourcent();
            i++;
        }
        if (str[i] == '%' && str[i + 1] == 'c')
        {
            i++;
            print_c(args);
            i++;
        }
        if (str[i] == '%' && str[i + 1] == 's')
        {
            i++;
            print_s(args);
            i++;
        }
        if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
        {
            i++;
            print_d_i(args);
            i++;
        }
        if (str[i] == '%' && str[i + 1] == 'u')
        {
            i++;
            print_u(args);
            i++;
        }
        if (str[i] == '%' && str[i + 1] == 'x')
        {
            i++;
            print_x(args);
            i++;
        }
        if (str[i] == '%' && str[i + 1] == 'X')
        {
            i++;
            print_X(args);
        }
        else
            ft_putchar(str[i]);
            i++;

    }
    return (i);

    va_end(args);

}

int main(void)
{
    char c = 'a';
    char *s = "Hello, World!";
    void *p = &s;
    int d = -42;
    unsigned int u = 42;
    unsigned int x = 0xDEADBEEF;

    ft_printf("%%c: %c\n", c);
    ft_printf("%%s: %s\n", s);
    ft_printf("%%p: %p\n", p);
    ft_printf("%%d: %d\n", d);
    ft_printf("%%i: %i\n", d);
    ft_printf("%%u: %u\n\n", u);
    ft_printf("%%x: %x\n", x);
    ft_printf("%%X: %X\n\n", x);

    printf("%%c: %c\n", c);
    printf("%%s: %s\n", s);
    printf("%%p: %p\n", p);
    printf("%%d: %d\n", d);
    printf("%%i: %i\n", d);
    printf("%%u: %u\n", u);
    printf("%%x: %x\n", x);
    printf("%%X: %X\n", x);

    return 0;
}




/*int main()
{
    ft_printf("mon print f : salut %c okok %c\n", 'a', 'b');
    printf("print f : salut %c okok %c\n", 'a', 'b');

    ft_printf("mon print f : salut %s okok %s\n", "wsh", "ok");
    printf("print f : salut %s okok %s\n", "wsh", "ok");

    ft_printf("mon print f : salut %%\n");
    printf("print f : salut %%\n");

    ft_printf("mon print f : salut %d\n", 0);
    printf("print f : salut %d\n", 0);

    ft_printf("mon print f : salut %i\n", 10);
    printf("print f : salut %i\n", 10);

    ft_printf("mon print f : salut %u\n", 0);
    printf("print f : salut %u\n", 0);

    ft_printf("mon print f : salut %x\n", 0x3a);
    printf("print f : salut %x\n", 0x3a);

    ft_printf("mon print f : salut %X\n", 0x3A);
    printf("print f : salut %X\n", 0x3A);

}*/