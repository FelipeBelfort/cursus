/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:33:51 by fbelfort          #+#    #+#             */
/*   Updated: 2022/12/02 14:52:11 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}


void	ft_putnbr_base(int nb, char *base)
{
	unsigned int	n;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	n = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		n = -nb;
	}
	if (n > base_len - 1)
	{
		ft_putnbr_base(n / base_len, base);
		ft_putnbr_base(n % base_len, base);
	}
	else
	{
		ft_putchar_fd(base[n], 1);
	}
}


int	ft_printf(const char *str, ...)
{
	int		i;
	int		fd;
	size_t	counter;
	va_list	valist;

	i = 0;
	counter = 0;
	fd = 1;
	va_start(valist, str);
	while (str[i])
	{
		if (str[i] != '%' || (str[i] == '%' && str[i + 1] == '%'))
		{
			if (str[i] == '%')
				i++;
			ft_putchar_fd(str[i], fd);
			counter++;
		}
		else
		{
			if (str[++i])
			{
				if (str[i] == 'c')
				{
					ft_putchar_fd(va_arg(valist, int), fd);
					counter++;
				}
				if (str[i] == 's')
				{
					ft_putstr_fd(va_arg(valist, char *), fd);
					counter++;
				}
				if (str[i] == 'p')
				{
					ft_putstr_fd(va_arg(valist, char *), fd);
					counter++;
				}
				if (str[i] == 'i')
				{
					ft_putnbr_base(va_arg(valist, int), "0123456789");
					counter++;
				}
				if (str[i] == 'd')
				{
					ft_putnbr_base(va_arg(valist, int), "0123456789"); // regler le decimal
					counter++;
				}
				if (str[i] == 'u')
				{
					ft_putstr_fd(va_arg(valist, char *), fd); // regler le decimal
					counter++;
				}
				if (str[i] == 'x')
				{
					ft_putnbr_base(va_arg(valist, int), "0123456789abcdef");
					counter++;
				}
				if (str[i] == 'X')
				{
					ft_putnbr_base(va_arg(valist, int), "0123456789ABCDEF");
					counter++;
				}
			}
			else
				return (-1);
		}
		i++;
	}
	va_end(valist);
	return (counter);
}

int	main()
{
	char c = 'c';
	char *nome = "Felipe";
	int	idade = 37;
	int	hexa = 43;
	
	ft_printf("Eu quero testar %% \n c --> %c\nnome --> %s\n tenho %i anos\n 43 = 2B -> %x -> %X", c, nome, idade, hexa, hexa);
	return 1;
}