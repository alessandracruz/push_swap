/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:45:52 by acastilh          #+#    #+#             */
/*   Updated: 2022/07/25 15:39:34 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_aux_str(int fd, char *aux_str)
{
	int		reader_bytes;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	reader_bytes = 1;
	while (!ft_strchr(aux_str, '\n') && reader_bytes)
	{
		reader_bytes = read(fd, buffer, BUFFER_SIZE);
		if (reader_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[reader_bytes] = '\0';
		if (!aux_str)
		{
			aux_str = malloc(1);
			*aux_str = '\0';
		}
		aux_str = ft_strjoin(aux_str, buffer);
	}
	free(buffer);
	return (aux_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*aux_str;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	aux_str = read_aux_str(fd, aux_str);
	if (!aux_str)
		return (NULL);
	line = return_line(aux_str);
	aux_str = new_aux_str(aux_str);
	return (line);
}
