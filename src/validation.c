/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:52:25 by surpetro          #+#    #+#             */
/*   Updated: 2024/07/22 20:23:40 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	validation(int argc, char **s, t_info *info)
{
	if (inspect(s) == 0)
		return (0);
	info->number_of_philosophers = ft_atoi(s[1]);
	if (info->number_of_philosophers < 1 || info->number_of_philosophers > 200)
		return (0);
	info->time_to_die = ft_atoi(s[2]);
	info->time_to_eat = ft_atoi(s[3]);
	info->time_to_sleep = ft_atoi(s[4]);
	if (info->time_to_die < 0 || info->time_to_eat < 0
		|| info->time_to_sleep < 0)
		return (0);
	info->is_deat = 0;
	pthread_mutex_init(&info->print_mutex, NULL);
	pthread_mutex_init(&info->is_died_mutex, NULL);
	if (argc == 6)
		info->amount_work = ft_atoi(s[5]);
	else
		info->amount_work = -1;
	if (argc == 6 && info->amount_work < 0)
		return (0);
	return (1);
}
