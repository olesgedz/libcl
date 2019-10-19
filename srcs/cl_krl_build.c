/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_krl_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:31:54 by olesgedz          #+#    #+#             */
/*   Updated: 2019/10/19 22:30:36 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"
#include "libgnl.h"
#include "libcl.h"
#include <stdio.h>
#define LOG_BUFSIZ 20480

cl_int	krl_set_args(cl_context ctxt, t_cl_krl *krl)
{
	cl_int		ret;
	size_t		i;

	i = 0;
	while (i < krl->nargs)
	{
		krl->args[i] = clCreateBuffer(ctxt, CL_MEM_READ_WRITE,
		krl->sizes[i], NULL, &ret);
		if (ret != CL_SUCCESS)
			return (ret);
		if ((ret = clSetKernelArg(krl->krl, i,\
		sizeof(krl->args[i]), (void*)&krl->args[i])) != CL_SUCCESS)
			return (ret);
		i++;
	}
	return (CL_SUCCESS);
}

static void	krl_get_opts(t_vect *build_line, char **opts)
{
	*opts = build_line->data;
}

static void	krl_source_free(t_vect lines)
{
	size_t	i;

	i = 0;
	while (i < lines.used / 8)
	{
		free(((char **)lines.data)[i]);
		i++;
	}
	free(lines.data);
}

cl_int	cl_krl_build(t_cl_info *cl, t_cl_krl *krl, int fd,
char *string, t_vect *kernel_names)
{
	char		*krlname;
	char		buffer[LOG_BUFSIZ];
	cl_int		ret;
	t_vect		lines;
	int i;

	i = -1;
	unsigned char **names;
	names = ft_nsplit((*kernel_names).data, (*kernel_names).used, ":", sizeof(":") - 1);
	vect_init(&lines);
	gnl_lines(fd, &lines, GNL_APPEND_CHAR);
	cl->prog = clCreateProgramWithSource(cl->ctxt, lines.used / sizeof(void *),
		(const char **)lines.data, NULL, &ret);
	if (ret != CL_SUCCESS)
		return (ret);
	if ((ret = clBuildProgram(cl->prog,
		cl->dev_num, &cl->dev_id, string, NULL, NULL)) != CL_SUCCESS)
	{
		clGetProgramBuildInfo(cl->prog, cl->dev_id, CL_PROGRAM_BUILD_LOG
			, LOG_BUFSIZ, buffer, NULL);
		write(1, buffer, ft_strlen(buffer));
		return (ret);
	}
	while ((char *)names[++i])
	{
		if (!(krl[i].krl = clCreateKernel(cl->prog, (char *)names[i], &ret)))
			return (ret);
	}
	krl_source_free(lines);
	ft_2darray_uchar_free(&names);
	return (ret);
}
