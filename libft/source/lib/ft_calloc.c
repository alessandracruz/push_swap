/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:40:51 by acastilh          #+#    #+#             */
/*   Updated: 2022/06/16 15:17:04 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = malloc(count * size);
	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	if (pointer == NULL)
		return (0);
	ft_bzero(pointer, count * size);
	return (pointer);
}
