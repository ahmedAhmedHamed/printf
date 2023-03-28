#include "main.h"

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
