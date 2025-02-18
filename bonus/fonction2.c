/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:52:09 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/18 04:38:45 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cheker.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_valid(t_stack *stack_a, t_stack *stack_b)
{
	if (size_list(stack_a) > 0 && is_sorted(stack_a) == 1
		&& size_list(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	affiche_list(t_stack *contor)
{
	if (contor == NULL)
		return ;
	while (contor != NULL)
	{
		contor = contor->next;
	}
}

void	add_to_stackk(t_var *var, int max_number, int *stok_maxxx)
{
	int	i;

	i = 0;
	while (i < max_number)
	{
		add_to_stak(&var->head_stack_a, stok_maxxx[i]);
		i++;
	}
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
