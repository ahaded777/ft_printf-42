/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:31:17 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/06 17:53:14 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "./libft/libft.h"

static int ft_put_str(char *str)
{
	int i;
	int	print_count;

	i = 0;
	print_count = 0;
	if (str == NULL)
		return (write(1, "(nil)\n", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (print_count);
}

int	ft_print_num(va_list args)
{
	int		va;
	int		print_count;
	char	*s_num;

	va = va_arg(args, int);
	s_num = ft_itoa(va);
	print_count = ft_put_str(s_num);
	free(s_num);
	return (print_count);
}
