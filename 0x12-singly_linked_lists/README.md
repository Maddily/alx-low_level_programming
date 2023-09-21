# C - Singly linked lists

## Description

This project includes tasks that require the use of singly linked lists.

## Tasks

### Task 0

This task involves writing a function that prints all the elements of a `list_t` list.

#### Usage

* The function returns the number of nodes in the list.
* If `str` is NULL, the function prints `[0] (nil)`.

#### File Name

`0-print_list.c`

#### Example

```c
int main(void)
{
    list_t *head;
    list_t *new;
    list_t hello = {"World", 5, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(list_t));
    if (new == NULL)
    {
        printf("Error\n");
        return (1);
    }
    new->str = strdup("Hello");
    new->len = 5;
    new->next = head;
    head = new;
    n = print_list(head); /*Output: [5] Hello \n [5] World*/
    printf("-> %lu elements\n", n); /*Output: -> 2 elements*/

    printf("\n");
    free(new->str);
    new->str = NULL;
    n = print_list(head); /*Output: [0] (nil) \n [5] World*/
    printf("-> %lu elements\n", n); /*Output: -> 2 elements*/

    free(new);
    return (0);
}
```

### Task 1

This task involves writing a function that returns the number of elements in a `list_t` list.

#### File Name

1-list_len.c

#### Example

```c
int main(void)
{
    list_t *head;
    list_t *new;
    list_t hello = {"World", 5, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(list_t));
    if (new == NULL)
    {
        printf("Error\n");
        return (1);
    }
    new->str = strdup("Hello");
    new->len = 5;
    new->next = head;
    head = new;
    n = list_len(head);
    printf("-> %lu elements\n", n); /*Output: -> 2 elements*/
    free(new->str);
    free(new);
    return (0);
}
```

### Task 2

This task involves writing a function that adds a new node at the beginning of a `list_t` list.

#### Usage

* The function returns the address of the new node, or `NULL` on failure.
* `str` needs to be duplicated.

#### File Name

2-add_node.c

#### Example

```c
int main(void)
{
    list_t *head;

    head = NULL;
    add_node(&head, "Alexandro");
    add_node(&head, "Asaia");
    add_node(&head, "Augustin");
    add_node(&head, "Bennett");
    add_node(&head, "Bilal");
    add_node(&head, "Chandler");
    add_node(&head, "Damian");
    add_node(&head, "Daniel");
    add_node(&head, "Dora");
    add_node(&head, "Electra");
    add_node(&head, "Gloria");
    add_node(&head, "Joe");
    add_node(&head, "John");
    add_node(&head, "John");
    add_node(&head, "Josquin");
    add_node(&head, "Kris");
    add_node(&head, "Marine");
    add_node(&head, "Mason");
    add_node(&head, "Praylin");
    add_node(&head, "Rick");
    add_node(&head, "Rick");
    add_node(&head, "Rona");
    add_node(&head, "Siphan");
    add_node(&head, "Sravanthi");
    add_node(&head, "Steven");
    add_node(&head, "Tasneem");
    add_node(&head, "William");
    add_node(&head, "Zee");
    print_list(head);
    return (0);
}
```
##### Output

[3] Zee
[7] William
[7] Tasneem
[6] Steven
[9] Sravanthi
[6] Siphan
[4] Rona
[4] Rick
[4] Rick
[7] Praylin
[5] Mason
[6] Marine
[4] Kris
[7] Josquin
[4] John
[4] John
[3] Joe
[6] Gloria
[7] Electra
[4] Dora
[6] Daniel
[6] Damian
[8] Chandler
[5] Bilal
[7] Bennett
[8] Augustin
[5] Asaia
[9] Alexandro

### Task 3

This task involves writing a function that adds a new node at the end of a `list_t` list.

#### Usage

* The function returns the address of the new node, or NULL on failure.
* `str` needs to be duplicated

#### File Name

3-add_node_end.c

#### Example

```c
int main(void)
{
    list_t *head;

    head = NULL;
    add_node_end(&head, "Anne");
    add_node_end(&head, "Colton");
    add_node_end(&head, "Corbin");
    add_node_end(&head, "Daniel");
    add_node_end(&head, "Danton");
    add_node_end(&head, "David");
    add_node_end(&head, "Gary");
    add_node_end(&head, "Holden");
    add_node_end(&head, "Ian");
    add_node_end(&head, "Ian");
    add_node_end(&head, "Jay");
    add_node_end(&head, "Jennie");
    add_node_end(&head, "Jimmy");
    add_node_end(&head, "Justin");
    add_node_end(&head, "Kalson");
    add_node_end(&head, "Kina");
    add_node_end(&head, "Matthew");
    add_node_end(&head, "Max");
    add_node_end(&head, "Michael");
    add_node_end(&head, "Ntuj");
    add_node_end(&head, "Philip");
    add_node_end(&head, "Richard");
    add_node_end(&head, "Samantha");
    add_node_end(&head, "Stuart");
    add_node_end(&head, "Swati");
    add_node_end(&head, "Timothy");
    add_node_end(&head, "Victor");
    add_node_end(&head, "Walton");
    print_list(head);
    return (0);
}
```

##### Output

[4] Anne
[6] Colton
[6] Corbin
[6] Daniel
[6] Danton
[5] David
[4] Gary
[6] Holden
[3] Ian
[3] Ian
[3] Jay
[6] Jennie
[5] Jimmy
[6] Justin
[6] Kalson
[4] Kina
[7] Matthew
[3] Max
[7] Michael
[4] Ntuj
[6] Philip
[7] Richard
[8] Samantha
[6] Stuart
[5] Swati
[7] Timothy
[6] Victor
[6] Walton

### Task 4

This task involves writing a function that frees a `list_t` list.

#### File Name

4-free_list.c

#### Example

```c
int main(void)
{
    list_t *head;

    head = NULL;
    add_node_end(&head, "Bob");
    add_node_end(&head, "&");
    add_node_end(&head, "Kris");
    add_node_end(&head, "love");
    add_node_end(&head, "asm");
    print_list(head);
    free_list(head);
    head = NULL;
    return (0);
}
```

### Task 5

This task involves writing a function that prints `You're beat! and yet, you must allow,\nI bore my house upon my back!\n` before the main function is executed.

#### File Name

100-first.c

#### Example

```c
int main(void)
{
    printf("(A tortoise, having pretty good sense of a hare's nature, challenges one to a race.)\n");
    return (0);
}
```

##### Output

You're beat! and yet, you must allow,
I bore my house upon my back!
(A tortoise, having pretty good sense of a hare's nature, challenges one to a race.)

### Task 6

This task involves writing a 64-bit program in assembly that prints `Hello, Holberton` followed by a new line.

#### Usage

* You are only allowed to use the printf function.
* You are not allowed to use interrupts.
* The program will be compiled using nasm and gcc.

#### File Name

101-hello_holberton.asm

## Compilation and Testing

All files are compiled using `gcc` with the options `-Wall -Werror -Wextra -pedantic -std=gnu89`.

## Author

Mayada Saeed

[`GitHub`](https://github.com/Maddily)
[`LinkedIn`](https://www.linkedin.com/in/mayadase/)
