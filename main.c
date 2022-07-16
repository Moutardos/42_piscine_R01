/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:37:46 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/07/16 18:00:01 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	**ft_input_to_tab(char *arg, int n);

int	main(int ac, char **av)
{
	int	**tab;
	int	tab_size;

	if (ac >= 2)
	{
		tab_size = 4;
		tab = ft_input_to_tab(av[1], tab_size);
	}
	if (tab == NULL)
		return (-1);
	return (0);
}
