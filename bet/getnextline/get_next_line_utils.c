/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:42:52 by cahaik            #+#    #+#             */
/*   Updated: 2025/02/23 08:39:58 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*get_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if ((char)c == '\0')
		return ((char *)str + get_strlen(str));
	while (*str != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*get_strjoin(char *sttc, char *buff)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	int		len;

	i = 0;
	j = 0;
	if (!sttc && !buff)
		return (NULL);
	len = get_strlen(sttc) + get_strlen(buff);
	if (len == 0)
		return (free(sttc), NULL);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (sttc && sttc[i])
	{
		ptr[i] = sttc[i];
		i++;
	}
	while (buff && buff[j])
		ptr[i++] = buff[j++];
	return (ptr[i] = '\0', free(sttc), sttc = NULL, ptr);
}

char	*get_strdup(char *str)
{
	size_t	i;
	size_t	size;
	char	*ptr;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		size++;
		i++;
	}
	ptr = (char *)malloc(1 * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
