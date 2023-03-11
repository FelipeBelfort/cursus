/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:02:06 by fbelfort          #+#    #+#             */
/*   Updated: 2023/02/04 21:12:14 by FelipeBelfo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * Applies the function ’f’ on each character of the string passed as argument,
 *  passing its index as first argument. 
 * Each character is passed by address to ’f’ to be modified if necessary.
 * @param s: The string on which to iterate.
 * @param f: The function to apply to each character.
 * 
 * 
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
