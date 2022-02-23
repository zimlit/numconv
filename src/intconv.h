#ifndef __INT_H__
#define __INT_H__

#include <stdint.h>

#define BYTES_TO_INT(num) num[0] | ((uint64_t)num[1] << 8) | ((uint64_t)num[2] << 16) | ((uint64_t)num[3] << 24) | ((uint64_t)num[4] << 32) | ((uint64_t)num[5] << 40) | ((uint64_t)num[6] << 48) | ((uint64_t)num[7] << 56)

#define ADD(l, r) BYTES_TO_INT(l) + BYTES_TO_INT(r);
#define SUB(l, r) BYTES_TO_INT(l) - BYTES_TO_INT(r);
#define MUL(l, r) BYTES_TO_INT(l) * BYTES_TO_INT(r);
#define DIV(l, r) BYTES_TO_INT(l) / BYTES_TO_INT(r);
#define MOD(l, r) BYTES_TO_INT(l) % BYTES_TO_INT(r);
#endif // __INT_H__