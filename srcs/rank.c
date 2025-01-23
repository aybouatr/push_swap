/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:42:41 by aybouatr          #+#    #+#             */
/*   Updated: 2025/01/15 12:42:48 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ascoding_by_index(t_stack *head)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if (head == NULL)
		return ;
	temp1 = head;
	while (temp1 != NULL)
	{
		temp1->index = 0;
		temp2 = head;
		while (temp2 != NULL)
		{
			if (*temp1->data > *temp2->data)
				temp1->index++;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

int	is_ranking(t_stack *head)
{
	int	i;

	if (head)
		i = head->index;
	while (head != NULL)
	{
		if (head->index != i)
			return (0);
		head = head->next;
		i++;
	}
	return (1);
}

long	ft_atoi(char *str)
{
	long	res;
	size_t	i;
	int		sgn;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	sgn = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	res = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sgn);
}

int	get_positions_node(t_stack *head, int index)
{
	int	pos;

	pos = 0;
	while (head->next != NULL)
	{
		if (head->index == index)
			return (pos);
		pos++;
		head = head->next;
	}
	return (pos);
}

void	is_there_repetition(t_stack *head)
{
	t_stack	*temp;
	t_stack	*temp_two;

	temp_two = head;
	while (head != NULL)
	{
		if ((*head->data > 2147483647 || *head->data < -2147483648))
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_satck(temp_two);
			exit(1);
		}
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
			if (*temp->data == *head->data)
			{
				ft_putstr_fd("Error\n", 2);
				ft_free_satck(temp_two);
				exit(1);
			}
		}
		head = head->next;
	}
}
