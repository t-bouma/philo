/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbouma <tbouma@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 11:29:09 by tbouma        #+#    #+#                 */
/*   Updated: 2022/06/16 15:41:28 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// int	main(void)
// {
// 	unsigned char	c;

// 	c = 'A';
// 	c = ft_lower(c);
// 	printf("%c\n", c);
// }