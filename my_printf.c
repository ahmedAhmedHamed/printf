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
        if (LSD < 0)
            LSD *= -1;
        str[len - (i + 1)] = LSD + '0';
    }
    str[len] = '\0';
    return (str) ;
}

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

int getintLength(int myInt)
{
    int size = 0;
    while(myInt)
    {
        myInt /= 10;
        size++;
    }
    if (size == 0)
        return (1);
    return (size);
}
int getUnsignedintLength(unsigned int myInt)
{
    unsigned int size = 0;
    if (myInt < 0)
    {
        myInt = 4294967295 + myInt;
    }
    while(myInt)
    {
        myInt /= 10;
        size++;
    }
    if (size == 0)
        return (1);
    return (size);
}

int ouratoi(char *s)
{
    int number = 0;
    int i;
    for (i = 0; i < _strlen(s); i++)

        number = number * 10 + (s[i] - 48);
    return number;
}

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
    else
        return (-1);
}

int print_string(char * str)
{
    if (str == 0)
        str = "(null)";
    write(1, str, _strlen(str));
    return (_strlen(str));
}

int print_char(char c)
{
    write(1, &c, 1);
    return (1);
}

int print_int(int number)
{
    int length;
    if (number < 0)
    {
        write(1, "-", 1);
    }
    length = getintLength(number);
    write(1, to_str(number), length);
    if (number < 0)
        length++;
    return (length);
}
int printUnsignedIntToBinary(unsigned int number)
{
    unsigned int x;
    if (number == 0)
        return (0);
    x = printUnsignedIntToBinary(number / 2);
    if (number % 2 == 0)
        print_char('0');
    else
        print_char('1');
    return (x + 1);
}
int printUnsignedInt(unsigned int number)
{
    int length;
    length = getUnsignedintLength(number);
    write(1, from_unsignedInt_to_str(number), length);
    return (length);
}

int verifyIdentifier(const char * format, int i)
{
    return (format[i + 1] != 's' && format[i + 1] != 'c'
            && format[i + 1] != 'i' && format[i + 1] != 'd'
            && format[i + 1] != 'b' && format[i + 1] != 'u'
            && format[i + 1] != 'o');
}

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
        charactersprinted += print_string(&singlechar);
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
    return (charactersprinted);
}

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

int printNonDecimal(int number, int base) {
    int charactersPrinted = 0;
    int i;
    if (number > base)
    {
        charactersPrinted += printNonDecimal(number / base, base);
        if (number % base > 9)
        {
            i = (number % base) + 65 - 9;
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
            number = number + 65 - 9;
            print_char(number);
            charactersPrinted++;
            return (charactersPrinted);
        }
        charactersPrinted += print_int(number);
    }
    return (charactersPrinted);
}

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

/**
 * _printf - my own printf - this one can't do anything other than %s and %c
 * @format: format to print
 * @...: strings to print
 * Return: the number of characters printed
 *
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

