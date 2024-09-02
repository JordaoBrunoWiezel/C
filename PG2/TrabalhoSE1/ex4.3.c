#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <dirent.h>

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
int main(int argc, char **argv ){
    if( argc<2 || argc>3 ){
        fprintf( stderr, "Usage: %s directory_path [name]\n", argv[0] );
        return 1;
    }
    DIR* d = opendir( argv[1] );
    if( d == NULL ){
        fprintf( stderr, "Error: Cannot open path \"%s\"\n", argv[1] );
        return 2;
    }
    struct dirent *de;
    while((de = readdir(d)) != NULL) {
        if(de->d_type == DT_REG && (argc == 2 || strNormSelect(de->d_name, argv[2]))) {
            fprintf( stderr, "File: %s\n", de->d_name);
        }
    }

    closedir(d);

    return 0;
}
