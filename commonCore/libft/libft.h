/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:50:10 by fbelfort          #+#    #+#             */
/*   Updated: 2022/11/17 12:52:10 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLIB.H
# define FTLIB.H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

        //string tests
int	    ft_isalnum(char c);
int	    ft_isalpha(char c);
int 	ft_isascii(char c);
int 	ft_isdigit(char c);
int 	ft_isprint(char c);

int	    ft_strlen(char *str);
char	ft_tolower(char c);
char	ft_toupper(char c);




#endif