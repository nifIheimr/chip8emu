CC = gcc
OBJ = main.c chip8.h c8instructions.h
BIN  = chip8emu
RM = rm -f
CFLAGS = -g 

chip8emu: ${OBJ}
	${CC} ${CFLAGS} ${OBJ}


clean: 
	${RM} $(OBJ) $(BIN)