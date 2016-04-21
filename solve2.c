/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 18:34:26 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/21 22:48:40 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*create_elem(t_room *path, char *name)
{
	t_room	*temp;
	t_room	*new;

	temp = path;
	if (path == NULL)
	{
		path = (t_room*)malloc(sizeof(t_room));
		path->name = ft_strdup(name);
		path->next = NULL;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		new = (t_room*)malloc(sizeof(t_room));
		new->name = ft_strdup(name);
		new->next = NULL;
		temp->next = new;
	}
	return (path);
}
