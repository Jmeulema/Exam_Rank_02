/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeulema <jmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:57:23 by jmeulema          #+#    #+#             */
/*   Updated: 2022/09/29 13:16:37 by jmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_printchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printstr(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int nb)
{
	long long int	n;
	int				len;

	len = 0;
	n = nb;
	if (n < 0)
	{
		len += ft_printchar('-');
		n = -n;
	}
	if (n > 9)
	{
		len += ft_printnbr(n / 10);
		len += ft_printnbr(n % 10);
	}
	else
		len += ft_printchar(n + 48);
	return (len);
}

int	ft_printhexa(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += ft_printhexa(n / 16);
		len += ft_printhexa(n % 16);
	}
	else if (n > 9)
		len += ft_printchar(n + 87);
	else
		len += ft_printchar(n + 48);
	return (len);
}

int	ft_search_args(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'x')
		len += ft_printhexa(va_arg(args, unsigned int));
	else if (format == 'd')
		len += ft_printnbr(va_arg(args, int));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_search_args(args, format[i + 1]);
			i++;
		}
		else
			len += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
