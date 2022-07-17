/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:37:46 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/07/17 18:46:13 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>
int	**ft_input_to_tab(char *arg, int n);
void	output_tab(int **tab, int size);
void	ft_putstr(char *str);
void	crea_solut(int size, int **tab, int *coord, int **ind);
int	**crea_tab(int size);

//	first arg: string that describe the puzzle (number delimated by spaces)
//	second arg (optional): size of the puzzle (4 if empty)
int	main(int ac, char **av)
{
	int	**tab;
	int	tab_size;
	int **solution;
	int coord[2];
	
	coord[0] = 0;
	coord[1] = 0;
	if (ac >= 2)
	{
		tab_size = 4;
		if (ac == 3)
			tab_size = av[2][0] - '0';
		tab = ft_input_to_tab(av[1], tab_size);
	}	
	if (tab == NULL)
	{
		ft_putstr("Error with the input");
		return (-1);
	}
	solution = crea_tab(tab_size);
	crea_solut(tab_size, solution, coord,tab);
	return (0);
}
