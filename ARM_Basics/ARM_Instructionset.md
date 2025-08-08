# ARM Instruction Set (Cortex-M3 – STM32 Blue Pill)

This document covers the fundamental ARM Cortex-M3 instruction set categories:
- Data Processing Instructions
- Data Transfer Instructions
- Control Flow Instructions

The Cortex-M3 uses the **Thumb-2 instruction set**, meaning most instructions are 16-bit, with some 32-bit extensions for complex operations.

---

## 1. Data Processing Instructions

These instructions operate on registers or immediate values without accessing memory (except for load/store in special cases).

### 1.1 Arithmetic Instructions

| Mnemonic | Description | Example |
|----------|-------------|---------|
| `ADD`    | Add two operands | `ADD R0, R1, R2` → R0 = R1 + R2 |
| `SUB`    | Subtract two operands | `SUB R0, R1, R2` → R0 = R1 - R2 |
| `ADC`    | Add with carry | `ADC R0, R1, R2` |
| `SBC`    | Subtract with carry | `SBC R0, R1, R2` |
| `RSB`    | Reverse subtract | `RSB R0, R1, R2` → R0 = R2 - R1 |

**Example:**
```asm
    MOV R0, #5
    MOV R1, #3
    ADD R2, R0, R1    ; R2 = 8
1.2 Logical Instructions
Mnemonic	Description	Example
AND	Bitwise AND	AND R0, R1, R2
ORR	Bitwise OR	ORR R0, R1, R2
EOR	Bitwise XOR	EOR R0, R1, R2
BIC	Bit Clear (AND NOT)	BIC R0, R1, R2

1.3 Move & Immediate Instructions
Mnemonic	Description	Example
MOV	Move value into register	MOV R0, #0x10
MVN	Move NOT (bitwise complement)	MVN R0, R1
LSL	Logical Shift Left	LSL R0, R1, #2
LSR	Logical Shift Right	LSR R0, R1, #1
ASR	Arithmetic Shift Right	ASR R0, R1, #1
ROR	Rotate Right	ROR R0, R1, #4

1.4 Compare & Test Instructions
These update flags (N, Z, C, V) without storing results.

Mnemonic	Description	Example
CMP	Compare two registers	CMP R0, R1
CMN	Compare Negative	CMN R0, R1
TST	Test bits (AND)	TST R0, R1
TEQ	Test equality (XOR)	TEQ R0, R1

2. Data Transfer Instructions
These load/store values between memory and registers.

2.1 Single Register Transfer
Mnemonic	Description	Example
LDR	Load from memory	LDR R0, [R1]
STR	Store to memory	STR R0, [R1]
LDRB	Load Byte	LDRB R0, [R1]
STRB	Store Byte	STRB R0, [R1]
LDRH	Load Halfword	LDRH R0, [R1]
STRH	Store Halfword	STRH R0, [R1]

2.2 Multiple Register Transfer
Mnemonic	Description	Example
LDM	Load Multiple	LDM R0!, {R1-R4}
STM	Store Multiple	STM R0!, {R1-R4}

2.3 Stack Operations
Mnemonic	Description	Example
PUSH	Push to stack	PUSH {R4, R5, LR}
POP	Pop from stack	POP {R4, R5, PC}

3. Control Flow Instructions
These change the flow of program execution.

3.1 Branch Instructions
Mnemonic	Description	Example
B	Branch (unconditional)	B label
BL	Branch with Link (call subroutine)	BL function
BX	Branch and exchange instruction set	BX LR
BLX	Branch with Link and exchange	BLX R0

3.2 Conditional Branches
Branches are executed only if condition flags match.

Condition Suffixes:

EQ → Equal (Z=1)

NE → Not Equal (Z=0)

CS/HS → Carry Set / Unsigned Higher or Same (C=1)

CC/LO → Carry Clear / Unsigned Lower (C=0)

MI → Minus (N=1)

PL → Plus (N=0)

VS → Overflow (V=1)

VC → No Overflow (V=0)

HI → Unsigned Higher (C=1 and Z=0)

LS → Unsigned Lower or Same (C=0 or Z=1)

GE → Signed Greater or Equal (N=V)

LT → Signed Less Than (N≠V)

GT → Signed Greater Than (Z=0 and N=V)

LE → Signed Less or Equal (Z=1 or N≠V)

Example:

asm
Copy
Edit
    CMP R0, #10
    BGE greater_equal
    ; else
    MOV R1, #0
greater_equal:
    MOV R1, #1
3.3 Special Instructions
Mnemonic	Description	Example
NOP	No operation	NOP
BKPT	Breakpoint for debugger	BKPT #0
SVC	Supervisor Call (system call)	SVC #0