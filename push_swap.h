/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:07 by sdonny            #+#    #+#             */
/*   Updated: 2022/02/23 19:17:07 by sdonny	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	int				score;
	int				ra;
	struct s_stack	*next;
}				t_stack;

typedef struct s_score
{
	int				count_a;
	int				count_b;
	int				flag_a;
	int				flag_b;

}				t_score;

typedef struct s_all
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				min;
	int				max;
	int				med;
	int				len_a;
	int				len_b;
}				t_all;

void	ft_error(void);
int		ft_parse(int argc, char **argv);
void	ft_init(t_list *stack, t_all *all);
void	ft_copying(int argc, char **argv, t_all *all);
int64_t	ft_atoii(const char *str);
int		ft_checkk(unsigned long result, int sign);
void	ft_min_max(int64_t res, char **mass_str);
void	ft_clean_split(char **mass);
int		ft_sortedstack(t_stack **stack);
void	ft_sortedthree(t_all *stack);
void	ft_sortedfive(t_all *all);
void	ft_swap_a_b(t_all *all, int flag);
void	ft_swap_a(t_stack *stack, int flag);
void	ft_swap_b(t_stack *stack, int flag);
void	ft_rotate_a(t_stack **stack, int flag);
void	ft_rotate_b(t_stack **stack, int flag);
void	ft_rotate_a_b(t_stack **stack_a, t_stack **stack_b, int flag);
void	ft_reverserotate_a(t_stack **stack, int flag);
void	ft_reverserotate_b(t_stack **stack, int flag);
void	ft_reverserotate_a_b(t_stack **stack_a, t_stack **stack_b, int flag);
void	ft_list_sort(t_stack *stack, t_all *all);
void	ft_sorted(t_all *all);
void	ft_push_a(t_all *all, int flag);
void	ft_push_b(t_all *all, int flag);
void	ft_globalsort(t_all *all);
void	ft_initScore(t_score *score);
void	ft_score(t_all *all);
void	ft_sortscore(t_all *all, t_score *score);
int		ft_findscore(t_all *all, t_stack *b, t_score *score, int minscore);
void	ft_searchscore(t_all *all, t_stack *b, int *score, int *ptr);
void	ft_minscore(t_all *all, t_score	*score);
void	ft_free(t_all *all);
void	ft_initscore(t_score *score);
void	ft_free_stack(t_stack **stack);
void	ft_stack_null(t_all *stack, t_stack *list);
void	f_rotate_b(t_all *all, int flag);
void	f_rotate_a(t_all *all, int flag);
void	f_reverserotate_b(t_all *all, int flag);
void	f_reverserotate_a(t_all *all, int flag);
void	f_rotate_a_b(t_all *all, int flag);
void	f_reverserotate_a_b(t_all *all, int flag);
void	f_swap_a(t_all *all, int flag);
void	f_swap_b(t_all *all, int flag);
void	f_swap_a_b(t_all *all, int flag);
void	f_push_a(t_all *all, int flag);
void	f_push_b(t_all *all, int flag);

#endif
