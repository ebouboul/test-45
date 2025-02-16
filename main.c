/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:32:52 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/16 00:54:55 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"


char * cont_chekk_pas_string(char *str,int *cheker,int i)
{
     while (str[i])
    {
        if (str[i] == ' ')
            i++;
        else if (str[i] == '+' || str[i] == '-' )
        {
            if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
                return (NULL);
            i++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
             {
                *cheker =1; 
                i++;
             }
        else
            return (NULL);
    }
     if (*cheker==0)
         return (NULL);
    return (str);
}
char * chekk_pas_string(char *str)
{
    int i;
    int cheker;
    char *p;
    
    cheker=0;
    p=NULL;
    i = 0;
    
    if (str == NULL)
        return (NULL);
    p = cont_chekk_pas_string(str,&cheker,i);
    return p;
}

char *strjondata(int ac, char **av)
{
    int i ;
    char *p ;
    char *data;
    
    i = 1;
    data = NULL;
     while (i < ac)
    {
        p = chekk_pas_string(av[i]);
        if(p == NULL || av[i][0]=='\0')
            {
            write(1,"Eroor!\n",7);
            free(data);
            return (NULL);
            }
        else
            {
                 char * tem = data;
                 data = ft_strjoin(data,p);
                free(tem);
            }
        i++;
    }
    return (data);
}

int	*conerty_data_integer(char *data, int *number, int i)
{
	char	**split;
	int		size_number;
	int		*maxxx;
	long	cheker;

	split = ft_split(data, ' ');
	*number = ft_strlenn(split);
	maxxx = malloc((*number) * sizeof(int));
	if (!maxxx)
		exit(0);
	while (i < *number)
	{
		size_number = ft_strlen(split[i]);
		cheker = ft_atoi(split[i]);
		if (size_number > 11 || cheker > 2147483647 || cheker < -2147483648)
		{
			write(1, "Eroor!\n", 7);
			ft_free(split);
			exit(0);
		}
		maxxx[i] = cheker;
		i++;
	}
	ft_free(split);
	return (maxxx);
}


int chek_double(int *maxxx ,int max_number)
{
    int i;
    i = 0;
    int j;
    while(i < max_number)
    {
        j = i + 1;
        while(j < max_number)
        {
            if(maxxx[i] == maxxx[j])
            {
                write(1,"Eroor!\n",7);
               return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
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

int	find_index(t_stack *a, int x, int p)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index <= x || a->index <= x + p)
			break ;
		i++;
		a = a->next;
	}
	return (i);
}
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

 int  trouve_ground_number(t_stack *stack)
{
   int	highest;

	highest = stack->value;
	while (stack)
	{
		if (highest < stack->value)
			highest = stack->value;
		stack = stack->next;
	}
	return (highest);
}

 int  trouve_min_number(t_stack *stack)
{
   int	highest;

	highest = stack->value;
	while (stack)
	{
		if (highest > stack->value)
			highest = stack->value;
		stack = stack->next;
	}
	return (highest);
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
void algo_troi_nombre(t_var *var)
{
    int (a),(b),(c);
        
     a = var->head_stack_a->value;
     b = var->head_stack_a->next->value;
     c = var->head_stack_a->next->next->value;
        if (a> b && b>c)
        {
            ra_and_rb(&var->head_stack_a, 'a');
            swap(&var->head_stack_a, 'a');
        }
        if (a > c && c >b )
        {
           rra_rrb(&var->head_stack_a, 'a');
            rra_rrb(&var->head_stack_a, 'a');
        }
        if(b>a && a > c)
            rra_rrb(&var->head_stack_a, 'a');
        if (b >c && c >a )
        {
            rra_rrb(&var->head_stack_a, 'a');
            swap(&var->head_stack_a, 'a');
        }
        if (c > a && a > b) 
            swap(&var->head_stack_a, 'a');
}

// void algo_quatre_nombre(t_var *var)
// {
//             int min;
     
//             min = trouve_min_number(var->head_stack_a);
//             if(position(var->head_stack_a,min)==1)
//                 push_a_push_b(&var->head_stack_a,&var->head_stack_b,'b');
//             else{
//                 if(position(var->head_stack_a,min)==2)
//                 {
//                     swap(&var->head_stack_a,'a');
//                     push_a_push_b(&var->head_stack_a,&var->head_stack_b,'b');
//                 }                
//                 else if(position(var->head_stack_a,min)==3)
//                 {
//                     rra_rrb(&var->head_stack_a,'a');
//                     rra_rrb(&var->head_stack_a,'a');
//                     push_a_push_b(&var->head_stack_a,&var->head_stack_b,'b');
//                 }
//                 else if(position(var->head_stack_a,min)==4)
//                 {
//                 rra_rrb(&var->head_stack_a,'a');
//                 push_a_push_b(&var->head_stack_a,&var->head_stack_b,'b'); 
//                 }
//             }
//              algo_troi_nombre(var);
//              push_a_push_b(&var->head_stack_b,&var->head_stack_a,'a');
// }

void contuni_algo_quatre_nombre(t_var *var, int min)
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

void contuni_algo_Cinquieme_nombre(t_var *var,int min)
{
     if(position(var->head_stack_a,min)==2)
                {
                    swap(&var->head_stack_a,'a');
                    push_a_push_b(&var->head_stack_a,&var->head_stack_b,'b');
                }                

                else if(position(var->head_stack_a,min)==3)
                {
                    rra_rrb(&var->head_stack_a,'a');
                    rra_rrb(&var->head_stack_a,'a');
                    rra_rrb(&var->head_stack_a,'a');
                    push_a_push_b(&var->head_stack_a,&var->head_stack_b,'b');
                }
                else if(position(var->head_stack_a,min)==4)
                {
                rra_rrb(&var->head_stack_a,'a');
                rra_rrb(&var->head_stack_a,'a');
                push_a_push_b(&var->head_stack_a,&var->head_stack_b,'b'); 
                }
                 else if(position(var->head_stack_a,min)==5)
                {
                rra_rrb(&var->head_stack_a,'a');
                push_a_push_b(&var->head_stack_a,&var->head_stack_b,'b'); 
                }
}

void algo_Cinquieme_nombre(t_var *var)
{
    int min;
    
            min = trouve_min_number(var->head_stack_a);
            if(position(var->head_stack_a,min)==1)
                push_a_push_b(&var->head_stack_a,&var->head_stack_b,'b');
            
            else{
               contuni_algo_Cinquieme_nombre(var,min);
            }
             algo_quatre_nombre(var);
             push_a_push_b(&var->head_stack_b,&var->head_stack_a,'a');
}



void free_list(t_stack *str)
{   

    while(str != NULL )
    {
        t_stack *temp= str;
        str = str->next;
        free(temp);
    }
}
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
