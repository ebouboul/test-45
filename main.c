/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmed <ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:32:52 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/16 03:00:24 by ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"






int main(int ac ,char **av)
{   
    int i =1;
    
    t_var var;
    // var.head_stack_a=NULL;
    // var.head_stack_b=NULL; 
    
    char *data;
    int max_number;
    int *stok_maxxx;
    
    if(ac == 1)
        return 0;
    data = strjondata(ac,av);
    i=0;
    stok_maxxx = conerty_data_integer(data, &max_number,i);
    if (!data)
        return (free(stok_maxxx),free(data), 1);
   if(sort_number(stok_maxxx,max_number) == 1 ||     chek_double(stok_maxxx,max_number) == 1)
        return (free(stok_maxxx), free(data), 0);
    else
    {
        i=0;
        int index =0;
        
        int max[max_number];
        while (i < max_number)
        {
            add_to_stak(&var.head_stack_a,stok_maxxx[i]);
            max[index++]=stok_maxxx[i++];  
        }
        add_to_array(max,max_number);
        add_les_index(max,max_number,var);
   
        if(size_list(var.head_stack_a)== 2)
            swap(&var.head_stack_a,'a');
        if(size_list(var.head_stack_a)== 3 )        
            algo_troi_nombre(&var);
         if(size_list(var.head_stack_a)== 4 )
            algo_quatre_nombre(&var);
        if(size_list(var.head_stack_a)== 5 )
            algo_Cinquieme_nombre(&var);
        if(size_list(var.head_stack_a)>=6 && size_list(var.head_stack_a)<= 499)
        {
                Push_stack_algo(&var,15);
                pushyyy(&var);
        }
        if(size_list(var.head_stack_a)>=500)
        {
                Push_stack_algo(&var,30);
                pushyyy(&var);
        }
    }
    free_list(var.head_stack_a);
   free(data);
   free(stok_maxxx);
    
}
