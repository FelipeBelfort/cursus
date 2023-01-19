/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:10:48 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/01/18 22:02:41 by FelipeBelfo      ###   ########.fr       */
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
	size_t			lstsize;
	t_list			*res;
	t_list			*res_tmp;
}				t_pushswap;

/* free */

void	free_stack(t_stack *stack);
void	free_container(t_pushswap *stacks);
void	free_tab(char **tab);

/* boolean tests */

int		parse_stack(char **argv, int i);
int		is_dup(t_stack *a, int nb);
int		is_int(char *str, int n);

/* stack manipulation */

t_stack	*stack_new(int nb);
void	stack_addback(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
int		swipe(t_stack **stack);
int		push(t_stack **from, t_stack **to);
int		rotate(t_stack **stack);
int		rev_rotate(t_stack **stack);
t_stack	*stack_getnode(t_stack **stack, t_stack *node);
void	stack_addfirst(t_stack **stack, t_stack *new);


# define ERROR "Error"
# define SORTED ""
# define SA "sa"
# define SB "sb"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RRA "rra"
# define RRB "rrb"

#endif