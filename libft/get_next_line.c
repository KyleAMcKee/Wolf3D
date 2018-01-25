/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:37:29 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/08 17:20:02 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		len_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*new_line(char **line, char **file, int fd)
{
	int		len;
	char	*temp;

	if (ft_strchr(file[fd], '\n'))
	{
		len = len_line(file[fd]);
		*line = ft_strsub(file[fd], 0, len);
		temp = file[fd];
		file[fd] = ft_strsub(file[fd], len + 1, ft_strlen(file[fd]));
		ft_strdel(&temp);
		if (!ft_strcmp(file[fd], ""))
			ft_strdel(&file[fd]);
		return (file[fd]);
	}
	else
	{
		*line = ft_strdup(file[fd]);
		ft_strdel(&file[fd]);
		return (file[fd]);
	}
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char *file[4096];

	FAIL(read(fd, buf, 0) < 0 || !line || fd < 0);
	if (file[fd] && ft_strchr(file[fd], '\n'))
	{
		file[fd] = new_line(line, file, fd);
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (!file[fd])
			file[fd] = ft_strnew(0);
		buf[ret] = '\0';
		file[fd] = ft_strfjoin(file[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (file[fd])
	{
		file[fd] = new_line(line, file, fd);
		return (1);
	}
	return (0);
}
