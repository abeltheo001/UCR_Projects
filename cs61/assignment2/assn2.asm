;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Abel Theodros
; Email: atheo003@ucr.edu
; 
; Assignment name: Assignment 2
; Lab section: 026
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

;----------------------------------------------
;output prompt
;----------------------------------------------	
LEA R0, intro			; get starting address of prompt string
PUTS			    	; Invokes BIOS routine to output string
					
GETC					; input first number
OUT 
ADD R1, R0, #0

LD R0, NEWLINE 			; newline
OUT
						
GETC					; input second number 
OUT 
ADD R2, R0, #0

LD R0, NEWLINE
OUT

ADD R0, R1, #0
OUT

LEA R0, subtract
PUTS

ADD R0, R2, #0
OUT

LEA R0, equals
PUTS


LD R3, FRTYEIGH

NOT R3, R3
ADD R3, R3, #1

ADD R1, R1, R3
ADD R2, R2, R3


NOT R2, R2
ADD R2, R2, #1

ADD R4, R1, R2

CHECK_NEGATIVE
ADD R0, R4, #0
BRn MAKE_POS
BRzp OUTPUT



MAKE_POS
NOT R4, R4
ADD R4, R4, #1
BRnzp OUTPUT_2



OUTPUT_2
LEA R0, subtract
PUTS
LD R3, FRTYEIGH
ADD R0, R4, R3
OUT
BRnzp END

OUTPUT
LD R3, FRTYEIGH
ADD R0, R4, R3
OUT


END

LD R0, NEWLINE
OUT

HALT				

intro 	 .STRINGZ	"ENTER two numbers (i.e '0'....'9')\n" 		
subtract .STRINGZ 	"-"
equals 	 .STRINGZ	"="
NEWLINE  .FILL '\n'		; newline character - use with LD followed by OUT
FRTYEIGH .FILL 		#48


.END

