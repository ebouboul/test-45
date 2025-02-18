/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quatre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:57:58 by ahmed             #+#    #+#             */
/*   Updated: 2025/02/18 04:57:17 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	contuni_algo_quatre_nombre(t_var *var, int min)
{
	if (position(var->head_stack_a, min) == 2)
	{
		swap(&var->head_stack_a, 'a');
		push_a_push_b(&var->head_stack_a, &var->head_stack_b, 'b');
	}
	else if (position(var->head_stack_a, min) == 3)
	{
		rra_rrb(&var->head_stack_a, 'a');
		rra_rrb(&var->head_stack_a, 'a');
		push_a_push_b(&var->head_stack_a, &var->head_stack_b, 'b');
	}
	else if (position(var->head_stack_a, min) == 4)
	{
		rra_rrb(&var->head_stack_a, 'a');
		push_a_push_b(&var->head_stack_a, &var->head_stack_b, 'b');
	}
}

void	algo_quatre_nombre(t_var *var)
{
	int	min;

	min = trouve_min_number(var->head_stack_a);
	if (position(var->head_stack_a, min) == 1)
		push_a_push_b(&var->head_stack_a, &var->head_stack_b, 'b');
	else
	{
		contuni_algo_quatre_nombre(var, min);
	}
	algo_troi_nombre(var);
	push_a_push_b(&var->head_stack_b, &var->head_stack_a, 'a');
}
