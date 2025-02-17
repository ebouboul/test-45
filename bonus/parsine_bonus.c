/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:23:05 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/17 22:43:23 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cheker.h"

char	*cont_chekk_pas_string(char *str, int *cheker, int i)
{
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == '+' || str[i] == '-')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (NULL);
			i++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			*cheker = 1;
			i++;
		}
		else
			return (NULL);
	}
	if (*cheker == 0)
		return (NULL);
	return (str);
}
char	*chekk_pas_string(char *str)
{
	int		i;
	int		cheker;
	char	*p;

	cheker = 0;
	p = NULL;
	i = 0;
	if (str == NULL)
		return (NULL);
	p = cont_chekk_pas_string(str, &cheker, i);
	return (p);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	int		a;
	long	n;

	i = 0;
	a = 1;
	n = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			a = a * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	return (n * a);
}

size_t	ft_strlenn(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strjoinn(char const *s1, char const *s2)
{
	char *str;
	size_t total_len;
	size_t i;
	size_t j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((total_len + 2));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	str[j++] = ' ';
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}