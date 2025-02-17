/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:45:56 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/17 06:19:34 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cheker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	implimnt_cmd(char *output, t_stack **stack_a, t_stack **stack_b, t_var *var)
{
	if (ft_strcmp(output, "sa\n") == 0)
		swap(stack_a, 'p');
	else if (ft_strcmp(output, "sb\n") == 0)
		swap(stack_b, 'p');
	else if (ft_strcmp(output, "ss\n") == 0)
		ss(var);
	else if (ft_strcmp(output, "ra\n") == 0)
		ra_and_rb(stack_a, 'p');
	else if (ft_strcmp(output, "rb\n") == 0)
		ra_and_rb(stack_b, 'p');
	else if (ft_strcmp(output, "rr\n") == 0)
		rr_ra_rb_meme_temp(var);
	else if (ft_strcmp(output, "rra\n") == 0)
		rra_rrb(stack_a, 'p');
	else if (ft_strcmp(output, "rrb\n") == 0)
		rra_rrb(stack_b, 'p');
	else if (ft_strcmp(output, "rrr\n") == 0)
		rrr_rra_rrb_meme_temp(var);
	else if (ft_strcmp(output, "pa\n") == 0)
		push_a_push_b(stack_b, stack_a, 'p');
	else if (ft_strcmp(output, "pb\n") == 0)
		push_a_push_b(stack_a, stack_b, 'p');
	else
		return (0);
	return (1);
}

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

void *test(t_var *var,int max_number , int	*stok_maxxx)
{
    int i;
    char	*moovm;
    int		max[max_number];
    
    i=0;
    while (i < max_number)
	{
		add_to_stak(&var->head_stack_a, stok_maxxx[i]);
		max[i] = stok_maxxx[i];
        i++;
	}
	moovm = get_next_line(0);
	while (moovm)
	{
		if (implimnt_cmd(moovm, &var->head_stack_a, &var->head_stack_b,var) == 0)
		{
			write(2, "Error\n", 6);
            free(moovm);
			return (NULL);
		}
		free(moovm);
		moovm = get_next_line(0);
	}
}
int	main(int ac, char **av)
{
	int		i;
	t_var	var;
	char	*data;
	int		*stok_maxxx;

	int		max_number;

	var.head_stack_a = NULL;
	var.head_stack_b = NULL;
	if (ac == 1)
		return (0);
	data = strjondata(ac, av);
	if (!data)
		return (1);
	i = 0;
	stok_maxxx = conerty_data_integer(data, &max_number, i);
	if (chek_double(stok_maxxx, max_number) == 1 || sort_number(stok_maxxx,max_number) == 1)
		return (free(stok_maxxx), free(data), 0);

    test(&var,max_number,stok_maxxx);
	ft_valid(var.head_stack_a, var.head_stack_b);
    
	free_list(var.head_stack_a);
	free(data);
	free(stok_maxxx);
}
