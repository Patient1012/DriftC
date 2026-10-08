#ifndef DRIFTC_IO_H
#define DRIFTC_IO_H

#include <driftc/types.h>

void print(const char *format, ...);
void println(const char *format, ...);

bool readln(char *buffer, usize capacity);

#endif
