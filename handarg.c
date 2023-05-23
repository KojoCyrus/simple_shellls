#include "main.h"

/**
*main - a function that handles argemtnts
*
*Return: should return 0 upon success
*/
int main(void)
{
	char *prompt = "simple_shell$ ";
	char *lnptr;
	size_t n = 0;

	write(STDOUT_FILENO, prompt, strlen(prompt));
	getline(&lnptr, &n, stdin);
	write(STDOUT_FILENO, lnptr, strlen(lnptr));

	free(lnptr);
	exit(0);
}
