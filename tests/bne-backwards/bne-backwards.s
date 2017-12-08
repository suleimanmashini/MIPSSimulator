addiu v1, v1, 0x1
bne zero, v1, 0x3
nop
jr zero
nop
addiu v0, v0, 0x1
bne zero, v1, 0xFFFC
nop