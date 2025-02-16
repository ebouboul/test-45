/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:55:34 by ahmed             #+#    #+#             */
/*   Updated: 2025/02/16 02:56:02 by ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void Push_stack_algo(t_var *var, int range)
{
    int i; 
    // int size;
    
    i = 0;
    // size = size_list(var->head_stack_a);
    while (var->head_stack_a)
    {
        if (var->head_stack_a->index <= i)
        {
            push_a_push_b(&var->head_stack_a, &var->head_stack_b, 'b');
            ra_and_rb(&var->head_stack_b, 'b');
            i++;
        }
        else if (var->head_stack_a->index <= i + range)
        {
            push_a_push_b(&var->head_stack_a, &var->head_stack_b, 'b');
            i++;
        }
        else if (find_index(var->head_stack_a, i, range) <= size_list(var->head_stack_a) / 2)
            ra_and_rb(&var->head_stack_a, 'a');
        else
            rra_rrb(&var->head_stack_a, 'a');
    }
}



void pushyyy(t_var *var)
{
    int biger;
     while(var->head_stack_b)
        {
                
            biger = trouve_ground_number(var->head_stack_b);
            while (var->head_stack_b->value != biger)
            {
                        
                if(position(var->head_stack_b, biger) <= size_list(var->head_stack_b)/2 
                        /*&& biger != var->head_stack_b->value*/ )
                {
                   
                        ra_and_rb(&var->head_stack_b,'b');
                }
                else
                {
                        rra_rrb(&var->head_stack_b,'b');
                }
            }
              push_a_push_b(&var->head_stack_b,&var->head_stack_a,'a'); 
        }
}
