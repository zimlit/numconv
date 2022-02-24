#ifndef __FLOAT_H__
#define __FLOAT_H__

#include <math.h>
#include <stdint.h>
#include "intconv.h"
#include <stdio.h>


extern inline double bytesToDouble(uint8_t num[8]) {
    uint64_t n = BYTES_TO_INT(num);

    uint64_t sign = n >> 63;
    uint64_t exponent = (n >> 52) & 0b011111111111;
    uint64_t mantissa = n & 4503599627370495;

    if ((exponent == 0) && (mantissa == 0)) {
        if (sign) {
            return -0.0;
        }
        return 0.0;
    }

    if (exponent == 2047) {
        if (mantissa == 0) {
            if (sign) {
                return -INFINITY;
            }
            return INFINITY;
        }
        return NAN;
    }

    double m = (double)mantissa;
    m = m * pow(2, -52);

    if (exponent == 0) {
        exponent -= 1022;
    } else {
        exponent -= 1023;
        m += 1;
    }

    if (sign) {
        return -(m * pow(2, exponent));
    }
    return m * pow(2, exponent);
 }

#define ADDF(l, r) bytesToDouble(l) + bytesToDouble(r);
#define SUBF(l, r) bytesToDouble(l) - bytesToDouble(r);
#define MULF(l, r) bytesToDouble(l) * bytesToDouble(r);
#define DIVF(l, r) bytesToDouble(l) / bytesToDouble(r);
#define MODF(l, r) bytesToDouble(l) % bytesToDouble(r);

#endif // __FLOAT_H__