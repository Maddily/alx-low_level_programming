# C - Bit manipulation

## Description

This project includes tasks that use bitwise operators to manipulate bits.

## Tasks

### Task 0

This task involves writing a function that converts a binary number to an unsigned int.

#### Usage

* The function returns the converted number or `0` if:
	* There's one or more characters in the string that isn't `0` or `1`.
	* The string containing the binary number is `NULL`.

#### Example

```c
int main(void)
{
    unsigned int n;

    n = binary_to_uint("1");
    printf("%u\n", n);
    n = binary_to_uint("101");
    printf("%u\n", n);
    n = binary_to_uint("1e01");
    printf("%u\n", n);
    n = binary_to_uint("1100010");
    printf("%u\n", n);
    n = binary_to_uint("0000000000000000000110010010");
    printf("%u\n", n);
    return (0);
}
```

##### Output

1
5
0
98
402

### Task 1

This task involves writing a function that prints the binary representation of a number.

#### Usage

* Arrays aren't allowed.
* `malloc` isn't allowed.
* `%` and `/` operators aren't allowed.

#### Example

```c
int main(void)
{
    print_binary(0);
    printf("\n");
    print_binary(1);
    printf("\n");
    print_binary(98);
    printf("\n");
    print_binary(1024);
    printf("\n");
    print_binary((1 << 10) + 1);
    printf("\n");
    return (0);
}
```

##### Output

0
1
1100010
10000000000
10000000001

### Task 2

This task involves writing a function that returns the value of a bit at a given index.

#### Usage

* The function returns the value or `-1` in case of an error.

#### Example

```c
int main(void)
{
    int n;

    n = get_bit(1024, 10);
    printf("%d\n", n);
    n = get_bit(98, 1);
    printf("%d\n", n);
    n = get_bit(1024, 0);
    printf("%d\n", n);
    return (0);
}
```

##### Output

1
1
0

### Task 3

This task involves writing a function that sets the value of a bit to `1` at a given index.

#### Usage

* The function returns `1` on success, `-1` on failure.

#### Example

```c
int main(void)
{
    unsigned long int n;

    n = 1024;
    set_bit(&n, 5);
    printf("%lu\n", n);
    n = 0;
    set_bit(&n, 10);
    printf("%lu\n", n);
    n = 98;
    set_bit(&n, 0);
    printf("%lu\n", n);
    return (0);
}
```

##### Output

1056
1024
99

### Task 4

This task involves writing a function that sets the value of a bit to `0` at a given index.

#### Usage

* The function returns `1` on success, `-1` on failure.

#### Example

```c
int main(void)
{
    unsigned long int n;

    n = 1024;
    clear_bit(&n, 10);
    printf("%lu\n", n);
    n = 0;
    clear_bit(&n, 10);
    printf("%lu\n", n);
    n = 98;
    clear_bit(&n, 1);
    printf("%lu\n", n);
    return (0);
}
```

##### Output

0
0
96

### Task 5

This task involves writing a function that returns the number of bits you would need to flip to get from one number to another.

#### Usage

* `%` and `/` operators aren't allowed.

#### Example

```c
int main(void)
{
    unsigned int n;

    n = flip_bits(1024, 1);
    printf("%u\n", n);
    n = flip_bits(402, 98);
    printf("%u\n", n);
    n = flip_bits(1024, 3);
    printf("%u\n", n);
    n = flip_bits(1024, 1025);
    printf("%u\n", n);
    return (0);
}
```

##### Output

2
5
3
1

### Task 6

This task involves writing a function that checks the endianness.

#### Usage

* The function returns `0` if big endian or `1` if little endian.

#### Example

```c
int main(void)
{
    int n;

    n = get_endianness();
    if (n != 0)
    {
        printf("Little Endian\n");
    }
    else
    {
        printf("Big Endian\n");
    }
    return (0);
}
```

##### Output

Little Endian

### Task 7

This task involves finding the password for a program.
