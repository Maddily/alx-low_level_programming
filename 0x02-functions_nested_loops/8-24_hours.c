#include "main.h"

/**
 * jack_bauer - Prints every minute of the day of Jack Bauer
 */
void jack_bauer(void)
{
	int i;
	int hour;
	int minute;

	for (i = 0; i < 1440; i++)
	{
		hour = i / 60;
		minute = i % 60;
		_putchar((hour / 10) + '0');
		_putchar((hour % 10) + '0');
		_putchar(':');
		_putchar((minute / 10) + '0');
		_putchar((minute % 10) + '0');
		_putchar('\n');
	}
}
