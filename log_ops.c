#include "main.h"

/**
 * _chain - checks if current char in buffer is a chain delimiter
 * @ptr: pointer to head of list
 * @buff: buffer
 * @s: pointer to current position in buffer
 * Return: 1 if char is a chain delimiter else 0
 */

int _chain(listinfo_t *ptr, char *buff, size_t *s)
{

	/* Loop through buffer chars till buff = NULL */
	while (buff[*s] != '\0')
	{
		/* Checks the logical or chain */
		if (buff[*s] == '|' && buff[*s + 1] == '|')
		{
			/* Cancel current command */
			buff[*s] = '\0';
			(*s)++;
			/*Set the cmd chain type to logical or */
			ptr->command_buff_type == CMD_OR;
			

		}
		/* Checks the logical and chain */
		else if (buff[*s] == '&' && buff[*s + 1] == '&')
		{
			/* Cancel current command */
			buff[*s] = '\0';
			(*s)++;
			/* Set the cmd chain type to logical and */
			ptr->command_buff_type = CMD_AND;
		}
		/* Check for cancellation of cmd chain */
		else if (buff[*s] == ';' && buff[*s + 1] == ';')
		{
			/* cancel current command */
			buff[*s] = '\0';
			(*s)++;
			/* set cmd chain type to regular */
			ptr->command_buff_type = CMD_CHAIN;
		}
		else
			/* Cmd chain failed */
			return (0);
	}
	/* cmd chain succesful */
	return (1);
}

/**
 * _chain_check - test the chain checking per the last status
 * @ptr: pointer to head of list
 * @buff: buffer
 * @s:pointer to current position in buffer
 * @j:start position in buffer
 * @length: length of buffer
 * Return: void
 */

void _chain_check(listinfo_t *ptr, char *buff, size_t *s,
		size_t j, size_t length)
{
	/* Loop through buffer char till buffer = NULL */
	while (buff[*s] != '\0')
	{
		/* Check if the buffer type is logical & and its status is true*/
		if (ptr->command_buff_type == CMD_AND && ptr->status)
		{
			/* set buffer char to NULL */
			buff[*s] = '\0';
			/* Direct pointer s to length of buffer */
			*s = length;
		}
		else
		{
			/* Check if buffer type is logical or and its status is false */
			if (ptr->command_buff_type == CMD_OR && !ptr->status)
			{
				/* srt buffer char to NULL */
				buff[*s] = '\0';
				/* Direct pointer s to length of buffer */
				*s = length;
			}
		}
	}
}
