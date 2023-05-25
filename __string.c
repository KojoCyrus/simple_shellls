#include "main.h"

/**
 * strcpy - Copies the string pointed by src to dest
 * @dest: the destination string
 * @src: the source string
 * Return: the copied string
 */

char *_strcpy(char *dest, const char *src)
{
	int len = 0;

	while (src[len] != '\0')
	{
		dest[len] = src[len];
		len++;
	}

	dest[len] = '\0';
	return (dest);
}

/**
 * _strdup - A function that duplicates a string
 * @str: the source string
 * Return: The duplicated string
 */

char _strdup(const char *str)
{
	char *ptr;
	size_t len = _strlen(str);

	/* If string is empty, return NULL */
	if (str == NULL)
		return (NULL);

	/* Allocate memory to new string */
	ptr = (char *) malloc(sizeof(char) * (len + 1));

	/* if malloc fails */
	if (ptr == NULL)
		return (NULL);

	_strcpy(ptr, str);
	return (ptr);
}
