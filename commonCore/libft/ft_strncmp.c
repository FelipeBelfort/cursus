/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:13:06 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/22 16:19:06 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] < (unsigned char) s2[i])
			return (-1);
		else if ((unsigned char) s1[i] > (unsigned char) s2[i])
			return (1);
		else
			i++;
	}
	return (0);
}
