// common.c -- Defines some global functions.
// From JamesM's kernel development tutorials.

#include "common.h"

// Write a byte out to the specified port.
void outb(u16int port, u8int value)
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

u8int inb(u16int port)
{
   u8int ret;
   asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
}

u16int inw(u16int port)
{
   u16int ret;
   asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
}

void memset(void *addr, u32int value, u32int size) {
	u8int v = (u8int) value;
	void *limit = addr + size;
	while (addr < limit) {
		*((u8int *)addr++) = value;
	}
}

extern void panic(const char *message, const char *file, u32int line)
{
	asm volatile("cli");

	monitor_write("PANIC(");
	monitor_write(message);
	monitor_write(") at ");
	monitor_write(file);
	monitor_write(":");
	monitor_write_dec(line);
	monitor_write("\n");

	for (;;);
}

extern void panic_asset(const char *file, u32int line, const char *desc)
{
	asm volatile("cli");

	monitor_write("ASSERTION-FAILED(");
	monitor_write(desc);
	monitor_write(") at ");
	monitor_write(file);
	monitor_write(":");
	monitor_write_dec(line);
	monitor_write("\n");

	for (;;);
}
