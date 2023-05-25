#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

/* For command */
#define CMD_NORMAL 0 /* For normal cmd exe mode */
#define CMD_OR 1 /* For logical operator OR in cmd chain */
#define CMD_AND 2 /* For logical operator AND in cmd chain */
#define CMD_CHAIN 3 /* For command chain */

/**
 * struct listssh - singly linked list
 * @value: The value/number field
 * @str: String
 * next: Pointer to the next node of a list
 */

typedef struct listssh
{
	int value;
	char *str;
	struct listssh *next;
} list_t;

/**
 * struct info - Passes pseudo-arguments into a function
 * @arg: a pointer to a char array
 * @argv: A double pointer to a char array
 * @path: A pointer to current command
 * @argc: Number of arguments
 * @error_count: Unsigned integer representing error count
 * @error_tally: Integer for error number for exit()
 * @linecount: A flag for the linecount
 * @filename: A pointer to a char array for filenames
 * @env: A pointer to singly linked list, list_t
 * @environ: pointer to modified copy of env
 * @hist: pointer to history node of list_t
 * @alias: pointer to alias node of list_t
 * @env_chg: Integer for enviroment change flag
 * @status: return status of the last execute command
 * @command_buff: A double pointer of a char array to a command
 * buffer for memory management
 * @command_buff_type: Integer representing type of command buffer
 * (||, &&, ;)
 * @read_file: A file descriptor for reading line input
 * @hist_count: Integer representing the history count
 * This Structure is to store information related to the command
 * execution
 */

typedef struct info
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int error_count;
	int error_tally;
	int linecount;
	char *filename;
	list_t env;
	char **environ;
	list_t hist;
	list_t alias;
	int env_chg;
	int status;
	char **command_buff;
	int command_buff_type;
	int read_file;
	int hist_count;
} listinfo_t;

#define LISTINFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL,\
			0, 0, 0}

/* Files */

/* _string.c */
int _strlen(char *s);
int _strcmp(char *str, char *s);
char *_starts(const char *hay, const char *ned);
char *_strcat(char *dest, char *src);

/* _variables.c */
void replace_str(char **str, char *s);
int replace_var(listinfo_t *ptr);

/* log_ops.c */
int _chain(listinfo_t *ptr, char *buff, size_t *s);
void _chain_check(listinfo_t *ptr, char *buff, size_t *s,
		size_t j, size_t length);

/* __string.c */
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);

/* _alias.c */
int replace_alias(listinfo_t *ptr);

/* _atoi.c */
int interact(listinfo_t *mode);
int _delim(char rac, char *delim);
int _isalpha(int n);
int _atoi(char *str);

#endif
