# CORTEX PROCESSORS

## Target
really want to throw away Keil and have total control

## History
* 2018/06/26 init

## References
1. Joseph Liu, The Definite Guide to ARM Cortex-M0 and Cortex-M0+ Processors, 2015 Elsevier Inc
2. [Writing your own startup code for Cortex-M](https://community.arm.com/processors/b/blog/posts/writing-your-own-startup-code-for-cortex-m)

## Tool Chain
* [GNU Arm Embedded Toolchain](https://launchpad.net/gcc-arm-embedded) pre-built GNU toolchain from Arm Cortex-M & Cortex-R processors (Cortex-M0/M0+/M3/M4/M7/M23/M33, Cortex-R4/R5/R7/R8/R52)
* [GNU Arm Embedded Toolchain 4.9-2014q4-major](https://launchpad.net/gcc-arm-embedded/4.9/4.9-2014-q4-major/+download/gcc-arm-none-eabi-4_9-2014q4-20141203-linux.tar.bz2)
* The linker scripts and start-up codes may differ from a version to another of the prebuilt gcc tool chain.
* In ref[1], version 4.9 2014q4 was used.
* arm-none-eabi-gcc/as/ld/objcopy/objdump: no specific target OS
* On Cortex-M-based system, uClinx might be used. Use arm-linux-*.
* EABI, embedded application binary interface: a standard convention for file formats, data types, register usage, stack frame organization, and function parameter passing of an embedded program

## Required files for a project
* a microcontroller vendor should provide device-specific files: 
  * CMSIS header files,
  * start-up code for gcc, 
  * system initialization files

## Keil assembly of startup
ARM Compiler v5.06 for µVision armasm User Guide [link](www.keil.com/support/man/docs/armasm/)
Unified Assembly Language (UAL) for both ARM and Thumb code
two passes: read twice the source code before generating object code
a load-store architecture: 
	* only load and store instructions can access memory
	* data processing instructions operate on register contents only

ARM instruction: 32-b
Thumb instruction: 16-bit instruction, better code density at the expence of performance

NUC100/120xxxDN: ARMv6-M Thumb instruction set
Thumb-2 technology
available modes:
* thread mode, the normal mode
* handler mode, the mode to handle exceptions

ARM processors provide general-purpose and special-purpose registers
	* 13 general-purpose registers R0-R12.
	* 1 Stack Pointer (SP).
	* 1 Link Register (LR).
	* 1 Program Counter (PC).
	* 1 Application Program Status Register (APSR).

http://www.keil.com/support/man/docs/armasm/armasm_pge1464343210583.png

syntax
{symbol} {instruction|directive|pseudo-instruction} {;comment}
instruction mnemonics, pseudo-instructions, directives, and symbolic register names in either all uppercase or all lowercase - no mixed case.
Labels and comments are OK with all 3 cases.

semihosting: a mechanism in which an ARM target in code running can communicate with the debugger installed on the host PC

Stack_Size	EQU	0x00000400
#define Stack_Size 0x00000400
