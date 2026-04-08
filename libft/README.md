*This project has been created as part of the 42 curriculum by maherraz.*

## Description

*Libft* is a custom C library that reimplements a wide range of standard C library functions, along with additional utility functions and list management tools. This project serves as the foundation for many future 42 projects by providing a personal toolkit of essential functions.

*Goal:* To deepen understanding of C programming, memory management, string manipulation, and linked lists by rebuilding standard functions from scratch.

*Overview:*
The functions are divided into three logical parts:
- Standard Libc Functions

    These functions reproduce the exact behavior of the original functions found in the C standard library.
    | Function           | Description                                         |
    | -------------------| ----------------------------------------------------|
    | **ft_isalpha**     | Check for alphabetic character                      |
    | **ft_isdigit**     | Check for digit (0-9)                               |
    | **ft_isalnum**     | Check for alphanumeric character                    |
    | **ft_isascii**     | Check for ASCII character                           |
    | **ft_isprint**     | Check for printable character                       |
    | **ft_strlen**      | Calculate string length                             |
    | **ft_memset**      | Fill memory with a constant byte                    |
    | **ft_bzero**       | Zero a byte string                                  |
    | **ft_memcpy**      | Copy memory area                                    |
    | **ft_memmove**     | Copy memory area with overlap handling              |
    | **ft_strlcpy**     | Size-bounded string copying                         |
    | **ft_strlcat**     | Size-bounded string concatenation                   |
    | **ft_toupper**     | Convert char to uppercase                           |
    | **ft_tolower**     | Convert char to lowercase                           |
    | **ft_strchr**      | Locate character in string                          |
    | **ft_strrchr**     | Locate character in string (reverse)                |
    | **ft_strncmp**     | Compare two strings                                 |
    | **ft_memchr**      | Scan memory for a character                         |
    | **ft_memcmp**      | Compare memory areas                                |
    | **ft_strnstr**     | Locate a substring in a string                      |
    | **ft_atoi**        | Convert string to integer                           |
    | **ft_calloc**      | Allocate and zero-initialize memory                 |
    | **ft_strdup**      | Duplicate a string                                  |

    - Additional Functions

    Utility functions not present in the standard `libc`, but essential for C programming.

    | Function          | Description                                        |
    | ------------------| ---------------------------------------------------|
    | **ft_substr**     | Creates a substring from a given index.            |
    | **ft_strjoin**    | Merges two strings into a new allocated area.      |
    | **ft_strtrim**    | Trims specified characters from start and end.     |
    | **ft_split**      | Splits a string into an array using a delimiter.   |
    | **ft_itoa**       | Converts an integer into a string.                 |
    | **ft_strmapi**    | Applies a function to each character (new string). |
    | **ft_putchar_fd** | Writes a character to a given file descriptor.     |
    | **ft_striteri**   | Apply function to each char (in-place)             |
    | **ft_putstr_fd**  | Output string to file descriptor                   |
    | **ft_putendl_fd** | Output string + newline to fd                      |
    | **ft_putnbr_fd**  | Output integer to file descriptor                  |


    - Linked List Functions

    Functions for manipulating the `t_list` structure to manage dynamic data.

    | Function            |  Description                                |
    | --------------------|  -------------------------------------------|
    | **ft_lstnew**       |  Allocates a new node with content.         |
    | **ft_lstadd_front** |  Adds a node to the beginning of the list.  |
    | **ft_lstsize**      |  Counts the number of elements in the list. |
    | **ft_lstlast**      |  Returns the last element of the list.      |
    | **ft_lstadd_back**  |  Adds a node to the end of the list.        |
    | **ft_lstclear**     |  Deletes and frees the entire list.         |
    | **ft_lstiter**      |  Apply function to each node                |
    | **ft_lstmap**       |  Apply function and create new list         |
    | **ft_lstdelone**    |  Delete one node                            |

---

## Instructions

### Compilation

The project uses a **Makefile** to compile the source files into a static library named `libft.a`.

* **Compile the library:** `make`
* **Remove object files (.o):** `make clean`
* **Remove object files and the library (.a):** `make fclean`
* **Recompile the entire project:** `make re`

### Usage
To use this library in your C projects:
1. *Clone the repository:*
```bash
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-a185c5e2-3d96-4da0-8346-e2330c593f04-7286583-maherraz libft
cd libft
```

2. *Compile the library:*
```bash
make
```
This will generate a libft.a static library file.

3. *include the header file and link the library during the compilation process*:

```bash
#include "libft.h"
int main(void)
{
    char *str;
    
    str = ft_strdup("Hello 42!");
    ft_putendl_fd(str, 1);
    free(str);
    return (0);
}
```
4. *Compile your program with the library:*

    * If your program and libft are in the same directory
    ```Bash
    cc -Wall -Wextra -Werror your_program.c libft.a -o your_program
    ```
    * If libft is in a subfolder
    ```Bash
    cc -Wall -Wextra -Werror your_program.c -L./libft -lft -o your_program
    ```
5. *Run your program:*
```Bash
./your_program
```

### Project Structure
libft/
├── Makefile          # Compilation configuration
├── libft.h           # Header file with all prototypes
├── ft_*.c           # Function implementations
└── README.md        # This file
---

---

## Testing

To verify the library, you can use the `main_test.c` file or external testers.

### Option 1: Manual Testing

1. **Compile the test:**
```bash
cc -Wall -Wextra -Werror main_test.c libft.a -o test_runner

```

## Resources

* **Official Documentation:** Unix Manual Pages (`man 3 malloc`, `man 3 strlen`).
* **42 Norm:** [School style guide](https://github.com/42School/norminette).
- [Official GNU C Language Facilities in the Library)](https://sourceware.org/glibc/manual/2.43/html_mono/libc.html#Language-Features)
- [Official GNU Memory Allocation in C Programs](https://sourceware.org/glibc/manual/2.43/html_mono/libc.html#Unconstrained-Allocation)
- [Official GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)

### AI Usage Disclosure

In accordance with 42's policy on AI-assisted learning, AI tools were used as supplementary resources to deepen understanding, not to generate complete solutions. All code was written, tested, and debugged personally.
Artificial intelligence was utilized for the following tasks:

* **README Structuring:** Assistance in the logical organization of tables and sections.
* **ft_split Logic:** Guidance on managing memory allocation failures (freeing partial arrays).
* **Pedagogical Explanations:** Clarifying the difference between `t_list *` and `t_list **` in Part 3.
* **Code Review:** Validation of project standards and identifying unnecessary libraries in the header.

## Technical Choices

- *Norminette compliant:* Code follows 42's strict coding standard
- *No forbidden functions:* All functions written from scratch
- *Static library:* Compiled as libft.a for easy integration
- *Makefile automation:* Automatic compilation and dependency management
- *Memory safety:* Extensive NULL checks and boundary validation

---

### Testing

The library has been tested with:
- [Francinette](https://github.com/xicodomingues/francinette)
- [LibftTester](https://github.com/Tripouille/libftTester)