
tests/tmp/BNE-loop.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <entry>:
10000000:	24 03 00 01 24 08 00 0a                             $...$...

10000008 <top>:
10000008:	00431021 	addu	v0,v0,v1
1000000c:	1448fffe 	bne	v0,t0,10000008 <top>
10000010:	00000000 	nop
10000014:	03e00008 	jr	ra
10000018:	00000000 	nop
1000001c:	00000000 	nop
