#SOURCES=boot.o gdt.o interrupt.o isr.o descriptor_tables.o main.o common.o monitor.o \
	#kheap.o paging.o
SOURCES=boot.o main.o monitor.o common.o descriptor_tables.o isr.o interrupt.o gdt.o \
        kheap.o paging.o timer.o

CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector -march=i386 -m32
LDFLAGS=-Tlink.ld -melf_i386
ASFLAGS=-felf

all: $(SOURCES) link

clean: 
	-rm *.o kernel

link:
	ld $(LDFLAGS) -o kernel $(SOURCES)

.s.o:
	nasm $(ASFLAGS) $<

