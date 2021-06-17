/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:09:38 by gscala            #+#    #+#             */
/*   Updated: 2021/04/26 17:09:40 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_callother(char *line, t_heads *heads)
{
	if (!ft_strncmp(line, "ss", 2))
	{
		ft_swap(&heads->head_a);
		ft_swap(&heads->head_b);
	}
	else if (!ft_strncmp(line, "rrr", 3))
	{
		ft_reverse_r(&heads->head_a);
		ft_reverse_r(&heads->head_b);
	}
	else if (!ft_strncmp(line, "rr", 2))
	{
		ft_rotate(&heads->head_a);
		ft_rotate(&heads->head_b);
	}
}

void	ft_parseline(char *line, t_heads *heads)
{
	if (!ft_strncmp(line, "rra", 3))
		ft_reverse_r(&heads->head_a);
	else if (!ft_strncmp(line, "rrb", 3))
		ft_reverse_r(&heads->head_b);
	else if (!ft_strncmp(line, "rrr", 3))
		ft_callother(line, heads);
	else if (!ft_strncmp(line, "sa", 2))
		ft_swap(&heads->head_a);
	else if (!ft_strncmp(line, "sb", 2))
		ft_swap(&heads->head_b);
	else if (!ft_strncmp(line, "ss", 2))
		ft_callother(line, heads);
	else if (!ft_strncmp(line, "pa", 2))
		ft_push(&heads->head_a, &heads->head_b);
	else if (!ft_strncmp(line, "pb", 2))
		ft_push(&heads->head_b, &heads->head_a);
	else if (!ft_strncmp(line, "ra", 2))
		ft_rotate(&heads->head_a);
	else if (!ft_strncmp(line, "rb", 2))
		ft_rotate(&heads->head_b);
	else if (!ft_strncmp(line, "rr", 2))
		ft_callother(line, heads);
	else
		ft_error();
}
