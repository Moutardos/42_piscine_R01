/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrier <mserrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 09:08:20 by mserrier          #+#    #+#             */
/*   Updated: 2022/07/17 09:36:37 by mserrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
/*
int	verif_caisse(int size, int depl, int sens, int sol[size][size], int cote, int place)
{
	int	valeur;

	if (cote % 2 == 0)
		valeur = sol[depl][place];
	else
		valeur = sol[cote][depl];
	depl += sens;
	while (depl != -1 && depl != size)
	{
		if (sol[depl][place] > valeur)
			return (0);
		depl += sens;
	}
	while (depl != -1 && depl != size)
	{
		if (sol[cote][depl] > valeur)
			return (0);
		depl += sens;
	}
	return (1);
}
*/



//	return the numbers of boxes from the given line,
//  don't work if size <= 1
//	size -> size of solution
//	sens -> 1 left-right and -1 right-left
//	sol -> a line from the solution
int value_of_line(int size, int sens, int* line)
{
	int pos;
	int lim;
	int max;

	if (sens < 0 )
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
	return size;
}

//	return the number of box visible in the i-th column,
//  don't work if size <= 1
//	size -> size of solution
//	sens -> 1 up-down and -1 down-up
//	i -> the i-th column
//	sol -> solution given
int value_of_col(int size, int sens, int i, int** sol)
{
	int pos;
	int lim;
	int max;

	if (sens < 0 )
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
	return size;
}

//	check if sol is a correct solution
//	since indication[0] -> colup     [2] -> rowleft
//									[1] -> coldown   [3] -> rowright
//	we use a formula to get the position through 'is_neg'
int verif_ligcol(int **sol, int i, int j)
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

int  **crea_tab(int size)
{
	int	i;
	int	**sol;

	i = 0;
	sol = (int **) malloc (size *  sizeof(int*) + 1);
	while (i < size)
	{
		sol[i] = (int *) malloc(size * sizeof(int) + 1);
		 i++;
	}
	return (sol);
}

void	crea_solut(int size, int **tab, int x, int y, int **ind)
{
	int	a;

	a = 0;
	if (x == size - 1 && y == size - 1)
	{
		output_tab(tab, 4);
		return;
	}
	while (a < size)
	{
		tab[x][y] = a++;
		if (verif_ligcol(tab, x, y))
		{
			if (y == size - 1)
			{
				if (!(value_of_line(size, 1, tab[x]) == ind[2][x] && value_of_line(size, -1, tab[x]) == ind[3][x]))
					return;
				y = -1;
				x++;
			}
			else if (x == size - 1)
				if (!(value_of_col(size, 1, y, tab) == ind[0][y] && value_of_col(size, -1, y, tab) == ind[1][y]))
					return;
			crea_solut(size, tab, x, y + 1, ind);
		}
	}
	return;
}
/* size  :  tail0le tableau
/  cote  :  0 : colup     2:rowleft
/			 	   	1 : coldown   3:rowright
/  place : position de l'indication
/	 sol   : la solution	
int	verif_ligne(int size, int cote, int place, int sol[size][size])
{
	int	depl;
	int	sens;
	int	valeur;
	int	compt;
	int	nb;

	compt = 0;
	if (cote > size / 2)
		depl = size - 1;
	else
		depl = 0;
	sens = -2 * (depl % (size - 2)) + 1;
	while (depl != -1 && depl != size)
	{
		if (verif_caisse(size, depl, sens, sol, cote, place))
			compt++;
		depl += sens;
	}
	if (compt == nb)
		return (1);
	return (0);
}

int	soluc(int size, int sol[size][size], int dep[size][size])
{
	int	place;
	int	cote;
	int	depl;

	cote = 0;
	while (cote < size)
	{
		place = 0;
		while (place < size)
		{
			if (!verif_ligne(size, cote, place, dep[cote][size]))
				return (0);
		place++;
		}
		cote++;
	}
	return (1);
}
int verif_ligcol(int size, int *sol[size], int i, int j)
{
  int a;
  int b;

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

int  **crea_tab(int size)
{
  int  i;
  int  j;
  int **sol;

  i = 0;
  sol = (int **) malloc (size *  sizeof(int[size]));
  while (i < size)
      sol[i] = (int *) malloc(size * sizeof(int));
  return (sol);
}

int  **crea_soluc(int size, int tab[size][size], int i, int j)
{
  int a;

  a = 0;
  while (i < size)
    {
      j = 0;
      while (j < size)
        
    }
  return (sol);
}*/ 