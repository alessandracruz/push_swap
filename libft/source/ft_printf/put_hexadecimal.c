/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexadecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:18:44 by acastilh          #+#    #+#             */
/*   Updated: 2022/07/13 14:59:23 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex(unsigned int h, char *caracter)
{
	unsigned int	hcopy;
	size_t			size;
	char			*numhex;

	hcopy = h;
	size = 1;
	while (hcopy > 15)
	{
		size++;
		hcopy = hcopy / 16;
	}
	numhex = (char *)malloc(size + 1);
	if (!numhex)
		return (0);
	numhex[0] = '0';
	numhex[size] = '\0';
	while (h != 0)
	{
		numhex[--size] = caracter[h % 16];
		h = h / 16;
	}
	size = put_string(numhex);
	free (numhex);
	return (size);
}
