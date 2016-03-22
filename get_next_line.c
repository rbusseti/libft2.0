/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:52:39 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/21 12:41:39 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check_end(char *buff)
{
	int		i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

static void	ft_buff_save(char *buff, char **buff_save)
{
	char		*temp;

	if (*buff_save == NULL)
		*buff_save = ft_strdup(buff);
	else
	{
		temp = ft_strdup(*buff_save);
		free(*buff_save);
		*buff_save = ft_strjoin(temp, buff);
		free(temp);
	}
}

static char	*ft_get_buff_save(char *buff, char **buff_save, int *keep)
{
	int		ret;
	char	*temp;

	ret = 0;
	temp = ft_strjoin(*buff_save, buff);
	if ((ret = ft_check_end(temp)))
	{
		free(*buff_save);
		*buff_save = ft_strdup(temp + ret);
		temp[ret - 1] = '\0';
		*keep = 1;
		return (temp);
	}
	else
	{
		free(*buff_save);
		*buff_save = NULL;
		if (temp[0] != '\0')
			return (temp);
		else
			return (NULL);
	}
}

static char	*ft_get_line(char *buff, char **buff_save, int *keep)
{
	int		ret;

	ret = 0;
	if (*buff_save == NULL)
	{
		if ((ret = ft_check_end(buff)))
		{
			*buff_save = ft_strdup(buff + ret);
			buff[ret - 1] = '\0';
			*keep = 1;
		}
		else
		{
			buff[ft_strlen(buff) - 1] = '\0';
			free(*buff_save);
			*buff_save = NULL;
		}
		return (ft_strdup(buff));
	}
	else
		return (ft_get_buff_save(buff, buff_save, keep));
}

int			get_next_line(const int fd, char **line)
{
	char		*buff;
	static char	*buff_save = NULL;
	int			ret;
	int			keep;

	keep = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_bzero(buff, BUFF_SIZE + 1);
	while (((ret = read(fd, buff, BUFF_SIZE)) > 0) && (ft_check_end(buff)) == 0)
	{
		ft_buff_save(buff, &buff_save);
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	if (ret >= 0)
		*line = ft_get_line(buff, &buff_save, &keep);
	free(buff);
	if (ret > 0 || (*line != NULL && (*line)[0] != '\0') || keep == 1)
		return (1);
	free(buff_save);
	return (ret);
}
