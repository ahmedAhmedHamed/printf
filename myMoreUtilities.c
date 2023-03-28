#include "main.h"

/**
 * to_str - hello
 * @number: s
 * Return: s
 */
char *to_str(int number)
{
    int i, LSD, len = 0, n;
    char *str;
    n = number;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    if (number == 0)/*check this later*/
    {
        len = 2;
    }
    str = malloc(len);
    for (i = 0; i < len; i++)
    {
        LSD = number % 10;
        number = number / 10;
        if (LSD < 0)
            LSD *= -1;
        str[len - (i + 1)] = LSD + '0';
    }
    str[len] = '\0';
    return (str) ;
}

/**
 * from_unsignedInt_to_str - hello
 * @number s
 * Return: s
 */
char *from_unsignedInt_to_str(unsigned int number)
{
    unsigned int i, LSD, len = 0, n;
    char *str;
    n = number;

    while (n != 0)
    {
        len++;
        n /= 10;
    }
    if (number == 0)/*check this later*/
    {
        len = 2;
    }
    str = malloc(len);
    for (i = 0; i < len; i++)
    {
        LSD = number % 10;
        number = number / 10;
        str[len - (i + 1)] = LSD + '0';
    }
    str[len] = '\0';
    return (str) ;
}

/**
 * chooseFunction - hello
 * @format: s
 * @i: s
 * Return: s
 */
int chooseFunction(const char *format,int i)
{
    if (format[i + 1] == 's')
        return (0);
    else if (format[i + 1] == 'c')
        return (1);
    else if (format[i + 1] == 'd' || format[i + 1] == 'i')
        return (2);
    else if (format[i + 1] == 'b')
        return (3);
    else if (format[i + 1] == 'u')
        return (4);
    else if(format[i + 1] == 'o')
        return (5);
    else if (format[i + 1] == 'x')
        return (6);
    else if (format[i + 1] == 'X')
        return (7);
    else
        return (-1);
}

/**
 * verifyIdentifier - hello
 * @format: s
 * @i: s
 * Return: s
 */
int verifyIdentifier(const char * format, int i)
{
    return (format[i + 1] != 's' && format[i + 1] != 'c'
            && format[i + 1] != 'i' && format[i + 1] != 'd'
            && format[i + 1] != 'b' && format[i + 1] != 'u'
            && format[i + 1] != 'o' && format[i + 1] != 'x'
            && format[i + 1] != 'X');
}

/**
 * processIdentifier - hello
 * @format: s
 * @i: s
 * @args: s
 * Return: s
 */
int processIdentifier(const char * format, int i, va_list args)
{
    int charactersprinted = 0;
    int choice = chooseFunction(format, i);
    if (choice == 0)/*identifier is string, print the string*/
    {
        char *str = va_arg(args, char *);
        charactersprinted += print_string(str);
    }
    else if (choice == 1)/*identifier is char, print the character*/
    {
        char singlechar = va_arg(args, int);
        charactersprinted += print_char(singlechar);
    }
    else if (choice == 2)
    {
        int digit = va_arg(args, int);
        charactersprinted += print_int(digit);
    }
    else if (choice == 3)
    {
        unsigned int digit = va_arg(args, unsigned int);

        charactersprinted += printUnsignedIntToBinary(digit);
    }
    else if (choice == 4)
    {
        unsigned int digit = va_arg(args, unsigned int);

        charactersprinted += printUnsignedInt(digit);
    }
    else if (choice == 5)
    {
        int digit = va_arg(args, unsigned int);

        charactersprinted += printNonDecimal(digit, 8);
    }
    else if (choice == 6)
    {
        int digit = va_arg(args, int);
        charactersprinted += printNonDecimalsmol(digit, 16);
    }
    else if (choice == 7)
    {
        int digit = va_arg(args, int);
        charactersprinted += printNonDecimal(digit, 16);
    }
    return (charactersprinted);
}
