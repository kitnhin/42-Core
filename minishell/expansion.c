#include "minishell.h"

char	*get_expand_string(char *str, char **envp)
{
	char *temp;
	int i = 0;

	while(envp[i] != NULL && ft_strncmp(envp[i], str, ft_strlen(str)) != 0)
		i++;
	if (envp[i] == NULL)
		return NULL; 
	temp = ft_substr(envp[i], ft_strlen(str) + 1, ft_strlen(envp[i]));
	return temp;
}

char	*expansion(char *line, char **envp)
{
	int i;
	int start;
	char *res;
	char *temp;
	int j;
	int k = 0;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * 1000000);
	while (line[j])
	{
		if (line[j] == '$')
		{
			start = j + 1;
			if(line[start] == '\0')
				res[i] = '$';
			else
			{
				while(line[j] && line[j] != ' ')
					j++;
				temp = get_expand_string(ft_substr(line, start, j - start), envp);
				if (temp != NULL)
				{
					k = 0;
					while(temp[k])
					{
						res[i] = temp[k];
						i++;
						k++;
					}
					free(temp);
				}
			}
		}
		res[i++] = line[j++];
	}
	res[i] = '\0';
	return res;
}

// int main(int argc, char **argv, char **envp)
// {
// 	char temp[] = "Hello this user is $USER $USER testing";
// 	char *str = expansion(temp, envp);

// 	printf("%s\n", str);
// 	return 0;
// }