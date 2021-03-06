/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoffner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:00:42 by vhoffner          #+#    #+#             */
/*   Updated: 2022/07/17 18:59:57 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

#include<stdlib.h>

void	ft_putchar(int i)
{
	char c;

	c = i + '0';
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}
void	output_tab(int **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(tab[i][j] + 1);
			j++;
			if (j != size)
				write(1, " ", 1);
			if (j == size)
				write(1, "\n", 1);
		}
	i++;
	}
}
