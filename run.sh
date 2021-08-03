clear

echo "Creating build enviroment"
echo -ne '\n'
sleep 0.2
echo -ne '<                        (0%)>\r'
mkdir build
echo -ne '<#####                  (33%)>\r'
sleep 0.2
#cp -r * build
cp -r * build 2>/dev/null || :
echo -ne '<#############          (66%)>\r'
sleep 0.2
cd build
echo -ne '<#######################(100%)>\r'
sleep 0.2
echo -ne '\n'
echo -ne '\n'

echo "Compiling the project"
echo -ne '\n'
echo -ne '<                              (0%)>\r'
#assemble boot.s file
as --32 boot.s -o boot.o
sleep 0.1
echo -ne '<##                            (6%)>\r'

#compile kernel.c file
gcc -m32 -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
sleep 0.1
echo -ne '<####                          (12%)>\r'

gcc -m32 -c lib/io.c -o io.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
sleep 0.1
echo -ne '<######                        (18%)>\r'

gcc -m32 -c lib/gui.c -o gui.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
sleep 0.1
echo -ne '<########                      (24%)>\r'

gcc -m32 -c lib/vga.c -o vga.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
sleep 0.1
echo -ne '<##########                    (30%)>\r'

gcc -m32 -c lib/char.c -o char.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
sleep 0.1
echo -ne '<############                  (36%)>\r'

gcc -m32 -c lib/draw.c -o draw.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
sleep 0.1
echo -ne '<##############                (42%)>\r'

gcc -m32 -c lib/func.c -o func.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
sleep 0.1
echo -ne '<################              (48%)>\r'

gcc -m32 -c lib/input.c -o input.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
sleep 0.1
echo -ne '<##################            (50%)>\r'

gcc -m32 -c lib/print.c -o print.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
sleep 0.1
echo -ne '<####################          (56%)>\r'

gcc -m32 -c lib/sleep.c -o sleep.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
sleep 0.1
echo -ne '<######################        (60%)>\r'

gcc -m32 -c lib/utils.c -o utils.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
sleep 0.1
echo -ne '<########################      (66%)>\r'

gcc -m32 -c lib/pkginf.c -o pkginf.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
sleep 0.1
echo -ne '<##########################    (70%)>\r'

gcc -m32 -c lib/vars.c -o vars.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
sleep 0.1
echo -ne '<############################ (80%)>\r'

gcc -m32 -c lib/pkgs.c -o pkgs.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
sleep 0.1
echo -ne '<#############################(100%)>\r'

#linking the kernel with kernel.o and boot.o files
ld -m elf_i386 -T linker.ld kernel.o utils.o boot.o io.o pkgs.o vars.o gui.o vga.o char.o draw.o func.o input.o print.o sleep.o pkginf.o -o Kernel.bin -nostdlib

#check Kernel.bin file is x86 multiboot file or not
grub-file --is-x86-multiboot Kernel.bin

#building the iso file
mkdir -p isodir/boot/grub
cp Kernel.bin isodir/boot/Kernel.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o Kernel.iso isodir


echo "Removing the build enviroment"
echo ""
echo -ne '<                        (0%)>\r'
cp Kernel.iso /run/user/1000/gvfs/smb-share:server=dimlap.local,share=isoserverdrop
echo -ne '<#############################(100%)>\r'
echo ""
cd ..
rm -fr build

#run it in qemu-system
#qemu-system-x86_64 -cdrom Kernel.iso
