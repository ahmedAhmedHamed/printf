#include "main.h"

/**
 * _strlen - helo
 * @s: number
 * Return: number
 */
int _strlen(const char *s)
{
int len;
len = 0;
while (s[len] != '\0')
{
s[len];
len++;
}
return (len);
}

/**
 * _printf - my own printf - this one can't do anything other than %s and %c
 * @format: format to print
 * @...: strings to print
 * Return: 1 always
 */
int _printf(const char *format, ...)
{
va_list args;
unsigned int i = 0;
int j = 0;
int formatlength = _strlen(format);

va_start(args, formatlength);
for (i = 0; i < formatlength; i++) {

if (format[i] == 's')
{
char *str = va_arg(args, char *);
write(1, str, _strlen(str));
}
else if (format[i] == 'c')
{
int singlechar = va_arg(args, int);
write(1, &singlechar, 1);
}

}

va_end(args);
return (1);
}

