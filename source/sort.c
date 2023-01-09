/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:31:09 by acastilh          #+#    #+#             */
/*   Updated: 2022/12/07 16:43:21 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_temp(int *temp_stack, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (temp_stack[i] > temp_stack[j])
			{
				temp = temp_stack[i];
				temp_stack[i] = temp_stack[j];
				temp_stack[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sort_three_a(t_stacks *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		swap_a(s, RUN);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		swap_a(s, RUN);
		rrt_move_a(s, RUN);
	}
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		rt_move_a(s, RUN);
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		swap_a(s, RUN);
		rt_move_a(s, RUN);
	}
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		rrt_move_a(s, RUN);
}

int	sort_small_b(t_stacks *s, int len)
{
	if (len == 1)
		push_a(s, RUN);
	else if (len == 2)
	{
		if (s->b[0] < s->b[1])
			swap_b(s, RUN);
		while (len--)
			push_a(s, RUN);
	}
	else if (len == 3)
	{
		while (len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 1 && s->a[0] > s->a[1])
				swap_a(s, RUN);
			else if (len == 1 || (len >= 2 && s->b[0] > s->b[1]) || (len == 3
					&& s->b[0] > s->b[2]))
				len = push(s, len, 1);
			else
				swap_b(s, RUN);
		}
	}
	return (0);
}

int	sort(t_stacks *stack, int size)
{
	if (check_sorted(stack->a, stack->size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(stack, RUN);
		else if (size == 3)
			sort_three_a(stack);
		else
			quicksort_a(stack, size, 0);
	}
	return (0);
}

int	push(t_stacks *stack, int len, int operation)
{
	if (operation == 0)
		push_b(stack, RUN);
	else
		push_a(stack, RUN);
	len--;
	return (len);
}
