#include "main.h"

/**
*main - is a function that handles the exit command
*Return: should return 0 on success
*/

void exit_shell(void);

int main (void)
{
	char command[100];
	pid_t child_pid, wait_pid;
	int status;
	ssize_t bytes_read;
	char error_msg[] = "Error reading command\n";
	char error_fork_msg[] = "Error forking process\n";
	char error_exec_msg[] = "Error executing command\n";
	char error_wait_msg[] = "Error waiting for child process\n";


	while (1)
	{
		write(STDOUT_FILENO, "Enter command: ", sizeof("Enter command: ") - 1);
		bytes_read = read(STDIN_FILENO, command, sizeof(command));
		if (bytes_read == -1)
		{	
			write(STDOUT_FILENO, error_msg, sizeof(error_msg) - 1);
			_exit(1);
		}

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			exit_shell();
		}
		else
		{
			child_pid = fork();

			if (child_pid == -1)
			{
				write(STDOUT_FILENO, error_fork_msg, sizeof(error_fork_msg) - 1);
				_exit(1);
			}
			else if (child_pid == 0)
			{
				char *args[3];
				args[0] = command;
				args[1] = NULL;
				execvp(args[0], args);
				write(STDOUT_FILENO, error_exec_msg, sizeof(error_exec_msg) - 1);
				_exit(1);
			}
			else
			{
				wait_pid = wait(&status);

				if (wait_pid == (pid_t)-1)
				{
					write(STDOUT_FILENO, error_wait_msg, sizeof(error_wait_msg) - 1);
					_exit(1);
				}
			}
		}
	}
}

void exit_shell(void)
{
	char exit_msg[] = "Exiting the shell...\n";

	write(STDOUT_FILENO, exit_msg, sizeof(exit_msg) - 1);
	_exit(0);
}
