/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:37:53 by FelipeBelfo       #+#    #+#             */
/*   Updated: 2023/02/04 21:18:54 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * Allocates (with malloc(3)) and returns a new node.
 *  The member variable ’content’ is initialized with 
 * the value of the parameter ’content’.
 *  The variable ’next’ is initialized to NULL.
 * @param content: The content to create the node with.
 * @return 
 * The new node
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
