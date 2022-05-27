// Projeto 1
// Eduardo Barros Guimarães
// Nº USP 13679040

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAM 10

typedef struct{
    char question[300];
    char word[100];
    int size;
    bool orientation;
    // 0 para horizontal e 1 para vertical
}Word;

int main(int argc, char* argv[]){
    Word words[10];
    char input[100];
    int cont=0;
    while(true){
        printf("Digite a pergunta %d: ",cont+1);
        gets(input);
        if(!strcmp(input,"fim"))break;
        strcpy(words[cont].question, input);
        printf("Digite a palavra %d: ",cont+1);
        gets(input);
        strcpy(words[cont].word, input);
        printf("Digite a orientacao da palavra %d: ",cont+1);
        bool pos;
        gets(input);
        if(input=="horizontal") pos=false;
        else pos=true;
        words[cont].orientation=pos;
        cont++;
    }
    for(int i=0;i<10;i++){
        printf("A pergunta eh: %s\nA resposta eh: %s\nA orientacao eh: %d\n",words[i].question,words[i].word,words[i].orientation);
    }

    return 0;
}
