/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_X.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:15:58 by lboudjel          #+#    #+#             */
/*   Updated: 2023/05/08 16:44:36 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	print_xx(va_list args)
{
	int	n;

	n = (unsigned long long int)va_arg(args, unsigned int);
	ft_putnbr_base(n, "0123456789ABCDEF");
	return (count_base(n));
}
