/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:28:57 by aybouatr          #+#    #+#             */
/*   Updated: 2025/01/11 13:29:00 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_ss(t_stack **head_stack_a, t_stack **head_stack_b, int is_print)
{
	swap_a(head_stack_a, 0);
	swap_b(head_stack_b, 0);
	if (is_print)
		ft_putstr_fd("ss\n", 1);
}
