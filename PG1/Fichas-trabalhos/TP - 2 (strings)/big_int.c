#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_DIGITS 255

typedef unsigned char byte;

typedef byte BIG_INT[MAX_DIGITS + 1];

// Esta função determina o tamanho real de um numero grande BIG_INT
int big_size(const BIG_INT b) {
    int size = MAX_DIGITS;
    while(size > 0 && b[size] == 0) {
        size--;
    }
    return size + 1;
}

//A função big_show é usada para imprimir um número grande BIG_INT. Ela percorre o array big de trás para frente e imprime cada dígito do número. 
void big_show(const BIG_INT big) {
    // Loop que percorre os dígitos do BIG_INT de trás para frente
    for (int i = big[0]; i > 0; i--) {
        printf("%d", big[i]); // Imprime cada dígito do BIG_INT
    }
    printf("\n"); // Imprime uma nova linha após a exibição dos dígitos
}

/* A função big_copy é usada para copiar o conteúdo de um array bsrc para outro array bcopy. A função usa um loop para iterar 
sobre os elementos de bsrc e copiar cada elemento para a posição correspondente em bcopy */
void big_copy(const BIG_INT bsrc, BIG_INT bcopy) {
    int size = bsrc[0]; // Armazena o tamanho do BIG_INT original

    bcopy[0] = size; // Define o tamanho para o BIG_INT de destino

    for(int i = 0; i < size; i++) {
        bcopy[i] = bsrc[i];
    }
}

/* Essa função converte um numero do tipo long para o formato BIG_INT (Inicia um BIG_INT com o valor de um inteiro longo)
n   - inteiro cujo valor deve ser colocado no BIG_INT
big - BIG_INT que vai conter o valor do inteiro "n"*/
void big_from_long(long n, BIG_INT big) {
    long temp = n; // Armazena o valor original de 'n'
    int digit_count = 0; // Inicializa a contagem de dígitos como zero

    // Calcula o número de dígitos no número 'n'
    while (temp != 0) {
        temp /= 10; // Remove o último dígito de 'temp'
        digit_count++; // Incrementa a contagem de dígitos
    }

    big[0] = digit_count; // Armazena o número de dígitos no BIG_INT no índice 0

    // Loop para preencher o BIG_INT com os dígitos do número 'n'
    for (int i = 1; i <= digit_count; i++) {
        big[i] = n % 10; // Armazena o último dígito de 'n' no BIG_INT
        n /= 10; // Remove o último dígito de 'n'
    }
} 

/* Esta função converte um numero representado como uma string char[] para o formato BIG_INT
  A função preenche um BIG_INT a partir de uma string com a representação de um valor inteiro  
  n - string de caracteres numéricos.
  big - BIG_INT a construir a partir de "n"  */
bool big_from_string(char n[], BIG_INT big) {
    int str_length = strlen(n); // Obtém o comprimento da string inserida
    int big_indice = 1; // Inicializa o índice para preencher o BIG_INT

    // Verifica se a string está vazia
    if (str_length == 0) {
        return false; // Retorna falso se a string estiver vazia
    }

    // Percorre a string na ordem reversa, ignora espaços e armazena dígitos
    for (int i = str_length - 1; i >= 0; i--) {
        if (isdigit(n[i])) {
            big[big_indice] = n[i] - '0'; // Converte o caractere para inteiro e armazena no BIG_INT
            big_indice++; // Incrementa o índice do BIG_INT para o próximo dígito

            // Verifica se excedeu o número máximo de dígitos permitidos no BIG_INT
            if (big_indice > MAX_DIGITS) {
                return false; // Retorna falso se exceder o número máximo de dígitos permitidos
            }
        } else if (!isspace(n[i])) {
            return false; // Retorna falso se encontrar um caractere inválido que não seja um espaço ou dígito
        }
    }

    big[0] = big_indice - 1; // Armazena o tamanho atual do BIG_INT (subtrai 1 para considerar o elemento [0])

    return true; // Retorna verdadeiro se a conversão for concluída com sucesso
}


// Esta função  compara dois números inteiros grandes(BIG INT) representados por arrays 
int big_cmp(const BIG_INT b1, const BIG_INT b2) {
    int size1 = b1[0]; // Tamanho do BIG_INT b1
    int size2 = b2[0]; // Tamanho do BIG_INT b2
    
    // Remove zeros à esquerda nos BIG_INTs
    while (size1 > 1 && b1[size1] == 0) {
        size1--; // Reduz o tamanho se o dígito for zero
    }
    while (size2 > 1 && b2[size2] == 0) {
        size2--; // Reduz o tamanho se o dígito for zero
    }

    // Verifica os tamanhos após remover os zeros à esquerda
    if (size1 > size2){
        return 1; // Retorna 1 se b1 for maior que b2
    }
    else if (size1 < size2){ 
        return -1; // Retorna -1 se b1 for menor que b2
    }

    // Se iguais, compara os dígitos dos BIG_INTs a partir do mais significativo
    for (int i = 1; i <= size1; i++) {
        if (b1[i] > b2[i]){ 
            return 1; // Retorna 1 se b1 for maior que b2
        }
        if (b1[i] < b2[i]){ 
            return -1; // Retorna -1 se b1 for menor que b2
        }
    }

    return 0; // Retorna 0 se os BIG_INTs forem iguais
}


//  A função calcula a soma de dois BIG_INT guardando-a num terceiro BIG_INT 
bool big_add(const BIG_INT b1, const BIG_INT b2, BIG_INT bm) {
    // Obtenção do tamanho de cada um dos BIG_INT
    int size1 = big_size(b1);
    int size2 = big_size(b2);

    // Encontrar o tamanho máximo entre os BIG_INTs
    int maxsize;
    if (size1 < size2) {
        maxsize = size2; // Define maxSize como o tamanho de b2 se for maior
    } 
    else {
        maxsize = size1; // Caso contrário, define maxSize como o tamanho de b1
    }

    // Realização da adição
    int carry = 0; // Variável para lidar com os valores excedentes na adição
    for (int i = 1; i <= maxsize; i++) {
        int digito, digito2;

        // Verifica se há dígitos restantes em b1 para adicionar, senão considera 0
        digito = (i <= size1) ? b1[i] : 0;

        // Verifica se há dígitos restantes em b2 para adicionar, senão considera 0
        digito2 = (i <= size2) ? b2[i] : 0;

        // Realiza a adição considerando os dígitos e o carry
        int soma = digito + digito2 + carry;
        carry = soma / 10; // Atualiza o carry para a próxima adição
        bm[i] = soma % 10; // Armazena o dígito resultante na posição i do BIG_INT resultado
    }

    // Verificação de carry no último dígito durante a adição
    if (carry > 0) {
        // Adiciona o carry no próximo dígito se houver espaço disponível
        if (maxsize < MAX_DIGITS) {
            bm[maxsize + 1] = carry; // Adiciona o carry no próximo dígito
            bm[0] = maxsize + 1; // Atualiza o tamanho do BIG_INT resultado
            return true; // Adição concluída com sucesso
        } else {
            // Overflow, não há espaço para o carry adicional
            return false; // Retorna falso indicando overflow
        }
    } else {
        // Não houve overflow, atualiza o tamanho do resultado
        bm[0] = maxsize; // Atualiza o tamanho do BIG_INT resultado
        return true; // Adição concluída com sucesso
    }
}


// A função multiplica um BIG_INT por um inteiro (de 0 a 9) guardando o resultado noutro BIG_INT Parâmetros:
bool big_mul_dig(const BIG_INT b, int d, BIG_INT bres) {
    int size = b[0]; // Obtém o tamanho do BIG_INT de entrada
    int carry = 0; // Inicializa a variável carry para lidar com valores excedentes na multiplicação

    // Loop para multiplicar cada dígito do BIG_INT pelo dígito 'd'
    for (int i = 1; i <= size; i++) {
        if (d == 0) {
            size = 1; // Define o tamanho como 1 se o dígito multiplicador for zero
        }

        int digito = b[i]; // Obtém o dígito atual do BIG_INT
        int product = digito * d + carry; // Calcula o produto do dígito com 'd' e adiciona o carry anterior
        carry = product / 10; // Atualiza o carry para a próxima multiplicação
        bres[i] = product % 10; // Armazena o dígito resultante no BIG_INT de resultado
    }

    // Verifica se há carry após a multiplicação dos dígitos
    while (carry > 0) {
        // Adiciona o carry ao BIG_INT resultante se houver espaço
        if (size < MAX_DIGITS) {
            bres[++size] = carry % 10; // Adiciona o carry ao próximo dígito do BIG_INT
            carry /= 10; // Atualiza o carry para a próxima iteração
        } else {
            return false; // Overflow, não há espaço para armazenar mais dígitos
        }
    }

    // Verifica se o dígito multiplicador está dentro do intervalo válido (0 a 9)
    for (int i = size - 1; i >= 0; i--) {
        if (d < 0 || d > 9) {
            return false; // Retorna falso se 'd' não estiver no intervalo válido
        }
    }

    bres[0] = size; // Atualiza o tamanho do BIG_INT de resultado
    return true; // Multiplicação bem-sucedida
}


// Esta função big_mul_pow_10 multiplica um numero grande (b) por uma potência de 10
bool big_mul_10(BIG_INT b) {
    // Obter o tamanho atual do BIG_INT
    int size = big_size(b);

    // Verificar se há espaço para adicionar mais um dígito
    if (size < MAX_DIGITS) {
        // Deslocar os dígitos para a esquerda (multiplicação por 10)
        for (int i = size + 1; i > 1; i--) {
            b[i] = b[i - 1]; // Desloca cada dígito uma posição para a esquerda
        }

        b[1] = 0; // Coloca zero no dígito mais à esquerda

        b[0]++; // Atualiza o tamanho do BIG_INT

        return true; // Operação bem-sucedida
    } else {
        // Overflow, não há espaço para adicionar mais dígitos
        return false; // Retorna falso indicando overflow
    }
}


//  A função  multiplica o bigint "b" pela potência de 10 de expoente "exp"
bool big_mul_pow_10(BIG_INT b, int exp) {
    // Verifica se o expoente é negativo
    if (exp < 0) {
        return false; // Retorna falso se o expoente for negativo
    }

    // Loop para multiplicar o BIG_INT por 10 'exp' vezes
    for (int i = 0; i < exp; i++) {
        // Verifica se houve overflow na multiplicação por 10
        if (!big_mul_10(b)) {
            return false; // Retorna falso se ocorrer overflow
        }
    }

    return true; // Retorna verdadeiro se a multiplicação por 10^exp for bem-sucedida
}


// A função recebe três BIG_INT:  os dois primeiros são os operandos da multiplicação e o resultado é  colocado no terceiro
bool big_mul(const BIG_INT b1, const BIG_INT b2, BIG_INT bm) {
    int size1 = b1[0]; // Tamanho do primeiro BIG_INT
    int size2 = b2[0]; // Tamanho do segundo BIG_INT

    // iniciar o resultado com o valor 0
    for (int i = 0; i < MAX_DIGITS; i++) {
        bm[i] = 0; // Inicializa o BIG_INT de resultado com zeros
    }

    // Multiplicação de cada dígito de b1 por b2
    for (int i = 1; i <= size1; i++) {
        int digit1 = b1[i]; // Dígito atual do primeiro BIG_INT
        int carry = 0; // Inicializa o carry para lidar com os valores excedentes na multiplicação

        // Multiplicação do dígito atual de b1 por cada dígito de b2
        for (int j = 1; j <= size2 || carry > 0; j++) {
            int digit2 = (j <= size2) ? b2[j] : 0; // Obtém o dígito correspondente de b2
            int product = bm[i + j - 1] + digit1 * digit2 + carry; // Calcula o produto
            carry = product / 10; // Calcula o carry para a próxima iteração
            bm[i + j - 1] = product % 10; // Armazena o dígito resultante
        }
    }

    // Atualizar o tamanho do BIG_INT resultante
    int resultSize = size1 + size2; // Tamanho esperado do resultado
    while (resultSize > 1 && bm[resultSize] == 0) {
        resultSize--; // Reduz o tamanho se houver dígitos zero à esquerda no resultado
    }
    bm[0] = resultSize; // Atualiza o tamanho do BIG_INT de resultado

    // Verificar overflow
    if (resultSize >= MAX_DIGITS) {
        return false; // Retorna falso se houver overflow
    }

    return true; // Retorna verdadeiro se a multiplicação for concluída com sucesso
}

