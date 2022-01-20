mkdir -p isodir/boot/grub
cp Kernel.bin isodir/boot/Kernel.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o Kernel.iso isodir
cp Kernel.iso ~/Documents
rm -fr isodir