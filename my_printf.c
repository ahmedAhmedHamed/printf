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
len++;
return (len);
}

int _isDigit(int digit)
{
    return(digit >= 48 && digit <= 57);
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

    va_start(args, format);
    for (i = 0; i < formatlength; i++)
    {
        if (format[i] != '%')
        {
            write(1, &format[i], 1);
            charactersprinted++;
            continue;
        }
        if (format[i + 1] != 's' && format[i + 1] != 'c')
        {
            write(1, &format[i], 1);
            charactersprinted++;
            if (format[i + 1] == '%')
                i++;
            continue;
        }
        if (format[i + 1] == 's')
        {
            char *str = va_arg(args, char *);
            charactersprinted += _strlen(str);
            write(1, str, _strlen(str));
        }
        else if (format[i + 1] == 'c')
        {
            int singlechar = va_arg(args, int);
            charactersprinted++;
            write(1, &singlechar, 1);
        }
        i++;
    }
    va_end(args);
    return (charactersprinted);
}
