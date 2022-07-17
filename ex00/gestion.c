/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:06:19 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/07/17 15:07:20 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
void	free_tab(int **tab, int size)
{
	int	c;

	c = 0;
	while (c < size)
	{
		if (tab[c] != NULL)
			free(tab[c]);
	}
	free(tab);
}

int	**crea_tab(int size)
{
	int	i;
	int	**sol;

	i = 0;
	sol = (int **) malloc (size * sizeof (int *) + 1);
	while (i < size)
	{
		sol[i] = (int *) malloc(size * sizeof(int) + 1);
		i++;
	}
	return (sol);
}
