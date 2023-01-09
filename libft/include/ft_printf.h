/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:42:15 by acastilh          #+#    #+#             */
/*   Updated: 2022/12/07 16:47:43 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		arg_format(const char *str, va_list args, int c);
int		put_char(char c);
int		put_string(char *str);
char	*ft_strchr(const char *s, int c);
int		pf_ft_itoa(int n);
size_t	ft_strlen(const char *s);
int		ft_utoa(unsigned int n);
int		put_hex(unsigned int h, char *caracter);
int		put_pointer(void *p);

#endif
