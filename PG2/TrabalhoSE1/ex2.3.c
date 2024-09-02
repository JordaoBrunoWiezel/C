#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

int charLeadingOnes(char value)
{
    int i = CHAR_BIT - 1; /* Para sabermos quantos bits tem um char */
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

int printSymbolCode(const char a[], int i)
{
    int byte = utf8Length(a, i);

    if(byte == 0) /* Significa que tem 1 byte(posição subsequente) */
        return 0;

    int z = i;
    while(z < i + byte)
    {
        printf("%c", a[z]);
        z++;
    }

    printf("(");

    int j = 0;
    while(j < byte)
    {
        printf("%02x", (unsigned char)a[i + j]);

        if(j < byte-1) 
            printf(" ");

        j++;
    }

    printf(")");
    return (byte);
}

int main() 
{
    setlocale(LC_ALL, "Portuguese");

    FILE *file;
    int answer;
    char frase[100];

    /* Aqui foi so para criar um ficheiro atraves de codigos
    file2 = fopen("C:\\Users\\Jordão Bruno\\Desktop\\Aulas pg\\Códigos pg2\\Trabalho\\texto.txt", "w");
    fprintf(file2, "Acentuação e símbolos como «€».");
    fclose(file2);
    */
    do{

        printf("------------------------------------------------------------\nQue ficheiro quer abrir com codificacao de simbolos: \n------------------------------------------------------------");

        printf("\n->Ficheiro 1(1)\n->Ficheiro 2(2)\n->Ficheiro 3(3)\n->EXIT(4)\n\nResposta(1,2,3 ou 4): ");

        scanf("%d",&answer);

        if(answer==4) 
            break;

        if(answer!=1 && answer!=2 && answer!=3 && answer!=4)
        {
            printf("\nOpção inválida\n");
            break;
        }

        if(answer == 1)
        {
            file = fopen("texto.txt", "r");

        }else if(answer == 2)
        {

            file = fopen("texto2.txt", "r");

        }else if(answer == 3)

        {
            file = fopen("texto3.txt", "r");
        }

        if(file == NULL)
        {
            printf("ficheiro nulo ou nao encontrado.\n");
            return (1);
        }

        // Se a resposta não for 4 então ... (isso nao fez sentido)
        if(answer !=4){
            while(fgets(frase, sizeof(frase), file)) { //endereço do buffer onde a string lida será armazenada, tamanho, onde será lido (FILE*)
                int lenght = strlen(frase); // Verifica o tamanho da string
                if(lenght > 0 && frase[lenght - 1] == ' ') { // Remove o espaço no final da line
                    frase[lenght - 1] = '\0'; // Adiciona o /0 no final da string
                }
                int i = 0;
                while(frase[i] != '\0') {
                    int temp = printSymbolCode(frase, i);// Processa a linha usando a função printSymbolCode
                    i += temp; // Pula para a proxima letra, temp possui o nº de bytes
                }			
            }
        } else {
            while(fgets(frase, sizeof(frase), file) != NULL) {
                printf("%s", frase);  // Se a resposta for 4, simplesmente le e escreve no terminal o coteudo do arquivo
            }
        }

        printf("\n\n\n");
        printf("Pressione ENTER para continuar ....");
        getchar(); 
        getchar(); 

        system("cls");

    }while(1);

    fclose(file);

return 0;
}