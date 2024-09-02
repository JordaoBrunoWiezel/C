#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int age;
} Person;

typedef struct {
    Person people[MAX_LENGTH];
    int num_people;
} PeopleList;

// a. [2 pontos] Implemente a função bool add_person(PeopleList *list, const Person *p) que adiciona uma pessoa à lista 'list'. 
// A função retorna verdadeiro se a pessoa foi adicionada com sucesso e falso se a lista estiver cheia ou se a pessoa já existir na lista (com base no nome).

bool add_person(PeopleList *list, const Person *p){

    if(list->num_people >= MAX_LENGTH){
        return false;
    }

    for(int i= 0; i < list->num_people; i++){
        if(strcmp(list->people[i].name, p->name) == 0 ){
            return false;
        }
    }
return true;
}


// b. [3 pontos]  Defina a função int average_age(const PeopleList *list) que calcula e retorna a idade média das pessoas na lista.

int average_age(const PeopleList *list){

    int sum = 0, contador = 0;

    for(int i=0; i < list->num_people; i++){
        sum += (list->people[i].age);
        contador++;
    }
    
    int media = sum/contador;
return media;
}

// c. [3 pontos] Implemente a função void remove_older_than(PeopleList *list, int age) que remove todas as pessoas da lista 
// que são mais velhas do que a idade fornecida.

void remove_older_than(PeopleList *list, int age){

    int indice = 0;

        for(int i = 0; i < list->num_people;i++){
                if(list->people[].age <= age){
                    list->people[indice] = list->people[i];
                    indice++;
                }
        }

list->num_people = indice;
}