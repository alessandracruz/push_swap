/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:45:23 by acastilh          #+#    #+#             */
/*   Updated: 2022/12/07 16:47:57 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int n)
{
	int	a;
	int	count_2;

	a = n;
	count_2 = 0;
	if (a <= 0)
		count_2++;
	while (a != 0)
	{
		a = a / 10;
		count_2++;
	}
	return (count_2);
}

static char	*ft_numb(char *num, unsigned int n, size_t count_1)
{
	while (n != 0)
	{
		num[count_1--] = ('0' + n % 10);
		n = n / 10;
	}
	return (num);
}

int	pf_ft_itoa(int n)
{
	size_t	count_1;
	char	*num;
	int		i;

	count_1 = ft_count(n);
	num = malloc(sizeof(char) * (count_1 + 1));
	if (!num)
		return (0);
	if (n == 0)
		num[0] = 48;
	num[count_1--] = 0;
	if (n < 0)
	{
		num[0] = '-';
		n *= (-1);
	}
	num = ft_numb(num, n, count_1);
	i = put_string(num);
	free(num);
	return (i);
}
