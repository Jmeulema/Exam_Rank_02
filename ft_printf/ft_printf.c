/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeulema <jmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:57:23 by jmeulema          #+#    #+#             */
/*   Updated: 2022/09/12 18:45:09 by jmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_print_char(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_str(const char *s1)
{
	int	i;

	i = 0;
	if (!s1)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s1[i])
	{
		write (1, &s1[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int nb)
{
	long long	n;
	int			len;

	len = 0;
	n = nb;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		len += ft_print_nbr(n / 10);
		len += ft_print_nbr(n % 10);
	}
	else
		len += ft_print_char(n + 48);
	return (len);
}

int	ft_print_hexa(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += ft_print_hexa(n / 16);
		len += ft_print_hexa(n % 16);
	}
	else if (n > 9)
		len += ft_print_char(n + 87);
	else
		len += ft_print_char(n + 48);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	arg;

	len = 0;
	i = -1;
	va_start(arg, format);
	while (format[++i])
	{
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		else if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 's')
				len += ft_print_str(va_arg(arg, char *));
			else if (format[i] == 'x')
				len += ft_print_hexa(va_arg(arg, unsigned int));
			if (format[i] == 'd')
				len += ft_print_nbr(va_arg(arg, int));
		}
	}
	va_end(arg);
	return (len);
}
