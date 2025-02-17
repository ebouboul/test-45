/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:09:18 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/18 00:11:42 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cheker.h"

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
			data = ft_strjoinn(data, p);
			free(tem);
		}
		i++;
	}
	return (data);
}
void contuni_conerty_data_integer(int number,int i,int*maxxx,char **split,char *data)
{
    long	cheker;
    int size_number;
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
			exit(0);
		}
		maxxx[i] = cheker;
		i++;
	}  
}
int	*conerty_data_integer(char *data, int *number, int i)
{
	char	**split;
	int		*maxxx;


	split = ft_split(data, ' ');
	*number = ft_strlenn(split);
	maxxx = malloc((*number) * sizeof(int));
	if (!maxxx)
		exit(0);
    contuni_conerty_data_integer(*number,i,maxxx,split,data);
	ft_free(split);
	return (maxxx);
}

int	chek_double(int *maxxx, int max_number)
{
	int	i;
	int	j;

	i = 0;
	while (i < max_number)
	{
		j = i + 1;
		while (j < max_number)
		{
			if (maxxx[i] == maxxx[j])
			{
				write(1, "Eroor!\n", 7);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	sort_number(int *stok_maxxx, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stok_maxxx[i] > stok_maxxx[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	free_list(t_stack *str)
{
	t_stack *temp;

	while (str != NULL)
	{
		temp = str;
		str = str->next;
		free(temp);
	}
}
