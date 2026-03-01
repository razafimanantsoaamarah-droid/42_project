*This project has been created as part of the 42 curriculum by maherraz*

# ft_printf - 42 Project

## 📋 Description

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

## 🚀 Instructions

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

## 🧠 Algorithm and Data Structure Explanation

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

## 📚 Resources

### Documentation
- **man 3 printf** - The official manual page for printf
- **man 3 stdarg** - Documentation for variadic functions
- **42 Network Subject** - Project requirements and specifications

### Articles and Tutorials
- [Beej's Guide to Variadic Functions](https://beej.us/guide/bgc/html/split/variadic-functions.html)
- [The GNU C Library: Variable Arguments](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [Understanding printf by re-implementing it](https://www.maizure.org/projects/printf/)

### Reference Implementations
- Original printf source code (various Unix implementations)
- Other 42 students' ft_printf projects (for learning purposes only)

### AI Usage Disclosure

Artificial Intelligence was used as a learning aid and debugging tool throughout this project:

1. **Understanding Concepts**: AI helped explain variadic functions, the va_list macros, and recursion in base conversion.

2. **Debugging Assistance**: When encountering counting errors (off-by-one issues), AI helped trace the problem through the call stack and identify inconsistent return values.

3. **Code Optimization**: AI suggested improvements for the recursive counting mechanism to ensure consistency across all format specifiers.

4. **Test Case Generation**: AI assisted in creating comprehensive test cases to verify the function against edge cases (INT_MIN, NULL pointers, empty strings, etc.).

5. **Documentation**: AI helped structure this README and articulate the algorithm choices.

**All code was written and understood by the author**. AI was used strictly as a supplementary learning tool and not to generate complete solutions without comprehension.

## ✅ Testing

The project has been tested with:
- **Tripouille's printfTester** - All mandatory tests pass
- Custom test suite covering edge cases
- Comparison with original printf for identical output and return values

## 📁 Repository Structure

```
.
├── Makefile           # Compilation rules
├── ft_printf.h        # Header file with prototypes
├── ft_printf.c        # Main function and dispatcher
├── ft_putchar.c       # Character printing
├── ft_putstr.c        # String printing
├── ft_putnbr.c        # Number printing (decimal)
├── ft_hexa.c          # Hexadecimal and pointer printing
└── README.md          # This file
```

## ⚠️ Notes

- The function returns `-1` if the format string is `NULL`
- All printing is done using the `write` system call
- The library follows the 42 Norm coding standards
- No undefined behavior: edge cases are handled explicitly

---