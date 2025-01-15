/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_first_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:28:35 by aybouatr          #+#    #+#             */
/*   Updated: 2025/01/11 13:28:38 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_first_last(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	last = (*head)->next;
	first->next = NULL;
	last->next = first;
	*head = last;
}
