#include <cstdint>

#define WIDTH 64
#define HEIGHT 32
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

class Chip8 {
    public:
        uint8_t registers[16]{};
        uint8_t memory[4096]{};
        uint16_t stack[16]{};
        uint16_t index{};
        uint16_t PC{};
        uint16_t SP{};
        uint8_t delayTimer{};
        uint8_t soundTimer{};
        uint8_t inputKeys[16]{};
        uint32_t screen[WIDTH * HEIGHT]{};
        uint16_t opcode{};

        void Chip8::Update() {
            opcode = 


            if (soundTimer > 0) {
                --soundTimer;
            }
            
            if(delayTimer > 0) {
                delayTimer--;
            }

        }


};