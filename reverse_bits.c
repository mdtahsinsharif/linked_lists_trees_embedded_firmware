//
//  main.c
//  reverse bits
//
//  Created by Md Tahsin Sharif on 2017-02-26.
//  Copyright © 2017 Md Tahsin Sharif. All rights reserved.
//

#include <stdio.h>

#define FIND_MSB(x) ((0x80000000 & x)>>31)

//reversing 8 bits in O(1)
u_char reverse_character(u_char y)
{
    y = ((y & 0xF0) >> 4) | ((y & 0x0F) << 4);
    y = ((y & 0x33) << 2) | ((y & 0xCC) >> 2);
    y = ((y & 0xAA) >> 1) | ((y & 0x55) << 1);
    return y;
}

//reversing 32 bits in O(1)
uint32_t reverse_integer(uint32_t y)
{
    y = ((y & 0xFFFF0000) >> 16) | ((y & 0x0000FFFF) << 16);
    y = ((y & 0x00FF00FF) << 8) | ((y & 0xFF00FF00) >> 8);
    y = ((y & 0x0F0F0F0F) << 4) | ((y & 0xF0F0F0F0) >> 4);
    y = ((y & 0x33333333) << 2) | ((y & 0xCCCCCCCC) >> 2);
    y = ((y & 0x55555555) << 1) | ((y & 0xAAAAAAAA) >> 1);
    return y;
}

//reverse bits in O(n) time
uint32_t reverse_time(uint32_t x){
    int num = 0;
    int y;
    while (x!=0){
        num <<= 1;
        y = x & 0x1;
        num += y;
        x >>= 1;
    }
    return num;
}

//addition using only bitwise operators
uint32_t addition (uint32_t num1, uint32_t num2){
    
    uint32_t res = num1 ^ num2;
    uint32_t carry = num1 & num2;
    uint32_t sc = 0; //shifted carry
    for (; carry != 0; ){
        sc = carry << 1;
        carry = res & sc;
        res ^= sc;
    }
    return res;
}

//find MSB of character
uint32_t character (u_char i){
    int r = 0;
    static int array[] = {0,1,
                          2,2,
                          3,3,3,3,
                          4,4,4,4,4,4,4,4};
    if (i & 0xF0) {
        r += 4;
        i>>=4;
    }
    if (i & 0x0C) {
        r += 2;
        i>>=2;
    }
    if (i & 0x02) {
        r += 1;
        i>>=1;
    }
    return r + array[i];
}


//find MSB of an integer
unsigned int msb32(unsigned int x)
{
    static const unsigned int msb_val[] =
    {0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4};
    
    unsigned int r = 0;
    if (x & 0xFFFF0000) {
        r += 16;
        x >>= 16;
    }
    if (x & 0x0000FF00) {
        r += 8;
        x >>= 8;
    }
    if (x & 0x000000F0) {
        r += 4;
        x >>= 4;
    }
    return (msb_val[x] + r);
}

//find string length
uint32_t find_length(char* str){
    
    if (str == NULL) return 0;
    uint32_t i = 0;
    while (str[i]!='\0'){
        i++;
    }
    return i;
}

void func0(void){
    printf("\nFUNC 0 being executed.");
}

void func1(){
    printf("\nFUNC1 being executed.");
}

void func2(){
    printf("\nFUNC2 being executed.");
}



void function (int x){
    void (*array[])(void) = {func0, func1, func2};
    array[x]();
}


int main(int argc, const char * argv[]) {
    
    char c[] = "String";
    printf("Reversing bits in 0(n) time: %u\n", reverse_time(11));
    printf("Reversing bits in 0(1) time(integer): %u\n", reverse_integer(11));
    printf("Reversing bits in 0(1) time(character): %u\n", reverse_character(11));
    printf("Addition: %u\n", addition(13, 13));
    printf("Character: %u\n", character(0xC1));
    printf("Find Length: %u\n", find_length(c));
    
    uint32_t (*foo)(char*);
    foo = find_length;
    uint32_t j = foo(c);
    printf("%u", j);
    
    function(2);
    
    pthread_mutex_t x;
    
    
    
    return 0;
}
