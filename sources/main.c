/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 20:02:35 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/24 19:20:23 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_ants_number(char **input)
{
	char	*str;
	int		i;

	i = 0;
	if (get_next_line(0, &str) == -1)
	{
		ft_putendl("Error : Reading has failed.");
		exit(1);
	}
	if (str[0] == '\0')
	{
		ft_putendl("Error : Not enough data.");
		exit(1);
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			ft_putendl("Error : Invalid ants number.");
			exit(1);
		}
		i++;
	}
	*input = ft_strjoin_free_both(*input, str);
	return (ft_atoi(str));
}

static int	special_case(t_rooms *room)
{
	t_rooms	*temp;

	temp = room;
	while (temp != NULL)
	{
		if (temp->start == 1 && temp->end == 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void		check_ants(int ants)
{
	if (ants < 0)
	{
		ft_putendl("Error : Invalid ants number.");
		exit(1);
	}
}

int			main(int argc, char **argv)
{
	t_rooms	*room;
	int		ants;
	char	*input;
	t_paths	*paths;

	room = NULL;
	paths = NULL;
	check_help(argc, argv);
	input = ft_strdup("");
	ants = get_ants_number(&input);
	check_ants(ants);
	room = get_input(&input, room, 0, 0);
	check_data(room);
	if (special_case(room) == 1 || ants == 0)
	{
		ft_putendl(input);
		return (0);
	}
	ft_putendl(input);
	ft_putchar('\n');
	solve(room, &paths);
	check_bonus(room, paths, argv);
	move_ants(paths, ants, argv);
	return (0);
}
