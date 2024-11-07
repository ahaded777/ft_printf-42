/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:30:35 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/07 11:48:51 by aahaded          ###   ########.fr       */
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

// static int  ft_print_len_nbr(int nb)
// {
// 	int i;

// 	if (nb <= 0)
// 		i = 1;
// 	else
// 		i = 0;
// 	while (nb)
// 	{
// 		nb = (nb / 10);
// 		i++;
// 	}
// 	return (i);
// }

static char *ft_uitoa(unsigned int nb)
{
	int		len_num;
	char	*res;
	
	len_num = ft_len_num(nb);
	res = malloc(len_num + 1);
	if (!res)
		return (NULL);
	res[len_num] = '\0';
	if (nb == 0)
		res[0] = '0';
	while (nb)
	{
		res[--len_num] = (nb % 10) + 48;
		nb /= 10;
	}
	return (res);
}

int ft_print_unsigned(va_list args)
{
	char			*str;
	unsigned int	va;
	int				print_count;

	va = va_arg(args, unsigned int);
	str = ft_uitoa(va);
	print_count = ft_put_str(str);
	free(str);
	return (print_count);
}
