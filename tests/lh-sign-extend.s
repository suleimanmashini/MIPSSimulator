lui v0, 0x2000
addiu v1, v1, 0x8F00
sw v1, 0x0(v0)
lh v0, 0x2(v0)
srl v0, v0, 0x10
jr zero
nop

