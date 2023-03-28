#include "main.h"

/**
 * processFunction - hello
 * @format: s
 * @args: s
 * Return: s
 */
int processFunction(const char *format, va_list args)
{
    int i;
    int formatlength = _strlen(format);
    int charactersprinted = 0;

    for (i = 0; i < formatlength; i++)
    {
        if (format[i] != '%')/*if character is not an identifier, print it*/
        {
            charactersprinted += print_char(format[i]);
            continue;
        }

        while (format[i + 1] == ' ')
            i++;

        if (format[i] + 1 == '\0')
            return(-1);

        if (verifyIdentifier(format, i))/*if character after % is not s or c then print %*/
        {
            if (format[i + 1] == '\0')/*if % has % after it increment i*/
                continue;

            charactersprinted += print_char(format[i]);

            if (format[i + 1] == '%')
                i++;
            continue;
        }

        charactersprinted += processIdentifier(format, i, args);

        i++;/*i needs to be incremented if an identifier is used in order to not print the identification character*/
    }
    return (charactersprinted);
}

/**
 * _printf - my own printf - this one can't do anything other than %s and %c
 * @format: format to print
 * @...: strings to print
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    int formatlength = _strlen(format);
    va_list args;
    int charactersprinted = 0;

    if (formatlength == -1)
        return (-1);

    va_start(args, format);/*start of args loop*/
    charactersprinted += processFunction(format, args);
    va_end(args);/*end of args loop*/
    return (charactersprinted);
}
