/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:07:02 by cahaik            #+#    #+#             */
/*   Updated: 2025/03/23 15:15:47 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*convert_to_space(char *str)
{
	int		len;
	int		i;
	char	*newstr;

	i = 0;
	len = ft_strlen(str);
	if (!len)
		return (NULL);
	newstr = malloc(len + 1);
	while (i < len)
	{
		if (str[i] == '\t')
			newstr[i] = ' ';
		else
			newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
