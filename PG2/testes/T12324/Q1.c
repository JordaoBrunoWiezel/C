#include <stdio.h>
#include <limits.h>

int countTrailingZeros( unsigned long long data)
{
    int size = sizeof(data) * CHAR_BIT;
    printf("%d\n", size);
    int i = 0, count = 0;

    while(i<size)
    {
        if(!!(data & (1ULL << i)) == 0)
            count++;
        else
            break;
    i++;
    }
return count;
}

int main()
{
    unsigned long long data = 0b11111100000011110000001110000111111110000001111000000111000000;
    int resp;

    resp = countTrailingZeros(data);

    printf("%d\n", resp);
    return 0;
}