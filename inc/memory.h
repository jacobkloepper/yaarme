#include <stdint.h>
#include <stdlib.h>

typedef struct Memory {
	uint16_t* data;
} Memory;

void mem_init(uint32_t cap);
void mem_destr();

uint8_t read_byte(uint64_t byte);
uint16_t read_word(uint32_t addr);

void write_byte(uint64_t byte_pos, uint8_t byte);