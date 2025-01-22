/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:19:06 by aybouatr          #+#    #+#             */
/*   Updated: 2025/01/13 18:19:12 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_len(const char *str)
{
	size_t	e;

	e = 0;
	while (str[e])
		e++;
	return (e);
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (-1);
	while ((i < len) && (s1[i]) && (s1[i] == s2[i]))
		i++;
	if (i == len)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	make_instructions(t_stack **head_a, t_stack **head_b, char *buffer,
		int *check)
{
	if (ft_strncmp(buffer, "sa\n", ft_len(buffer)) == 0 && ft_len(buffer))
		swap_a(head_a, 0);
	else if (ft_strncmp(buffer, "sb\n", ft_len(buffer)) == 0 && ft_len(buffer))
		swap_b(head_b, 0);
	else if (ft_strncmp(buffer, "ss\n", ft_len(buffer)) == 0 && ft_len(buffer))
		swap_ss(head_a, head_b, 0);
	else if (ft_strncmp(buffer, "pb\n", ft_len(buffer)) == 0 && ft_len(buffer))
		push_a(head_a, head_b, 0);
	else if (ft_strncmp(buffer, "pa\n", ft_len(buffer)) == 0 && ft_len(buffer))
		push_b(head_a, head_b, 0);
	else if (ft_strncmp(buffer, "ra\n", ft_len(buffer)) == 0 && ft_len(buffer))
		rotate_ra(head_a, 0);
	else if (ft_strncmp(buffer, "rb\n", ft_len(buffer)) == 0 && ft_len(buffer))
		rotate_rb(head_b, 0);
	else if (ft_strncmp(buffer, "rr\n", ft_len(buffer)) == 0 && ft_len(buffer))
		rotate_rr(head_a, head_b, 0);
	else if (ft_strncmp(buffer, "rra\n", ft_len(buffer)) == 0 && ft_len(buffer))
		rev_rotate_rra(head_a, 0);
	else if (ft_strncmp(buffer, "rrb\n", ft_len(buffer)) == 0 && ft_len(buffer))
		rev_rotate_rrb(head_b, 0);
	else if (ft_strncmp(buffer, "rrr\n", ft_len(buffer)) == 0 && ft_len(buffer))
		rev_rotate_rrr(head_a, head_b, 0);
	else if (buffer[0] != '\0')
		*check = 1;
}

void	read_instructions(t_stack *head_a, t_stack *head_b)
{
	char	buffer[100];
	ssize_t	len_read;
	int		check;

	len_read = 1;
	check = 0;
	while (len_read)
	{
		len_read = read(0, buffer, 99);
		buffer[len_read] = '\0';
		make_instructions(&head_a, &head_b, buffer, &check);
		if (check)
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_satck(head_a);
			ft_free_satck(head_b);
			exit(1);
		}
	}
	is_there_repetition(head_a);
	if (is_ranking(head_a) && ft_lstsize(head_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_satck(head_a);
	ft_free_satck(head_b);
}

int	main(int ac, char **av)
{
	t_stack		*head_stack_a;
	t_stack		*head_stack_b;

	head_stack_a = NULL;
	head_stack_b = NULL;
	check_error(av, ac);
	full_stack(ac, av, &head_stack_a);
	ascoding_by_index(head_stack_a);
	read_instructions(head_stack_a, head_stack_b);
}
