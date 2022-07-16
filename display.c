/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoffner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:00:42 by vhoffner          #+#    #+#             */
/*   Updated: 2022/07/16 19:00:46 by vhoffner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

int	**ft_input_to_tab(char *arg, int m);

void	ft_putchar(int i)
{
	char	c;

	c = i + '0';
	write(1, &c, 1);
}

void	output_tab(int **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(tab[i][j]);
			j++;
			if (j != size)
				write(1, " ", 1);
			if (j == size)
				write(1, "\n", 1);
		}
	i++;
	}
}
=======
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:02:58 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/07/16 17:50:04 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
>>>>>>> 6ff9f7c70abe98c5c82bc4dae3989ac0b24bcd34
