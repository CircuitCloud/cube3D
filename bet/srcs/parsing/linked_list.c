/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:46:51 by cahaik            #+#    #+#             */
/*   Updated: 2025/02/25 16:48:32 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_identifier	*cub_lstnew()
{
	t_identifier	*new;

	new = (t_identifier *)malloc(sizeof(t_identifier));
	if (!new)
		return (NULL);
	new->identifier = NULL;
	new->path = NULL;
	new->colors = NULL;
	new->next = NULL;
	return (new);
}

t_identifier	*cub_lstlast(t_identifier *lst)
{
	t_identifier	*last;

	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}

void	cub_lstadd_back(t_identifier **lst, t_identifier *new)
{
	t_identifier	*head;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		head = cub_lstlast(*lst);
		head->next = new;
	}
}
