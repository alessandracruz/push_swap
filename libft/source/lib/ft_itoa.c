/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:45:23 by acastilh          #+#    #+#             */
/*   Updated: 2022/06/14 16:17:24 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	int		t;
	int		count_1;
	char	*num;
	long	a;

	a = n;
	t = 1;
	if (n < 0)
		t = -1;
	count_1 = ft_count(n);
	num = malloc(sizeof(char) * (count_1 + 1));
	if (!num)
		return (0);
	if (a == 0)
		num[0] = 48;
	num[count_1--] = 0;
	while (a != 0)
	{
		num[count_1] = '0' + (a % 10) * t;
		a = a / 10;
		count_1--;
	}
	if (t < 0)
		num[count_1] = '-';
	return (num);
}
