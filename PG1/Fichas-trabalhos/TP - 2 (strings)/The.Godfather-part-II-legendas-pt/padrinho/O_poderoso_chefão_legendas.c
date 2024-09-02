#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIMESTRING 13 // "hh:mm:ss,xxx\0"
#define MAX_LINE 1024 // Tamanho máximo de uma linha do arquivo

// Função para converter uma string de tempo para milissegundos
long time_to_ms(const char *time) {
    int h, m, s, ms;
    sscanf(time, "%02d:%02d:%02d,%03d", &h, &m, &s, &ms);
    return ((long)h * 3600000) + ((long)m * 60000) + ((long)s * 1000) + ms;
}

// Função para converter milissegundos de volta para uma string de tempo
void ms_to_time(long ms, char *time) {
    int h = ms / 3600000; ms %= 3600000;
    int m = ms / 60000;   ms %= 60000;
    int s = ms / 1000;    ms %= 1000;
    sprintf(time, "%02d:%02d:%02d,%03d", h, m, s, (int)ms);
}

// Função para processar o segundo arquivo de legendas e escrevê-lo no arquivo de saída
void process_second_file(FILE *src, FILE *dest, long offset, int seq_num) {
    char buffer[MAX_LINE];
    char start[MAX_TIMESTRING], end[MAX_TIMESTRING];
    long start_ms, end_ms;

    while (fgets(buffer, MAX_LINE, src)) {
        if (sscanf(buffer, "%d", &seq_num) == 1) {
            fprintf(dest, "%d\n", seq_num); // Escreve o número de sequência

            fgets(buffer, MAX_LINE, src); // Lê a linha do tempo
            sscanf(buffer, "%12s --> %12s", start, end);
            start_ms = time_to_ms(start) + offset;
            end_ms = time_to_ms(end) + offset;
            ms_to_time(start_ms, start);
            ms_to_time(end_ms, end);
            fprintf(dest, "%s --> %s\n", start, end); // Escreve os tempos ajustados
        } else {
            fputs(buffer, dest); // Copia a linha de texto
        }
    }
}

int main() {
    char file1[MAX_LINE], file2[MAX_LINE], file_out[MAX_LINE], last_time[MAX_TIMESTRING];
    long offset_ms;
    int last_seq = 1;

    // Solicita ao usuário as informações dos arquivos e a duração da primeira parte
    printf("Nome do primeiro arquivo .srt: ");
    scanf("%s", file1);
    printf("Nome do segundo arquivo .srt: ");
    scanf("%s", file2);
    printf("Nome do arquivo de saída .srt: ");
    scanf("%s", file_out);
    printf("Tempo final do primeiro arquivo (hh:mm:ss,xxx): ");
    scanf("%s", last_time);

    offset_ms = time_to_ms(last_time); // Converte o tempo final para milissegundos

    FILE *first_srt = fopen(file1, "r");
    FILE *second_srt = fopen(file2, "r");
    FILE *output_srt = fopen(file_out, "w");

    // Verifica se os arquivos foram abertos com sucesso
    if (!first_srt || !second_srt || !output_srt) {
        fprintf(stderr, "Erro ao abrir um dos arquivos. Verifique os nomes e tente novamente.\n");
        if (first_srt) fclose(first_srt);
        if (second_srt) fclose(second_srt);
        if (output_srt) fclose(output_srt);
        return EXIT_FAILURE;
    }

    char line[MAX_LINE];
    // Copia o conteúdo do primeiro arquivo para o de saída
    while (fgets(line, MAX_LINE, first_srt)) {
        fputs(line, output_srt);
        if (sscanf(line, "%d", &last_seq) == 1) {
            last_seq++; // Incrementa a contagem de sequência para o próximo número
        }
    }

    // Ajusta e copia o segundo arquivo para o de saída
    process_second_file(second_srt, output_srt, offset_ms, last_seq);

    // Fecha todos os arquivos
    fclose(first_srt);
    fclose(second_srt);
    fclose(output_srt);

    printf("Arquivos de legendas combinados com sucesso em '%s'.\n", file_out);

    return 0;
}
