/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:54:16 by surpetro          #+#    #+#             */
/*   Updated: 2024/07/22 21:54:20 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 5 || argc == 6)
	{
		if (info_start(argc, argv, &info) == 0)
		{
			printf("invalid input\n");
			return (1);
		}
	}
	else
	{
		printf("ERROR!\nSxal qanaki mutqagrum\n");
		return (1);
	}
	start_philo(&info);
	return (0);
}
