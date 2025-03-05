/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:16:47 by cahaik            #+#    #+#             */
/*   Updated: 2025/02/25 10:01:17 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int ac, char **av)
{
	// mlx_t *win = mlx_init(500, 500, "Chaima", false);
	// mlx_image_t *img = mlx_new_image(win, 500, 500);
	// mlx_image_to_window(win, img, 0, 0);
	// mlx_loop(win);
	if (ac == 2)
	{
		if (ft_strcmp(".cub", ft_strrchr(av[1], '.')))
			return (write(1, "**Invalid Map Name**\n", 21), 1);
		parse(av[1]);
	}
	else
		write(1, "**PARAMETERS ERROR**\n", 21);
	return (0);
}
