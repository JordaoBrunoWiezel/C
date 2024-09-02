#include <stdio.h>
#include <string.h>
#include <dirent.h>

int action( const char *path, const char *name, void *context ) { // Funcao que escreve o caminho e o nome
    printf("File: %s\n", name);
    return 1;
}

int dirTreeFiles( const char *path, int (*action)( const char *path, const char *name, void *context ), void *context ) //retorna o nº de ficheiros e subdireetorias
{
    DIR* d = opendir(path); // abre o diretório de path
    int result = 0;
    struct dirent *de;

    if(d == NULL) return 2; // se o diretório nao puder ser aberto retorna 2

    while((de = readdir(d))!=NULL ) // enquanto houver entradas do diretório para ler
    {
        switch(de->d_type)
        {
            case DT_REG: result+=action(path,de->d_name,context); break; // caso seja um ficheiro regular, chamamos a fnção action e adicionamos a result

            case DT_DIR: if(strcmp(de->d_name,".")!=0 && (strcmp(de->d_name,"..")!=0)){ // caso seja uma diretoria ignora os diretórios "." e ".."

                action(path,de->d_name,context);    // aplicamos a função action ao diretório

                // criar o caminho até ao subdiretório
                char subpath[2+strlen(de->d_name)+strlen(path)]; // criar o caminho até ao subdiretório
                sprintf(subpath,"%s/%s",path,de->d_name);   
                
                 // Chama a função recursivamente no subdiretório e adiciona ao resultado               
                result+=dirTreeFiles(subpath,action,context);
                result++;
            }
            break;
        }
    }
    closedir(d);
return result;
}