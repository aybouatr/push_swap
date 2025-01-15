/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:28:13 by aybouatr          #+#    #+#             */
/*   Updated: 2025/01/11 13:28:16 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_b(t_stack **head, int is_print)
{
	t_stack	*temp;
	t_stack	*before_last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	if (ft_lstsize(*head) == 2)
	{
		swap_first_last(head);
		if (is_print)
			ft_putstr_fd("sb\n", 1);
		return ;
	}
	temp = *head;
	before_last = *head;
	temp->next->next = NULL;
	swap_first_last(&temp);
	temp->next->next = before_last->next->next;
	*head = temp;
	if (is_print)
		ft_putstr_fd("sb\n", 1);
}
