*********************************************************************
* Filename: HEADER.INC
* Date:     05/01/2016
* Author:   orbitaldecay
*
* Standard bank header. Needs to be COPYed to the begining of each bank.
* Switches to bank 0 (in the event that we didn't start there). Note: if you
* change the binary size of this header, make sure you update the split command
* in the build script to split files on a (8192 - header size) boundary.
*********************************************************************

* We use the following register addresses to interact with the VDP
* (Video Display Processor). We first write the low byte of the
* address we want to write at to VDPWA and then write the high byte
* to VDPWA. Then we write the byte we want to write to VDPWD. See
* below for an example. These symbols are defined on page 247 of the
* editor / assembler manual. Usage is described in section 16.4.

VDPWA  EQU  >8C02     * Address of VDP RAM write address register
VDPRD  EQU  >8800     * Address of VDP RAM read data register
VDPWD  EQU  >8C00     * Address of VDP RAM write data register
VDPSTA EQU  >8802     * Address of VDP status register

* Memory constants

LMEMSP  EQU >2000    * Pointer to lower memory space
HMEMSP  EQU >A000    * Pointer to upper memory space
CARTSP  EQU >6000    * Pointer to cart space
BANKSZ  EQU >2000    * Bank size (including header)

* Workspaces and scratchpad stuff

CTRLWP  EQU  >8300     * Default workspace pointer
SONGWP  EQU  >8320     * Workspace pointer for song playing routine RESERVED
FREEWP  EQU  >8340     * A free workspace
GPLWP   EQU  >83E0     * Address of GPL workspace (>20 bytes)
FNPNTR  EQU  >8356     * Filename pointer for DSRLNK (>02 bytes)

* Other memory that is used by stuff

SONGMEM EQU  >F000     * The currently playing song is located at >F000 - >FFFF
FXMEM   EQU  >A000     * Effect at >A000 to >EFFF avail to use (20K)

* Reserved for save states. A save state is all 256 bytes of
* scratch pad RAM and the upper >900 bytes of VRAM.
       
STATE0  EQU  >3000     * The original state of the machine
STATE1  EQU  >3800     * Temporary save state 1


* Cartridge ROM header:

HEADER
       .ifdef CARTRIDGE
       BYTE >AA           ; Standard header
       BYTE >01           ; Version number
       BYTE >01           ; Number of programs (optional)
       BYTE >00           ; Reserved
       DATA >0000         ; Pointer to power-up list
       DATA PRGLST        ; Pointer to program list
       DATA >0000         ; Pointer to DSR list
       DATA >0000         ; Pointer to subprogram list
PRGLST DATA >0000         ; Next program list entry
       DATA MAIN          ; Program address
       BYTE 11            ; Length of name
       TEXT 'DEMO       ' ; Name (don't change the length of this string!!)
       EVEN
MAIN
       CLR  @>6000        ; Switch to bank 0
       .endif
START

* Bank length (excluding header if present)
BANKLEN EQU BANKSZ - (START - HEADER)