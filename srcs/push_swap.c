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


void increament_index(int* start,int* end,int size)
{
	if (*end < size)
		*end = *end + 1;
	if (*start < size - 1)
		*start = *start + 1;
}

void	ranking_all_digite(t_stack **head_a, t_stack **head_b)
{
	int	i;
	t_stack* h_b;

	h_b = *head_b;
	i = ft_lstsize(h_b) - 1;
	while (ft_lstsize(h_b))
	{
		if (get_positions_node(h_b, i) == 0)
		{
			push_b(head_a, &h_b, 1);
			if (i > 0)
				i--;
		}
		else if (0)
			swap_b(&h_b, 1);
		else if (get_positions_node(h_b, i) < ft_lstsize(h_b) / 2)
			rotate_rb(&h_b, 1);
		else if (get_positions_node(h_b, i) >= ft_lstsize(h_b) / 2)
			rev_rotate_rrb(&h_b, 1);
	}
}

void small_algo(t_stack *head_a, t_stack *head_b)
{
	int i;

	i = 0;
	while (ft_lstsize(head_a) > 2)
	{
		if (get_positions_node(head_a, i) == 0)
		{
			push_a(&head_a,&head_b, 1);
				i++;
		}
		else if (0)
			swap_a(&head_a, 1);
		else if (get_positions_node(head_a, i) < ft_lstsize(head_a) / 2)
			rotate_ra(&head_a, 1);
		else if (get_positions_node(head_a, i) >= ft_lstsize(head_a) / 2)
			rev_rotate_rra(&head_a, 1);
	}
	if (get_positions_node(head_a, i) == 1)
		swap_a(&head_a, 1);
	while (ft_lstsize(head_b))
		push_b(&head_a, &head_b, 1);
	ft_free_satck(head_a);
	exit(0);
}

void	ranking_all_digite_help(t_stack *head_a, t_stack *head_b,int start,int size)
{
	int end;

	 if (size < 7)
	 	small_algo(head_a, head_b);
	if(size < 100 && size >= 7)
		end = size/7;
	else if (size >= 100)
		end = size/12;
	while (ft_lstsize(head_a))
	{
		if(head_a->index <= start)
		{
			push_a(&head_a,&head_b,1);
			rotate_rb(&head_b,1);
			increament_index(&start,&end,size);
		}
		else if (head_a->index <= end)
		{
			push_a(&head_a,&head_b,1);
			increament_index(&start,&end,size);
		}
		else
			rotate_ra(&head_a,1);
	}
	ranking_all_digite(&head_a,&head_b);
}

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
	(head_stack_a);
	ascoding_by_index(head_stack_a);
	if (!is_ranking(head_stack_a))
		ranking_all_digite_help(head_stack_a, head_stack_b,0,ft_lstsize(head_stack_a));
	ft_free_satck(head_stack_a);
	return (0);
}