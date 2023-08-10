#include <stdio.h>

#define STRING \
	"and that piece of art is useful\" - Dora Korpar, 2015-10-19\n"

/**
  * main - Prints a string to the standard error
  * Return: Returns 1
  */
int main(void)
{
	fputs(STRING, stderr);
	return (1);
}
