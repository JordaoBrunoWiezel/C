#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar informações de uma legenda
typedef struct {
    int numero;
    char tempoInicial[12]; // hh:mm:ss,xxx
    char tempoFinal[12];   // hh:mm:ss,xxx
    char texto[1000];      // Tamanho arbitrário para o texto da legenda
} Legenda;

int main() {
    // Declaração de ponteiros de arquivo
    FILE *arquivo1, *arquivo2, *arquivoDestino;

    // Nas próximas 12 linhas, pedimos os requisitos do programa ao utilizador e armazenamos os nomes dos arquivos em ponteiros
    char input_file1[50], input_file2[50], output_file[50], duration[12];
    printf("Nome do primeiro ficheiro .srt: ");
    scanf("%s", input_file1);
    printf("Nome do segundo ficheiro .srt: ");
    scanf("%s", input_file2);
    printf("Duração da primeira parte do filme (hh:mm:ss,xxx): ");
    scanf("%s", duration);
    printf("Nome do ficheiro .srt de destino: ");
    scanf("%s", output_file);

    // Abertura dos arquivos
    arquivo1 = fopen(input_file1, "r");
    arquivo2 = fopen(input_file2, "r");
    arquivoDestino = fopen(output_file, "w");

    if (arquivo1 == NULL || arquivo2 == NULL || arquivoDestino == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    // Lógica para a junção dos arquivos .srt
    int duration_second_part;
    sscanf(duration, "%d", &duration_second_part);

    // Copiar legendas do primeiro arquivo para o arquivo de destino
    Legenda legenda;
    while (fscanf(arquivo1, "%d %s --> %s\n", &legenda.numero, legenda.tempoInicial, legenda.tempoFinal) == 3) {
        fgets(legenda.texto, sizeof(legenda.texto), arquivo1);

        // Escrever no arquivo de destino
        fprintf(arquivoDestino, "%d %s --> %s%s", legenda.numero, legenda.tempoInicial, legenda.tempoFinal, legenda.texto);
    }

    // Ajustar os tempos e números de sequência do segundo arquivo e escrever no arquivo de destino
    int numeroAjuste = legenda.numero;
    while (fscanf(arquivo2, "%d %s --> %s\n", &legenda.numero, legenda.tempoInicial, legenda.tempoFinal) == 3) {
        fgets(legenda.texto, sizeof(legenda.texto), arquivo2);

        // Ajustar os tempos de acordo com a duração da segunda parte
        // Ajustar o número de sequência
        legenda.numero += numeroAjuste;

        // Escrever no arquivo de destino
        fprintf(arquivoDestino, "%d %s --> %s%s", legenda.numero, legenda.tempoInicial, legenda.tempoFinal, legenda.texto);
    }

    // Fechamento dos arquivos
    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivoDestino);

    printf("A junção foi concluída. O resultado foi salvo em %s.\n", output_file);

    return 0;
}
