cmd_drivers/crypto/msm/qcrypto.ko := arm-eabi-ld -EL -r  -T /data/repos/kernels/scripts/module-common.lds --build-id -o drivers/crypto/msm/qcrypto.ko drivers/crypto/msm/qcrypto.o drivers/crypto/msm/qcrypto.mod.o