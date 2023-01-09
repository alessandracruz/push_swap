/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:11:46 by acastilh          #+#    #+#             */
/*   Updated: 2022/12/13 14:47:40 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	quicksort_3(t_stacks *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		sort_three_a(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			swap_a(stack, RUN);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				swap_a(stack, RUN);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				swap_a(stack, RUN);
			else if (len++)
				push_a(stack, RUN);
		}
	}
}

int	get_middle(int *pivot, int *stack, int size)
{
	int	*temp_stack;
	int	i;

	temp_stack = (int *)malloc(size * sizeof(int));
	if (!temp_stack)
		return (0);
	i = 0;
	while (i < size)
	{
		temp_stack[i] = stack[i];
		i++;
	}
	sort_temp(temp_stack, size);
	*pivot = temp_stack[size / 2];
	free(temp_stack);
	return (1);
}

int	quicksort_a(t_stacks *stack, int len, int cnt)
{
	int	pivot;
	int	items;

	if (check_sorted(stack->a, len, 0) == 1)
		return (1);
	items = len;
	if (len <= 3)
	{
		quicksort_3(stack, len);
		return (1);
	}
	if (!cnt && !get_middle(&pivot, stack->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot && (len--))
			push_b(stack, RUN);
		else if (++cnt)
			rt_move_a(stack, RUN);
	}
	while (items / 2 + items % 2 != stack->size_a && cnt--)
		rrt_move_a(stack, RUN);
	return (quicksort_a(stack, items / 2 + items % 2, 0) && quicksort_b(stack,
			items / 2, 0));
	return (1);
}

int	quicksort_b(t_stacks *stack, int len, int cnt)
{
	int	pivot;
	int	items;

	if (!cnt && check_sorted(stack->b, len, 1) == 1)
		while (len--)
			push_a(stack, RUN);
	if (len <= 3)
	{
		sort_small_b(stack, len);
		return (1);
	}
	items = len;
	if (!get_middle(&pivot, stack->b, len))
		return (0);
	while (len != items / 2)
	{
		if (stack->b[0] >= pivot && len--)
			push_a(stack, RUN);
		else if (++cnt)
			rt_move_b(stack, RUN);
	}
	while (items / 2 != stack->size_b && cnt--)
		rrt_move_b(stack, RUN);
	return (quicksort_a(stack, items / 2 + items % 2, 0) && quicksort_b(stack,
			items / 2, 0));
}
