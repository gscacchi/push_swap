/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:12:06 by gscala            #+#    #+#             */
/*   Updated: 2021/04/26 17:12:07 by gscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*s3;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen2(s1) + ft_strlen2(s2);
	s3 = malloc(len + 1);
	if (!(s3))
		return (NULL);
	ft_strlcpy2(s3, s1, ft_strlen2(s1) + 1);
	ft_strlcat(s3, (char *)s2, len + 1);
	free(s1);
	return (s3);
}

int	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy2(char *dst, char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!dst)
		return (0);
	while (src[len])
		len++;
	if (dstsize != 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*(dst + i) && i < dstsize)
		++i;
	while (*src && i + 1 < dstsize)
	{
		*(dst + i) = *src;
		++src;
		++i;
	}
	if (i < dstsize)
		*(dst + i) = 0;
	while (*src++)
		++i;
	return (i);
}
