#include "monitor.h"
#include "descriptor_tables.h"

int main(struct multiboot *mboot_ptr)
{
	monitor_clear();
	monitor_write("Initializing GDT...");
 	init_descriptor_tables();
	monitor_write("GDT initialized.");
	asm volatile ("int $0x3");
	asm volatile ("int $0x4");
	//monitor_write_dec(15);
	//monitor_write_dec(-48281);
	//monitor_write_dec(295180203);
	monitor_write_hex(0xFF);
	monitor_put('\n');
	monitor_write_hex(0x0);
	monitor_put('\n');
	monitor_write_hex(0xFAFABABA);
	monitor_put('\n');
	monitor_write_hex(0xABA);

	// All our initialisation calls will go in here.
	return 0xDEADBABA;
}
