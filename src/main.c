/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:26:22 by tiemen            #+#    #+#             */
/*   Updated: 2022/06/30 12:26:18 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	mutex_free(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->number_of_philo)
	{
		free(state->mutex_fork[i]);
		i++;
	}
	free(state->mutex_fork);
	free(state->mutex_done_eating);
	free(state->mutex_print);
	free(state->mutex_someone_died);
	return (0);
}

static int	all_free(t_philo **philo, t_state *state)
{
	int	i;

	i = 0;
	mutex_free(state);
	while (i < state->number_of_philo)
	{
		free(philo[i]);
		i++;
	}
	free(philo);
	free(state->bool_fork);
	return (0);
}

static int	main2(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		error_msg("Wrong number of arguments\n");
		return (1);
	}
	if (ft_atoi(argv[1]) < 1 && ft_atoi(argv[1]) < 10000)
	{
		error_msg("To few or to many Philosophrs\n");
		return (2);
	}
	return (0);
}

static int	main3(t_state *state, t_philo **philo)
{
	int i;

	i = 0;
	if (start_thread(philo))
	{
		error_msg("Error: Tread error.\n");
		all_free(philo, state);
		return (1);
	}
	if (wait_thread(philo))
	{
		error_msg("Error: Tread error.\n");
		all_free(philo, state);
		return (1);
	}
	while (i < state->number_of_philo)
	{
		if ((*philo)->err != 0)
		{
			error_msg("Error; Philo tread has error.");
			break ;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo			**philo;
	t_state			state;

	if (main2(argc, argv))
		return (1);
	philo = malloc(sizeof(t_philo *) * ft_atoi(argv[1]));
	if (philo == NULL)
		return (3);
	if (init_state(philo, &state, argv, argc))
	{
		error_msg("Error: Malloc or mutex error.\n");
		all_free(philo, &state);
		return (1);
	}
	if (start_program_time(philo[0]))
	{
		error_msg("Error: Time error.\n");
		all_free(philo, &state);
		return (1);
	}
	main3(&state, philo);
	destroy_mutex(&state);
	all_free(philo, &state);
	return (0);
}

//system("leaks philo");