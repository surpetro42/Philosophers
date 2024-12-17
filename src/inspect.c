/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:52:25 by surpetro          #+#    #+#             */
/*   Updated: 2024/07/22 20:23:30 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	inspect(char **s)
{
	int	i;
	int	l;

	i = 1;
	while (s[i])
	{
		l = 0;
		while (s[i][l])
		{
			if (!(s[i][l] >= '0' && s[i][l] <= '9'))
			{
				printf("ERROR!\nSxal mutqagrum\n");
				return (0);
			}
			l++;
		}
		i++;
	}
	return (1);
}
