addiu v1, v1, 0xFF
lui v0, 0x1000
sh v1, 0x2(v0)
lh v0, 0x2(v0)
jr zero
nop