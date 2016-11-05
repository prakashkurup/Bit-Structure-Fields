/*
 * =====================================================================================
 *
 *       Filename:  bit_structures.c
 *
 *    Description:  Bit masking using structure bit fields.
 *
 *        Version:  1.0
 *        Created:  10/19/2016 11:57:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Kurup (pk), prakashkurup7@gmail.com
 *        Company:  NONE
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BIT(reg) ((*(BitStructType *)&reg))

/* Assuming little endian architecture */
typedef union {
  uint32_t full32int;

  /* Individual bits in 32-bit unsigned int */
  struct {
    volatile uint8_t bit0  : 1; volatile uint8_t bit1  : 1;  volatile uint8_t bit2  : 1; volatile uint8_t bit3  : 1;
    volatile uint8_t bit4  : 1; volatile uint8_t bit5  : 1;  volatile uint8_t bit6  : 1; volatile uint8_t bit7  : 1;
    volatile uint8_t bit8  : 1; volatile uint8_t bit9  : 1;  volatile uint8_t bit10 : 1; volatile uint8_t bit11 : 1;
    volatile uint8_t bit12 : 1; volatile uint8_t bit13 : 1;  volatile uint8_t bit14 : 1; volatile uint8_t bit15 : 1;
    volatile uint8_t bit16 : 1; volatile uint8_t bit17 : 1;  volatile uint8_t bit18 : 1; volatile uint8_t bit19 : 1;
    volatile uint8_t bit20 : 1; volatile uint8_t bit21 : 1;  volatile uint8_t bit22 : 1; volatile uint8_t bit23 : 1;
    volatile uint8_t bit24 : 1; volatile uint8_t bit25 : 1;  volatile uint8_t bit26 : 1; volatile uint8_t bit27 : 1;
    volatile uint8_t bit28 : 1; volatile uint8_t bit29 : 1;  volatile uint8_t bit30 : 1; volatile uint8_t bit31 : 1;
  };

  /* Individual bytes in 32-bit unsigned int */
  struct {
    uint8_t byte0; // b7 to b0
    uint8_t byte1; // b15 to b8
    uint8_t byte2; // b23 to b16
    uint8_t byte3; // b31 to b24
  };

  /* Individual nibbles ---> 4 bits */
  struct {
    uint8_t nib0 : 4; uint8_t nib1 : 4; uint8_t nib2 : 4; uint8_t nib3 : 4;
    uint8_t nib4 : 4; uint8_t nib5 : 4; uint8_t nib6 : 4; uint8_t nib7 : 4;
  };

} BitStructType;

int main(void)
{
  uint32_t reg = 0x12345678;
  
  BIT(reg).byte0 = 0xEF;
  BIT(reg).byte1 = 0xBE;
  BIT(reg).byte2 = 0xAD;
  BIT(reg).byte3 = 0xDE;

  printf("0x%08x\n", reg);

  return 0;
}
