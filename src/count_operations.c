/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:26:13 by mburnett          #+#    #+#             */
/*   Updated: 2020/04/17 14:33:42 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

size_t	find_order_from_tail(t_dlist *stack, int num)
{
	t_dlist	*list;
	int		count;

	list = stack;
	count = 1;
	while (list->next)
		list = list->next;
	while (list && list->num != num)
	{
		count++;
		list = list->previous;
	}
	return (count);
}

int		count_operations_stack_a(t_dlist *stack_a, int b)
{
	t_dlist	*list;
	int		count;
	int		list_len;

	list = stack_a;
	count = 0;
	list_len = ft_dlistlen(stack_a);
	while (list)
	{
		count++;
		if (list->next)
		{
			if (b > list->num && b < list->next->num)
			{
				if (count > list_len / 2 + 1)
					return (list_len - count + 1);
				return (count);
			}
		}
		list = list->next;
	}
	return (0);
}

void	assist_count_operations(int *min, int count_min,
		t_dlist *stack_a, t_dlist *stack_b)
{
	int		current;
	t_dlist	*b;

	b = stack_b->next;
	while (b)
	{
		current = find_order(stack_b, b->num) - 1;
		if (current > ft_dlistlen(stack_a) / 2)
			current = find_order_from_tail(stack_b, b->num);
		current = current + count_operations_stack_a(stack_a, b->num);
		if (current < count_min)
		{
			count_min = current;
			*min = b->num;
		}
		b = b->next;
	}
}

int		count_operations(t_dlist *stack_a, t_dlist *stack_b)
{
	int		count_min;
	int		min;
	t_dlist	*b;

	b = stack_b;
	min = b->num;
	count_min = find_order(stack_b, b->num) - 1;
	if (count_min > ft_dlistlen(stack_a) / 2)
		count_min = find_order_from_tail(stack_b, b->num);
	count_min = count_min + count_operations_stack_a(stack_a, b->num);
	assist_count_operations(&min, count_min, stack_a, stack_b);
	return (min);
}

int		find_place_to_paste(t_dlist *stack_a, int num)
{
	t_dlist	*list;
	int		count;

	list = stack_a;
	count = 0;
	if (num < list->num)
	{
		while (list && num < list->num)
		{
			list = list->next;
			count++;
		}
	}
	while (list && num > list->num)
	{
		list = list->next;
		count++;
	}
	return (count);
}
