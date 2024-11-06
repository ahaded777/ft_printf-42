/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:06:11 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/06 18:34:40 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int ft_put_char(char c)
{
	return (write(1, &c, 1));
}

static int	ft_put_HEX(int va)
{
	int		print_count;
	char	*str_hex;

	print_count = 0;
	str_hex = "0123456789ABCDEF";
	if (va >= 16)
		print_count += ft_put_HEX(va / 16);
	print_count += ft_put_char(str_hex[va % 16]);
	return (print_count);
}

static int	ft_put_hex(int va)
{
	int		print_count;
	char	*str_hex;

	print_count = 0;
	str_hex = "0123456789abcdef";
	if (va >= 16)
		print_count += ft_put_hex(va / 16);
	print_count += ft_put_char(str_hex[va % 16]);
	return (print_count);
}

int	ft_print_hex(char c, va_list args)
{
	int print_count;
	int va;

	print_count = 0;
	va = va_arg(args, int);
	if (c == 'x')
		print_count += ft_put_hex(va);
	else if (c == 'X')
		print_count += ft_put_HEX(va);
	return (print_count);
}
