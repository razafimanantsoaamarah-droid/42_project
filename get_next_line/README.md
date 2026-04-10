*This project has been created as part
of the 42 curriculum by maherraz*

# GET_NEXT_LINE

## Description

`get_next_line` is a function that reads a line from a file descriptor, ending with a newline character (`\n`). It works with any buffer size defined at compile time (`-D BUFFER_SIZE=n`) and relies on a **static variable** to retain data between calls. This project is essential for later file/input parsing in C.

### Features

- Reads from files or standard input.
- Handles arbitrary `BUFFER_SIZE` (≥ 1).
- Manages memory efficiently (no leaks).
- Returns `NULL` on error or end‑of‑file.

## Instructions:

### Compilation

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

### Example `main.c`

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    int count = 1;

    if (fd == -1)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", count++, line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Execution

```bash
./gnl_test
```

## Algorithm Overview

1. **Accumulation**  
   Read chunks of `BUFFER_SIZE` bytes and append them to a static buffer (`save`) until a newline or EOF is reached.

2. **Extraction**  
   Copy the content from the start of `save` up to (and including) the first newline. This is the line to return.

3. **Update remainder**  
   Keep everything after the newline in the static buffer for the next call.

4. **Error handling**  
   On read error or allocation failure, free all allocated memory and return `NULL`.

## Functions & Their Roles

| Function          | Role                                                       |
|-------------------|------------------------------------------------------------|
| `get_next_line`   | Main controller: validates input, calls helpers, returns line. |
| `fill_save`       | Reads from `fd` and accumulates data until `\n` or EOF.   |
| `get_clean_line`  | Isolates the complete line from the static buffer.        |
| `get_new_save`    | Removes the returned line from the static buffer.         |
| `ft_strlen`       | Returns string length (handles `NULL`).                   |
| `ft_strchr`       | Searches for a character in a string.                     |
| `ft_strjoin`      | Concatenates two strings, freeing the first one.          |
| `ft_substr`       | Extracts a substring (safely handles out‑of‑range starts).|
| `ft_strdup`       | Duplicates a string.                                      |

## Key Concepts Explained (with AI assistance)

### Static Variables
- A `static` variable inside a function retains its value between calls.  
- Here, `static char *save` holds the leftover data after each line extraction.  
- **Example**:  
  ```c
  static int counter = 0;
  counter++;   // increments each time the function is called
  ```

### File Descriptors & `read()`
- A file descriptor is an integer (e.g., 0 = stdin, 1 = stdout, 2 = stderr).  
- `read(fd, buffer, size)` returns the number of bytes read (0 = EOF, -1 = error).

### Memory Management
- Every `malloc` must have a matching `free`.  
- Use **Valgrind** to detect leaks:
  ```bash
  valgrind --leak-check=full --show-leak-kinds=all ./gnl_test
  ```

### Buffer Size Flexibility
- `BUFFER_SIZE` is defined at compile time. The function must work correctly for any positive value (including 1 and very large numbers).

## Modifications Applied (based on code review)

- Removed duplicate `ft_strdup` prototype in `get_next_line.h`.
- Improved `fill_save` to avoid an unnecessary `ft_strjoin` when `read_bytes == 0`.
- Added safeguards against `NULL` pointers in utility functions.

## Resources

- **Man pages**: `man 2 read`, `man 3 malloc`, `man 3 free`
- **Static variables in C**: [GeeksforGeeks](https://www.geeksforgeeks.org/static-variables-in-c/)
- **File descriptors**: [Beej's Guide to Unix IPC](https://beej.us/guide/bgipc/html/multi/unixsock.html)
- **Valgrind tutorial**: [Valgrind Quick Start](https://valgrind.org/docs/manual/quick-start.html)
- **42 project guidelines**: [42 Network – get_next_line](https://cdn.intra.42.fr/pdf/pdf/96068/en.subject.pdf)

## AI Acknowledgment

This README and the conceptual explanations were produced with the help of an AI assistant (Claude/GPT) to deepen understanding of static variables, file I/O, and memory safety. All code remains the original author’s work; AI was used for debugging advice and documentation.