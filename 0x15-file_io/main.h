#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <elf.h>

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _strlen(char *s);
void closeAndCheck(int fdFrom, int fdTo);
void exit99(int fdFrom, int fdTo, char *fileTo);
void displayMagic(Elf64_Ehdr *elfHeader);
char *displayType(Elf64_Ehdr *elfHeader);
char *displayOsAbi(unsigned char osAbi);
void displayFields(Elf64_Ehdr *elfHeader);

#endif
