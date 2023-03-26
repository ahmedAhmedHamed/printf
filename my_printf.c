#include "main.h"
/**
 * _strlen - helo
 * @s: number
 * Return: number
 */
int _strlen(const char *s)
{
int len;
if (s == 0)
    return (-1);
len = 0;
while (s[len] != '\0')
len++;
return (len);
}

/**
 * _printf - my own printf - this one can't do anything other than %s and %c
 * @format: format to print
 * @...: strings to print
 * Return: the number of characters printed
 *
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int charactersprinted = 0;
    int formatlength = _strlen(format);
    if (formatlength == -1)
        return (-1);

    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);


    va_start(args, format);/*start of args loop*/
    for (i = 0; i < formatlength; i++)
    {
        if (format[i] != '%')/*if character is not an identifier, print it*/
        {
            write(1, &format[i], 1);
            charactersprinted++;
            continue;
        }

        while (format[i + 1] == ' ')
            i++;

        if (format[i] + 1 == '\0')
            return(-1);

        if (format[i + 1] != 's' && format[i + 1] != 'c')/*if character after % is not s or c then print %*/
        {
            if (format[i + 1] == '\0')/*if % has % after it increment i*/
                continue;
            write(1, &format[i], 1);
            charactersprinted++;
            if (format[i + 1] == '%')
            i++;
            continue;
        }

        if (format[i + 1] == 's')/*identifier is string, print the string*/
        {
            char *str = va_arg(args, char *);
            if (str == 0)
                str = "(null)";
            charactersprinted += _strlen(str);
            write(1, str, _strlen(str));
        }

        else if (format[i + 1] == 'c')/*identifier is char, print the character*/
        {
            char singlechar = va_arg(args, int);
            charactersprinted++;
            write(1, &singlechar, 1);
        }
        i++;/*i needs to be incremented if an identifier is used in order to not print the identification character*/
    }
    va_end(args);/*end of args loop*/
    return (charactersprinted);
}
