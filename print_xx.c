/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   print_X.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/08 16:15:58 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/05/11 15:05:05 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	print_xx(va_list args)
{
	unsigned long long int	n;

	n = va_arg(args, unsigned long long int);
	ft_putnbr_base(n, "0123456789ABCDEF");
	return (count_base(n));
}
