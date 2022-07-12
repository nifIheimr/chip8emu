#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "chip8.h"

/*DOCUMENTATION:
    REGISTERS: We have 16 8bit registers, identified from V0 to VF. The last register (VF) will be reserved for operation result flags
    MEMORY: 4096 Bytes (4K) ranging from 0x000 to 0xFFF segmented in three sections:
        - From 0x000 to 0x1FF: Interpreter
        - From 0x050 to 0x0A0: Storage for 16 built in characters
        - From 0x200 to 0xFFF: From here we'll store every instruction, every free byte after that will be free for our use
    INDEX REGISTER: 16Bit register used to store memory addresses while in use in operations.


    SCREEN: Our screen array will hold either 1 or 0 to draw our graphics on the screen, we don't need anything else due to the graphics being 1bit. The graphics are 
    drawn using sprites and XORing with the corresponding pixels on the screen
*/

int main(int argc, char *argv[]) {
    
    if(argc != 2) {
        perror("WRONG NUMBER OF ARGUMENTS");
        exit(errno);
    }
    
    Chip8 chip8;

    initializeChip8(&chip8);

    char const *ROM = argv[0];

    bool turnOff;

    while(!turnOff) {
        turnOff = keyboardInput(&chip8);

    }


    return 0;
}

int initializeChip8(Chip8 *chip8) {
    chip8->PC = INST_ADDRESS; //Initialize PC to write instructions to 0x200

    printf("INITIALIZED PC TO 0x%03X\n", INST_ADDRESS);

    for (int i = 0; i < FONTSET_SIZE; i++) {
        chip8->memory[FONTSET_ADDRESS + i] = fontset[i]; //Load fontset in memory
    }

    printf("LOADED FONTSET TO 0x%03X\n", FONTSET_ADDRESS);

    return 0;
}


int loadROM(Chip8 *c, char const *ROM) {\
    FILE *romFile; 

    if((romFile = fopen(ROM, "rb")) == NULL) { //Reading file in binary format
        return -1;
    }

    long size = ftell(romFile); //Gets total filesize for the ROM
    char *buffer = malloc(sizeof(char) * size);
    char readChar;

    fseek(romFile, size, SEEK_SET); //Sets file pointer at the beggining of the file

    while((readChar = getc(romFile)) != EOF) {
        strcat(buffer, &readChar);
    }

    fclose(romFile);

    //Load into memory
    for (long i = 0; i < size; i++) {
        c->memory[INST_ADDRESS + i] = buffer[i]; //We're loading the program instructions so we start in 0x200
    }
    
    free(buffer);

    return 0;
}



void update(Chip8 *c) {

}


bool keyboardInput(Chip8 *c) {
    return true;
}
