#include <unistd.h>

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
