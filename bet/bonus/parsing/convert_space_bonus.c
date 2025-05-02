/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:07:02 by cahaik            #+#    #+#             */
/*   Updated: 2025/04/30 00:32:40 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

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
