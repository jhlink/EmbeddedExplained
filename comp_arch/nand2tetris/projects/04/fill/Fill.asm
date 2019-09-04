// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

  @8192       //  Screen size 1D length from 32(columns) * 256(rows)
  D=A
  @scrn_max
  M=D
  @scrn_pos
  M=0 

(KEYLP)       //  Start of infinite loop
  @KBD
  D=M
  @BLACK_FWD
  D; JNE

  @scrn_pos
  D=M

  @SCREEN     //  Set pixel at scrn_pos offset to white
  A=A+D
  M=0

  @scrn_pos   //  If scrn_pos offset == 0, jump to KEYLP 
  D=M
  @KEYLP
  D; JEQ
  @scrn_pos   //  Else decrement then to KEYLP 
  M=M-1

  @KEYLP      //  Repeat loop
  0;JMP

(BLACK_FWD)
  @scrn_pos   //  If scrn_pos offset reached scrn_max (8192) 
  D=M
  @scrn_max
  D=D-M
  @KEYLP      //  Jump to KEYLP
  D; JEQ
  @scrn_pos   
  D=M

  @SCREEN     //  Set pixel to scrn_pos offset to black
  A=A+D
  M=-1

  @scrn_pos   //  Increment scrn_pos for next iteration
  M=M+1

  @KEYLP      //  Repeat loop
  0;JMP
