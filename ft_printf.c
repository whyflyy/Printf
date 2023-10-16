/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:46:27 by jcavadas          #+#    #+#             */
/*   Updated: 2023/10/16 13:21:22 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_conversions(const char c)
{
	if (c == 'c')
		return ()
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		len;

	i = -1;
	len = 0;
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
	return (len);
}

int	main(void)
{
	ft_printf("AWA OWO UWU");
	return (0);
}
