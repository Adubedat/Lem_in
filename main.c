/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 20:02:35 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/19 07:38:48 by adubedat         ###   ########.fr       */
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
		ft_putendl("Error : Reading has failed");
		exit (1);
	}
	if (str[0] == '\0')
	{
		ft_putendl("Error : Not enough data");
		exit (1);
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			ft_putendl("Error : Invalid ants number");
			exit(1);
		}
		i++;
	}
	*input = ft_strjoin_free_both(*input, str);
	return (ft_atoi(str));
}

int			main(int argc, char **argv)
{
	t_rooms	*room;
	int		ants;
	char	*input;
	char	*str;

	room = NULL;
	input = ft_strdup("");
	ants = get_ants_number(&input);
	room = get_input(&input, room, 0, 0);
	check_data(room);
	ft_putendl(input);
	if (ants == 0)
		return (0);
	ft_putchar('\n');
	solve(room);
	return (0);
}
