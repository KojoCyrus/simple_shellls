#include "main.h"

/**
 * _strlen - Returns the lenght of a string
 * @s: string
 * Return: length of string
 */

int _strlen(char *s)
{
	int length = 0;

	if (s == NULL)
		return (-1);

	while (*s != '\0')
	{
		s++;
		length++;
	}
	return (length);
}

/**
 * _strcmp - compares two strings
 * @str: First string
 * @s: Second String
 * Return: compared strings
 */

int _strcmp(char *str, char *s)
{
	int i = 0;

	for (; str[i] != '\0' && s[i] != '\0'; i++)
	{
		if (str[i] != s[i])
			return (str[i] - s[i]);
	}
		i++;
	return (0);
}

/**
 * _starts - A function that checks if a sub string is in a string
 * @ned: The sub string
 * @hay: The main string
 * Return: Address of next character of the string else NULL
 *
 */

char *_starts(const char *hay, const char *ned)
{
	while (*ned && (*ned++ == *hay++))
	{
		/* Checks for the end of the needle string */
		if (*ned == '\0')
			/* typecast to convert from const char to char before return */
			return ((char *)hay);
	}
	return (NULL);
}

/**
 * _strcat - concatenates two strings
 * @dest: Destination string
 * @src: source string
 * Return: pointer to the dest string
 */

char *_strcat(char *dest, char *src)
{
	int length = 0, s = 0;

	for (; dest[length] != '\0'; length++)

	for (; src[s] != '\0'; s++)
	{
		dest[length] = src[s];
		length++;
	}

	dest[length] = '\0';
	return (dest);
}

/**
 * _strchr -  A function that locates a char in a string
 * @
