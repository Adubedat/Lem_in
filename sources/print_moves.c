/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:02:42 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/23 16:04:18 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_moves(t_ants ants[], int ants_nbr)
{
	int	i;

	i = 0;
	while (i < ants_nbr)
	{
		while (ants[i].room->next == NULL)
		{
			ants[i].room->ant = 0;
			i++;
		}
		if (ants[i].room->next->ant == 0)
		{
			ft_printf("L%d-%s ", ants[i].name, ants[i].room->next->name);
			ants[i].room->next->ant = ants[i].name;
			ants[i].room->ant = 0;
			ants[i].room = ants[i].room->next;
		}
		i++;
	}
	ft_putchar('\n');
	if (ants[ants_nbr - 1].room->next == NULL)
		return ;
	return (print_moves(ants, ants_nbr));
}
