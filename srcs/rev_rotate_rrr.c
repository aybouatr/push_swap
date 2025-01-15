/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:26:36 by aybouatr          #+#    #+#             */
/*   Updated: 2025/01/11 13:26:38 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_rotate_rrr(t_stack **head_stack_a, t_stack **head_stack_b,
		int is_print)
{
	rev_rotate_rra(head_stack_a, 0);
	rev_rotate_rrb(head_stack_b, 0);
	if (is_print)
		ft_putstr_fd("rrr\n", 1);
}
