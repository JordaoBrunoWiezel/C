#include <stdio.h>
#include <limits.h>

int lowerOnePosition( long data )
{
    int size = sizeof(data)*CHAR_BIT;
    int i = 0;

    while(i < size)
    {
        if(!!(data & (1L << i)) == 1)
            return i;
    i++;
    }
return -1;
}

int main()
{
    long data = 0b00000000000000000000000000000100;
    
    int resp = lowerOnePosition(data);
    printf("%d", resp);

return 0;
}