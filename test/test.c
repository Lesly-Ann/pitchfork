#include <stdint.h>

// FORCEDINLINE definition from spectector-clang/13.c
#ifdef __MSVC__
#define FORCEDINLINE __forceinline
#else
#define FORCEDINLINE __attribute__((always_inline))
#endif

uint64_t publicarray_size = 16;
uint8_t publicarray[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
uint8_t publicarray2[512 * 256] = { 20 };

// The attacker's goal in all of these examples is to learn any of the secret data in secretarray
uint64_t secretarray_size = 16;
uint8_t secretarray[16] = { 10,21,32,43,54,65,76,87,98,109,110,121,132,143,154,165 };

// 'volatile' ensures it's actually in memory
volatile uint8_t benignIndex = 0;

// this is mostly used to prevent the compiler from optimizing out certain operations
volatile uint8_t temp = 0;

// In all of these examples, the arguments to the functions are attacker-controlled

void case_1(uint64_t idx, uint8_t val, uint64_t idx2) {

    if (idx < publicarray_size) {
      publicarray2[publicarray[idx] * 512] = val;
    }
    
}

// Provided just so this can compile into a complete binary.
// Clearly, these inputs will not result in leaked secrets themselves.
int main() {
    case_1(0, 0, 0);
    return 0;
}
