/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:57:36 by acastilh          #+#    #+#             */
/*   Updated: 2022/06/12 21:57:44 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!s)
		return ((void *)0);
	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return ((void *)0);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, *(s + i));
		i++;
	}
	str[i] = '\0';
	return (str);
}
