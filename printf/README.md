*This project has been created as part of the 42 curriculum by maherraz*

## Description

**ft_printf** is a custom implementation of the standard C library function `printf`. This project aims to recreate the behavior of the original `printf` function, handling various format specifiers and returning the exact number of characters printed.
The function prototype is:
```c
int ft_printf(const char *format, ...);
```
### Supported Format Specifiers:
- `%c` - Prints a single character
- `%s` - Prints a string
- `%p` - Prints a pointer address in hexadecimal format
- `%d` - Prints a decimal (base 10) number
- `%i` - Prints an integer in base 10
- `%u` - Prints an unsigned decimal (base 10) number
- `%x` - Prints a number in hexadecimal (base 16) lowercase format
- `%X` - Prints a number in hexadecimal (base 16) uppercase format
- `%%` - Prints a percent sign

### Repository Structure
    .
    ├── Makefile           # Compilation rules
    ├── ft_printf.h        # Header file with prototypes
    ├── ft_printf.c        # Main function and dispatcher
    ├── ft_putchar.c       # Character printing
    ├── ft_putstr.c        # String printing
    ├── ft_putnbr.c        # Number printing (decimal)
    ├── ft_hexa.c          # Hexadecimal and pointer printing
    └── README.md          # This file

## Instructions

### Compilation

To compile the library, simply run:

```bash
make
```

This will generate a static library file `libftprintf.a`.

Available Makefile rules:
- `make all` - Compile the library
- `make clean` - Remove object files
- `make fclean` - Remove object files and the library
- `make re` - Recompile everything from scratch
- `make test` - Compile and run the test program (if test_ft_printf.c exists)

### Usage

Include the header in your C files:

```c
#include "ft_printf.h"
```

Link the library when compiling your program:

```bash
cc -o your_program your_program.c -L. -lftprintf
```

### Example

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    
    count = ft_printf("Hello %s, you are %d years old!\n", "Alice", 25);
    ft_printf("Printed %d characters\n", count);
    
    ft_printf("Char: %c\n", 'A');
    ft_printf("String: %s\n", "Hello World");
    ft_printf("Pointer: %p\n", &count);
    ft_printf("Decimal: %d\n", 123);
    ft_printf("Integer: %i\n", -456);
    ft_printf("Unsigned: %u\n", 789);
    ft_printf("Hex lowercase: %x\n", 255);
    ft_printf("Hex uppercase: %X\n", 255);
    ft_printf("Percent sign: %%\n");
    
    return (0);
}
```

## Algorithm and Data Structure Explanation

### Architecture Overview

The ft_printf implementation follows a modular architecture with clear separation of concerns:

```
ft_printf (main function)
    ↓
Parse format string
    ↓
ft_check_list (dispatcher)
    ↓
Individual printing functions (ft_putchar, ft_putstr, ft_putnbr, etc.)
```

### Key Design Decisions

#### 1. **Variadic Arguments Handling**
The project uses `<stdarg.h>` macros (`va_start`, `va_arg`, `va_end`) to handle the variable number of arguments. This is essential for mimicking the behavior of the original printf.

#### 2. **Modular Function Design**
Each format specifier has its dedicated printing function, making the code:
- **Maintainable**: Easy to add new format specifiers
- **Testable**: Each function can be tested independently
- **Reusable**: Functions can be used in other projects

#### 3. **Recursive Number Printing**
For numeric conversions (`%d`, `%i`, `%u`, `%x`, `%X`), a recursive approach is used:

```c
static int	ft_putnbr_base(long n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_base(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
```

**Advantages of recursion:**
- Clean and readable code
- Natural handling of digit extraction from most significant to least significant
- Automatic stack-based memory management

**Why not iteration?** While iteration could be used, recursion provides more elegant code for base conversion and automatically handles the correct order of digit printing without needing to reverse a string.

#### 4. **Counting Strategy**
The counting mechanism is crucial for returning the correct number of printed characters:

- **ft_putchar**: Returns 1 for each character written
- **Higher-level functions**: Sum the return values of their callees
- **No artificial +1 additions**: Each character is counted exactly once

This approach ensures that the total count is always accurate and matches the behavior of the original printf.

#### 5. **NULL Pointer Handling**
Special attention is given to edge cases:
- `NULL` strings are printed as `"(null)"`
- `NULL` pointers are printed as `"(nil)"`
- Empty strings are handled gracefully

### Data Flow

```
User calls ft_printf("%s %d", "Hello", 42)
    ↓
ft_printf iterates through format string
    ↓
'%' detected → ft_check_list called with 's'
    ↓
ft_check_list dispatches to ft_putstr("Hello")
    ↓
ft_putstr calls ft_putchar for each character, accumulating count
    ↓
Return to ft_printf, add to total count
    ↓
Continue parsing: space character printed via ft_putchar
    ↓
'%' detected → ft_check_list called with 'd'
    ↓
ft_check_list dispatches to ft_putnbr(42)
    ↓
ft_putnbr handles sign and calls ft_putnbr_base recursively
    ↓
Each digit printed via ft_putchar, counts accumulated
    ↓
Final total returned to user
```
## Resources

### Primary Documentation
- **[man 3 stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html)** - Official documentation for variadic functions (primary reference for va_list, va_start, va_arg, va_end)
- **man 3 printf** - Standard printf behavior reference

### Educational Resources Used

1. **Variadic Functions Understanding**:
   - Studied the stdarg.h documentation to understand how variable arguments work in C
   - Learned about stack layout and argument passing conventions
   - Understood why va_arg needs the type parameter

2. **Recursion Concepts**:
   - Studied recursive algorithms for number base conversion
   - Understood call stack behavior and return value propagation
   - Analyzed time complexity: O(log n) for number printing

3. **Format String Parsing**:
   - Researched how printf parses format strings
   - Understood the importance of handling edge cases (NULL, empty strings)

### AI Usage Disclosure
Artificial Intelligence was used as a supplementary learning tool:
1. **Concept Clarification**:
   - Helped explain the mechanics of va_list and why it must be used with va_start/va_end
   - Clarified recursion vs iteration trade-offs for number printing
   - Explained pointer casting for the %p specifier

2. **Debugging Assistance**:
   - Helped identify off-by-one errors in counting
   - Suggested proper handling of INT_MIN edge case
   - Assisted in understanding recursive return value accumulation

3. **Documentation Structure**:
   - Helped organize technical explanations
   - Assisted in creating clear algorithm descriptions

**Important Note**: All code was written, understood, and debugged by the author. AI was used strictly as a learning aid, similar to consulting documentation or tutorials, not to generate solutions without comprehension.

## Notes

- The function returns `-1` if the format string is `NULL`
- All printing is done using the `write` system call
- The library follows the 42 Norm coding standards
- No undefined behavior: edge cases are handled explicitly