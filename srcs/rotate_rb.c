/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:27:13 by aybouatr          #+#    #+#             */
/*   Updated: 2025/01/11 13:27:15 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_rb(t_stack **head_stack_a, int is_print)
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
			ft_putstr_fd("rb\n", 1);
		return ;
	}
	lst = temp;
	temp = temp->next;
	lst->next = NULL;
	ft_lstadd_back(&temp, lst);
	*head_stack_a = temp;
	if (is_print)
		ft_putstr_fd("rb\n", 1);
}
