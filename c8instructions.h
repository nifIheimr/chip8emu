#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "chip8.h"
//00E0
void CLS(Chip8 chip8) {
    memset(chip8.screen, 0, sizeof(chip8.screen)); //sets every value in the screen to zero
}