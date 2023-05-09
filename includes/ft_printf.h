/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:57:46 by lboudjel          #+#    #+#             */
/*   Updated: 2023/05/08 00:57:46 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *str, ...);
int     print_c(va_list args);
int	print_d_i(va_list args);
//int		print_s(va_list args);
int	print_pourcent(void);
int	print_s(va_list args);
int	print_u(va_list args);
int	print_x(va_list args);




void	ft_putchar(char c);
int		ft_putstr(const char *str);
void	ft_putnbr(int n);
void	ft_putnbr_positive(unsigned int n);
void	ft_putnbr_base(unsigned long long int nb, char *base);

#endif