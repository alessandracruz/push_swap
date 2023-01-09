/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:11:15 by acastilh          #+#    #+#             */
/*   Updated: 2022/06/16 14:39:42 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	index;
	int	start_word;
	int	count;

	count = 0;
	index = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c && s[index] != '\0')
			index++;
		start_word = index;
		while (s[index] != c && s[index] != '\0')
			index++;
		if (start_word != index)
			count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		start_word;
	char	**pointer;
	int		word;

	index = 0;
	word = 0;
	if (!s)
		return (NULL);
	pointer = ft_calloc(ft_count(s, c) + 1, sizeof(char *));
	if (!pointer)
		return (NULL);
	while (s[index] != '\0')
	{
		while (s[index] == c && s[index] != '\0')
			index++;
		start_word = index;
		while (s[index] != c && s[index] != '\0')
			index++;
		if (start_word != index)
			pointer[word++] = ft_substr(s, start_word, index - start_word);
	}
	pointer[word] = NULL;
	return (pointer);
}
