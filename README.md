*This project has been created as part of the 42 curriculum by rafcrist.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the standard C `printf()` function.

The goal of the project is to understand variadic functions, formatted output, type handling, recursive number conversion, and static-library creation. This implementation does not reproduce the original `printf()` buffering system; it focuses on the conversions required by the subject.

Supported conversions:

- `%c` — prints a character
- `%s` — prints a string
- `%p` — prints a `void *` address in hexadecimal
- `%d` — prints a signed decimal integer
- `%i` — prints a signed decimal integer
- `%u` — prints an unsigned decimal integer
- `%x` — prints a hexadecimal number using lowercase letters
- `%X` — prints a hexadecimal number using uppercase letters
- `%%` — prints a percent sign

The project produces the static library:

```text
libftprintf.a
```

## Algorithm and data structure

The format string is scanned from left to right.

1. When the current character is not `%`, it is written directly to standard output.
2. When `%` is found, the next character is interpreted as a conversion specifier.
3. A dispatcher selects the appropriate conversion function.
4. The next variadic argument is retrieved with `va_arg()` using the type required by that conversion.
5. Each helper function prints its value and returns the number of characters written.
6. `ft_printf()` accumulates those return values and returns the final character count.

Text conversions are handled by dedicated character and string functions. A null string is represented as `(null)`.

Signed decimal conversion handles the sign first and then prints the absolute value. A wider signed type is used internally so that the minimum `int` value can be processed safely.

Unsigned decimal and hexadecimal values are converted recursively. At each recursive step, the number is divided by the base. Digits are printed while the recursive calls return, which naturally produces the correct most-significant-to-least-significant order.

Pointer conversion prints `(nil)` for a null pointer. A valid pointer is printed with the `0x` prefix followed by its address in lowercase hexadecimal.

No custom linked list, array container, or dynamically allocated data structure is needed. The main data structure is `va_list`, which stores the state required to access the variable arguments. Constant strings are used as lookup tables for hexadecimal digits.

This design was chosen because it separates parsing, argument extraction, and output conversion. Each helper has one clear responsibility, making the implementation easier to test, explain, and extend.

## Instructions

### Compilation

Run:

```bash
make
```

This creates `libftprintf.a` at the root of the repository.

Available Makefile rules:

```bash
make
make all
make clean
make fclean
make re
```

- `all` builds the library.
- `clean` removes object files.
- `fclean` removes object files and `libftprintf.a`.
- `re` performs a complete rebuild.

### Usage

Create a test file such as:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Name: %s | Number: %d | Hex: %x\n", "42", 42, 42);
	return (0);
}
```

Compile it with the library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
```

Run:

```bash
./test
```

## Resources

Classic references used to study the project:

- `man 3 printf`
- `man 3 stdarg`
- `man 3 va_start`
- `man 3 va_arg`
- `man 3 write`
- C variadic functions: https://en.cppreference.com/w/c/variadic
- GNU `ar` documentation: https://sourceware.org/binutils/docs/binutils/ar.html

### AI usage

AI was used as a tutoring and code-review aid. It helped clarify variadic argument handling, `va_list` pointer usage, recursive number conversion, pointer-size differences between environments, Makefile rules, edge cases, testing strategy, and README organization.

The implementation was typed, tested, and revised by the author. AI suggestions were reviewed against the project subject, compiler diagnostics, and comparisons with the original `printf()` behavior rather than being accepted without verification.
