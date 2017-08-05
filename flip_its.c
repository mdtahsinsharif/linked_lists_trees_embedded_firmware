//
//  main.c
//  flip bits
//
//  Created by Md Tahsin Sharif on 2017-02-18.
//  Copyright © 2017 Md Tahsin Sharif. All rights reserved.
//

#include <stdio.h>

//flip every two bits
#define FLIP_BITS(x) (((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1))

const int i = 12;

uint32_t clear_first_set_bit(uint32_t num){
        int n = 0;
    int bit = 0;
    int number = num;
    while (bit==0){
        bit = 0x1 & num;
        num >>= 1;
        n++;
        
    }
    n = 0x1 << n;
    number &= ~(n);
    return n;
}

uint32_t set_bit (uint32_t num, uint32_t index){
    int n = 0x1 << (index-1);
    return (num | n);
}

int main(int argc, const char * argv[]) {
    printf("Original number: %d\n", i);
    printf("Setting nth bit: %d\n", set_bit(i, 2));
    printf("Clearing first set bit: %d\n", clear_first_set_bit(i));
    printf("Flipping every two bits: %d\n", FLIP_BITS(i+1));
    return 0;
}
