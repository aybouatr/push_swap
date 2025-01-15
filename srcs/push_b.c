/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:25:26 by aybouatr          #+#    #+#             */
/*   Updated: 2025/01/11 13:25:29 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b(t_stack **head_stack_a, t_stack **head_stack_b, int is_print)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *head_stack_b;
	if (!temp)
		return ;
	if (ft_lstsize(temp) == 1)
	{
		*head_stack_b = NULL;
		ft_lstadd_front(head_stack_a, temp);
		if (is_print)
			ft_putstr_fd("pa\n", 1);
		return ;
	}
	last = temp;
	temp = temp->next;
	*head_stack_b = temp;
	last->next = NULL;
	ft_lstadd_front(head_stack_a, last);
	if (is_print)
		ft_putstr_fd("pa\n", 1);
}
