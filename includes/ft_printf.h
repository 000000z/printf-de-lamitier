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
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>


int		ft_printf(const char *str, ...);

//print

int		print_c(va_list args);
int		print_s(va_list args);
int		print_x(va_list args);
int		print_xx(va_list args);
int		print_u(va_list args);
int		print_d_i(va_list args);
int		print_pourcent(va_list args);
int		print_p(va_list args);

//utiles

void	ft_putchar(char c);
int		ft_putstr(const char *str);
void	ft_putnbr(int n);
void	ft_putnbr_positive(unsigned int n);
void	ft_putnbr_base(unsigned long long int nb, char *base);
int		count_len(int n);
int		count_base(unsigned long long int nb);

#endif