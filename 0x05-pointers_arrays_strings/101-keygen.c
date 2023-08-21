#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASS_LENGTH 8

/**
 * main - Generates random valid passwords
 * Return: 0
 */
int main(void)
{
	int i, randNumber;
	char password[PASS_LENGTH + 1];
	char ch;

	srand(time(NULL));

	for (i = 0; i < PASS_LENGTH; i++)
	{
		randNumber = rand() % 62;
		if (randNumber < 26)
			ch = 'A' + randNumber;
		else if (randNumber < 52)
			ch = 'a' + (randNumber - 26);
		else
			ch = '0' + (randNumber - 52);
		password[i] = ch;
	}

	password[PASS_LENGTH] = '\0';
	printf("%s\n", password);

	return (0);
}
