/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   print_u.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/08 16:18:15 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/05/10 17:11:55 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(va_list args)
{
	size_t	n;

	n = va_arg(args, size_t);
	ft_putnbr_positive(n);
	return (count_len_u(n));
}
