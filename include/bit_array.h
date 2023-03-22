#ifndef __BIT_ARRAY_H__
#define __BIT_ARRAY_H__

#include <stddef.h> /*__uint64_t*/
#include <stdint.h>

typedef __uint64_t bit_arr_t;

bit_arr_t BitArrSetBitOn(bit_arr_t bit_arr, __uint64_t index); 

bit_arr_t BitArrSetBitOff(bit_arr_t bit_arr, __uint64_t index);

bit_arr_t BitArrSetBit(bit_arr_t arr, __uint64_t index, int bool_val);

int BitArrGetValBit(bit_arr_t bit_arr, __uint64_t index);

bit_arr_t BitArrFlipBit(bit_arr_t bit_arr, __uint64_t index);

bit_arr_t BitArrRotateArrR(bit_arr_t bit_arr, __uint64_t shift);

bit_arr_t BitArrRotateArrL(bit_arr_t bit_arr, __uint64_t shift);

__uint64_t BitArrCountOn(bit_arr_t bit_arr);

__uint64_t BitArrCountOff(bit_arr_t bit_arr);

bit_arr_t BitArrSetAll(bit_arr_t bit_arr);

bit_arr_t BitArrResetAll(bit_arr_t bit_arr);

bit_arr_t BitArrMirror(bit_arr_t bit_arr);

char *BitArrToString(bit_arr_t bit_arr, char *dest);

bit_arr_t BitArrFlipAll(bit_arr_t bit_arr);

#endif






