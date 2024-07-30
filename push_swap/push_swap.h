/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:09:12 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/30 17:12:35 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					sorted_index;
	int					push_cost;
	int					above_median;
	int					cheapest;

	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;	
}	t_stack_node;

//utils
t_stack_node	*find_last(t_stack_node *stack);
long			ft_atol(char *str);
void			append_node(t_stack_node **stack, int n);
int				stack_len(t_stack_node *stack);

//utils2
int				stack_sorted(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
void			current_index(t_stack_node **stack);

//utils3
t_stack_node	*find_cheapest(t_stack_node *stack);
void			bring_min_top(t_stack_node **stack);
void			bring_node_to_top(t_stack_node **stack, t_stack_node *top_node,
					char stack_name);
void			free_stack(t_stack_node **stack);
void			free_array(char **argv);

//sort100utils
void			move_a_to_b_100(t_stack_node **a, t_stack_node **b);
void			move_b_to_a_100(t_stack_node **a, t_stack_node **b);
void			rotate_both_100(t_stack_node **stack_a, t_stack_node **stack_b,
					t_stack_node *cheapest_node);
void			rev_rotate_both_100(t_stack_node **stack_a,
					t_stack_node **stack_b, t_stack_node *cheapest_node);

//sort500utils
void			rotate_both_500(t_stack_node **stack_a, t_stack_node **stack_b,
					t_stack_node *cheapest_node);
void			rev_rotate_both_500(t_stack_node **stack_a,
					t_stack_node **stack_b, t_stack_node *cheapest_node);
void			move_a_to_b_500(t_stack_node **a, t_stack_node **b);
void			move_b_to_a_500(t_stack_node **a, t_stack_node **b);

//costs
void			set_target_a(t_stack_node *a, t_stack_node *b);
void			push_costs_b(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *stack);
void			set_target_b(t_stack_node *a, t_stack_node *b);
void			push_costs_a(t_stack_node *a, t_stack_node *b);

//s_index
void			init_sorted_index(t_stack_node **stack);

//inits
void			init_stack_a(t_stack_node **a, char **argv);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);

//instructions

void			ra(t_stack_node **a, int print);
void			rb(t_stack_node **b, int print);
void			rr(t_stack_node **a, t_stack_node **b, int print);

void			rra(t_stack_node **a, int print);
void			rrb(t_stack_node **b, int print);
void			rrr(t_stack_node **a, t_stack_node **b, int print);

void			sa(t_stack_node **a, int print);
void			sb(t_stack_node **b, int print);
void			ss(t_stack_node **a, t_stack_node**b, int print);

void			pa(t_stack_node **a, t_stack_node **b, int print);
void			pb(t_stack_node **a, t_stack_node **b, int print);

//sorts
void			sort_three(t_stack_node **stack);
void			sort_stacks_500(t_stack_node **a, t_stack_node **b);
void			sort_stacks_100(t_stack_node **a, t_stack_node **b);
void			sort(t_stack_node**a, t_stack_node**b);

//main
void			validate_input(char **argv, int argc);

//error checks
void			print_error(void);
int				check_nums(char *str);
int				check_sign(char *str);
int				check_dup(char **argv);
int				check_int(char *str);

// //print
// void print_stack(t_stack_node *stack);
// void print_sorted_index(t_stack_node *stack);
// void print_index(t_stack_node *stack);
// void print_median(t_stack_node *stack);
// void print_target(t_stack_node *stack);
// void print_push_cost(t_stack_node *stack);
// void print_cheapest(t_stack_node *stack);
// void print_sorted_index(t_stack_node *stack);

#endif