/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:10:48 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/30 17:37:50 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int				nb;
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
}				t_pushswap;

/* free */

void		free_stack(t_stack *stack);
void		free_container(t_pushswap *stacks);
void		free_tab(char **tab);

/* parsing */

t_pushswap	*stack_init(char **argv, int argc);

/* to sort */

void		sort_3(t_pushswap *bin);
void		sort_few(t_pushswap *bin);
void		sort_ordered(t_pushswap *bin);
void		sort_inverted(t_pushswap *bin);
void		sort_selectcost(t_pushswap *bin);

/* selectcost utilities */

t_stack		*set_costs(int n, t_stack *s);
void		push_to(t_pushswap *bin, int direction);
int			seek_prev(int n, t_stack *s);
int			seek_next(int n, t_stack *s);
void		fetch_topush(t_pushswap *bin, int direction);

/* boolean tests */

int			is_dup(t_stack *a, int nb);
int			is_int(char *str, int n);
int			is_sorted(t_stack *stack);
int			is_ordered(t_stack *s);
int			is_inverted(t_stack *s);

/* operations */

void		do_op(t_pushswap *bin, char *(*op)(t_pushswap *));
char		*sa(t_pushswap *bin);
char		*sb(t_pushswap *bin);
char		*pa(t_pushswap *bin);
char		*pb(t_pushswap *bin);
char		*ra(t_pushswap *bin);
char		*rb(t_pushswap *bin);
char		*rr(t_pushswap *bin);
char		*rra(t_pushswap *bin);
char		*rrb(t_pushswap *bin);
char		*rrr(t_pushswap *bin);

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

/* error */

void		ft_error(t_pushswap *bin);

# define TO_A 0
# define TO_B 1
# define PA "pa\n"
# define PB "pb\n"
# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

#endif