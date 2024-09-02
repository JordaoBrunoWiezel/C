#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE 256

typedef struct{
 int number; // Número de identificação
 char *name; // Nome (string alojada dinamicamente)
 char *function; // Cargo desempenhado (string alojada dinamicamente)
} Member; 

typedef struct{
 int count; // Quantidade de ponteiros alojados e preenchidos no array
 Member **array; // Array de ponteiros, alojado dinamicamente
} Staff; 

/* destinada a separar e identificar os dados de uma linha, contidos na string indicada por text,
e afetando as variáveis indicadas por number, name e job, respetivamente, com o número
de identificação, o nome e o cargo. A função retorna: 1, em caso de sucesso; 0, se ocorrer
insucesso, devido a conteúdo de text incompleto. 
*/

int lineParse(char *text, int *number, char *name, char *job)
{
    char *token = strtok(text, ";");
    if(token == NULL) return 0;
    *number = atoi(token);

    token = strtok(NULL, ";");
    if(token == NULL) return 0;
    strcpy(name,token);

    token = strtok(NULL, ";");
    if(token == NULL) return 0;
    strcpy(job, token);

    return 1;   
}

/* destinada a criar, em alojamento dinâmico, um elemento Member preenchido com os dados
obtidos da string text. A função retorna o endereço do elemento criado ou NULL, em caso
de insucesso. Neste caso, a função não deve deixar espaço inadequadamente alojado.
Deve utilizar a função lineParse. Sugere-se que use dois arrays auxiliares para armazenar
temporariamente o nome e o cargo, dimensionados com a macro MAX_LINE que se assume já
existir
*/

Member *memberCreate(char *text)
{
    Member *m = (Member *) malloc(sizeof(*m));
    if(m == NULL) return NULL;

    char temp_name[MAX_LINE];
    char temp_function[MAX_LINE];

    if(lineParse(text, &m->number, temp_name, temp_function) == 0)
     {free(m); return NULL;};

    m->name = (char *)malloc(strlen(temp_name) + 1);
    if (m->name == NULL) {free(m); return NULL;}
    strcpy(m->name, temp_name);

    m->function = (char *)malloc(strlen(temp_function) + 1);
    if (m->function == NULL) {free(m->name); free(m); return NULL;}
    strcpy(m->function, temp_function);

    return m;
}

/*que adiciona ao vetor staff uma posição com o ponteiro para o elemento indicado por
member.
Deve usar a função de biblioteca adequada para assegurar o espaço necessário ao novo conteúdo
do array dinâmico. 
*/

void staffAdd(Staff *staff, Member *member)
{
    Member **aux = realloc(staff->array,(staff->count + 1)*sizeof(Member *));
    if(aux == NULL) return;

    staff->array = aux;

    staff->array[staff->count] = member;
    staff->count++;
}