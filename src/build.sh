
#ASSEMBLER COMPILATION
nasm -fbin ./boot/boot.asm 
nasm -fbin ./boot/locateFS.asm
nasm -fbin ./boot/kernelLoader.asm
nasm -f elf32 ./handlers/keyboard.asm -o keyboard.o
nasm -f elf32 ./pit/pit.asm -o pit.o

#TO COPY
sudo cp pit -r /usr/local/i386elfgcc/bin
sudo cp IDT -r /usr/local/i386elfgcc/bin
sudo cp lib -r /usr/local/i386elfgcc/bin
sudo cp boot -r /usr/local/i386elfgcc/bin
sudo cp tetris -r /usr/local/i386elfgcc/bin
sudo cp headers -r /usr/local/i386elfgcc/bin
sudo cp terminal -r /usr/local/i386elfgcc/bin
sudo cp keyboard -r /usr/local/i386elfgcc/bin
sudo cp handlers -r /usr/local/i386elfgcc/bin
sudo cp xaninApps -r /usr/local/i386elfgcc/bin
sudo cp xaninGraphics -r /usr/local/i386elfgcc/bin
sudo cp spaceInv -r /usr/local/i386elfgcc/bin
sudo cp pong -r /usr/local/i386elfgcc/bin
sudo cp ustar -r /usr/local/i386elfgcc/bin
sudo cp kernel.c /usr/local/i386elfgcc/bin





#COMPILE
cd /usr/local/i386elfgcc/bin
sudo ./i386-elf-gcc -O0 -masm=intel -Wno-builtin-declaration-mismatch -nostdlib -Wno-unused-function kernel.c ./handlers/keyboard.o ./pit/pit.o -o kernel.bin
cp kernel.bin /mnt/c/Users/wiktor/Desktop/xaninOS/src
cd /mnt/c/Users/wiktor/Desktop/xaninOS/src
cat ./boot/boot ./boot/kernelLoader kernel.bin ./boot/locateFS files.tar > xanin.bin



#MOV XANIN.img to BIN

dd if=xanin.bin of=xanin.img
mv xanin.img -f /mnt/c/Users/wiktor/Desktop/xaninOS/bin
cd /mnt/c/Users/wiktor/Desktop/xaninOS/bin
./a.out
cd /mnt/c/Users/wiktor/Desktop/xaninOS/src

#CLEANING SRC
rm xanin.bin
rm pit.o
rm keyboard.o


