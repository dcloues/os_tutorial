#include "monitor.h"
#include "descriptor_tables.h"

int main(struct multiboot *mboot_ptr)
{
	monitor_clear();
	monitor_write("Initializing GDT...");
 	init_descriptor_tables();
	monitor_write("GDT initialized.");
	// All our initialisation calls will go in here.
	return 0xDEADBABA;
}
