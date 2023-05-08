/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:18:15 by lboudjel          #+#    #+#             */
/*   Updated: 2023/05/08 16:30:50 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	print_u(va_list args)
{
	unsigned long long int	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_positive(n);
	return (count_len(n));
}
