/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:30:35 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/06 22:25:04 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_unsigned(va_list args)
{
	char			*str;
	int				print_count;
	unsigned int	va;

	print_count = 0;
	va = va_arg(args, unsigned int);
	str = ft_itoa((int)va);
	print_count += ft_put_str(str);
	return (print_count);
}
