/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:38:49 by aybouatr          #+#    #+#             */
/*   Updated: 2025/01/22 09:38:56 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long			*data;
	int				index;
	struct s_stack	*next;

}					t_stack;

void				ft_putstr_fd(char *s, int fd);
int					is_found_alph(char *str);
int					check_error(char **av, int ac);
void				ft_free(char **arr);
t_stack				*ft_lstnew(long cont);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
long				ft_atoi(char *str);
void				full_stack(int ac, char **av, t_stack **heade);
void				is_there_repetition(t_stack *head);
char				**ft_split(char const *str, char c);
void				ft_free_satck(t_stack *head);
int					ft_lstsize(t_stack *lst);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
void				swap_first_last(t_stack **head);
void				swap_a(t_stack **head, int is_print);
void				swap_b(t_stack **head, int is_print);
void				swap_ss(t_stack **head_stack_a, t_stack **head_stack_b,
						int is_print);
void				push_a(t_stack **head_stack_a, t_stack **head_stack_b,
						int is_print);
void				push_b(t_stack **head_stack_a, t_stack **head_stack_b,
						int is_print);
void				rotate_ra(t_stack **head_stack_a, int is_print);
void				rotate_rb(t_stack **head_stack_a, int is_print);
void				rotate_rr(t_stack **head_stack_a, t_stack **head_stack_b,
						int is_print);
void				rev_rotate_rra(t_stack **head_stack_a, int is_print);
void				rev_rotate_rrb(t_stack **head_stack_a, int is_print);
void				rev_rotate_rrr(t_stack **head_stack_a,
						t_stack **head_stack_b, int is_print);
int					get_positions_node(t_stack *head, int index);
void				ranking_all_digite_help(t_stack **head_a, t_stack **head_b);
void				ranking_all_digite(t_stack *head_a, t_stack *head_b,
						int start, int size);
void				increament_index(int *start, int *end, int size);
int					is_ranking(t_stack *head);
void				ascoding_by_index(t_stack *head);

int					read_instructions(t_stack *head_a, t_stack *head_b);
void				make_instructions(t_stack **head_a, t_stack **head_b,
						char *buffer, int *check);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
size_t				ft_len(const char *str);
void				small_algo(t_stack *head_a, t_stack *head_b);

#endif
