cmd_drivers/serial/built-in.o :=  arm-eabi-ld -EL    -r -o drivers/serial/built-in.o drivers/serial/serial_core.o drivers/serial/msm_serial_hs.o drivers/serial/msm_serial_hs_lite.o 
