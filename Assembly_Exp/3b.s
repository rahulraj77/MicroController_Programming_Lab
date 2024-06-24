	PRESERVE8
Stack EQU 0x00000100
	AREA STACK, NOINIT, READWRITE
StackMem SPACE Stack
	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD StackMem
	DCD Reset_Handler
	AREA tempData, DATA, READONLY
Array DCD 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

	AREA |.text|, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
Reset_Handler_End
	LDR R0, = Array
	MOV R1, #0
	MOV R2, #9
	MOV R3, #0x8
	BL Binary_Search_Start
foreverloop B foreverloop
Binary_Search_Start
	MOV R4, R0
	MOV R0, #0
Binary_Search_Loop
	ADD R5, R1, R2
	LSR R5, R5, #1
	LSL R7, R5, #2
	LDR R6, [R4, R7]
	CMP R3, R6
	ADDEQ R0, R0, R5
	ADDEQ R0, R0, #1
	MOVEQ PC, LR
	SUBLT R5, R5, #1
	MOVLT R2, R5
	ADDGT R5, R5, #1
	MOVGT R1, R5
	CMP R1, R2
	MOVEQ PC, R8
	B Binary_Search_Loop
	END
