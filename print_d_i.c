/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   print_d_i.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/08 16:10:28 by lboudjel		  #+#	#+#			 */
/*   Updated: 2023/05/10 17:11:55 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d_i(va_list args)
{
	long long int	n;

	n = va_arg(args, int);
	ft_putnbr(n);
	return (count_len(n));
}
