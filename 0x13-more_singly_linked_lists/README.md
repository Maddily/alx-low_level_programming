# C - Singly linked lists

## Description

This project includes tasks that require the use of singly linked lists.

## Requirements

* Global variables aren't allowed.
* No more than 5 functions per file.
* The only C standard library functions allowed are malloc, free and exit.

## Tasks

### Task 0

This task involves writing a function that prints all of the elements of a `listint_t` list.

#### Usage

* The function returns the number of nodes in the list.
* Using printf is allowed.

#### Example

```c
int main(void)
{
    listint_t *head;
    listint_t *new;
    listint_t hello = {8, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(listint_t));
    if (new == NULL)
    {
        printf("Error\n");
        return (1);
    }
    new->n = 9;
    new->next = head;
    head = new;
    n = print_listint(head);
    printf("-> %lu elements\n", n);
    free(new);
    return (0);
}
```

##### Output

9
8
-> 2 elements

### Task 1

This task involves writing a function that returns the number of nodes in a `listint_t` list.

#### Example

```c
int main(void)
{
    listint_t *head;
    listint_t *new;
    listint_t hello = {8, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(listint_t));
    if (new == NULL)
    {
        printf("Error\n");
        return (1);
    }
    new->n = 9;
    new->next = head;
    head = new;
    n = listint_len(head);
    printf("-> %lu elements\n", n); /*Output: -> 2 elements*/
    free(new);
    return (0);
}
```

### Task 2

This task involves writing a function that adds a new node at the beginning of a `listint_t` list.

#### Usage

* The function returns the address of the new node or `NULL` on failure.

#### Example

```c
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 4);
    add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    print_listint(head);
    return (0);
}
```

##### Output

1024
402
98
4
3
2
1
0

### Task 3

This task involves writing a function that adds a new node at the end of a `listint_t` list.

#### Usage

* The function returns the address of the new node or `NULL` on failure.

#### Example

```c
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    return (0);
}
```

##### Output

0
1
2
3
4
98
402
1024

### Task 4

This task involves writing a function that frees a `listint_t` list.

### Task 5

This task involves writing a function that frees a `listint_t` list.

#### Usage

* The function sets the `head` to `NULL`.

### Task 6

This task involves writing a function that deletes the first node of a list and returns the first node's data.

#### Usage

* The function returns 0 if the list is empty.

### Task 7

This task involves writing a function that returns the data of the nth node of a list.

#### Usage

* Prototype: `listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);`
* `index` is the index of the node, starting at 0.
* The function returns `NULL` if the node doesn't exist.

#### Example

```c
int main(void)
{
    listint_t *head;
    listint_t *node;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    node = get_nodeint_at_index(head, 5);
    printf("%d\n", node->n);
    print_listint(head);
    free_listint2(&head);
    return (0);
}
```

##### Output

0
1
2
3
4
98
402
1024
98
0
1
2
3
4
98
402
1024

### Task 8

This task involves writing a function that returns the sum of all of the data in a list.

#### Usage

* The function returns `0` if the list is empty.

#### Example

```c
int main(void)
{
    listint_t *head;
    int sum;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    sum = sum_listint(head);
    printf("sum = %d\n", sum); /*Output: sum = 1534*/
    free_listint2(&head);
    return (0);
}
```

### Task 9

This task involves writing a function that inserts a new node at a given position.

#### Usage

* Prototype: `listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);`
* `idx` is the index of the list where the new node should be added. Indices start at `0`.
* The function returns the address of the new node, or `NULL` on failure.
* If it's not possible to add the new node at index `idx`, return `NULL`.

#### Example

```c
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    printf("-----------------\n");
    insert_nodeint_at_index(&head, 5, 4096);
    print_listint(head);
    free_listint2(&head);
    return (0);
}
```

##### Output

0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
4096
98
402
1024

### Task 10

This task involves writing a function that deletes the node in a list at a given index.

#### Usage

* Prototype: `int delete_nodeint_at_index(listint_t **head, unsigned int index);`
* `index` is the index of the node that should be deleted. Indices start at `0`.
* The function returns `1` on success, `-1` on failure.

### Task 11

This task involves writing a function that reverses a list.

#### Usage

* The function returns a pointer to the first node of the reversed list.
* A maximum of one loop can be used.
* Using `malloc`, `free` and arrays are not allowed.
* A maximum of two variables can be declared in the function.

### Task 12

This task involves writing a function that prints a list.

#### Usage

* The function returns the number of nodes in the list.
* The function can print a list using a loop.
* You should go through the list only once.
* On failure, exit with a status of 98.

#### Example

```c
int main(void)
{
    listint_t *head;
    listint_t *head2;
    listint_t *node;

    head2 = NULL;
    add_nodeint(&head2, 0);
    add_nodeint(&head2, 1);
    add_nodeint(&head2, 2);
    add_nodeint(&head2, 3);
    add_nodeint(&head2, 4);
    add_nodeint(&head2, 98);
    add_nodeint(&head2, 402);
    add_nodeint(&head2, 1024);
    print_listint_safe(head2);
    head = NULL;
    node = add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 4);
    node->next = add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    print_listint_safe(head);
    return (0);
}
```

##### Output

[0x1b500f0] 1024
[0x1b500d0] 402
[0x1b500b0] 98
[0x1b50090] 4
[0x1b50070] 3
[0x1b50050] 2
[0x1b50030] 1
[0x1b50010] 0
[0x1b50600] 1024
[0x1b505e0] 402
[0x1b505c0] 98
[0x1b505a0] 4
[0x1b50580] 3
[0x1b50560] 2
[0x1b50540] 1
[0x1b50110] 0
-> [0x1b505c0] 98

### Task 13

This task involves writing a function that frees a list.

#### Usage

* The function can free a list using a loop.
* You should go through the list only once.
* The function returns the size of the list that was freed.
* The function sets `head` to NULL.

#### Example

```c
int main(void)
{
    listint_t *head;
    listint_t *head2;
    listint_t *node;

    head2 = NULL;
    add_nodeint(&head2, 0);
    add_nodeint(&head2, 1);
    add_nodeint(&head2, 2);
    add_nodeint(&head2, 3);
    add_nodeint(&head2, 4);
    add_nodeint(&head2, 98);
    add_nodeint(&head2, 402);
    add_nodeint(&head2, 1024);
    print_listint_safe(head2);
    head = NULL;
    node = add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 4);
    node->next = add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    print_listint_safe(head);
    free_listint_safe(&head2);
    free_listint_safe(&head);
    printf("%p, %p\n", (void *)head2, (void *)head);
    return (0);
}
```

##### Output

[0x11260f0] 1024
[0x11260d0] 402
[0x11260b0] 98
[0x1126090] 4
[0x1126070] 3
[0x1126050] 2
[0x1126030] 1
[0x1126010] 0
[0x1126600] 1024
[0x11265e0] 402
[0x11265c0] 98
[0x11265a0] 4
[0x1126580] 3
[0x1126560] 2
[0x1126540] 1
[0x1126110] 0
-> [0x11265c0] 98
(nil), (nil)

### Task 14

This task involves writing a function that finds the loop in a linked list.

#### Usage

* The function returns the address of the node where the loop starts, or `NULL` if there' no loop.
* Using `malloc`, `free` and arrays isn't allowed.
* A maximum of two variables can be declared in the function.

#### Example

```c
int main(void)
{
    listint_t *head;
    listint_t *head2;
    listint_t *node;

    head2 = NULL;
    add_nodeint(&head2, 0);
    add_nodeint(&head2, 1);
    add_nodeint(&head2, 2);
    add_nodeint(&head2, 3);
    add_nodeint(&head2, 4);
    add_nodeint(&head2, 98);
    add_nodeint(&head2, 402);
    add_nodeint(&head2, 1024);
    print_listint_safe(head2);
    node = find_listint_loop(head2);
    if (node != NULL)
    {
        printf("Loop starts at [%p] %d\n", (void *)node, node->n);
    }
    free_listint_safe(&head2);
    head = NULL;
    node = add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 4);
    add_nodeint(&head, 5);
    add_nodeint(&head, 6);
    node->next = add_nodeint(&head, 7);
    add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    print_listint_safe(head);
    node = find_listint_loop(head);
    if (node != NULL)
    {
        printf("Loop starts at [%p] %d\n", (void *)node, node->n);
    }
    free_listint_safe(&head);
    return (0);
```

##### Output

[0x13700f0] 1024
[0x13700d0] 402
[0x13700b0] 98
[0x1370090] 4
[0x1370070] 3
[0x1370050] 2
[0x1370030] 1
[0x1370010] 0
[0x1370560] 1024
[0x1370540] 402
[0x1370010] 98
[0x1370030] 7
[0x1370050] 6
[0x1370070] 5
[0x1370090] 4
[0x13700b0] 3
[0x13700d0] 2
[0x13700f0] 1
[0x1370110] 0
-> [0x1370030] 7
Loop starts at [0x1370030] 7
