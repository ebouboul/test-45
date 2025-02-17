/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:47:02 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/17 04:16:11 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHEKER_H
#define CHEKER_H

# include "get_next_line.h"


#include <stdlib.h>
#include <unistd.h>
#include<stdio.h>

typedef struct s_stack
{
	int value;
	int index;
	struct s_stack *next;

} t_stack;

typedef struct s_var
{
	t_stack *head_stack_a;
	t_stack *head_stack_b;
} t_var;

char *strjondata(int ac, char **av);
int	*conerty_data_integer(char *data, int *number, int i);
int chek_double(int *maxxx ,int max_number);
int sort_number(int *stok_maxxx, int size);
void free_list(t_stack *str);

int ft_trove(char const *str, char c);
void ft_free(char **p);
char **copieword(char **p, const char *s, char c);
char **ft_split(char const *s, char c);
size_t ft_strlenn(char **s);
char	*ft_substr(char const *s, unsigned int start, size_t len);


char * cont_chekk_pas_string(char *str,int *cheker,int i);
char * chekk_pas_string(char *str);
long	ft_atoi(const char *nptr);
char	*ft_strjoinn(char const *s1, char const *s2);

void add_front(t_stack **head, int value);
void push_a_push_b(t_stack ** new ,t_stack **to,char flag);
void ra_and_rb(t_stack **head,char flag);
void rr_ra_rb_meme_temp(t_var *head);
void rrr_rra_rrb_meme_temp(t_var *head);


void rra_rrb(t_stack ** head,char flag);
int	size_list(t_stack *heed);
void	ss(t_var *swapp);
void	swap(t_stack **heed, char flag);
void	add_to_stak(t_stack **head, int value);

#endif