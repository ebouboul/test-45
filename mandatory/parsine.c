/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:48:33 by ahmed             #+#    #+#             */
/*   Updated: 2025/02/18 05:27:56 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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

char	*strjondata(int ac, char **av)
{
	int		i;
	char	*p;
	char	*data;
	char	*tem;

	i = 1;
	data = NULL;
	while (i < ac)
	{
		p = chekk_pas_string(av[i]);
		if (p == NULL || av[i][0] == '\0')
		{
			write(1, "Eroor!\n", 7);
			free(data);
			return (NULL);
		}
		else
		{
			tem = data;
			data = ft_strjoin(data, p);
			free(tem);
		}
		i++;
	}
	return (data);
}

void	contuni_conerty_data_integer(int number, int *maxxx, char **split,
		char *data)
{
	int		i;
	long	cheker;
	int		size_number;

	i = 0;
	while (i < number)
	{
		size_number = ft_strlen(split[i]);
		cheker = ft_atoi(split[i]);
		if (size_number > 11 || cheker > 2147483647 || cheker < -2147483648)
		{
			write(2, "Eroor!\n", 7);
			free(maxxx);
			free(data);
			ft_free(split);
			exit(1);
		}
		maxxx[i] = cheker;
		i++;
	}
}

int	*conerty_data_integer(char *data, int *number)
{
	char	**split;
	int		*maxxx;

	split = ft_split(data, ' ');
	*number = ft_strlenn(split);
	maxxx = malloc((*number) * sizeof(int));
	if (!maxxx)
		exit(1);
	contuni_conerty_data_integer(*number, maxxx, split, data);
	ft_free(split);
	return (maxxx);
}
