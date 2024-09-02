#include <stdio.h>
#include <string.h>

typedef struct{ // Descritor de uma localização de linha
 int fileIdx; // índice no array de ponteiros para os nomes dos ficheiros
 int line; // número da linha no texto
 long offset; // posição do início da linha no ficheiro
} Location;

typedef struct{ // Descritor de um vetor de localizações de linhas
 int space; // quantidade de elementos alojados no array dinâmico
 int count; // quantidade de elementos ocupados no array dinâmico
 Location *data; // aponta array alojado dinamicamente
} VecLoc;

// que retorna a contagem de ficheiros que contêm alguma localização com o número de linha passado em line. 


int count_line_in_files(VecLoc *vec, int line)
{

    int count = 0; // Contador para os arquivos que contêm a linha especificada
    int current_file = -1; // Índice do arquivo atual, inicializado para um valor inválido
    int i = 0;

    while(i < vec->count)
    {
        if(vec->data[i].line == line && vec->data[i].fileIdx != current_file)
        {
            count++;
            current_file = vec->data[i].fileIdx; // Atualiza o arquivo atual
        }
    i++;
    }
}

// que remove do vetor de localizações, passado em vec, a localização com índice loc_idx mantendo o vetor ordenado. 

void delete_location(VecLoc *vec, int loc_idx)
{
    int i = loc_idx;

    // Desloca todos os elementos após loc_idx uma posição à esquerda
    while(i < vec->count)
    {
        vec->data[i] = vec->data[i+1];
    i++;
    }

    vec->count--;
}

/* que se destina a inserir no vetor, indicado por vec, um novo elemento com os dados passados
em loc, mantendo o vetor ordenado e sem repetições. Se já existir um elemento igual, não se
realiza qualquer modificação. A função deve assegurar espaço no vetor, alojado dinamicamente,
para o novo elemento; se necessário, deve redimensionar o espaço, fazendo-o em blocos de 10
elementos, com recurso à função realloc de biblioteca.
A função insert_location retorna: 0, caso a localização indicada por loc já exista no
vetor; 1, em caso de sucesso na inserção; -1, em caso de insucesso por falta de memória de
alojamento dinâmico. Note que, caso não haja memória dinâmica disponível, o vetor deve ser
mantido inalterado.
Sugere-se que percorra o vetor sequencialmente para identificar o ponto de inserção do novo
elemento.
*/

int insert_location(VecLoc *vec, Location *loc) { // NO MANITO, APENAS NO

    // Verificar se o vetor de localizações é nulo ou se a localização é nula
    if (vec == NULL || loc == NULL) {
        return -1;
    }

    // Percorrer o vetor para verificar se a localização já existe e encontrar o ponto de inserção
    int insert_idx = 0;
    for (int i = 0; i < vec->count; i++) {
        if (vec->data[i].fileIdx == loc->fileIdx && vec->data[i].line == loc->line) {
            // A localização já existe no vetor
            return 0;
        }
        if (vec->data[i].fileIdx < loc->fileIdx || (vec->data[i].fileIdx == loc->fileIdx && vec->data[i].line < loc->line)) {
            insert_idx = i + 1;
        } else {
            break;
        }
    }

    // Verificar se há espaço suficiente no vetor, se não, realocar
    if (vec->count >= vec->space) {
        int new_space = vec->space + 10;
        Location *new_data = realloc(vec->data, new_space * sizeof(Location));
        if (new_data == NULL) {
            // Falha na realocação de memória
            return -1;
        }
        vec->data = new_data;
        vec->space = new_space;
    }

    // Mover os elementos para a direita para criar espaço para a nova localização
    for (int i = vec->count; i > insert_idx; i--) {
        vec->data[i] = vec->data[i - 1];
    }

    // Inserir a nova localização
    vec->data[insert_idx] = *loc;
    vec->count++;

    // Inserção bem-sucedida
    return 1;
}