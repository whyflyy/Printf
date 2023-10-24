/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:46:27 by jcavadas          #+#    #+#             */
/*   Updated: 2023/10/24 10:56:25 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static int ft_conversions(const char c) //tambem vou ter de mandar as cenas variadic coiso e tal que nem sei como funciona para ele saber o que printar
{
	if (c == 'c')
		return (ft_putchar(c)); //Nao pode ser putchar porque vai ter de ser uma funcao que devolva um valor para adicionar a len
	if (c == 's')
		return (ft_putstr(c)); //Nao pode ser putstr porque vai ter de ser uma funcao que devolva um valor para adicionar a len
	if (c == 'p')
		return (ft_print_pointer(c)); //ver o que e que tenho de fazer para printar um pointer (?)
	if (c == 'd')
		return (ft_print_decimal(c)); //Printar um numero em base decimal
	if (c == 'i')
		return (ft_print_decimal(c)); //Printa um int em base decimal. Assumo que possa ser com a mesma funcao que vou fazer para cima :)
	if (c == 'u')
		return (ft_print_unsigned(c)); //Printa um decimal unsigned
	if (c == 'x')
		return (ft_print_hexadecimal(c)); //Printa um numero em base hexadecimal lowercase
	if (c == 'X')
		return (ft_print_hexadecimal(c)); //Printa um numero em base hexadecimal uppercase
	if (c == '%')
		return (ft_putchar('%')); //Nao pode ser putchar porque vai ter de ser uma funcao que devolva um valor para adicionar a len
}
*/
int	ft_printf(const char *str, ...) //Ver variadic functions
{
	va_list	arglist;
	size_t	i;
	int		len;

	i = -1;
	len = 0;
	va_start(arglist, str);	
	/*
	while (str[++i])
	{
		if (str[i] == '%')
		{
			len += ft_conversions(str[++i]);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
	}
	return (len);*/

	while (str[++i])
	{
		if (str[i] == '%')
		{
			ft_putchar_fd(arglist, 1);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
	}
	return (len);
}

int	main(void)
{
	ft_printf("a%a b%b c%c d%d", 'b', 'c', 'd', 'e');
	return (0);
}
