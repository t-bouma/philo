/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbouma <tbouma@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 17:02:20 by tbouma        #+#    #+#                 */
/*   Updated: 2022/06/21 19:19:34 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	error_msg(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int	perror_msg(char *str)
{
	perror(str);
	exit(1);
}

void	print_die(t_philo *philo)
{
	action_print(philo, "\tis dead\n");
	exit(0);
}

int	action_print(t_philo *philo, char *str)
{
	long	curr_time;
	
	curr_time = current_time_stamp(philo);
	lock(philo->state->mutex_print);
	ft_putnbr_fd(curr_time, 1);
	ft_putstr_fd(" ms Philo ", 1);
	ft_putnbr_fd(philo->philo_n, 1);
	ft_putstr_fd(str, 1);
	unlock(philo->state->mutex_print);
	return (0);
}