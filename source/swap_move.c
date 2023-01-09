/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:16:59 by acastilh          #+#    #+#             */
/*   Updated: 2022/12/07 23:25:23 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_stacks *stack, int print)
{
	int	temp;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (print == ERROR)
			ft_printf("Few elements in stack a!\n");
		return ;
	}
	temp = 0;
	temp = stack->a[0];
	stack->a[0] = stack ->a[1];
	stack->a[1] = temp;
	if (print == RUN)
		ft_printf("sa\n");
}

void	swap_b(t_stacks *stack, int print)
{
	int	temp;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (print == ERROR)
			ft_printf("Few elements in stack b!\n");
		return ;
	}
	temp = 0;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	if (print == RUN)
		ft_printf("sb\n");
}

void	swap_ss(t_stacks *stack, int print)
{
	int	temp;

	if (stack->size_a == 0 || stack->size_a == 1
		|| (stack->size_b == 0 || stack->size_b == 1))
	{
		if (print == ERROR)
			ft_printf("Few elements in stack!\n");
		return ;
	}
	temp = 0;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	if (print == RUN)
		ft_printf("ss\n");
}
