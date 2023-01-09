/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:46:46 by acastilh          #+#    #+#             */
/*   Updated: 2022/12/07 18:53:44 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char )c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	size_t	i1;
	size_t	i2;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * size);
	if (!str)
		return (str);
	i1 = 0;
	while (s1[i1])
	{
		str[i1] = s1[i1];
		i1++;
	}
	i2 = 0;
	while (s2[i2])
	{
		str[i1 + i2] = s2[i2];
		i2++;
	}
	str[i1 + i2] = '\0';
	return (str);
}

char	*return_line(char *aux_str)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!aux_str[i])
		return (NULL);
	while (aux_str[i] && aux_str[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (aux_str[i] && aux_str[i] != '\n')
	{
		str[i] = aux_str[i];
		i++;
	}
	if (aux_str[i] == '\n')
	{
		str[i] = aux_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_aux_str(char *aux_str)
{
	size_t	i;
	size_t	a;
	char	*str;

	a = 0;
	while (aux_str[a] && aux_str[a] != '\n')
		a++;
	if (!aux_str[a])
	{
		free(aux_str);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(aux_str) - a + 1));
	if (!str)
		return (NULL);
	i = 0;
	a++;
	while (aux_str[a])
		str[i++] = aux_str[a++];
	str[i] = '\0';
	free(aux_str);
	return (str);
}
