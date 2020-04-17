/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:28:25 by mburnett          #+#    #+#             */
/*   Updated: 2020/04/17 16:17:54 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

size_t	is_sorted(t_dlist **stack_a)
{
	t_dlist	*list;
	int		prev;

	list = (*stack_a);
	prev = list->num;
	while (list->next)
	{
		list = list->next;
		if (list->num < prev)
			return (0);
		prev = list->num;
	}
	return (1);
}

size_t	check_place_if_not_sorted(t_dlist **stack_a)
{
	int		num;
	int		prev;
	int		count;
	t_dlist	*a;

	a = (*stack_a);
	count = 1;
	prev = a->num;
	while (a->next)
	{
		a = a->next;
		count++;
		num = a->num;
		if (num < prev)
		{
			if (count > (ft_dlistlen((*stack_a)) / 2))
				do_func(stack_a, "rra");
			else
				do_func(stack_a, "ra");
		}
		else
			prev = a->num;
	}
	return (0);
}

void	sort_three(t_dlist **a)
{
	if ((*a)->num < (*a)->next->num)
	{
		if ((*a)->num < (*a)->next->next->num)
		{
			write_function2(a, "sa");
			write_function2(a, "ra");
		}
		else
			write_function3(a, "rra");
	}
	else
	{
		if ((*a)->num < (*a)->next->next->num)
			write_function2(a, "sa");
		else if ((*a)->next->num > (*a)->next->next->num)
		{
			write_function2(a, "sa");
			write_function3(a, "rra");
		}
		else
		{
			write_function2(a, "ra");
		}
	}
}

void	sort_five(t_dlist **a, t_dlist **b)
{
	int	min;

	while (ft_dlistlen((*a)) != 3)
	{
		min = find_min_int((*a));
		if (find_order((*a), min) < ft_dlistlen((*a)) / 2)
		{
			while ((*a)->num != min)
				write_function2(a, "ra");
		}
		else
		{
			while ((*a)->num != min)
				write_function2(a, "rra");
		}
		write_function(b, a, "pb");
	}
	sort_three(a);
	while ((*b))
	{
		while ((*b)->num > (*a)->num)
			write_function2(a, "ra");
		write_function(a, b, "pa");
	}
}

void	dlistdell(t_dlist **begin)
{
	while ((*begin)->next)
		dlistdell(&(*begin)->next);
	(*begin)->next = NULL;
	(*begin)->previous = NULL;
	free((*begin));
	(*begin) = NULL;
}
