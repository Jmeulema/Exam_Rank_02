/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeulema <jmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:46:10 by jmeulema          #+#    #+#             */
/*   Updated: 2022/09/16 10:57:07 by jmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_repeat(char *str, char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		ft_strjoin(av[1], av[2]);
		while (av[1][i])
		{
			if (check_repeat(av[1], av[1][i], i))
				write (1, &av[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
