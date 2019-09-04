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

  @8192
  D=A
  @scrn_max
  M=D
  @scrn_pos
  M=0 

(KEYLP)
  @KBD
  D=M
  @BLACK_FWD
  D; JNE

  @scrn_pos
  D=M

  @SCREEN
  A=A+D
  M=0

  @scrn_pos
  D=M
  @KEYLP
  D; JEQ
  @scrn_pos
  M=M-1

  @KEYLP
  0;JMP

(BLACK_FWD)
  @scrn_pos
  D=M
  @scrn_max
  D=D-M
  @KEYLP
  D; JEQ
  @scrn_pos
  D=M

  @SCREEN
  A=A+D
  M=-1

  @scrn_pos
  M=M+1

  @KEYLP 
  0;JMP
