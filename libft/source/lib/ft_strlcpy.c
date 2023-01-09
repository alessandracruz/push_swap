/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:51:27 by acastilh          #+#    #+#             */
/*   Updated: 2022/06/15 21:04:40 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;
	char	*source;

	source = (char *)src;
	i = 0;
	len_src = ft_strlen(source);
	if (!src || !dst)
		return (len_src);
	if (dstsize == 0)
		return (len_src);
	while (source[i] && i < dstsize - 1)
	{
		dst[i] = source[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}
