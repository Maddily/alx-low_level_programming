# Variadic functions

This directory contains a collection of variadic functions implemented in C. Each function
performs a specific task using a variable number of arguments.

## Task 0: Beauty is variable, ugliness is constant

This task involves writing a function that returns the sum of all its parameters.

### Prototype

```c
int sum_them_all(const unsigned int n, ...);
```

### Usage

* If `n == 0`, the function returns `0`.

### Example

```c
int main(void)
{
    int sum;

    sum = sum_them_all(2, 98, 1024);
    printf("%d\n", sum);    /*Output: 1122*/
    sum = sum_them_all(4, 98, 1024, 402, -1024);
    printf("%d\n", sum);    /*Output: 500*/
    return (0);
}
```

## Task 1: To be is to be the value of a variable

This task involves writing a function that prints numbers, followed by a new line.

### Prototype

```c
void print_numbers(const char *separator, const unsigned int n, ...);
```

### Usage

* `separator` is the string to be printed between numbers.
* `n` is the number of integers passed to the function.
* If `separator` is NULL, it doesn't print it.

### Example

```c
int main(void)
{
    print_numbers(", ", 4, 0, 98, -1024, 402);	/*Output: 0, 98, -1024, 402*/
    return (0);
}
```

## Task 2: One woman's constant is another woman's variable

This task involves writing a function that prints strings, followed by a new line.

### Prototype

```c
void print_strings(const char *separator, const unsigned int n, ...);
```

### Usage

* `separator` is the string to be printed between the strings.
* `n` is the number of strings passed to the function.
* If `separator` is NULL, it doesn't print it.
* If one of the string is NULL, it prints "(nil)" instead.

### Example

```c
int main(void)
{
    print_strings(", ", 2, "Jay", "Django");	/*Output: Jay, Django*/
    return (0);
}
```

## Task 3: To be is a to be the value of a variable

This task involves writing a function that prints anything.

### Prototype

```c
void print_all(const char * const format, ...);
```

### Usage

* `format` is a list of types of arguments passed to the function.
	* `c`: `char`
	* `i`: `integer`
	* `f`: `float`
	* `s`: `char *` (If the string is NULL, it prints "(nil)" instead).
	* Any other character is ignored.
	* You are not allowed to use `for`, `goto`, ternary operator, `else` and `do ... while`.
	* You can use a maximum of two `while` loops and two `if`.
	* You can declare a maximum of 9 variables.

### Example

```c
int main(void)
{
    print_all("ceis", 'B', 3, "stSchool");  /*Output: B, 3, stSchool*/
    return (0);
}
```
