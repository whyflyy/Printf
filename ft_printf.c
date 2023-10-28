/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:46:27 by jcavadas          #+#    #+#             */
/*   Updated: 2023/10/28 16:50:07 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_conversions(const char c, va_list arglist)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arglist, int))); //Done and working
	else if (c == 's')
		return (ft_putstr(va_arg(arglist, char *))); //Done and working
	/*else if (c == 'p')
		return (ft_print_pointer(c)); //ver o que e que tenho de fazer para printar um pointer (?) -> tem de ser hexadecimal por isso vou deixar para ultimo*/
	else if (c == 'd')
		return (ft_print_decimal(va_arg(arglist, int))); //Done and working
	else if (c == 'i')
		return (ft_print_decimal(va_arg(arglist, int))); //Done and working
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(arglist, int))); //I think it's working but recheck it !!!!!!!!!!!!!!!!!
	/*else if (c == 'x')
		return (ft_print_hexadecimal(c)); //Printa um numero em base hexadecimal lowercase
	else if (c == 'X')
		return (ft_print_hexadecimal(c)); //Printa um numero em base hexadecimal uppercase*/
	else if (c == '%')
		return (ft_putchar('%')); //Nao pode ser putchar porque vai ter de ser uma funcao que devolva um valor para adicionar a len
	else
		return (write(1, "0", 1));
}

int	ft_printf(const char *str, ...) //Ver variadic functions
{
	va_list	arglist;
	size_t	i;
	int		len;

	i = -1;
	len = 0;
	va_start(arglist, str);	

	while (str[++i])
	{
		if (str[i] == '%')
		{
			len += ft_conversions(str[++i], arglist);
		}
		else
		{
			ft_putchar_fd(str[i], 1); 
			len++;
		}
	}
	return (len);
}

/*
int	main(void)
{
	int		res = 0;
	char	c = 'x';
	char	str[] = "UwU OwO";
	int		n = 42;
	int		i = -65;
	
	res += ft_printf("AwA\n");
	res += ft_printf("%c\n", c);
	res += ft_printf("%s\n", str);
	res += ft_printf("%d\n", n);
	res += ft_printf("%i\n", i);
	res += ft_printf("%%\n");
	ft_printf("Res: %d\n", res);
	return (0);
}*/
