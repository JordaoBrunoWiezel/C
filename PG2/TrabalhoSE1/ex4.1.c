#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strNormSelect( const char *str1, const char *str2 )
{
    char normalizada1_str1[50];
    char normalizada2_str2[50];

    for(int i=0; str1[i] != '\0'; i++) 
        normalizada1_str1[i] = tolower(str1[i]);

    for(int j=0; str2[j] != '\0'; j++) 
        normalizada2_str2[j] = tolower(str2[j]);

    if(strstr(normalizada1_str1, normalizada2_str2) ==NULL ) 
        return (0);
    else 
        return (1);   
}

int main(void) {
    
    char *str1 = "olaaloolaalo";
    char *str2 = "alo";
    
    int resp = strNormSelect(str1, str2);
    printf("%d", resp);
}