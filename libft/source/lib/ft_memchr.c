/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:56:19 by acastilh          #+#    #+#             */
/*   Updated: 2022/06/12 18:56:50 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	carac;

	i = 0;
	str = (unsigned char *)s;
	carac = (unsigned char )c;
	while (i < n)
	{
		if (str[i] == carac)
			return (str + i);
		i++;
	}
	return (0);
}
