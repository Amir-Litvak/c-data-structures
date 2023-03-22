#include <stddef.h>		/* __uint64_t */
#include <limits.h> 	/* CHAR_BIT */
#include <stdint.h>

#include "bit_array.h"

#define BITS (sizeof(__uint64_t) * CHAR_BIT)

bit_arr_t BitArrSetBitOn(bit_arr_t bit_arr, __uint64_t index)
{
	return (bit_arr|((__uint64_t)1 << index));
}

bit_arr_t BitArrSetBitOff(bit_arr_t bit_arr, __uint64_t index)
{
	return (bit_arr & ~(1 << index));
}

bit_arr_t BitArrSetBit(bit_arr_t bit_arr, __uint64_t index, int bool_val)
{
	return (1 == bool_val) ? BitArrSetBitOn(bit_arr, index) : BitArrSetBitOff(bit_arr, index); 
}

int BitArrGetValBit(bit_arr_t bit_arr, __uint64_t index)
{
	return (1 & (bit_arr >> index));
}

bit_arr_t BitArrFlipBit(bit_arr_t bit_arr, __uint64_t index)
{
	return (bit_arr^(1 << index));
}

bit_arr_t BitArrRotateArrR(bit_arr_t bit_arr, __uint64_t shift)
{
	return (bit_arr >> (shift % BITS))|(bit_arr << (BITS - (shift % BITS)));
}

bit_arr_t BitArrRotateArrL(bit_arr_t bit_arr, __uint64_t shift)
{
	return (bit_arr << shift)|(bit_arr >> (BITS - shift));
}

__uint64_t BitArrCountOn(bit_arr_t bit_arr)
{
	__uint64_t count = 0;
	while (0 < bit_arr) 
	{
		bit_arr &= (bit_arr-1);
		++count;
	}
    return count;
}

__uint64_t BitArrCountOff(bit_arr_t bit_arr)
{
	return  (BITS - BitArrCountOn(bit_arr));
}

bit_arr_t BitArrSetAll(bit_arr_t bit_arr)
{
	return (~0);
}

bit_arr_t BitArrResetAll(bit_arr_t bit_arr)
{
	return 0;
}

bit_arr_t BitArrMirror(bit_arr_t bit_arr)
{
	bit_arr_t reversed_arr = 0; 
	__uint64_t i = 0;

	for(i = 0; i < BITS; ++i)
	{
		reversed_arr |= ((bit_arr >> i) & 1) << (BITS - i - 1);
	}

	return reversed_arr;
}

char *BitArrToString(bit_arr_t bit_arr, char *dest)
{
	int i = 0;
	for (i = (BITS - 1); i >= 0; --i)
	{
		dest[i] = (bit_arr & 1) + '0';
		bit_arr >>= 1;
	}
	dest[BITS] = '\0';
	return dest;
}

bit_arr_t BitArrFlipAll(bit_arr_t bit_arr)
{
	return (~bit_arr);
}

