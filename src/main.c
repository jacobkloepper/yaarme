#include "common.h"
#include "memory.h"

int main() {
	mem_init(32);
	
	write_byte(0, 0xFF);
	write_byte(1, 0xEE);
	write_byte(2, 0xDD);
	write_byte(3, 0xCC);
	
	for (int i = 0; i < 4; i++) {
		printf("byte[%d]: %x\n", i, read_byte(i));
	}
	
	for (int i = 0; i < 2; i++) {
		printf("word[%d]: %x\n", i, read_word(i));
	}
	
	mem_destr();
	
}
