/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_first_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:27:36 by mburnett          #+#    #+#             */
/*   Updated: 2020/04/17 16:28:15 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DLIST_H
# define PUSH_SWAP_DLIST_H

# include <stdio.h>
# include "../LIBFT/lib_str/libft.h"

typedef struct		s_dlist
{
	int				num;
	struct s_dlist	*next;
	struct s_dlist	*previous;
	int				flag;
}					t_dlist;

void				write_function4(t_dlist **a, t_dlist **b, char *buf);
void				write_function3(t_dlist **list, char *buf);
void				write_function(t_dlist **a, t_dlist **b, char *buf);
void				write_function2(t_dlist **list, char *buf);
void				solve_command2(t_dlist **stack_a, t_dlist **stack_b,
		char *str);
void				solve_command(t_dlist **stack_a, t_dlist **stack_b,
		char *str);
void				do_operations(t_dlist **stack_a, t_dlist **stack_b,
		char **str);
void				assist_checker_ok(int *flag, int prev, t_dlist **stack_a);
void				checker_ok(t_dlist **stack_a, t_dlist **stack_b);
int					assist_checker_main(t_dlist **stack_a, t_dlist **stack_b,
		char **str);
void				read_commands(char **str, int *proverka);
int					checker_valid_duplicates(char **av);
int					checker_valid_overflow(char **av);
int					checker_valid_isdigit(char **av);
int					checker_valid_command(char *str);
void				oper_s(t_dlist **stack_a);
void				assist_oper_p(t_dlist **begin_push, t_dlist **begin_pop);
void				oper_p(t_dlist **stack_push, t_dlist **stack_pop);
void				oper_r(t_dlist **stack);
void				oper_rr(t_dlist **stack);
size_t				find_order_from_tail(t_dlist *stack, int num);
int					count_operations(t_dlist *stack_a, t_dlist *stack_b);
int					find_place_to_paste(t_dlist *stack_a, int num);
int					find_min_int(t_dlist *begin);
int					find_max_int(t_dlist *begin);
int					find_end_int(t_dlist **list);
int					ft_dlistlen(t_dlist *begin);
void				sort_five(t_dlist **a, t_dlist **b);
void				sort_three(t_dlist **a);
size_t				check_place_if_not_sorted(t_dlist **stack_a);
size_t				is_sorted(t_dlist **stack_a);
void				first_sort3(t_dlist **stack_a, t_dlist **stack_b,
		int max, int min);
void				first_sort2(t_dlist **stack_a, t_dlist **stack_b);
int					find_order(t_dlist *list, int num);
t_dlist				*get_stack_a(char **av, int flag);
void				rotate_b_to_min(t_dlist **a, t_dlist **b);
void				rotate_first_half_of_a(t_dlist **a, t_dlist **b);
void				rotate_last_half_of_a(t_dlist **a, t_dlist **b);
void				sort_hundred(t_dlist **a, t_dlist **b);
void				do_func(t_dlist **stack_a, char *buf);
t_dlist				*ft_dlstnew(int num, int flag);
void				ft_dlstadd_to_end(t_dlist **alst, t_dlist **new);
char				*exist_str(char *str, int count);
char				*del_substr(char *str);
void 				display_stack(t_dlist **stack_a, t_dlist **stack_b);
void 				first_display(t_dlist **stack_a);
void				assist_display_stack(t_dlist *a, t_dlist *b);
void				dlistdell(t_dlist **begin);
void 				parse_stack(t_dlist **stack_a, t_dlist **stack_b, int ac);
void				set_flag(int *ac, int *flag);

#endif
