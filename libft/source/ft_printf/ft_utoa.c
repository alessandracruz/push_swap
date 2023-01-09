/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:55:44 by acastilh          #+#    #+#             */
/*   Updated: 2022/07/13 14:55:03 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count_u(unsigned int n)
{
	unsigned int	a;
	size_t			count_2;

	a = n;
	count_2 = 0;
	if (a == 0)
		count_2++;
	while (a != 0)
	{
		a = a / 10;
		count_2++;
	}
	return (count_2);
}

int	ft_utoa(unsigned int n)
{
	size_t				count_1;
	char				*num;
	unsigned int		a;
	size_t				i;

	a = n;
	i = 0;
	count_1 = ft_count_u(n);
	num = malloc(sizeof(char) * (count_1 + 1));
	if (!num)
		return (0);
	if (a == 0)
		num[0] = 48;
	num[count_1--] = 0;
	while (a != 0)
	{
		num[count_1] = '0' + (a % 10);
		a = a / 10;
		count_1--;
	}
	i = put_string(num);
	free(num);
	return (i);
}
