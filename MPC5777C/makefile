OS_BINARY=os_binary.bin
OS_BINARY_ELF=os_binary.elf

SRCS = $(wildcard *.c *.S)
OBJS = $(patsubst %.S,%.o,$(patsubst %.c,%.o,$(SRCS)))

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
export GCC=powerpc-linux-gnu-gcc
export OBJCP=powerpc-linux-gnu-objcopy
export LD=powerpc-linux-gnu-ld
export GCCOPT=-mcpu=powerpc
else
export GCC=ppc-gcc
export OBJCP=ppc-objcopy
export LD=ppc-ld
endif

# Build system image
all: clean $(OS_BINARY)

# Run QEMU on our system
run:
	../../../qemu-2.12.0/build/ppc-softmmu/qemu-system-ppc -cpu e200 -d guest_errors,unimp -M ppce200 -serial stdio -s -bios $(OS_BINARY_ELF)

debug:
	../../../qemu-2.12.0/build/ppc-softmmu/qemu-system-ppc -cpu e200 -d guest_errors,unimp -M ppce200 -serial stdio -s -S -bios $(OS_BINARY_ELF)

$(OS_BINARY) : $(OS_BINARY_ELF)
	$(OBJCP) -O binary  $< $@

$(OS_BINARY_ELF) : $(OBJS) linker.ld
	$(LD) -T linker.ld $(OBJS) -o $@



boot.o : boot.S
	$(GCC) -mbig-endian -g -c -gstabs+ -Wa,-alh=boot.lst,-L -o $@ $<

%.o : %.S
	$(GCC) -mbig-endian -g -c -gstabs+ -Wa,-L -o $@ $<

%.o: %.c
	$(GCC) -Iextra_freescale -c -mcpu=8540 -g $< -o $@

clean :
	rm -f -v *.o *.elf *.bin *.lst
