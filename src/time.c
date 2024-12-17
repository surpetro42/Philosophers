/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:52:25 by surpetro          #+#    #+#             */
/*   Updated: 2024/07/22 19:17:29 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long	get_time(void)
{
	static long long	start;
	t_timeval			time;

	if (start == 0)
	{
		gettimeofday(&time, NULL);
		start = time.tv_sec * 1000 + time.tv_usec / 1000;
	}
	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)) - start);
}

void	usleep_philo(t_philosophers *philo, long long time)
{
	long long	t2;

	t2 = get_time();
	while (get_time() - t2 <= time)
	{
		pthread_mutex_lock(&philo->info->is_died_mutex);
		if (philo->info->is_deat == -1)
		{
			pthread_mutex_unlock(&philo->info->is_died_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->info->is_died_mutex);
		usleep(500);
	}
}
