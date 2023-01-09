/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:52:54 by acastilh          #+#    #+#             */
/*   Updated: 2022/11/26 23:10:32 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_format(const char *str, va_list args, int c)
{
	if (str[c + 1] == 'c')
		return (put_char(va_arg(args, int )));
	if (str[c + 1] == 's')
		return (put_string(va_arg(args, char *)));
	if (str[c + 1] == 'i' || str[c + 1] == 'd')
		return (pf_ft_itoa(va_arg(args, int)));
	if (str[c + 1] == 'u')
		return (ft_utoa(va_arg(args, unsigned int)));
	if (str[c + 1] == 'x')
		return (put_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	if (str[c + 1] == 'X')
		return (put_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (str[c + 1] == '%')
		return (put_char('%'));
	if (str[c + 1] == 'p')
		return (put_string("0x") + put_pointer(va_arg(args, void *)));
	return (0);
}
