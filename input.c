/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:07:33 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/07/17 18:40:21 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (c == '\t' || c == '\f' || c == '\n' || c == '\v' || c == '\r');
}

//	take a string and put every digit (between 2 and 9)
//	in a double arrayf
int	**ft_input_to_tab(char *arg, int n)
{
	int	**tab;
	int	i;
	int	j;

	j = 0;
	tab = (int **) malloc(4 * sizeof(int *));
	while (j < 4)
	{
		i = 0;
		tab[j] = (int *) malloc(n * sizeof(int));
		while (i < n)
		{
			while (ft_isspace(*arg))
				arg++;
			if (*arg >= '0' && *arg <= '9')
				tab[j][i] = *arg++ - '0';
			else
				return (NULL);
			i++;
		}
		j++;
		i = 0;
	}
	return (tab);
}
