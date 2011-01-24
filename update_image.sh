#!/bin/bash

echo "updating image. old:"
md5sum floppy.img
sudo losetup /dev/loop0 floppy.img
sudo mount /dev/loop0 /mnt/os_tutorial
sudo cp src/kernel /mnt/os_tutorial/kernel
echo "done:"

sudo umount /dev/loop0
sudo losetup -d /dev/loop0
md5sum floppy.img
