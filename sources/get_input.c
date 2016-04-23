/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 21:45:10 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/23 14:29:48 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		check_room(char *str, int i)
{
	if (str[0] == 'L')
		return (0);
	while (str[i] != ' ')
	{
		if (str[i++] == '\0')
			return (0);
	}
	i++;
	if (str[i] == '-')
		i++;
	while (str[i] != ' ')
	{
		if (!(str[i] >= '0' && str[i] <= '9') || str[i] == '\0')
			return (0);
		i++;
	}
	i++;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i++] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

static int		check_str(char *str, t_rooms *room)
{
	static int	flag = 1;
	int			i;

	i = 0;
	if (flag == 1)
	{
		if (check_room(str, 0) == 0)
		{
			flag = 2;
			return (check_str(str, room));
		}
		else
			return (1);
	}
	return (check_tube(str, 0, room));
}

static t_rooms	*create_room(t_rooms *room, char *str, int start, int end)
{
	t_rooms	*new;
	t_rooms *temp;
	char	**split;

	temp = room;
	split = ft_strsplit(str, ' ');
	while (temp != NULL)
	{
		if (ft_strcmp(temp->name, split[0]) == 0)
			error_room();
		temp = temp->next;
	}
	new = (t_rooms*)malloc(sizeof(t_rooms));
	new->name = ft_strdup(split[0]);
	new->x = ft_atoi(split[1]);
	new->y = ft_atoi(split[2]);
	new->tubes = NULL;
	new->start = start;
	new->end = end;
	new->number = -1;
	new->used = 0;
	new->next = room;
	room = new;
	free_split(split);
	return (room);
}

static t_rooms	*create_tube(t_rooms *room, char *str)
{
	char	**split;
	t_tubes *new[2];
	t_rooms *temp;
	t_rooms *temp2;

	temp = room;
	temp2 = room;
	split = ft_strsplit(str, '-');
	while (ft_strcmp(temp->name, split[0]) != 0)
		temp = temp->next;
	while (ft_strcmp(temp2->name, split[1]) != 0)
		temp2 = temp2->next;
	new[0] = (t_tubes*)malloc(sizeof(t_tubes));
	new[0]->room = temp;
	new[0]->next = temp2->tubes;
	temp2->tubes = new[0];
	new[1] = (t_tubes*)malloc(sizeof(t_tubes));
	new[1]->room = temp2;
	new[1]->next = temp->tubes;
	temp->tubes = new[1];
	return (room);
}

t_rooms			*get_input(char **input, t_rooms *room, int start, int end)
{
	char	*str;

	if (get_next_line(0, &str) == 0 || str[0] == '\0')
		return (room);
	if (ft_strcmp(str, "##start") == 0)
		start = 1;
	else if (ft_strcmp(str, "##end") == 0)
		end = 1;
	else if (str[0] == '#')
		;
	else
	{
		if (check_str(str, room) == 0)
			return (room);
		else if (check_str(str, room) == 1)
			room = create_room(room, str, start, end);
		else
			room = create_tube(room, str);
		start = 0;
		end = 0;
	}
	*input = ft_strjoin_free_s1(*input, "\n");
	*input = ft_strjoin_free_both(*input, str);
	return (get_input(input, room, start, end));
}
