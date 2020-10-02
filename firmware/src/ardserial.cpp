#include "ardserial.h"

namespace ardserial
{
// source: https://arduino.stackexchange.com/questions/176/how-do-i-print-multiple-variables-in-a-string. changed
// formatting and fixed bug related to not printing input string if buffer is not full and does not contain a variable
int printf(const char *str, ...)
{
	int count = 0;
	int j	  = 0;
	char temp[ARDBUFFER + 1];

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '%')
			count++;
	}

	va_list argv;
	va_start(argv, count);

	for (int i = 0; str[i] != '\0'; i++)
	{
		// to print '%' as a regular character, use '%%'
		if (str[i] == '%')
		{
			temp[j] = '\0';
			Serial.print(temp);
			j		= 0;
			temp[0] = '\0';

			switch (str[++i])
			{
				case 'd':
					Serial.print(va_arg(argv, int));
					break;
				case 'l':
					Serial.print(va_arg(argv, long));
					break;
				case 'f':
					Serial.print(va_arg(argv, double));
					break;
				case 'c':
					Serial.print(static_cast<char>(va_arg(argv, int)));
					break;
				case 's':
					Serial.print(va_arg(argv, char *));
					break;
				default:
					break;
			}
		}
		else
		{
			temp[j] = str[i];
			j		= (j + 1) % ARDBUFFER;

			// buffer full
			if (j == 0)
			{
				temp[ARDBUFFER] = '\0';
				Serial.print(temp);
				temp[0] = '\0';
			}
		}
	}

	// buffer has content: print it
	if (j != 0)
	{
		temp[j] = '\0';
		Serial.print(temp);
		temp[0] = '\0';
	}

	Serial.println();
	return count + 1;
}
} // namespace ardserial