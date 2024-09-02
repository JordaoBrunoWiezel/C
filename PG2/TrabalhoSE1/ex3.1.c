#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

int charLeadingOnes(char value)
{
    int i = CHAR_BIT - 1; // Para sabermos quantos bits tem um char
    int contador = 0;
    while (i >= 0)
    {
        if(!!(value & (1 << i)) == 1)
            contador++;
        else
            break;
    i--;
    }
    return (contador);
}

int utf8Length(const char a[], int i)
{
    char v = a[i];
    int resp;

   resp = charLeadingOnes(v);

    if(resp == 1)
        return (0);
    else if(resp == 0)
        return (1);
    else
        return (resp);
}

// Tabela de indexação para traduzir caracteres especiais da gama 0xc3
char lookup_c3_range[] = {
    'a', // U+00C0 À  c3 80  0
    'a', // U+00C1 Á  c3 81  1
    'a', // U+00C2 Â  c3 82  2
    'a', // U+00C3 Ã  c3 83  3
    'a', // U+00C4 Ä  c3 84  4
    'a', // U+00C5 Å  c3 85  5
    ' ', // U+00C6 Æ  c3 86  6
    'c', // U+00C7 Ç  c3 87  7
    'e', // U+00C8 È  c3 88  8
    'e', // U+00C9 É  c3 89  9
    'e', // U+00CA Ê  c3 8A  10
    'e', // U+00CB Ë  c3 8B  11
    'i', // U+00CC Ì  c3 8C  12
    'i', // U+00CD Í  c3 8D  13
    'i', // U+00CE Î  c3 8E  14
    'i', // U+00CF Ï  c3 8F  15
    'd', // U+00D0 Ð  c3 90  16
    'n', // U+00D1 Ñ  c3 91  17
    'o', // U+00D2 Ò  c3 92  18
    'o', // U+00D3 Ó  c3 93  19
    'o', // U+00D4 Ô  c3 94  20
    'o', // U+00D5 Õ  c3 95  21
    'o', // U+00D6 Ö  c3 96  22
    ' ', // U+00D7 ×  c3 97  23
    'o', // U+00D8 Ø  c3 98  24
    'u', // U+00D9 Ù  c3 99  25
    'u', // U+00DA Ú  c3 9A  26
    'u', // U+00DB Û  c3 9B  27
    'u', // U+00DC Ü  c3 9C  28
    'y', // U+00DD Ý  c3 9D  29
    ' ', // U+00DE Þ  c3 9E  30
    ' ', // U+00DF ß  c3 9F  31
    'a', // U+00E0 à  c3 A0  32
    'a', // U+00E1 á  c3 A1  33
    'a', // U+00E2 â  c3 A2  34
    'a', // U+00E3 ã  c3 A3  35
    'a', // U+00E4 ä  c3 A4  36
    'a', // U+00E5 å  c3 A5  37
    ' ', // U+00E6 æ  c3 A6  38
    'c', // U+00E7 ç  c3 A7  39
    'e', // U+00E8 è  c3 A8  40
    'e', // U+00E9 é  c3 A9  41
    'e', // U+00EA ê  c3 AA  42
    'e', // U+00EB ë  c3 AB  43
    'i', // U+00EC ì  c3 AC  44
    'i', // U+00ED í  c3 AD  45
    'i', // U+00EE î  c3 AE  46
    'i', // U+00EF ï  c3 AF  47
    ' ', // U+00F0 ð  c3 B0  48
    'n', // U+00F1 ñ  c3 B1  49
    'o', // U+00F2 ò  c3 B2  50
    'o', // U+00F3 ó  c3 B3  51
    'o', // U+00F4 ô  c3 B4  52
    'o', // U+00F5 õ  c3 B5  53
    'o', // U+00F6 ö  c3 B6  54
    ' ', // U+00F7 ÷  c3 B7  55
    'o', // U+00F8 ø  c3 B8  56
    'u', // U+00F9 ù  c3 B9  57
    'u', // U+00FA ú  c3 BA  58
    'u', // U+00FB û  c3 BB  59
    'u', // U+00FC ü  c3 BC  60
    'y', // U+00FD ý  c3 BD  61
    ' ', // U+00FE þ  c3 BE  62
    'y', // U+00FF ÿ  c3 BF  63
};

int symNormalize( const char sym[], char *res )
{
    int j = 0;
    int nbytes;
    for(int i=0;sym[i]!='\0';i++)
    {  
        nbytes = utf8Length(sym,i);
        if(nbytes==1)
        {
            res[j] = tolower(sym[i]);

        } else 
            if((unsigned char)sym[i] == 0xc3 && ((unsigned char)sym[i+1] >=0x80 && (unsigned char)sym[i+1] <=0xBF))
        {
            int idx = (unsigned char)sym[i+1] - 0x80;
            res[j] = lookup_c3_range[idx];
            i+=nbytes - 1;
        } else
        {
            res[j] = ' ';
            i+=nbytes - 1;
        }
        j++;
    }
    res[j] = '\0';
return j;
} 

int main() {
    const char inputSymbol[] = "\xc3\x82"; // Exemplo: símbolo Â em UTF-8
    char resultSymbol;
    int bytesProcessed = symNormalize(inputSymbol, &resultSymbol);
    printf("Símbolo resultante: %c\n", resultSymbol);
    printf("Número de bytes processados: %d\n", bytesProcessed);
    return 0;
}
