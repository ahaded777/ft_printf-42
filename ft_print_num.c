/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:31:17 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/07 10:19:21 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_put_strw(char *str)
{
	int	i;
	int	ret;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		ret = write(1, &str[i], 1);
		if (ret == -1)
			return (-1);
		i++;
	}
	return (i);
}

static int	ft_len_num(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	else
		i = 0;
	while (n)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

static char	*ft_itoa(int n)
{
	int		len_num;
	long	nb;
	char	*res;

	nb = n;
	len_num = ft_len_num(nb);
	res = malloc(len_num + 1);
	if (!res)
		return (NULL);
	res[len_num] = '\0';
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		res[len_num - 1] = (nb % 10) + 48;
		nb = nb / 10;
		len_num--;
	}
	return (res);
}

int	ft_print_num(va_list args)
{
	int		va;
	int		print_count;
	char	*s_num;

	va = va_arg(args, int);
	s_num = ft_itoa(va);
	if (!s_num)
		return (-1);
	print_count = ft_put_strw(s_num);
	free(s_num);
	if (print_count == -1)
		return (-1);
	return (print_count);
}
