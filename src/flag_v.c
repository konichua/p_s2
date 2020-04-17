/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 15:55:41 by mburnett          #+#    #+#             */
/*   Updated: 2020/04/17 16:10:16 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void 	first_display(t_dlist **stack_a)
{
	t_dlist *a;

	if (stack_a == NULL)
		a = NULL;
	else
		a = (*stack_a);
	write(1, "stack_A: ", 9);
	if (!a)
		write(1, "unchanged", 9);
	while (a)
	{
		ft_putnbr(a->num);
		write(1, " ", 1);
		a = a->next;
	}
	write(1, "\nstack_B: ---\n", 14);
}

void 	assist_display_stack(t_dlist *a, t_dlist *b)
{
	write(1, "stack_A: ", 9);
	if (!a)
		write(1, "unchanged", 9);
	while (a)
	{
		ft_putnbr(a->num);
		write(1, " ", 1);
		a = a->next;
	}
	write(1, "\nstack_B: ", 10);
	if (!b)
		write(1, "unchanged", 9);
	while (b)
	{
		ft_putnbr(b->num);
		write(1, " ", 1);
		b = b->next;
	}
	write(1, "\n", 1);
}

void 	display_stack(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist *a;
	t_dlist *b;

	if (stack_a == NULL)
		a = NULL;
	else
		a = (*stack_a);
	if (stack_b == NULL)
		b = NULL;
	else
		b = (*stack_b);
	assist_display_stack(a, b);
}

void 	parse_stack(t_dlist **stack_a, t_dlist **stack_b, int ac)
{
	if (ac == 4)
		sort_three(stack_a);
	else if (ac == 6)
		sort_five(stack_a, stack_b);
	else
		sort_hundred(stack_a, stack_b);
	if (is_sorted(stack_a) == 0)
		check_place_if_not_sorted(stack_a);
	if ((*stack_a))
		dlistdell(stack_a);
}

void	set_flag(int *ac, int *flag)
{
	*ac = *ac - 1;
	*flag = 1;
}