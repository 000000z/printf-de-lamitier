/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:59:56 by lboudjel          #+#    #+#             */
/*   Updated: 2023/05/08 00:59:56 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/ft_printf.h"

/*
on donne a va_arg un int qu'on cast ensuite en char, pour les char etendu
qui n'ont pas de place dans un char
*/

int	print_c(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar(c);
	return (1);
}
