/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:37:34 by acastilh          #+#    #+#             */
/*   Updated: 2022/07/13 15:01:38 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_string(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		str = "(null)";
	while (str[counter] != '\0')
	{
		write(1, &str[counter], 1);
		counter++;
	}
	return (counter);
}
