#include <stdlib.h>
#include <stdio.h>
#include "main.h"
/**
 * append_char - Multiple copies of a particular character
 * are appended to the end of a string.
 * @str: The string input whose ending is to be trimmed
 * @c: The char to append
 * @n: The number of times the char will be added
 * @can_free: Specifies if the given string can be freed
 * Return: The new copy of the string
 */
char *append_char(char *str, char c, int n, char can_free)
{
	int i, size;
	char *new_str;

	size = str ? str_len(str) : 0;
	new_str = malloc(sizeof(char) * (size + n + 1));
	if (new_str)
	{
		for (i = 0; i < (size + n); i++)
			new_str[i] = i < size ? str[i] : c;
		new_str[i] = '\0';
	}
	if (can_free)
		free(str);
	return (new_str);
}
/**
 * delete_char - Removes duplicates of a specified character from a string.
 * @str: The string passed
 * @c: The character to remove from the string
 * @can_free: Specifies if the given string can be freed
 * Return: The new copy of the string, otherwise NULL
 */
char *delete_char(char *str, char c, char can_free)
{
	char *new_str;
	int len = str_len(str), i;

	new_str = malloc(sizeof(char) * (len - count_char(str, c) + 1));
	if (new_str)
	{
		for (i = 0, len = 0; *(str + i) != '\0'; i++)
		{
			if (*(str + i) != c)
				*(new_str + len++) = *(str + i);
		}
		*(new_str + len) = '\0';
	}
	if (can_free)
		free(str);
	return (new_str);
}
/**
 * insert_char - Inserts a character into a string
 * @str: The source string input
 * @pos: The insertion position of the character
 * @c: The character to insert into the string
 * @can_free: Specifies if the given string can be freed
 * Return: The trimmed copy
 */
char *insert_char(char *str, int pos, char c, char can_free)
{
	char *new_str;
	int i, j, len;

	len = str_len(str);
	new_str = malloc(sizeof(char) * (len + 2));
	if (new_str != NULL)
	{
		for (i = 0, j = 0; i < len; i++)
		{
			if (i == pos)
				*(new_str + j++) = c;
			*(new_str + j) = *(str + i);
			j++;
		}
		*(new_str + len + 1) = '\0';
		if (can_free)
			free(str);
	}
	return (new_str);
}
/**
 * count_char - Counts the number of copies of a character in a string
 * @str: The source string input
 * @c: The character find
 * Return: The number of times the character was found
 */
int count_char(char *str, char c)
{
	int count = 0, i;

	for (i = 0; str != NULL && *(str + i) != '\0'; i++)
		count += *(str + i) == c ? 1 : 0;
	return (count);
}
/**
 * str_cat - Concatenates two strings
 * @left: The left string
 * @right: The right string
 * @can_free: Specifies if the given strings can be freed
 * Return: A pointer to the concatenated string
 */
char *str_cat(char *left, char *right, char can_free)
{
	int left_length = str_len(left);
	int right_length = str_len(right);
	int i;
	char *str;

	if (left == NULL && right == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (left_length + right_length + 1));
	if (str != NULL)
	{
		for (i = 0; *(left + i) != '\0'; i++)
			*(str + i) = *(left + i);
		for (i = 0; *(right + i) != '\0'; i++)
			*(str + left_length + i) = *(right + i);
		*(str + left_length + right_length) = '\0';
	}
	if (can_free)
	{
		free(left);
		free(right);
	}
	return (str);
}
