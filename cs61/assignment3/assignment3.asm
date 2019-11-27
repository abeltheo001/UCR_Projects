;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Abel Theodros
; Email: atheo003@ucr.edu
; 
; Assignment name: Assignment 3
; Lab section: 026
; TA: Robert Colvin
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=========================================================================

.ORIG x3000			; Program begins here
;-------------
;Instructions
;-------------
LD R6, Value_addr		; R6 <-- pointer to value to be displayed as binary
LDR R1, R6, #0			; R1 <-- value to be displayed as binary 
;-------------------------------
;INSERT CODE STARTING FROM HERE
;--------------------------------
LD R2, Sixteen_Counter
LD R3, Four_Counter

PRINT_LOOP
	ADD R1, R1, #0	
	BRn	ONE_LOOP 	; if the first digit is a negative, start by outputting a one
	BRp ZERO_LOOP   ; if the first digit is a positive, start by outputting a zero
END_PRINT_LOOP

ZERO_LOOP
	LD R0, Zero
	OUT 
	BRnzp NEXT_LOOP
END_ZERO_LOOP

ONE_LOOP
	LD R0, Uno
	OUT
	BRnzp NEXT_LOOP
END_ONE_LOOP

NEXT_LOOP
	ADD R1, R1, R1 	; Move to next		
	ADD R2, R2, #-1 ; Decrement the 16 counter
	ADD R3, R3, #-1 ; Decrement the 4 counter

	LD R5, Zero 	; Reset R5
	LD R4, Zero 	; Reset R4

	ADD R5, R2, #0
	BRz NEWLINE_LOOP ; if the newline counter is zero, output a newline, no space.

	ADD R4, R3, #0
	BRz SPACE_LOOP ; if the four counter is zero and the newline counter isn't, output a space.

	BRnzp PRINT_LOOP ; if neither qualify, then the number is yet to be fully ouputted, so keep going
END_NEXT_LOOP

SPACE_LOOP
	LD R0, Space
	OUT 

	ADD R3, R3, #4			; reset the 4 counter to 4
	ADD R2, R2, #0			; reset the 16 counter		

	BRnzp PRINT_LOOP 		; at this point, the only option is to keep outputting, so it goes back to the print loop
END_SPACE_LOOP

NEWLINE_LOOP
	LD R0, Newline
	OUT
	BRnzp ENDING
END_NEWLINE_LOOP

ENDING 

HALT
;---------------	
;Data
;---------------
Value_addr		.FILL xAA00			; The address where value to be displayed is stored
Sixteen_Counter .FILL #16
Four_Counter	.FILL #4
Newline			.FILL #10
Zero 			.FILL #48
Uno 			.FILL #49
Space 			.FILL #32

.ORIG xAA00								; Remote data
Value 			.FILL xABCD			; <----!!!NUMBER TO BE DISPLAYED AS BINARY!!! Note: label is redundant.

;---------------	
;END of PROGRAM
;---------------	
.END
