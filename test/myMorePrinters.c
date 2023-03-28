#include "main.h"

/**
 * printNonDecimalsmol - hello
 * @number: s
 * @base: s
 * Return: s
 */
int printNonDecimalsmol(int number, int base)
{
    int charactersPrinted = 0;
    int i;
    if (number > base)
    {
        charactersPrinted += printNonDecimal(number / base, base);
        if (number % base > 9)
        {
            i = (number % base) + 97 - 10;
            print_char(i);
            charactersPrinted++;
            return (charactersPrinted);
        }
        charactersPrinted += print_int(number % base);
    }
    else
    {
        if (number > 9)
        {
            number = number + 97 - 10;
            print_char(number);
            charactersPrinted++;
            return (charactersPrinted);
        }
        charactersPrinted += print_int(number);
    }
    return (charactersPrinted);
}

/**
 * printNonDecimal - hello
 * @number: s
 * @base: s
 * Return: s
 */
int printNonDecimal(int number, int base) {
    int charactersPrinted = 0;
    int i;
    if (number > base)
    {
        charactersPrinted += printNonDecimal(number / base, base);
        if (number % base > 9)
        {
            i = (number % base) + 65 - 10;
            print_char(i);
            charactersPrinted++;
            return (charactersPrinted);
        }
        charactersPrinted += print_int(number % base);
    }
    else
    {
        if (number > 9)
        {
            number = number + 65 - 10;
            print_char(number);
            charactersPrinted++;
            return (charactersPrinted);
        }
        charactersPrinted += print_int(number);
    }
    return (charactersPrinted);
}

/**
 * printS - hello
 * @str: s
 * Return: s
 */
int printS(char *str)
{
    int i = 0;
    int length;
    if (str == 0)
        str = "(null)";
    length = _strlen(str);
    for (i = 0; i < length; i++)
    {
        if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
        {

        }
        else
        {
            print_char(str[i]);
        }
    }
    write(1, str, length);
    return (length);
}
