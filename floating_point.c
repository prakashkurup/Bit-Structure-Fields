/*
 * =====================================================================================
 *
 *       Filename:  floating_point.c
 *
 *    Description:  IEEE 754 Floating Point representation: Mantissa,
 *                  Exponent, Sign.
 *
 *        Version:  1.0
 *        Created:  11/04/2016 10:44:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Kurup (pk), prakashkurup7@gmail.com
 *        Company:  NONE
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define FLOATPT(fp) (*((FloatPt *)&fp))

typedef union {
  // Assuming little-endian system
  float fValue; // 4 bytes

  struct {
    uint32_t mantissa: 23; // Bit:0 to Bit:22
    uint32_t exponent: 8;  // Bit:23 to Bit:30
    uint32_t sign: 1;      // Bit:31
  };

} FloatPt;

int main(void)
{
  float fp;

  puts("Enter any single precision floating point value: Positive / Negative / 0.0 / -0.0 / NAN/ INFINITY / -INFINITY");

  scanf("%f", &fp);

  printf("Float value: %f\n", FLOATPT(fp).fValue);
  printf("Mantissa: %d\n", FLOATPT(fp).mantissa);
  printf("Exponent: %d\n", FLOATPT(fp).exponent);
  printf("Sign: %d\n", FLOATPT(fp).sign);
  
  /* You can manipulate the manitssa, exponent and sign to make your floating point number */

  return 0;
}
