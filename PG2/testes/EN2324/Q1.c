#include <stdio.h>
#include <limits.h>

void activateBits(long long *value, int step) 
{
    int size = sizeof(long long) * CHAR_BIT;
    printf("size: %d\n", size);
    int i = 0;

    while(i < size) 
    {
        *value |= (1LL << i*step);
        i++;
    }
}

int main() 
{
    long long value = 0b010011011;
    int step = 2;

    activateBits(&value, step); // Passa o endereço de value
    printf("Value after activating bits: %d\n", value);

    return 0;

}