;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Abel Theodros
; Email: atheo003@ucr.edu
; 
; Assignment name: Assignment 4
; Lab section: 026
; TA: Robert Colvin
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=================================================================================
;THE BINARY REPRESENTATION OF THE USER-ENTERED DECIMAL NUMBER MUST BE STORED IN R3
;=================================================================================

.ORIG x3000		
;-------------
;Instructions
;-------------

START

; output intro prompt
LD R0, introPromptPtr
PUTS
						
; Set up flags, counters, accumulators as needed
LD R3, accumulator
LD R4, negative_flag
LD R6, countdown

; Get first character, test for '\n', '+', '-', digit, or a non-digit

GETC
OUT

; Is very first character = '\n'? if so, just quit (no message)!

NEWLINE_CHECKER
	LD R1, newline
	NOT R1, R1
	ADD R1, R1, #1
	ADD R1, R0, R1
BRz ENDING
BRnp POS_CHECKER

; is it = '+'? if so, ignore it, go get digits

POS_CHECKER
	LD R1, plus
	NOT R1, R1
	ADD R1, R1, #1
	ADD R1, R0, R1
BRz BEGIN_INPUT
BRnp NEG_CHECKER

; is it = '-'? if so, set neg flag, go get digits

NEG_CHECKER
	LD R1, minus
	NOT R1, R1
	ADD R1, R1, #1
	ADD R1, R0, R1
BRz NEG_FLAG
BRnp LESS_THAN_CHECKER

NEG_FLAG
	ADD R4, R4, #-1
BR BEGIN_INPUT

; is it < '0'? if so, it is invalid	- o/p error message, start over
LESS_THAN_CHECKER
	LD R1, less_zero
	ADD R1, R0, R1
BRn ERROR
BRzp MORE_THAN_CHECKER

; is it > '9'? if so, it is invalid	- o/p error message, start over
MORE_THAN_CHECKER
	LD R1, more_nine
	ADD R1, R0, R1
BRp ERROR
BRnz VALID_UNIT

; if none of the above, first character is first numeric digit!
VALID_UNIT
	LD R1, ascii
	ADD R3, R0, R1
	ADD R6, R6, #-1
BR BEGIN_INPUT

; Go get remaining digits
BEGIN_INPUT
	GETC

	ENTER_CHECKER
		LD R1, enter_check
		ADD R1, R0, R1
	BRz FINAL_CHECK
	OUT
	BINARY_CONVERT
		LD R1, ascii
		ADD R0, R0, R1

	NON_NUMB_CHECKER
		ADD R0, R0, #0
		BRn ERROR

		LD R1, nine
		ADD R1, R0, R1
		BRp ERROR

	LD R1, ten
	ADD R3, R3, R2
	MULTIPLIER
		ADD R2, R2, R3
		ADD R1, R1, #-1
	BRp MULTIPLIER
	ADD R3, R2, R0
	AND R2, R2, #0
ADD R6, R6, #-1 ; even if it's first value wasn't a digit, this countdown should help make sure the final value is max 5 units. 
BRz FINAL_CHECK
BRp BEGIN_INPUT
					
FINAL_CHECK 		; check if the flag is -1/0, if R2 is neg, it becomes two's complement
ADD R4, R4, #0
BRn TWOS_COMPLEMENT
BRz ENDING

ERROR
	LEA R0, newline
	PUTS

	LD R0, errorMessagePtr
	PUTS
BR START

TWOS_COMPLEMENT
	NOT R3, R3
	ADD R3, R3, #1
BR ENDING

ENDING
	LEA R0, newline
	PUTS 

	LEA R0, newline
	PUTS

HALT

;---------------	
; Program Data
;---------------
newline				.STRINGZ "\n"
plus				.STRINGZ "+"
minus				.STRINGZ "-"
more_nine			.FILL #-57
nine 				.FILL #-9
nine_nine			.FILL #9
less_zero			.FILL #-48
counter 			.FILL #0
countdown			.FILL #5
negative_flag 		.FILL #0
accumulator 		.FILL #0
ascii 				.FILL #-48
ten 				.FILL #10
enter_check 		.FILL #-10
introPromptPtr		.FILL x4000
errorMessagePtr		.FILL x4100


;------------
; Remote data
;------------
.ORIG x4000			; intro prompt
.STRINGZ	"Input a positive or negative decimal number (max 5 digits), followed by ENTER\n"
					
					
.ORIG x4100			; error message
.STRINGZ	"ERROR: invalid input\n"

;---------------
; END of PROGRAM
;---------------
.END

;-------------------
; PURPOSE of PROGRAM
;-------------------
; Convert a sequence of up to 5 user-entered ascii numeric digits into a 16-bit two's complement binary representation of the number.
; if the input sequence is less than 5 digits, it will be terminated with a newline (ENTER).
; Input validation is performed on the individual characters as they are input, but not on the magnitude of the number