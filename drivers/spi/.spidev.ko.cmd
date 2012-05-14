cmd_drivers/spi/spidev.ko := arm-eabi-ld -EL -r  -T /data/repos/kernels/scripts/module-common.lds --build-id -o drivers/spi/spidev.ko drivers/spi/spidev.o drivers/spi/spidev.mod.o
