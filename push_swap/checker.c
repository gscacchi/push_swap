/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:09:14 by gscala            #+#    #+#             */
/*   Updated: 2021/04/26 17:09:16 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checkargs(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-')
				ft_error();
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_argparsing(int argc, char **argv, t_list **head, int j)
{
	int		i;
	t_list	*tmp;
	char	**arr;

	i = 1;
	j = 0;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		while (arr[j])
		{
			if (i == 1 && j == 0)
				*head = ft_lstnew(ft_atoi(arr[j]));
			else
			{
				tmp = ft_lstnew(ft_atoi(arr[j]));
				ft_lstadd_back(*head, tmp);
			}
			free(arr[j]);
			j++;
		}
		free(arr);
		i++;
		j = 0;
	}
}

int	ft_sortedlist(t_heads heads)
{
	int		mem;
	t_list	*tmp;

	if (heads.head_b == NULL)
	{
		if (heads.head_a == NULL)
			return (1);
		tmp = heads.head_a;
		mem = tmp->content;
		while (tmp->next)
		{
			if (tmp->next->content < mem)
				return (0);
			tmp = tmp->next;
			mem = tmp->content;
		}
		return (1);
	}
	else
		return (0);
}

void	ft_checkduplicates(t_list *head)
{
	int		mem;
	t_list	*tmp1;
	t_list	*tmp2;

	if (head == NULL)
		return ;
	tmp1 = head;
	tmp2 = tmp1;
	mem = tmp1->content;
	while (tmp2->next)
	{
		while (tmp1->next)
		{
			if (tmp1->next->content == mem)
				ft_error();
			tmp1 = tmp1->next;
		}
		tmp2 = tmp2->next;
		tmp1 = tmp2;
		mem = tmp1->content;
	}
}

int	main(int argc, char **argv)
{
	char	*line;
	t_heads	heads;

	heads.head_a = NULL;
	heads.head_b = NULL;
	if (argc == 1)
		ft_error();
	ft_checkargs(argc, argv);
	ft_argparsing(argc, argv, &heads.head_a, 0);
	ft_checkduplicates(heads.head_a);
	while (get_next_line(0, &line))
		ft_parseline(line, &heads);
	if (ft_sortedlist(heads))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
