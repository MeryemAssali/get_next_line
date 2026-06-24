*This project has been created as part of the 42 curriculum by <mel_assa>.*

# get_next_line

## Description

The goal of this project is to implement a function called `get_next_line` that reads and returns one line at a time from a file descriptor.

Instead of reading an entire file into memory, the function reads the file incrementally using a fixed-size buffer. Since a line may be split across multiple reads, the implementation stores any unused characters between function calls and continues processing them later.

This project introduces several important concepts in systems programming, including file descriptors, static variables, dynamic memory allocation, buffer management, and incremental file reading.

### Learning Objectives

Through this project, I learned how to:

* Read files incrementally using `read()`
* Work with file descriptors
* Manage dynamically allocated memory
* Handle partial reads and buffers
* Preserve state between function calls using static variables
* Process input efficiently without loading an entire file into memory

---

# Instructions

## Files Submitted

The project consists of the following files:

* `get_next_line.c`
* `get_next_line_utils.c`
* `get_next_line.h`
* `README.md`

## Compilation

Compile with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

The project must work with any valid buffer size.

Examples:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c
```

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1000 get_next_line.c get_next_line_utils.c main.c
```

## Function Prototype

```c
char *get_next_line(int fd);
```

## Return Values

The function returns:

* The next line from the file, including the terminating `\n` when present.
* The remaining characters if EOF is reached without a final newline.
* `NULL` when there is nothing left to read or when an error occurs.

## Project Rules

* Language: C
* Allowed functions: `read`, `malloc`, `free`
* No global variables
* No use of `lseek`
* Must work with files and standard input
* Must work with any valid `BUFFER_SIZE`
* Undefined behavior is expected when:

  * The file is modified while it is being read before EOF is reached.
  * A binary file is used as input.

---

# Algorithm

The implementation is based on a static string called `leftover`.

The purpose of `leftover` is to store characters that have already been read from the file descriptor but have not yet been returned to the caller.

Without a static variable, any unused characters would be lost when the function returns, making it impossible to continue reading the file correctly during the next call.

## Algorithm Overview

1. Check whether the static leftover string already contains a complete line.
2. If no complete line exists, continue reading from the file descriptor into a temporary buffer.
3. Append newly read data to the leftover string.
4. Stop reading as soon as a newline character is found or EOF is reached.
5. Extract the next line from the leftover string.
6. Update the leftover string by removing the returned line.
7. Return the extracted line.

## Data Flow

```text
read() -> buffer -> append to leftover -> extract line -> update leftover
```

## Why This Algorithm?

The project requires reading as little as possible from the file descriptor.

Consider the following file:

```text
Hello
World
```

Assume:

```text
BUFFER_SIZE = 10
```

A single call to `read()` might return:

```text
Hello
Wor
```

The function should immediately return:

```text
Hello\n
```

while preserving:

```text
Wor
```

for the next call.

The static leftover string makes this possible by storing already-read but unused characters between function calls.

This approach satisfies the project requirements because:

* The file is read incrementally.
* No unnecessary reads are performed.
* Memory usage remains efficient.
* The function works correctly regardless of the chosen `BUFFER_SIZE`.

---

# Technical Implementation

The project is organized around four core functions.

## extract_line()

Creates a new string containing the next complete line from the leftover data.

## update_leftover()

Removes the returned line from the leftover string and keeps only the unused characters.

## read_and_concatenate()

Reads from the file descriptor and appends newly read data to the leftover string until either a newline character or EOF is encountered.

## get_next_line()

Coordinates the entire process and serves as the public interface exposed to the user.

---

# Notes

## File Descriptors

A file descriptor is a non-negative integer assigned by the operating system to an open file.

The file descriptor identifies the file and keeps track of the current reading position.

## Static Variables

A static variable keeps its value between function calls.

In this project, the static variable is used to remember any leftover characters that were already read but not yet returned.

## EOF Detection

EOF is detected when:

```c
read(fd, buffer, BUFFER_SIZE) == 0
```

The static leftover string is not used to detect EOF.

## Buffer Size

`BUFFER_SIZE` determines how many bytes `read()` attempts to read at a time.

```c
read(fd, buffer, BUFFER_SIZE);
```

* `buffer` stores the newly read data.
* `BUFFER_SIZE` specifies the maximum number of bytes to read.

The implementation must behave correctly regardless of the chosen value.

---

# Resources

## References

* 42 get_next_line subject
* Linux `read(2)` manual page
* Linux file descriptor documentation
* Discussions with 42 peers
* GitHub repositories used for general reference and comparison

## AI Usage

ChatGPT was used as a learning aid during the development of this project.

Specifically, it was used to:

* Clarify concepts related to file descriptors
* Explain the role of static variables in preserving state
* Discuss algorithm design choices
* Review edge cases and expected behavior
* Assist with debugging and interpreting compiler errors
* Improve understanding of memory management and buffer handling

All code was ultimately written, tested, and integrated by me.
