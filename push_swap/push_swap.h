/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:10:47 by gscala            #+#    #+#             */
/*   Updated: 2021/04/26 17:10:51 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

typedef struct s_list
{
	int				content;
	int				moving;
	struct s_list	*next;
	struct s_list	*prev;
	int				flag;
	int				lis;
	int				pa;
	int				pb;
}				t_list;

typedef struct s_heads
{
	t_list	*head_a;
	t_list	*head_b;
}				t_heads;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_push_convenience(t_heads *heads, t_list *node);
int		ft_iscinstr(char c, char const *str, size_t len);
int		ft_findpos(t_heads *heads, t_list *node);
int		ft_node_pos(t_list *head, t_list *node);
int		get_next_line(int fd, char **line);
int		ft_renewbuffer(char *buff);
int		ft_emptybuffer(char *buff);
int		ft_largest(t_heads *heads);
int		ft_findmin(t_list *head);
int		ft_atoi(const char *str);
int		ft_position(t_list *lst);
int		ft_lstsize(t_list *lst);
int		ft_isc(char c, char *s);
int		ft_issorted(t_list *lst);
int		ft_strlen2(char *s);
int		ft_isdigit(char c);
char	*ft_strnew(size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_pushflags(t_heads *heads, char *ret);
char	*ft_idealmove_values(t_heads *heads, char *ret);
void	ft_argparsing(int argc, char **argv, t_list **head, int j);
void	ft_lstadd_front(t_list *lst, t_list *new);
void	ft_lstadd_back(t_list *lst, t_list *new);
void	ft_parseline(char *line, t_heads *heads);
void	ft_rotation(t_heads *heads, char **ret);
void	ft_empty_a(t_heads *heads, char **ret);
void	ft_subsequence2(t_list *tmp2, int i);
void	ft_push(t_list **dst, t_list **src);
void	ft_checkargs(int argc, char **argv);
void	ft_checkduplicates(t_list *head);
void	ft_reverse_r(t_list **head);
void	ft_subsequence(t_list *lst);
void	ft_rotate(t_list **head);
void	ft_swap(t_list **head);
void	ft_error(void);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy2(char *dst, char *src, size_t dstsize);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);

#endif
