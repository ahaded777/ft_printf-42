/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:36:35 by aahaded           #+#    #+#             */
/*   Updated: 2024/11/06 22:43:30 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_print_percent(void)
{
	return (write(1, "%", 1));
}

int	ft_print_char(va_list args)
{
	int	va;

	va = va_arg(args, int);
	return (write(1, &va, 1));
}

int	ft_format(const char c, va_list args)
{
	int	print_count;

	print_count = 0;
	if (c == 'c')
		print_count += ft_print_char(args);
	else if (c == 's')
		print_count += ft_print_string(args);
	else if (c == 'p')
		print_count += ft_print_ptr(args);
	else if (c == 'd' || c == 'i')
		print_count += ft_print_num(args);
	else if (c == 'u')
		print_count += ft_print_unsigned(args);
	else if (c == 'x' || c == 'X')
		print_count += ft_print_hex(c, args);
	else if (c == '%')
		print_count += ft_print_percent();
	return (print_count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_count;
	va_list	args;

	i = 0;
	print_count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print_count += ft_format(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			print_count++;
		}
		i++;
	}
	va_end(args);
	return (print_count);
}
 
int main()
{
     int len;
     int len2;
     unsigned int ui;
     void *addr;

   len = ft_printf("Let's try to printf a simple sentence.\n");
     len2 = printf("Let's try to printf a simple sentence.\n");
     ui = (unsigned int)1024 + 1024;
     addr = (void *)0x7ffe637541f0;
     ft_printf("Length:[%d, %i]\n", len, len);
     printf("Length:[%d, %i]\n", len2, len2);
     ft_printf("Negative:[%d]\n", -762534);
     printf("Negative:[%d]\n", -762534);
     ft_printf("Unsigned:[%u]\n", ui);
     printf("Unsigned:[%u]\n", ui);
     ft_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
     printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
     ft_printf("Character:[%c]\n", 'H');
     printf("Character:[%c]\n", 'H');
 	 ft_printf("String:[%s]\n", "I am a string !");
     printf("String:[%s]\n", "I am a string !");
     ft_printf("Address:[%p]\n", addr);
     printf("Address:[%p]\n", addr);
     len = ft_printf("Percent:[%%]\n");
     len2 = printf("Percent:[%%]\n");
     ft_printf("Len:[%d]\n", len);
     printf("Len:[%d]\n", len2);
     return (0);
}
