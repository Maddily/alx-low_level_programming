# C - File I/O

## Description

This project includes tasks about the use of file descriptors and file i/o system calls.

## Tasks

### Task 0

This task involves writing a function that reads a text file and prints it to the `POSIX` standard output.

#### Usage

* Prototype: `ssize_t read_textfile(const char *filename, size_t letters);`
	* `letters`: The number of letters it should read and print.
* The function returns the actual number of letters it could read and print.
* The function returns `0` if the file can't be opened or read, or if `filename` is `NULL`, or in case `write` fails or doesn't write the expected number of bytes.

### Task 1

This task involves writing a function that creates a file.

#### Usage

* Prototype: `int create_file(const char *filename, char *text_content);`
	* `filename`: The name of the file to create.
	* `text_content`: A null-terminated string to write to the file.
* The function returns `1` on success. `-1` on failure (file can not be created, file can not be written, write “fails”, etc…).
* The created file must have these permissions: `rw-------`. If the file already exists, do not change its permissions.
* The function truncates the file if it already exists.
* The function returns `-1` if `filename` is `NULL`.
* The function creates an empty file if `text_content` is `NULL`.

### Task 2

This task involves writing a function that appends text at the end of a file.

#### Usage

* Prototype: `int append_text_to_file(const char *filename, char *text_content);`
	* `filename`: The name of the file.
	* `text_content`: The null-terminated string to append to the file.
* The function returns `1` on success, `-1` on failure.
* The function doesn't create the file if it doesn't already exist.
* The function returns `-1` if `filename` is `NULL`.
* The function doesn't add anything to the file if `text_content` is `NULL`.
* The function returns `1` if the file exists and `-1` if the file does not exist or if you do not have the required permissions to write to the file.

### Task 3

This task involves writing a program that copies the content of a file into another file.

#### Usage

* `cp file_from file_to`
* If the number of argument is not the correct one, exit with code `97` and print Usage: `cp file_from file_to`, followed by a new line, on the `POSIX` standard error.
* If `file_to` already exists, truncate it.
* If `file_from` does not exist, or if you can not read it, exit with code `98` and print `Error: Can't read from file NAME_OF_THE_FILE`, followed by a new line, on the `POSIX` standard error.
	* `NAME_OF_THE_FILE`: The  first argument passed to the program.
* If you can not create or if `write` to `file_to` fails, exit with code `99` and print `Error: Can't write to NAME_OF_THE_FILE`, followed by a new line, on the `POSIX` standard error.
	* `NAME_OF_THE_FILE`: The second argument passed to the program.
* If you can not close a file descriptor, exit with code `100` and print `Error: Can't close fd FD_VALUE`, followed by a new line, on the `POSIX` standard error.
	* `FD_VALUE`: The value of the file descriptor.
* Permissions of the created file are: `rw-rw-r--`. If the file already exists, do not change its permissions.
* You must read `1,024` bytes at a time from the `file_from` to make less system calls. Use a buffer.

### Task 4

This task involves writing a program that displays the information contained in the `ELF` header at the start of an `ELF` file.

#### Usage

* `elf_header elf_filename`
* Displayed information: (no less, no more, do not include trailing whitespace)
	* Magic
	* Class
	* Data
	* Version
	* OS/ABI
	* ABI Version
	* Type
	* Entry point address
* Format: The same as `readelf -h` (version `2.26.1`)
* If the file is not an `ELF` file, or on error, the program exits with status code `98` and display a comprehensive error message to `stderr`.
* You are allowed to use `lseek` once.
* You are allowed to use `read` a maximum of 2 times at runtime.
