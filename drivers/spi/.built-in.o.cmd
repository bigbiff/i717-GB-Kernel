cmd_drivers/spi/built-in.o :=  arm-eabi-ld -EL    -r -o drivers/spi/built-in.o drivers/spi/spi.o drivers/spi/spi_bitbang.o drivers/spi/spi_qsd.o 
