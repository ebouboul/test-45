/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:32:52 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/18 05:28:14 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int     *get_max(int max_number)
{
    int *max;

    max = malloc(max_number * sizeof(int));
    if (!max)
        return (NULL);
    return (max);    
}

void	implementation(t_var *var, int max_number, int *stok_maxxx)
{
	int	i;
	int	*max;

	i = 0;
    max = get_max(max_number);
    if(!max)
        exit(1);
	while (i < max_number)
	{
		add_to_stak(&var->head_stack_a, stok_maxxx[i]);
		max[i] = stok_maxxx[i];
		i++;
	}
	add_to_array(max, max_number);
	add_les_index(max, max_number, var);
	if (size_list(var->head_stack_a) == 2)
		swap(&var->head_stack_a, 'a');
	if (size_list(var->head_stack_a) == 3)
		algo_troi_nombre(var);
	if (size_list(var->head_stack_a) == 4)
		algo_quatre_nombre(var);
	if (size_list(var->head_stack_a) == 5)
		algo_cinquieme_nombre(var);
    free(max);
	contuni_implementation(var);
}

void	contuni_implementation(t_var *var)
{
	if (size_list(var->head_stack_a) >= 6
		&& size_list(var->head_stack_a) <= 499)
	{
		push_stack_algo(var, 15);
		pushyyy(var);
	}
	if (size_list(var->head_stack_a) >= 500)
	{
		push_stack_algo(var, 30);
		pushyyy(var);
	}
}

int	main(int ac, char **av)
{
	t_var	var;
	char	*data;
	int		max_number;
	int		*stok_maxxx;

	var.head_stack_a = NULL;
	var.head_stack_b = NULL;
	if (ac == 1)
		return (0);
	data = strjondata(ac, av);
	if (!data)
		return (1);
	stok_maxxx = conerty_data_integer(data, &max_number);
	if (chek_double(stok_maxxx, max_number) == 1 || sort_number(stok_maxxx,
			max_number) == 1)
		return (free(stok_maxxx), free(data), 0);
	else
		implementation(&var, max_number, stok_maxxx);
	free_list(var.head_stack_a);
	free(data);
	free(stok_maxxx);
}
