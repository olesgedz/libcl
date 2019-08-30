/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_krl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:32:12 by olesgedz          #+#    #+#             */
/*   Updated: 2019/08/30 23:32:13 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "malloc.h"
#include "libcl.h"

void
	cl_krl_init
	(t_cl_krl *krl
	, size_t nargs)
{
	MALLOC_N(krl->args, nargs);
	MALLOC_N(krl->sizes, nargs);
	krl->nargs = nargs;
}
