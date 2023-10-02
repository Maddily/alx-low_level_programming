#include "main.h"

/**
 * main - Displays the information contained in the ELF header
 * at the start of an ELF file.
 *
 * @argc: The number of arguments
 * @argv: A pointer to an array of pointers to arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	int fd, i;
	Elf64_Ehdr elfHeader;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot open file %s\n", argv[1]);
		exit(98);
	}
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}
	if (read(fd, &elfHeader, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		dprintf(STDERR_FILENO,
				"Error: Cannot read ELF header from file %s\n", argv[1]);
		close(fd);
		exit(98);
	}
	for (i = 0; i < SELFMAG; i++)
	{
		if (elfHeader.e_ident[i] != ELFMAG[i])
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			close(fd);
			exit(98);
		}
	}
	printf("ELF Header:\n");
	displayMagic(&elfHeader);
	displayFields(&elfHeader);
	close(fd);
	return (0);
}
/**
 * displayFields - Displays the fields after the magic field
 *
 * @elfHeader: A pointer to the elfHeader struct
 */
void displayFields(Elf64_Ehdr *elfHeader)
{
	printf("  Class:                             %s\n",
			(elfHeader->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
	printf("  Data:                              %s\n",
			(elfHeader->e_ident[EI_DATA] == ELFDATA2LSB ?
			 "2's complement, little endian" : "2's complement, big endian"));
	printf("  Version:                           %d\n",
			elfHeader->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
			displayOsAbi(elfHeader->e_ident[EI_OSABI]));
	printf("  ABI Version:                       %d\n",
			elfHeader->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
			displayType(elfHeader));
	printf("  Entry point address:               0x%lx\n",
			(unsigned long)elfHeader->e_entry);
}
/**
 * displayMagic - Display the magic information in the header
 *
 * @elfHeader: A pointer to the elfHeader struct
 */
void displayMagic(Elf64_Ehdr *elfHeader)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < SELFMAG; i++)
		printf("%02x ", elfHeader->e_ident[i]);
	printf("\n");
}
/**
 * displayType - Checks the type field in the header
 * @elfHeader: A pointer to the elfHeader struct
 *
 * Return: A pointer to the type
 */
char *displayType(Elf64_Ehdr *elfHeader)
{
	char *elfType;

	switch (elfHeader->e_type)
	{
	case ET_NONE:
		elfType = "NONE (Unknown)";
		break;
	case ET_REL:
		elfType = "REL (Relocatable file)";
		break;
	case ET_EXEC:
		elfType = "EXEC (Executable file)";
		break;
	case ET_DYN:
		elfType = "DYN (Shared object file)";
		break;
	case ET_CORE:
		elfType = "CORE (Core file)";
		break;
	default:
		elfType = "Unknown";
	}

	return (elfType);
}
/**
 * displayOsAbi - Checks the OS/ABI field in the header
 *
 * @osAbi: The OS/ABI field content
 *
 * Return: A pointer to a description of the OS/ABI field content
 */
char *displayOsAbi(unsigned char osAbi)
{
	switch (osAbi)
	{
	case ELFOSABI_SYSV:
		return ("UNIX - System V");
	case ELFOSABI_HPUX:
		return ("HP-UX");
	case ELFOSABI_NETBSD:
		return ("NetBSD");
	case ELFOSABI_LINUX:
		return ("Linux");
	case ELFOSABI_SOLARIS:
		return ("Solaris");
	case ELFOSABI_AIX:
		return ("AIX");
	case ELFOSABI_IRIX:
		return ("IRIX");
	case ELFOSABI_FREEBSD:
		return ("FreeBSD");
	case ELFOSABI_TRU64:
		return ("Tru64");
	case ELFOSABI_MODESTO:
		return ("Novell Modesto");
	case ELFOSABI_OPENBSD:
		return ("OpenBSD");
	case ELFOSABI_ARM:
		return ("ARM");
	case ELFOSABI_STANDALONE:
		return ("Standalone (embedded) application");
	default:
		printf("<unknown: %d>", osAbi);
		return ("");
	}
}
