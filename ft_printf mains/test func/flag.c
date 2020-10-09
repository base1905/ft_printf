/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 00:30:28 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/07 16:27:19 by arannara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

# define FLG_NONE	0b00000000

# define FLG_ONE	0b00000001
# define FLG_TWO	0b00000010
# define FLG_THREE	0b00000100
# define FLG_FOUR	0b00001000

int main()
{
	unsigned char	flags;

	flags = FLG_NONE;  // 0
	if (flags & FLG_ONE) // 0&0=0, 1&1=1, 0&1=0, 1&0=0
		printf("[-] FLG_ONE exist\n");
	else
		printf("[+] FLG_ONE not exist\n");

	flags = flags | FLG_ONE; // 0&0=0, 1&1=1, 0&1=1, 1&0=1
	if (flags & FLG_ONE)
		printf("[+] FLG_ONE exist\n");
	else
		printf("[-] FLG_ONE not exist\n");

	flags = flags | FLG_TWO;
	if ((flags & FLG_ONE) && (flags & FLG_TWO))
		printf("[+] FLG_ONE and FLG_TWO exist\n");
	else
		printf("[-] FLG_ONE or FLG_TWO not exist\n");

	flags = flags & (~FLG_TWO); // ~ не
	if ((flags & FLG_ONE) && (flags & FLG_TWO))
		printf("[-] FLG_ONE and FLG_TWO exist\n");
	else
		printf("[+] FLG_ONE or FLG_TWO not exist\n");
	
	return (0);
}
