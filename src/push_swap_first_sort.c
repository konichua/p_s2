/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_first_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:27:36 by mburnett          #+#    #+#             */
/*   Updated: 2020/04/17 14:37:36 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	first_sort3(t_dlist **stack_a, t_dlist **stack_b, int max, int min)
{
	int count;
	int all_num;

	count = 0;
	all_num = ft_dlistlen((*stack_a));
	while ((*stack_a) && count < all_num)
	{
		if (((*stack_a)->num < (max - min) / 1.5 + 1) &&
		(*stack_a)->num != max && (*stack_a)->num != min)
		{
			if ((*stack_a)->num < (max - min) / 3 + 1 &&
			(*stack_a)->num != max && (*stack_a)->num != min)
			{
				write_function(&(*stack_b), &(*stack_a), "pb");
				write_function2(&(*stack_b), "rb");
			}
			else
				write_function(&(*stack_b), &(*stack_a), "pb");
		}
		else
			write_function2(&(*stack_a), "ra");
		count++;
	}
}

void	first_sort2(t_dlist **stack_a, t_dlist **stack_b)
{
	int max;
	int min;

	max = find_max_int((*stack_a));
	min = find_min_int((*stack_a));
	first_sort3(stack_a, stack_b, max, min);
	while (ft_dlistlen(*stack_a) != 2)
	{
		if ((*stack_a)->num == max || (*stack_a)->num == min)
			write_function2(&(*stack_a), "ra");
		else
			write_function(&(*stack_b), &(*stack_a), "pb");
	}
}

int		find_order(t_dlist *list, int num)
{
	int i;

	i = 1;
	while (num != list->num)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_dlist	*get_stack_a(char **av, int flag)
{
	t_dlist	*new;
	t_dlist	*begin;
	int		i;
	char	*new_str;
	int		j;

	i = 1;
	begin = NULL;
	while (av[i])
	{
		j = 0;
		new_str = av[i];
		while ((new_str = exist_str(new_str, j)) != NULL)
		{
			new = ft_dlstnew(ft_atoi(new_str), flag);
			ft_dlstadd_to_end(&begin, &new);
			j++;
		}
		i++;
	}
	return (begin);
}
