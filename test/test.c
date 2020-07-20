#include <stdint.h>

// FORCEDINLINE definition from spectector-clang/13.c
#define MASK(x, size) (x & (size - 1))

uint32_t publicarray_size = 16;
uint8_t publicarray[16];
uint8_t publicarray2[512 * 256];

// The attacker's goal in all of these examples is to learn any of the secret data in secretarray
uint32_t secretarray_size = 16;
uint8_t secretarray[16];


// this is mostly used to prevent the compiler from optimizing out certain operations
volatile uint8_t temp = 0;

// In all of these examples, the arguments to the functions are attacker-controlled
static void leakByteLocalFunction(uint8_t leakThis) { temp &= publicarray2[leakThis * 512]; }

/* Pitchfork detects a vulnerability while this is actually a false
   alarm */
/* void case_1(uint32_t idx, uint8_t val) { */
/*   uint8_t toleak = publicarray[idx]; */

/*   toleak = toleak & 0xf0; */
/*   toleak = toleak & 0x0f; */
/*   if (idx < publicarray_size) { */
/*     leakByteLocalFunction(toleak); */
/*   } */
/* } */

/* Pitchfork cuts vulnerable paths after finding a vulnerability. Thus
   it only detects the first vulnerability in this example. */
void case_1(uint32_t idx1, uint32_t idx2) {
    if (idx1 < publicarray_size && idx2 < publicarray_size) {
        temp &= publicarray2[publicarray[idx1] * 512];
        temp &= publicarray2[publicarray[idx2] * 512];
    }
}

// Provided just so this can compile into a complete binary.
// Clearly, these inputs will not result in leaked secrets themselves.
int main() {
  case_1(0, 0);
    return 0;
}
