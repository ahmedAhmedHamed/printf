#ifndef ALGOS_MAIN_H
#define ALGOS_MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
char *to_str(int number);
char *from_unsignedInt_to_str(unsigned int number);
int _strlen(const char *s);
int getintLength(int myInt);
int getUnsignedintLength(unsigned int myInt);
int ouratoi(char *s);
int chooseFunction(const char *format,int i);
int print_string(char * str);
int print_char(char c);
int print_int(int number);
int printUnsignedIntToBinary(unsigned int number);
int printUnsignedInt(unsigned int number);
int verifyIdentifier(const char * format, int i);
int processIdentifier(const char * format, int i, va_list args);
int processFunction(const char *format, va_list args);
int printNonDecimal(int number, int base);
int printS(char *str);
int _printf(const char *format, ...);
int printNonDecimalsmol(int number, int base);
#endif

