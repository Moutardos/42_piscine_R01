/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C04_ex03_ft_atoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoffner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:40:07 by vhoffner          #+#    #+#             */
/*   Updated: 2022/07/15 02:33:03 by vhoffner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<stdlib.h>
// check isspace et return 0 pour le reste si la fonction ne commence par des space ou singes signes
int	count_sign(char *str, int i)
{
	int n;	

	n = 0; 	
	while (str[i] == '+' || str[i] == '-')
	{	
		if (str[i] == '-')
			n++;
		i++;
	}

	if (n % 2 == 0)
		return(1);
	else
		return(-1); 
		
}

int	ft_atoi(char *str)
{
	int i; 
	int n;

	i = 0;
	n = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '9')
		{	
			n = 10 * n + (str[i] - '0');
			if (str[i + 1] < '0' || str[i + 1] > '9')
				break;
		}
	i++;
	}
	i = 0; 
	while (str[i] != '\0')
        {
                if (str[i] == '-')
		{
			n = n * (count_sign(str, i));
			break;
		}
		i++;
	}
	return n;
}

int main(int ac, char **av)
{
	printf("%d\n", ft_atoi(av[1]));
	printf("%d\n", atoi(av[1]));
}
