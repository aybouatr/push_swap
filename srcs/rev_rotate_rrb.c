/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_rrb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:26:13 by aybouatr          #+#    #+#             */
/*   Updated: 2025/01/11 13:26:18 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_rotate_rrb(t_stack **head_stack_a, int is_print)
{
	t_stack	*temp;
	t_stack	*lst;

	temp = *head_stack_a;
	if (!temp || !temp->next)
		return ;
	if (ft_lstsize(temp) == 2)
	{
		swap_first_last(&temp);
		*head_stack_a = temp;
		if (is_print)
			ft_putstr_fd("rrb\n", 1);
		return ;
	}
	while (temp->next->next != NULL)
		temp = temp->next;
	lst = temp->next;
	temp->next = NULL;
	lst->next = *head_stack_a;
	*head_stack_a = lst;
	if (is_print)
		ft_putstr_fd("rrb\n", 1);
}
