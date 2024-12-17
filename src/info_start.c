/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:55:20 by surpetro          #+#    #+#             */
/*   Updated: 2024/07/22 21:55:21 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	info_start(int argc, char **argv, t_info *info)
{
	if (validation(argc, argv, info) == 0)
		return (0);
	if (initializations_philo(info) == 0)
		return (0);
	return (1);
}
