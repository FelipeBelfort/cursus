/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:51:56 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/03/11 23:32:34 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	unsigned char	c;
	struct s_stack	*next;
}				t_stack;

#endif
