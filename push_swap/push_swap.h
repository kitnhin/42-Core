#include "libft/libft.h"
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

# define TRUE 1
# define FALSE 0


typedef struct s_stack_node
{
	int		nbr;
	int		index;
	int		push_cost;
	int		above_median;
	int		cheapest;

	struct	s_stack_node	*target_node;
	struct	s_stack_node	*next;
	struct	s_stack_node	*prev;	
}	t_stack_node;


//utils
t_stack_node	*find_last(t_stack_node *stack);
long	ft_atol(char *str);
void	append_node(t_stack_node **stack, int n);
int		stack_sorted(t_stack_node *stack);
int	stack_len(t_stack_node *stack);
t_stack_node *find_max(t_stack_node *stack);
t_stack_node *find_min(t_stack_node *stack);

void	current_index(t_stack_node *stack);
void	set_target_a(t_stack_node *a, t_stack_node *b);
void	push_costs_a(t_stack_node *a, t_stack_node *b);
void	set_cheapest(t_stack_node *stack);
void	set_target_b(t_stack_node *a, t_stack_node *b);

t_stack_node	*find_cheapest(t_stack_node *stack);
void	bring_min_top(t_stack_node **stack);

//commands
void	rotate_both(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheapest_node);
void	rev_rotate_both(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheapest_node);
void	move_a_to_b(t_stack_node **a, t_stack_node **b);
void	move_b_to_a(t_stack_node **a, t_stack_node **b);

//inits
void	init_stack_a(t_stack_node **a, char **argv);
void	init_nodes_a(t_stack_node *a, t_stack_node *b);
void	init_nodes_b(t_stack_node *a, t_stack_node *b);

//instructions

void	ra(t_stack_node **a, int print);
void	rb(t_stack_node **b, int print);
void	rr(t_stack_node **a, t_stack_node **b, int print);

void	rra(t_stack_node **a, int print);
void	rrb(t_stack_node **b, int print);
void	rrr(t_stack_node **a, t_stack_node **b, int print);

void	sa(t_stack_node **a, int print);
void	sb(t_stack_node **b, int print);
void	ss(t_stack_node **a, t_stack_node**b, int print);

void	pa(t_stack_node **a, t_stack_node **b, int print);
void	pb(t_stack_node **b, t_stack_node **a, int print);

//sorts

void	sort_three(t_stack_node **stack);
void	sort_stacks(t_stack_node **a, t_stack_node **b);

char	**ft_split_special(char const *s, char c);

void print_stack(t_stack_node *stack);
