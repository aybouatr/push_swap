/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:28:42 by aybouatr          #+#    #+#             */
/*   Updated: 2025/01/07 12:28:45 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}

int	is_found_alph(char *str)
{
	int		i;
	char	sign;

	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] == '-')
			i++;
		if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
			return (1);
		while (str[i] && (str[i] >= '0' && str[i] <= '9'))
			i++;
		if (str[i] != '\0' && !(str[i] == ' ' || str[i] == '\t'))
			return (1);
	}
	return (0);
}

int	check_error(char **av, int ac)
{
	int	i;

	i = 1;
	if (ac == 1)
		exit(0);
	while (i < ac)
	{
		if (av[i][0] == '\0' || is_found_alph(av[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		i++;
	}
}

void	full_stack(int ac, char **av, t_stack **heade)
{
	char	**arr;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		arr = ft_split(av[i], ' ');
		j = 0;
		while (arr && arr[j])
		{
			ft_lstadd_back(heade, ft_lstnew(ft_atoi(arr[j])));
			j++;
		}
		if (*arr == NULL)
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_satck(*heade);
			exit(1);
		}
		ft_free(arr);
		i++;
	}
}

void	ft_free_satck(t_stack *head)
{
	t_stack	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;  
		free(temp->data);
		free(temp);         
	}
}
