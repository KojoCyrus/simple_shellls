#include "main.h"

/**
*execute_shell - a function the executes shell
*/
void execute_shell(void)
{
	char *prompt = "simple_shell$ ";
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	pid_t child_pid;
	int status;

	char *error_message_read = "read: Error\n";
	char *error_message_fork = "fork: Error\n";
	char *error_message_waitpid = "waitpid: Error\n";

	char **argv;
	int arg_count;
	char *token;

	while (1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));

		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			write(STDERR_FILENO, error_message_read,
				strlen(error_message_read));
			_exit(EXIT_FAILURE);
		} else if (bytes_read == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
				break;
		}

		buffer[bytes_read - 1] = '\0';

		if (strlen(buffer) == 0)
		{
			continue;
		}

		argv = malloc(sizeof(char *) * (BUFFER_SIZE / 2));
		arg_count = 0;

		token = strtok(buffer, " ");

		if (token == NULL)
		{
		write(STDOUT_FILENO, "Command not found\n", 18);
			continue;
		}

		while (token != NULL)
		{
			argv[arg_count] = token;
			arg_count++;
			token = strtok(NULL, " ");
		}
			argv[arg_count] = NULL;

		if ((child_pid = fork()) < 0)
		{
			write(STDERR_FILENO, error_message_fork, strlen(error_message_fork));
			_exit(EXIT_FAILURE);
		} else if (child_pid == 0)
		{
			if (strcmp(argv[0], "ls") == 0)
			{
				char *ls_args[] = { "/bin/ls", NULL };

				execve(ls_args[0], ls_args, NULL);
			} else if (strcmp(argv[0], "pwd") == 0)
			{
				char *pwd_args[] = { "/bin/pwd", NULL };

				execve(pwd_args[0], pwd_args, NULL);
			} else
			{
				write(STDOUT_FILENO, "Command not found\n", 18);
					free(argv);
				_exit(EXIT_FAILURE);
			}
		} else
		{
			if (waitpid(child_pid, &status, 0) == -1)
			{
				write(STDERR_FILENO, error_message_waitpid,
					strlen(error_message_waitpid));
				_exit(EXIT_FAILURE);
			}

			write(STDOUT_FILENO, "\n", 1);
		}
		free(argv);

	}
}


/**
*main - handles shell execution
*
*Return: exits upon success
*/
int main(void)
{
	execute_shell();

	write(STDOUT_FILENO, "Exiting shell\n", 18);
	_exit(EXIT_SUCCESS);
}
