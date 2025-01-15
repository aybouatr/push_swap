#include "../includes/push_swap.h"

t_stack	*ft_lstnew(int cont)
{
	t_stack	*node;
	int		*content;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	content = malloc(sizeof(int));
	if (!content)
		return (NULL);
	*content = cont;
	node->data = content;
	node->next = NULL;
	node->index = -1;
	return (node);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_free(char **arr)
{
	int i;

	i = 0;
	while (arr != NULL && arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
}