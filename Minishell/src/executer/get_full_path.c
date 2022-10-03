/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:40:51 by minkyeki          #+#    #+#             */
/*   Updated: 2022/08/03 21:47:26 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/** For opendir | readdir | closedir */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <dirent.h>

#include "../builtin/environ.h"
#include "../../include/libft.h"
#include "../main/minishell.h"
#include "../string/string.h"

#define COMMAND_NOT_FOUND (127)

char	**get_environ_path(char	**envp)
{
	int		i;
	char	*p_path;
	char	**p_path_split;

	i = 0;
	p_path_split = NULL;
	while (envp[i] != NULL)
	{
		p_path = ft_strnstr(envp[i], "PATH", 4);
		if (p_path != NULL)
		{
			p_path_split = ft_split(p_path + 5, ':');
			break ;
		}
		i++;
	}
	return (p_path_split);
}

/* is_valid_path():
** NOTES: 
** 1) If there is a program in that path, return true.
** 2) struct dirent *file: we only use entry [d_name]. 
*/
int	is_valid_path(char *path, char *name)
{
	DIR				*dir_ptr;
	struct dirent	*file;
	int				is_valid_path;

	is_valid_path = false;
	dir_ptr = opendir(path);
	if (dir_ptr == NULL)
		return (is_valid_path);
	while (is_valid_path == false)
	{
		file = readdir(dir_ptr);
		if (file == NULL)
			break ;
		if (ft_strncmp(file->d_name, name, ft_strlen(name) + 1) == 0)
			is_valid_path = true;
	}
	closedir(dir_ptr);
	return (is_valid_path);
}

char	*get_cmd_full_path(t_string *buffer, char *name, char **env_path)
{
	size_t		i;
	char		*cmd_full_path;

	i = -1;
	cmd_full_path = NULL;
	if (env_path == NULL)
		return (NULL);
	while (env_path[++i])
	{
		buffer->f_append(buffer, env_path[i]);
		if (is_valid_path(buffer->text, name))
		{
			buffer->f_push_back(buffer, '/');
			buffer->f_append(buffer, name);
			cmd_full_path = ft_strdup(buffer->text);
			break ;
		}
		buffer->f_clear(buffer);
	}
	return (cmd_full_path);
}

/** get_full_path()
 ** NOTES:
 ** 1) It iterates through the environment variables and appends them to [name].
 ** 2) if it fail to find, return NULL.
 ** 3) it also supports: ./minishell
 */
char	*get_full_path(char *name, char **envp)
{
	t_string	*buffer;
	char		**env_path;
	char		*cmd_full_path;

	cmd_full_path = get_environ_value("PWD", envp);
	buffer = new_string(20);
	if (ft_strchr(name, '/') != NULL && ft_strchr(name, '.') != NULL \
		&& is_valid_path(cmd_full_path, ft_strchr(name, '/') + 1))
	{
		buffer->f_append(buffer, name);
		buffer->f_replace_all(buffer, ".", cmd_full_path);
		cmd_full_path = ft_strdup(buffer->text);
	}
	else if (ft_strchr(name, '/') == NULL)
	{
		env_path = get_environ_path(envp);
		cmd_full_path = get_cmd_full_path(buffer, name, env_path);
		delete_strs(&env_path);
	}
	else
		cmd_full_path = ft_strdup(name);
	delete_string(&buffer);
	return (cmd_full_path);
}
