	PRESERVE8
Stack EQU 0x00000100
	AREA STACK, NOINIT, READWRITE, ALIGN = 4
StackMem SPACE Stack
	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD StackMem
	DCD Reset_Handler
	AREA tempData, DATA, READONLY, ALIGN = 4
ROMARRAY1 DCD 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
ROMARRAY2 DCD 0x09, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16
	AREA |.data|, DATA, READWRITE, ALIGN = 4
LEN EQU 0x08
ARRAY1 SPACE 32
ARRAY2 SPACE 32
	AREA |.text|, CODE, READONLY, ALIGN = 4
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
Reset_Handler_End
	MOV R0, #0x10
	LDR R1,= ROMARRAY2 + 28
	LDR R2,= ARRAY2 + 28
MEMCPY_LOOP
	LDR R3,[R1],#-4
	STR R3,[R2],#-4
	SUBS R0,R0,#1
	BNE MEMCPY_LOOP
	MOV R0, #LEN
	LDR R1,= ARRAY1 + 28
	LDR R2,= ARRAY2 + 28
EXCH_LOOP
	LDR R3,[R1]
	LDR R4,[R2]
	STR R4,[R1],#-4
	STR R3,[R2],#-4
	SUBS R0,R0,#1
	BNE EXCH_LOOP
STOP B STOP
END