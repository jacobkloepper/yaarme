#include "common.h"
#include "memory.h"

// Data sizes:
// - 8 bits
// word - 2 bytes
// address space: 32 bits

Memory memory;

void mem_init(uint32_t cap) {
	memory.data = (uint16_t*) malloc(cap);
}

void mem_destr() {
	free(memory.data);
}

uint8_t read_byte(uint64_t byte_pos) {
	return (uint8_t) ((memory.data)[byte_pos >> 1] >> (8 * (byte_pos & 0x0001))) & 0xFF;
}

uint16_t read_word(uint32_t addr) {
	return (uint16_t) (memory.data)[addr];
}

void write_byte(uint64_t byte_pos, uint8_t byte) {
	if (byte_pos & 0x0001) {
		memory.data[byte_pos >> 1] = ((uint16_t)byte << 8) | (memory.data[byte_pos >> 1] & 0x00FF);
	}
	else {
		memory.data[byte_pos >> 1] = ((uint16_t)byte) | (memory.data[byte_pos >> 1] & 0xFF00);
	}
}
