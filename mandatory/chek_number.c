/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:53:12 by ahmed             #+#    #+#             */
/*   Updated: 2025/02/16 02:54:30 by ahmed            ###   ########.fr       */
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
int  trouve_ground_number(t_stack *stack)
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

 int  trouve_min_number(t_stack *stack)
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

void free_list(t_stack *str)
{   

    while(str != NULL )
    {
        t_stack *temp= str;
        str = str->next;
        free(temp);
    }
}