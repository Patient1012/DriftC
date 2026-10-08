```
       __     _ ______      
  ____/ /____(_) __/ /______
 / __  / ___/ / /_/ __/ ___/
/ /_/ / /  / / __/ /_/ /__  
\__,_/_/  /_/_/  \__/\___/  
                            
```
A lightweight C library providing Drift-inspired types and utilities for C99.

`driftc` aims to make C more convenient to write while keeping the simplicity, control, and portability of standard C. It builds on existing C functionality rather than trying to replace the language.

## Features

* **Type aliases** — concise integer and floating-point types inspired by Drift.
* **Formatted output** — `print()` and `println()` with custom format specifiers.
* **Line input** — `readln()` for reading user input into a buffer.
* **C99 compatibility** — designed to work with C99-compatible compilers.

## Installation

Clone the repository:

```sh
git clone https://github.com/Patient1012/driftc.git
cd driftc
```

Build instructions will be added as the library's build system develops.

## Usage

Include the headers you need in your C source files.

```c
#include <driftc/types.h>
#include <driftc/io.h>

int main(void)
{
    i32 number = 42;
    f64 pi = 3.14159;

    println("Number: %i", number);
    println("Pi: %f", pi);

    char name[64];

    print("Enter your name: ");

    if (readln(name, sizeof name)) {
        println("Hello, %s!", name);
    }

    return 0;
}
```

## Types

`driftc/types.h` provides aliases for fixed-width integer types and floating-point types.

| Type   | Underlying C type |
| ------ | ----------------- |
| `i8`   | `int8_t`          |
| `i16`  | `int16_t`         |
| `i32`  | `int32_t`         |
| `i64`  | `int64_t`         |
| `ui8`  | `uint8_t`         |
| `ui16` | `uint16_t`        |
| `ui32` | `uint32_t`        |
| `ui64` | `uint64_t`        |
| `f32`  | `float`           |
| `f64`  | `double`          |

The integer aliases use the fixed-width types from `<stdint.h>`. These types are available when the implementation provides the corresponding exact-width integer type.

## Input and output

Include `driftc/io.h` to use the I/O functions.

### Functions

| Function    | Description                                          |
| ----------- | ---------------------------------------------------- |
| `print()`   | Prints formatted output without a trailing newline.  |
| `println()` | Prints formatted output followed by a newline.       |
| `readln()`  | Reads a line of input into a caller-provided buffer. |

### Format specifiers

| Specifier | Meaning                                                       |
| --------- | ------------------------------------------------------------- |
| `%i`      | Integer                                                       |
| `%f`      | Floating-point value                                          |
| `%s`      | String                                                        |
| `%c`      | Character                                                     |
| `%m`      | Memory address                                                |
| `%n`      | Reserved for variable-name formatting; implementation pending |
| `%%`      | Literal percent sign                                          |

Format specifiers must match the argument types expected by the implementation.

## Project structure

```text
driftc/
├── headers/
│   └── driftc/
│       ├── types.h
│       └── io.h
├── src/
│   └── io.c
├── tests/
├── examples/
├── Makefile
└── README.md
```

## Goals

The long-term goal of `driftc` is to provide a collection of useful C utilities and type aliases inspired by the design of Drift, without introducing a separate language or compiler.

Planned areas of development include:

* String utilities
* Dynamic arrays
* Memory management helpers
* Improved input and output
* Additional convenience types and functions

## Compatibility

The library targets C99. Compiler and platform compatibility will depend on the features used by each module.

## License

See [LICENSE](LICENSE) for licensing information.

