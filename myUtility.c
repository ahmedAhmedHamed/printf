#include "main.h"

/**
 * _strlen - helo
 * @s: s
 * Return: s
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
 * getintLength - hello
 * @myInt s
 * Return: s
 */
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
/**
 * getUnsignedintLength - hello
 * @myInt s
 * Return: s
 */
int getUnsignedintLength(unsigned int myInt)
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

/**
 * ouratoi - hello
 * @s s
 * Return: s
 */
int ouratoi(char *s)
{
    int number = 0;
    int i;
    for (i = 0; i < _strlen(s); i++)
        number = number * 10 + (s[i] - 48);
    return number;
}

