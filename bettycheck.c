#include "main.h"

/**
*main - a function that prints a message
*
*Return: 0 on success
*/
int main(void)
{
	char *message = "Simple Shell Project is not that simple, haha!\n";

	write(STDOUT_FILENO, message, strlen(message));

	exit(0);
}
