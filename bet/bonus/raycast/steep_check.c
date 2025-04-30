/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steep_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:39:39 by ykamboua          #+#    #+#             */
/*   Updated: 2025/04/30 00:32:58 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	steep_y_check(t_ray *ray)
{
	if (ray->up)
		ray->step_y = -TILESIZE;
	else
		ray->step_y = TILESIZE;
}

void	steep_x_check(t_ray *ray)
{
	if (ray->right)
		ray->step_x = TILESIZE;
	else
		ray->step_x = -TILESIZE;
}
