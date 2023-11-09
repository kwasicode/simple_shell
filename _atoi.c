#include "shell.h"

/**
 * is_delim - This function checks for a  delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 0 if false, and 1 if true
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * interactive - This function returns true when in interactive mode
 * @info: the address
 * Return: 0 if others and  interactive 1
 */
int interactive(info_t *info)
{
        return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *_atoi - This function converts integer to string
 *@s: converitng variable
 *Return: 0 
 */

int _atoi(char *s)
{
        int i, sign = 1, flag = 0, output;
        unsigned int result = 0;

        for (i = 0;  s[i] != '\0' && flag != 2; i++)
        {
                if (s[i] == '-')
                        sign *= -1;

                if (s[i] >= '0' && s[i] <= '9')
                {
                        flag = 1;
                        result *= 10;
                        result += (s[i] - '0');
                }
                else if (flag == 1)
                        flag = 2;
        }

        if (sign == -1)
                output = -result;
        else
                output = result;

        return (output);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

