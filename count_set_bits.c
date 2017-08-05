//
//  main.c
//  count set bits
//
//  Created by Md Tahsin Sharif on 2017-02-18.
//  Copyright © 2017 Md Tahsin Sharif. All rights reserved.
//

#include <stdio.h>

//find set bits indicating the number of bits to flip
#define NUMBER_OF_BITS_TO_FLIP(x,y) (x^y)

const uint32_t i = 0xF, A = 0xFCAB, B = 0xAABF;

uint32_t count_set_bits_constant_time(uint32_t num) //constant time O(1)
{
    num = num - ((num >> 1) & 0x55555555);
    num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
    num = (((num + (num >> 4)) & 0x0F0F0F0F) * 0x01010101)>>24;
    return num;
}

uint32_t count_set_bits(uint32_t x){ // O(m) where m = number of 1s
    uint32_t n = 0;
    while (x!=0){
        x = x&(x-1);
        n++;
    }
    return n;
}

int main(int argc, const char * argv[]) {
    uint32_t m = count_set_bits(i);
    uint32_t n = count_set_bits_constant_time(i+1);
    printf("Calculated Set bits in O(1) time: %d\n", n);
    printf("Calculated Set bits in O(m) time: %d\n", m);
    
    printf("Number of bits to convert from A to B: %d\n", count_set_bits_constant_time(NUMBER_OF_BITS_TO_FLIP(A, B)));
    
    return 0;
}
