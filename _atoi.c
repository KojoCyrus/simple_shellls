#include "main.h"

/**
 * interact - Displays my shell when in its interactive mode
 * @mode: pointer to struct
 * Return: 1 on success, else 0
 */

int interact(listinfo_t *mode)
{
	return (isatty(STDIN_FILENO) && mode->read_file < 3);

}

/**
 * _delim - checks if a character is a delimeter
 * @rac: The character
 * @delim: The delimeter
 * Return: 1 if output is correct, else 0
 */

int _delim(char rac, char *delim)
{
	while (*delim != '\0')
	{
		if (*delim == rac)
			return (1);

		delim++;
	}
	return (0);
}

/**
 * _isalpha - checks for characters (alphabets)
 * @n: character
 * Return: 1 if letter is n, else 0
 */

int _isalpha(int n)
{
	if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - A function that converts a string into an integer
 * @str: The string yet to be converted
 * Return: 0 if conversion fails, else 1
 */

int _atoi(char *str)
{
	int flag = 0, result = 0, sign = 1, n = 0;
	unsigned int count;

	while (str[n] != '\0' && flag == 0)
	{
		if (str[n] == '-')
		{
			sign = -1;
			n++;
		}
		else if (str[n] >= '0' && str[n] <= '9')
		{
			flag = 1;
			result = result * 10;
			result = result + (str[n] - '0');
			n++;
		}
		else if (flag == 0)
		{
			flag = 0;
			n++;
		}
	if (sign == -1)
		result = -result;
	}
	return (result);
}
