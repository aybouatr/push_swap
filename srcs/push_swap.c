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

void	ranking_all_digite(t_stack *head_a, t_stack *head_b)
{
	int	i;

	i = 0;
	while (head_a && ft_lstsize(head_a) > 2 && !is_ranking(head_a))
	{
		if (get_positions_node(head_a, i) == 0)
		{
			push_a(&head_a, &head_b, 1);
			i++;
		}
		else if (get_positions_node(head_a, i) == 1)
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
	is_there_repetition(head_stack_a);
	ascoding_by_index(head_stack_a);
	if (!is_ranking(head_stack_a))
		ranking_all_digite(head_stack_a, head_stack_b);
	ft_free_satck(head_stack_a);
}
