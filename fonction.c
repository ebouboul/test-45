/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:45:00 by ahmed             #+#    #+#             */
/*   Updated: 2025/02/16 02:50:52 by ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"head.h"

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

int sort_number(int *stok_maxxx, int size)
{
    int i = 0;

    while (i < size -1) 
    {
        if (stok_maxxx[i] > stok_maxxx[i + 1]) 
            return (0); 
        i++;
    }
    return (1); 
}


void add_to_array(int max[],int max_number)
{
    int i;
    int h;
    int p;
    
    i=0;
    while(i < max_number)
        {
            h=1+i;
            while (h < max_number)
            {
                if(max[i] > max[h])
                {                  
                    p = max[h];
                    max[h] = max[i];
                    max[i] = p;
                }
                h++;
            }
            i++;
        }
}

void add_les_index(int max[],int max_number,t_var var)
{
    t_stack *p;
    p = var.head_stack_a;
    int i;
    
    while(p)
        {
            i=0;
            while(i < max_number)
            {
                
                if(max[i]==p->value)
                    {
                    p->index=i;
                    }
            i++;
            }   
            p=p->next;
        }
}

int position(t_stack *temp,int value)
{
    int  i;
    i = 1;
    while(temp)
    {
        if(temp->value == value)
            return i;
        i++;
        temp = temp->next;
    }
    return(i);
}
