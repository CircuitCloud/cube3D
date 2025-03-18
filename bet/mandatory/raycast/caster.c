/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:40:55 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/17 13:11:44 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double periodic_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = angle + (2 * M_PI);
	return (angle);
}
// for kula ray
void ray_look_direction(double *angle, t_ray *ray)
{
	double ray_angle;
	
	ray->down = 0;
	ray->up = 0;
	ray->right = 0;
	ray->left = 0;
	*angle = periodic_angle(*angle);
	ray_angle = *angle;
	if (ray_angle >= 0 && ray_angle < M_PI)
		ray->down = 1;
	else
		ray->up = 1;
	if (ray_angle < (M_PI_2) || ray_angle > (3 * (M_PI_2)))
		ray->right = 1;
	else
		ray->left = 1;
	return;
}
