/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:05:03 by acastilh          #+#    #+#             */
/*   Updated: 2022/12/07 22:17:54 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/libft.h"
# include <limits.h>
# include <stdlib.h>

# define ERROR 1
# define RUN 0

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}		t_stacks;

/* utils.c */
void	error(int *stack);
int		ps_atoi(char *str, int *stack);
int		ps_strlen(char **argv);
int		check_sorted(int *stack, int size, int order);
void	check_repeat(int *stack, int size);

/* operators */
void	swap_a(t_stacks *stack, int print);
void	swap_b(t_stacks *stack, int print);
void	swap_ss(t_stacks *stack, int print);
void	push_a(t_stacks *stack, int print);
void	push_b(t_stacks *stack, int print);
void	rt_move_a(t_stacks *stack, int print);
void	rt_move_b(t_stacks *stack, int print);
void	rt_move_rr(t_stacks *stack, int print);
void	rrt_move_a(t_stacks *stack, int print);
void	rrt_move_b(t_stacks *stack, int print);
void	rrt_move_rrr(t_stacks *stack, int print);

/* sort.c */
void	sort_temp(int *temp_stack, int size);
void	sort_three_a(t_stacks *s);
int		sort_small_b(t_stacks *s, int len);
int		sort(t_stacks *stack, int size);
int		push(t_stacks *stack, int len, int operation);

/* algorithm.c */
void	quicksort_3(t_stacks *stack, int len);
int		get_middle(int *pivot, int *stack, int size);
int		quicksort_a(t_stacks *stack, int len, int cnt);
int		quicksort_b(t_stacks *stack, int len, int cnt);

/* push_swap.c */
void	push_swap(char **argv);

#endif
