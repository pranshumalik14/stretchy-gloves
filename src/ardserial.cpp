#include "ardserial.h"

namespace ardserial {
    // taken from: https://arduino.stackexchange.com/questions/176/how-do-i-print-multiple-variables-in-a-string
    int printf(char *str, ...) {
        int count = 0;
        char temp[ARDBUFFER + 1];

        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '%')
                count++;
        }

        va_list argv;
        va_start(argv, count);

        for (int i = 0, j = 0; str[i] != '\0'; i++) {
            if (str[i] == '%') {
                temp[j] = '\0';
                Serial.print(temp);
                j = 0;
                temp[0] = '\0';

                switch (str[++i]) {
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
                        Serial.print((char) va_arg(argv, int));
                        break;
                    case 's':
                        Serial.print(va_arg(argv, char *));
                        break;
                    default:;
                }
            } else {
                temp[j] = str[i];
                j = (j + 1) % ARDBUFFER;
                if (j == 0) {
                    temp[ARDBUFFER] = '\0';
                    Serial.print(temp);
                    temp[0] = '\0';
                }
            }
        }
        Serial.println();
        return count + 1;
    }
} // ardserial