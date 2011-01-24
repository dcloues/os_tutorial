SOURCES=boot.o main.o common.o monitor.o

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

