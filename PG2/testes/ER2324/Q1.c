#include <stdio.h>
#include <limits.h>

int isMirror(unsigned long value)
{
    int size = sizeof(unsigned long) * CHAR_BIT;
    printf("%d\n", size);
    int i = 0;

    while(i < size/2)
    {
        if(!!(value & (1UL << i)) != (!!(value & (1UL << (size - 1 - i)))))
            return 0;
        i++;
    }
    return 1;
}

int main() 
{
    unsigned long value = 0b11000000000000000000000000000011;
    int resp = isMirror(value); // Passa o endereço de value
    printf("%d\n", resp);

    return 0;

}