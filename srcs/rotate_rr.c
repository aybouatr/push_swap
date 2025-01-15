/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:27:25 by aybouatr          #+#    #+#             */
/*   Updated: 2025/01/11 13:27:27 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_rr(t_stack **head_stack_a, t_stack **head_stack_b, int is_print)
{
	rotate_ra(head_stack_a, 0);
	rotate_rb(head_stack_b, 0);
	if (is_print)
		ft_putstr_fd("rr\n", 1);
}
