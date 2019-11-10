/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 17:17:15 by olesgedz          #+#    #+#             */
/*   Updated: 2019/11/08 18:20:23 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

cl_int
	cl_init
	(t_cl_info *cl)
{
	cl_int	ret;
	cl->n_progs = 0; 
	if ((ret = clGetPlatformIDs(1, &cl->pl_id, NULL)) != CL_SUCCESS)
		return (ret);
	if ((ret = clGetDeviceIDs(cl->pl_id
		, CL_DEVICE_TYPE_GPU
		, 1
		, &cl->dev_id
		, &cl->dev_num)) != CL_SUCCESS)
		return (ret);
	cl->ctxt = clCreateContext(NULL, 1, &cl->dev_id, NULL, NULL, &ret);
	if (ret != CL_SUCCESS)
		return (ret);
	cl->cmd_queue = clCreateCommandQueue(cl->ctxt, cl->dev_id
		, CL_QUEUE_PROFILING_ENABLE, &ret);
	return (ret);
}
