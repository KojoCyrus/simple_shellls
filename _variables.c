#include "main.h"

/**
 * replace_var - handles variable replacement
 * @ptr: pointer to head of the lists
 * Return: 1 upon replacement else 0
 */

int replace_var(listinfo_t *ptr)
{
	int a = 0;
	list_t *rep;

	while (ptr->argv[a])
	{
		/* Check if the arg starts with '$' or is not empty */
		if (ptr->argv[a][0] != '$' || ptr->argv[a][1] == '\0')
		{

			/* check if argument is not empty and is "$?" */
			if (_strcmp(ptr->argv[a] == '\0', "$?"))
			{
				/* replace status converted argument into a string */
				replace_str(ptr->argv + a,
						_strdup(_convert_num(ptr->status, 10, 0)));
			}
			/* Check if the arg is not emty and is "$$" */
			else if (_strcmp(ptr->argv[a] == '\0', "$$"))
			{
				/* replace converted argument with current pid into a string */
				replace_str(ptr->argv + a,
						_strdup(_convert_num(getpid(), 10, 0)));
			}
			else
			{
				/* Find node in env list that start with argument that has the '=' sign */
				rep = node_starts(ptr->env, ptr->argv[a] + 1, '=');
				if (rep != NULL)
				{
					/* Replace argument with value after '=' is found in env list */
					replace_str(ptr->argv + a,
							_strdup(_strchr(rep->str, '=') + 1));
				}
			}
			/* Replace argument with empty string */
			replace_str(ptr->argv + a, _strdup(""));
		}
		a++;
	}
	return (0);
}

/**
 * replace_str - Replaces a string
 * @str: former string
 * @s: new string
 * Return: Void
 */

void replace_str(char **str, char *s)
{
	/* free memory of old string */
	free(*str);
	/* point old string to new string */
	*str = s;

}
