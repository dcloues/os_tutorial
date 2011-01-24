#include "monitor.h"

int main(struct multiboot *mboot_ptr)
{
  monitor_clear();
  monitor_write("Hello, world!");
  // All our initialisation calls will go in here.
  return 0xDEADBABA;
}
