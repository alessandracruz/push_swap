/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:11:15 by acastilh          #+#    #+#             */
/*   Updated: 2022/12/07 23:23:11 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrt_move_a(t_stacks *stack, int print)
{
	int	temp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (print == ERROR)
			ft_printf("Few numbers in Stack a!\n");
		return ;
	}
	i = stack->size_a - 1;
	temp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = temp;
	if (print == RUN)
		ft_printf("rra\n");
}

void	rrt_move_b(t_stacks *stack, int print)
{
	int	temp;
	int	i;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (print == ERROR)
			ft_printf("Few numbers in Stack a!\n");
		return ;
	}
	i = stack->size_b - 1;
	temp = stack->b[i];
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = temp;
	if (print == RUN)
		ft_printf("rrb\n");
}

void	rrt_move_rrr(t_stacks *stack, int print)
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
	i = stack->size_a - 1;
	temp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = temp;
	i = stack->size_b - 1;
	temp = stack->b[i];
	while (i--)
		stack->b[i] = stack->b[i - 1];
	stack->b[i] = temp;
	if (print == RUN)
		ft_printf("rrr\n");
}
