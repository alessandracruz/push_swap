/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:06:22 by acastilh          #+#    #+#             */
/*   Updated: 2022/07/13 15:01:12 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pcounter(void *p);

int	put_pointer(void *p)
{
	unsigned long	pcopy;
	int				size;
	char			*phex;
	char			*caracter;

	caracter = "0123456789abcdef";
	pcopy = (unsigned long)p;
	size = pcounter(p);
	phex = (char *)malloc(size + 1);
	if (!phex)
		return (0);
	phex[0] = '0';
	phex[size] = '\0';
	while (pcopy != 0)
	{
		phex[--size] = caracter[pcopy % 16];
		pcopy = pcopy / 16;
	}
	size = put_string(phex);
	free (phex);
	return (size);
}

int	pcounter(void *p)
{
	unsigned long	pcopy;
	size_t			size;

	pcopy = (unsigned long)p;
	size = 1;
	while (pcopy > 15)
	{
		size++;
		pcopy = pcopy / 16;
	}
	return (size);
}
