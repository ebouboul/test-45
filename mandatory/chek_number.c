/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:53:12 by ahmed             #+#    #+#             */
/*   Updated: 2025/02/18 05:13:41 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	find_index(t_stack *a, int x, int p)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index <= x || a->index <= x + p)
			break ;
		i++;
		a = a->next;
	}
	return (i);
}

int	trouve_ground_number(t_stack *stack)
{
	int	highest;

	highest = stack->value;
	while (stack)
	{
		if (highest < stack->value)
			highest = stack->value;
		stack = stack->next;
	}
	return (highest);
}

int	trouve_min_number(t_stack *stack)
{
	int	highest;

	highest = stack->value;
	while (stack)
	{
		if (highest > stack->value)
			highest = stack->value;
		stack = stack->next;
	}
	return (highest);
}

void	free_list(t_stack *str)
{
	t_stack	*temp;

	while (str != NULL)
	{
		temp = str;
		str = str->next;
		free(temp);
	}
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
				write(2, "Eroor!\n", 7);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
