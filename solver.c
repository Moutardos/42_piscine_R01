/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrier <mserrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 09:08:20 by mserrier          #+#    #+#             */
/*   Updated: 2022/07/17 18:58:17 by mserrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


void	crea_solut(int size, int **tab, int *pos, int **ind);
void	output_tab(int **tab, int size);

int	value_of_line(int size, int sens, int *line)
{
	int	pos;
	int	lim;
	int	max;

	if (sens < 0)
	{
		pos = size - 1;
		lim = -1;
	}
	else
	{
		pos = 0;
		lim = size;
	}
	max = line[pos];
	while (pos != lim)
	{
		if (line[pos] < max)
			size--;
		else
			max = line[pos];
		pos += sens;
	}
	return (size);
}

//	return the number of box visible in the i-th column,
//  don't work if size <= 1
//	size -> size of solution
//	sens -> 1 up-down and -1 down-up
//	i -> the i-th column
//	sol -> solution given
int	value_of_col(int size, int sens, int i, int **sol)
{
	int	pos;
	int	lim;
	int	max;

	if (sens < 0)
	{
		pos = size - 1;
		lim = -1;
	}
	else
	{
		pos = 0;
		lim = size;
	}
	max = sol[pos][i];
	while (pos != lim)
	{
		if (sol[pos][i] < max)
			size--;
		else
			max = sol[pos][i];
				pos += sens;
	}
	return (size);
}

//	check if sol is a correct solution
//	since indication[0] -> colup     [2] -> rowleft
//									[1] -> coldown   [3] -> rowright
//	we use a formula to get the position through 'is_neg'
int	verif_ligcol(int **sol, int i, int j)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < i)
	{
		if (sol[a][j] == sol[i][j])
			return (0);
		a++;
	}
	while (b < j)
	{
		if (sol[i][b] == sol[i][j])
			return (0);
		b++;
	}
	return (1);
}

void	crea_solut2(int size, int **tab, int *pos, int **ind)
{
	if (verif_ligcol(tab, pos[0], pos[1]))
	{
		if (pos[1] == size - 1)
		{
			if (!(value_of_line(size, 1, tab[pos[0]]) == ind[2][pos[0]]))
				if (!(value_of_line(size, -1, tab[pos[0]]) == ind[3][pos[0]]))
					return ;
			pos[1] = -1;
			pos[0]++;
		}
		else if (pos[0] == size - 1)
			if (!(value_of_col(size, 1, pos[1], tab) == ind[0][pos[1]]))
				if (!(value_of_col(size, -1, pos[1], tab) == ind[1][pos[1]]))
					return ;
		pos[1]++;
		crea_solut(size, tab, pos, ind);
	}
}

void	crea_solut(int size, int **tab, int *pos, int **ind)
{
	int	a;

	a = 0;
	if (pos[0] == size - 1 && pos[1] == size - 1)
	{
		output_tab(tab, size);
		return ;
	}
	while (a < size)
	{
		tab[pos[0]][pos[1]] = a++;
		crea_solut2(size, tab, pos, ind);
	}
}
