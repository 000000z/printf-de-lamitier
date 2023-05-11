/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   print_p.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/08 16:25:21 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/05/10 17:11:55 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(va_list args)
{
	unsigned long	n;

	n = (unsigned long)va_arg(args, void *);
	if (n == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	ft_putnbr_base(n, "0123456789abcdef");
	return (count_base(n) + 2);
}
