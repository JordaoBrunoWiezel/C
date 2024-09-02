#include <stdio.h>
#include <limits.h>

int checkOnesSequence(unsigned long data, int minSize )
{
    int size = sizeof(data) * CHAR_BIT;
    printf("%d\n", size);
    int i = 0, count = 0;

    while(i < size)
    {
        if(!!(data &(1UL << i)) == 1)
        {
            count++;
            if(count >= minSize)
                return 1;
        } else 
            count = 0;
    i++;
    }
return 0;
}

int main()
{
    unsigned long data = 0b1111110000001111000000111000011;
    int minSize = 4;

    int resp = checkOnesSequence(data, minSize); // Passa o endereço de value
    printf("Ha pelo menos MinSize de 1: %d\n", resp);

    return 0;
}