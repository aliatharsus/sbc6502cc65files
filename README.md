#sbc6502 barebones C linker files

These files are absolutely necessary for using the cc65 to run a C program on a 6502. cc65 is an easy to use program and can be found here:

https://cc65.github.io/

To upload the program to the ROM use anything that can upload .bin or any other supported format. To build an EEPROM programmer from minimal tools, refer:

https://github.com/aliatharsus/at28cxxAIDEprog

To actually convert C code to .bin file, use the following commands after placing all the above files into the cc65 folder (my version of sbc doesnt have a serial port):

```shell

ca65 crt0.s
ar65 a sbc.lib crt0.o
cc65 -t none -O --cpu 6502 main.c
ca65 --cpu 6502 main.s
ca65 --cpu 6502 interrupt.s
ca65 --cpu 6502 vectors.s
ca65 --cpu 6502 wait.s
ld65 -C sbc.cfg -m main.map interrupt.o vectors.o wait.o main.o sbc.lib -o main.bin

```
