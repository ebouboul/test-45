/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:10:58 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/18 05:38:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cheker.h"

void	add_to_stak(t_stack **head, int value)
{
	t_stack	*noud;
	t_stack	*contor;

	contor = *head;
	noud = (t_stack *)malloc(sizeof(t_stack));
	if (!noud)
		return ;
	noud->value = value;
	noud->next = NULL;
	if (!noud)
		return ;
	if (*head == NULL)
		*head = noud;
	else
	{
		while (contor->next != NULL)
			contor = contor->next;
		contor->next = noud;
	}
}

void	swap(t_stack **heed, char flag)
{
	t_stack	*tmp;
	int		size;

	size = size_list(*heed);
	if (*heed == NULL || size < 2)
		return ;
	tmp = (*heed);
	(*heed) = (*heed)->next;
	tmp->next = (*heed)->next;
	(*heed)->next = tmp;
	if (flag == 'a')
		write(1, "sa\n", 3);
	else if (flag == 'b')
		write(1, "sb\n", 3);
}

void	ss(t_var *swapp)
{

		swap(&swapp->head_stack_a, 's');
		swap(&swapp->head_stack_b, 's');
		write(1, "ss\n", 3);
}

int	size_list(t_stack *heed)
{
	t_stack	*head;
	int		result;

	head = heed;
	result = 0;
	if (!head)
		return (0);
	while (head != NULL)
	{
		result++;
		head = head->next;
	}
	return (result);
}

void	rra_rrb(t_stack **head, char flag)
{
	t_stack	*con;
	t_stack	*temp;
	int		size;

	con = *head;
	temp = *head;
	size = size_list(*head);
	if (*head == NULL || size < 2)
		return ;
	while (con->next->next != NULL)
		con = con->next;
	temp = con->next;
	con->next = NULL;
	temp->next = *head;
	*head = temp;
	if (flag == 'a')
		write(1, "rra\n", 4);
	else if (flag == 'b')
		write(1, "rrb\n", 4);
}
