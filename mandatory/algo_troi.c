/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_troi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:56:52 by ahmed             #+#    #+#             */
/*   Updated: 2025/02/18 04:57:53 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	algo_troi_nombre(t_var *var)
{
	int (a), (b), (c);
	a = var->head_stack_a->value;
	b = var->head_stack_a->next->value;
	c = var->head_stack_a->next->next->value;
	if (a > b && b > c)
	{
		ra_and_rb(&var->head_stack_a, 'a');
		swap(&var->head_stack_a, 'a');
	}
	if (a > c && c > b)
	{
		rra_rrb(&var->head_stack_a, 'a');
		rra_rrb(&var->head_stack_a, 'a');
	}
	if (b > a && a > c)
		rra_rrb(&var->head_stack_a, 'a');
	if (b > c && c > a)
	{
		rra_rrb(&var->head_stack_a, 'a');
		swap(&var->head_stack_a, 'a');
	}
	if (c > a && a > b)
		swap(&var->head_stack_a, 'a');
}
