
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:29:58 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/11 03:54:37 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_trove(char const *str, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str && str[i] == c)
	{
		i++;
	}
	while (str && str[i])
	{
		if ((str[i] == c && str[i + 1] != c) || str[i + 1] == '\0')
			k++;
		i++;
	}
	return (k);
}

void	ft_free(char **p)
{
	int	i;

	i = 0;
	while (p && p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}

char	**copieword(char **p, const char *s, char c)
{
	int (i), (l), (t);
	i = 0;
	t = 0;
	while (s && s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (p);
		l = i;
		while (s && s[i] && s[i] != c)
			i++;
		p[t] = ft_substr(s, l, (i - l));
		if (!p[t])
		{
			ft_free(p);
			return (NULL);
		}
		t++;
	}
	return (p);
}


char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;

	if (!s)
		return (NULL);
	i = ft_trove(s, c);
	p = (char **)malloc(sizeof(char *) * (i + 1));
	if (!p)
		return (NULL);
	if (!copieword(p, s, c))
		return (NULL);
	p[i] = NULL;
	return (p);
}

size_t	ft_strlenn(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
