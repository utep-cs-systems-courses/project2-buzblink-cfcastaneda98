# makfile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf

#additional rules for files
main.elf: ${COMMON_OBJECTS} main.o stateMachines.o switches.o buzzer.o led.o wdInterruptHandler.o p2_interrupt_handler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf *h ~* *~

led.o: led.c led.h

buzzer.o: buzzer.h

switches.o: switches.h led.h

main.o: led.h switches.h buzzer.h

p2_interrupt_handler.0: switches.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h
