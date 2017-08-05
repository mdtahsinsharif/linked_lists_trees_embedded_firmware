//
//  main.c
//  find unique number
//
//  Created by Md Tahsin Sharif on 2017-02-21.
//  Copyright © 2017 Md Tahsin Sharif. All rights reserved.
//

#include <stdio.h>

//max of two numbers
#define MAX(x,y) (x ^ ((x^y) & -(x<y)))

//min of two numbers
#define MIN(x,y) (y ^ ((x^y) & -(x<y)))


int getUniqueElement(int arr[])
{
    //this variable holds XOR of all the elements which have appeared "only" once.
    int ones = 0 ;
    //this variable holds XOR of all the elements which have appeared "only" twice.
    int twos = 0 ;
    int not_threes ;
    
    for( int x=0; x<10; x++ )
    {
        twos |= ones & x ; //add it to twos if it exists in ones
        ones ^= x ; //if it exists in ones, remove, otherwise, add it
        
        // Next 3 lines of code just converts the common 1's between "ones" and "twos" to zero.
        
        //if x is in ones and twos, dont add it to Threes.
        not_threes = ~(ones & twos) ;
        ones &= not_threes ;//remove x from ones
        twos &= not_threes ;//remove x from twos
    }
    printf("IN FUNC: %d\n", ones);
    return ones;
}


uint32_t find_unique_number_2 (uint32_t array[]){
    uint32_t one = 0, two = 0, inter;
    for (int x = 0; x<9; x++){
        printf("%d\n", array[x]);
        two |= one & array[x];
        one ^= array[x];
        
        inter = ~(one & two);
        one &= inter;
        two &= inter;
    }
    return (uint32_t)one;
}


uint32_t find_unique_number (uint32_t* ptr){
    uint32_t one = 0, two = 0, inter;
    for (int x = 0; x<9; x++){
        printf("%d\n", ptr[x]);
        two |= one & ptr[x];
        one ^= ptr[x];
        
        inter = ~(one & two);
        one &= inter;
        two &= inter;
        
        ptr++;
    }
    return (uint32_t)one;
}

int min(int x, int y)
{
    return y ^ ((x ^ y) & -(x < y));
}

/*Function to find maximum of x and y*/
int max(int x, int y)
{
    return x ^ ((x ^ y) & ~(x < y));
    //return -(x<y);
}


int main(int argc, const char * argv[]) {
    uint32_t array[] = {9, 90, 3, 15, 3, 3, 2, 1, 2, 3};
    int arr[] = {10, 1, 10, 3, 10, 1, 1, 2, 3, 3};
    uint32_t* ptr;
    int ans;
    ptr = (uint32_t*)&array[0];
    ans = getUniqueElement(arr);
    printf("ANSER IS: %d\n\n\n\n", ans);
    printf("MAX: %d\n", MAX(5, 60));
    return 0;
}
