/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lesregles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:22:00 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/14 06:45:30 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void add_front(t_stack **head, int value)
{
    t_stack *noud;
    noud =(t_stack*)malloc(sizeof(t_stack));
    if(!noud)
        return ;
    noud->value = value;
    noud->next  = NULL;
    if(*head == NULL)
        *head = noud;
    else
    {
        noud->next =*head;
        *head = noud;     
    }
}
void push_a_push_b(t_stack ** new ,t_stack **to,char flag)
{ 
    t_stack * noud;
    int value;
    int size ;
    size = size_list(*new);
        if(size < 1)
             return ;
    noud = *new;
    value = noud->value;
    *new = noud->next;
    free(noud);
    add_front(to,value);
    if (flag == 'a')
		write(1, "pa\n", 3);
	else if (flag == 'b')
		write(1, "pb\n", 3);
}

void ra_and_rb(t_stack **head,char flag)
{
    t_stack *temp;
    t_stack *poin;
    temp = *head;
    poin = *head;
    int size;
    size =size_list(*head);
    if(*head ==NULL || size < 2)
        return ;
        
     *head =(*head)->next;
   
    while (temp->next != NULL)
            temp =temp->next;
    temp->next = poin;
    poin ->next = NULL;
     if (flag == 'a')
		write(1, "ra\n", 3);
	else if (flag == 'b')
		write(1, "rb\n", 3);

}

void rr_ra_rb_meme_temp(t_var *head)
{
    if (head->head_stack_a == NULL ||head->head_stack_b==NULL)
        return ;
    else
    {
    ra_and_rb(&head->head_stack_a,'s');
    ra_and_rb(&head->head_stack_b,'s');
    write(1,"rr\n",3);
    }

}





void rra_rrb(t_stack ** head,char flag)
{
    t_stack *con;
    t_stack *temp;
    con = *head;
    temp =*head;
    int size;
    size =size_list(*head);
    if(*head ==NULL || size < 2)
        return ;
    while(con->next->next !=NULL)
        con=con->next;
    temp= con->next;
    con->next=NULL;
    temp->next=*head;
    *head=temp;
     if (flag == 'a')
		write(1, "rra\n", 4);
	else if (flag == 'b')
		write(1, "rrb\n", 4);
}

void rrr_rra_rrb_meme_temp(t_var *head)
{
    if(head->head_stack_a == NULL || head ->head_stack_b == NULL)
        return ;
    else
    {
        rra_rrb(&head->head_stack_a,'s');
        rra_rrb(&head->head_stack_b,'s');
        write(1, "rrr\n", 4);
    }
}