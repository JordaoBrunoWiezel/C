#include <stdio.h>

//2.[4] Crie a função int longest_substring(char str[]) que retorna o comprimento da maior 
// subsequência de caracteres consecutivos idênticos na string fornecida.

int longest_substring(char str[]){

    int count1 = 0, count2 = 0;

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i]==str[i+]){
            count1++;
                if(count1 > count2){
                    count2 = count1;
                }
        } else{
            count1 = 0;
        }
    }
    
return count2+;
}