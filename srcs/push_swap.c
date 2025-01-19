/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:19:58 by aybouatr          #+#    #+#             */
/*   Updated: 2025/01/07 10:20:02 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// void	ranking_all_digite(t_stack *head_a, t_stack *head_b)
// {
// 	int	i;

// 	i = 0;

// 	while (head_a && ft_lstsize(head_a) > 2 && !is_ranking(head_a))
// 	{
// 		if (get_positions_node(head_a, i) == 0)
// 		{
// 			push_a(&head_a, &head_b, 1);
// 			i++;
// 		}
// 		else if (0)
// 			swap_a(&head_a, 1);
// 		else if (get_positions_node(head_a, i) < ft_lstsize(head_a) / 2)
// 			rotate_ra(&head_a, 1);
// 		else if (get_positions_node(head_a, i) >= ft_lstsize(head_a) / 2)
// 			rev_rotate_rra(&head_a, 1);
// 	}
// 	if (get_positions_node(head_a, i) == 1)
// 		swap_a(&head_a, 1);
// 	while (ft_lstsize(head_b))
// 		push_b(&head_a, &head_b, 1);
// }

// void	help_rank(t_stack **head_a, t_stack **head_b,int i)
// {
// 	int is_level_two = 0;

// 	while (1)
// 	{	
// 		if (get_positions_node(*head_a, i) == 0)
// 		{
// 			push_a(head_a, head_b, 1);
// 			if ((*head_b)->range == 2)
// 				is_level_two = 2;
// 			break;
// 		}
// 		if (get_positions_node(*head_a, i) < ft_lstsize(*head_a) / 2)
// 			rotate_ra(head_a, 1);
// 		else if (get_positions_node(*head_a, i) >= ft_lstsize(*head_a) / 2)
// 			rev_rotate_rra(head_a, 1);
// 	}
// 	if (is_level_two)
// 		rotate_rb(head_b, 1);
	
// }

// void level_determination(t_stack *head,int first_level)
// {
    
//     while (head != NULL)
//     {
//         if (head->index >= 0 && head->index < first_level)
//             head->range = 1;
//         else if (head->index >= first_level && head->index < (first_level * 2))
//             head->range = 2;
//         else
//             head->range = 3;
        
//         head = head->next;
//     }
// }

// int	get_positions_node(t_stack *head, int index)
// {
// 	int	pos;

// 	pos = 0;
// 	while (head->next != NULL)
// 	{
// 		if (head->index == index)
// 			return (pos);
// 		pos++;
// 		head = head->next;
// 	}
// 	return (pos);
// }

// int get_index_near_help(t_stack* head_a,int level_two,int level_three)
// {
//    int index_two;
//     int index_three;
//     int size;

//     size = ft_lstsize(head_a);
//     index_two = get_positions_node(head_a,level_two);
//     index_three = get_positions_node(head_a,level_three);
//     if (index_two < size/2 && index_three > size/2)
//     {
//         if ((size - index_three) >= index_two)
//             return (level_two);
//         else
//             return (level_three);

//     }
//     else
//     {
//         if ((size - index_two) >= index_three)
//             return (level_three);
//         else
//             return (level_two);  
//     }
//     return (-1);
// }

// int get_index_near(t_stack* head_a,int level_two,int level_three)
// {
//     int index_two;
//     int index_three;
//     int size;

//     size = ft_lstsize(head_a);
//     index_two = get_positions_node(head_a,level_two);
//     index_three = get_positions_node(head_a,level_three);
//     if (index_two > size/2 && index_three > size/2)
//     {
//         if (index_three > index_two)
//             return (level_three);
//         else
//             return (level_two);
//     }
//     else if (index_two < size/2 && index_three < size/2)
//     {
//         if (index_three > index_two)
//             return (level_two);
//         else
//             return (level_three);
//     }
//     else
//         return (get_index_near_help(head_a,level_two,level_three));
//     return (-1);
// }
//----------------------------------------------------------------------------------
//New algo Turk algorithem 
//

int	is_ranking(t_stack *head)
{
	int	i;

	i = head->index;
	while (head != NULL)
	{
		if (head->index != i)
			return (0);
		head = head->next;
		i++;
	}
	return (1);
}

int	get_positions_node(t_stack *head, int index)
{
	int	pos;

	pos = 0;
	while (head->next != NULL)
	{
		if (head->index == index)
			return (pos);
		pos++;
		head = head->next;
	}
	return (888899);
}

int get_index_near_help(t_stack* head_a,int level_two,int level_three)
{
   int index_two;
    int index_three;
    int size;

    size = ft_lstsize(head_a);
    index_two = get_positions_node(head_a,level_two);
    index_three = get_positions_node(head_a,level_three);
    if (index_two < size/2 && index_three > size/2)
    {
        if ((size - index_three) >= index_two)
            return (level_two);
        else
            return (level_three);

    }
    else
    {
        if ((size - index_two) >= index_three)
            return (level_three);
        else
            return (level_two);  
    }
    return (-1);
}

int get_index_near(t_stack* head_a,int level_two,int level_three)
{
    int index_two;
    int index_three;
    int size;

    size = ft_lstsize(head_a);
    index_two = get_positions_node(head_a,level_two);
    index_three = get_positions_node(head_a,level_three);
    if (index_two > size/2 && index_three > size/2)
    {
        if (index_three > index_two)
            return (level_three);
        else
            return (level_two);
    }
    else if (index_two <= size/2 && index_three <= size/2)
    {
        if (index_three > index_two)
            return (level_two);
        else
            return (level_three);
    }
    else
        return (get_index_near_help(head_a,level_two,level_three));
    return (-1);
}

void	help_rank(t_stack **head_a, t_stack **head_b,int i,int is_level_two)
{
	int kk = 0;
	t_stack* h_a;
	t_stack* h_b;

	h_a = *head_a;
	h_b = *head_b;
	while (1)
	{	
		if (get_positions_node(h_a, i) == 0)
		{
			push_a(&h_a, &h_b, 1);
			break;
		}
		if (get_positions_node(h_a, i) < ft_lstsize(h_a) / 2)
			rotate_ra(&h_a, 1);
		else if (get_positions_node(h_a, i) >= ft_lstsize(h_a) / 2)
			rev_rotate_rra(&h_a, 1);
		//printf("help rank\n");
		
	}
	if (is_level_two)
		rotate_rb(&h_b,1);
	*head_a = h_a;
	*head_b = h_b;
}

void recieve_all_date_to_stack_a(t_stack* head_a,t_stack* head_b)
{
	int i;
	int size;

	i = 3;
	size = ft_lstsize(head_b);
	while(ft_lstsize(head_b))
	{
		if (3 == head_b->range)
			push_b(&head_a,&head_b,1);
		else if (2 == head_b->range)
			push_b(&head_a,&head_b,1);
		else if (1 == head_b->range && ft_lstsize(head_b) > (size/3))
			rev_rotate_rrb(&head_b,1);
		else if (1 == head_b->range)
			push_b(&head_a,&head_b,1);
	}
	
}
	

void	ranking_all_digite(t_stack *head_a, t_stack *head_b)
{
	int i;
	int j;
	int size;
	int e;
	int stop = 0;

	size = ft_lstsize(head_a) ;
	j = (size/2);
	i = (size/2) + 1;
	while (ft_lstsize(head_a) > 1)
	{

			if (j != -1 && i != size)
				e = get_index_near(head_a,i,j);
			if ((e == i && i < size) || !( j >= 0))
			{
				help_rank(&head_a,&head_b,i,0);
				i++;
			}
			else if(( j >= 0) || !(e == i && i < size))
			{
				help_rank(&head_a,&head_b,j,1);
				j--;
			}
			
	}
	if (head_a->index == 0)
	{
		push_a(&head_a,&head_b,1);
		rotate_rb(&head_b,1);
	}
	else
		push_a(&head_a,&head_b,1);
	while (ft_lstsize(head_b))
		push_b(&head_a,&head_b,1);
	
}

//-----------------------------------------------------------------------
// void	ranking_all_digite(t_stack *head_a, t_stack *head_b)
// {
// 	int	i;

// 		i = 0;
// 		while (head_a && ft_lstsize(head_a) > 2 && !is_ranking(head_a))
// 		{
// 			if (get_positions_node(head_a, i) == 0)
// 			{
// 				push_a(&head_a, &head_b, 1);
// 				i++;
// 			}
// 			else if (get_positions_node(head_a, i) == 1)
// 				swap_a(&head_a, 1);
// 			else if (get_positions_node(head_a, i) < ft_lstsize(head_a) / 2)
// 				rotate_ra(&head_a, 1);
// 			else if (get_positions_node(head_a, i) >= ft_lstsize(head_a) / 2)
// 				rev_rotate_rra(&head_a, 1);
// 		}
// 		if (get_positions_node(head_a, i) == 1)
// 			swap_a(&head_a, 1);
// 		while (ft_lstsize(head_b))
// 			push_b(&head_a, &head_b, 1);
// }

int	main(int ac, char **av)
{
	int		i;
	t_stack	*head_stack_a;
	t_stack	*head_stack_b;

	i = 0;
	head_stack_a = NULL;
	head_stack_b = NULL;
	check_error(av, ac);
	full_stack(ac, av, &head_stack_a);
	is_there_repetition(head_stack_a);
	ascoding_by_index(head_stack_a);
	if (!is_ranking(head_stack_a))
		ranking_all_digite(head_stack_a, head_stack_b);
	ft_free_satck(head_stack_a);
}