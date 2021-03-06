/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swaps_b.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 17:06:26 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 17:06:49 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_stack *a, int rr, t_data *data)
{
	int	temp;
	int	i;

	if (a == NULL || a->next == NULL)
		return ;
	i = 0;
	temp = a->value;
	while (i < data->a_count - 1)
	{
		a->value = a->next->value;
		a = a->next;
		i++;
	}
	a->value = temp;
	if (rr == 0)
		ft_putstr_fd("ra\n", 1);
	return ;
}

void	rb(t_stack *b, int rr, t_data *data)
{
	int	temp;
	int	i;

	if (b == NULL || b->next == NULL || data->b_count == 0)
		return ;
	temp = b->value;
	i = 0;
	while (i < data->b_count - 1)
	{
		b->value = b->next->value;
		b = b->next;
		i++;
	}
	b->value = temp;
	if (rr == 0)
		ft_putstr_fd("rb\n", 1);
	return ;
}

void	rr(t_stack *a, t_stack *b, t_data *data)
{
	ra(a, 1, data);
	rb(b, 1, data);
	if (data->a_count != 0 || data->b_count != 0)
		ft_putstr_fd("rr\n", 1);
	return ;
}
