#include "main.h"
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * is_elf - checks if a file is an ELF file
 * @filename: the file to check
 * Return: True if ELF file, or false if otherwise
 */

bool is_elf(const char *filename)
{
	int fd;
	ssize_t n;
	Elf64_Ehdr ehdr;

	fd = open(filename, O_RDONLY);
	n = read(fd, &ehdr, sizeof(ehdr));

	if (n != sizeof(ehdr))
	{
		fprintf(stderr, "Error in reading file\n");
		exit(98);
	}

	return (ehdr.e_ident[EI_MAG0] == ELFMAG0 && ehdr.e_ident[EI_MAG1]
			== ELFMAG1 && ehdr.e_ident[EI_MAG2]
			== ELFMAG2 && ehdr.e_ident[EI_MAG3] == ELFMAG3);
}

/**
 * print_elf_header - displays the information contained in the
 * ELF header at the start of an ELF file
 * Return: nothing
 */

void print_elf_header(void)
{
	int i;
	Elf64_Ehdr ehdr;

	printf("ELF Header:\n");
	printf("  Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
		if (i == EI_NIDENT - 1)
			printf("%02x", ehdr.e_ident[i]);
		else
			printf("%02x ", ehdr.e_ident[i]);
	printf("\n");

	printf("  Class:     %s\n", (ehdr.e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" :
			(ehdr.e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "unknown");
	printf("  Data:       %s\n", (ehdr.e_ident[EI_DATA] == ELFDATA2LSB) ?
			"2's complement, little endian" :
			(ehdr.e_ident[EI_DATA] == ELFDATA2MSB) ?
			"2's complement, big endian" : "unknown");
	printf("  Version:    %s\n", ehdr.e_ident[EI_VERSION] == EV_CURRENT ?
			"1 (current)" : "0 (invalid)");
	printf("  OS/ABI:     %s\n", (ehdr.e_ident[EI_OSABI] == ELFOSABI_SYSV) ?
			"UNIX - System V" :
			(ehdr.e_ident[EI_OSABI] == ELFOSABI_HPUX) ? "HP-UX" :
			(ehdr.e_ident[EI_OSABI] == ELFOSABI_NETBSD) ? "NetBSD" :
			(ehdr.e_ident[EI_OSABI] == ELFOSABI_LINUX) ? "Linux" :
			(ehdr.e_ident[EI_OSABI] == ELFOSABI_SOLARIS) ? "Solaris" :
			(ehdr.e_ident[EI_OSABI] == ELFOSABI_AIX) ? "AIX" :
			(ehdr.e_ident[EI_OSABI] == ELFOSABI_IRIX) ? "IRIX" :
			(ehdr.e_ident[EI_OSABI] == ELFOSABI_FREEBSD) ? "FreeBSD" :
			(ehdr.e_ident[EI_OSABI] == ELFOSABI_TRU64) ? "Tru64" :
			(ehdr.e_ident[EI_OSABI] == ELFOSABI_MODESTO) ? "Novell Modesto" :
			(ehdr.e_ident[EI_OSABI] == ELFOSABI_OPENBSD) ? "OpenBSD" : "unknown");
	printf("  ABI Version:%d\n", ehdr.e_ident[EI_ABIVERSION]);
	printf("  Type:       %s\n", ehdr.e_type == ET_DYN ?
			"DYN (Shared object file)" :
			ehdr.e_type == ET_REL ? "REL (Relocatable file)" :
			ehdr.e_type == ET_EXEC ? "EXEC (Executable file)" :
			ehdr.e_type == ET_CORE ? "CORE (Core file)" : "Unknown");
	printf("  Entry point address:    %p\n", (void *)(ehdr.e_entry & 0xFFFF));
}

/**
 * main - function to display info contained in the ELF header of an ELF file
 * @argc: number of arguments inclusive of filename
 * @argv: array of arguments
 * Return:0 - successful
 */
int main(int argc, char **argv)
{
	int fd;
	bool is_elf_file;
	char *filename = argv[1];

	if (argc != 2)
	{
		fprintf(stderr, "Error in number of argumnts required");
		exit(98);
	}

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "File does not exist\n");
		exit(98);
	}

	/* check if file is an ELF format file */
	is_elf_file = is_elf(filename);
	if (!is_elf_file)
	{
		fprintf(stderr, "File format not ELF!\n");
		exit(98);
	}

	print_elf_header();
	return (0);
}
