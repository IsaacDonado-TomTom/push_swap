/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_five.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 17:16:11 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/26 17:17:22 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sub_swap(t_stack *a, t_data *data)
{
	if (a->value > a->next->value && a->next->value \
	< a->next->next->value && a->next->next->value > a->value)
		sa(a);
	else if (a->value > a->next->value && a->next->value \
	> a->next->next->value && a->next->next->value < a->value)
	{
		sa(a);
		rra(a, 0, data);
	}
	else if (a->value > a->next->value && a->next->value \
	< a->next->next->value && a->next->next->value < a->value)
		ra(a, 0, data);
	else if (a->value < a->next->value && a->next->value \
	> a->next->next->value && a->next->next->value > a->value)
	{
		sa(a);
		ra(a, 0, data);
	}
	else if (a->value < a->next->value && a->next->value \
	> a->next->next->value && a->next->next->value < a->value)
		rra(a, 0, data);
}

void	swap_five(t_data *data)
{
	pb(&data->a, &data->b, data);
	pb(&data->a, &data->b, data);
	sub_swap(data->a, data);
	while (data->b != NULL)
	{
		if (is_smallest(data->a, data->b->value, data, "a") == 1)
			pa(&data->a, &data->b, data);
		else if (is_biggest(data->a, data->b->value, data, "a"))
		{
			pa(&data->a, &data->b, data);
			ra(data->a, 0, data);
		}
		else if (data->b->value > data->a->value && \
		data->b->value < data->a->next->value)
		{
			ra(data->a, 0, data);
			pa(&data->a, &data->b, data);
			rra(data->a, 0, data);
		}
		else if (data->b->value > data->a->next->value \
		&& data->b->value < data->a->next->next->value)
		{
			ra(data->a, 0, data);
			ra(data->a, 0, data);
			pa(&data->a, &data->b, data);
			rra(data->a, 0, data);
			rra(data->a, 0, data);
		}
		else if (data->b->value > data->a->next->next->value \
		&& data->b->value < data->a->next->next->next->value)
		{
			rra(data->a, 0, data);
			pa(&data->a, &data->b, data);
			ra(data->a, 0, data);
			ra(data->a, 0, data);
		}
	}
	stackclear(&data->a, data, "a");
	exit (0);
	return ;
}
