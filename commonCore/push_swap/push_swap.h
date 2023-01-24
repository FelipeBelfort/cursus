/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:10:48 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/23 14:34:58 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				nb;
	int				ordered;
	int				index;
	struct s_stack	*next;
}				t_stack;

typedef struct s_pushswap
{
	int				max;
	int				min;
	int				max_a;
	int				min_a;
	t_stack			*a;
	int				max_b;
	int				min_b;
	t_stack			*b;
	int				lstsize;
	int				target;
	int				nb;
	t_list			*res;
	t_list			*res_tmp;
}				t_pushswap;

/* free */

void		free_stack(t_stack *stack);
void		free_lst(t_list *stack);
void		free_container(t_pushswap *stacks);
void		free_tab(char **tab);

/* parsing */

t_pushswap	*stack_init(char **argv, int argc);

/* to sort */

void		sort_3(t_pushswap *bin);
void		sort_selection(t_pushswap *bin);
void		sort_ordered(t_pushswap *bin);
void		sort_inverted(t_pushswap *bin);
void		sort_radix(t_pushswap *bin);
void		sort_selectcost(t_pushswap *bin);

/* boolean tests */

int			is_int(char *str, int n);
int			is_sorted(t_stack *stack);
int			is_ordered(t_stack *s);
int			is_inverted(t_stack *s);

/* operations */

void		do_op(t_pushswap *bin, void (*op)(t_pushswap *));
void		sa(t_pushswap *bin);
void		sb(t_pushswap *bin);
void		pa(t_pushswap *bin);
void		pb(t_pushswap *bin);
void		ra(t_pushswap *bin);
void		rb(t_pushswap *bin);
void		rr(t_pushswap *bin);
void		rra(t_pushswap *bin);
void		rrb(t_pushswap *bin);
void		rrr(t_pushswap *bin);

/* stack info */

int			stack_size(t_stack *stack);
int			stack_max(t_stack *stack);
int			stack_min(t_stack *stack);
int			stack_get_i(t_stack *stack, int nb);
void		fill_container(t_pushswap *bin);

/* stack manipulation */

t_stack		*stack_new(int nb);
void		stack_addback(t_stack **stack, t_stack *new);
t_stack		*stack_last(t_stack *stack);
int			swipe(t_stack **stack);
int			push(t_stack **from, t_stack **to);
int			rotate(t_stack **stack);
int			rev_rotate(t_stack **stack);
t_stack		*stack_getnode(t_stack **stack, t_stack *node);
void		stack_addfirst(t_stack **stack, t_stack *new);
void		reset_stack(t_pushswap *bin);

/* error */

void		ft_error(t_pushswap *bin);

# define TO_A 0
# define TO_B 1
# define SA "sa"
# define SB "sb"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

#endif