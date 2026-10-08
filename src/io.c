
#include <driftc/io.h>

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

/*
 * Internal formatting function.
 * The trailing newline is controlled by the caller.
 */
static void vprint(const char *format, va_list args)
{
    while (*format != '\0') {
        if (*format != '%') {
            putchar(*format++);
            continue;
        }

        format++;

        if (*format == '\0') {
            putchar('%');
            break;
        }

        switch (*format++) {
            case '%':
                putchar('%');
                break;

            case 'i':
                printf("%d", va_arg(args, int));
                break;

            case 'f':
                printf("%f", va_arg(args, double));
                break;

            case 's':
                printf("%s", va_arg(args, const char *));
                break;

            case 'c':
                putchar(va_arg(args, int));
                break;

            case 'm':
                printf("%p", va_arg(args, void *));
                break;

            case 'n':
                /*
                 * TODO: Define how variable names are supplied.
                 */
                fputs("%n", stdout);
                break;

            default:
                putchar('%');
                putchar(format[-1]);
                break;
        }
    }
}

void print(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vprint(format, args);
    va_end(args);
}

void println(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vprint(format, args);
    va_end(args);

    putchar('\n');
}

bool readln(char *buffer, usize capacity)
{
    if (buffer == NULL || capacity == 0) {
        return false;
    }

    if (fgets(buffer, (int)capacity, stdin) == NULL) {
        buffer[0] = '\0';
        return false;
    }

    for (usize i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            break;
        }
    }

    return true;
}
