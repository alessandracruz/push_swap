/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:07:32 by acastilh          #+#    #+#             */
/*   Updated: 2022/12/07 23:24:55 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rt_move_a(t_stacks *stack, int print)
{
	int	temp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (print == ERROR)
			ft_printf("Few numbers in Stack a!\n");
		return ;
	}
	i = 0;
	temp = stack->a[i];
	i++;
	while (i < stack->size_a)
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = temp;
	if (print == RUN)
		ft_printf("ra\n");
}

void	rt_move_b(t_stacks *stack, int print)
{
	int	temp;
	int	i;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (print == ERROR)
			ft_printf("Few numbers in Stack a!\n");
		return ;
	}
	i = 0;
	temp = stack->b[i];
	i++;
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = temp;
	if (print == RUN)
		ft_printf("rb\n");
}

void	rt_move_rr(t_stacks *stack, int print)
{
	int	temp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1
		|| (stack->size_b == 0 || stack->size_b == 1))
	{
		if (print == ERROR)
			ft_printf("Few numbers in stacks!\n");
		return ;
	}
	i = 0;
	temp = stack->a[i];
	while (++i < stack->size_a)
		stack->a[i - 1] = stack->a[i];
	stack->a[i - 1] = temp;
	i = 0;
	temp = stack->b[i];
	while (++i < stack->size_b)
		stack->b[i - 1] = stack->b[i];
	stack->b[i - 1] = temp;
	if (print == RUN)
		ft_printf("rr\n");
}
