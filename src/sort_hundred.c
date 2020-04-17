/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:32:27 by mburnett          #+#    #+#             */
/*   Updated: 2020/04/17 14:33:42 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	rotate_b_to_min(t_dlist **a, t_dlist **b)
{
	int min;

	min = count_operations((*a), (*b));
	if ((*b)->num != min)
	{
		if (find_order((*b), min) <= (ft_dlistlen((*b)) / 2 + 1))
		{
			while ((*b)->num != min)
				write_function2(b, "rb");
		}
		else
		{
			while ((*b)->num != min)
				write_function2(b, "rrb");
		}
	}
}

void	rotate_first_half_of_a(t_dlist **a, t_dlist **b)
{
	if ((*a)->num < (*b)->num)
	{
		while ((*a)->num < (*b)->num)
			write_function2(a, "ra");
		while (find_end_int(a) > (*b)->num)
			write_function2(a, "ra");
	}
	else
	{
		while ((*a)->num > (*b)->num && find_end_int(a) > (*b)->num)
			write_function2(a, "ra");
		while ((*a)->num < (*b)->num)
			write_function2(a, "ra");
	}
	write_function(a, b, "pa");
}

void	rotate_last_half_of_a(t_dlist **a, t_dlist **b)
{
	if ((*a)->num < (*b)->num)
	{
		while ((*a)->num < (*b)->num)
			write_function2(a, "rra");
		while (find_end_int(a) > (*b)->num)
			write_function2(a, "rra");
	}
	else
	{
		while ((*a)->num > (*b)->num && find_end_int(a) > (*b)->num)
			write_function2(a, "rra");
		while ((*a)->num < (*b)->num)
			write_function2(a, "rra");
	}
	write_function(a, b, "pa");
}

void	sort_hundred(t_dlist **a, t_dlist **b)
{
	first_sort2(a, b);
	while ((*b))
	{
		rotate_b_to_min(a, b);
		if ((*b)->num < ((*a)->num) && (*b)->num > find_end_int(a))
			write_function(a, b, "pa");
		else if (find_place_to_paste((*a), (*b)->num) <= ft_dlistlen((*a)) / 2)
			rotate_first_half_of_a(a, b);
		else
			rotate_last_half_of_a(a, b);
	}
}

void	do_func(t_dlist **stack_a, char *buf)
{
	if (ft_strcmp(buf, "ra") == 0)
	{
		while ((*stack_a)->num > find_end_int(stack_a))
			write_function2(stack_a, "ra");
	}
	else if (ft_strcmp(buf, "rra") == 0)
	{
		while ((*stack_a)->num > find_end_int(stack_a))
			write_function2(stack_a, "rra");
	}
}
