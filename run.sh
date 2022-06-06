clear

mkdir build
cd ..
cp -a Kernel/* Kernel/build 2>/dev/null || :
cd Kernel
cd build

echo "Compiling the project"
echo -ne '\n'
echo -ne '<                              (0%)>\r'
#assemble boot.s file
as --32 boot.s -o boot.o
sleep 0.1
echo -ne '<##                            (6%)>\r'

#compile DDOS.c file
gcc -m32 -c DDOS.c -o DDOS.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

gcc -m32 -c lib/io.c -o io.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

gcc -m32 -c lib/vga.c -o vga.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

gcc -m32 -c lib/char.c -o char.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

gcc -m32 -c lib/draw.c -o draw.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

gcc -m32 -c lib/ascii.c -o ascii.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

gcc -m32 -c lib/input.c -o input.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

gcc -m32 -c lib/print.c -o print.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

gcc -m32 -c lib/sleep.c -o sleep.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

gcc -m32 -c lib/utils.c -o utils.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

gcc -m32 -c lib/memlib.c -o memlib.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

gcc -m32 -c lib/vars.c -o vars.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

gcc -m32 -c lib/kpm.c -o kpm.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

#linking the DDOS with DDOS.o and boot.o files
ld -m elf_i386 -T linker.ld DDOS.o utils.o boot.o io.o vars.o vga.o char.o draw.o input.o print.o sleep.o memlib.o ascii.o kpm.o  -o DDOS.bin -nostdlib

#check DDOS.bin file is x86 multiboot file or not
grub-file --is-x86-multiboot DDOS.bin

#building the iso file
mkdir -p isodir/boot/grub
cp DDOS.bin isodir/boot/DDOS.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o DDOS.iso isodir


echo "Removing the build enviroment"
echo ""
echo -ne '<                        (0%)>\r'
#cp DDOS.iso /run/user/1000/gvfs/smb-share:server=dimlap.local,share=isoserverdrop
cp DDOS.iso ..
echo -ne '<#############################(100%)>\r'
echo ""
cd ..
rm -fr build

#run it in qemu-system
qemu-system-x86_64 -cdrom DDOS.iso